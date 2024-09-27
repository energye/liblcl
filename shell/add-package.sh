#!/usr/bin/env bash

echo "Add Dependency Package"

sudo lazbuild --add-package-link ./src/3rd-party/richmemo/richmemopackage.lpk
sudo lazbuild ./src/3rd-party/richmemo/richmemopackage.lpk
sudo lazbuild --add-package ./src/3rd-party/richmemo/ide/richmemo_design.lpk
sudo lazbuild ./src/3rd-party/richmemo/ide/richmemo_design.lpk

sudo lazbuild --add-package ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk
sudo lazbuild ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk

sudo lazbuild --add-package-link ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
sudo lazbuild ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
sudo lazbuild --add-package ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk
sudo lazbuild ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk

sudo lazbuild --add-package ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
sudo lazbuild ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk