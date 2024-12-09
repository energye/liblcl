echo "Add Dependency Package"

lazbuild.exe --add-package-link ./src/3rd-party/richmemo/richmemopackage.lpk
lazbuild.exe ./src/3rd-party/richmemo/richmemopackage.lpk
lazbuild.exe --add-package ./src/3rd-party/richmemo/ide/richmemo_design.lpk
lazbuild.exe ./src/3rd-party/richmemo/ide/richmemo_design.lpk

lazbuild.exe --add-package ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk
lazbuild.exe ./src/3rd-party/ATFlatControls/atflatcontrols/atflatcontrols_package.lpk

lazbuild.exe --add-package-link ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
lazbuild.exe ./src/3rd-party/DCPcrypt/dcpcrypt.lpk
lazbuild.exe --add-package ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk
lazbuild.exe ./src/3rd-party/DCPcrypt/dcpcrypt_laz.lpk

lazbuild.exe --add-package ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk
lazbuild.exe ./src/3rd-party/CEF4Delphi/packages/cef4delphi_lazarus.lpk