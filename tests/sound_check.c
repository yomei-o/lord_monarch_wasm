/* Checks the sound sequences against the disk.
 *
 *   tmp/sound_check.exe tmp/monarch.fim
 *
 * There is no synthesiser yet, so what this can check is everything up to one:
 * that the chromatic table really is one, that every effect terminates, and
 * that the notes each effect plays are inside the range a YM2203 can express.
 * Those are the things a wrong reading of the format would break.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "sound.h"

static int failures;

static void check(int ok, const char *what)
{
    if (!ok) {
        printf("FAIL  %s\n", what);
        failures++;
    }
}

static void checkf(int ok, const char *fmt, int a, int b)
{
    if (!ok) {
        printf("FAIL  ");
        printf(fmt, a, b);
        printf("\n");
        failures++;
    }
}

/* Sixteen wide even though only twelve are notes: the table used to be twelve
 * and a wrong reading of the format handed it a fifteen, which under -O2 came
 * out as a segfault rather than as a failing check. */
static const char *NOTE[16] = {
    "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B ",
    "?c", "?d", "?e", "?f"
};

int main(int argc, char **argv)
{
    Disk *d = disk_open(argc > 1 ? argv[1] : "tmp/monarch.fim");
    unsigned char *dat;
    unsigned n = 0;
    const unsigned char *fnum;
    int id;

    if (!d) {
        fprintf(stderr, "%s\n", disk_error());
        return 1;
    }
    dat = disk_read_lz(d, "PROG.DAT", &n);
    if (!dat) {
        fprintf(stderr, "PROG.DAT: %s\n", disk_error());
        return 1;
    }
    check(n > (unsigned)(SND_FNUM_AT - 0x1000) + 32, "PROG.DAT holds the table");
    fnum = dat + (SND_FNUM_AT - 0x1000);

    /* The twelve words at DS:0x244d are a chromatic octave: each step is the
     * twelfth root of two away from the one before, and at block 4 the whole
     * thing lands on concert pitch. */
    {
        int i;
        double prev = 0;
        for (i = 0; i < 12; i++) {
            double hz = snd_note_hz(fnum, 0x40 | i, 0);
            double want = 261.6255653 * 1.0;
            int k;
            for (k = 0; k < i; k++) want *= 1.0594630943592953;
            printf("  %s  fnum %4d   %8.2f Hz  (equal temperament %8.2f)\n",
                   NOTE[i], fnum[i * 2] | (fnum[i * 2 + 1] << 8), hz, want);
            checkf(hz > want * 0.995 && hz < want * 1.005,
                   "semitone %d is %d Hz off equal temperament", i,
                   (int)(hz - want));
            checkf(i == 0 || hz > prev, "semitone %d does not rise", i, 0);
            prev = hz;
        }
    }

    /* Every effect has to terminate, and every note it plays has to be one a
     * YM2203 can express - block 0..7 and a semitone under twelve. */
    for (id = 0; id < SND_EFFECTS; id++) {
        SndVoice v;
        int t, notes = 0, keyed;
        char line[256];
        int at = 0;

        if (!snd_start(&v, dat, n, id)) {
            printf("FAIL  effect %d will not load\n", id);
            failures++;
            continue;
        }
        line[0] = 0;
        for (t = 0; t < 4000; t++) {
            if (!snd_tick(&v, &keyed)) break;
            if (!keyed) continue;
            notes++;
            checkf((v.note & 0x0f) < 12,
                   "effect %d plays semitone %d, which does not exist", id,
                   v.note & 0x0f);
            if (at < 200)
                at += snprintf(line + at, sizeof line - at, "%s%d ",
                               NOTE[v.note & 0x0f], (v.note >> 4) & 7);
        }
        checkf(t < 4000, "effect %d never ends (%d ticks)", id, t);
        printf("effect %2d: %2d notes over %4d ticks  %s\n", id, notes, t,
               line);
        checkf(notes > 0, "effect %d plays nothing", id, 0);
    }

    free(dat);
    disk_close(d);
    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("ok\n");
    return 0;
}
