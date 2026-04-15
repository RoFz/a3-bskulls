# Next Session Notes

## Branch

- `codex-required-addons-audit`

## Current State

- Added a report-only dependency audit tool at [tools/audit_required_addons.py](/workspaces/a3-bskulls/tools/audit_required_addons.py).
- Added a seed class-to-patch mapping file at [tools/class_to_patch_map.json](/workspaces/a3-bskulls/tools/class_to_patch_map.json).
- Documented the audit workflow in [README.md](/workspaces/a3-bskulls/README.md).
- Cleaned up `bskulls-modern` by:
  - syncing `CfgPatches.units[]` and `weapons[]` with public classes
  - setting internal UAV AI helper classes to non-public scope in [addons/bskulls-modern/CfgVehicles.hpp](/workspaces/a3-bskulls/addons/bskulls-modern/CfgVehicles.hpp)

## Constraints Agreed In Session

- Do not rely on ALiVE for dependency discovery.
- Do not rely on Mikero tools for dependency discovery.
- Official BI docs/wiki remain the primary authority for Arma behavior.
- Reputable mod implementations like CBA, ACE3, and ALiVE can be used as supporting references, but not as the primary source of truth.

## Problem Statement

The dependency audit can already identify many referenced assets from local source, but it cannot automatically determine which upstream addon owns each referenced classname unless that ownership has been taught manually in the mapping file.

The next major step is to replace that manual mapping burden with an indexer that reads installed upstream Arma 3 mods and builds a local ownership database.

## Next Goal

Build an upstream-mod indexer that:

1. scans installed upstream Arma 3 mods on the Windows machine
2. reads addon config data from those mods
3. builds:
   - `class -> CfgPatches owner`
   - `CfgPatches owner -> mod/package`
4. feeds the audit workflow so `requiredAddons[]` can be derived much more automatically

## Expected Inputs For The Indexer

- one or more Windows paths pointing at installed Arma 3 mod folders
- access to upstream addon data such as unpacked configs or packed addon contents
- a way to read Arma config definitions and distinguish real class definitions from declarations

## Resume Prompt

When resuming from Windows, continue from this branch and use this prompt:

```text
Continue building the upstream-mod indexer for Arma 3 dependency resolution.
Use the existing tools/audit_required_addons.py workflow as the source-side scanner.
The next task is to design and implement the installed-mod indexing step that can map external classnames to their owning CfgPatches addon automatically.
Do not use ALiVE or Mikero as dependencies for the solution.
```
