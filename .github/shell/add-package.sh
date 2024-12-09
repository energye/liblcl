#!/usr/bin/env bash

echo "Add Dependency Package"

lazbuild --add-package-link ./src/3rd-party/richmemo/richmemopackage.lpk
lazbuild ./src/3rd-party/richmemo/richmemopackage.lpk
lazbuild --add-package ./src/3rd-party/richmemo/ide/richmemo_design.lpk
lazbuild ./src/3rd-party/richmemo/ide/richmemo_design.lpk

lazbuild --add-package ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk
lazbuild ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk

lazbuild --add-package-link ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
lazbuild ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
lazbuild --add-package ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk
lazbuild ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk

lazbuild --add-package ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
lazbuild ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk