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
    APP_MODE_MAP
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
    APP_KEY_TITLE          /* back to the title screen */
};

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
int app_dialog_lines(void);
const char *app_dialog_line(int i);
int app_dialog_pick(void);
void app_render(void);

/* One turn of the world - the cell sweep, the unit sweep and the castles. */
void app_tick(void);

const Screen *app_screen(void);
int app_mode(void);
const char *app_status(void);

/* For the headless tool: jump straight somewhere without pressing keys. */
int app_show_title(void);
int app_show_map(int number, int tileSize);

#endif
