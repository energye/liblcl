#!/usr/bin/env bash

lazarusBaseDir="/app/lazarus"

if [ "$1" != "" ]; then
  lazarusBaseDir=$1
fi

echo "Add Dependency Package, lazarusBaseDir:$lazarusBaseDir"

$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package-link ./src/3rd-party/richmemo/richmemopackage.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/richmemo/richmemopackage.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package ./src/3rd-party/richmemo/ide/richmemo_design.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/richmemo/ide/richmemo_design.lpk

$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk

$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package-link ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk

$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir --add-package ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
$lazarusBaseDir/lazbuild --lazarusdir=$lazarusBaseDir ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk