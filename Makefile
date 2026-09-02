# Native build.  mingw from w64devkit; -mwindows keeps the console off the
# window build, and monarch_shot stays a console tool so renders can be checked
# without a window opening on a desktop somebody is using.
CC      ?= gcc
CFLAGS  ?= -O2 -Wall -Wextra -std=c99
OUT     ?= tmp

CORE = src/disk.c src/gfx.c src/bz.c

all: $(OUT)/monarch.exe $(OUT)/monarch_shot.exe

$(OUT)/monarch.exe: src/main_win32.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -mwindows -municode -o $@ $^ -lgdi32

$(OUT)/monarch_shot.exe: src/main_shot.c src/png.c $(CORE) | $(OUT)
	$(CC) $(CFLAGS) -o $@ $^

$(OUT):
	mkdir -p $(OUT)

# Regenerate the verification renders with the native code path.
shots: $(OUT)/monarch_shot.exe
	sh tools/shots.sh

clean:
	rm -f $(OUT)/monarch.exe $(OUT)/monarch_shot.exe

.PHONY: all shots clean
