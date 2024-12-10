#!/usr/bin/env bash

# CEF | WK | WK2 | none
bm=$1
# gtk2 | gtk3
ws=$2
# branch
branch=$3
# zip out filename
zipFilename=$4

echo "Add Package ============================================="

cd /app/liblcl

git clean -xdf
git checkout "origin/$branch"

ls -al
/app/shell/add-package.sh "/app/lazarus"

echo "Build Dynamic library: bm=$bm, ws=$ws ============================================="
/app/lazarus/lazbuild -B --bm="$bm" --ws=$ws --lazarusdir="/app/lazarus" "liblcl.lpi"

echo "View liblcl.so ============================================="
objdump -p $HOME/golcl/liblcl.so

echo "ZIP liblcl.so ============================================="
zip -j /app/bins/$zipFilename $HOME/golcl/liblcl.so
rm -rf $HOME/golcl/liblcl.so