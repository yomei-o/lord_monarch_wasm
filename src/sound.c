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

static void fm_write_tl(Opn *opn, const unsigned char *progDat,
                        unsigned progDatSize, int ch, int algorithm,
                        int volume)
{
    unsigned off = (unsigned)(FM_CARRIER_AT - 0x1000) + (unsigned)(algorithm & 7);
    int mask, tl, s;

    if (off >= progDatSize) return;
    mask = progDat[off];
    if (volume > 0x48) tl = 0x7f;
    else tl = 0x48 - (((0x48 - volume) * FM_MASTER) >> 8);
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

int snd_render_song(const unsigned char *progDat, unsigned progDatSize,
                    const unsigned char *song, unsigned songSize,
                    short *out, int maxSamples, int sampleRate)
{
    const unsigned char *periods, *fnums;
    unsigned char env[256];         /* writable: command 0xf9 fills it in */
    SndVoice v[6];
    int live[6], algo[3];
    Ssg chip;
    Opn opn;
    int made = 0, ch, mixer;
    int perTick = sampleRate / SND_TICK_HZ;

    if (progDatSize < (unsigned)(SSG_PERIOD_AT - 0x1000) + 32) return 0;
    if (progDatSize < (unsigned)(SND_ENV_AT - 0x1000) + 256) return 0;
    if (progDatSize < (unsigned)(SND_FNUM_AT - 0x1000) + 32) return 0;
    periods = progDat + (SSG_PERIOD_AT - 0x1000);
    fnums = progDat + (SND_FNUM_AT - 0x1000);
    memcpy(env, progDat + (SND_ENV_AT - 0x1000), sizeof env);

    for (ch = 0; ch < 6; ch++) {
        unsigned off = 0, len = 0;

        live[ch] = snd_song_track(song, songSize, ch, &off, &len) &&
                   snd_start_bytes(&v[ch], song + off, (int)len);
        v[ch].chan = ch % 3;
        v[ch].envRam = env;
        v[ch].fm = ch < 3;
        if (ch < 3 && progDatSize > (unsigned)(FM_VOL_AT - 0x1000) + 32)
            v[ch].fmVol = progDat + (FM_VOL_AT - 0x1000);
    }
    for (ch = 0; ch < 3; ch++) algo[ch] = 0;
    if (!live[0] && !live[1] && !live[2] && !live[3] && !live[4] && !live[5])
        return 0;

    ssg_reset(&chip);
    mixer = 0x3f;
    ssg_write(&chip, 7, mixer);
    opn_reset(&opn, (double)SND_CLOCK);

    for (;;) {
        int any = 0, room;

        /* The three FM parts. */
        for (ch = 0; ch < 3; ch++) {
            int keyed = 0;

            if (!live[ch]) continue;
            if (!snd_tick(&v[ch], &keyed)) {
                live[ch] = 0;
                opn_write(&opn, 0x28, ch);           /* key off */
                continue;
            }
            any = 1;
            if (v[ch].voiceWanted) {
                fm_load_voice(&opn, song, songSize, ch, v[ch].timbre, &algo[ch]);
                v[ch].voiceWanted = 0;
            }
            if (keyed) {
                unsigned short f = snd_fnumber(fnums, v[ch].note, 0);

                opn_write(&opn, 0x28, ch);           /* off before on */
                opn_write(&opn, 0xa4 + ch, f >> 8);
                opn_write(&opn, 0xa0 + ch, f & 0xff);
                fm_write_tl(&opn, progDat, progDatSize, ch, algo[ch],
                            v[ch].volume);
                opn_write(&opn, 0x28, 0xf0 | ch);    /* all four operators on */
            } else if (!v[ch].keyed) {
                opn_write(&opn, 0x28, ch);
            }
        }

        /* The three SSG parts. */
        for (ch = 3; ch < 6; ch++) {
            int c = ch - 3, keyed = 0, level;

            if (!live[ch]) continue;
            if (!snd_tick(&v[ch], &keyed)) {
                snd_env_release(&v[ch], env);
                if (v[ch].spent) {
                    live[ch] = 0;
                    ssg_write(&chip, 8 + c, 0);
                    mixer |= (1 << c) | (8 << c);
                    ssg_write(&chip, 7, mixer);
                }
            } else {
                any = 1;
                if (v[ch].chipPending) {
                    int r = v[ch].chipReg & 0x0f;

                    if (r == 7) mixer = v[ch].chipVal;
                    ssg_write(&chip, r, v[ch].chipVal);
                    v[ch].chipPending = 0;
                }
                if (keyed) {
                    int p = ssg_period(periods, v[ch].note, 0);
                    int a4 = v[ch].algo;

                    ssg_write(&chip, c * 2, p & 0xff);
                    ssg_write(&chip, c * 2 + 1, (p >> 8) & 0x0f);
                    /* sub_10ee: [si+4] is this channel's half of register 7.
                     * Bit 7 is tone only - and skips the noise period - bit 6
                     * is noise only, and the low bits are the noise period. */
                    if (!(a4 & 0x80)) ssg_write(&chip, 6, a4 & 0x1f);
                    mixer &= ~((1 << c) | (8 << c));
                    if (a4 & 0x40) mixer |= 1 << c;
                    if (a4 & 0x80) mixer |= 8 << c;
                    ssg_write(&chip, 7, mixer);
                    snd_env_key(&v[ch], env);
                }
                if (v[ch].keyed && v[ch].tie &&
                    v[ch].wait <= v[ch].tieAt + 1 && !(v[ch].stage & 8))
                    snd_env_release(&v[ch], env);
            }
            level = v[ch].keyed ? snd_env_step(&v[ch], env) : 0;
            level = (level * (v[ch].volume + 1)) >> 8;
            ssg_write(&chip, 8 + c, level > 15 ? 15 : level);
        }

        if (!any) break;
        room = maxSamples - made;
        if (room > perTick) room = perTick;
        if (room <= 0) break;
        ssg_render(&chip, out + made, room, sampleRate);
        opn_render(&opn, out + made, room, sampleRate);
        made += room;
    }
    return made;
}
