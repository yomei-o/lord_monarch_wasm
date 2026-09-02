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
 * a register address is operator 2 in every algorithm diagram.  That reading
 * is not a guess: the game's own carrier masks at DS:0x2445 are
 * 08 08 08 08 0c 0e 0e 0f, and they line up with the algorithm diagrams only
 * under this order.
 *
 * The arithmetic follows Neko Project II's sound/opngen, because three
 * attempts at deriving it from memory all came out wrong - one of them as a
 * plain sine.  What was taken, and from where:
 *
 *   opngencfg.h   SIN_BITS 10, so 1024 phase steps to a turn; FREQ_BITS 21,
 *                 so the phase counter holds 2^21 to a turn; SINTBL_BIT 15
 *                 and ENVTBL_BIT 14 against TL_BITS = FREQ_BITS + 2, which
 *                 put a full-scale operator at 2^23.  The modulation shift
 *                 (FREQ_BITS - (TL_BITS - 2)) is zero, so a modulator at full
 *                 scale swings 2^23 / 2^21 = four whole turns.
 *   opngeng.c     the envelope, which is
 *                 env = totallevel - envcurve[env_cnt >> 16] with the counter
 *                 running up through attack, decay, sustain and release; and
 *                 the feedback, which is (op1fb >> feedback), so the register
 *                 is a shift and each step is a halving.
 *   opngenc.c     envcurve - an eighth power over the attack and a straight
 *                 line after it - and the rate tables, which are a base
 *                 frequency over OPM_ARRATE or OPM_DRRATE.
 *
 * Not modelled: the LFO (a YM2203 has none) and the SSG-EG bits (this driver
 * never writes them).
 */
#include "opn.h"

#include <math.h>
#include <string.h>

enum { OPN_ATT, OPN_DEC, OPN_SUS, OPN_REL, OPN_OFF };

/* opngenc.c */
#define OPM_ARRATE 399128.0
#define OPM_DRRATE 5514396.0
/* opngencfg.h: the envelope's range in steps, and what one step is worth. */
#define EVC_ENT 1024.0
#define EG_STEP (96.0 / EVC_ENT)

/* The envelope counter walks 0..2048: nought to EVC_ENT is the attack, and
 * EVC_ENT to twice it is everything after. */
#define ENV_OFF (2.0 * EVC_ENT)

/* How many turns of the next operator's phase a full-scale modulator swings.
 * Four - see above, and mind that nothing in these songs ever runs a modulator
 * at full scale, so this has to be judged against the total levels in a real
 * voice rather than against a full-scale operator.  Getting that backwards is
 * what made the first cut sound like a sine with a wobble. */
#define MOD_TURNS 4.0

/* Detune, in F-number units, by keycode and DT.  The chip's table. */
static const int DETUNE[4][32] = {
    { 0 },
    { 0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7,8,8,8,8 },
    { 1,1,1,1,2,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7,8,8,9,10,11,12,13,14,16,16,16,16 },
    { 2,2,2,2,2,3,3,3,4,4,4,5,5,6,6,7,8,8,9,10,11,12,13,14,16,17,19,20,22,22,22,22 }
};

/* MUL 0 means a half. */
static double multiple_of(int m) { return m ? (double)m : 0.5; }

/* opngenc.c's envcurve, as an attenuation: an eighth power falling from a full
 * 1024 to nothing across the attack, then a straight line back up.  An eighth
 * power is a very different shape from a straight ramp, and it is most of what
 * an FM attack sounds like. */
static double envcurve(double idx)
{
    if (idx <= 0.0) return EVC_ENT;
    if (idx < EVC_ENT) {
        double t = (EVC_ENT - 1.0 - idx) / EVC_ENT;

        if (t < 0.0) t = 0.0;
        return pow(t, 8.0) * EVC_ENT;
    }
    if (idx >= ENV_OFF) return EVC_ENT;
    return idx - EVC_ENT;
}

/* opngenc.c's rate tables, in envelope steps per chip sample.  A rate below
 * four does not move, which is the chip's behaviour too. */
static double rate_inc(int r, double perRate)
{
    double freq;

    if (r < 4) return 0.0;
    if (r > 63) r = 63;
    freq = EVC_ENT * 65536.0 * (72.0 / 64.0);
    if (r < 60) freq *= 1.0 + (r & 3) * 0.25;
    freq *= (double)(1 << ((r >> 2) - 1));
    return freq / perRate / 65536.0;    /* the table is in 1/65536 steps */
}

/* The rate an operator's envelope runs at: twice the register value plus the
 * key-scaled part of the note. */
static int scaled_rate(int rate, int keyScale, int keycode)
{
    int r;

    if (rate == 0) return 0;
    r = rate * 2 + (keycode >> (3 - keyScale));
    return r > 63 ? 63 : r;
}

/* The chip's keycode: the block and two bits off the top of the F-number. */
static int keycode_of(const OpnCh *c)
{
    int f11 = (c->fnum >> 10) & 1;
    int f10 = (c->fnum >> 9) & 1;
    int f9  = (c->fnum >> 8) & 1;
    int f8  = (c->fnum >> 7) & 1;
    int n3 = f11 & (f10 | f9 | f8);

    return (c->block << 2) | (f11 << 1) | n3;
}

