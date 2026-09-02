#include "sound.h"
#include "ssg.h"
#include "opn.h"

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

/* A word out of a table in PROG.DAT, or 0 when it is off the end. */
static unsigned dat_word(const unsigned char *progDat, unsigned progDatSize,
                         unsigned addr)
{
    unsigned off = addr - 0x1000;

    if (addr < 0x1000 || off + 2 > progDatSize) return 0;
    return progDat[off] | (progDat[off + 1] << 8);
}

/* Where a sequence stops.  NOT at the first 0xff: 0xff turns up inside
 * operands - one pitch envelope is f7 01 01 38 ff - and stopping there
 * truncated it to nothing.  The sequences lie one after another, so the end is
 * whichever address in the same table comes next, and the last one is capped
 * at `hardEnd`. */
static unsigned seq_end(const unsigned char *progDat, unsigned progDatSize,
                        unsigned tableAt, int words, unsigned seqAddr,
                        unsigned hardEnd)
{
    unsigned end = hardEnd;
    int j;

    for (j = 0; j < words; j++) {
        unsigned a = dat_word(progDat, progDatSize, tableAt + (unsigned)j * 2);

        if (a > seqAddr && a < end) end = a;
    }
    return end;
}

/* Copies one sequence in.  It is copied rather than pointed at because command
 * 0xf6 decrements its own counter inside the data: played in place it would
 * work once. */
static int start_at(SndVoice *v, const unsigned char *progDat,
                    unsigned progDatSize, unsigned seqAddr, unsigned end)
{
    unsigned off, i;

    memset(v, 0, sizeof *v);
    v->note = -1;
    v->volume = 0x0f;
    if (seqAddr < 0x1000 || end <= seqAddr) return 0;
    off = seqAddr - 0x1000;
    if (off >= progDatSize) return 0;
    if (end - 0x1000 > progDatSize) end = progDatSize + 0x1000;
    for (i = 0; off + i < end - 0x1000 && i < SND_SEQ_MAX; i++)
        v->seq[i] = progDat[off + i];
    v->len = (int)i;
    return v->len > 0;
}

int snd_start(SndVoice *v, const unsigned char *progDat, unsigned progDatSize,
              int id)
{
    unsigned a, b, want;

    memset(v, 0, sizeof *v);
    v->note = -1;
    v->volume = 0x0f;
    if (id < 0 || id >= SND_EFFECTS) return 0;

    /* See sound.h: the sound board's table is pairs, and the second of a pair
     * lands on the same voice as the first, so it is the one that sounds. */
    a = dat_word(progDat, progDatSize, SND_FX_AT + (unsigned)id * 4);
    b = dat_word(progDat, progDatSize, SND_FX_AT + (unsigned)id * 4 + 2);
    want = b ? b : a;
    if (!want) return 0;
    return start_at(v, progDat, progDatSize, want,
                    seq_end(progDat, progDatSize, SND_FX_AT, SND_EFFECTS * 2,
                            want, SND_FX_END));
}

/* The beeper driver's own nineteen, from DS:0x38a1.  Nothing plays these on a
 * machine with a sound board; they are here so the two can be compared. */
