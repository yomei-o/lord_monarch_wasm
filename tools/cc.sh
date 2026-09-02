#!/bin/sh
# A C compiler for the native builds, without needing a developer prompt.
#
# The machine this started on had w64devkit; the one it moved to has Visual
# Studio instead, so the build scripts ask this wrapper for a compiler rather
# than naming one.  Set CC to override.
#
#   sh tools/cc.sh -O2 -Isrc -o out.exe a.c b.c -lgdi32
#
# gcc-style flags in, either compiler out.
set -e
here="$(cd "$(dirname "$0")" && pwd)"

GCC="${CC:-}"
[ -n "$GCC" ] || for c in /c/prog/w64devkit/bin/gcc gcc clang; do
    command -v "$c" >/dev/null 2>&1 && { GCC="$c"; break; }
done
if [ -n "$GCC" ]; then
    exec sh "$here/lowpri.sh" "$GCC" "$@"
fi

# --- MSVC ------------------------------------------------------------------
#
# vcvars is deliberately not used: it hangs when invoked from Git Bash on this
# machine, so cl gets the include and library directories as explicit flags.
# For the same reason cl does NOT go through tools/lowpri.sh - `cmd /c start`
# hangs forever here as soon as it launches an MSVC tool.  Nothing is lost:
# these builds are a handful of files with no parallelism to starve the
# desktop with.
#
# Everything cl is told goes into a response file, one argument per line, so
# that the spaces in "Program Files" survive without a layer of eval quoting.
MSVC="${MSVC_DIR:-C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.31.31103}"
SDK="${WINSDK_DIR:-C:/Program Files (x86)/Windows Kits/10}"
SDKVER="${WINSDK_VER:-10.0.19041.0}"
CL="$MSVC/bin/Hostx64/x64/cl.exe"
[ -f "$CL" ] || { echo "no C compiler: neither gcc/clang on PATH nor $CL" >&2; exit 1; }

# cl resolves a /c/... path as C:\c\..., so every path handed to it is
# converted to the drive-letter form first (cygpath -m keeps forward slashes,
# which cl accepts and which do not escape the closing quote).
w() { cygpath -m "$1" 2>/dev/null || echo "$1"; }

out=
objdir="$here/../tmp/obj"
mkdir -p "$objdir"
rsp="$objdir/cl.rsp"
wobj="$(w "$objdir")"

# -utf-8 is not optional: the sources carry Japanese comments, and without it
# cl reads UTF-8 as Shift-JIS, a trailing byte eats the newline after it, and
# whole lines vanish with errors reported nowhere near the real text.
#
# The header and library directories go in INCLUDE/LIB rather than on the
# command line: -libpath: after -link is ignored when it comes from a response
# file (cl only honours -link when the linker options follow it on the same
# line), and this keeps the response file to just the build's own flags.
INCLUDE="$MSVC/include;$SDK/Include/$SDKVER/ucrt;$SDK/Include/$SDKVER/um;$SDK/Include/$SDKVER/shared"
LIB="$MSVC/lib/x64;$SDK/Lib/$SDKVER/ucrt/x64;$SDK/Lib/$SDKVER/um/x64"
export INCLUDE LIB

{
    echo '-nologo'
    echo '-utf-8'
    echo '-W3'
    echo '-D_CRT_SECURE_NO_WARNINGS'
    echo "-Fo:\"$wobj/\""
} > "$rsp"

srcs=; libs=; subsystem=
while [ $# -gt 0 ]; do
    case "$1" in
    -O2|-O1)      echo '-O2' >> "$rsp" ;;
    -O0)          echo '-Od' >> "$rsp" ;;
    -g)           echo '-Zi' >> "$rsp" ;;
    -Wall|-Wextra) ;;
    -mwindows)    subsystem=1 ;;
    -I*)          echo "-I\"$(w "${1#-I}")\"" >> "$rsp" ;;
    -D*)          echo "-D${1#-D}" >> "$rsp" ;;
    -o)           out="$2"; shift ;;
    -l*)          libs="$libs ${1#-l}.lib" ;;
    -*)           echo "$1" >> "$rsp" ;;
    *)            srcs="$srcs $1"; echo "\"$(w "$1")\"" >> "$rsp" ;;
    esac
    shift
done

# cl puts every object in one directory named after the source's BASENAME, so
# two sources called the same thing in different directories silently clobber
# each other and the link fails with an unresolved symbol that looks nothing
# like the cause.  Say so instead.
dups=$(for f in $srcs; do basename "$f"; done | sort | uniq -d)
[ -z "$dups" ] || {
    echo "two sources share a basename, so their .obj files would collide:" >&2
    echo "$dups" >&2
    exit 1
}

echo "-Fe:\"$(w "$out")\"" >> "$rsp"
# Everything after -link has to sit on one line; see the note above.
link="-link"
for l in $libs; do link="$link $l"; done
[ -z "$subsystem" ] || link="$link -subsystem:windows -entry:WinMainCRTStartup"
echo "$link" >> "$rsp"

export MSYS2_ARG_CONV_EXCL='*' MSYS_NO_PATHCONV=1 VSLANG=1033
exec "$CL" "@$(w "$rsp")"
