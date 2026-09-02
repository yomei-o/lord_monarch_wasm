#include "sound.h"
#include "ssg.h"

#include <string.h>

/* sub_1518.  The octave goes to bits 3..5 of the high byte, which is where the
 * YM2203 keeps its block, and the semitone indexes a table of sixteen words at
 * DS:0x244d of which twelve are a chromatic octave.  [si+8] is a signed detune
 * added to the F-number before the block is folded in. */
unsigned short snd_fnumber(const unsigned char *fnumTable, int note,
                           int detune)
{
    int semitone = note & 0x0f;
    int block = (note & 0x70) >> 1;         /* already shifted into place */
    int fnum = fnumTable[semitone * 2] | (fnumTable[semitone * 2 + 1] << 8);

    fnum += detune;
    return (unsigned short)((fnum & 0xffff) | (block << 8));
}

double snd_note_hz(const unsigned char *fnumTable, int note, int detune)
{
    unsigned short v = snd_fnumber(fnumTable, note, detune);
    int block = (v >> 11) & 7;
    int fnum = v & 0x07ff;
    /* The OPN's own relation, with its prescaler of 72. */
    double step = (double)SND_CLOCK / 72.0 / 1048576.0;
    int shift = block - 1;
    double hz = fnum * step;

    while (shift-- > 0) hz *= 2.0;
    return hz;
}

int snd_start(SndVoice *v, const unsigned char *progDat, unsigned progDatSize,
              int id)
{
    unsigned tableOff, seqAddr, off, i;

    memset(v, 0, sizeof *v);
    v->note = -1;
    v->volume = 0x0f;
    if (id < 0 || id >= SND_EFFECTS) return 0;

    /* PROG.DAT sits at DS:0x1000, so a DS address is an offset less that. */
    tableOff = (unsigned)(SND_TABLE_AT - 0x1000) + (unsigned)id * 2;
    if (tableOff + 2 > progDatSize) return 0;
    seqAddr = progDat[tableOff] | (progDat[tableOff + 1] << 8);
    if (seqAddr < 0x1000) return 0;
    off = seqAddr - 0x1000;
    if (off >= progDatSize) return 0;

    /* How far it runs.  NOT "up to the first 0xff": 0xff turns up inside
     * operands - effect 11's pitch envelope is f7 01 01 38 ff - and stopping
     * there truncated it to nothing.  The nineteen sequences lie one after
     * another in PROG.DAT, so the end is the next address in the table, and
     * the last one is capped.
     *
     * It is copied rather than pointed at because command 0xf6 decrements its
     * own counter inside the data: played in place it would work once. */
    {
        unsigned end = off + SND_SEQ_MAX, j;
        for (j = 0; j < SND_EFFECTS; j++) {
            unsigned o = (unsigned)(SND_TABLE_AT - 0x1000) + j * 2;
            unsigned a2;
            if (o + 2 > progDatSize) break;
            a2 = progDat[o] | (progDat[o + 1] << 8);
            if (a2 > seqAddr && a2 - 0x1000 < end) end = a2 - 0x1000;
        }
        if (end > progDatSize) end = progDatSize;
        for (i = 0; off + i < end && i < SND_SEQ_MAX; i++)
            v->seq[i] = progDat[off + i];
        v->len = (int)i;
    }
    return v->len > 0;
}

/* The commands, from the jump table at CS:0x11a6.  Each has already had one
 * operand byte fetched by sub_1175, which is why every one of the sixteen takes
 * at least one.  Returns 0 when the sequence has ended. */
