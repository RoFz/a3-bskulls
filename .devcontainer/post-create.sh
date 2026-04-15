#!/usr/bin/env bash
set -euo pipefail

export PATH="$HOME/.local/bin:$PATH"

echo "[devcontainer] Installing repo tooling..."

sudo apt-get update -qq && sudo apt-get install -y --no-install-recommends \
  default-jre-headless \
  libssl-dev

python3 -m pip install --user --upgrade pip
python3 -m pip install --user pre-commit

# Claude Code
npm install -g @anthropic-ai/claude-code

# Codex CLI
npm install -g @openai/codex

# Ensure Claude Code skips onboarding - ~/.claude.json is outside the bind-mounted
# ~/.claude dir, so it is not persisted automatically and must be seeded on each build.
test -f ~/.claude.json || echo '{"hasCompletedOnboarding":true,"installMethod":"native"}' > ~/.claude.json

if ! command -v armake2 >/dev/null 2>&1; then
  echo "[devcontainer] Installing armake2..."
  cargo install armake2
fi

if ! command -v hemtt >/dev/null 2>&1; then
  echo "[devcontainer] Installing HEMTT via official installer..."
  if curl -sSf https://hemtt.dev/install.sh | sh; then
    echo "[devcontainer] HEMTT installed via official installer."
  else
    echo "[devcontainer] Official installer failed, falling back to source build..."
    tmpdir="$(mktemp -d)"
    git clone https://github.com/BrettMayson/HEMTT.git "$tmpdir/HEMTT"
    cargo install --path "$tmpdir/HEMTT/bin"
    rm -rf "$tmpdir"
  fi
fi

echo "[devcontainer] Tool versions:"
java -version || true
python3 --version
pre-commit --version
armake2 --version || true
hemtt --version || true
echo "[devcontainer] post-create complete."
