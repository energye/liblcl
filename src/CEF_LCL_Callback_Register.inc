//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//IPC事件回调函数注册
procedure SetCEFIPCCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GCEFIPCEventCallbackPtr := TCEFIPCEventCallbackPtr(APtr);
  handleExceptionEnd
end;

//WindowBind事件回调函数注册
procedure SetCEFWindowBindCallbackFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GCEFWindowBindPtr := TCEFWindowBindPtr(APtr);
  handleExceptionEnd
end;


exports
    SetCEFIPCCallbackFunc,
    SetCEFWindowBindCallbackFunc
;

