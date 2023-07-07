//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPrintJobCallback_Cont(const AObj: ICefPrintJobCallback); extdecl;
begin
  handleExceptionBegin
  AObj.cont;
  handleExceptionEnd
end;

exports
  CefPrintJobCallback_Cont;