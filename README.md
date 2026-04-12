# QMK Userspace for 0xc7/61key

This repository builds the firmware for the keymap in
`0xc7_61key_layout_60_ansi_2026-04-12.json` using GitHub Actions and the official
QMK CLI container.

## Files

- `.github/workflows/build.yaml` builds the firmware on every push and on manual dispatch.
- `0xc7_61key_layout_60_ansi_2026-04-12.json` is the exported QMK Configurator layout.
- `config.h`, `rules.mk`, and `source.c` provide the minimal userspace scaffold required by QMK.

## Build output

After pushing to GitHub, open the Actions tab, run or inspect `Build QMK firmware`,
and download the generated artifact (`.hex`, `.bin`, or `.uf2`, depending on the board target).

## Notes

This repository is structured as a QMK userspace repo, not a full fork of `qmk_firmware`.
The workflow checks out `qmk/qmk_firmware`, places this repository under `users/<github-actor>/`,
and compiles the JSON keymap directly.