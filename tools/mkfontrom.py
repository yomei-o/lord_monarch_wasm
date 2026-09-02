"""Builds a PC-98-shaped font image out of free BDF fonts.

    python tools/mkfontrom.py <8x16 JIS X 0201 bdf> <16x16 JIS X 0208 bdf> out.rom

The PC-98 keeps its glyphs in a font ROM that is NEC's, so it cannot be shipped
with a port.  But nothing stops us building a file of the same shape out of a
font that *can* be shipped, and the game does not care where the bits came
from.  The Shinonome fonts are the obvious source: 8x16 and 16x16 bitmaps
designed for Japanese, and their licence puts them in the public domain and
says in as many words that converting them to another format, embedding them
and redistributing them are all fine.

The layout is the one measured from a real 288768-byte image, and written down
in src/gfx.h:

    0x0000 + code * 8       8 x 8 ANK        (left blank here; nothing uses it)
    0x0800 + code * 16      8 x 16 ANK       by JIS X 0201 code
    0x1800 + n * 32         16 x 16          sixteen bytes of the left half then
                            sixteen of the right, with
                              n = (jisHi - 0x21) * 96 + (jisLo - 0x21) + 1

Ninety-six to the row rather than the ninety-four JIS actually uses, and that
extra +1, are not a guess: in a real image "0".."9" is a run of exactly ten
blocks starting at 208, "A".."Z" twenty-six at 225, hiragana eighty-three at
289 and NEC's row 13 thirty at 1153, and only that formula puts all four where
they are.
"""
import sys

SIZE = 0x46800
ANK16 = 0x0800
KANJI = 0x1800


def bdf_glyphs(path):
    """{encoding: [row ints]} plus the width, from a BDF."""
    out = {}
    width = None
    code = None
    rows = None
    with open(path, 'rb') as f:
        for raw in f:
            line = raw.decode('latin-1').strip()
            if line.startswith('ENCODING'):
                code = int(line.split()[1])
            elif line.startswith('BBX'):
                parts = line.split()
                width = int(parts[1])
            elif line == 'BITMAP':
                rows = []
            elif line == 'ENDCHAR':
                if code is not None and rows is not None:
                    out[code] = rows
                rows = None
            elif rows is not None and line:
                rows.append(int(line, 16))
    return out, width


def main():
    if len(sys.argv) < 4:
        raise SystemExit(__doc__)
    ankPath, kanjiPath, outPath = sys.argv[1], sys.argv[2], sys.argv[3]

    rom = bytearray(SIZE)

    ank, ankWidth = bdf_glyphs(ankPath)
    if ankWidth != 8:
        raise SystemExit('%s is %d wide, expected 8' % (ankPath, ankWidth))
    for code, rows in ank.items():
        if not 0 <= code <= 0xff:
            continue
        off = ANK16 + code * 16
        for i, v in enumerate(rows[:16]):
            rom[off + i] = v & 0xff

    kanji, kanjiWidth = bdf_glyphs(kanjiPath)
    if kanjiWidth != 16:
        raise SystemExit('%s is %d wide, expected 16' % (kanjiPath, kanjiWidth))
    placed = 0
    for code, rows in kanji.items():
        hi, lo = code >> 8, code & 0xff
        if not (0x21 <= hi <= 0x7e and 0x21 <= lo <= 0x7e):
            continue
        n = (hi - 0x21) * 96 + (lo - 0x21) + 1
        off = KANJI + n * 32
        if off + 32 > SIZE:
            continue
        for i, v in enumerate(rows[:16]):
            rom[off + i] = (v >> 8) & 0xff          # the left half
            rom[off + 16 + i] = v & 0xff            # and the right
        placed += 1

    with open(outPath, 'wb') as f:
        f.write(rom)
    print('%s  %d bytes, %d ANK glyphs, %d kanji' %
          (outPath, len(rom), len([c for c in ank if c <= 0xff]), placed))


if __name__ == '__main__':
    main()
