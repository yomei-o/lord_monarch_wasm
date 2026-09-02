"""Dump the game's window descriptors - what sub_4a4d is handed.

    python tools/lmwin.py            every descriptor this file knows about
    python tools/lmwin.py 1105 ...   just these

`sub_4a4d` reads

    [si+0]  bx   position, handed straight to sub_4b61 (bh = column in bytes,
                 bl = row in units of eight lines)
    [si+2]  cx   cl = how many lines follow (ch is the frame's width, used by
                 sub_4b61)
    [si+4]  cl words, each the address of a sub_759b format string

and puts line n at di = 2 * (bl * 8 * 80 + bh) + 0x50e + n * 0x500, i.e. the
lines are sixteen scanlines apart.

The strings are sub_759b's own format language (RESUME.md has it):

    >= 0x20   text, Shift-JIS
    <  0x20   a colour, minus 0x10, kept for whatever is drawn next
    '@'       a field: the next character indexes DS:0x2847
              ".0123456789sSbBwWlLoO?+tgGyY" - a digit is a width and the
              letter after it is the kind - and its argument is a word taken
              from after the string's NUL, one per field in order.

DS = 0 for this program, so a DS address is an offset into PROG.DAT once
PROG.DAT is unpacked (it is read to 0000:1000 by the boot sector).
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lmz

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DAT_BASE = 0x1000
FIELDS = ".0123456789sSbBwWlLoO?+tgGyY"

# Every descriptor address that appears as `mov si, imm` before a call to
# sub_4a4d, found with tools/lmdis.py.
KNOWN = [
    (0x10ff, ''), (0x1105, 'sub_b2f2 0xb410  the win, and its table'),
    (0x1119, 'sub_b2f2 0xb46b  somebody else won'),
    (0x1129, 'sub_b2f2 0xb41f  a new record, over the win'),
    (0x112f, 'sub_b28d 0xb2bc  your country has fallen'),
    (0x1137, 'sub_b197         a country has been destroyed'),
    (0x113f, ''), (0x1147, ''),
    (0x1153, '0x1b10           GO after the game is over'),
    (0x1159, ''), (0x115f, ''), (0x1165, ''), (0x116b, ''), (0x1177, ''),
    (0x117d, ''), (0x1183, ''), (0x1189, ''), (0x118f, ''), (0x1195, ''),
    (0x11a1, ''), (0x11a9, ''), (0x11b1, ''), (0x11c1, ''), (0x11c7, ''),
    (0x11d5, ''), (0x11dd, ''), (0x11e3, ''), (0x11ef, ''), (0x11f5, ''),
    (0x11fd, ''), (0x1209, ''), (0x120f, ''), (0x1215, ''), (0x1223, ''),
    (0x1233, ''), (0x123f, ''), (0x12a5, ''), (0x2958, ''),
]


def load():
    with open(os.path.join(ROOT, 'disk', 'PROG.DAT'), 'rb') as f:
        return lmz.unpack(f.read())[0]


def at(d, ds):
    return ds - DAT_BASE


def text(d, ds):
    """One sub_759b string, decoded, plus the words that follow its NUL."""
    i = at(d, ds)
    out = []
    fields = 0
    while i < len(d) and d[i]:
        b = d[i]
        if b == 0x40 and i + 1 < len(d):          # '@'
            k = chr(d[i + 1])
            out.append('@' + k)
            fields += 1
            i += 2
            continue
        if b < 0x20:
            out.append('<colour %d>' % (b - 0x10 if b >= 0x10 else b))
            i += 1
            continue
        if 0x81 <= b <= 0x9f or 0xe0 <= b <= 0xef:
            out.append(bytes(d[i:i + 2]).decode('shift_jis', 'replace'))
            i += 2
            continue
        # 0xa1..0xdf is one byte of half-width katakana, and the game ends most
        # of its lines with 0xa1 = the full stop.
        out.append(bytes(d[i:i + 1]).decode('shift_jis', 'replace'))
        i += 1
    args = []
    j = i + 1
    for _ in range(fields):
        if j + 2 <= len(d):
            args.append(struct.unpack_from('<H', d, j)[0])
            j += 2
    return ''.join(out), args


def window(d, ds, why=''):
    i = at(d, ds)
    bx, cx = struct.unpack_from('<HH', d, i)
    lines = cx & 0xff
    print('DS:%04x  %s' % (ds, why))
    print('  frame  sub_4b61 bx=%04x cx=%04x  -> column %d, row %d, '
          'width %d, %d line(s)' % (bx, cx, bx >> 8, bx & 0xff, cx >> 8, lines))
    for n in range(lines):
        p = struct.unpack_from('<H', d, i + 4 + n * 2)[0]
        s, args = text(d, p)
        print('  %2d  DS:%04x  %s%s' % (n, p, s,
              ('   args ' + ' '.join('DS:%04x' % a for a in args)) if args else ''))
    print()


def main():
    d = load()
    if len(sys.argv) > 1:
        for a in sys.argv[1:]:
            window(d, int(a, 16))
    else:
        for ds, why in KNOWN:
            window(d, ds, why)


main()
