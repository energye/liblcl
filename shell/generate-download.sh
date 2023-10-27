#!/usr/bin/env bash

version=$1
fileName=$2

if [ -s "$HOME/golcl/$fileName" ];then
  echo "`date`, ${fileName} exist. "
  exit 0
fi

downloadURL="https://github.com/energye/liblcl/releases/download/version/fileName"
downloadURL=${downloadURL/version/$version}
downloadURL=${downloadURL/fileName/$fileName}

echo "Download URL: $downloadURL"

# save to user home/golcl/
wget -O $HOME/golcl/$fileName $downloadURL