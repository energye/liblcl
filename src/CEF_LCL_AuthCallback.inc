//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefAuthCallback_Cont(const TObj: ICefAuthCallback; const username: PChar; const password: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.Cont(PCharToUStr(username), PCharToUStr(password));
  handleExceptionEnd
end;

procedure CefAuthCallback_Cancel(const TObj: ICefAuthCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;

exports
  CefAuthCallback_Cont,
  CefAuthCallback_Cancel;