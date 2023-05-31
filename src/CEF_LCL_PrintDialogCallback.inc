//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefPrintDialogCallback_Cont(const AObj: ICefPrintDialogCallback; const settings: ICefPrintSettings); extdecl;
begin
  handleExceptionBegin
  AObj.cont(settings);
  handleExceptionEnd
end;

procedure CefPrintDialogCallback_Cancel(const AObj: ICefPrintDialogCallback); extdecl;
begin
  handleExceptionBegin
  AObj.cancel;
  handleExceptionEnd
end;

exports
  CefPrintDialogCallback_Cont,
  CefPrintDialogCallback_Cancel
;