void opn_reset(Opn *o, double clock)
{
    int i, s;

    memset(o, 0, sizeof *o);
    o->clock = clock > 0 ? clock : 3993600.0;
    for (i = 0; i < OPN_CHANNELS; i++)
        for (s = 0; s < OPN_OPS; s++) {
            o->ch[i].op[s].envIdx = ENV_OFF;
            o->ch[i].op[s].stage = OPN_OFF;
        }
}

/* Where the decay stops.  Sustain level 15 means all the way down. */
static double decay_level(const OpnOp *op)
{
    if (op->sustainLevel >= 15) return ENV_OFF;
    return EVC_ENT + op->sustainLevel * 32.0;
}

static void key_on(OpnCh *c, int slot)
{
    OpnOp *op = &c->op[slot];

    op->stage = OPN_ATT;
    op->envIdx = 0.0;                   /* EC_ATTACK */
    op->phase = 0.0;
}

static void key_off(OpnCh *c, int slot)
{
    OpnOp *op = &c->op[slot];

    if (op->stage == OPN_OFF) return;
    /* The release picks the envelope up where it stands, so letting go during
     * an attack does not click. */
    if (op->stage == OPN_ATT) op->envIdx = EVC_ENT + envcurve(op->envIdx);
    op->stage = OPN_REL;
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
            case 0x30:
                op->detune = (value >> 4) & 7;
                op->multiple = value & 0x0f;
                break;
            case 0x40: op->totalLevel = value & 0x7f; break;
            case 0x50:
                op->keyScale = (value >> 6) & 3;
                op->attackRate = value & 0x1f;
                break;
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
            int fb = (value >> 3) & 7;

            o->ch[ch].algorithm = value & 7;
            /* Kept as the shift the chip applies rather than as written, the
             * way opngenc.c's 0xb0 does it: 7 is the deepest and shifts by
             * one, 1 the shallowest and shifts by seven, 0 is no feedback. */
            o->ch[ch].feedback = fb ? 8 - fb : 0;
        }
        return;
    }
}

/* One chip sample of envelope, the way opngeng.c's CALCENV walks it. */
static void env_step(OpnOp *op, int keycode)
{
    double end;

    switch (op->stage) {
    case OPN_ATT:
        op->envIdx += rate_inc(scaled_rate(op->attackRate, op->keyScale,
                                           keycode), OPM_ARRATE);
        if (op->envIdx >= EVC_ENT) {
            op->envIdx = EVC_ENT;
            op->stage = OPN_DEC;
        }
        break;
    case OPN_DEC:
        op->envIdx += rate_inc(scaled_rate(op->decayRate, op->keyScale,
                                           keycode), OPM_DRRATE);
        end = decay_level(op);
        if (op->envIdx >= end) {
            op->envIdx = end;
            op->stage = (end >= ENV_OFF) ? OPN_OFF : OPN_SUS;
        }
        break;
    case OPN_SUS:
        op->envIdx += rate_inc(scaled_rate(op->sustainRate, op->keyScale,
                                           keycode), OPM_DRRATE);
        if (op->envIdx >= ENV_OFF) { op->envIdx = ENV_OFF; op->stage = OPN_OFF; }
        break;
    case OPN_REL:
        /* RR is four bits and the chip uses 2*RR+1 as the five-bit rate. */
        op->envIdx += rate_inc(scaled_rate(op->releaseRate * 2 + 1,
                                           op->keyScale, keycode), OPM_DRRATE);
        if (op->envIdx >= ENV_OFF) { op->envIdx = ENV_OFF; op->stage = OPN_OFF; }
        break;
    default:
        break;
    }
}

/* One operator's sample.  `mod` is the phase modulation coming in, in turns. */
static double op_sample(OpnOp *op, double mod)
{
    /* opngeng.c has env = totallevel - envcurve[...] as a level, and
     * opngenc.c builds totallevel as (~TL & 0x7f) << 3.  As an attenuation in
     * envelope steps that comes to 1024 - (127 - TL)*8 + curve, which is
     * curve + 8*TL + 8 - so a TL step is eight steps, and there are eight more
     * that never go away.  Those eight are only three quarters of a decibel,
     * but they are three quarters of a decibel on every modulator, and a
     * modulator that is louder than it should be is a brighter timbre. */
    double att = envcurve(op->envIdx) + op->totalLevel * 8.0 + 8.0;
    double gain = att >= EVC_ENT ? 0.0 : pow(10.0, -(att * EG_STEP) / 20.0);

    op->prev = op->out;
    op->out = sin((op->phase + mod) * 2.0 * 3.14159265358979323846) * gain;
    return op->out;
}

/* Operator 1's contribution to the rest of the channel: the mean of its last
 * output and this one while it feeds back, and simply this one when it does
 * not.  opngeng.c averages only inside the feedback branch. */
