//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//cef callback
procedure cefCallback_Cont(TObj: ICefCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cont;
  handleExceptionEnd
end;

procedure cefCallback_Cancel(TObj: ICefCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;


exports
  cefCallback_Cont,
  cefCallback_Cancel
;
