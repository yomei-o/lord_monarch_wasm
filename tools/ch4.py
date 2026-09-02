"""Dump a BZ-compressed PC-98 graphic from the Lord Monarch demo disk to a PNG.

    python tools/ch4.py disk/B_010M.CH4 tmp/b010m.png            tile bank
    python tools/ch4.py disk/WAKU tmp/waku.png --screen          four planes

`.CH4` is a bank of 4-plane tiles; `.B1/.R1/.G1/.E1` are the four bit planes of a
full 640x400 screen, one file each (32000 bytes = 640 * 400 / 8 after BZ).

Everything on the disk is squeezed with Falcom's own LZ.  That codec is the same
one the 1997 Windows Lord Monarch uses - measured, not assumed: the decoder
written for that game turns B_000.MAP into exactly 2306 bytes and WAKU.B1 into
exactly one plane's worth.  Only the codec carries over.  The art, the maps and
the program here are the PC-98 original's own and are used as they are.

Decompression goes through tmp/bzcat.exe, built from that decoder.
"""
import os
import struct
import subprocess
import sys
import zlib

# Palettes.  The hardware side comes from PROG.BIN and is exact: the setter at
# 0x5db7 walks a 48-byte table at DS:0x3e20, three bytes per index, and pushes
# them to ports 0xae, 0xac, 0xaa - so the order inside an entry is **B, R, G**,
# each masked with 0x0f and scaled by the fade level at DS:0x34d6.  Fades run
# through DS:0x249b + 0x30 * n; 0x24cb, 0x24fb and 0x252b are used by name.
#
# The table *contents* are not in PROG.DAT or PROG.BIN as 48 contiguous bytes -
# searched exhaustively, including a sweep over every possible fade level and
# over nibble-packed 24-byte forms - so they are built at run time and still
# have to be traced.  Until then these are **measured off the real screens**
# (ss0.jpg, ss3.jpg): per palette index, the median of the screenshot pixels at
# the centre of a run of >= 6 same-index pixels, which is what survives the
# JPEG.  4-bit values, scaled by 17.
def _pal(entries):
    out = [(0, 0, 0)] * 16
    for i, (r, g, b) in entries.items():
        out[i] = (r * 17, g * 17, b * 17)
    return out


# DS7TTL has no E1 plane, so the title only ever uses indices 0..6.
PAL_TITLE = _pal({
    0: (0, 0, 0), 1: (0, 2, 2), 2: (4, 14, 10), 3: (0, 8, 8),
    4: (4, 7, 7), 5: (7, 10, 10), 6: (10, 12, 12),
})

# 0..9 from WAKU (the in-game frame), which is the only screen that uses just
# frame art: 8 is the orange of the frame, 6 its yellow highlight, 1 the panel
# blue.  WAKU is byte-identical between the demo and the retail game, so these
# carry over.
#
# 10..14 are **provisional**, not measured.  They never appear in WAKU - only in
# the terrain tiles - and the only screenshot of a map to hand (ss3.jpg) is from
# the *retail* game, whose maps and character art differ from the demo's, so its
# map window cannot be aligned against anything on this disk.  What the tiles do
# say is which indices belong together: the grass cell (value 0x00, 33% of every
# cell on the disk) is drawn from indices 4, 12, 13 and 14 in that order of
# area, and the mountain cell (0x60) pairs index 10 with the frame orange.  So
# these are a green ramp plus two browns, picked to make development renders
# legible, and they will be replaced the moment the real tables turn up.
PAL_GAME = _pal({
    0: (0, 0, 0), 1: (0, 0, 10), 2: (10, 1, 0), 3: (8, 12, 14),
    4: (0, 11, 5), 5: (0, 10, 12), 6: (15, 12, 1), 7: (1, 11, 8),
    8: (13, 7, 0), 9: (1, 7, 11),
    10: (12, 8, 2), 11: (7, 4, 1), 12: (0, 9, 4), 13: (0, 13, 7),
    14: (0, 7, 3), 15: (15, 15, 15),
})

