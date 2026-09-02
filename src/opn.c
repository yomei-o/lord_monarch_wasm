/* See opn.h.  A four-operator OPN, written to be read rather than to be fast.
 *
 * The register map, which is what the driver at 0x1430 walks:
 *
 *   0x30 + 4*slot + ch   detune (bits 4..6), multiple (bits 0..3)
 *   0x40 + 4*slot + ch   total level, 0..127
 *   0x50 + 4*slot + ch   key scale (bits 6..7), attack rate (bits 0..4)
 *   0x60 + 4*slot + ch   decay rate (bits 0..4)
 *   0x70 + 4*slot + ch   sustain rate (bits 0..4)
 *   0x80 + 4*slot + ch   sustain level (bits 4..7), release rate (bits 0..3)
 *   0xa0 + ch            F-number low
 *   0xa4 + ch            block (bits 3..5), F-number high (bits 0..2)
 *   0xb0 + ch            feedback (bits 3..5), algorithm (bits 0..2)
 *   0x28                 key on/off: bits 4..7 pick operators, 0..1 the channel
 *
 * The slot order in the register map is the chip's, S1 S3 S2 S4, so slot 1 in
 * a register address is operator 2 in every algorithm diagram.  The order is
 * kept as the chip has it here and the algorithms below index accordingly.
 *
 * Two things are approximations rather than the chip:
 *
 *   - the envelope rate tables.  A real OPN advances its envelope out of a
 *     counter with per-rate shifts and a four-entry increment pattern; here a
 *     rate is turned into attenuation units per envelope tick directly, by the
 *     same doubling every four steps.  It sounds right and the timing is close,
 *     but it is not the chip's table.
 *   - the sine and exponent are computed rather than looked up in the chip's
 *     log tables, so the quantisation of a very quiet operator differs.
 */
#include "opn.h"

#include <math.h>
#include <string.h>

enum { OPN_ATT, OPN_DEC, OPN_SUS, OPN_REL, OPN_OFF };

/* How deep a modulator goes: an operator here puts out -1..1, and this is how
 * many turns of the next one's phase a modulator at full scale swings.
 *
 * Four, and the number matters more than it looks.  A modulator's output on
 * the chip reaches about 2^13 and the phase index is 1024 to a turn, with the
 * modulation taken as output >> 1 - so a full-scale modulator swings four
 * whole turns.  That sounds like far too much until you look at what a voice
 * actually asks for: FM001's first has total levels of 25, 39 and 40 on its
 * three modulators, which are gains of 0.115, 0.035 and 0.031.  At one turn
 * those modulate by three to eleven hundredths of a turn, which is not FM at
 * all - it is a sine with a wobble, and that is exactly what it sounded like.
 * At four turns they land between 0.12 and 0.46, which is an FM timbre.
 *
 * The lesson for whoever changes this next: judge the depth against the total
 * levels in a real voice, not against a full-scale operator, because nothing
 * in these songs ever runs a modulator at full scale. */
#define MOD_TURNS 4.0

/* 1024 units of attenuation is 96 dB, which is the chip's envelope range. */
#define ATT_MAX 1023.0
#define ATT_DB  (96.0 / 1024.0)

/* Detune, in F-number units, by keycode and DT.  The chip's table. */
static const int DETUNE[4][32] = {
    { 0 },
    { 0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7,8,8,8,8 },
    { 1,1,1,1,2,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7,8,8,9,10,11,12,13,14,16,16,16,16 },
    { 2,2,2,2,4,4,4,4,4,6,6,6,8,8,8,10,10,12,12,14,16,16,18,20,22,24,26,28,32,32,32,32 }
};

/* MUL 0 means a half. */
static double multiple_of(int m) { return m ? (double)m : 0.5; }

static double attenuation_to_gain(double att)
{
    if (att >= ATT_MAX) return 0.0;
    return pow(10.0, -(att * ATT_DB) / 20.0);
}

