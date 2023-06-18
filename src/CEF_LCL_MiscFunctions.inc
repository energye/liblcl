//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure Misc_WindowInfoAsChild(var windowInfo : TCefWindowInfo; const windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; const PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

procedure Misc_WindowInfoAsPopUp(var windowInfo : TCefWindowInfo; const windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; const PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsPopUp(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

procedure Misc_WindowInfoAsWindowless(var windowInfo : TCefWindowInfo; const windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; const PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsWindowless(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

function Misc_CefRegisterExtension(const name, code: PChar; const Handler: TV8HandlerRef): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := CefRegisterExtension(PCharToUStr(name), PCharToUStr(code), Handler);
  handleExceptionEnd
end;

function Misc_CheckSubprocessPath(const aSubprocessPath: PChar; var aMissingFiles: PChar) : LongBool; extdecl;
var
  MissingFiles: string;
begin
  handleExceptionBegin
  Result := CheckSubprocessPath(StrPas(aSubprocessPath), MissingFiles);
  aMissingFiles := PChar(MissingFiles);
  handleExceptionEnd
end;

function Misc_CheckLocales(const aLocalesDirPath: PChar; var aMissingFiles: PChar; const aLocalesRequired: PChar) : LongBool; extdecl;
var
  MissingFiles: string;
begin
  handleExceptionBegin
  Result := CheckLocales(StrPas(aLocalesDirPath), MissingFiles, StrPas(aLocalesRequired));
  aMissingFiles := PChar(MissingFiles);
  handleExceptionEnd
end;

function Misc_CheckResources(const aResourcesDirPath: PChar; var aMissingFiles: PChar) : LongBool; extdecl;
var
  MissingFiles: string;
begin
  handleExceptionBegin
  Result := CheckResources(StrPas(aResourcesDirPath), MissingFiles);
  aMissingFiles := PChar(MissingFiles);
  handleExceptionEnd
end;

function Misc_CheckDLLs(const aFrameworkDirPath: PChar; var aMissingFiles: PChar) : LongBool; extdecl;
var
  MissingFiles: string;
begin
  handleExceptionBegin
  Result := CheckDLLs(StrPas(aFrameworkDirPath), MissingFiles);
  aMissingFiles := PChar(MissingFiles);
  handleExceptionEnd
end;

function Misc_CefRegisterSchemeHandlerFactory(const SchemeName, DomainName : PChar; const handler: TCefResourceHandlerClass): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := CefRegisterSchemeHandlerFactory(StrPas(SchemeName), StrPas(DomainName), handler);
  handleExceptionEnd
end;

function Misc_CefClearSchemeHandlerFactories : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := CefClearSchemeHandlerFactories();
  handleExceptionEnd
end;

function  Misc_CefGetMimeType(const extension: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(CefGetMimeType(StrPas(extension))));
  handleExceptionEnd
end;

function  Misc_DeviceToLogicalInt32(aValue : integer; const aDeviceScaleFactor : PDouble) : integer; extdecl;
begin
  handleExceptionBegin
  DeviceToLogical(aValue, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

procedure  Misc_DeviceToLogicalFloat32(aValue : PSingle; const aDeviceScaleFactor : PDouble; out Result: Single); extdecl;
begin
  handleExceptionBegin
  Result := DeviceToLogical(Single(aValue^), Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

procedure Misc_DeviceToLogicalMouse(var aEvent : TCEFMouseEvent; const aDeviceScaleFactor : PDouble); extdecl;
begin
  handleExceptionBegin
  DeviceToLogical(aEvent, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

procedure Misc_DeviceToLogicalTouch(var aEvent : TCefTouchEvent; const aDeviceScaleFactor : PDouble); extdecl;
begin
  handleExceptionBegin
  DeviceToLogical(aEvent, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

procedure Misc_DeviceToLogicalPoint(var aPoint : TPoint; const aDeviceScaleFactor : PDouble); extdecl;
begin
  handleExceptionBegin
  DeviceToLogical(aPoint, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

function  Misc_LogicalToDeviceInt32(aValue : integer; const aDeviceScaleFactor : PDouble) : integer; extdecl;
begin
  handleExceptionBegin
  Result := LogicalToDevice(aValue, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

procedure Misc_LogicalToDeviceRect(var aRect : TCEFRect; const aDeviceScaleFactor : PDouble); extdecl;
begin
  handleExceptionBegin
  LogicalToDevice(aRect, Double(aDeviceScaleFactor^));
  handleExceptionEnd
end;

exports
  Misc_WindowInfoAsChild,
  Misc_WindowInfoAsPopUp,
  Misc_WindowInfoAsWindowless,
  Misc_CefRegisterExtension,
  Misc_CheckSubprocessPath,
  Misc_CheckLocales,
  Misc_CheckResources,
  Misc_CheckDLLs,
  Misc_CefRegisterSchemeHandlerFactory,
  Misc_CefClearSchemeHandlerFactories,
  Misc_CefGetMimeType,
  Misc_DeviceToLogicalInt32,
  Misc_DeviceToLogicalFloat32,
  Misc_DeviceToLogicalMouse,
  Misc_DeviceToLogicalTouch,
  Misc_DeviceToLogicalPoint,
  Misc_LogicalToDeviceInt32,
  Misc_LogicalToDeviceRect
;

