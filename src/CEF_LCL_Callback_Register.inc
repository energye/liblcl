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
     //GlobalCEFApp.OnContextCreated := GlobalCEFAppEvent_OnContextCreated;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnContextCreated, AEventId);
  end
  else if eventName = AppEvent_OnWebKitInitialized then
  begin
     GlobalCEFApp.OnWebKitInitialized := GlobalCEFApp_OnWebKitInitialized;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnWebKitInitialized, AEventId);
  end
  else if eventName = AppEvent_OnProcessMessageReceived then
  begin
     GlobalCEFApp.OnProcessMessageReceived := GlobalCEFApp_OnProcessMessageReceived;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnProcessMessageReceived, AEventId);
  end
  else if eventName = AppEvent_OnBeforeChildProcessLaunch then
  begin
     GlobalCEFApp.OnBeforeChildProcessLaunch := GlobalCEFApp_OnBeforeChildProcessLaunch;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnBeforeChildProcessLaunch, AEventId);
  end
  else if eventName = AppEvent_OnBrowserDestroyed then
  begin
     GlobalCEFApp.OnBrowserDestroyed := GlobalCEFApp_OnBrowserDestroyed;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnBrowserDestroyed, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadStart then
  begin
     GlobalCEFApp.OnLoadStart := GlobalCEFApp_OnRenderLoadStart;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadStart, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadEnd then
  begin
     GlobalCEFApp.OnLoadEnd := GlobalCEFApp_OnRenderLoadEnd;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadEnd, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadError then
  begin
     GlobalCEFApp.OnLoadError := GlobalCEFApp_OnRenderLoadError;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadError, AEventId);
  end
  else if eventName = AppEvent_OnRenderLoadingStateChange then
  begin
     GlobalCEFApp.OnLoadingStateChange := GlobalCEFApp_OnRenderLoadingStateChange;
     //TEventClass.Add(CommonInstance, @GlobalCEFAppEvent_OnRenderLoadingStateChange, AEventId);
  end;

  handleExceptionEnd
end;

//Application.QueueAsyncCall UI主程序异步调用回调指针
procedure SetApplicationQueueAsyncCallFunc(APtr: Pointer); extdecl;
begin
  handleExceptionBegin
  GApplicationQueueAsyncCallPtr := ApplicationQueueAsyncCallPtr(APtr);
  handleExceptionEnd
end;


//EVENT_TYPE:GlobalCEFAppEventOnContextCreated
procedure CEFGlobalApp_SetOnContextCreated(AObj: TCefApplication; AEventData: Pointer); extdecl;
var
  onContextCreatedMethod: TMethod;
begin
  //{$DEFINE EventMethodName := CEFGlobalAppEvent_OnContextCreated}
  //{$DEFINE EventName := OnContextCreated}
  //EventMethodCode

  handleExceptionBegin

  ConsoleLn('CEFGlobalApp_SetOnContextCreated: ' + IntToStr(int64(AEventData)));
  onContextCreatedMethod.Code := @AObj.OnContextCreated;
  onContextCreatedMethod.Data := @Pointer(AObj); //self
  ConsoleLn('CEFGlobalApp_SetOnContextCreated 1');

  if AEventData = nil then
  begin
    ConsoleLn('CEFGlobalApp_SetOnContextCreated 2');
    TLCLEvent.Remove(onContextCreatedMethod);
    AObj.OnContextCreated := nil;
    exit;
  end;
  ConsoleLn('CEFGlobalApp_SetOnContextCreated 3');
  if TLCLEvent.CheckAndUpdate(onContextCreatedMethod, AEventData) then
  begin
    ConsoleLn('CEFGlobalApp_SetOnContextCreated 3.1');
    exit;
  end;
  ConsoleLn('CEFGlobalApp_SetOnContextCreated 4');
  TLCLEvent.Create(AEventData);
  ConsoleLn('CEFGlobalApp_SetOnContextCreated 5');
  AObj.OnContextCreated := @TLCLEvent.CEFGlobalAppEvent_OnContextCreated;
  ConsoleLn('CEFGlobalApp_SetOnContextCreated 6');
  //GlobalCEFApp.EventName := @Pointer(TLCLEvent.Create(AEventData).EventMethodName)^;

  handleExceptionEnd
end;

exports
    SetCEFCallbackEvent,
    SetCEFIPCCallbackFunc,
    SetCEFWindowBindCallbackFunc,
    SetApplicationQueueAsyncCallFunc,
    SetCEFCallbackFunc,
    //GlobalCEFApp
    CEFGlobalApp_SetOnContextCreated
//结尾
;

