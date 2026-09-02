/* The FM half of a YM2203 - three channels of four operators.
 *
 * This is needed because the songs use it.  FUN at 0x1430, reached from the FM
 * side's 0xf0 handler at 0x11c6, uploads a voice out of the song file itself:
 * twenty-four registers from 0x30 + channel stepping by four, then the
 * twenty-fifth byte to 0xb0 + channel.  The port missed that for a while
 * because tools/lmdis.py follows flow and the FM command handlers are only
 * reachable through an indirect jump, so they sat in the 5% of the binary it
 * never disassembled.
 *
 * Written here rather than lifted: the chip is documented, and the shape below
 * is the one every OPN implementation has - a phase accumulator and a
 * four-stage envelope per operator, eight ways of wiring the four together,
 * and feedback on the first.  Neko Project II's sound/opngen is where the
 * details were checked.
 *
 * What is deliberately not modelled: the LFO (a YM2203 has none), the SSG-EG
 * bits (the driver never writes them), and the chip's exact rate tables, which
 * are approximated - see opn.c.
 */
#ifndef OPN_H
#define OPN_H

#define OPN_CHANNELS 3
#define OPN_OPS 4

typedef struct {
    /* Straight out of the voice. */
    int detune, multiple;       /* 0x30 */
    int totalLevel;             /* 0x40, 0..127, 0.75 dB a step */
    int keyScale, attackRate;   /* 0x50 */
    int decayRate;              /* 0x60 (bit 7 is AM, which a 2203 has not) */
    int sustainRate;            /* 0x70 */
    int sustainLevel, releaseRate; /* 0x80 */

    /* State.  envIdx is NP2's env_cnt in envelope steps rather than its
     * 16.16 fixed point: nought to 1024 is the attack, and 1024 to 2048 is
     * everything after.  What it means as an attenuation goes through
     * envcurve, which is an eighth power over the attack. */
    double phase;               /* in turns, 0..1 */
    double envIdx;
    int stage;                  /* OPN_ATT .. OPN_OFF */
    double out, prev;           /* the last two outputs, for feedback */
} OpnOp;

typedef struct {
    OpnOp op[OPN_OPS];
    int fnum, block;            /* 0xa0 / 0xa4 */
    int algorithm, feedback;    /* 0xb0 */
    int keyed;                  /* which operators are on, one bit each */
} OpnCh;

typedef struct {
    OpnCh ch[OPN_CHANNELS];
    double clock;               /* the chip's own clock, 3993600 on a PC-98 */
    double egCounter;           /* the envelope clock, one per 3 FM samples */
} Opn;

void opn_reset(Opn *o, double clock);

/* One register, exactly as the driver writes it through sub_740d: `reg` is dh
 * and `value` is dl. */
void opn_write(Opn *o, int reg, int value);

/* Mixes `samples` of all three channels into `out`, adding rather than
 * replacing so the SSG can already be there. */
void opn_render(Opn *o, short *out, int samples, int sampleRate);

#endif
