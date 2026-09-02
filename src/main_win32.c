/* The native host: one window, 640x400 through an 8bpp DIB.
 *
 *   monarch.exe [image.fim]
 *
 *   SPACE / ENTER   title -> map view
 *   LEFT / RIGHT    previous / next map
 *   1 2 3           8x8 / 16x16 / 32x32 tiles
 *   arrows (in map) scroll when the map is bigger than the window
 *   ESC             quit
 *
 * An 8bpp DIB with a palette in its BITMAPINFO is the closest thing Windows has
 * to what the PC-98 does, so the drawing code stays indexed all the way to the
 * blit and the palette can be swapped per terrain set the way the hardware
 * swaps it.  StretchDIBits then does the 2x scale.
 *
 * There is no game logic here yet - this is the frame the port gets built in.
 */
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disk.h"
#include "gfx.h"

#define ZOOM 2

/* The map window inside WAKU: the columns that are empty for almost the whole
 * height run x = 160..479, and the rows likewise y = 8..391.  So the view is
 * 320 x 384, which at 16x16 is 20 x 24 cells of a 48 x 48 map - a scrolling
 * view, which is what a real-time strategy game wants. */
#define VIEW_X 160
#define VIEW_Y 8
#define VIEW_W 320
#define VIEW_H 384

enum { MODE_TITLE, MODE_MAP };

static Screen scr;
static Disk *disk;
static Bank bank;
static Map map;
static int mode = MODE_TITLE;
static int mapIndex = 0, tileSize = 8, scrollX = 0, scrollY = 0;
static int dirty = 1;

static const unsigned char TITLE_PAL[16][3] = {
    {0, 0, 0}, {0, 2, 2}, {4, 14, 10}, {0, 8, 8},
    {4, 7, 7}, {7, 10, 10}, {10, 12, 12}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
};

static struct {
    BITMAPINFOHEADER h;
    RGBQUAD pal[256];
} bmi;

static void refresh_palette(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        unsigned char r, g, b;
        gfx_rgb(&scr, i, &r, &g, &b);
        bmi.pal[i].rgbRed = r;
        bmi.pal[i].rgbGreen = g;
        bmi.pal[i].rgbBlue = b;
        bmi.pal[i].rgbReserved = 0;
    }
}

static int palette_from_terrain(int terrain)
{
    char name[32];
    unsigned n = 0;
    unsigned char *b;
    snprintf(name, sizeof name, "B_%03dL.CH4", terrain);
    b = disk_read_bz(disk, name, &n);
    if (!b || n < 48) {
        free(b);
        return 0;
    }
    gfx_set_palette(&scr, b + n - 48);
    free(b);
    refresh_palette();
    return 1;
}

/* The maps are B_000.MAP .. B_051.MAP; step through them by number rather than
 * by directory order, which is not sorted on the disk. */
static int load_map(int n)
{
    char name[32], bankName[32];
    if (n < 0) n = 51;
    if (n > 51) n = 0;
    snprintf(name, sizeof name, "B_%03d.MAP", n);
    if (!gfx_load_map(&map, disk, name)) return 0;
    mapIndex = n;
    palette_from_terrain(map.terrain);
    gfx_bank_name(&map, tileSize, bankName, sizeof bankName);
    gfx_free_bank(&bank);
    if (!gfx_load_bank(&bank, disk, bankName, tileSize)) return 0;
    scrollX = scrollY = 0;
    return 1;
}

static void draw(void)
{
    if (mode == MODE_TITLE) {
        gfx_set_palette_rgb(&scr, TITLE_PAL);
        refresh_palette();
        gfx_clear(&scr, 0);
        gfx_load_screen(&scr, disk, "DS7TTL");
    } else {
        gfx_clear(&scr, 0);
        gfx_load_screen(&scr, disk, "WAKU");
        gfx_draw_map(&scr, &map, &bank, VIEW_X, VIEW_Y, scrollX, scrollY,
                     VIEW_W / bank.size + 1, VIEW_H / bank.size + 1);
    }
    dirty = 0;
}

static void scroll_by(int dx, int dy)
{
    int maxX = MAP_W - VIEW_W / bank.size, maxY = MAP_H - VIEW_H / bank.size;
    if (maxX < 0) maxX = 0;
    if (maxY < 0) maxY = 0;
    scrollX += dx;
    scrollY += dy;
    if (scrollX < 0) scrollX = 0;
    if (scrollY < 0) scrollY = 0;
    if (scrollX > maxX) scrollX = maxX;
    if (scrollY > maxY) scrollY = maxY;
    dirty = 1;
}