static int command(SndVoice *v, int cmd)
{
    int a;

    if (v->pos >= v->len) return 0;
    a = v->seq[v->pos++];                   /* sub_1175 fetches this one */

    switch (cmd) {
    case 0xf0:                              /* 0x1310: the timbre */
        v->timbre = a;
        return 1;
    case 0xf1:                              /* 0x132e: the volume */
        v->volume = a;
        return 1;
    case 0xfb:                              /* 0x1332: quieter, floored at 0 */
        v->pos--;
        if (--v->volume < 0) v->volume = 0;
        return 1;
    case 0xfc:                              /* 0x133e: louder */
        v->pos--;
        v->volume++;
        return 1;
    case 0xf6: {                            /* 0x120e: loop */
        /* The counter lives in the sequence: decrement it, and when it runs
         * out reload it from the next byte and carry on, otherwise jump back
         * by the sixteen-bit offset that follows. */
        int at = v->pos - 1;                /* where the counter is */
        int reload, back;
        if (at + 3 >= v->len) return 0;
        reload = v->seq[at + 1];
        back = v->seq[at + 2] | (v->seq[at + 3] << 8);
        v->seq[at]--;
        if (v->seq[at] == 0) {
            v->seq[at] = (unsigned char)reload;
            v->pos = at + 4;
        } else {
            v->pos = at + 4 - back;
            if (v->pos < 0) v->pos = 0;
        }
        return 1;
    }
    case 0xf7:                              /* 0x1351: the pitch envelope */
        v->pos--;
        if (v->pos + 5 > v->len) return 0;
        v->envA = v->seq[v->pos] | (v->seq[v->pos + 1] << 8);
        v->envB = v->seq[v->pos + 2] | (v->seq[v->pos + 3] << 8);
        v->envC = v->seq[v->pos + 4];
        v->pos += 5;
        return 1;
    case 0xfe:                              /* 0x13de: silence everything */
        v->silenceAll = 1;
        return 1;
    case 0xff:                              /* 0x127f: the end */
        return 0;
    default:
        /* f2 f3 f4 f5 f8 f9 fa fd are not worked out yet; their one operand
         * has been eaten, which keeps the walk in step. */
        return 1;
    }
}

int snd_tick(SndVoice *v, int *keyedNow)
{
    if (keyedNow) *keyedNow = 0;
    if (v->done) return 0;

    /* sub_0f2d: the note runs until its count reaches zero. */
    if (v->wait > 0 && --v->wait > 0) return 1;

    for (;;) {
        int d, n;

        if (v->pos >= v->len) {
            v->done = 1;
            v->keyed = 0;
            return 0;
        }
        d = v->seq[v->pos];
        if (d >= 0xf0) {
            v->pos++;
            if (!command(v, d)) {
                v->done = 1;
                v->keyed = 0;
                return 0;
            }
            continue;
        }
        v->pos++;

        /* The duration's bit 7 makes it a REST: 0x0f69 branches to 0x0f99,
         * which stores the pointer and leaves without reading a note byte.
         * Reading one anyway walked off the end of effect 17 and turned its
         * terminating 0xff into a note of semitone 15. */
        v->wait = d & 0x7f;
        if (v->wait == 0) v->wait = 1;
        if (d & 0x80) {
            v->keyed = 0;
            return 1;
        }
        v->keyed = 0;                               /* 0x0f71, sub_111e */
        if (v->pos >= v->len) {
            v->done = 1;
            return 0;
        }
        n = v->seq[v->pos++];
        v->tie = (n & 0x80) != 0;
        n &= 0x7f;
        /* A tie onto the same note leaves it alone; anything else keys on. */
        if (!(v->tie && n == v->note)) {
            v->note = n;
            v->keyed = 1;
            if (keyedNow) *keyedNow = 1;
        }
        return 1;
    }
}

/* ------------------------------------------------------- the level envelope */

/* sub_111e: back to stage 0 of this timbre and load all four of its bytes. */
void snd_env_key(SndVoice *v, const unsigned char *env)
{
    int at = v->timbre & 0xf0;

    v->stage = at;
    v->step = env[at];
    v->count = env[at + 1] & 0x7f;
    v->downwards = (env[at + 1] & 0x80) != 0;
    v->target = env[at + 2];
    v->level = env[at + 3];
    v->spent = 0;
    if (v->count == 0) v->count = 1;
}

void snd_env_release(SndVoice *v, const unsigned char *env)
{
    int at = (v->timbre & 0xf0) | 0x0c;         /* 0x114f, 0x1152 */

    v->stage = at;
    v->step = env[at];
    v->count = env[at + 1] & 0x7f;
    v->downwards = (env[at + 1] & 0x80) != 0;
    v->target = env[at + 2];
    if (v->count == 0) v->count = 1;
    v->spent = 0;
}

/* 0x0fab onwards.  The count runs down; when it reaches zero the level takes
 * one step towards the target, and on arriving it either chains to the next
 * stage or the voice is spent. */
