# QMK Build Repo for 61_white

This repository is set up for remote GitHub Actions builds of the custom keyboard
`61_white` with the `default` keymap using the official QMK CLI container.

## Files

- `.github/workflows/build.yaml` stages this repo as `keyboards/61_white` inside the QMK checkout and builds `61_white/default` on every push and on manual dispatch.
- `keymaps/default/keymap.c` contains the default keymap.
- `config.h`, `info.json`, `rules.mk`, `keyboard.c`, `keyboard.h`, `source.c`, and `via.json` are staged into the `keyboards/61_white` directory during the workflow.

## Metadata

- `info.json` contains the QMK keyboard definition used for compilation.
- `keyboard.json` remains as the original configurator export reference and is not used as build metadata.

## Build output

After pushing to GitHub, open the Actions tab, run or inspect `Build QMK firmware`,
and download the generated artifact for `61_white-default` (`.hex`, `.bin`, or `.uf2`, depending on the board target).

## Notes

This repository is not a local QMK checkout. The workflow checks out `qmk/qmk_firmware`,
stages this repository as a custom keyboard under `keyboards/61_white/`,
and compiles the `default` keymap remotely on GitHub Actions.