/* How much attenuation one envelope tick moves, for a rate of 0..63.  Zero
 * means "never": rates below four do not move at all on the chip either. */
static double rate_step(int r)
{
    if (r < 4) return 0.0;
    if (r > 63) r = 63;
    return (4 + (r & 3)) * pow(2.0, (r >> 2) - 11.0);
}

/* The rate an operator's envelope actually runs at: twice the register value
 * plus the key-scaled part of the note. */
static int scaled_rate(int rate, int keyScale, int keycode)
{
    int r;

    if (rate == 0) return 0;
    r = rate * 2 + (keycode >> (3 - keyScale));
    return r > 63 ? 63 : r;
}

/* The chip's keycode: the block, then two bits worked out of the top of the
 * F-number. */
static int keycode_of(const OpnCh *c)
{
    int f11 = (c->fnum >> 10) & 1;
    int f10 = (c->fnum >> 9) & 1;
    int f9  = (c->fnum >> 8) & 1;
    int f8  = (c->fnum >> 7) & 1;
    int n3 = f11 & (f10 | f9 | f8);
    int n4 = f11 ? (f10 & f9 & f8) : 0;

    (void)n4;
    return (c->block << 2) | (f11 << 1) | n3;
}

void opn_reset(Opn *o, double clock)
{
    memset(o, 0, sizeof *o);
    o->clock = clock > 0 ? clock : 3993600.0;
    for (int i = 0; i < OPN_CHANNELS; i++)
        for (int s = 0; s < OPN_OPS; s++) {
            o->ch[i].op[s].att = ATT_MAX;
            o->ch[i].op[s].stage = OPN_OFF;
        }
}

static void key_on(OpnCh *c, int slot)
{
    OpnOp *op = &c->op[slot];

    op->stage = OPN_ATT;
    op->phase = 0.0;
    /* The chip does not reset the level on a key-on; a fresh note simply
     * attacks from wherever it was, which is why a fast retrigger keeps its
     * body. */
    if (op->att >= ATT_MAX) op->att = ATT_MAX;
}

static void key_off(OpnCh *c, int slot)
{
    if (c->op[slot].stage != OPN_OFF) c->op[slot].stage = OPN_REL;
}

void opn_write(Opn *o, int reg, int value)
{
    int ch, slot;

    value &= 0xff;
    if (reg == 0x28) {                          /* key on / off */
        ch = value & 3;
        if (ch >= OPN_CHANNELS) return;
        for (slot = 0; slot < OPN_OPS; slot++) {
            int want = (value >> (4 + slot)) & 1;
            int have = (o->ch[ch].keyed >> slot) & 1;

            if (want && !have) key_on(&o->ch[ch], slot);
            else if (!want && have) key_off(&o->ch[ch], slot);
        }
        o->ch[ch].keyed = (value >> 4) & 0x0f;
        return;
    }
    if (reg >= 0x30 && reg < 0x90) {
        ch = reg & 3;
        slot = (reg >> 2) & 3;
        if (ch >= OPN_CHANNELS) return;
        {
            OpnOp *op = &o->ch[ch].op[slot];

            switch (reg & 0xf0) {
            case 0x30: op->detune = (value >> 4) & 7; op->multiple = value & 0x0f; break;
            case 0x40: op->totalLevel = value & 0x7f; break;
            case 0x50: op->keyScale = (value >> 6) & 3; op->attackRate = value & 0x1f; break;
            case 0x60: op->decayRate = value & 0x1f; break;
            case 0x70: op->sustainRate = value & 0x1f; break;
            case 0x80:
                op->sustainLevel = (value >> 4) & 0x0f;
                op->releaseRate = value & 0x0f;
                break;
            default: break;
            }
        }
        return;
    }
    if (reg >= 0xa0 && reg <= 0xa2) {
        ch = reg & 3;
        if (ch < OPN_CHANNELS) o->ch[ch].fnum = (o->ch[ch].fnum & 0x700) | value;
        return;
    }
    if (reg >= 0xa4 && reg <= 0xa6) {
        ch = reg & 3;
        if (ch < OPN_CHANNELS) {
            o->ch[ch].fnum = (o->ch[ch].fnum & 0xff) | ((value & 7) << 8);
            o->ch[ch].block = (value >> 3) & 7;
        }
        return;
    }
    if (reg >= 0xb0 && reg <= 0xb2) {
        ch = reg & 3;
        if (ch < OPN_CHANNELS) {
            o->ch[ch].algorithm = value & 7;
            o->ch[ch].feedback = (value >> 3) & 7;
        }
        return;
    }
}