int snd_env_step(SndVoice *v, const unsigned char *env)
{
    int at;

    if (v->spent) return 0;
    if (--v->count > 0) return v->level;        /* 0x0fb0: hold */

    at = v->stage;
    v->count = env[at + 1] & 0x7f;              /* reloaded from this stage */
    v->downwards = (env[at + 1] & 0x80) != 0;
    if (v->count == 0) v->count = 1;

    if (v->downwards) {
        v->level -= v->step;
        if (v->level >= 0 && v->level > v->target) return v->level;
    } else {
        v->level += v->step;
        if (v->level <= 0xff && v->level < v->target) return v->level;
    }

    /* 0x0fdf: arrived.  The target is written, and then - if it was zero, or
     * this was the last stage - 0x1016 marks the voice finished and writes a
     * level of ZERO over it.  Leaving the target standing instead ended every
     * effect on a step down to silence rather than a fade into it, which is
     * audible as a click and measured as a tail that stops around 6000. */
    v->level = v->target;
    if (v->level == 0 || (v->stage & 8)) {      /* 0x0fe5, 0x0fee */
        v->spent = 1;
        v->level = 0;                           /* 0x101a: xor al, al */
        return 0;
    }
    v->stage = at + 4;                          /* 0x0ff3 */
    at = v->stage;
    v->step = env[at];
    v->count = env[at + 1] & 0x7f;
    v->downwards = (env[at + 1] & 0x80) != 0;
    v->target = env[at + 2];
    if (v->count == 0) v->count = 1;
    return v->level;
}

/* --------------------------------------------------------------- rendering */

int snd_render_effect(const unsigned char *progDat, unsigned progDatSize,
                      int id, short *out, int maxSamples, int sampleRate)
{
    const unsigned char *periods, *env;
    SndVoice v;
    Ssg chip;
    int made = 0;
    int perTick = sampleRate / SND_TICK_HZ;
    int level = 0;

    if (progDatSize < (unsigned)(SSG_PERIOD_AT - 0x1000) + 32) return 0;
    if (progDatSize < (unsigned)(SND_ENV_AT - 0x1000) + 256) return 0;
    periods = progDat + (SSG_PERIOD_AT - 0x1000);
    env = progDat + (SND_ENV_AT - 0x1000);
    if (!snd_start(&v, progDat, progDatSize, id)) return 0;

    ssg_reset(&chip);
    ssg_write(&chip, 7, 0x3f);              /* everything off to begin with */

    for (;;) {
        int keyed = 0, room;
        if (!snd_tick(&v, &keyed)) {
            /* The sequence is over but the voice is not: sub_114b takes it into
             * the release stage and the driver keeps servicing it until it is
             * spent.  Stopping here instead cut every effect off dead, which is
             * the difference between a note that fades and one that clicks. */
            int tail = 0;
            snd_env_release(&v, env);
            while (!v.spent && made < maxSamples && tail < 240) {
                int n2 = maxSamples - made;
                level = snd_env_step(&v, env);
                ssg_write(&chip, 8, (level * (v.volume + 1)) >> 8 > 15
                                    ? 15 : (level * (v.volume + 1)) >> 8);
                if (n2 > perTick) n2 = perTick;
                if (n2 <= 0) break;
                ssg_render(&chip, out + made, n2, sampleRate);
                made += n2;
                tail++;
            }
            break;
        }
        if (keyed) {
            int p = ssg_period(periods, v.note, 0);
            ssg_write(&chip, 0, p & 0xff);
            ssg_write(&chip, 1, (p >> 8) & 0x0f);
            ssg_write(&chip, 7, 0x3e);      /* tone on channel A */
            snd_env_key(&v, env);           /* sub_111e */
        }
        /* 0x0f40: with the tie flag set, the note goes into its release when
         * its remaining ticks reach [si+9] - which the initialiser leaves at
         * zero, so that is the note's last tick. */
        if (v.keyed && v.tie && v.wait <= 1 && !(v.stage & 8))
            snd_env_release(&v, env);
        level = v.keyed ? snd_env_step(&v, env) : 0;
        /* sub_10c2: the level times volume + 1, shifted down eight. */
        ssg_write(&chip, 8, (level * (v.volume + 1)) >> 8 > 15
                            ? 15 : (level * (v.volume + 1)) >> 8);
        room = maxSamples - made;
        if (room > perTick) room = perTick;
        if (room <= 0) break;
        ssg_render(&chip, out + made, room, sampleRate);
        made += room;
    }
    return made;
}