int snd_start_beep(SndVoice *v, const unsigned char *progDat,
                   unsigned progDatSize, int id)
{
    unsigned a;

    memset(v, 0, sizeof *v);
    v->note = -1;
    v->volume = 0x0f;
    if (id < 0 || id >= SND_EFFECTS) return 0;
    a = dat_word(progDat, progDatSize, SND_BEEP_AT + (unsigned)id * 2);
    if (!a) return 0;
    return start_at(v, progDat, progDatSize, a,
                    seq_end(progDat, progDatSize, SND_BEEP_AT, SND_EFFECTS,
                            a, 0x3a3a));
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
    case 0xf0:
        if (v->fm) {
            /* 0x11c6: [si+5] is the voice number and the handler falls into
             * 0x1430, which uploads it.  A song's first command is usually
             * "f0 00", so waiting for the number to change would never upload
             * anything - which is exactly what went wrong the first time. */
            v->timbre = a;
            v->voiceWanted = 1;
        } else {
            v->timbre = a << 4;             /* 0x1310: [si+5] = al << 4 */
        }
        return 1;
    case 0xf1:
        /* 0x132e on the SSG side is the volume as it stands; 0x11cc on the FM
         * side maps it through DS:0x2431 first and the result is a level where
         * bigger is quieter. */
        v->volume = (v->fm && v->fmVol) ? v->fmVol[a & 0x1f] : a;
        return 1;
    case 0xfb:
        v->pos--;
        if (v->fm) {                        /* 0x11d8: quieter is TL + 3 */
            v->volume += 3;
            if (v->volume >= 0x80) v->volume = 0x7f;
        } else if (--v->volume < 0) {       /* 0x1332 */
            v->volume = 0;
        }
        return 1;
    case 0xfc:
        v->pos--;
        if (v->fm) {                        /* 0x11ea: louder is TL - 3 */
            v->volume -= 3;
            if (v->volume < 0) v->volume = 0;
        } else {                            /* 0x133e */
            v->volume++;
        }
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
    case 0xf2:                              /* 0x11fa: [si+9] */
        v->tieAt = a;
        return 1;
    case 0xf3:                              /* 0x11fe: [si+8] */
        v->param8 = a;
        return 1;
    case 0xf4:
        /* 0x134d on the SSG side is [si+4], the tone/noise half of register 7.
         * 0x1202 on the FM side is [si+6], the volume, and then a TL write. */
        if (v->fm) v->volume = a;
        else v->algo = a;
        return 1;
    case 0xf5:                              /* 0x1208: [0x3b3d], then
                                             * sub_14c9 writes it to the
                                             * YM2203's timer at 0x26/0x27 */
        v->tempo = a;
        return 1;
    case 0xf8:                              /* 0x1373: poke the structure */
        if (v->pos >= v->len) return 0;
        {
            int b = v->seq[v->pos++];

            /* [si + al] = b, for the offsets this port keeps.  0x10 is its
             * own case in the original and sets bits in [si+0x1f]. */
            switch (a) {
            case 4:  v->algo = b; break;
            case 5:  v->timbre = b; break;
            case 6:  v->volume = b; break;
            case 8:  v->param8 = b; break;
            case 9:  v->tieAt = b; break;
            default: break;                 /* the rest are not modelled */
            }
        }
        return 1;
    case 0xf9: {                            /* 0x1398: the song's own envelope */
        /* On the FM side this is 0x13de, which is a bare ret: the operand the
         * dispatcher already took is the whole of it. */
        if (v->fm) return 1;
        /* The slot is [0x3b3f] + this channel + 0x0a, and [si+5] becomes
         * slot << 4 - so f9 both writes an envelope and selects it.  The six
         * bytes go into the table at DS:0x34e2 + slot*16, at +0, +3, +4, +6,
         * +8 and +12, which is stage 0's step and starting level, stage 1's
         * step and target, and one step each for stages 2 and 3. */
        int at = v->pos - 1, slot = v->envBase + v->chan + 0x0a, base;

        if (at + 6 > v->len) return 0;
        base = (slot << 4) & 0xff;
        v->timbre = base;
        if (v->envRam) {
            v->envRam[base + 0x00] = v->seq[at + 1];
            v->envRam[base + 0x03] = v->seq[at + 0];
            v->envRam[base + 0x04] = v->seq[at + 2];
            v->envRam[base + 0x06] = v->seq[at + 3];
            v->envRam[base + 0x08] = v->seq[at + 4];
            v->envRam[base + 0x0c] = v->seq[at + 5];
        }
        v->pos = at + 6;
        return 1;
    }
    case 0xfa:                              /* 0x13d6: straight to the chip */
        /* dh = al, dl = the next byte, sub_740d.  Left for the renderer. */
        if (v->pos >= v->len) return 0;
        v->chipReg = a;
        v->chipVal = v->seq[v->pos++];
        v->chipPending = 1;
        return 1;
    case 0xfd: {                            /* 0x1225: a conditional jump */
        /* bx += the sixteen-bit word that starts at the operand, and the jump
         * only sticks if the byte after the target is 1; otherwise it carries
         * on past both operand bytes. */
        int at = v->pos - 1, disp, target;

        if (at + 2 > v->len) return 0;
        disp = v->seq[at] | (v->seq[at + 1] << 8);
        target = at + 1 + disp;
        if (target >= 0 && target + 1 < v->len && v->seq[target + 1] == 1)
            v->pos = target;
        else
            v->pos = at + 2;
        return 1;
    }
    default:
        return 1;
    }
}

