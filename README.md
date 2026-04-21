# QMK Build Repo for 61_white

This repository is set up for remote GitHub Actions builds of the custom keyboard
`61_white` with the `default` keymap using the QMK CLI.

## Files

- `.github/workflows/build.yaml` stages this repo as `keyboards/handwired/61_white` inside the QMK checkout and compiles the staged `default` keymap file on every push and on manual dispatch.
- `keymaps/default/keymap.c` contains the default keymap.
- `config.h`, `info.json`, `rules.mk`, `keyboard.c`, `keyboard.h`, and `source.c` are staged into the `keyboards/handwired/61_white` directory during the workflow.
- `via61.json` is the standalone VIA definition for the board.

## Metadata

- `info.json` is the authoritative QMK keyboard definition used for compilation.
- `keyboard.json` is kept only as a disposable QMK Configurator export reference and is not used as build metadata.
- When metadata changes, update `info.json`; regenerate or ignore `keyboard.json` as needed.

## Build output

After pushing to GitHub, open the Actions tab, run or inspect `Build QMK firmware`,
and download the generated artifact for `61_white-default` (`.hex`, `.bin`, or `.uf2`, depending on the board target).

## Notes

This repository is not a local QMK checkout. The workflow checks out `qmk/qmk_firmware`,
stages this repository as a custom keyboard under `keyboards/handwired/61_white/`,
and compiles the staged `default` keymap remotely on GitHub Actions.
