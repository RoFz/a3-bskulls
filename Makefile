# Build launcher-ready PBOs and sync into the host mods folder mounted at /arma3/mods.
# Requires A3_MODS_DIR on the host and a Dev Container reopen.

MODS_DIR ?= /arma3/mods
PYTHON ?= python3
BUILD_GUARD ?= tools/run_guarded_build.py
ARMA3_EXE ?= /arma3/game/arma3_x64.exe

.PHONY: all modern cold coldwar nam help _build-all _build-sync

help:
	@echo "Targets:"
	@echo "  make all      - build + sync modern, coldwar, nam"
	@echo "  make modern   - build + sync bskulls-modern"
	@echo "  make cold     - build + sync bskulls-coldwar (alias: coldwar)"
	@echo "  make nam      - build + sync bskulls-nam"
	@echo ""
	@echo "Uses hemtt build --no-bin (not hemtt dev). Syncs to \$$(MODS_DIR)/@bskulls-*/Addons/"
	@echo "Default MODS_DIR=/arma3/mods (host A3_MODS_DIR bind mount)."
	@echo "Refuses to build while another local build or Arma 3 is running."

all:
	@$(PYTHON) "$(BUILD_GUARD)" --label "all faction mods" --arma-exe "$(ARMA3_EXE)" -- \
	  $(MAKE) --no-print-directory _build-all

modern:
	@$(PYTHON) "$(BUILD_GUARD)" --label "faction mod: modern" --arma-exe "$(ARMA3_EXE)" -- \
	  $(MAKE) --no-print-directory _build-sync ERA=modern

cold coldwar:
	@$(PYTHON) "$(BUILD_GUARD)" --label "faction mod: coldwar" --arma-exe "$(ARMA3_EXE)" -- \
	  $(MAKE) --no-print-directory _build-sync ERA=coldwar

nam:
	@$(PYTHON) "$(BUILD_GUARD)" --label "faction mod: nam" --arma-exe "$(ARMA3_EXE)" -- \
	  $(MAKE) --no-print-directory _build-sync ERA=nam

_build-all:
	@$(MAKE) --no-print-directory _build-sync ERA=modern
	@$(MAKE) --no-print-directory _build-sync ERA=coldwar
	@$(MAKE) --no-print-directory _build-sync ERA=nam

_build-sync:
	@test -n "$(ERA)" || (echo "ERA is required" >&2; exit 1)
	@test -d "$(MODS_DIR)" || (echo "Missing $(MODS_DIR). Set host A3_MODS_DIR and rebuild/reopen the Dev Container." >&2; exit 1)
	@set -e; \
	dest="$(MODS_DIR)/@bskulls-$(ERA)/Addons"; \
	test -d "$$dest" || (echo "Missing $$dest. Create @bskulls-$(ERA)/Addons under A3_MODS_DIR on the host." >&2; exit 1); \
	echo "==> hemtt build --no-bin (bskulls-$(ERA))"; \
	(cd "bskulls-$(ERA)" && hemtt build --no-bin); \
	echo "==> sync -> $$dest"; \
	rm -f "$$dest"/*.pbo; \
	cp -f "bskulls-$(ERA)/.hemttout/build/addons/"*.pbo "$$dest/"; \
	mod_root="$(MODS_DIR)/@bskulls-$(ERA)"; \
	if [ -f "bskulls-$(ERA)/.hemttout/build/mod.cpp" ]; then \
	  cp -f "bskulls-$(ERA)/.hemttout/build/mod.cpp" "$$mod_root/mod.cpp"; \
	elif [ -f "bskulls-$(ERA)/mod.cpp" ]; then \
	  cp -f "bskulls-$(ERA)/mod.cpp" "$$mod_root/mod.cpp"; \
	fi; \
	ls -la "$$mod_root" "$$dest"