int snd_tick(SndVoice *v, int *keyedNow)
{
    if (keyedNow) *keyedNow = 0;
    v->noteEvent = 0;
    v->restEvent = 0;
    v->waitWas = v->wait;
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
            v->restEvent = 1;                       /* 0x0ece */
            v->prevTie = v->tie;
            v->tie = 0;                             /* 0x0ed1: [si+0xa] = 0 */
            return 1;
        }
        v->keyed = 0;                               /* 0x0f71, sub_111e */
        if (v->pos >= v->len) {
            v->done = 1;
            return 0;
        }
        n = v->seq[v->pos++];
        v->prevTie = v->tie;
        v->tie = (n & 0x80) != 0;
        n &= 0x7f;
        v->noteEvent = 1;
        /* 0x0ebe: the F-number is rewritten unless the note before this one
         * was tied and had the same pitch. */
        v->pitchNew = !(v->prevTie && n == v->note);
        /* A tie onto the same note leaves it alone; anything else keys on. */
        if (!(v->tie && n == v->note)) {
            v->note = n;
            v->keyed = 1;
            if (keyedNow) *keyedNow = 1;
        }
        v->note = n;
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

/* --------------------------------------------------------------- the songs */

int snd_start_bytes(SndVoice *v, const unsigned char *seq, int len)
{
    int i;

    memset(v, 0, sizeof *v);
    v->note = -1;
    v->volume = 0x0f;
    /* FUN_1000_0bda gives every SSG channel [si+4] = 0x80, which sub_10ee
     * reads as "tone, no noise". */
    v->algo = 0x80;
    if (!seq || len <= 0) return 0;
    if (len > SND_SEQ_MAX) len = SND_SEQ_MAX;
    for (i = 0; i < len; i++) v->seq[i] = seq[i];
    v->len = len;
    return 1;
}

int snd_song_track(const unsigned char *song, unsigned songSize, int track,
                   unsigned *offOut, unsigned *lenOut)
{
    unsigned a, b;

    if (!song || track < 0 || track > 5 || songSize < 20) return 0;
    /* Word 3 is the first channel, so track n is word 3 + n; the next word
     * along is where it stops, and for the last one that is word 9. */
    a = song[(3 + track) * 2] | (unsigned)song[(3 + track) * 2 + 1] << 8;
    b = song[(4 + track) * 2] | (unsigned)song[(4 + track) * 2 + 1] << 8;
    if (a >= songSize || b > songSize || b <= a) return 0;
    *offOut = a;
    *lenOut = b - a;
    return 1;
}

/* The FM side.  A song's first three tracks go to the YM2203's FM channels,
 * and they are the half this port was missing.
 *
 *   0x11c6 -> 0x1430   command 0xf0 uploads a voice: 24 registers from
 *                      0x30 + channel stepping by four, out of the song's own
 *                      table at file offset 0x20 + timbre * 32, then the
 *                      twenty-fifth byte to 0xb0 + channel
 *   sub_1488           the volume, as TL on the carriers only.  The mask is
 *                      DS:0x2445 indexed by the algorithm - 08 08 08 08 0c 0e
 *                      0e 0f, which is the standard carrier set and agrees
 *                      with the wiring in opn.c - and the level is
 *                      0x48 - ((0x48 - volume) * [0x3b42] >> 8)
 *   0x0ee0             the note: F-number to 0xa4 + ch then 0xa0 + ch
 *   0x13fe, 0x140d     key on and off through register 0x28
 */
