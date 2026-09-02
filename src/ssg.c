/* The SSG half of a YM2203 - three square waves, a noise source and a mixer -
 * which is what the game's sound effects come out of.
 *
 * Registers, as the driver writes them:
 *
 *   0,1  2,3  4,5   the twelve-bit tone period of channels A, B and C
 *   6              the five-bit noise period
 *   7              the mixer: bits 0..2 turn tone off, bits 3..5 noise off
 *   8,9,10         the four-bit volume of each channel
 *
 * The period comes from sub_1541: the semitone indexes sixteen words at
 * DS:0x2465, [si+8] is added as a signed detune, and the whole thing is shifted
 * right by the octave (sub_1539 is nothing but that shift).  A square then runs
 * at clock / 16 / period, with the SSG clock a quarter of the OPN's.
 *
 * This is my own code; only the numbers are the game's.
 */
#include "ssg.h"

void ssg_reset(Ssg *s)
{
    int i;
    for (i = 0; i < 3; i++) {
        s->period[i] = 1;
        s->volume[i] = 0;
        s->counter[i] = 0;
        s->high[i] = 0;
    }
    s->noisePeriod = 1;
    s->noiseCounter = 0;
    s->noise = 1;                       /* the shift register, never zero */
    s->mixer = 0x3f;                    /* everything off */
    s->dc = s->dcIn = s->dcPrev = 0;
}

void ssg_write(Ssg *s, int reg, int value)
{
    int ch;

    switch (reg) {
    case 0: case 2: case 4:
        ch = reg / 2;
        s->period[ch] = (s->period[ch] & 0x0f00) | (value & 0xff);
        break;
    case 1: case 3: case 5:
        ch = reg / 2;
        s->period[ch] = (s->period[ch] & 0x00ff) | ((value & 0x0f) << 8);
        break;
    case 6:
        s->noisePeriod = value & 0x1f;
        break;
    case 7:
        s->mixer = value & 0x3f;
        break;
    case 8: case 9: case 10:
        s->volume[reg - 8] = value & 0x0f;
        break;
    default:
        break;                          /* the envelope shape is not used here */
    }
}

/* The sixteen levels are a ladder of 3 dB, not a straight 0..15: the part's
 * DAC is logarithmic, and treating it as linear makes a quiet note far too
 * loud next to a loud one and turns an envelope's fade into a ramp.  Three
 * decibels is the sixteen-level SSG's step - the YM2149's thirty-two levels
 * halve it - and Neko Project II's psggen builds the same ladder by starting
 * at 0x0c00 and dividing by 1.41492 down to zero, which is where these
 * numbers were checked. */
static const short SSG_VOL[16] = {
    0, 23, 33, 47, 67, 95, 135, 191, 270, 382, 541, 766, 1084, 1534, 2171, 3072
};

/* One sample.  The counters run at the SSG's own rate, so the caller says how
 * many chip cycles a sample is worth. */
static int step(Ssg *s, int cycles)
{
    int ch, out = 0;

    for (ch = 0; ch < 3; ch++) {
        int p = s->period[ch] ? s->period[ch] : 1;
        s->counter[ch] += cycles;
        /* period * 8, not * 16: the output frequency is clock / (16 * period),
         * so a full square cycle is 16 * period chip cycles and each half of it
         * is eight.  Getting this wrong put everything an octave down, which a
         * frequency check on the rendered samples caught at once. */
        while (s->counter[ch] >= p * 8) {
            s->counter[ch] -= p * 8;
            s->high[ch] = !s->high[ch];
        }
    }
    {
        int np = s->noisePeriod ? s->noisePeriod : 1;
        s->noiseCounter += cycles;
        while (s->noiseCounter >= np * 8) {
            s->noiseCounter -= np * 8;
            /* A seventeen-bit maximal shift register, which is what the part
             * uses; taps at 0 and 3. */
            s->noise = (s->noise >> 1) |
                       (((s->noise ^ (s->noise >> 3)) & 1) << 16);
        }
    }
    for (ch = 0; ch < 3; ch++) {
        int tone = (s->mixer >> ch) & 1;        /* 1 = tone off */
        int noise = (s->mixer >> (ch + 3)) & 1; /* 1 = noise off */
        int on = (tone || s->high[ch]) && (noise || (s->noise & 1));
        if (!tone || !noise)
            out += on ? SSG_VOL[s->volume[ch] & 0x0f] : 0;
    }
    return out;
}

void ssg_render(Ssg *s, short *out, int samples, int sampleRate)
{
    /* The SSG runs at a quarter of the OPN clock. */
    const int chipRate = SSG_CLOCK;
    int i;
    long long acc = 0;

    for (i = 0; i < samples; i++) {
        int cycles = chipRate / sampleRate;
        int v;
        acc += chipRate % sampleRate;
        if (acc >= sampleRate) {
            acc -= sampleRate;
            cycles++;
        }
        v = step(s, cycles);
        /* A one-pole high pass takes the offset out.  Without it the level sits
         * wherever the number of sounding channels puts it - one channel idles
         * at zero and swings up, which is a step of several thousand at every
         * key-on and sounds like a click rather than a note. */
        /* Three channels at full is 3 * 3072.  Three was too quiet on its
         * own and six put the SSG three decibels over the FM, which is the
         * wrong way round for this chip: the user heard an SSG arrangement
         * with an FM part somewhere underneath. */
        s->dcIn = v * 3;
        s->dc = s->dcIn - s->dcPrev + (s->dc * 1023) / 1024;
        s->dcPrev = s->dcIn;
        if (s->dc > 32000) s->dc = 32000;
        if (s->dc < -32000) s->dc = -32000;
        out[i] = (short)s->dc;
    }
}

int ssg_period(const unsigned char *periodTable, int note, int detune)
{
    int semitone = note & 0x0f;
    int octave = (note >> 4) & 7;
    int p = periodTable[semitone * 2] | (periodTable[semitone * 2 + 1] << 8);

    p += detune;                        /* sub_1541: [si+8], signed */
    p >>= octave;                       /* sub_1539 is only this shift */
    return p > 0 ? p : 1;
}

double ssg_period_hz(int period)
{
    if (period <= 0) period = 1;
    return (double)SSG_CLOCK / 16.0 / (double)period;
}
