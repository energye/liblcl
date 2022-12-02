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

//CEF App相关回调函数事件设置 SetCEFCallbackEvent
procedure SetCEFCallbackEvent(AEventName: PChar; AEventData: Pointer); extdecl;
var
  eventName : ustring;
begin
  handleExceptionBegin

  eventName := PCharToUStr(AEventName);

  if eventName = AppEvent_OnContextCreated then
  begin
     GlobalCEFApp.OnContextCreated := GlobalCEFAppEvent_OnContextCreated;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnContextCreated, AEventId);
  end
  else if eventName = AppEvent_OnWebKitInitialized then
  begin
     GlobalCEFApp.OnWebKitInitialized := GlobalCEFAppEvent_OnWebKitInitialized;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnWebKitInitialized, AEventId);
  end
  else if eventName = AppEvent_OnProcessMessageReceived then
  begin
     GlobalCEFApp.OnProcessMessageReceived := GlobalCEFAppEvent_OnProcessMessageReceived;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnProcessMessageReceived, AEventId);
  end
  else if eventName = AppEvent_OnBeforeChildProcessLaunch then
  begin
     GlobalCEFApp.OnBeforeChildProcessLaunch := GlobalCEFAppEvent_OnBeforeChildProcessLaunch;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnBeforeChildProcessLaunch, AEventId);
  end
  else if eventName = AppEvent_OnBrowserDestroyed then
  begin
     GlobalCEFApp.OnBrowserDestroyed := GlobalCEFAppEvent_OnBrowserDestroyed;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnBrowserDestroyed, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadStart then
  begin
     GlobalCEFApp.OnLoadStart := GlobalCEFAppEvent_OnRenderLoadStart;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadStart, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadEnd then
  begin
     GlobalCEFApp.OnLoadEnd := GlobalCEFAppEvent_OnRenderLoadEnd;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadEnd, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadError then
  begin
     GlobalCEFApp.OnLoadError := GlobalCEFAppEvent_OnRenderLoadError;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadError, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadingStateChange then
  begin
     GlobalCEFApp.OnLoadingStateChange := GlobalCEFAppEvent_OnRenderLoadingStateChange;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadingStateChange, AEventId);
  end;

  handleExceptionEnd
end;

//Application.QueueAsyncCall UI主程序异步调用回调指针
procedure SetApplicationQueueAsyncCallFunc(APtr: Pointer); extdecl;
begin
  GApplicationQueueAsyncCallPtr := ApplicationQueueAsyncCallPtr(APtr);
end;


exports
    SetCEFCallbackEvent,
    SetCEFIPCCallbackFunc,
    SetCEFWindowBindCallbackFunc,
    SetApplicationQueueAsyncCallFunc,
    SetCEFCallbackFunc
//结尾
;

