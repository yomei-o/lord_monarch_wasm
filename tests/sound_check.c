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
#include <math.h>

#include "disk.h"
#include "sound.h"
#include "ssg.h"

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

    /* The SSG's own table, which sits directly after the FM one - DS:0x244d
     * plus twelve words is DS:0x2465 exactly, which is why the FM table looked
     * as though it had four odd entries on the end.  At octave 0 it is the
     * bottom of the piano: A comes out at 27.50 Hz, which is that note by
     * definition. */
    {
        const unsigned char *per = dat + (SSG_PERIOD_AT - 0x1000);
        double a0 = ssg_period_hz(ssg_period(per, 0x09, 0));
        double a4 = ssg_period_hz(ssg_period(per, 0x49, 0));
        printf("  SSG A octave 0 %7.2f Hz, octave 4 %7.2f Hz\n", a0, a4);
        checkf(a0 > 27.4 && a0 < 27.6, "SSG A0 is %d.%02d Hz", (int)a0,
               (int)((a0 - (int)a0) * 100));
        /* 442.55, not 440, and that is the game's own answer rather than a
         * mistake: the table sits at octave 0 and sub_1539 shifts right, so
         * 2269 >> 4 truncates to 141 where the exact value would be 141.8.
         * The part is handed a whole number, so a whole number is what it
         * plays.  A quarter of a semitone is the honest bound. */
        checkf(a4 > 440.0 * 0.986 && a4 < 440.0 * 1.014,
               "SSG A4 is %d.%02d Hz, over a quarter tone from 440",
               (int)a4, (int)((a4 - (int)a4) * 100));

        /* And the chip really makes that note.  Render a second of A4 on
         * channel A and find the strongest frequency by hand - a square wave's
         * fundamental is its loudest part, so the peak is the pitch. */
        {
            static short pcm[16000];
            Ssg chip;
            int p = ssg_period(per, 0x49, 0);
            int rate = 16000, i, best = 0;
            double bestPower = -1;

            ssg_reset(&chip);
            ssg_write(&chip, 0, p & 0xff);
            ssg_write(&chip, 1, (p >> 8) & 0x0f);
            ssg_write(&chip, 8, 0x0f);
            ssg_write(&chip, 7, 0x3e);          /* tone on channel A only */
            ssg_render(&chip, pcm, rate, rate);

            for (i = 200; i < 1200; i++) {
                double re = 0, im = 0, w = 2.0 * 3.14159265358979 * i / rate;
                int k;
                for (k = 0; k < rate; k++) {
                    re += pcm[k] * cos(w * k);
                    im += pcm[k] * sin(w * k);
                }
                if (re * re + im * im > bestPower) {
                    bestPower = re * re + im * im;
                    best = i;
                }
            }
            /* The chip has to agree with the period it was handed, whatever
             * that period happens to round to. */
            {
                double want = ssg_period_hz(p);
                printf("  the chip's loudest frequency is %d Hz, and the "
                       "period asks for %.2f\n", best, want);
                checkf(best > want - 3 && best < want + 3,
                       "the rendered note peaks at %d Hz against %d asked for",
                       best, (int)want);
            }
        }
    }

    /* And a whole effect, rendered the way the port will play it.  Effect 6 is
     * a G-B-D arpeggio, so its first note should measure as that G. */
    {
        static short pcm[48000];
        int rate = 16000;
        int made = snd_render_effect(dat, n, 6, pcm, 48000, rate);
        const unsigned char *per = dat + (SSG_PERIOD_AT - 0x1000);
        double want = ssg_period_hz(ssg_period(per, 0x47, 0));
        int best = 0, i;
        double bestPower = -1;
        int window = rate / 20;             /* the first twentieth of a second */

        printf("  effect 6 rendered %d samples at %d Hz\n", made, rate);
        checkf(made > rate / 20, "effect 6 made only %d samples", made, 0);
        if (window > made) window = made;
        for (i = 200; i < 900; i++) {
            double re = 0, im = 0, w = 2.0 * 3.14159265358979 * i / rate;
            int k;
            for (k = 0; k < window; k++) {
                re += pcm[k] * cos(w * k);
                im += pcm[k] * sin(w * k);
            }
            if (re * re + im * im > bestPower) {
                bestPower = re * re + im * im;
                best = i;
            }
        }
        printf("  its first note measures %d Hz, and G4 asks for %.2f\n",
               best, want);
        checkf(best > want - 6 && best < want + 6,
               "the first note of effect 6 is %d Hz, not the %d asked for",
               best, (int)want);
    }

    /* The two effect tables are not the same set of sounds, and this port has
     * to be on the sound board's.  0x01e4 hangs the driver at 0x0d52 on the
     * board's interrupt and that one reads DS:0x35e2; 0x0218 hangs 0x162b on
     * INT 8 and that one reads DS:0x38a1.  If the two ever came out equal,
     * something would have gone wrong with the addresses. */
    {
        SndVoice a, b;
        int id, differ = 0, both = 0;

        for (id = 0; id < SND_EFFECTS; id++) {
            int ga = snd_start(&a, dat, n, id);
            int gb = snd_start_beep(&b, dat, n, id);

            if (!ga || !gb) continue;
            both++;
            if (a.len != b.len || memcmp(a.seq, b.seq, (size_t)a.len))
                differ++;
        }
        if (both != SND_EFFECTS) {
            printf("FAIL  only %d of %d effects are in both tables\n",
                   both, SND_EFFECTS);
            failures++;
        }
        /* Two of the nineteen happen to be the same bytes in both tables,
         * which is fine - they are short.  What would not be fine is the two
         * tables coming out as the same set. */
        if (differ < both - 4) {
            printf("FAIL  only %d of %d effects differ between the tables\n",
                   differ, both);
            failures++;
        }
        printf("  the board's effects differ from the beeper's in %d of %d\n",
               differ, both);
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
