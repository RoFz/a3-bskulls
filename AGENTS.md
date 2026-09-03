# Agent Instructions

These rules apply to agents working in this repository. Human contribution
guidance lives in `CONTRIBUTING.md`; keep the two files aligned.

## Project and repository boundaries

- This public repository owns the Black Skulls faction mod. It contains three
  independently versioned HEMTT projects: `bskulls-modern`,
  `bskulls-coldwar`, and `bskulls-nam`.
- The separate, currently private `a3-scenarios` repository owns scenario
  sources and packed scenario PBOs. DRO maps live there under `dro/<map>/`; do
  not vendor or copy their canonical source into this repository.
- The private `a3-root` repository can open `a3-bskulls` and `a3-scenarios` as
  independent sibling clones in one VS Code Dev Container. The child clones
  are ignored workspace content, not files or submodules of one another.
- When both repositories are present, coupled changes may touch both, but
  inspect, stage, commit, and report each repository separately. Resolve
  siblings relative to the workspace instead of assuming an absolute host or
  container path.
- `a3-bskulls` must remain fully usable as a standalone public clone. Do not
  make its normal build or validation depend on access to the private
  repositories.

## Scope and safety

- Prefer targeted changes. Do not reorganize existing addon directories unless
  explicitly approved.
- Keep repository/process changes separate from gameplay or content changes
  whenever possible.
- Do not rewrite Git history or use destructive Git operations without explicit
  approval.
- Only commit when the user asks.
- Preserve LF line endings. Do not add CRLF files unless an Arma tool or file
  format explicitly requires them.
- Do not commit `.hemttout/`, local PBOs, `.bisign` or `.bikey` files, private
  keys, authentication state, local certificates, editor state, or host-mounted
  Arma data. Signed release artifacts come from GitHub Actions on `main`.

## Research before changing code

Ground config, SQF, engine, and dependency work in evidence before editing. Do
not guess engine behavior, class inheritance, magazine/weapon compatibility, or
iterate blindly until `hemtt check` passes.

### Required sources

Search these first, in this order of trust:

1. Official Bohemia / Arma 3 documentation, including the Community Wiki,
   scripting-command reference, and configuration reference.
2. Reputable mainstream open-source mods and their configs, such as ACE3, CUP,
   RHS, and 3CB, when they demonstrate the same pattern.