static double op1_sample(OpnCh *c, double fb, double was)
{
    double v = op_sample(&c->op[0], fb);

    return c->feedback ? (was + v) / 2.0 : v;
}

/* The eight ways the four operators wire up.  Slots are in the chip's register
 * order, S1 S3 S2 S4, so op[0] is the one with feedback and op[3] is always a
 * carrier. */
static double channel_sample(OpnCh *c, double inc[OPN_OPS])
{
    double fb, was, m1, m2, m3, out = 0.0;
    int i;

    /* Operator 1 modulates itself with the output it had last sample, shifted
     * down by the feedback amount - and what leaves it is the mean of that
     * output and this one, not this one.  Both halves of that come straight
     * out of opngeng.c's calcratechannel, and both matter: without the mean
     * the loop rings near the sample rate, which came out of the speakers as
     * a buzz on top of the note rather than as a timbre. */
    was = c->op[0].out;
    fb = c->feedback ? was * MOD_TURNS / (double)(1 << c->feedback) : 0.0;

    switch (c->algorithm) {
    case 0:  /* S1 -> S2 -> S3 -> S4 */
        m1 = op1_sample(c, fb, was);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], m2 * MOD_TURNS);
        out = op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 1:  /* (S1 + S2) -> S3 -> S4 */
        m1 = op1_sample(c, fb, was);
        m2 = op_sample(&c->op[2], 0.0);
        m3 = op_sample(&c->op[1], (m1 + m2) * MOD_TURNS);
        out = op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 2:  /* S1 + (S2 -> S3) -> S4 */
        m1 = op1_sample(c, fb, was);
        m2 = op_sample(&c->op[2], 0.0);
        m3 = op_sample(&c->op[1], m2 * MOD_TURNS);
        out = op_sample(&c->op[3], (m1 + m3) * MOD_TURNS);
        break;
    case 3:  /* (S1 -> S2) + S3 -> S4 */
        m1 = op1_sample(c, fb, was);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], 0.0);
        out = op_sample(&c->op[3], (m2 + m3) * MOD_TURNS);
        break;
    case 4:  /* (S1 -> S2) + (S3 -> S4), two carriers */
        m1 = op1_sample(c, fb, was);
        m2 = op_sample(&c->op[2], m1 * MOD_TURNS);
        m3 = op_sample(&c->op[1], 0.0);
        out = m2 + op_sample(&c->op[3], m3 * MOD_TURNS);
        break;
    case 5:  /* S1 -> (S2, S3, S4), three carriers */
        m1 = op1_sample(c, fb, was);
        out = op_sample(&c->op[2], m1 * MOD_TURNS) +
              op_sample(&c->op[1], m1 * MOD_TURNS) +
              op_sample(&c->op[3], m1 * MOD_TURNS);
        break;
    case 6:  /* (S1 -> S2) + S3 + S4, three carriers */
        m1 = op1_sample(c, fb, was);
        out = op_sample(&c->op[2], m1 * MOD_TURNS) +
              op_sample(&c->op[1], 0.0) +
              op_sample(&c->op[3], 0.0);
        break;
    default: /* 7: all four in parallel */
        out = op1_sample(c, fb, was) +
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
     * the envelope runs at that same rate - NP2 steps it once per output
     * sample and scales the rate tables instead, which comes to the same. */
    const double fmRate = o->clock / 72.0;
    const double perSample = fmRate / (double)sampleRate;
    int i, c, s;

    for (i = 0; i < samples; i++) {
        double acc = 0.0;

        o->egCounter += perSample;
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
                /* An OPN's note is fnum * 2^(block-1) / 2^20 of its own
                 * sample rate, per turn, times MUL.  Detune is added to that
                 * increment and not to the F-number, so the block does not
                 * scale it: opngenc.c builds keynote as fn << (blk + 21 - 21)
                 * but detunetable as dt << (0 + 21 - 20), one fixed step
                 * whatever octave the note is in.  Scaling it by the block
                 * instead put this port eighteen cents sharp at block four. */
                double dt = DETUNE[op->detune & 3][kc & 31] *
                            ((op->detune & 4) ? -1 : 1);
                double turnsPerFm = (ch->fnum * pow(2.0, ch->block - 1) + dt)
                                    / 1048576.0 * multiple_of(op->multiple);

                inc[s] = turnsPerFm * perSample;
                if (op->stage != OPN_OFF) live = 1;
            }
            if (!live) continue;
            acc += channel_sample(ch, inc);
        }
        {
            /* The balance.  On the chip the FM is the loud half and the SSG
             * supports it; here the SSG was three decibels the louder and the
             * FM lifted the total by only 1.7 dB, so what came out was an SSG
             * arrangement with something underneath it.  At this scale one
             * carrier at TL 0 is worth rather more than one SSG channel at
             * volume 15, which is the way round the chip has it. */
            long v = out[i] + (long)(acc * 24000.0);

            if (v > 32000) v = 32000;
            if (v < -32000) v = -32000;
            out[i] = (short)v;
        }
    }
}
