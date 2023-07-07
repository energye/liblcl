//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RunQuickMenuCallback_Cont(const TObj: ICefRunQuickMenuCallback; commandId: Integer; eventFlags: Cardinal); extdecl;
begin
  handleExceptionBegin
  // TCefEventFlags
  TObj.Cont(commandId, TCefEventFlags(eventFlags));
  handleExceptionEnd
end;

procedure RunQuickMenuCallback_Cancel(const TObj: ICefRunQuickMenuCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;


exports
  RunQuickMenuCallback_Cont,
  RunQuickMenuCallback_Cancel;