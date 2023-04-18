//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure RunContextMenuCallback_Cont(const TObj: ICefRunContextMenuCallback; commandId: Integer; eventFlags: Cardinal); extdecl;
begin
  handleExceptionBegin
  // TCefEventFlags
  TObj.Cont(commandId, TCefEventFlags(eventFlags));
  handleExceptionEnd
end;

procedure RunContextMenuCallback_Cancel(const TObj: ICefRunContextMenuCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;


exports
   RunContextMenuCallback_Cont,
   RunContextMenuCallback_Cancel
;
