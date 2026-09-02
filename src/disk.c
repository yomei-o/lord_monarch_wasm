#include "disk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bz.h"
#include "lmz.h"

#define MAX_ENTRIES 256
#define MAX_UNPACKED (1u << 21)

typedef struct {
    char name[13];              /* "PROG.BIN", NUL-terminated */
    unsigned short start;       /* first cluster */
    unsigned size;
} Entry;

struct Disk {
    unsigned char *img;
    unsigned imgSize;
    unsigned hdr;               /* bytes of container header before sector 0 */
    unsigned bps, spc, rootSec, rootSecs, dataSec, fatSec;
    Entry ent[MAX_ENTRIES];
    int nent;
};

static char errbuf[256];

const char *disk_error(void) { return errbuf; }

static unsigned rd16(const unsigned char *p) { return p[0] | (p[1] << 8); }
static unsigned rd32(const unsigned char *p)
{
    return rd16(p) | ((unsigned)rd16(p + 2) << 16);
}

/* A container header is 0 (raw), 256 (FIM) or 4096 (FDI/HDM) bytes, and no
 * extension tells you reliably which - so try each and keep the one whose BPB
 * makes sense.  This is the same test tools/fat12.py makes. */
static int plausible(const unsigned char *p, unsigned avail)
{
    unsigned bps = rd16(p + 0x0b), spc = p[0x0d], nfat = p[0x10];
    unsigned root = rd16(p + 0x11), total = rd16(p + 0x13);
    unsigned spf = rd16(p + 0x16), res = rd16(p + 0x0e);
    if (bps != 256 && bps != 512 && bps != 1024) return 0;
    if (spc == 0 || spc > 8) return 0;
    if (nfat != 1 && nfat != 2) return 0;
    if (root == 0 || root > 1024 || (root * 32) % bps) return 0;
    if (total == 0 || spf == 0 || res == 0) return 0;
    return (unsigned long)total * bps <= avail;
}

static const unsigned char *sector(Disk *d, unsigned n)
{
    unsigned off = d->hdr + n * d->bps;
    if (off + d->bps > d->imgSize) return 0;
    return d->img + off;
}

/* FAT12: two entries share three bytes. */
static unsigned fat_entry(Disk *d, unsigned n)
{
    unsigned off = n + (n >> 1);        /* n * 3 / 2 */
    unsigned sec = d->fatSec + off / d->bps, in = off % d->bps;
    const unsigned char *s = sector(d, sec);
    unsigned lo, hi;
    if (!s) return 0xfff;
    lo = s[in];
    if (in + 1 < d->bps) {
        hi = s[in + 1];
    } else {
        const unsigned char *t = sector(d, sec + 1);
        hi = t ? t[0] : 0xff;
    }
    return (n & 1) ? ((lo >> 4) | (hi << 4)) & 0xfff : (lo | (hi << 8)) & 0xfff;
}

static void trim_name(const unsigned char *e, char *out)
{
    int i, n = 0;
    for (i = 0; i < 8 && e[i] != ' '; i++) out[n++] = (char)e[i];
    if (e[8] != ' ') {
        out[n++] = '.';
        for (i = 8; i < 11 && e[i] != ' '; i++) out[n++] = (char)e[i];
    }
    out[n] = 0;
}

