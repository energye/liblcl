//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_Application;

{$mode objfpc}{$H+}
{$I cef.inc}

{.$DEFINE USE_MULTI_THREAD_LOOP}// Only Windows/Linux
{.$DEFINE USE_APP_HELPER}// Optional on Windows/Linux

{$IFDEF MACOSX}
  {$UNDEF  USE_MULTI_THREAD_LOOP} // Will fail on Mac
  {$DEFINE USE_APP_HELPER}        // Required on Mac
{$ENDIF}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils, Controls, uEventCallback, uCEF_LCL_EventCallback, uCEFSchemeRegistrar, uCEFPreferenceRegistrar,
  uCEFWorkScheduler,
  uCEFInterfaces, uCEFv8Value, uCEFConstants, uCEFTypes,
  uCEF_LCL_Entity, uCEF_LCL_Event;

type

  //应用主进程内执行函数
  TCEFApplicationClass = class
  public
    //应用主进程内执行函数
    procedure ApplicationQueueAsyncCall(Data: PtrInt);
  end;


// 渲染进程回调事件函数
// ICefApp
procedure GlobalCEFApp_OnRegCustomSchemes(const registrar: TCefSchemeRegistrarRef);

// ICefBrowserProcessHandler
procedure GlobalCEFApp_OnRegisterCustomPreferences(type_: TCefPreferencesType; const registrar: TCefPreferenceRegistrarRef);
procedure GlobalCEFApp_OnContextInitialized;
procedure GlobalCEFApp_OnBeforeChildProcessLaunch(const commandLine: ICefCommandLine);
procedure GlobalCEFApp_OnGetDefaultClient(var aClient: ICefClient);

// ICefResourceBundleHandler
procedure GlobalCEFApp_OnGetLocalizedString(stringId: Integer; out stringVal: ustring; var aResult : Boolean);
procedure GlobalCEFApp_OnGetDataResource(resourceId: Integer; out data: Pointer; out dataSize: NativeUInt; var aResult : Boolean);
procedure GlobalCEFApp_OnGetDataResourceForScale(resourceId: Integer; scaleFactor: TCefScaleFactor; out data: Pointer; out dataSize: NativeUInt; var aResult : Boolean);

// ICefRenderProcessHandler
procedure GlobalCEFApp_OnWebKitInitialized;
procedure GlobalCEFApp_OnBrowserCreated(const browser: ICefBrowser; const extra_info: ICefDictionaryValue);
procedure GlobalCEFApp_OnBrowserDestroyed(const browser: ICefBrowser);
procedure GlobalCEFApp_OnContextCreated(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);
procedure GlobalCEFApp_OnContextReleased(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);
procedure GlobalCEFApp_OnUncaughtException(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context; const exception: ICefV8Exception; const stackTrace: ICefV8StackTrace);
procedure GlobalCEFApp_OnFocusedNodeChanged(const browser: ICefBrowser; const frame: ICefFrame; const node: ICefDomNode);
procedure GlobalCEFApp_OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const aMessage: ICefProcessMessage; var aHandled: boolean);

// ICefLoadHandler
procedure GlobalCEFApp_OnRenderLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
procedure GlobalCEFApp_OnRenderLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
procedure GlobalCEFApp_OnRenderLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
procedure GlobalCEFApp_OnRenderLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);

// ScheduleMessagePumpWork
procedure GlobalCEFApp_OnScheduleMessagePumpWork(const aDelayMS: int64);

var
  // 渲染进程回调事件函数指针
  // ICefApp
  OnRegCustomSchemes_DataPtr: Pointer;
  // ICefBrowserProcessHandler

  OnRegisterCustomPreferences_DataPtr: Pointer;
  OnContextInitialized_DataPtr: Pointer;
  OnBeforeChildProcessLaunch_DataPtr: Pointer;
  OnScheduleMessagePumpWork_DataPtr: Pointer;
  OnGetDefaultClient_DataPtr: Pointer;

  // ICefResourceBundleHandler
  OnGetLocalizedString_DataPtr: Pointer;
  OnGetDataResource_DataPtr: Pointer;
  OnGetDataResourceForScale_DataPtr: Pointer;

  // ICefRenderProcessHandler
  OnWebKitInitialized_DataPtr: Pointer;
  OnBrowserCreated_DataPtr: Pointer;
  OnBrowserDestroyed_DataPtr: Pointer;
  OnContextCreated_DataPtr: Pointer;
  OnContextReleased_DataPtr: Pointer;
  OnUncaughtException_DataPtr: Pointer;
  OnFocusedNodeChanged_DataPtr: Pointer;
  OnProcessMessageReceived_DataPtr: Pointer;

  // ICefLoadHandler
  OnRenderLoadingStateChange_DataPtr: Pointer;
  OnRenderLoadStart_DataPtr: Pointer;
  OnRenderLoadEnd_DataPtr: Pointer;
  OnRenderLoadError_DataPtr: Pointer;

{实现}
implementation

//应用主进程内执行函数
procedure TCEFApplicationClass.ApplicationQueueAsyncCall(Data: PtrInt);
begin
  ApplicationQueueAsyncCallEventClass.SendEvent(nativeuint(Data));
end;

// ICefApp
procedure GlobalCEFApp_OnRegCustomSchemes(const registrar: TCefSchemeRegistrarRef);
begin
  TCEFEventCallback.SendEvent(OnRegCustomSchemes_DataPtr, [registrar]);
end;

