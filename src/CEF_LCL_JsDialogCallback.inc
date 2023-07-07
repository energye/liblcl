//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefJsDialogCallback_Cont(const AObj: ICefJsDialogCallback; success: LongBool; const userInput: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.cont(success, PCharToUStr(userInput));
  handleExceptionEnd
end;

exports
  CefJsDialogCallback_Cont;