#define FM_CARRIER_AT 0x2445        /* eight masks, one per algorithm */
#define FM_VOL_AT 0x2431            /* what the FM side's 0xf1 maps through */
#define FM_MASTER 0xff              /* DS:0x3b42, which nothing here changes */

/* sub_1488.  `last` is [si+0x1d], the level the chip was given: the original
 * works the new one out every time it is called and writes nothing when it
 * comes out the same, so this keeps that byte too.
 *
 * When it is called matters as much as what it writes.  All three volume
 * commands end in `jmp 0x1488` - 0x11cc sets the level through DS:0x2431,
 * 0x11d8 adds three and 0x11ea takes three off - and the voice upload at
 * 0x147c puts 0xff in [si+0x1d] and calls it as well.  On top of that the
 * interrupt runs it over all three FM voices at 0x0daf whenever [0x3b40]
 * says a master fade is in progress.  Calling it once at key-on, which is
 * what this used to do, meant a part that swells or dies away inside a note
 * stayed wherever it started. */
static void fm_write_tl(Opn *opn, const unsigned char *progDat,
                        unsigned progDatSize, int ch, int algorithm,
                        int volume, int *last)
{
    unsigned off = (unsigned)(FM_CARRIER_AT - 0x1000) + (unsigned)(algorithm & 7);
    int mask, tl, s;

    if (off >= progDatSize) return;
    mask = progDat[off];
    if (volume > 0x48) tl = 0x7f;
    else tl = 0x48 - (((0x48 - volume) * FM_MASTER) >> 8);
    if (tl == *last) return;
    *last = tl;
    for (s = 0; s < 4; s++)
        if (mask >> s & 1) opn_write(opn, 0x40 + s * 4 + ch, tl);
}

/* 0x1430, the voice upload. */
static void fm_load_voice(Opn *opn, const unsigned char *song, unsigned songSize,
                          int ch, int timbre, int *algorithmOut)
{
    unsigned at = 0x20 + (unsigned)timbre * 32;
    int s, i;

    /* The old voice is silenced first: 0xff into 0x80 + ch and the three
     * above it. */
    for (s = 0; s < 4; s++) opn_write(opn, 0x80 + s * 4 + ch, 0xff);
    if (at + 25 > songSize) return;
    for (i = 0; i < 24; i++) opn_write(opn, 0x30 + i * 4 + ch, song[at + i]);
    opn_write(opn, 0xb0 + ch, song[at + 24]);
    *algorithmOut = song[at + 24] & 7;
}

int snd_song_open(SndSong *s, const unsigned char *progDat,
                  unsigned progDatSize, const unsigned char *song,
                  unsigned songSize, int sampleRate)
{
    int ch;

    memset(s, 0, sizeof *s);
    if (progDatSize < (unsigned)(SSG_PERIOD_AT - 0x1000) + 32) return 0;
    if (progDatSize < (unsigned)(SND_ENV_AT - 0x1000) + 256) return 0;
    if (progDatSize < (unsigned)(SND_FNUM_AT - 0x1000) + 32) return 0;
    if (sampleRate < 4000) return 0;
    s->progDat = progDat;
    s->progDatSize = progDatSize;
    s->song = song;
    s->songSize = songSize;
    s->sampleRate = sampleRate;
    s->perTick = sampleRate / SND_TICK_HZ;
    s->periods = progDat + (SSG_PERIOD_AT - 0x1000);
    s->fnums = progDat + (SND_FNUM_AT - 0x1000);
    memcpy(s->env, progDat + (SND_ENV_AT - 0x1000), sizeof s->env);

    for (ch = 0; ch < 6; ch++) {
        unsigned off = 0, len = 0;

        s->live[ch] = snd_song_track(song, songSize, ch, &off, &len) &&
                      snd_start_bytes(&s->v[ch], song + off, (int)len);
        s->v[ch].chan = ch % 3;
        s->v[ch].envRam = s->env;
        s->v[ch].fm = ch < 3;
        if (ch < 3 && progDatSize > (unsigned)(FM_VOL_AT - 0x1000) + 32)
            s->v[ch].fmVol = progDat + (FM_VOL_AT - 0x1000);
    }
    for (ch = 0; ch < 3; ch++) { s->algo[ch] = 0; s->fmTl[ch] = -1; }
    if (!s->live[0] && !s->live[1] && !s->live[2] &&
        !s->live[3] && !s->live[4] && !s->live[5])
        return 0;

    ssg_reset(&s->chip);
    s->mixer = 0x3f;
    ssg_write(&s->chip, 7, s->mixer);
    opn_reset(&s->opn, (double)SND_CLOCK);
    return 1;
}

