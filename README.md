# The Black Skulls Faction (Ex Tenebris)

[![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/license-CC%20BY--NC--ND%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-nd/4.0/)

Black Skulls is an Arma 3 faction mod project that packages the group across multiple eras instead of as a single all-in-one setting. Each addon focuses on a different time period, with its own units, groups, vehicles, weapons, identities, scripts, textures, and editor assets.

![Black Skulls insignia](docs/assets/black_skulls_picture_256_256.png)

## Addons

- `bskulls-modern`: present-day / near-contemporary faction content
- `bskulls-coldwar`: Cold War-era faction content
- `bskulls-nam`: Vietnam-era faction content

These are released as separate addons and versioned independently.

## Install A Release In Arma 3

Each addon release currently ships as an individual `.pbo` file.

### Option 1: Arma 3 Launcher

1. Download the addon `.pbo` you want from the repository's Releases page.
2. Create a local mod folder somewhere on disk, for example:
   - `@bskulls-modern`
   - `@bskulls-coldwar`
   - `@bskulls-nam`
3. Inside that folder, create an `Addons` directory.
4. Copy the released `.pbo` into that `Addons` directory.
5. Open the Arma 3 Launcher.
6. Add the folder as a local mod and enable it in the launcher.

Example layout:

```text
@bskulls-modern/
  Addons/
    bskulls-modern_v0.1.0.pbo
```

### Option 2: Startup Parameter

You can also load the addon with Arma 3's `-mod=` startup parameter.

Example:

```text
-mod=@bskulls-modern
```

If you are loading multiple mods, separate them with semicolons.

Example:

```text
-mod=@CBA_A3;@bskulls-modern
```

## Dependencies

These addons depend on Arma 3 base content plus third-party mods. The dependency set is addon-specific, so check each addon's `CfgPatches.hpp` for the authoritative required addons list.

## Notes For Multiplayer Servers

All releases are signed. Each release includes:

- `.pbo`: the addon
- `.bisign`: the signature file, must sit alongside the `.pbo` in the mod's `Addons` folder
- `RoFz_bskulls.bikey`: the public key for server-side verification

Server-side setup:

- place the addon `.pbo` and its `.bisign` in the mod's `Addons` folder
- place `RoFz_bskulls.bikey` in the server's `keys` folder

## Repository Layout

- `addons/`: active HEMTT addon content
- `discarded/`: reference and study material kept for context, not for active builds
- `.hemtt/`: HEMTT project configuration
- `.github/workflows/`: CI and release automation

## Development Workflow

1. Make focused changes.
2. Avoid broad structural edits unless they are intentional and reviewed.
3. Use Conventional Commits.
4. Run `hemtt check` before opening a pull request.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for contribution rules, review expectations, and repository safety guidance.

## License

This repository is licensed under [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/).

In short: attribution is required, commercial use is not allowed, and redistribution of modified versions is not allowed under this license.
