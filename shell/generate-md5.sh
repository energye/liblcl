#!/usr/bin/env bash

echo "Generate MD5 value"

fileName="liblcl.Linux64.zip"
unzip $fileName
mv liblcl.so liblcl.Linux64.so
md5sum liblcl.Linux64.so >> md5.txt

fileName="liblcl.Linux64GTK2.zip"
unzip $fileName
mv liblcl.so liblcl.Linux64GTK2.so
md5sum liblcl.Linux64GTK2.so >> md5.txt

fileName="liblcl.LinuxARM64.zip"
unzip $fileName
mv liblcl.so liblcl.LinuxARM64.so
md5sum liblcl.LinuxARM64.so >> md5.txt

fileName="liblcl.LinuxARM64GTK2.zip"
unzip $fileName
mv liblcl.so liblcl.LinuxARM64GTK2.so
md5sum liblcl.LinuxARM64GTK2.so >> md5.txt

fileName="liblcl.MacOSX64.zip"
unzip $fileName
mv liblcl.dylib liblcl.MacOSX64.dylib
md5sum liblcl.MacOSX64.dylib >> md5.txt

fileName="liblcl.MacOSARM64.zip"
unzip $fileName
mv liblcl.dylib liblcl.MacOSARM64.dylib
md5sum liblcl.MacOSARM64.dylib >> md5.txt

fileName="liblcl.Windows32.zip"
unzip $fileName
mv liblcl.dll liblcl.Windows32.dll
md5sum liblcl.Windows32.dll >> md5.txt

fileName="liblcl.Windows64.zip"
unzip $fileName
mv liblcl.dll liblcl.Windows64.dll
md5sum liblcl.Windows64.dll >> md5.txt

fileName="liblcl-109.Windows32.zip"
unzip $fileName
mv liblcl.dll liblcl-109.Windows32.dll
md5sum liblcl-109.Windows32.dll >> md5.txt

fileName="liblcl-109.Windows64.zip"
unzip $fileName
mv liblcl.dll liblcl-109.Windows64.dll
md5sum liblcl-109.Windows64.dll >> md5.txt

fileName="liblcl-87.Linux64.zip"
unzip $fileName
mv liblcl.so liblcl-87.Linux64.so
md5sum liblcl-87.Linux64.so >> md5.txt

fileName="liblcl-87.LinuxARM64.zip"
unzip $fileName
mv liblcl.so liblcl-87.LinuxARM64.so
md5sum liblcl-87.LinuxARM64.so >> md5.txt

fileName="liblcl-87.MacOSARM64.zip"
unzip $fileName
mv liblcl.dylib liblcl-87.MacOSARM64.dylib
md5sum liblcl-87.MacOSARM64.dylib >> md5.txt

fileName="liblcl-87.MacOSX.zip"
unzip $fileName
mv liblcl.dylib liblcl-87.MacOSX.dylib
md5sum liblcl-87.MacOSX.dylib >> md5.txt

fileName="liblcl-87.Windows32.zip"
unzip $fileName
mv liblcl.dll liblcl-87.Windows32.dll
md5sum liblcl-87.Windows32.dll >> md5.txt

fileName="liblcl-87.Windows64.zip"
unzip $fileName
mv liblcl.dll liblcl-87.Windows64.dll
md5sum liblcl-87.Windows64.dll >> md5.txt