DEFAULT_PAL = PAL_GAME


ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BZCAT = os.path.join(ROOT, 'tmp', 'bzcat.exe')


def bzcat(path):
    """Decompress one file through the helper, returning the bytes.

    An absolute path with backslashes: CreateProcess does not resolve a relative
    one with forward slashes in it.
    """
    return subprocess.run([BZCAT, os.path.abspath(path)],
                          stdout=subprocess.PIPE, check=True).stdout


def png(path, w, h, rows, pal=DEFAULT_PAL):
    raw = b''.join(b'\0' + bytes(r) for r in rows)

    def chunk(tag, data):
        c = tag + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c))

    open(path, 'wb').write(
        b'\x89PNG\r\n\x1a\n' +
        chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 3, 0, 0, 0)) +
        chunk(b'PLTE', b''.join(bytes(c) for c in pal)) +
        chunk(b'IDAT', zlib.compress(raw, 9)) +
        chunk(b'IEND', b''))


def planes_to_indices(planes, w, h):
    """Combine four 1bpp planes into palette indices.

    The PC-98 forms the index as (E << 3) | (G << 2) | (R << 1) | B, which is the
    order the file extensions come in.
    """
    stride = w // 8
    rows = []
    for y in range(h):
        row = [0] * w
        for bit, p in enumerate(planes):
            if p is None:
                continue
            off = y * stride
            for xb in range(stride):
                if off + xb >= len(p):
                    break
                byte = p[off + xb]
                for k in range(8):
                    if byte & (0x80 >> k):
                        row[xb * 8 + k] |= 1 << bit
        rows.append(row)
    return rows


def tiles(data, tw, th, cols=16, zoom=1):
    """A bank of 4-plane tiles: per tile, plane 0 then 1 then 2 then 3."""
    stride = tw // 8
    per = stride * th * 4
    n = len(data) // per
    gw, gh = cols * (tw + 1), ((n + cols - 1) // cols) * (th + 1)
    sheet = [[0] * gw for _ in range(gh)]
    for i in range(n):
        base = i * per
        pl = [data[base + p * stride * th: base + (p + 1) * stride * th]
              for p in range(4)]
        cx, cy = (i % cols) * (tw + 1), (i // cols) * (th + 1)
        for y, row in enumerate(planes_to_indices(pl, tw, th)):
            for x, v in enumerate(row):
                sheet[cy + y][cx + x] = v
    if zoom > 1:
        big = []
        for r in sheet:
            rr = [v for v in r for _ in range(zoom)]
            for _ in range(zoom):
                big.append(rr)
        sheet, gw, gh = big, gw * zoom, gh * zoom
    return n, gw, gh, sheet


def main():
    src, dst = sys.argv[1], sys.argv[2]
    screen = '--screen' in sys.argv
    tw = th = 16
    cols, zoom = 16, 1
    for i, a in enumerate(sys.argv):
        if a == '--tile':
            tw = th = int(sys.argv[i + 1])
        elif a == '--cols':
            cols = int(sys.argv[i + 1])
        elif a == '--zoom':
            zoom = int(sys.argv[i + 1])

    pal = PAL_TITLE if '--pal' in sys.argv and         sys.argv[sys.argv.index('--pal') + 1] == 'title' else PAL_GAME

    if screen:
        pl = []
        for ext in ('B1', 'R1', 'G1', 'E1'):
            p = src + '.' + ext
            pl.append(bzcat(p) if os.path.exists(p) else None)
        rows = planes_to_indices(pl, 640, 400)
        png(dst, 640, 400, rows, pal)
        print('%s.* -> %s (640x400, planes %s)' %
              (src, dst, ''.join('BRGE'[i] for i, p in enumerate(pl) if p)))
        return

    data = bzcat(src)
    n, gw, gh, sheet = tiles(data, tw, th, cols, zoom)
    png(dst, gw, gh, sheet, pal)
    print('%s -> %s  %d bytes, %d tiles of %dx%d (%dx%d sheet)' %
          (src, dst, len(data), n, tw, th, gw, gh))


if __name__ == '__main__':
    main()