3. Reported issues and confirmed workarounds on the
   [Bohemia Interactive forums](https://forums.bohemia.net/).

Cite the source and what it established whenever research drives a change.

### If facts are missing

Tell the user that the proposed change would be experimental. Present a small,
logical test plan: what will change, what success looks like, how it will be
observed (`hemtt check`, in-game behavior, or `.rpt` files under
`/arma3/logs`), and when testing stops. Wait for agreement unless the user
already requested an experiment.

### Web search

Prefer the Perplexity MCP when it is available. Use another available search
tool only when Perplexity is unavailable, errors, or the user asks for a
different source.

- `perplexity_search` finds ranked URLs and snippets.
- `perplexity_ask` provides a short cited answer.
- `perplexity_reason` supports cited multi-step comparison or compatibility
  analysis.
- `perplexity_research` is reserved for requested deep investigations, not
  routine lookups.

Restrict searches to official or high-signal domains when useful, such as
`community.bistudio.com`, `forums.bohemia.net`, and `github.com`.

### Multi-item work

When the user asks for multiple builds, fixes, or investigations, present a
numbered list before starting. Preserve those numbers in progress updates,
questions, and results.

## Git commits and pull requests

All commit subjects use Conventional Commits:

```text
type(scope): short description
```

Examples:

- `feat(modern): add new unit loadout variant`
- `fix(coldwar): correct faction patch metadata`
- `docs(repo): document contribution workflow`
- `chore(devcontainer): update shared Arma environment`
- `ci(release): keep release PRs synchronized`

Common scopes are `modern`, `coldwar`, `nam`, `devcontainer`, `build`, `ci`,
`release`, `repo`, and `deps`.

If a body is present, leave one blank line after the subject. Start every body
line with `- ` followed by a Conventional Commit identifier:

```text
feat(modern): add new unit loadout variant

- feat: add updated unit config
- fix: align script references with the new loadout
- docs: note the change in repository documentation
```

### Release-triggering types

Release Please uses commit types to version each addon. Use `feat:` or `fix:`
only for shipped addon content or behavior:

- `feat:` triggers a minor release for a touched addon: new units, loadouts,
  vehicles, weapons, identities, scripts, textures, editor assets, or content
  dependencies that enable new capability.
- `fix:` triggers a patch release for a touched addon: incorrect config or
  script behavior, broken references, or metadata defects that affect players
  or mission makers.

Do not use `feat:` or `fix:` for these changes:

- Dev Container, Makefile, editor, or local workflow work: use `chore:` or
  `docs:`.
- CI or GitHub workflow-only work: use `ci:`.
- Documentation-only work: use `docs:`.
- Tooling or dependency maintenance without shipped-content impact: use
  `chore:` or `chore(deps):`.
- Refactors without player-visible or mission-maker-visible behavior changes:
  use `refactor:`.

Split content and process work when practical. If they must share a commit, the
subject type reflects the release-impacting part and each body line identifies
its own type.

Before committing, validate the final subject against these rules. Before a
squash merge, validate the pull-request title as well because GitHub uses that
title for the resulting commit subject.

## Local checks

Use the repository's actual tooling:

- Run `hemtt check` inside each touched project directory:
  `bskulls-modern`, `bskulls-coldwar`, or `bskulls-nam`.
- Run `pre-commit run --all-files` after repository or process changes when
  pre-commit is available.
- Run `make modern`, `make cold`, `make nam`, or `make all` for the local
  launcher loop. These commands build unsigned PBOs and copy them under
  `/arma3/mods/@bskulls-*/Addons/`; they are not release builds.
- Run the report-only dependency audit from the repository root with, for
  example:

  ```text
  python3 tools/audit_required_addons.py bskulls-modern/addons/bskulls-modern
  ```

Do not suggest committing `.hemttout/` or anything installed under
`/arma3/mods`.

## Shared Dev Container

- `.devcontainer/` is a pinned Git submodule of the public
  `a3-devcontainers` repository. Use the `arma3` variant at
  `.devcontainer/arma3/devcontainer.json`.
- The submodule pins the whole shared repository at an exact commit; it does
  not follow that repository's default branch automatically. Treat changes
  inside `.devcontainer` as changes to the separate `a3-devcontainers`
  repository, not as ordinary `a3-bskulls` files.
- After a shared environment change is committed and pushed, explicitly assess
  every known consumer: `a3-root`, `a3-bskulls`, and `a3-scenarios`. Update the
  `.devcontainer` gitlink in each affected consumer. Use
  `chore(devcontainer): update shared Arma environment` for a pointer-only
  consumer commit.
- Keep the shared environment project-agnostic. Never hard-code a consumer
  repository name or absolute host path in its implementation.
- The host variables and container targets are:

  ```text
  A3_MODS_DIR      -> /arma3/mods
  A3_RPT_DIR       -> /arma3/logs
  A3_WORKSHOP_DIR  -> /arma3/workshop
  A3_DOCUMENTS_DIR -> /arma3/documents
  A3_GAME_DIR      -> /arma3/game
  ```

- These variables must resolve to existing host directories before container
  creation. `A3_WORKSHOP_DIR` must target Steam's
  `steamapps/workshop/content/107410`, not Arma's `!Workshop` junctions. Fully
  quit VS Code after changing host environment variables so `${localEnv:...}`
  is refreshed.
- All consumers intentionally share the `a3-bskulls-codex` named volume at
  `/home/vscode/.codex`. Preserve that name unless the user explicitly requests
  a change. Keep Codex authentication and `.codex*` state out of Git.
- Cursor is not supported. Do not add Cursor-only configuration.
- Personal certificates belong under
  `.devcontainer/arma3/.local-certs/`. The shared repository ignores that
  directory while including it in the local Docker build context.
- After a Dev Container change, use static JSON, shell, path, and consumer-pin
  checks. Do not build or rebuild a container unless the user explicitly asks.

## GitHub access

Prefer the `gh` CLI for workflow logs, pull requests, repository settings, and
releases when it is available. If it is unavailable, use a narrowly scoped
read-only API fallback and do not expose credentials.