Disk *disk_open(const char *path)
{
    static const unsigned tries[] = {0, 256, 0x800, 0x1000};
    Disk *d;
    FILE *f = fopen(path, "rb");
    long n;
    unsigned i, s;
    const unsigned char *bpb;

    errbuf[0] = 0;
    if (!f) {
        snprintf(errbuf, sizeof errbuf, "cannot open %s", path);
        return 0;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    d = (Disk *)calloc(1, sizeof *d);
    d->img = (unsigned char *)malloc((size_t)n);
    d->imgSize = (unsigned)n;
    if (fread(d->img, 1, (size_t)n, f) != (size_t)n) {
        snprintf(errbuf, sizeof errbuf, "short read on %s", path);
        fclose(f);
        disk_close(d);
        return 0;
    }
    fclose(f);

    d->hdr = 0xffffffffu;
    for (i = 0; i < sizeof tries / sizeof *tries; i++) {
        if (tries[i] + 0x20 > d->imgSize) continue;
        if (plausible(d->img + tries[i], d->imgSize - tries[i])) {
            d->hdr = tries[i];
            break;
        }
    }
    if (d->hdr == 0xffffffffu) {
        snprintf(errbuf, sizeof errbuf, "%s: no FAT12 BPB at any known "
                 "header offset", path);
        disk_close(d);
        return 0;
    }

    bpb = d->img + d->hdr;
    d->bps = rd16(bpb + 0x0b);
    d->spc = bpb[0x0d];
    d->fatSec = rd16(bpb + 0x0e);
    d->rootSec = d->fatSec + (unsigned)bpb[0x10] * rd16(bpb + 0x16);
    d->rootSecs = rd16(bpb + 0x11) * 32 / d->bps;
    d->dataSec = d->rootSec + d->rootSecs;

    for (s = 0; s < d->rootSecs; s++) {
        const unsigned char *sec = sector(d, d->rootSec + s);
        unsigned o;
        if (!sec) break;
        for (o = 0; o + 32 <= d->bps; o += 32) {
            const unsigned char *e = sec + o;
            if (e[0] == 0x00) { s = d->rootSecs; break; }   /* end of dir */
            if (e[0] == 0xe5 || (e[11] & 0x08)) continue;   /* erased, label */
            if (e[11] & 0x10) continue;                     /* directory */
            if (d->nent >= MAX_ENTRIES) continue;
            trim_name(e, d->ent[d->nent].name);
            d->ent[d->nent].start = (unsigned short)rd16(e + 26);
            d->ent[d->nent].size = rd32(e + 28);
            d->nent++;
        }
    }
    return d;
}

void disk_close(Disk *d)
{
    if (!d) return;
    free(d->img);
    free(d);
}

int disk_count(Disk *d) { return d ? d->nent : 0; }

const char *disk_name(Disk *d, int i)
{
    return (d && i >= 0 && i < d->nent) ? d->ent[i].name : "";
}

static int same(const char *a, const char *b)
{
    for (; *a && *b; a++, b++) {
        int x = *a, y = *b;
        if (x >= 'a' && x <= 'z') x -= 32;
        if (y >= 'a' && y <= 'z') y -= 32;
        if (x != y) return 0;
    }
    return *a == *b;
}

unsigned char *disk_read(Disk *d, const char *name, unsigned *sizeOut)
{
    int i;
    unsigned char *out;
    unsigned got = 0, cl;

    errbuf[0] = 0;
    if (sizeOut) *sizeOut = 0;
    if (!d) return 0;
    for (i = 0; i < d->nent; i++)
        if (same(d->ent[i].name, name)) break;
    if (i == d->nent) {
        snprintf(errbuf, sizeof errbuf, "%s: not on the disk", name);
        return 0;
    }
    out = (unsigned char *)malloc(d->ent[i].size ? d->ent[i].size : 1);
    cl = d->ent[i].start;
    while (got < d->ent[i].size && cl >= 2 && cl < 0xff0) {
        unsigned k;
        for (k = 0; k < d->spc && got < d->ent[i].size; k++) {
            const unsigned char *s =
                sector(d, d->dataSec + (cl - 2) * d->spc + k);
            unsigned take = d->ent[i].size - got;
            if (!s) {
                snprintf(errbuf, sizeof errbuf, "%s: cluster %u off the image",
                         name, cl);
                free(out);
                return 0;
            }
            if (take > d->bps) take = d->bps;
            memcpy(out + got, s, take);
            got += take;
        }
        cl = fat_entry(d, cl);
    }
    if (got != d->ent[i].size) {
        snprintf(errbuf, sizeof errbuf, "%s: chain ended after %u of %u bytes",
                 name, got, d->ent[i].size);
        free(out);
        return 0;
    }
    if (sizeOut) *sizeOut = got;
    return out;
}

unsigned char *disk_read_lz(Disk *d, const char *name, unsigned *sizeOut)
{
    unsigned packed = 0, want, got;
    unsigned char *in = disk_read(d, name, &packed), *out;

    if (sizeOut) *sizeOut = 0;
    if (!in) return 0;
    want = lmz_size(in, packed);
    if (want == 0) {
        snprintf(errbuf, sizeof errbuf, "%s: no LZSS header", name);
        free(in);
        return 0;
    }
    out = (unsigned char *)malloc(want);
    got = lmz_unpack(in, packed, out, want);
    free(in);
    if (got != want) {
        snprintf(errbuf, sizeof errbuf, "%s: unpacked %u of %u bytes",
                 name, got, want);
        free(out);
        return 0;
    }
    if (sizeOut) *sizeOut = got;
    return out;
}

unsigned char *disk_read_bz(Disk *d, const char *name, unsigned *sizeOut)
{
    unsigned packed = 0, produced = 0;
    unsigned char *in = disk_read(d, name, &packed), *out;

    if (sizeOut) *sizeOut = 0;
    if (!in) return 0;
    out = (unsigned char *)malloc(MAX_UNPACKED);
    if (!bzDecompress(in, packed, out, MAX_UNPACKED, &produced) ||
        produced == 0) {
        snprintf(errbuf, sizeof errbuf, "%s: not BZ (or corrupt)", name);
        free(in);
        free(out);
        return 0;
    }
    free(in);
    if (sizeOut) *sizeOut = produced;
    return out;
}
