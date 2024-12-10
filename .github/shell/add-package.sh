#!/usr/bin/env bash

echo "Add Dependency Package"

lazarusBaseDir="lazbuild"
lazarusDIRArgs=""

if [ "$1" != "" ]; then
  lazarusBaseDir=$1/lazbuild
  lazarusDIRArgs="--lazarusdir=$1"
fi

echo "Lazarus DIR: $lazarusBaseDir ============================================="

$lazarusBaseDir $lazarusDIRArgs --add-package-link ./3rd-party/richmemo/richmemopackage.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/richmemo/richmemopackage.lpk
$lazarusBaseDir $lazarusDIRArgs --add-package ./3rd-party/richmemo/ide/richmemo_design.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/richmemo/ide/richmemo_design.lpk

$lazarusBaseDir $lazarusDIRArgs --add-package ./3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk

$lazarusBaseDir $lazarusDIRArgs --add-package-link ./3rd-party/DCPcrypt/dcpcrypt.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/DCPcrypt/dcpcrypt.lpk
$lazarusBaseDir $lazarusDIRArgs --add-package ./3rd-party/DCPcrypt/dcpcrypt_laz.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/DCPcrypt/dcpcrypt_laz.lpk

$lazarusBaseDir $lazarusDIRArgs --add-package ./3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
$lazarusBaseDir $lazarusDIRArgs ./3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