/* One tick of one SSG voice.  `c` is the chip channel; `mute` drops every
 * write, which is what [0x3b43] does to a voice whose channel an effect has
 * borrowed - sub_740d returns without writing while it is set, so the voice
 * keeps its place in the sequence and simply is not heard. */
static void ssg_voice_tick(SndSong *s, SndVoice *v, int *live, int c,
                           int mute, int *any)
{
    int keyed = 0, level;

    if (!snd_tick(v, &keyed)) {
        snd_env_release(v, s->env);
        if (v->spent) {
            *live = 0;
            if (!mute) {
                ssg_write(&s->chip, 8 + c, 0);
                s->mixer |= (1 << c) | (8 << c);
                ssg_write(&s->chip, 7, s->mixer);
            }
        }
    } else {
        *any = 1;
        if (v->chipPending) {
            int r = v->chipReg & 0x0f;

            if (!mute) {
                if (r == 7) s->mixer = v->chipVal;
                ssg_write(&s->chip, r, v->chipVal);
            }
            v->chipPending = 0;
        }
        /* Either a new note, or the channel just came back from an effect and
         * has to be told again what it was playing. */
        if (keyed || (s->refresh && !mute && c == SND_FX_CHANNEL &&
                      v != &s->fx && v->keyed)) {
            int p = ssg_period(s->periods, v->note, 0);
            int a4 = v->algo;

            if (!mute) {
                ssg_write(&s->chip, c * 2, p & 0xff);
                ssg_write(&s->chip, c * 2 + 1, (p >> 8) & 0x0f);
                /* sub_10ee: [si+4] is this channel's half of register 7.
                 * Bit 7 is tone only - and skips the noise period - bit 6 is
                 * noise only, and the low bits are the noise period. */
                if (!(a4 & 0x80)) ssg_write(&s->chip, 6, a4 & 0x1f);
                s->mixer &= ~((1 << c) | (8 << c));
                if (a4 & 0x40) s->mixer |= 1 << c;
                if (a4 & 0x80) s->mixer |= 8 << c;
                ssg_write(&s->chip, 7, s->mixer);
            }
            if (keyed) snd_env_key(v, s->env);
            if (!mute && c == SND_FX_CHANNEL && v != &s->fx) s->refresh = 0;
        }
        if (v->keyed && v->tie && v->wait <= v->tieAt + 1 && !(v->stage & 8))
            snd_env_release(v, s->env);
    }
    level = v->keyed ? snd_env_step(v, s->env) : 0;
    level = (level * (v->volume + 1)) >> 8;
    if (!mute) ssg_write(&s->chip, 8 + c, level > 15 ? 15 : level);
}

