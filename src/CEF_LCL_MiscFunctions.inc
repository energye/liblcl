//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFWindowInfoAsChild(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  //ConsoleLn('CEFWindowInfoAsChild windowParent.Width: ' + IntToStr(windowParent.ClientRect.Width));
  WindowInfoAsChild(windowInfo, windowParent.Handle, windowParent.ClientRect, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

procedure CEFWindowInfoAsPopUp(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  //ConsoleLn('CEFWindowInfoAsPopUp windowParent.Width: ' + IntToStr(windowParent.ClientRect.Width));
  WindowInfoAsPopUp(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
end;
  handleExceptionEnd

procedure CEFWindowInfoAsWindowless(var windowInfo : TCefWindowInfo; windowParent: {$ifdef MSWINDOWS}TCEFWindowParent{$else}TCEFLinkedWindowParent{$endif}; PWindowName: PChar); extdecl;
begin
  handleExceptionBegin
  //ConsoleLn('CEFWindowInfoAsWindowless windowParent.Width: ' + IntToStr(windowParent.ClientRect.Width));
  WindowInfoAsWindowless(windowInfo, windowParent.Handle, PCharToUStr(PWindowName));
  handleExceptionEnd
end;

exports
  CEFWindowInfoAsChild,
  CEFWindowInfoAsPopUp,
  CEFWindowInfoAsWindowless
{end}
;

