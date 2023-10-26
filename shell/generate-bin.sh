#!/usr/bin/env bash

version=$1
token=$2

echo "Compress and generate binaries, version: $version"

baseDir=$(pwd)

mkdir -p $HOME/golcl

if [ ! -d "liblclbinres" ]; then
  git clone git@github.com:energye/liblclbinres.git
fi

fileName="liblcl.Linux64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.Linux64GTK2.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.LinuxARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.LinuxARM64GTK2.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.MacOSX64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.MacOSARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.Windows32.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl.Windows64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl-109.Windows32.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

fileName="liblcl-109.Windows64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi

cd liblclbinres/genbinres && go run main.go $version

cd ../

git config --local user.email "snxamdf@126.com"
git config --local user.name "yanghy"

git config --local --add safe.directory ./
git add .
git commit -m "Upgrade-version:${version}"
git push git@github.com:energye/liblclbinres.git main
#git tag -a $version -m "Upgrade to $version"