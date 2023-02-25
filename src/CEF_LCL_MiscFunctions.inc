//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFWindowInfoAsChild(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

procedure CEFWindowInfoAsPopUp(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsPopUp(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

procedure CEFWindowInfoAsWindowless(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  WindowInfoAsWindowless(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

function CEFJSRegisterExtension(const name, code: PChar; const Handler: TV8HandlerRef): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := CefRegisterExtension(PCharToUStr(name), PCharToUStr(code), Handler);
  handleExceptionEnd
end;

function CEFCheckSubprocessPath(const aSubprocessPath: PChar; var aMissingFiles: PChar) : Boolean; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFCheckLocales(const aLocalesDirPath: PChar; var aMissingFiles: PChar; const aLocalesRequired: PChar) : Boolean; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFCheckResources(const aResourcesDirPath: PChar; var aMissingFiles: PChar) : Boolean; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

function CEFCheckDLLs(const aFrameworkDirPath: PChar; var aMissingFiles: PChar) : Boolean; extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

exports
  CEFWindowInfoAsChild,
  CEFWindowInfoAsPopUp,
  CEFWindowInfoAsWindowless,
  CEFJSRegisterExtension
{end}
;

