# pkm39

![*Planck-like Keyboard, Minimized for Personal Knowledge Management*.](pkm39.JPEG)

## pkm39は日本語文書におけるマークアップ言語/数式の入力を快適にするために生まれた、39キーのポータブルキーボードです。

* Keyboard Maintainer: [lil Pusher](https://github.com/Sahu)
* Hardware Supported: *RP2040(On-board)*
* Hardware Availability: *TBA(will be in 2024, booth or ebay)*

### デフォルトのファームウェアの書き込み

Make example for this keyboard (after setting up your build environment):

    make pkm39:default

Flashing example for this keyboard:

    make pkm39:default:flash

### IME切り替えのためのカスタムキーコードを含んだファームウェアの書き込み

Make example for this keyboard (after setting up your build environment):

    make pkm39:custom

Flashing example for this keyboard:

    make pkm39:default:custom

こちらのファームウェアはVIA, Remapに対応しています。

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

### Custom Keycodes on VIA/Remap

|Name on `keymap.c` | Name on VIA/Remap | Description |
|:-----------------:|:-----------------:|:------------:|
|EISUU   | User 1 | `Tap`: IME OFF(Send `Lang 2`)/Hold:  IME OFF and momentary activate  `Layer 2`|
|KANA    | User 2 | `Tap`: IME ON(Send `Lang 1`)/Hold:  IME ON and momentary activate  `Layer 1` |
|VIM_ESC | User 3 | IME OFF and send `ESC`|
|ALPHA   | User 4 | input string `\alpha` |
|BETA    | User 5 | input string `\beta` |
|GAMMA   | User 6 | input string `\gamma` |
|DELTA   | User 7 | input string `\delta` |
|EPSILON | User 8 | input string `\epsilon` |
|ZETA    | User 9 | input string `\zeta` |
|ETA     | User 10 | input string `\eta` |
|THETA   | User 11 | input string `\theta` |
|IOTA    | User 12 | input string `\iota` |
|KAPPA   | User 13 | input string `\kappa` |
|LAMBDA  | User 14 | input string `\lambda` |
|MU      | User 15 | input string `\mu` |
|NU      | User 16 | input string `\nu` |
|XI      | User 17 | input string `\xi` |
|OMICRON | User 18 | input string `\omicron` |
|PI      | User 19 | input string `\pi` |
|HO      | User 20 | input string `\rho` |
|SIGMA   | User 21 | input string `\sigma` |
|TAU     | User 22 | input string `\tau` |
|UPSILON | User 23 | input string `\upsilon` |
|PHI     | User 24 | input string `\phi` |
|CHI     | User 25 | input string `\chi` |
|PSI     | User 26 | input string `\psi` |
|OMEGA   | User 27 | input string `\omega` |
|INLINE   | User 28 | input string `$$` and move cursor to the center|
|BLOCK   | User 29 | begin `aligned` environment and set cursor to the center |
|GATHER   | User 30 | begin `gather` environment and set cursor to the center |
|FRAC   | User 31 | input string `\frac{}{}` and move cursor to the first brace|
|SQRT   | User 32 | input string `\sqrt{}` and move cursor to inside of the brace|
|LR   | User 33 | input string `\left\right` and move cursor between them|


## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: PCB裏にある二つのボタンを同時押しすることでファームウェアの書き込みを受け付けることができます。Briefly press the button on the back of the PCB.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

うっかりこれらの操作を意図せず行ってもあわてないでください。たいていの場合PCにつなぎなおせば問題ありません。

