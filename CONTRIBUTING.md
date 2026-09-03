# Contributing

## Scope

This repository preserves existing addon content and layout. Prefer targeted changes, and do not reorganize existing addon directories unless that work has been explicitly approved.

## Getting started

```sh
git clone --recurse-submodules https://github.com/RoFz/a3-bskulls.git
cd a3-bskulls
```

For an existing clone whose `.devcontainer` submodule is empty:

```sh
git submodule update --init --recursive
```

The repository works as a standalone public clone; the private multi-repository
workspace is not required. To use the shared Dev Container, select the `arma3`
configuration and let its post-create bootstrap finish before opening
`Cfg*.hpp` files. It installs Java for the `skacekachna.sqflint` extension;
without Java, SQFLint repeatedly fails with `spawn java ENOENT`.

Review the relevant addon directory before making changes:

- `bskulls-modern`
- `bskulls-coldwar`
- `bskulls-nam`

Dependency declarations vary by addon and should be checked in the corresponding `CfgPatches.hpp`.

## Repository hygiene

This repository currently uses lightweight hygiene checks via pre-commit. Keep repo/process changes separate from gameplay or content changes whenever possible.

Preserve LF line endings unless an Arma tool or file format explicitly requires
otherwise. Keep local certificates, authentication state, private keys,
generated build output, editor state, and host-mounted Arma data out of Git.

Scenario sources belong in the separate `a3-scenarios` repository. When a
maintainer uses the private `a3-root` workspace for coupled faction/scenario
work, stage and commit each repository independently.

## Commit messages

This repository uses [Conventional Commits](https://www.conventionalcommits.org/).

### Subject line

Format:

```text
type(scope): short description
```

Examples:

- `feat(modern): add new unit loadout variant`
- `fix(coldwar): correct faction patch metadata`
- `docs(repo): document contribution workflow`

### Body

If a body is present, each line must start with a hyphen and a space:

```text
feat(modern): add new unit loadout variant

- feat: add updated unit config
- fix: align script references with the new loadout
- docs: note the change in repository documentation
```

Use `feat:` or `fix:` only when the change affects shipped addon content or
in-game behavior. `feat:` produces a minor addon release and `fix:` produces a
patch addon release. Use `ci:` for CI/workflow-only changes, `docs:` for
documentation-only changes, `chore:` for Dev Container, Makefile, editor, or
tooling maintenance, and `refactor:` for changes without player-visible or
mission-maker-visible behavior.

Validate a pull-request title against the same rules before a squash merge,
because GitHub uses that title for the resulting commit subject.

## Pull requests

Keep each pull request focused on a single logical change.

Before opening a pull request:

- confirm the change does not reorganize existing addon content unintentionally
- update documentation if repo/process expectations changed
- use Conventional Commit messages for commits and the pull-request title
- avoid including local/editor-generated files
- run `hemtt check` in every touched `bskulls-*` project
- run `pre-commit run --all-files` after repository/process changes when available

## Safety rules

- Do not rewrite git history without explicit approval.
- Do not use destructive git operations without explicit approval.
- Do not make broad addon-structure changes without explicit approval.
- Do not commit canonical scenario source or packed scenario PBOs here; those
  belong in `a3-scenarios`.
