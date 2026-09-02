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
    APP_KEY_STEP           /* one tick */
};

/* Opens the image and puts the app on the title screen.  0 on failure, with a
 * reason in app_status(). */
int app_init(const char *imagePath);
void app_shutdown(void);

void app_key(int key);

/* The pointer, in screen pixels (0..639, 0..399).  The original is keyboard
 * only - there is no INT 33h anywhere in it - so this is the port's own way in:
 * a click inside the map picks up one of the player's units, and the next click
 * sends it somewhere, which is the game's own "walk there" order (a path and
 * state 2).  Clicks outside the map are ignored for now; the panel's icons have
 * not been decoded. */
void app_hover(int x, int y);
void app_click(int x, int y);

/* -1 when nothing is picked up. */
int app_selected(void);
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