static void title_text(HWND w)
{
    wchar_t buf[128];
    if (mode == MODE_TITLE)
        wsprintfW(buf, L"Lord Monarch (PC-98) - title");
    else
        wsprintfW(buf, L"Lord Monarch (PC-98) - B_%03d.MAP  terrain %d  "
                  L"%dx%d tiles", mapIndex, map.terrain, bank.size, bank.size);
    SetWindowTextW(w, buf);
}

static LRESULT CALLBACK proc(HWND w, UINT m, WPARAM wp, LPARAM lp)
{
    switch (m) {
    case WM_KEYDOWN:
        switch (wp) {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        case VK_SPACE:
        case VK_RETURN:
            if (mode == MODE_TITLE) {
                mode = MODE_MAP;
                load_map(0);
                dirty = 1;
            }
            break;
        case VK_LEFT:
            if (mode == MODE_MAP) {
                if (GetKeyState(VK_SHIFT) < 0) scroll_by(-1, 0);
                else { load_map(mapIndex - 1); dirty = 1; }
            }
            break;
        case VK_RIGHT:
            if (mode == MODE_MAP) {
                if (GetKeyState(VK_SHIFT) < 0) scroll_by(1, 0);
                else { load_map(mapIndex + 1); dirty = 1; }
            }
            break;
        case VK_UP:    scroll_by(0, -1); break;
        case VK_DOWN:  scroll_by(0, 1);  break;
        case '1': case '2': case '3':
            if (mode == MODE_MAP) {
                tileSize = wp == '1' ? 8 : wp == '2' ? 16 : 32;
                load_map(mapIndex);
                dirty = 1;
            }
            break;
        default:
            break;
        }
        title_text(w);
        InvalidateRect(w, 0, FALSE);
        return 0;
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC dc = BeginPaint(w, &ps);
        if (dirty) draw();
        /* The DIB is bottom-up unless the height is negative; a negative height
         * keeps our own top-down rows, which is one fewer thing to flip. */
        StretchDIBits(dc, 0, 0, SCR_W * ZOOM, SCR_H * ZOOM,
                      0, 0, SCR_W, SCR_H, scr.px,
                      (BITMAPINFO *)&bmi, DIB_RGB_COLORS, SRCCOPY);
        EndPaint(w, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProcW(w, m, wp, lp);
}

int WINAPI wWinMain(HINSTANCE inst, HINSTANCE prev, PWSTR cmd, int show)
{
    WNDCLASSEXW wc;
    HWND w;
    MSG msg;
    RECT r;
    char imgPath[MAX_PATH * 2];
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    (void)prev; (void)cmd;
    strcpy(imgPath, "orig/\xdb\xb0\xc4\xde\xd3\xc5\xb0\xb8.FIM");
    if (argc > 1)
        WideCharToMultiByte(CP_ACP, 0, argv[1], -1, imgPath, sizeof imgPath,
                            0, 0);
    disk = disk_open(imgPath);
    if (!disk) {
        wchar_t msgbuf[512];
        MultiByteToWideChar(CP_ACP, 0, disk_error(), -1, msgbuf, 512);
        MessageBoxW(0, msgbuf, L"Lord Monarch", MB_ICONERROR);
        return 1;
    }

    memset(&bmi, 0, sizeof bmi);
    bmi.h.biSize = sizeof bmi.h;
    bmi.h.biWidth = SCR_W;
    bmi.h.biHeight = -SCR_H;            /* top-down */
    bmi.h.biPlanes = 1;
    bmi.h.biBitCount = 8;
    bmi.h.biCompression = BI_RGB;
    bmi.h.biClrUsed = 256;
    gfx_set_palette_rgb(&scr, TITLE_PAL);
    refresh_palette();

    memset(&wc, 0, sizeof wc);
    wc.cbSize = sizeof wc;
    wc.lpfnWndProc = proc;
    wc.hInstance = inst;
    wc.lpszClassName = L"LordMonarchWnd";
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    RegisterClassExW(&wc);

    r.left = r.top = 0;
    r.right = SCR_W * ZOOM;
    r.bottom = SCR_H * ZOOM;
    AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME, FALSE);
    w = CreateWindowExW(0, wc.lpszClassName, L"Lord Monarch (PC-98)",
                        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        r.right - r.left, r.bottom - r.top, 0, 0, inst, 0);
    title_text(w);
    ShowWindow(w, show);

    while (GetMessageW(&msg, 0, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    gfx_free_bank(&bank);
    disk_close(disk);
    return 0;
}
