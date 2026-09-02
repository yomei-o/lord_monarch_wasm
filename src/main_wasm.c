/* The browser host.
 *
 * No WebGL: the target machines have none, so the frame is rasterised into a
 * plain RGBA buffer here and JS hands it to putImageData.  The only thing that
 * crosses the boundary is a pointer into the wasm heap, so there is no copy on
 * this side and one on the JS side.
 *
 * The floppy image is baked in with --embed-file, which keeps the page to two
 * files and means the disk reader is the same code as the native build's.
 */
#include <emscripten.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

#define IMAGE_PATH "/monarch.fim"

static unsigned char rgba[SCR_W * SCR_H * 4];

EMSCRIPTEN_KEEPALIVE
int lm_init(void)
{
    return app_init(IMAGE_PATH);
}

EMSCRIPTEN_KEEPALIVE
int lm_width(void) { return SCR_W; }

EMSCRIPTEN_KEEPALIVE
int lm_height(void) { return SCR_H; }

EMSCRIPTEN_KEEPALIVE
unsigned char *lm_framebuffer(void) { return rgba; }

EMSCRIPTEN_KEEPALIVE
const char *lm_status(void) { return app_status(); }

EMSCRIPTEN_KEEPALIVE
int lm_mode(void) { return app_mode(); }

EMSCRIPTEN_KEEPALIVE
void lm_key(int key) { app_key(key); }

/* The pointer, in the frame's own 640 x 400 pixels.  The page scales the canvas
 * with CSS, so it divides the client coordinates itself. */
EMSCRIPTEN_KEEPALIVE
void lm_hover(int x, int y) { app_hover(x, y); }

EMSCRIPTEN_KEEPALIVE
void lm_click(int x, int y) { app_click(x, y); }

EMSCRIPTEN_KEEPALIVE
int lm_selected(void) { return app_selected(); }

/* A font ROM handed over by the page.  The buffer lives here rather than being
 * malloc'd from JS so that nothing but the lm_* functions has to be exported:
 * the page writes into lm_font_rom_buffer() and then calls lm_font_rom() with
 * how many bytes it wrote. */
static unsigned char romBuf[0x50000];

EMSCRIPTEN_KEEPALIVE unsigned char *lm_font_rom_buffer(void) { return romBuf; }
EMSCRIPTEN_KEEPALIVE int lm_font_rom_capacity(void) { return (int)sizeof romBuf; }
EMSCRIPTEN_KEEPALIVE int lm_font_rom(int n)
{
    if (n <= 0 || (unsigned)n > sizeof romBuf) return 0;
    return app_font_rom(romBuf, (unsigned)n);
}
EMSCRIPTEN_KEEPALIVE int lm_japanese(void) { return app_japanese(); }

/* The pending sound request, taken and cleared: (id << 8) | priority, or 0. */
EMSCRIPTEN_KEEPALIVE int lm_sound(void) { return app_sound_take(); }

EMSCRIPTEN_KEEPALIVE int lm_dialog(void) { return app_dialog(); }
EMSCRIPTEN_KEEPALIVE int lm_dialog_lines(void) { return app_dialog_lines(); }
EMSCRIPTEN_KEEPALIVE int lm_dialog_pick(void) { return app_dialog_pick(); }
EMSCRIPTEN_KEEPALIVE const char *lm_dialog_line(int i)
{
    return app_dialog_line(i);
}

/* Expands the indexed frame to RGBA.  A 16-entry lookup rebuilt each frame is
 * cheaper than it looks and means a palette change needs no invalidation. */
EMSCRIPTEN_KEEPALIVE
void lm_render(void)
{
    const Screen *s;
    unsigned lut[16];
    int i;
    size_t n;

    app_render();
    s = app_screen();
    for (i = 0; i < 16; i++) {
        unsigned char r, g, b;
        gfx_rgb(s, i, &r, &g, &b);
        /* Little-endian ABGR in memory reads as RGBA in a Uint8ClampedArray. */
        lut[i] = (unsigned)r | ((unsigned)g << 8) | ((unsigned)b << 16) |
                 0xff000000u;
    }
    for (n = 0; n < (size_t)SCR_W * SCR_H; n++)
        memcpy(rgba + n * 4, &lut[s->px[n] & 15], 4);
}
