/* The SSG half of a YM2203: three squares, noise, and a mixer.
 *
 * The game uses both halves of the part.  The proof is that there are two
 * note-to-pitch converters, one per side:
 *
 *   sub_1518  the semitone indexes DS:0x244d for an F-number and the octave
 *             goes into bits 3..5 of the high byte, which is the FM block -
 *             out to registers 0xa4 + ch and 0xa0 + ch
 *   sub_1541  the semitone indexes DS:0x2465 for a period and the whole thing
 *             is shifted right by the octave - out to registers ch * 2 and
 *             ch * 2 + 1
 *
 * This file is the second of those.  The FM side wants a four-operator core and
 * is the next piece.
 */
#ifndef SSG_H
#define SSG_H

/* The OPN on a PC-98 runs at 3.9936 MHz and the SSG at a quarter of that. */
#define SSG_CLOCK (3993600 / 4)

/* The period table the driver reads, and how it uses it. */
#define SSG_PERIOD_AT 0x2465

typedef struct {
    int period[3];
    int volume[3];
    int counter[3];
    int high[3];
    int noisePeriod;
    int noiseCounter;
    int noise;
    int mixer;
    /* The one-pole high pass that keeps the offset out. */
    int dc, dcIn, dcPrev;
} Ssg;

void ssg_reset(Ssg *s);
void ssg_write(Ssg *s, int reg, int value);
void ssg_render(Ssg *s, short *out, int samples, int sampleRate);

/* period = (table[semitone] + detune) >> octave, which is sub_1541 followed by
 * sub_1539.  `note` is the game's (octave << 4) | semitone. */
int ssg_period(const unsigned char *periodTable, int note, int detune);

/* What that period sounds like, for a test to check against. */
double ssg_period_hz(int period);

#endif
