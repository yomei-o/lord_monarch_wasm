/* The native host: one window, 640x400 through an 8bpp DIB.
 *
 *   monarch.exe [image.fim]
 *
 *   SPACE / ENTER    title -> map view
 *   LEFT / RIGHT     previous / next map
 *   arrows + SHIFT   scroll the view
 *   1 2 3            8x8 / 16x16 / 32x32 tiles
 *   C                mark the four castles
 *   BACKSPACE        back to the title
 *   ESC              quit
 *
 * An 8bpp DIB with the palette in its BITMAPINFO is the closest thing Windows
 * has to what the PC-98 does, so the drawing stays indexed all the way to the
 * blit and the palette can be swapped per terrain set the way the hardware
 * swaps it.  StretchDIBits does the 2x scale.
 *
 * Everything that is not Windows lives in app.c, shared with the WASM build and
 * the headless PNG tool.
 */
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "app.h"

#define ZOOM 2

static struct {
    BITMAPINFOHEADER h;
    RGBQUAD pal[256];
} bmi;

static void refresh_palette(void)
{
    const Screen *s = app_screen();
    int i;
    for (i = 0; i < 16; i++) {
        unsigned char r, g, b;
        gfx_rgb(s, i, &r, &g, &b);
        bmi.pal[i].rgbRed = r;
        bmi.pal[i].rgbGreen = g;
        bmi.pal[i].rgbBlue = b;
        bmi.pal[i].rgbReserved = 0;
    }
}

static void set_title(HWND w)
{
    wchar_t buf[320];
    MultiByteToWideChar(CP_ACP, 0, app_status(), -1, buf, 300);
    SetWindowTextW(w, buf);
}

static int translate(WPARAM wp, int shift)
{
    switch (wp) {
    case VK_SPACE: case VK_RETURN: return APP_KEY_START;
    case VK_BACK:                  return APP_KEY_BACK;
    case VK_LEFT:  return shift ? APP_KEY_LEFT  : APP_KEY_PREV_MAP;
    case VK_RIGHT: return shift ? APP_KEY_RIGHT : APP_KEY_NEXT_MAP;
    case VK_UP:    return APP_KEY_UP;
    case VK_DOWN:  return APP_KEY_DOWN;
    case '1':      return APP_KEY_TILE8;
    case '2':      return APP_KEY_TILE16;
    case '3':      return APP_KEY_TILE32;
    case 'C':      return APP_KEY_CASTLES;
    default:       return 0;
    }
}

static LRESULT CALLBACK proc(HWND w, UINT m, WPARAM wp, LPARAM lp)
{
    switch (m) {
    case WM_KEYDOWN: {
        int key;
        if (wp == VK_ESCAPE) {
            PostQuitMessage(0);
            return 0;
        }
        key = translate(wp, GetKeyState(VK_SHIFT) < 0);
        if (key) {
            app_key(key);
            refresh_palette();
            set_title(w);
            InvalidateRect(w, 0, FALSE);
        }
        return 0;
    }
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC dc = BeginPaint(w, &ps);
        app_render();
        StretchDIBits(dc, 0, 0, SCR_W * ZOOM, SCR_H * ZOOM,
                      0, 0, SCR_W, SCR_H, app_screen()->px,
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
    /* The image on the disk has a Shift-JIS half-width katakana name, so the
     * default is spelled in bytes rather than as a literal. */
    char imgPath[MAX_PATH * 2] = "orig/\xdb\xb0\xc4\xde\xd3\xc5\xb0\xb8.FIM";
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    (void)prev; (void)cmd;
    if (argc > 1)
        WideCharToMultiByte(CP_ACP, 0, argv[1], -1, imgPath, sizeof imgPath,
                            0, 0);
    if (!app_init(imgPath)) {
        wchar_t buf[512];
        MultiByteToWideChar(CP_ACP, 0, app_status(), -1, buf, 512);
        MessageBoxW(0, buf, L"Lord Monarch", MB_ICONERROR);
        return 1;
    }

    memset(&bmi, 0, sizeof bmi);
    bmi.h.biSize = sizeof bmi.h;
    bmi.h.biWidth = SCR_W;
    bmi.h.biHeight = -SCR_H;            /* negative: our rows are top-down */
    bmi.h.biPlanes = 1;
    bmi.h.biBitCount = 8;
    bmi.h.biCompression = BI_RGB;
    bmi.h.biClrUsed = 256;
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
    set_title(w);
    ShowWindow(w, show);

    while (GetMessageW(&msg, 0, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    app_shutdown();
    return 0;
}