// ICefBrowserProcessHandler
procedure GlobalCEFApp_OnRegisterCustomPreferences(type_: TCefPreferencesType; const registrar: TCefPreferenceRegistrarRef);
var
  t: integer;
begin
  t := 0;
  if type_ = TCefPreferencesType.CEF_PREFERENCES_TYPE_GLOBAL then
     t := 0
  else if type_ = TCefPreferencesType.CEF_PREFERENCES_TYPE_REQUEST_CONTEXT then
     t := 1;
  TCEFEventCallback.SendEvent(OnRegisterCustomPreferences_DataPtr, [t, registrar]);
end;

procedure GlobalCEFApp_OnContextInitialized;
begin
  TCEFEventCallback.SendEvent(OnContextInitialized_DataPtr, []);
end;

procedure GlobalCEFApp_OnBeforeChildProcessLaunch(const commandLine: ICefCommandLine);
begin
  TCEFEventCallback.SendEvent(OnBeforeChildProcessLaunch_DataPtr, [commandLine]);
end;

procedure GlobalCEFApp_OnGetDefaultClient(var aClient: ICefClient);
begin
  TCEFEventCallback.SendEvent(OnGetDefaultClient_DataPtr, [aClient]);
end;

// ICefResourceBundleHandler
procedure GlobalCEFApp_OnGetLocalizedString(stringId: Integer; out stringVal: ustring; var aResult : Boolean);
var
  result: PChar;
begin
  TCEFEventCallback.SendEvent(OnGetLocalizedString_DataPtr, [stringId, @result, @aResult]);
  stringVal := PCharToUStr(result);
  result := nil;
end;

procedure GlobalCEFApp_OnGetDataResource(resourceId: Integer; out data: Pointer; out dataSize: NativeUInt; var aResult : Boolean);
begin
  TCEFEventCallback.SendEvent(OnGetDataResource_DataPtr, [resourceId, @data, @dataSize, @aResult]);
end;

procedure GlobalCEFApp_OnGetDataResourceForScale(resourceId: Integer; scaleFactor: TCefScaleFactor; out data: Pointer; out dataSize: NativeUInt; var aResult : Boolean);
begin
  TCEFEventCallback.SendEvent(OnGetDataResourceForScale_DataPtr, [resourceId, Integer(scaleFactor), @data, @dataSize, @aResult]);
end;


// ICefRenderProcessHandler
procedure GlobalCEFApp_OnWebKitInitialized;
begin
  TCEFEventCallback.SendEvent(OnWebKitInitialized_DataPtr, []);
end;

procedure GlobalCEFApp_OnBrowserCreated(const browser: ICefBrowser; const extra_info: ICefDictionaryValue);
begin
  TCEFEventCallback.SendEvent(OnBrowserCreated_DataPtr, [browser, extra_info]);
end;

procedure GlobalCEFApp_OnBrowserDestroyed(const browser: ICefBrowser);
begin
  TCEFEventCallback.SendEvent(OnBrowserDestroyed_DataPtr, [browser]);
end;

procedure GlobalCEFApp_OnContextCreated(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);
begin
  TCEFEventCallback.SendEvent(OnContextCreated_DataPtr, [browser, frame, context]);
end;

procedure GlobalCEFApp_OnContextReleased(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);
begin
  TCEFEventCallback.SendEvent(OnContextReleased_DataPtr, [browser, frame, context]);
end;

procedure GlobalCEFApp_OnUncaughtException(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context; const exception: ICefV8Exception; const stackTrace: ICefV8StackTrace);
begin
  TCEFEventCallback.SendEvent(OnUncaughtException_DataPtr, [browser, frame, context, exception, stackTrace]);
end;

procedure GlobalCEFApp_OnFocusedNodeChanged(const browser: ICefBrowser; const frame: ICefFrame; const node: ICefDomNode);
begin
  TCEFEventCallback.SendEvent(OnFocusedNodeChanged_DataPtr, [browser, frame, node]);
end;

procedure GlobalCEFApp_OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const aMessage: ICefProcessMessage; var aHandled: boolean);
begin
  aHandled := False;
  TCEFEventCallback.SendEvent(OnProcessMessageReceived_DataPtr, [browser, frame, sourceProcess, aMessage, @aHandled]);
end;

// ICefLoadHandler
procedure GlobalCEFApp_OnRenderLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  TCEFEventCallback.SendEvent(OnRenderLoadingStateChange_DataPtr, [browser, isLoading, canGoBack, canGoForward]);
end;

procedure GlobalCEFApp_OnRenderLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
begin
  TCEFEventCallback.SendEvent(OnRenderLoadStart_DataPtr, [browser, frame, transitionType]);
end;

procedure GlobalCEFApp_OnRenderLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
begin
  TCEFEventCallback.SendEvent(OnRenderLoadEnd_DataPtr, [browser, frame, httpStatusCode]);
end;

procedure GlobalCEFApp_OnRenderLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
begin
  TCEFEventCallback.SendEvent(OnRenderLoadError_DataPtr, [browser, frame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
end;

// ScheduleMessagePumpWork
procedure GlobalCEFApp_OnScheduleMessagePumpWork(const aDelayMS: int64);
begin
  // callback ptr OnScheduleMessagePumpWork_DataPtr
  if (GlobalCEFWorkScheduler <> nil) then
  begin
    GlobalCEFWorkScheduler.ScheduleMessagePumpWork(aDelayMS);
    if OnScheduleMessagePumpWork_DataPtr <> nil then
       TCEFEventCallback.SendEvent(OnScheduleMessagePumpWork_DataPtr, [aDelayMS]);
  end;
end;

end.
