#!/usr/bin/env python3
"""
Audit Arma 3 addon dependencies for CfgPatches.requiredAddons[].

This is a conservative report-only tool. It scans config-like files for:
- hard references: top-level inheritance and load-order-sensitive class refs
- soft references: loadout/content refs such as uniforms, weapons, magazines
- best-effort SQF refs for common gear/identity commands

It then maps referenced external classes to owning CfgPatches entries using a
maintained JSON mapping file.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


CONFIG_SUFFIXES = {".hpp", ".cpp"}
SQF_SUFFIXES = {".sqf"}
SCAN_SUFFIXES = CONFIG_SUFFIXES | SQF_SUFFIXES

SCAN_PROPERTY_TIERS = {
    "hard": {
        "ammo",
        "assembleTo",
        "crew",
        "faction",
        "gunnerType",
        "submunitionAmmo",
        "uavHacker",
        "vehicle",
    },
    "soft": {
        "backpack",
        "face",
        "glasses",
        "identityTypes",
        "item",
        "items",
        "linkedItems",
        "magazine",
        "magazines",
        "respawnItems",
        "respawnMagazines",
        "respawnWeapons",
        "respawnlinkedItems",
        "speaker",
        "uniformClass",
        "weapon",
        "weapons",
    },
}

SQF_COMMAND_TIERS = {
    "hard": {
        "createUnit",
    },
    "soft": {
        "addBackpack",
        "addBackpackGlobal",
        "addGoggles",
        "addHeadgear",
        "addItem",
        "addItemToBackpack",
        "addItemToUniform",
        "addItemToVest",
        "addMagazine",
        "addMagazineGlobal",
        "addPrimaryWeaponItem",
        "addSecondaryWeaponItem",
        "addUniform",
        "addVest",
        "addWeapon",
        "addWeaponGlobal",
        "forceAddUniform",
        "linkItem",
        "setFace",
        "setIdentity",
        "setObjectTextureGlobal",
        "setSpeaker",
    },
}

NESTED_CLASS_SKIP = {
    "AnimationSources",
    "AssembleInfo",
    "Burst1",
    "CargoTurret_01",
    "CargoTurret_02",
    "CargoTurret_03",
    "CargoTurret_04",
    "Close",
    "Components",
    "CopilotTurret",
    "CowsSlot",
    "Default",
    "EventHandlers",
    "Far_Optic1",
    "Far_Optic2",
    "FrontTurret",
    "ItemInfo",
    "LinkedItems",
    "LinkedItemsAcc",
    "LinkedItemsMuzzle",
    "LinkedItemsOptic",
    "LinkedItemsUnder",
    "MainTurret",
    "Manual",
    "Medium_Optic2",
    "RearTurret",
    "Single",
    "Single1",
    "TransportItems",
    "TransportMagazines",
    "TransportPylonsComponent",
    "TransportWeapons",
    "Turrets",
    "WeaponSlotsInfo",
}

CLASS_CANDIDATE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
DEFINE_RE = re.compile(r"^\s*#define\s+([A-Za-z_][A-Za-z0-9_]*)(\([^)]*\))?\s+(.+?)\s*$")
CLASS_RE = re.compile(r"^\s*class\s+([A-Za-z_][A-Za-z0-9_]*)\b")
CLASS_DEF_RE = re.compile(r"\bclass\s+([A-Za-z_][A-Za-z0-9_]*)\b[^{;]*\{", re.S)
TOP_LEVEL_INHERIT_RE = re.compile(
    r"^(?P<indent>\s*)class\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*:\s*(?P<base>[A-Za-z_][A-Za-z0-9_]*)\b"
)
PROPERTY_RE = re.compile(
    r"\b(?P<key>[A-Za-z_][A-Za-z0-9_]*)\s*(?:\[\])?\s*=\s*(?P<value>\{.*?\}|[^;]+);",
    re.S,
)
CFGPATCHES_RE = re.compile(
    r"requiredAddons\[\]\s*=\s*\{(?P<body>.*?)\};",
    re.S,
)
STRING_RE = re.compile(r'"([^"\\]*(?:\\.[^"\\]*)*)"')
TOKEN_RE = re.compile(r"\b[A-Za-z_][A-Za-z0-9_]*\b")
LINE_COMMENT_RE = re.compile(r"//.*?$", re.M)
BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.S)


@dataclass(frozen=True)
class Reference:
    symbol: str
    tier: str
    ref_type: str
    source: str
    line: int


def strip_comments(text: str) -> str:
    text = BLOCK_COMMENT_RE.sub("", text)
    return LINE_COMMENT_RE.sub("", text)


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="ignore")


def load_mapping(path: Path) -> dict[str, dict[str, str]]:
    if not path.exists():
        return {}
    data = json.loads(read_text(path))
    if not isinstance(data, dict):
        raise ValueError(f"Mapping file must contain an object: {path}")
    return {str(key): value for key, value in data.items()}


def collect_files(addon_dir: Path) -> list[Path]:
    files = [
        path
        for path in sorted(addon_dir.rglob("*"))
        if path.is_file() and path.suffix.lower() in SCAN_SUFFIXES
    ]
    return files


def parse_macros(files: Iterable[Path]) -> dict[str, str]:
    macros: dict[str, str] = {}
    for path in files:
        if path.suffix.lower() not in CONFIG_SUFFIXES:
            continue
        for line in read_text(path).splitlines():
            match = DEFINE_RE.match(line)
            if not match:
                continue
            name, params, body = match.groups()
            if params:
                continue
            body = body.strip()
            if not body:
                continue
            macros[name] = body
    return macros


def resolve_macro(name: str, macros: dict[str, str], seen: set[str] | None = None) -> str | None:
    if name not in macros:
        return None
    if seen is None:
        seen = set()
    if name in seen:
        return None
    seen.add(name)
    body = macros[name].strip()
    quoted = STRING_RE.fullmatch(body)
    if quoted:
        return quoted.group(1)
    if CLASS_CANDIDATE.fullmatch(body):
        return resolve_macro(body, macros, seen) or body
    return None


def collect_local_classes(files: Iterable[Path]) -> set[str]:
    classes: set[str] = set()
    for path in files:
        if path.suffix.lower() not in CONFIG_SUFFIXES:
            continue
        text = strip_comments(read_text(path))
        classes.update(CLASS_DEF_RE.findall(text))
    return classes


def parse_required_addons(cfg_patches_path: Path) -> list[str]:
    text = read_text(cfg_patches_path)
    match = CFGPATCHES_RE.search(text)
    if not match:
        return []
    return STRING_RE.findall(match.group("body"))


def is_probable_symbol(value: str) -> bool:
    if not CLASS_CANDIDATE.fullmatch(value):
        return False
    if len(value) < 2:
        return False
    if value in {"true", "false", "nil", "this", "player", "objNull"}:
        return False
    return True


def normalize_symbol(
    token: str,
    macros: dict[str, str],
    local_classes: set[str],
) -> str | None:
    resolved_macro = resolve_macro(token, macros)
    if resolved_macro is None and token not in macros:
        if token.upper() == token and any(char.isalpha() for char in token):
            return None
    resolved = resolved_macro or token
    if not is_probable_symbol(resolved):
        return None
    if resolved in local_classes:
        return None
    return resolved


def line_number_for_offset(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def collect_hard_inheritance_refs(
    path: Path,
    macros: dict[str, str],
    local_classes: set[str],
) -> list[Reference]:
    refs: list[Reference] = []
    for line_number, line in enumerate(read_text(path).splitlines(), start=1):
        match = TOP_LEVEL_INHERIT_RE.match(line)
        if not match:
            continue
        indent = len(match.group("indent"))
        if indent > 4:
            continue
        class_name = match.group("name")
        base_name = match.group("base")
        if class_name in NESTED_CLASS_SKIP or base_name in NESTED_CLASS_SKIP:
            continue
        symbol = normalize_symbol(base_name, macros, local_classes)
        if not symbol:
            continue
        refs.append(
            Reference(
                symbol=symbol,
                tier="hard",
                ref_type="inheritance_base",
                source=str(path),
                line=line_number,
            )
        )
    return refs


def extract_tokens_from_value(
    raw_value: str,
    macros: dict[str, str],
    local_classes: set[str],
) -> list[str]:
    symbols: list[str] = []
    quoted_values = STRING_RE.findall(raw_value)
    for quoted in quoted_values:
        symbol = normalize_symbol(quoted, macros, local_classes)
        if symbol:
            symbols.append(symbol)
    value_without_strings = STRING_RE.sub(" ", raw_value)
    for token in TOKEN_RE.findall(value_without_strings):
        symbol = normalize_symbol(token, macros, local_classes)
        if symbol:
            symbols.append(symbol)
    return symbols


def collect_property_refs(
    path: Path,
    macros: dict[str, str],
    local_classes: set[str],
) -> list[Reference]:
    refs: list[Reference] = []
    clean_text = strip_comments(read_text(path))
    for match in PROPERTY_RE.finditer(clean_text):
        key = match.group("key")
        tier = None
        for candidate_tier, keys in SCAN_PROPERTY_TIERS.items():
            if key in keys:
                tier = candidate_tier
                break
        if tier is None:
            continue
        symbols = extract_tokens_from_value(match.group("value"), macros, local_classes)
        line = line_number_for_offset(clean_text, match.start())
        for symbol in symbols:
            refs.append(
                Reference(
                    symbol=symbol,
                    tier=tier,
                    ref_type=f"property:{key}",
                    source=str(path),
                    line=line,
                )
            )
    return refs


def collect_sqf_refs(
    path: Path,
    macros: dict[str, str],
    local_classes: set[str],
) -> list[Reference]:
    refs: list[Reference] = []
    text = strip_comments(read_text(path))
    for tier, commands in SQF_COMMAND_TIERS.items():
        for command in commands:
            pattern = re.compile(
                rf'"(?P<symbol>[A-Za-z_][A-Za-z0-9_]*)"\s+(?:call|spawn\s+)?{re.escape(command)}\b'
            )
            for match in pattern.finditer(text):
                symbol = normalize_symbol(match.group("symbol"), macros, local_classes)
                if not symbol:
                    continue
                refs.append(
                    Reference(
                        symbol=symbol,
                        tier=tier,
                        ref_type=f"sqf:{command}",
                        source=str(path),
                        line=line_number_for_offset(text, match.start()),
                    )
                )
            reverse_pattern = re.compile(
                rf"\b{re.escape(command)}\s+\"(?P<symbol>[A-Za-z_][A-Za-z0-9_]*)\""
            )
            for match in reverse_pattern.finditer(text):
                symbol = normalize_symbol(match.group("symbol"), macros, local_classes)
                if not symbol:
                    continue
                refs.append(
                    Reference(
                        symbol=symbol,
                        tier=tier,
                        ref_type=f"sqf:{command}",
                        source=str(path),
                        line=line_number_for_offset(text, match.start()),
                    )
                )
    return refs


def dedupe_refs(refs: Iterable[Reference]) -> list[Reference]:
    seen: set[tuple[str, str, str, str, int]] = set()
    out: list[Reference] = []
    for ref in refs:
        key = (ref.symbol, ref.tier, ref.ref_type, ref.source, ref.line)
        if key in seen:
            continue
        seen.add(key)
        out.append(ref)
    return out


def collect_references(
    addon_dir: Path,
    files: list[Path],
    macros: dict[str, str],
    local_classes: set[str],
) -> list[Reference]:
    refs: list[Reference] = []
    for path in files:
        if path.suffix.lower() in CONFIG_SUFFIXES:
            refs.extend(collect_hard_inheritance_refs(path, macros, local_classes))
            refs.extend(collect_property_refs(path, macros, local_classes))
        elif path.suffix.lower() in SQF_SUFFIXES:
            refs.extend(collect_sqf_refs(path, macros, local_classes))
    return dedupe_refs(refs)


def summarize_refs(refs: Iterable[Reference]) -> dict[str, list[Reference]]:
    grouped: dict[str, list[Reference]] = defaultdict(list)
    for ref in refs:
        grouped[ref.symbol].append(ref)
    return grouped


def format_refs(refs: list[Reference], limit: int = 3) -> str:
    examples = refs[:limit]
    bits = [f"{Path(ref.source).name}:{ref.line} {ref.ref_type}" for ref in examples]
    if len(refs) > limit:
        bits.append(f"+{len(refs) - limit} more")
    return ", ".join(bits)


def audit_addon(addon_dir: Path, mapping: dict[str, dict[str, str]]) -> str:
    return audit_addon_with_runtime(addon_dir, mapping, [])


def audit_addon_with_runtime(
    addon_dir: Path,
    mapping: dict[str, dict[str, str]],
    runtime_cfg_files: list[Path],
) -> str:
    files = collect_files(addon_dir)
    macros = parse_macros(files)
    local_classes = collect_local_classes(files)
    cfg_patches = addon_dir / "CfgPatches.hpp"
    current_required = parse_required_addons(cfg_patches) if cfg_patches.exists() else []
    refs = collect_references(addon_dir, files, macros, local_classes)

    by_symbol = summarize_refs(refs)
    mapped_by_tier: dict[str, dict[str, list[Reference]]] = {"hard": defaultdict(list), "soft": defaultdict(list)}
    unresolved_by_tier: dict[str, dict[str, list[Reference]]] = {"hard": {}, "soft": {}}

    for symbol, symbol_refs in sorted(by_symbol.items()):
        highest_tier = "hard" if any(ref.tier == "hard" for ref in symbol_refs) else "soft"
        if symbol in mapping and "patch" in mapping[symbol]:
            mapped_by_tier[highest_tier][mapping[symbol]["patch"]].extend(symbol_refs)
        else:
            unresolved_by_tier[highest_tier][symbol] = symbol_refs

    hard_patches = sorted(mapped_by_tier["hard"].keys())
    all_mapped_patches = sorted(set(mapped_by_tier["hard"]) | set(mapped_by_tier["soft"]))
    current_required_set = set(current_required)
    missing_hard = [patch for patch in hard_patches if patch not in current_required_set]
    probably_stale = [patch for patch in current_required if patch not in set(all_mapped_patches)]

    runtime_required_by_file: dict[Path, list[str]] = {}
    runtime_required_union: list[str] = []
    runtime_required_set: set[str] = set()
    for runtime_cfg in runtime_cfg_files:
        runtime_required = parse_required_addons(runtime_cfg)
        runtime_required_by_file[runtime_cfg] = runtime_required
        runtime_required_set.update(runtime_required)
    runtime_required_union = sorted(runtime_required_set)

    runtime_missing_from_current = sorted(runtime_required_set - current_required_set)
    current_missing_from_runtime = sorted(current_required_set - runtime_required_set)
    runtime_missing_from_static_hard = sorted(runtime_required_set - set(hard_patches))
    static_hard_missing_from_runtime = sorted(set(hard_patches) - runtime_required_set)

    lines: list[str] = []
    lines.append(f"# requiredAddons audit: {addon_dir}")
    lines.append("")
    lines.append(f"- Scanned files: {len(files)}")
    lines.append(f"- Local classes discovered: {len(local_classes)}")
    lines.append(f"- External refs discovered: {len(refs)}")
    lines.append(f"- Current requiredAddons[] count: {len(current_required)}")
    lines.append(f"- Recommended hard patch count: {len(hard_patches)}")
    if runtime_cfg_files:
        lines.append(f"- Runtime/oracle files: {len(runtime_cfg_files)}")
        lines.append(f"- Runtime/oracle patch count: {len(runtime_required_union)}")
    lines.append("")

    lines.append("## Current requiredAddons[]")
    if current_required:
        for patch in current_required:
            lines.append(f"- {patch}")
    else:
        lines.append("- none found")
    lines.append("")

    lines.append("## Recommended requiredAddons[] (hard refs only)")
    if hard_patches:
        for patch in hard_patches:
            example_refs = mapped_by_tier["hard"][patch]
            lines.append(f"- {patch}")
            lines.append(f"  via {format_refs(example_refs)}")
    else:
        lines.append("- no mapped hard refs")
    lines.append("")

    lines.append("## Missing mapped patches")
    if missing_hard:
        for patch in missing_hard:
            lines.append(f"- {patch}")
    else:
        lines.append("- none")
    lines.append("")

    lines.append("## Probably stale current patches")
    lines.append("These are current requiredAddons[] entries not justified by any mapped hard or soft refs.")
    lines.append("Unresolved external classes can make this list incomplete or noisy.")
    if probably_stale:
        for patch in probably_stale:
            lines.append(f"- {patch}")
    else:
        lines.append("- none")
    lines.append("")

    if runtime_cfg_files:
        lines.append("## Runtime/oracle requiredAddons[]")
        lines.append("These come from exported config snippets, for example an ALiVE ORBAT export.")
        if runtime_required_union:
            for patch in runtime_required_union:
                lines.append(f"- {patch}")
        else:
            lines.append("- none found in supplied runtime/oracle files")
        lines.append("")

        lines.append("## Runtime/oracle source files")
        for runtime_cfg in runtime_cfg_files:
            count = len(runtime_required_by_file[runtime_cfg])
            lines.append(f"- {runtime_cfg} ({count} patches)")
        lines.append("")

        lines.append("## Runtime/oracle patches missing from current requiredAddons[]")
        if runtime_missing_from_current:
            for patch in runtime_missing_from_current:
                lines.append(f"- {patch}")
        else:
            lines.append("- none")
        lines.append("")

        lines.append("## Current requiredAddons[] entries not seen in runtime/oracle")
        lines.append("This can be legitimate if the runtime export is scenario-specific or incomplete.")
        if current_missing_from_runtime:
            for patch in current_missing_from_runtime:
                lines.append(f"- {patch}")
        else:
            lines.append("- none")
        lines.append("")

        lines.append("## Runtime/oracle patches not justified by mapped static hard refs")
        lines.append("These are good candidates for expanding the class-to-patch mapping file.")
        if runtime_missing_from_static_hard:
            for patch in runtime_missing_from_static_hard:
                lines.append(f"- {patch}")
        else:
            lines.append("- none")
        lines.append("")

        lines.append("## Mapped static hard patches not seen in runtime/oracle")
        lines.append("This can happen when a runtime export does not touch every inheritance path or optional asset.")
        if static_hard_missing_from_runtime:
            for patch in static_hard_missing_from_runtime:
                lines.append(f"- {patch}")
        else:
            lines.append("- none")
        lines.append("")

    for tier in ("hard", "soft"):
        lines.append(f"## Mapped {tier} refs by patch")
        if mapped_by_tier[tier]:
            for patch, patch_refs in sorted(mapped_by_tier[tier].items()):
                lines.append(f"- {patch}: {len(patch_refs)} refs")
        else:
            lines.append("- none")
        lines.append("")

        lines.append(f"## Unresolved {tier} refs")
        if unresolved_by_tier[tier]:
            for symbol, symbol_refs in sorted(unresolved_by_tier[tier].items()):
                lines.append(f"- {symbol}")
                lines.append(f"  via {format_refs(symbol_refs)}")
        else:
            lines.append("- none")
        lines.append("")

    return "\n".join(lines).rstrip() + "\n"


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Audit Arma 3 addon requiredAddons[] dependencies.")
    parser.add_argument(
        "addons",
        nargs="+",
        help="Addon directories to audit, for example: addons/bskulls-modern",
    )
    parser.add_argument(
        "--mapping",
        default="tools/class_to_patch_map.json",
        help="Path to the class-to-patch mapping JSON file.",
    )
    parser.add_argument(
        "--runtime-cfg",
        action="append",
        default=[],
        help=(
            "Path to a runtime-exported config snippet that contains requiredAddons[], "
            "for example an ALiVE ORBAT/autogen export. May be provided multiple times."
        ),
    )
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    mapping = load_mapping(Path(args.mapping))

    outputs: list[str] = []
    for addon in args.addons:
        addon_dir = Path(addon)
        if not addon_dir.is_dir():
            print(f"error: addon directory not found: {addon_dir}", file=sys.stderr)
            return 2
        runtime_cfg_files = [Path(path) for path in args.runtime_cfg]
        for runtime_cfg in runtime_cfg_files:
            if not runtime_cfg.is_file():
                print(f"error: runtime/oracle config file not found: {runtime_cfg}", file=sys.stderr)
                return 2
        outputs.append(audit_addon_with_runtime(addon_dir, mapping, runtime_cfg_files))

    print("\n".join(outputs).rstrip())
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
