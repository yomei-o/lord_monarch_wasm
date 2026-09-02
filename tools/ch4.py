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
# each masked with 0x0f and scaled by the fade level at DS:0x34d6.
#
# The tables themselves are **on the disk, appended to the 32x32 terrain
# banks**: every `B_0n0L.CH4` decompresses to 32816 bytes = 64 tiles of
# 32x32x4 planes (32768) plus **48 bytes**, and those 48 bytes are the palette,
# stored as plain 0..15 values rather than packed.  That is why searching
# PROG.BIN and PROG.DAT for them never turned anything up: the game reads them
# off the disk with the tileset and copies them into the RAM table at DS:0x249b.
#
# Indices 0..9 are identical in all five sets - they are the interface colours -
# and 10..15 change with the terrain, which is what makes one map look like
# grassland and another like stationery.  Cross-checked three ways and all three
# agree: index 8 = E80 against (13,7,0) measured off the retail frame, index 7 =
# FFF against #efefef in org45.gif, index 1/2/3/5/6/9 likewise.
import glob


def _scale(entries):
    """0..15 per channel -> 0..255, which is what a PNG and a DIB want."""
    return [(r * 17, g * 17, b * 17) for r, g, b in entries]


def tail_palette(path):
    """The 48-byte palette appended to a `B_0n0L.CH4`."""
    t = bzcat(path)[-48:]
    #                   B         R         G
    return _scale([(t[i * 3 + 1], t[i * 3 + 2], t[i * 3]) for i in range(16)])


def palette_for(terrain, where='disk'):
    """The palette belonging to terrain set 10 / 20 / 30 / 40 / 50."""
    return tail_palette(os.path.join(where, 'B_%03dL.CH4' % terrain))


# The title has no terrain bank, so its table is not appended to a .CH4 - it is
# inside PROG.DAT, which is packed with the boot sector's LZSS (lmz.py).  The
# game fades to the table at DS:24fb, and index 0 there is a blue that never
# shows: the screen is cleared first and DS7TTL laid over it with index 0
# transparent, so what you see behind the logo is index 1, black.  Checked
# against ss0.jpg - indices 1 and 3 come out exactly right that way.
PAL_TITLE_AT = 0x24fb
DAT_BASE = 0x1000


def palette_at(addr, where='disk'):
    """A 48-byte table at a DS: address inside PROG.DAT."""
    import lmz
    with open(os.path.join(where, 'PROG.DAT'), 'rb') as f:
        dat = lmz.unpack(f.read())[0]
    t = dat[addr - DAT_BASE: addr - DAT_BASE + 48]
    return _scale([(t[i * 3 + 1], t[i * 3 + 2], t[i * 3]) for i in range(16)])


def palette_title(where='disk'):
    return palette_at(PAL_TITLE_AT, where)


def _default():
    try:
        return palette_for(10)
    except Exception:
        return [(i * 17, i * 17, i * 17) for i in range(16)]


DEFAULT_PAL = _default()


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

    pal = DEFAULT_PAL
    if '--pal' in sys.argv:
        which = sys.argv[sys.argv.index('--pal') + 1]
        pal = palette_title() if which == 'title' else palette_for(int(which))

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
