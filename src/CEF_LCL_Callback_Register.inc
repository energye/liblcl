//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//IPC event callback
procedure SetCEFIPCCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GCEFIPCEventCallbackPtr := TCEFIPCEventCallbackPtr(APtr);
  handleExceptionEnd
end;

//WindowBind event callback
procedure SetCEFWindowBindCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GCEFWindowBindPtr := TCEFWindowBindPtr(APtr);
  handleExceptionEnd
end;


exports
  SetCEFIPCCallbackFunc,
  SetCEFWindowBindCallbackFunc;