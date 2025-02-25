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

git config --global --add safe.directory /app/liblcl
git fetch

# 分枝不存在不构建
IsExist=`git branch -r --list "origin/$branch"`
if [ "$IsExist" = "" ]; then
  echo "Branch $branch does not exist."
  exit 1
fi

# 检出要编译的分枝
if [ "$branch" != "main" ]; then
  echo "Checkout branch $branch"
  git clean -xdf
  git checkout "origin/$branch"
fi

ls -al
/app/shell/add-package.sh "/app/lazarus"

echo "Build Dynamic library: bm=$bm, ws=$ws branch=$branch zip=$zipFilename ============================================="
/app/lazarus/lazbuild -B --bm="$bm" --ws=$ws --lazarusdir="/app/lazarus" "src/liblcl.lpi"

echo "View liblcl.so ============================================="
objdump -p $HOME/golcl/liblcl.so

echo "ZIP liblcl.so ============================================="
zip -j /app/bins/$zipFilename $HOME/golcl/liblcl.so
rm -rf $HOME/golcl/liblcl.so