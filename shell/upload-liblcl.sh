#!/usr/bin/env bash

version=$1
token=$2
uploadURL=$3

echo "Upload liblcl, version: $version url: $uploadURL"

baseDir=$(pwd)

mkdir -p $HOME/golcl

fileName="liblcl.Linux64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-106.Linux64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl.LinuxARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-106.LinuxARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl.MacOSX64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl.MacOSARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl.Windows32.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl.Windows64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-109.Windows32.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-109.Windows64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.Linux64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.LinuxARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.MacOSARM64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.MacOSX.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.Windows32.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL

fileName="liblcl-87.Windows64.zip"
./generate-download.sh "$version" "$fileName"
if [ ! -s "$HOME/golcl/$fileName" ];then
  echo "`date`, The ${fileName} size is zero, failed. "
  exit 1
fi
echo "Upload ${HOME}/golcl/${fileName}"
curl -F "liblcl=@${HOME}/golcl/${fileName}" -F "token=${token}"  -F "version=${version}" $uploadURL