/* One tick of the driver.  Returns 0 when every part has finished. */
static int song_tick(SndSong *s)
{
    int any = 0, ch;

        /* The three FM parts. */
        for (ch = 0; ch < 3; ch++) {
            int keyed = 0;

            if (!s->live[ch]) continue;
            if (!snd_tick(&s->v[ch], &keyed)) {
                s->live[ch] = 0;
                opn_write(&s->opn, 0x28, ch);           /* key off */
                continue;
            }
            any = 1;
            if (s->v[ch].voiceWanted) {
                fm_load_voice(&s->opn, s->song, s->songSize, ch, s->v[ch].timbre, &s->algo[ch]);
                s->v[ch].voiceWanted = 0;
                s->fmTl[ch] = 0xff;                     /* 0x147c: [si+0x1d]=0xff */
            }
            /* Every tick, not only at key-on: see fm_write_tl. */
            fm_write_tl(&s->opn, s->progDat, s->progDatSize, ch, s->algo[ch],
                        s->v[ch].volume, &s->fmTl[ch]);
            /* 0x0e75: a note that is not tied lets go [si+9] ticks early, so
             * the voice's own release has somewhere to ring. */
            if (!s->v[ch].tie && s->v[ch].tieAt && s->v[ch].waitWas == s->v[ch].tieAt)
                opn_write(&s->opn, 0x28, ch);
            if (s->v[ch].restEvent) {
                opn_write(&s->opn, 0x28, ch);           /* 0x0ece */
            } else if (s->v[ch].noteEvent) {
                /* 0x0e89: the note that just ended lets go only if it was not
                 * tied - and then 0x0ea9 keys on either way.  Writing 0x28
                 * with the bits already set is what a legato is on this s->chip:
                 * the envelope only restarts on a nought-to-one edge, so
                 * keying off first, which is what this used to do whenever a
                 * tied note changed pitch, re-attacked every slur. */
                if (!s->v[ch].prevTie) opn_write(&s->opn, 0x28, ch);
                if (s->v[ch].pitchNew) {
                    unsigned short f = snd_fnumber(s->fnums, s->v[ch].note, 0);

                    opn_write(&s->opn, 0xa4 + ch, f >> 8);
                    opn_write(&s->opn, 0xa0 + ch, f & 0xff);
                }
                opn_write(&s->opn, 0x28, 0xf0 | ch);
            }
        }

        /* The three SSG parts, then the effect on the one it has taken. */
        for (ch = 3; ch < 6; ch++)
            if (s->live[ch])
                ssg_voice_tick(s, &s->v[ch], &s->live[ch], ch - 3,
                               ch - 3 == SND_FX_CHANNEL && s->borrowed, &any);
        if (s->fxLive) {
            ssg_voice_tick(s, &s->fx, &s->fxLive, SND_FX_CHANNEL, 0, &any);
            if (!s->fxLive) {
                /* 0x12d1: the channel goes back to the music, and its
                 * registers are written again because nothing has reached
                 * the chip from it while the effect was on. */
                s->borrowed = 0;
                s->refresh = 1;
            }
        }
    return any;
}

int snd_song_fill(SndSong *s, short *out, int samples)
{
    int made = 0;

    while (made < samples) {
        int room;

        if (s->pending <= 0) {
            if (s->done) break;
            if (!song_tick(s)) { s->done = 1; break; }
            s->pending = s->perTick;
            if (s->pending <= 0) { s->done = 1; break; }
        }
        room = samples - made;
        if (room > s->pending) room = s->pending;
        /* The SSG writes and the FM adds on top, which is the order the chip
         * has them in. */
        ssg_render(&s->chip, out + made, room, s->sampleRate);
        opn_render(&s->opn, out + made, room, s->sampleRate);
        made += room;
        s->pending -= room;
    }
    return made;
}

int snd_song_effect(SndSong *s, int id)
{
    if (!snd_start(&s->fx, s->progDat, s->progDatSize, id)) return 0;
    s->fx.chan = SND_FX_CHANNEL;
    s->fx.envRam = s->env;
    s->fxLive = 1;
    s->borrowed = 1;                    /* 0x0e67 */
    s->done = 0;                        /* an effect can outlive the song */
    return 1;
}

int snd_render_song(const unsigned char *progDat, unsigned progDatSize,
                    const unsigned char *song, unsigned songSize,
                    short *out, int maxSamples, int sampleRate)
{
    static SndSong s;           /* a kilobyte or so; not worth the stack */
    int made = 0;

    if (!snd_song_open(&s, progDat, progDatSize, song, songSize, sampleRate))
        return 0;
    while (made < maxSamples) {
        int n = snd_song_fill(&s, out + made, maxSamples - made);

        if (n <= 0) break;
        made += n;
    }
    return made;
}
