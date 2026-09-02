# Native and WASM builds.
#
# mingw from w64devkit for the native side; -mwindows keeps a console off the
# window build, while monarch_shot stays a console tool so a render can be
# checked without a window opening on a desktop somebody is using.
#
# The WASM build bakes the floppy image in with --embed-file, so the page is
# just two files and the disk reader is the same code as the native build's.
CC      ?= gcc
CFLAGS  ?= -O2 -Wall -Wextra -std=c99
OUT     ?= tmp
EMCC    ?= C:/prog/emsdk/emsdk/upstream/emscripten/emcc.exe
IMAGE   ?= $(firstword $(wildcard orig/*.FIM))

CORE = src/disk.c src/gfx.c src/bz.c src/lmz.c
APP  = src/app.c $(CORE)

all: $(OUT)/monarch.exe $(OUT)/monarch_shot.exe

$(OUT)/monarch.exe: src/main_win32.c $(APP) | $(OUT)
	$(CC) $(CFLAGS) -mwindows -municode -o $@ $^ -lgdi32

$(OUT)/monarch_shot.exe: src/main_shot.c src/png.c $(APP) | $(OUT)
	$(CC) $(CFLAGS) -o $@ $^

$(OUT):
	mkdir -p $(OUT)

# Regenerate the verification renders through the native code path.
shots: $(OUT)/monarch_shot.exe
	sh tools/shots.sh

# GitHub Pages serves docs/, so the WASM output lands there.
#
# The image on the disk is named in Shift-JIS half-width katakana, which no
# shell here passes through intact, so it is copied to an ASCII name first.
wasm: docs/monarch.js

$(OUT)/monarch.fim: $(IMAGE) | $(OUT)
	cp "$(IMAGE)" $@

docs/monarch.js: src/main_wasm.c $(APP) $(OUT)/monarch.fim
	$(EMCC) -O2 -std=c99 -o $@ src/main_wasm.c $(APP) --embed-file $(OUT)/monarch.fim@/monarch.fim -s MODULARIZE=1 -s EXPORT_NAME=LordMonarch -s EXPORTED_RUNTIME_METHODS=ccall,cwrap,UTF8ToString,HEAPU8,HEAPU32 -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=web,worker,node

clean:
	rm -f $(OUT)/monarch.exe $(OUT)/monarch_shot.exe docs/monarch.js docs/monarch.wasm

.PHONY: all shots wasm clean
