#!/bin/sh
# Run a build at low priority so the rest of the machine stays usable.
#
# A parallel compile here starves the desktop, so every build in this
# repository goes through this.  cmd's `start /LOW` sets the priority class at
# creation and every child the compiler driver spawns inherits it, which is
# both lighter and more reliable than watching for processes and renicing them
# afterwards.  /B keeps it in this console, /WAIT makes it synchronous so the
# exit status is the build's.
#
#   sh tools/lowpri.sh gcc -O2 ... -o out.exe
#
# LOWPRI=BELOWNORMAL picks the gentler class when a build is long enough that
# idle priority would crawl.
set -e
[ $# -gt 0 ] || { echo "usage: lowpri.sh <command>..." >&2; exit 2; }
CLASS="${LOWPRI:-LOW}"
# //c and //B rather than /c and /B: MSYS would otherwise treat them as paths.
exec cmd //c start "//${CLASS}" //B //WAIT "$@"