/* One envelope tick for one operator. */
static void env_step(OpnOp *op, int keycode)
{
    double step;
    int r;

    switch (op->stage) {
    case OPN_ATT:
        r = scaled_rate(op->attackRate, op->keyScale, keycode);
        if (r >= 62) { op->att = 0.0; op->stage = OPN_DEC; break; }
        step = rate_step(r);
        if (step <= 0.0) break;
        /* The attack is not linear in dB: the chip moves a fraction of what is
         * left, which is what gives it its shape. */
        op->att += (-(op->att) - 1.0) * step / 16.0;
        if (op->att <= 0.0) { op->att = 0.0; op->stage = OPN_DEC; }
        break;
    case OPN_DEC:
        step = rate_step(scaled_rate(op->decayRate, op->keyScale, keycode));
        op->att += step;
        {
            double sl = op->sustainLevel == 15 ? ATT_MAX
                                               : op->sustainLevel * 32.0;

            if (op->att >= sl) { op->att = sl; op->stage = OPN_SUS; }
        }
        break;
    case OPN_SUS:
        op->att += rate_step(scaled_rate(op->sustainRate, op->keyScale, keycode));
        if (op->att >= ATT_MAX) { op->att = ATT_MAX; op->stage = OPN_OFF; }
        break;
    case OPN_REL:
        /* RR is four bits, and the chip uses 2*RR+1 as the five-bit rate. */
        op->att += rate_step(scaled_rate(op->releaseRate * 2 + 1, op->keyScale,
                                         keycode));
        if (op->att >= ATT_MAX) { op->att = ATT_MAX; op->stage = OPN_OFF; }
        break;
    default:
        break;
    }
}

/* One operator's sample.  `mod` is the phase modulation coming in, in turns. */
static double op_sample(OpnOp *op, double mod)
{
    double att = op->att + op->totalLevel * 8.0;

    op->prev = op->out;
    op->out = sin((op->phase + mod) * 2.0 * 3.14159265358979323846) *
              attenuation_to_gain(att);
    return op->out;
}

/* The eight ways the four operators wire up.  Slots are in the chip's register
 * order, S1 S3 S2 S4, so op[0] is the one with feedback and op[3] is always a
 * carrier. */
