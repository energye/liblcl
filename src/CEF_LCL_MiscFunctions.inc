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

exports
  CEFWindowInfoAsChild,
  CEFWindowInfoAsPopUp,
  CEFWindowInfoAsWindowless
{end}
;

