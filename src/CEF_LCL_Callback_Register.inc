//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//IPC event callback
procedure SetCEFIPCCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

//WindowBind event callback
procedure SetCEFWindowBindCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;


exports
  SetCEFIPCCallbackFunc,
  SetCEFWindowBindCallbackFunc;