static double channel_sample(OpnCh *c, double inc[OPN_OPS])
{
    double fb, m1, m2, m3, out = 0.0;
    int i;

    /* Operator 1 modulates itself with the average of its last two outputs.
     * The register is 0..7 and the chip turns it into a shift, so each step is
     * a halving: 7 is the most and 0 is none at all. */
    fb = c->feedback ? (c->op[0].prev + c->op[0].out) / 2.0 * MOD_TURNS /
                       (double)(1 << (7 - c->feedback))
                     : 0.0;

    switch (c->algorithm) {
    case 0:  /* 1 -> 2 -> 3 -> 4 */
        m1 = op_sample(&c->op[0], fb);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], m2 * MOD_TURNS);
        out = op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 1:  /* (1 + 2) -> 3 -> 4 */
        m1 = op_sample(&c->op[0], fb);
        m2 = op_sample(&c->op[2], 0.0);
        m3 = op_sample(&c->op[1], (m1 + m2) * MOD_TURNS);
        out = op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 2:  /* 1 + (2 -> 3) -> 4 */
        m1 = op_sample(&c->op[0], fb);
        m2 = op_sample(&c->op[2], 0.0);
        m3 = op_sample(&c->op[1], m2 * MOD_TURNS);
        out = op_sample(&c->op[3], (m1 + m3) * MOD_TURNS);
        break;
    case 3:  /* (1 -> 2) + 3 -> 4 */
        m1 = op_sample(&c->op[0], fb);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], 0.0);
        out = op_sample(&c->op[3], (m2 + m3) * MOD_TURNS);
        break;
    case 4:  /* (1 -> 2) + (3 -> 4) */
        m1 = op_sample(&c->op[0], fb);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], 0.0);
        out = m2 + op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 5:  /* 1 -> (2, 3, 4) */
        m1 = op_sample(&c->op[0], fb);
        out = op_sample(&c->op[2], m1 * MOD_TURNS) +
              op_sample(&c->op[1], m1 * MOD_TURNS) +
              op_sample(&c->op[3], m1 * MOD_TURNS);
        break;
    case 6:  /* (1 -> 2) + 3 + 4 */
        m1 = op_sample(&c->op[0], fb);
        out = op_sample(&c->op[2], m1 * MOD_TURNS) +
              op_sample(&c->op[1], 0.0) +
              op_sample(&c->op[3], 0.0);
        break;
    default: /* 7: all four in parallel */
        out = op_sample(&c->op[0], fb) +
              op_sample(&c->op[2], 0.0) +
              op_sample(&c->op[1], 0.0) +
              op_sample(&c->op[3], 0.0);
        break;
    }
    for (i = 0; i < OPN_OPS; i++) c->op[i].phase += inc[i];
    return out;
}

void opn_render(Opn *o, short *out, int samples, int sampleRate)
{
    /* An OPN divides its clock by 72 for one sample of all three channels, and
     * its envelope moves once every three of those. */
    const double fmRate = o->clock / 72.0;
    const double perSample = fmRate / (double)sampleRate;
    int i, c, s;

    for (i = 0; i < samples; i++) {
        double acc = 0.0;

        /* Envelopes first, at their own rate. */
        o->egCounter += perSample / 3.0;
        while (o->egCounter >= 1.0) {
            o->egCounter -= 1.0;
            for (c = 0; c < OPN_CHANNELS; c++) {
                int kc = keycode_of(&o->ch[c]);

                for (s = 0; s < OPN_OPS; s++) env_step(&o->ch[c].op[s], kc);
            }
        }
        for (c = 0; c < OPN_CHANNELS; c++) {
            OpnCh *ch = &o->ch[c];
            double inc[OPN_OPS];
            int kc = keycode_of(ch);
            int live = 0;

            for (s = 0; s < OPN_OPS; s++) {
                OpnOp *op = &ch->op[s];
                /* An OPN's note is fnum * 2^(block-1) / 2^20 of its own sample
                 * rate, per turn; the operator takes that times MUL, with the
                 * detune added in F-number units first. */
                double f = ch->fnum + DETUNE[op->detune & 3][kc & 31] *
                                      ((op->detune & 4) ? -1 : 1);
                double turnsPerFm = f * pow(2.0, ch->block - 1) / 1048576.0 *
                                    multiple_of(op->multiple);

                inc[s] = turnsPerFm * perSample;
                if (op->stage != OPN_OFF) live = 1;
            }
            if (!live) continue;
            acc += channel_sample(ch, inc);
        }
        {
            /* The FM and the SSG have to arrive at comparable levels.  A carrier at a
             * typical TL out of these songs comes out around a fifth of full
             * scale, and there are three of them, so this is what puts the FM
             * beside the SSG rather than twenty decibels under it - which is
             * where it was, and why it could not be heard at all. */
            long v = out[i] + (long)(acc * 11000.0);

            if (v > 32000) v = 32000;
            if (v < -32000) v = -32000;
            out[i] = (short)v;
        }
    }
}
