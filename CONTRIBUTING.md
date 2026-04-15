# Contributing

## Scope

This repository preserves existing addon content and layout. Prefer targeted changes, and do not reorganize existing addon directories unless that work has been explicitly approved.

## Getting started

```sh
git clone https://github.com/RoFz/a3-bskulls.git
cd a3-bskulls
```

If you are using the repo devcontainer, let the post-create bootstrap finish before opening `Cfg*.hpp` files in VS Code. It installs Java for the `skacekachna.sqflint` extension, and without it SQFLint will repeatedly fail with `spawn java ENOENT`.

Review the relevant addon directory before making changes:

- `bskulls-modern`
- `bskulls-coldwar`
- `bskulls-nam`

Dependency declarations vary by addon and should be checked in the corresponding `CfgPatches.hpp`.

## Repository hygiene

This repository currently uses lightweight hygiene checks via pre-commit. Keep repo/process changes separate from gameplay or content changes whenever possible.

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

Reserve `feat:` and `fix:` for real addon/content or dependency changes. Use `docs:`, `chore:`, `ci:`, `refactor:`, and similar types for repository and process work.

## Pull requests

Keep each pull request focused on a single logical change.

Before opening a pull request:

- confirm the change does not reorganize existing addon content unintentionally
- update documentation if repo/process expectations changed
- use Conventional Commit messages
- avoid including local/editor-generated files

## Safety rules

- Do not rewrite git history without explicit approval.
- Do not use destructive git operations without explicit approval.
- Do not make broad addon-structure changes without explicit approval.
