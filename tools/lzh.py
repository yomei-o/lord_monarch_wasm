"""Read an LZH archive - list or extract.

    python tools/lzh.py <archive.lzh>            list
    python tools/lzh.py <archive.lzh> <outdir>   extract

Written because no lha/7z is installed here.  Handles header levels 0/1/2 and
the -lh0- (stored) and -lh5-/-lh6-/-lh7- methods, which is everything a PC-98
era archive uses.  The compressed methods are LHA's static-Huffman-per-block
LZSS: each block carries a Huffman table for the literal/length alphabet, a
second one for the match offsets, and a third that codes the first table's own
code lengths.
"""
import os
import struct
import sys

# LHA's alphabet sizes.  NC covers 256 literals plus the match lengths
# (MAXMATCH - THRESHOLD + 1), NT codes the code lengths of that table.
NC = 510
NT = 19
CBIT = 9
TBIT = 5
THRESHOLD = 3

# method -> (dictionary bits, offset-table entries, bits for its length field)
METHODS = {
    b'-lh0-': None,                 # stored
    b'-lhd-': None,                 # directory
    b'-lh5-': (13, 14, 4),
    b'-lh6-': (15, 16, 5),
    b'-lh7-': (17, 17, 5),
}


def crc16(data):
    """CRC-16/ARC, which is what LHA stores."""
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc


class Bits:
    def __init__(self, data):
        self.d = data
        self.pos = 0
        self.byte = 0
        self.left = 0

    def get(self, n):
        v = 0
        for _ in range(n):
            if self.left == 0:
                self.byte = self.d[self.pos] if self.pos < len(self.d) else 0
                self.pos += 1
                self.left = 8
            v = (v << 1) | ((self.byte >> (self.left - 1)) & 1)
            self.left -= 1
        return v


class Huff:
    """Canonical Huffman decoder, same code assignment as LHA's make_table."""

    def __init__(self, lengths):
        self.map = {}
        self.maxlen = max(lengths) if lengths else 0
        code = 0
        for ln in range(1, self.maxlen + 1):
            for sym, l in enumerate(lengths):
                if l == ln:
                    self.map[(ln, code)] = sym
                    code += 1
            code <<= 1

    def decode(self, br):
        code = 0
        for ln in range(1, self.maxlen + 1):
            code = (code << 1) | br.get(1)
            sym = self.map.get((ln, code))
            if sym is not None:
                return sym
        raise ValueError('bad Huffman code')


def read_pt_len(br, nn, nbit, i_special):
    """The offset table, and (with nn=NT) the table that codes c_len."""
    n = br.get(nbit)
    if n == 0:
        return None, br.get(nbit)       # every code is this one symbol
    ln = [0] * nn
    i = 0
    while i < n and i < nn:
        c = br.get(3)
        if c == 7:
            while br.get(1):
                c += 1
        ln[i] = c
        i += 1
        if i == i_special:
            c = br.get(2)
            while c > 0 and i < nn:
                ln[i] = 0
                i += 1
                c -= 1
    return Huff(ln), None


def read_c_len(br, pt, pt_single):
    n = br.get(CBIT)
    if n == 0:
        return None, br.get(CBIT)
    ln = [0] * NC
    i = 0
    while i < n and i < NC:
        c = pt_single if pt is None else pt.decode(br)
        if c <= 2:
            if c == 0:
                c = 1
            elif c == 1:
                c = br.get(4) + 3
            else:
                c = br.get(CBIT) + 20
            while c > 0 and i < NC:
                ln[i] = 0
                i += 1
                c -= 1
        else:
            ln[i] = c - 2
            i += 1
    return Huff(ln), None


def unpack(data, size, method):
    dicbit, np, pbit = METHODS[method]
    br = Bits(data)
    out = bytearray()
    blocksize = 0
    ct = cs = pt2 = ps2 = None

    while len(out) < size:
        if blocksize == 0:
            blocksize = br.get(16)
            if blocksize == 0:
                break
            pt, ps = read_pt_len(br, NT, TBIT, 3)
            ct, cs = read_c_len(br, pt, ps)
            pt2, ps2 = read_pt_len(br, np, pbit, -1)
        blocksize -= 1
        c = cs if ct is None else ct.decode(br)
        if c < 256:
            out.append(c)
            continue
        length = c - 256 + THRESHOLD
        j = ps2 if pt2 is None else pt2.decode(br)
        off = 0 if j == 0 else (1 << (j - 1)) | br.get(j - 1)
        start = len(out) - off - 1
        if start < 0:
            raise ValueError('match before start of output')
        for k in range(length):
            out.append(out[start + k])
            if len(out) >= size:
                break
    return bytes(out[:size])


def entries(data):
    o = 0
    while o < len(data):
        hsize = data[o]
        if hsize == 0:
            break
        method = data[o + 2:o + 7]
        packed, original = struct.unpack_from('<II', data, o + 7)
        level = data[o + 20]

        if level in (0, 1):
            nlen = data[o + 21]
            name = data[o + 22:o + 22 + nlen].decode('shift_jis', 'replace')
            crc, = struct.unpack_from('<H', data, o + 22 + nlen)
            base_end = o + 2 + hsize
            if level == 0:
                body = base_end
                skip = packed
            else:
                # Level 1 keeps extended headers between the base header and the
                # body, and `packed` counts both, so walk them to find the body.
                p = base_end
                total_ext = 0
                while True:
                    nxt, = struct.unpack_from('<H', data, p - 2)
                    if nxt == 0:
                        break
                    total_ext += nxt
                    p += nxt
                body = p
                skip = packed - total_ext
            yield name, method, body, skip, original, crc
            o = body + skip
        elif level == 2:
            total, = struct.unpack_from('<H', data, o)
            crc, = struct.unpack_from('<H', data, o + 21)
            name = ''
            p = o + 24
            while True:
                nxt, = struct.unpack_from('<H', data, p)
                if nxt == 0:
                    break
                kind = data[p + 2]
                if kind == 1:
                    name = data[p + 3:p + nxt].decode('shift_jis', 'replace')
                p += nxt
            yield name, method, o + total, packed, original, crc
            o = o + total + packed
        else:
            raise ValueError('header level %d' % level)


def main():
    path = sys.argv[1]
    outdir = sys.argv[2] if len(sys.argv) > 2 else None
    data = open(path, 'rb').read()

    if outdir:
        os.makedirs(outdir, exist_ok=True)
    print('%-16s %-7s %9s %9s  %s' % ('name', 'method', 'packed', 'size', 'crc'))
    for name, method, body, packed, original, crc in entries(data):
        raw = data[body:body + packed]
        if METHODS.get(method) is None:
            plain = raw[:original]
        else:
            plain = unpack(raw, original, method)
        ok = 'ok' if crc16(plain) == crc else 'CRC MISMATCH'
        print('%-16s %-7s %9d %9d  %04x %s' %
              (name, method.decode(), packed, original, crc, ok))
        if outdir:
            out = os.path.join(outdir, os.path.basename(name.replace('\\', '/')))
            open(out, 'wb').write(plain)


if __name__ == '__main__':
    main()
