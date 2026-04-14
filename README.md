# QMK Build Repo for 61_white

This repository is set up for remote GitHub Actions builds of the custom keyboard
`61_white` with the `default` keymap using the official QMK CLI container.

## Files

- `.github/workflows/build.yaml` stages this repo as `61_white/default` inside QMK userspace and builds it on every push and on manual dispatch.
- `keymaps/default/keymap.c` contains the default keymap.
- `config.h`, `rules.mk`, `source.c`, and `keyboard.json` are staged into the `61_white` keyboard directory during the workflow.

## Build output

After pushing to GitHub, open the Actions tab, run or inspect `Build QMK firmware`,
and download the generated artifact for `61_white-default` (`.hex`, `.bin`, or `.uf2`, depending on the board target).

## Notes

This repository is not a local QMK checkout. The workflow checks out `qmk/qmk_firmware`,
stages this repository as a custom keyboard under `users/<github-actor>/keyboards/61_white/`,
and compiles the `default` keymap remotely on GitHub Actions.