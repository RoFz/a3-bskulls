#!/usr/bin/env python3
"""Run a local Arma build only when no other build or Arma 3 is active."""

from __future__ import annotations

import argparse
import errno
import fcntl
import os
import socket
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path

DEFAULT_ARMA_EXE = Path("/arma3/game/arma3_x64.exe")
DEFAULT_LOCK_FILE = Path("/tmp/a3-local-build.lock")


def error(message: str) -> int:
    print(f"ERROR: {message}", file=sys.stderr)
    return 2


def check_arma_stopped(arma_exe: Path, label: str) -> None:
    if not arma_exe.is_file():
        raise RuntimeError(
            f"Cannot verify that Arma 3 is stopped; build '{label}' was not started.\n"
            f"       Expected executable: {arma_exe}\n"
            "       Mount the Arma 3 game directory at /arma3/game via A3_GAME_DIR."
        )

    flags = os.O_WRONLY | getattr(os, "O_CLOEXEC", 0)
    try:
        descriptor = os.open(arma_exe, flags)
    except OSError as exc:
        if exc.errno == errno.EROFS:
            raise RuntimeError(
                f"Cannot verify that Arma 3 is stopped; build '{label}' was not started.\n"
                f"       The game mount is read-only: {arma_exe}\n"
                "       Ensure A3_GAME_DIR is mounted read/write, then retry."
            ) from exc
        if exc.errno in {errno.EACCES, errno.EBUSY, errno.EPERM, errno.ETXTBSY}:
            raise RuntimeError(
                f"Arma 3 appears to be running; build '{label}' was not started.\n"
                f"       The executable is locked against write access: {arma_exe}\n"
                "       Close Arma 3 completely, then retry."
            ) from exc
        raise RuntimeError(
            f"Cannot verify that Arma 3 is stopped; build '{label}' was not started.\n"
            f"       Write-access probe failed for {arma_exe}: {exc}"
        ) from exc
    else:
        os.close(descriptor)


def run_guarded(command: list[str], label: str, arma_exe: Path, lock_file: Path) -> int:
    try:
        lock_file.parent.mkdir(parents=True, exist_ok=True)
        lock_handle = lock_file.open("a+", encoding="utf-8")
    except OSError as exc:
        return error(f"Cannot open the shared build lock {lock_file}: {exc}")

    with lock_handle:
        try:
            fcntl.flock(lock_handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            lock_handle.seek(0)
            owner = lock_handle.read().strip() or "owner details unavailable"
            return error(
                f"Another Arma build/install is already running; build '{label}' "
                f"was not started.\n       Active build: {owner}\n"
                f"       Shared lock: {lock_file}"
            )

        owner = (
            f"{label}; pid={os.getpid()}; host={socket.gethostname()}; "
            f"started={datetime.now(timezone.utc).isoformat(timespec='seconds')}"
        )
        lock_handle.seek(0)
        lock_handle.truncate()
        lock_handle.write(owner + "\n")
        lock_handle.flush()

        try:
            check_arma_stopped(arma_exe, label)
        except RuntimeError as exc:
            return error(str(exc))

        try:
            return subprocess.run(command, check=False).returncode
        except FileNotFoundError as exc:
            return error(f"Cannot start guarded command {command[0]!r}: {exc}")
        except KeyboardInterrupt:
            return 130


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--label", required=True, help="Human-readable build name")
    parser.add_argument(
        "--arma-exe",
        type=Path,
        default=Path(os.environ.get("ARMA3_EXE", DEFAULT_ARMA_EXE)),
        help="Arma 3 executable used for the running-process lock probe",
    )
    parser.add_argument(
        "--lock-file",
        type=Path,
        default=Path(os.environ.get("A3_BUILD_LOCK_FILE", DEFAULT_LOCK_FILE)),
        help="Shared advisory lock file",
    )
    parser.add_argument("command", nargs=argparse.REMAINDER)
    args = parser.parse_args()

    command = args.command[1:] if args.command[:1] == ["--"] else args.command
    if not command:
        return error("No command was supplied after '--'.")

    return run_guarded(command, args.label, args.arma_exe, args.lock_file)


if __name__ == "__main__":
    raise SystemExit(main())
