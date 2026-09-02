/* PNG output, so a render can be checked from the console instead of a window. */
#ifndef PNG_H
#define PNG_H

int png_write_indexed(const char *path, int w, int h,
                      const unsigned char *px, int stride,
                      const unsigned char pal[][3], int palCount);

#endif
