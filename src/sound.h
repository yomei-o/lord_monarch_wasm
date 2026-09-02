/* The game's own sound sequences, read and stepped.
 *
 * This is the half that does not need a synthesiser: it walks a sequence and
 * says what should be sounding at each tick.  Making a noise from that is the
 * next piece.
 *
 * Where it all comes from, in the original:
 *
 *   sub_0d12          a priority latch and nothing else - it keeps one pending
 *                     request in [0x3b46] as (id << 8) | priority and only lets
 *                     a new one in when its priority is at least as high
 *   DS:0x38a1         nineteen pointers, one per effect, into PROG.DAT itself
 *   sub_0f2d          the player, run over 0x20-byte channel structures from
 *                     DS:0x3afa
 *   CS:0x11a6         the command jump table, (cmd - 0xf0) * 2, with one
 *                     operand byte already fetched
 *   sub_1518          note byte to F-number, through the table at DS:0x244d
 *   0x0eeb, 0x0ef5    the frequency going out to registers 0xa4 + ch and
 *                     0xa0 + ch, so the effects play on the FM side
 *
 * A sequence is pairs of (duration, note) with commands 0xf0..0xff mixed in:
 *
 *   duration   bit 7 holds back the key-off before this note, the rest is ticks
 *   note       bit 7 is a tie, the rest is (octave << 4) | semitone
 */
#ifndef SOUND_H
#define SOUND_H

/* The chromatic table at DS:0x244d, and the octave in bits 3..5 of the high
 * byte, which is where the YM2203 wants its block.  At block 4 it comes out as
 * concert pitch to two decimal places, so the reading is not in doubt. */
#define SND_FNUM_AT 0x244d
#define SND_TABLE_AT 0x38a1         /* the nineteen effect pointers */
#define SND_EFFECTS 19
#define SND_CLOCK 3993600           /* the PC-98's OPN */

/* (block << 3) | fnum high in the high byte, fnum low in the low byte - the
 * pair that goes to registers 0xa4 + ch and 0xa0 + ch.  `detune` is [si+8]. */
unsigned short snd_fnumber(const unsigned char *fnumTable, int note,
                           int detune);

/* What that comes out as, for a synthesiser or for a test to check. */
double snd_note_hz(const unsigned char *fnumTable, int note, int detune);

/* One voice, walking one sequence.
 *
 * The sequence is copied rather than pointed at: command 0xf6 is a loop that
 * decrements its own counter *inside the data*, so playing straight out of
 * PROG.DAT would work once and then be wrong for ever. */
#define SND_SEQ_MAX 96

typedef struct {
    unsigned char seq[SND_SEQ_MAX];
    int len;
    int pos;
    int wait;                   /* ticks left on the current note, [si+0] */
    int note;                   /* the last note byte, [si+7] */
    int volume;                 /* [si+6], 0x0f is loudest */
    int timbre;                 /* [si+5] */
    int keyed;                  /* is a note sounding */
    int tie;                    /* the note byte's bit 7 */
    int done;
    /* The pitch envelope from command 0xf7: [si+0x11], [si+0x13], [si+0x15]. */
    int envA, envB, envC;
    /* The amplitude envelope, which is the game's own and not a guess.
     *
     *   sub_111e   on every key-off and new note it goes back to stage 0 of the
     *              timbre's block and loads all four of its bytes
     *   0x0fab..   each tick counts down, and when the count runs out the level
     *              moves one step towards the target; on arriving it clamps,
     *              and either chains to the next stage or finishes
     *   sub_10c2   level * (volume + 1) >> 8 is what reaches register 8 + ch
     *
     * A stage is four bytes at DS:0x34e2 + (timbre << 4) + stage * 4:
     *
     *   0  the step the level moves by
     *   1  the tick count, with bit 7 meaning downwards
     *   2  the level to stop at
     *   3  the level to start from, used only by stage 0
     *
     * [si+5] holds (timbre << 4) | stage and advances by four; bit 3 of it
     * marks the last stage, so a timbre gets at most three of them. */
    int step, count, target, level, stage, downwards, spent;
    int silenceAll;             /* command 0xfe was seen */
} SndVoice;

/* Loads effect `id` out of PROG.DAT.  0 if there is no such effect. */
int snd_start(SndVoice *v, const unsigned char *progDat, unsigned progDatSize,
              int id);

/* One tick.  Returns 1 while the voice is still playing.  `keyedNow` is set
 * when this tick started a new note. */
int snd_tick(SndVoice *v, int *keyedNow);

/* Renders one effect through an SSG and returns how many samples it made.
 *
 * All of it is the game's now: the period comes from its own table through
 * ssg_period, the note lengths are the sequence's ticks, and the amplitude
 * envelope is the one at DS:0x34e2 stepped the way sub_111e and the tail of
 * sub_0f2d step it, with the level multiplied by volume + 1 and shifted down
 * eight as sub_10c2 does.
 *
 * Nothing FM is involved, and that is not a shortcut: this program never writes
 * a single FM operator register - not 0x30, 0x50, 0x60, 0x70, 0x80 or 0xb0 - so
 * after a reset every rate is zero, no envelope ever rises, and the FM channels
 * are silent however diligently the driver keys them.  Everything audible on
 * this disk comes out of the SSG.
 */
int snd_render_effect(const unsigned char *progDat, unsigned progDatSize,
                      int id, short *out, int maxSamples, int sampleRate);

/* The driver's tick rate, from the timer it sets up: register 0x26 takes
 * [0x3b3d] and 0x27 gets 0x3a, which is timer B enabled and loaded. */
#define SND_TICK_HZ 60

/* Where the amplitude envelopes live. */
#define SND_ENV_AT 0x34e2

/* Loads stage 0 of the current timbre, which is what sub_111e does. */
void snd_env_key(SndVoice *v, const unsigned char *env);

/* One tick of it, after snd_tick.  Returns the level that reaches the chip. */
int snd_env_step(SndVoice *v, const unsigned char *env);

/* sub_114b, the release: it jumps straight to stage 0x0c of the timbre's block
 * and loads that stage's step, count and target.  Since bit 3 of 0x0c is set,
 * arriving at its target is the end of the voice - so stage 0x0c is the fade,
 * and the four-byte block is attack, decay, sustain, release in that order.
 *
 * The original enters it from 0x0f40, when the note's remaining ticks reach
 * [si+9] and the tie flag is set, which is how a note starts fading before the
 * next one arrives rather than stopping dead. */
void snd_env_release(SndVoice *v, const unsigned char *env);

#endif
