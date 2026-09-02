# font/

`shinonome.fnt` is a font image in the shape the PC-98 keeps its glyphs in, so
that the dialogs can be drawn in the original's own Japanese.

The machine's own font ROM is NEC's and is not in this repository and never will
be. The layout of one, though, is just a layout, and nothing stops us filling it
with a font that *can* be shipped. This file is built from the **Shinonome**
bitmap fonts, whose licence puts them in the public domain and says in as many
words that converting them to another format, embedding them and redistributing
them are all fine — see `SHINONOME-LICENSE.txt`, which is the licence as it came,
converted from EUC-JP to UTF-8 and otherwise untouched.

    The Electronic Font Open Laboratory, 2001
    http://openlab.ring.gr.jp/efont/
    16-dot design by Yasuyuki Furukawa, 2000 (public domain)

Rebuilt with:

    python tools/mkfontrom.py \
        shnm8x16r.bdf shnmk16.bdf font/shinonome.fnt

from `xfonts-shinonome_0.9.11.orig.tar.gz`. `shnm8x16r` is the 8x16 JIS X 0201
half of it and `shnmk16` the 16x16 JIS X 0208 half; that comes to 221 ANK glyphs
and 6879 kanji, which is more than the game has anything to say with.

## The layout

Measured from a real 288768-byte image rather than looked up, and the same note
is in `src/gfx.h`:

| offset | contents |
|---|---|
| `0x0000 + code * 8` | 8x8 ANK — not used by this port, left blank here |
| `0x0800 + code * 16` | 8x16 ANK, by JIS X 0201 code |
| `0x1800 + n * 32` | 16x16, sixteen bytes of the left half then sixteen of the right |

where

    n = (jisHi - 0x21) * 96 + (jisLo - 0x21) + 1

Ninety-six to the row rather than the ninety-four JIS actually uses, and that
extra `+1`, are not guesses. In a real image `0`..`9` is a run of exactly ten
blocks starting at 208, `A`..`Z` twenty-six at 225, hiragana eighty-three at 289,
and NEC's row 13 — the circled numbers and the ㈱㍉ oddments — thirty at 1153.
Only that one formula puts all four where they are.

## Using the machine's own ROM instead

If you have a font ROM dumped from real hardware and would rather see the exact
glyphs the game shipped with, the port will take it:

    ./tmp/monarch_shot.exe tmp/monarch.fim view 0 16 out.png --fontrom font.rom

or drop a `font.rom` in the working directory, or pick one with the file input on
the web page — that one is read in your own browser and goes nowhere.
