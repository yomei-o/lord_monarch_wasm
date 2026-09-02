"""Draw a `.MAP` as a PNG by looking every cell up in a `.CH4` tile bank.

    python tools/map.py disk/B_000.MAP tmp/map.png              # 8x8
    python tools/map.py disk/B_000.MAP tmp/map.png --tile 16    # and 16x16
    python tools/map.py disk/B_000.MAP tmp/map.png --bank disk/B_020S.CH4

A `.MAP` decompresses to 2306 bytes.  The grid is **48 x 48 cells, one byte
each**, plus two bytes over - found by scanning every candidate row stride and
taking the one that minimises the mean absolute difference between a byte and
the byte one stride later: 48 wins by a wide margin (12.6 against 17.5 for its
nearest rival) and 96 shows up as its second harmonic, which is what a real
image does and a coincidence does not.

The two spare bytes are at the **end**, and they are a `uint16` naming the
terrain set: every one of the 52 maps holds 10, 20, 30, 40 or 50, and those are
exactly the five `B_010* B_020* B_030* B_040* B_050*` banks on the disk
(12 + 10 + 10 + 10 + 10 = 52).  So a map carries its own tileset and nothing
else has to be looked up.

Cell value = tile number in the bank.  `B_nnnS/M/L` are the same terrain set at
8x8 / 16x16 / 32x32, so the same map draws at three zooms - which is how the
game does its overview and its close-up.
"""
import os
import sys

import ch4

W = H = 48


def cells(path):
    data = ch4.bzcat(path)
    if len(data) < W * H + 2:
        raise SystemExit('%s: %d bytes, need at least %d' %
                         (path, len(data), W * H + 2))
    tail = data[W * H] | (data[W * H + 1] << 8)
    return data[:W * H], tail


def bank_for(mp, tail, tw):
    """The map's own terrain set, as B_0<n>0<size>.CH4 next to the map."""
    size = {8: 'S', 16: 'M', 32: 'L'}[tw]
    return os.path.join(os.path.dirname(mp), 'B_%03d%s.CH4' % (tail, size))


def bank(path, tw, th):
    """Split a .CH4 into per-tile index bitmaps."""
    data = ch4.bzcat(path)
    stride = tw // 8
    per = stride * th * 4
    out = []
    for i in range(len(data) // per):
        base = i * per
        pl = [data[base + p * stride * th: base + (p + 1) * stride * th]
              for p in range(4)]
        out.append(ch4.planes_to_indices(pl, tw, th))
    return out


def draw(cell, tiles, tw, th):
    rows = [[0] * (W * tw) for _ in range(H * th)]
    missing = set()
    for cy in range(H):
        for cx in range(W):
            n = cell[cy * W + cx]
            if n >= len(tiles):
                missing.add(n)
                continue
            t = tiles[n]
            for y in range(th):
                dst = rows[cy * th + y]
                src = t[y]
                for x in range(tw):
                    dst[cx * tw + x] = src[x]
    return rows, missing


def main():
    mp, dst = sys.argv[1], sys.argv[2]
    tw = th = 8
    bk = None
    for i, a in enumerate(sys.argv):
        if a == '--tile':
            tw = th = int(sys.argv[i + 1])
        elif a == '--bank':
            bk = sys.argv[i + 1]

    cell, tail = cells(mp)
    if bk is None:
        bk = bank_for(mp, tail, tw)
    tiles = bank(bk, tw, th)
    rows, missing = draw(cell, tiles, tw, th)
    ch4.png(dst, W * tw, H * th, rows, ch4.PAL_GAME)
    print('%s x %s -> %s  %dx%d cells of %dx%d, %d tiles in the bank, '
          'terrain set %d%s' %
          (os.path.basename(mp), os.path.basename(bk), dst, W, H, tw, th,
           len(tiles), tail,
           ', %d cell values past the bank: %s' %
           (len(missing), ' '.join('%02x' % m for m in sorted(missing)))
           if missing else ''))


if __name__ == '__main__':
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
