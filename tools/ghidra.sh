#!/bin/sh
# Decompile PROG.BIN with Ghidra, headless.
#
#   sh tools/ghidra.sh          # -> decomp/all.c, decomp/functions/, index.csv
#
# It analyses the **unpacked** memory image, not disk/PROG.BIN.  Both PROG.BIN
# and PROG.DAT go through the boot sector's LZSS (tools/lmz.py), so handing
# Ghidra the disk copy produces a listing that is real code in patches and
# nonsense in between - those patches are the literal runs of the LZ stream.
# Unpacked, the same run goes from 802 bogus functions to 330 real ones with
# nothing failing to decompile.
#
# tools/image.py assembles the flat image (PROG.DAT at 0x1000, PROG.BIN at
# 0x10000) so that the code lands where it really runs - Ghidra shows it as
# 1000:0000 - and the low-memory data references resolve at the same time.
#
# Ghidra ships its own JDK but analyzeHeadless.bat will not find it on its own.
set -e
cd "$(dirname "$0")/.."

GHIDRA=${GHIDRA:-/c/prog/ghidra/ghidra_12.1.3_PUBLIC}
export JAVA_HOME="${JAVA_HOME:-C:/prog/ghidra/jdk-21.0.12.1+1}"
export PATH="$JAVA_HOME/bin:$PATH"
PYTHON=${PYTHON:-/c/Python313/python}

mkdir -p ghidra_proj decomp
$PYTHON tools/image.py tmp/mem.bin

"$GHIDRA/support/analyzeHeadless.bat" ghidra_proj lm \
  -import tmp/mem.bin -overwrite \
  -processor "x86:LE:16:Real Mode" -loader BinaryLoader -loader-baseAddr 0000:0 \
  -scriptPath tools/ghidra_scripts \
  -preScript SetEntry.java 1000:0000 \
  -postScript DecompileAll.java decomp
