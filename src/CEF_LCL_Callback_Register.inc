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

//Application.QueueAsyncCall UI主程序异步调用回调指针
procedure SetApplicationQueueAsyncCallFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GApplicationQueueAsyncCallPtr := ApplicationQueueAsyncCallPtr(APtr);
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnContextCreated
procedure CEFGlobalApp_SetOnContextCreated(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnContextCreated_DataPtr := AEventData;
  GlobalCEFApp.OnContextCreated := GlobalCEFApp_OnContextCreated;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnWebKitInitialized
procedure CEFGlobalApp_SetOnWebKitInitialized(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnWebKitInitialized_DataPtr := AEventData;
  GlobalCEFApp.OnWebKitInitialized := GlobalCEFApp_OnWebKitInitialized;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnWebKitInitialized
procedure CEFGlobalApp_SetOnProcessMessageReceived(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnProcessMessageReceived_DataPtr := AEventData;
  GlobalCEFApp.OnProcessMessageReceived := GlobalCEFApp_OnProcessMessageReceived;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnBeforeChildProcessLaunch
procedure CEFGlobalApp_SetOnBeforeChildProcessLaunch(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnBeforeChildProcessLaunch_DataPtr := AEventData;
  GlobalCEFApp.OnBeforeChildProcessLaunch := GlobalCEFApp_OnBeforeChildProcessLaunch;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnBrowserDestroyed
procedure CEFGlobalApp_SetOnBrowserDestroyed(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnBrowserDestroyed_DataPtr := AEventData;
  GlobalCEFApp.OnBrowserDestroyed := GlobalCEFApp_OnBrowserDestroyed;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnRenderLoadStart
procedure CEFGlobalApp_SetOnRenderLoadStart(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnRenderLoadStart_DataPtr := AEventData;
  GlobalCEFApp.OnLoadStart := GlobalCEFApp_OnRenderLoadStart;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnRenderLoadEnd
procedure CEFGlobalApp_SetOnRenderLoadEnd(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnRenderLoadEnd_DataPtr := AEventData;
  GlobalCEFApp.OnLoadEnd := GlobalCEFApp_OnRenderLoadEnd;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnRenderLoadError
procedure CEFGlobalApp_SetOnRenderLoadError(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnRenderLoadError_DataPtr := AEventData;
  GlobalCEFApp.OnLoadError := GlobalCEFApp_OnRenderLoadError;
  handleExceptionEnd
end;

//EVENT_TYPE:GlobalCEFAppEventOnRenderLoadingStateChange
procedure CEFGlobalApp_SetOnRenderLoadingStateChange(AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  OnRenderLoadingStateChange_DataPtr := AEventData;
  GlobalCEFApp.OnLoadingStateChange := GlobalCEFApp_OnRenderLoadingStateChange;
  handleExceptionEnd
end;

exports
    SetCEFIPCCallbackFunc,
    SetCEFWindowBindCallbackFunc,
    SetApplicationQueueAsyncCallFunc,
    SetCEFCallbackFunc,
    //GlobalCEFApp
    CEFGlobalApp_SetOnContextCreated,
    CEFGlobalApp_SetOnWebKitInitialized,
    CEFGlobalApp_SetOnProcessMessageReceived,
    CEFGlobalApp_SetOnBeforeChildProcessLaunch,
    CEFGlobalApp_SetOnBrowserDestroyed,
    CEFGlobalApp_SetOnRenderLoadStart,
    CEFGlobalApp_SetOnRenderLoadEnd,
    CEFGlobalApp_SetOnRenderLoadError,
    CEFGlobalApp_SetOnRenderLoadingStateChange
//结尾
;

