/* Everything the port does that is not the host's business.
 *
 * The Win32 build, the headless PNG tool and the WASM build all drive this, so
 * anything that behaves differently between them is a host bug rather than a
 * game bug.  The hosts only have to: hand over a disk image, forward keys, call
 * app_render, and put app_screen() on the display.
 */
#ifndef APP_H
#define APP_H

#include "gfx.h"

enum {
    APP_MODE_TITLE,
    APP_MODE_MAP,
    /* The first thing the game shows: sub_06e7, called from the boot at
     * 0x00b5, asks which display is attached before anything is drawn. */
    APP_MODE_DEVICE
};

/* Key codes the app understands; the host translates its own. */
enum {
    APP_KEY_START = 1,          /* space / enter */
    APP_KEY_PREV_MAP,
    APP_KEY_NEXT_MAP,
    APP_KEY_LEFT,
    APP_KEY_RIGHT,
    APP_KEY_UP,
    APP_KEY_DOWN,
    APP_KEY_TILE8,
    APP_KEY_TILE16,
    APP_KEY_TILE32,
    APP_KEY_BACK,
    APP_KEY_CASTLES,       /* toggle the unit and castle markers */
    APP_KEY_RUN,           /* run the world tick */
    APP_KEY_STEP,          /* one tick */
    APP_KEY_TITLE,         /* back to the title screen */

    /* Not the game's: fills the player's purse, for working on the parts that
     * only happen once there is money to spend.  999,999,999 rather than the
     * 32-bit maximum, because the purse is added to every turn and wrapping
     * round to nothing in the middle of a session would be worse than useless
     * - and because that is the widest number the panel's ten columns show
     * without the game having to change how it adds. */
    APP_KEY_MONEY
};

#define APP_MONEY_MAX 999999999UL

/* Opens the image and puts the app on the title screen.  0 on failure, with a
 * reason in app_status(). */
int app_init(const char *imagePath);
void app_shutdown(void);

void app_key(int key);

/* APP_KEY_START is the original's confirm button and APP_KEY_BACK its cancel:
 * on the map, confirm picks a unit up and then says where it goes, and cancel
 * opens the panel; in the panel the arrows walk the icons, confirm presses one
 * and cancel returns to the map.  Pushing the cursor off the left of the map
 * also opens the panel, as sub_269e does.
 *
 * The pointer below is the port's own addition - the original has no mouse at
 * all, not one mouse port in the binary - and it does the same things: a click
 * on an icon presses it, a click on a square is a confirm there. */
void app_hover(int x, int y);
void app_click(int x, int y);

/* -1 when nothing is picked up. */
int app_selected(void);

/* The dialog the game is showing, 0 when there is none.  Everything the panel
 * answers goes into one of these rather than into the host's own furniture, the
 * way the original draws its windows on its own screen. */
int app_dialog(void);

/* A PC-98 font ROM, handed over by whoever is running this - it is the
 * machine's, not the game's, so it is never shipped here.  With one the dialogs
 * are in the original's own Japanese; without one they are in English. */
/* Sound, as the original asks for it.  sub_0d12 is a priority latch: it keeps
 * one pending request in [0x3b46] as (id << 8) | priority, and a new one only
 * replaces it when its priority is at least as high.  Something else reads and
 * clears it.  So the port does the same, and the host is what turns an id into
 * a noise.
 *
 * The ids come from the calls themselves rather than from any table:
 *
 *   0x0602  a click that was taken - a unit picked up, a panel icon pressed
 *   0x0402  refused - not your unit, or the square will not take that order
 *   0x0702  the order was taken but could not be carried out
 *   0x0302  a country has fallen
 *   0x0f03  the game is over
 *
 * That distinction is the point: without it there is no way to tell a refusal
 * from something this port has not got round to implementing. */
/* The window sounds, which are the driver's own ids at their own priorities:
 * 0x0500 when the selection moves (0x4c2e) and 0x0601 on confirm (0x4c8a). */
#define APP_SND_MOVE    0x0500
#define APP_SND_CONFIRM 0x0601

#define APP_SND_OK      0x0602
#define APP_SND_NO      0x0402
#define APP_SND_FAILED  0x0702
#define APP_SND_FALLEN  0x0302
#define APP_SND_OVER    0x0f03

/* Whether the world is advancing - GO on the panel and the R key both toggle
 * it, so a host must ask instead of tracking its own flag. */
int app_running(void);

/* How far the player has got - the original's [0xce70].  A stage is entered
 * from here, and clearing the furthest one moves it on. */
int app_reached(void);

/* Renders one of the game's own sound effects.  Returns the sample count. */
int app_effect_pcm(int id, short *out, int maxSamples, int rate);

/* The music.
 *
 * Which song a screen wants is the game's own choice, not this port's: the
 * boot at 0x00fe puts 4 in [0x3bc6], and 0x1945 works a map's out as
 * 16 + 2 * (terrain / 10 - 1) - so the ten songs FM016..FM025 are five
 * terrains with a pair each, and 0x1979 sets the low bit to pick the second
 * of a pair.  0xca59 uses 6 for the ending.
 *
 * app_song_start loads one and app_song_fill hands out as much of it as is
 * asked for, so a host can keep a small buffer going rather than holding a
 * whole song in memory.  Filling past the end returns short: that is where a
 * caller loops by starting it again. */
int app_song_wanted(void);
int app_song_start(int number, int rate);
int app_song_fill(short *out, int frames);
int app_song_playing(void);

/* Fires one of the game's effects on the song's own chip, which is where the
 * driver puts it: an effect takes SSG channel B from the music while it
 * sounds and hands it back after.  Returns 0 when no song is playing, and
 * then app_effect_pcm is the way to hear it on its own. */
int app_song_effect(int id);

void app_sound(int idAndPriority);

/* Takes the pending request and clears it, or 0 when there is none. */
int app_sound_take(void);

int app_font_rom(const unsigned char *data, unsigned n);
int app_japanese(void);
/* The two settings the knob windows change, so a test can say what the cancel
 * did without reaching into the game. */
/* The save slots, for a host that can keep them between visits.  A slot is one
 * opaque byte array holding both the directory entry the list draws and the
 * payload, so the store does not need to know the shape of either.  The page
 * puts each used slot in localStorage and hands them back with app_slot_put on
 * the way in. */
int app_save_slots(void);
int app_slot_used(int at);
const unsigned char *app_slot_bytes(int at, unsigned *len);
int app_slot_put(int at, const unsigned char *bytes, unsigned len);
/* Changes when any slot does, so the host need not copy them all every frame. */
int app_slot_stamp(void);

/* The day the world is on, so a test can say whether a load put it back. */
int app_day(void);
int app_tax(void);
int app_speed(void);

int app_dialog_lines(void);
const char *app_dialog_line(int i);
int app_dialog_pick(void);
void app_render(void);

/* One turn of the world - the cell sweep, the unit sweep and the castles. */
void app_tick(void);

/* How many drawn frames go by between world steps: 0x1a3e puts 8 into
 * [0x32d1] and the retrace counts it down. */
int app_step_frames(void);

const Screen *app_screen(void);
int app_mode(void);
const char *app_status(void);

/* For the headless tool: jump straight somewhere without pressing keys. */
/* The display-device question sub_06e7 asks at boot. */
int app_show_device(void);

/* The screen the game opens on: the frame and the panel with the map window
 * empty, because [0x3bc2] is 0xffff until GO loads a stage. */
int app_show_ready(void);
int app_show_title(void);
int app_show_map(int number, int tileSize);

/* Which map is up - the original's [0x3bc2], the stage number. */
int app_map_number(void);

#endif
