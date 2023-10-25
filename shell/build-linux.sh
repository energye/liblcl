#!/usr/bin/env bash

branch=$1   # Flash-89.0.18, GTK2-106.1.1, ...
arch=$2     # x64, arm64
ws=""       # gtk2, gtk3
zipName=""  # out zip name
lazarusBaseDir="/app/lazarus"  #lazarusBaseDir

if [ "$3" != "" ]; then
  lazarusBaseDir=$3
fi

# 进入liblcl目录
cd /app/liblcl
git config --global --add safe.directory /app/liblcl
git fetch

if [ "$branch" = "" ]; then
  echo "Need to specify a branch."
  exit 1
fi

# 分枝不存在不构建
IsExist=`git branch -r --list "origin/$branch"`
if [ "$IsExist" = "" ]; then
  echo "Branch $branch does not exist."
  exit 1
fi

# linux: x64或arm64
if [ "$arch" != "x64" ] && [ "$arch" != "arm64" ]; then
  echo "Arch should be x64 or arm64."
  exit 1
fi

# 分枝判断, 固定分枝 gtk2=106, flash=89, 其它为gtk3
if [ "$branch" = "GTK2-106.1.1" ]; then
  ws=gtk2
  if [ "$arch" = "x64" ]; then
    zipName="liblcl.Linux64GTK2.zip"
  elif [ "$arch" = "arm64" ]; then
    zipName="liblcl.LinuxARM64GTK2.zip"
  fi
elif [ "$branch" = "Flash-89.0.18" ]; then
  ws=gtk2
  if [ "$arch" = "x64" ]; then
    zipName="liblcl-87.Linux64.zip"
  fi
else
  ws=gtk3
  if [ "$arch" = "x64" ]; then
    zipName="liblcl.Linux64.zip"
  elif [ "$arch" = "arm64" ]; then
    zipName="liblcl.LinuxARM64.zip"
  fi
fi

# zipName 是空时表示不支持
if [ "$zipName" = "" ]; then
  echo "Current compilation not supported."
  exit 1
fi

# 检出要编译的分枝
echo "Checkout branch $branch"
git checkout "origin/$branch"

# 添加依赖包
./shell/add-package-container.sh $lazarusBaseDir

# 构建liblcl
echo "Build liblcl"
$lazarusBaseDir/lazbuild -B --bm=Linux64 --ws=$ws --lazarusdir=$lazarusBaseDir "src/liblcl.lpi"

# 压缩liblcl.so
echo "Zip liblcl"
zip -j liblclbinary/$zipName $HOME/golcl/liblcl.so