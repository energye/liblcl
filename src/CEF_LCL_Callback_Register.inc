//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//CEF IPC 事件处理函数
procedure SetCEFIPCCallbackFunc(APtr: Pointer); extdecl;
begin
  GCEFIPCEventCallbackPtr := TCEFIPCEventCallbackPtr(APtr);
end;

//CEF WindowBindFunction 事件回调函数注册
procedure SetCEFWindowBindCallbackFunc(APtr: Pointer); extdecl;
begin
  GCEFWindowBindPtr := TCEFWindowBindPtr(APtr);
end;

//CEF事件回调函数注册
procedure SetCEFCallbackFunc(APtr: Pointer); extdecl;
begin
  GCEFEventCallbackPtr := TCEFEventCallbackPtr(APtr);
end;

exports
    SetCEFIPCCallbackFunc,
    SetCEFWindowBindCallbackFunc,
    SetCEFCallbackFunc
//结尾
;

