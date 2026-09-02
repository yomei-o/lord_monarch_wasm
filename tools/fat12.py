"""List or extract the FAT12 filesystem out of a PC-98 floppy image.

    python tools/fat12.py <image>            list
    python tools/fat12.py <image> <outdir>   extract

PC-98 2HD floppies are FAT12 with 1024-byte sectors, 77 cylinders x 2 heads x 8
sectors = 1232 sectors of 1024 bytes.  Image formats differ only in what they put
in front of that:

    raw   nothing
    FIM   256 bytes: a little-endian 1, then 0x2000, then the track count (0x9a
          = 154 = 77 cylinders x 2 heads)
    FDI   4096 bytes
    HDM   4096 bytes

so the header is found by trying the known sizes and checking for a plausible
BIOS parameter block rather than trusting the extension.

Long names do not exist here - these are DOS 3.x disks - but subdirectories do,
and the demo disks use them, so the walk recurses.
"""
import os
import struct
import sys

HEADERS = (0, 256, 0x800, 0x1000)


def plausible(d, off):
    """Does a BIOS parameter block start at `off`?"""
    if off + 512 > len(d):
        return False
    bps, spc, res, nfat = struct.unpack_from('<HBHB', d, off + 11)
    if bps not in (128, 256, 512, 1024):
        return False
    if spc == 0 or spc > 8 or res == 0 or nfat not in (1, 2):
        return False
    root, total = struct.unpack_from('<HH', d, off + 17)
    if root == 0 or root > 1024:
        return False
    if total == 0:
        return False
    if off + total * bps > len(d) + bps:
        return False
    return True


class Fat12:
    def __init__(self, path):
        d = open(path, 'rb').read()
        self.base = None
        for h in HEADERS:
            if plausible(d, h):
                self.base = h
                break
        if self.base is None:
            raise ValueError('no BPB found at any known header offset')
        self.d = d
        o = self.base
        self.bps, self.spc, self.res, self.nfat = struct.unpack_from('<HBHB', d, o + 11)
        self.root_ents, self.total = struct.unpack_from('<HH', d, o + 17)
        self.spf, = struct.unpack_from('<H', d, o + 22)
        self.media = d[o + 21]

        self.fat_sec = self.res
        self.root_sec = self.res + self.nfat * self.spf
        self.root_secs = (self.root_ents * 32 + self.bps - 1) // self.bps
        self.data_sec = self.root_sec + self.root_secs
        self.clusters = (self.total - self.data_sec) // self.spc

    def sector(self, n):
        o = self.base + n * self.bps
        return self.d[o:o + self.bps]

    def fat_entry(self, n):
        fat = self.sector(self.fat_sec) + self.sector(self.fat_sec + 1) \
            if self.spf >= 2 else self.sector(self.fat_sec)
        # A 12-bit entry straddles bytes, so read a word at the byte offset.
        i = n + n // 2
        if i + 1 >= len(fat):
            return 0xfff
        v = fat[i] | (fat[i + 1] << 8)
        return (v >> 4) if (n & 1) else (v & 0xfff)

    def chain(self, start):
        out = []
        c = start
        seen = set()
        while 2 <= c < 0xff0 and c not in seen:
            seen.add(c)
            out.append(c)
            c = self.fat_entry(c)
        return out

    def read(self, start, size):
        buf = b''
        for c in self.chain(start):
            sec = self.data_sec + (c - 2) * self.spc
            for k in range(self.spc):
                buf += self.sector(sec + k)
            if len(buf) >= size:
                break
        return buf[:size]

    def dir_entries(self, raw):
        for o in range(0, len(raw), 32):
            e = raw[o:o + 32]
            if not e or e[0] == 0x00:
                return
            if e[0] == 0xe5:
                continue
            attr = e[11]
            if attr & 0x08:                    # volume label
                continue
            name = e[0:8].rstrip(b' ')
            ext = e[8:11].rstrip(b' ')
            n = name.decode('shift_jis', 'replace')
            if ext:
                n += '.' + ext.decode('shift_jis', 'replace')
            start, = struct.unpack_from('<H', e, 26)
            size, = struct.unpack_from('<I', e, 28)
            date, time = struct.unpack_from('<HH', e, 24), None
            yield dict(name=n, attr=attr, start=start, size=size,
                       dir=bool(attr & 0x10), raw=e)

    def root(self):
        raw = b''.join(self.sector(self.root_sec + i)
                       for i in range(self.root_secs))
        return list(self.dir_entries(raw))

    def walk(self, entries=None, path=''):
        if entries is None:
            entries = self.root()
        for e in entries:
            if e['dir']:
                if e['name'] in ('.', '..'):
                    continue
                sub = self.read(e['start'], self.spc * self.bps * 4096)
                yield path + e['name'] + '/', None
                for p, ee in self.walk(list(self.dir_entries(sub)),
                                       path + e['name'] + '/'):
                    yield p, ee
            else:
                yield path + e['name'], e


def main():
    img = sys.argv[1]
    outdir = sys.argv[2] if len(sys.argv) > 2 else None
    f = Fat12(img)
    print('%s: header %d bytes, %d bytes/sector, %d sectors, %d FATs of %d, '
          'root %d entries, data from sector %d, %d clusters' %
          (os.path.basename(img), f.base, f.bps, f.total, f.nfat, f.spf,
           f.root_ents, f.data_sec, f.clusters))
    if outdir:
        os.makedirs(outdir, exist_ok=True)
    total = 0
    for path, e in f.walk():
        if e is None:
            print('  %-24s <dir>' % path)
            if outdir:
                os.makedirs(os.path.join(outdir, path), exist_ok=True)
            continue
        print('  %-24s %8d' % (path, e['size']))
        total += e['size']
        if outdir:
            data = f.read(e['start'], e['size'])
            dst = os.path.join(outdir, path)
            os.makedirs(os.path.dirname(dst) or '.', exist_ok=True)
            open(dst, 'wb').write(data)
    print('%d bytes in files' % total)


if __name__ == '__main__':
    main()
