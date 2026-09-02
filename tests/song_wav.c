/* Render one of the disk's songs to a WAV, so it can be looked at without a
 * sound card - and, on a machine whose desktop is in use, without making a
 * noise at all.
 *
 *   song_wav <image.fim> <n> [out.wav]      n as in FMnnn.DAT
 *
 * Only the three SSG tracks come out.  The three FM ones are in the file and
 * are read here for their lengths, but this program never loads an FM voice
 * (no 0x30, 0x50, 0x60, 0x70, 0x80 or 0xb0 is ever written to the chip), so on
 * this floppy they are silent however diligently the driver keys them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "sound.h"

/* The chip makes a sample every 72 clocks, which is 55,467 a second, and its
 * modulators put real energy well above 11 kHz.  Rendering at 22,050 folded
 * all of that back down as a ring on top of the note; 44,100 moves the fold
 * above most of it.  --rate takes anything. */
#define RATE_DEFAULT 44100
#define MAX_SAMPLES (RATE_DEFAULT * 200)

static void put32(FILE *f, unsigned v)
{
    fputc(v & 0xff, f); fputc(v >> 8 & 0xff, f);
    fputc(v >> 16 & 0xff, f); fputc(v >> 24 & 0xff, f);
}

static void put16(FILE *f, unsigned v)
{
    fputc(v & 0xff, f); fputc(v >> 8 & 0xff, f);
}

/* Set from --rate; see RATE_DEFAULT. */
static int rate = RATE_DEFAULT;

static void write_wav(const char *path, const short *pcm, long n)
{
    FILE *f = fopen(path, "wb");
    long i;

    if (!f) { fprintf(stderr, "%s: cannot write\n", path); return; }
    fwrite("RIFF", 1, 4, f);
    put32(f, (unsigned)(36 + n * 2));
    fwrite("WAVEfmt ", 1, 8, f);
    put32(f, 16);
    put16(f, 1);
    put16(f, 1);
    put32(f, rate);
    put32(f, rate * 2);
    put16(f, 2);
    put16(f, 16);
    fwrite("data", 1, 4, f);
    put32(f, (unsigned)(n * 2));
    for (i = 0; i < n; i++) put16(f, (unsigned)(unsigned short)pcm[i]);
    fclose(f);
    printf("%s  %.2fs at %d Hz\n", path, (double)n / rate, rate);
}

int main(int argc, char **argv)
{
    Disk *d;
    unsigned char *dat, *song;
    unsigned datN = 0, songN = 0;
    char name[32];
    short *pcm;
    long max;
    int n, t;

    if (argc < 3) {
        puts("song_wav <image.fim> <n> [out.wav] [--rate HZ]");
        return 2;
    }
    for (t = 1; t + 1 < argc; t++)
        if (!strcmp(argv[t], "--rate")) rate = atoi(argv[t + 1]);
    if (rate < 8000 || rate > 96000) rate = RATE_DEFAULT;
    d = disk_open(argv[1]);
    if (!d) { printf("%s\n", disk_error()); return 1; }
    dat = disk_read_lz(d, "PROG.DAT", &datN);
    if (!dat) { printf("PROG.DAT: %s\n", disk_error()); return 1; }
    snprintf(name, sizeof name, "FM%03d.DAT", atoi(argv[2]));
    song = disk_read_bz(d, name, &songN);
    if (!song) { printf("%s: %s\n", name, disk_error()); return 1; }
    printf("%s  %u bytes\n", name, songN);
    for (t = 0; t < 6; t++) {
        unsigned off = 0, len = 0;

        if (snd_song_track(song, songN, t, &off, &len))
            printf("  track %d (%s)  %04x  %u bytes\n", t,
                   t < 3 ? "FM " : "SSG", off, len);
        else
            printf("  track %d: no\n", t);
    }
    max = (long)rate * 200;
    pcm = (short *)calloc((size_t)max, sizeof *pcm);
    if (!pcm) return 1;
    n = snd_render_song(dat, datN, song, songN, pcm, (int)max, rate);
    if (n <= 0) { puts("nothing rendered"); return 1; }
    write_wav(argc > 3 ? argv[3] : "song.wav", pcm, n);
    return 0;
}
