#!/bin/sh
# Render a spread of screens with the native code path, for eyeballing.
# Deliberately no window: the build machine's desktop is in use.
set -e
cd "$(dirname "$0")/.."
IMG=$(ls orig/*.FIM | head -1)
SHOT=tmp/monarch_shot.exe
mkdir -p tmp/shots
"$SHOT" "$IMG" title tmp/shots/title.png
"$SHOT" "$IMG" frame tmp/shots/waku.png  WAKU
"$SHOT" "$IMG" frame tmp/shots/waku2.png WAKU2
for n in 000 005 014 023 040; do
  "$SHOT" "$IMG" map  "B_$n.MAP" "tmp/shots/map$n.png"
  "$SHOT" "$IMG" map  "B_$n.MAP" "tmp/shots/map${n}_16.png" --tile 16
  "$SHOT" "$IMG" game "B_$n.MAP" "tmp/shots/game$n.png"
done
echo "-> tmp/shots/"
