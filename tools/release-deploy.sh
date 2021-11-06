#!/bin/bash
EXEC_DIR=$(pwd)
RELEASE_ARTIFACT="ED64P-$RELEASE_VERSION.zip"
docker run --rm -v "$EXEC_DIR:/build" altra64-dev make

# make the release dirs
mkdir -p "$EXEC_DIR/release/ED64P" "$EXEC_DIR/release/ED64P/CFG" "$EXEC_DIR/release/ED64P/CHEATS" "$EXEC_DIR/release/ED64P/SDSAVE" "$EXEC_DIR/release/ED64P/WALLPAPER"
cp "$EXEC_DIR/bin/OS64P.v64" "$EXEC_DIR/release/ED64P"
cp "$EXEC_DIR/res/ALT64.INI" "$EXEC_DIR/release/ED64P"
cp "$EXEC_DIR/res/WALLPAPER/bg.bmp" "$EXEC_DIR/release/ED64P/WALLPAPER"

cd "$EXEC_DIR/release"
zip -9 -r $RELEASE_ARTIFACT .