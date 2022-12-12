//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
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
  SysUtils, Controls, uEventCallback,
  uCEFInterfaces, uCEFv8Value, uCEFConstants, uCEFTypes,
  uCEF_LCL_Entity, uCEF_LCL_Chromium, uCEF_LCL_V8ValueRef,
  uCEF_LCL_V8CommonAccessor, uCEF_LCL_V8CommonHandler,
  uCEF_LCL_V8ObjectAccessor, uCEF_LCL_V8ObjectHandler,
  uCEF_LCL_V8EventEmitHandler, uCEF_LCL_V8EventOnHandler,
  uCEF_LCL_V8WindowMoveDragHandler, uCEF_LCL_BrowserWindowHandler, uCEF_LCL_ContextCreatedJSInject,
  uCEF_LCL_Event, uCEF_LCL_IPC;

type

  //应用主进程内执行函数
  TCEFApplicationClass = class

  public
    //应用主进程内执行函数
    procedure ApplicationQueueAsyncCall(Data: PtrInt);
  end;

procedure SendEvent(DataPtr: Pointer; AArgs: array of const);

// 渲染进程回调事件函数
procedure GlobalCEFApp_OnContextCreated(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);

procedure GlobalCEFApp_OnWebKitInitialized;
procedure GlobalCEFApp_OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const aMessage: ICefProcessMessage; var aHandled: boolean);
procedure GlobalCEFApp_OnBeforeChildProcessLaunch(const commandLine: ICefCommandLine);
procedure GlobalCEFApp_OnBrowserDestroyed(const browser: ICefBrowser);
procedure GlobalCEFApp_OnRenderLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
procedure GlobalCEFApp_OnRenderLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
procedure GlobalCEFApp_OnRenderLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
procedure GlobalCEFApp_OnRenderLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
procedure GlobalCEFApp_OnGetDefaultClient(var aClient: ICefClient);

//绑定处理
procedure ObjectValueBindHandler(const ObjectAccessor: TV8ObjectAccessor; const ObjectHandler: TV8ObjectHandler; const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);
procedure ObjectFieldFuncHandler(const ObjectAccessor: TV8ObjectAccessor; const ObjectHandler: TV8ObjectHandler; const CefObject: PRCefObject; const NewCefObjectBind: PRCEFObjectBind);
procedure CommonValueBindHandler(const CommonAccessor: TV8CommonAccessor; const CommonHandler: TV8CommonHandler; const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);

var
  // 渲染进程回调事件函数指针
  OnRegCustomSchemes_DataPtr: Pointer;
  OnWebKitInitialized_DataPtr: Pointer;
  OnBeforeChildProcessLaunch_DataPtr: Pointer;
  OnScheduleMessagePumpWork_DataPtr: Pointer;
  OnGetDefaultClient_DataPtr: Pointer;
  OnGetLocalizedString_DataPtr: Pointer;
  OnGetDataResource_DataPtr: Pointer;
  OnGetDataResourceForScale_DataPtr: Pointer;
  OnContextCreated_DataPtr: Pointer;
  OnProcessMessageReceived_DataPtr: Pointer;
  OnBrowserDestroyed_DataPtr: Pointer;
  OnRenderLoadStart_DataPtr: Pointer;
  OnRenderLoadEnd_DataPtr: Pointer;
  OnRenderLoadError_DataPtr: Pointer;
  OnRenderLoadingStateChange_DataPtr: Pointer;
  OnBrowserCreated_DataPtr: Pointer;
  OnContextReleased_DataPtr: Pointer;
  OnUncaughtException_DataPtr: Pointer;
  OnFocusedNodeChanged_DataPtr: Pointer;
  OnLoadingStateChange_DataPtr: Pointer;
  OnLoadStart_DataPtr: Pointer;
  OnLoadEnd_DataPtr: Pointer;
  OnLoadError_DataPtr: Pointer;

{实现}
implementation


procedure SendEvent(DataPtr: Pointer; AArgs: array of const);
var
  LParams: array[0..CALL_MAX_PARAM - 1] of Pointer;
  LArgLen: integer;
  LV: TVarRec;
  I: integer;
begin
  if Assigned(GEventCallbackPtr) then
  begin
    LArgLen := Length(AArgs);
    if LArgLen <= Length(LParams) then
    begin
      for I := 0 to LArgLen - 1 do
      begin
        LV := AArgs[I];
        case LV.VType of
          vtInteger: LParams[I] := Pointer(LV.VInteger);
          vtBoolean: LParams[I] := Pointer(byte(LV.VBoolean));
          vtChar: LParams[I] := Pointer(Ord(LV.VChar));
          vtExtended: LParams[I] := LV.VExtended;

          vtString: LParams[I] :=
{$IFDEF MSWINDOWS}
              LV.VString
{$ELSE}LV.VAnsiString{$ENDIF}
            ;

          vtPointer: LParams[I] := LV.VPointer;
          vtPChar: LParams[I] := LV.VPChar;
          vtObject: LParams[I] := LV.VObject;
          vtClass: LParams[I] := LV.VClass;
          vtWideChar: LParams[I] := Pointer(Ord(LV.VWideChar));
          vtPWideChar: LParams[I] := LV.VPWideChar;
          vtAnsiString: LParams[I] := LV.VAnsiString;
          //          vtCurrency      = 12;
          //          vtVariant       = 13;
          vtInterface: LParams[I] := LV.VInterface;
          vtWideString: LParams[I] := LV.VWideString;
          vtInt64: LParams[I] := LV.VInt64;
          vtUnicodeString: LParams[I] := LV.VUnicodeString;
        end;
      end;
      GEventCallbackPtr(DataPtr, @LParams[0], LArgLen);
    end;
  end;
end;

//TCefApplication OnContextCreated
procedure GlobalCEFApp_OnContextCreated(const browser: ICefBrowser; const frame: ICefFrame; const context: ICefv8Context);
var
  v8Context: RCEFV8Context;
  cefFrame: PRCEFFrame;
  FrameName, Frameurl, FrameId: PChar;
  //IPC emit
  IPCObject: ICefv8Value;
  EventEmitHandler: TV8EventEmitHandler;
  //IPC on
  EventOnHandler: TV8EventOnHandler;
  //common
  CommonAccessor: TV8CommonAccessor;
  CommonHandler: TV8CommonHandler;
  //object
  ObjectAccessor: TV8ObjectAccessor;
  ObjectHandler: TV8ObjectHandler;
  //process devtools
  isDevtools: boolean;
  //window move drag
  windowMoveDragHandler: TV8WindowMoveDragHandler;
  WindowDragObject: ICefv8Value;
  //browser window
  browserWindowHandler: TBrowserWindowHandler;
  //js inject
  ContextCreatedJSInject: TContextCreatedJSInjectClass;
  state: boolean; //状态
begin
  //开发者工具不加载绑定变量
  isDevtools := string(frame.Url).IndexOf('devtools://') = 0;
  if isDevtools or (not frame.IsValid) or (not context.IsValid) then
  begin
    exit;
  end;

  FrameName := PChar(UTF8Encode(frame.Name));
  Frameurl := PChar(UTF8Encode(frame.Url));
  FrameId := PChar(IntToStr(frame.Identifier));
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := FrameName;
  cefFrame^.Url := Frameurl;
  cefFrame^.Identifier := FrameId;

  v8Context.Browser := context.Browser;
  v8Context.Global := context.Global;

  TMainChromiumBrowserClass.PutBrowser(browser);
  //事件触发, go 绑定一些js属性和函数
  SendEvent(OnContextCreated_DataPtr, [browser.Identifier, cefFrame, @v8Context, @state]);
  if not state then
  begin
    exit;
  end;

  //js 注入
  ContextCreatedJSInject := TContextCreatedJSInjectClass.Create(browser, frame, context);
  ContextCreatedJSInject.JavaScriptInject();

  //通用类型变量 Accessor
  CommonAccessor := TV8CommonAccessor.Create;
  CommonAccessor.Browser := browser;
  CommonAccessor.Frame := frame;
  CommonAccessor.initState := 0;
  //通用类型变量 Handler
  CommonHandler := TV8CommonHandler.Create;
  CommonHandler.Browser := browser;
  CommonHandler.Frame := frame;

  //结构类型变量 Accessor
  ObjectAccessor := TV8ObjectAccessor.Create;
  ObjectAccessor.RootObjectAccessor := TCefv8ValueRef.NewObject(ObjectAccessor, nil);
  ObjectAccessor.Browser := browser;
  ObjectAccessor.Frame := frame;

  //结构类型变量 Handler
  ObjectHandler := TV8ObjectHandler.Create;
  ObjectHandler.Browser := browser;
  ObjectHandler.Frame := frame;
  ObjectHandler.ObjectAccessor := ObjectAccessor;

  //数据绑定处理
  //ObjectValueBindHandler
  ObjectValueBindHandler(ObjectAccessor, ObjectHandler, browser, frame, context);
  //CommonValueBindHandler
  CommonValueBindHandler(CommonAccessor, CommonHandler, browser, frame, context);

  //IPC class
  TCEFIPCClass.SetCommonAccessor(frame.Identifier, CommonAccessor);
  TCEFIPCClass.SetObjectAccessor(frame.Identifier, ObjectAccessor);

  //注册全局异步执行函数 emit
  EventEmitHandler := TV8EventEmitHandler.Create;
  EventEmitHandler.Browser := browser;
  EventEmitHandler.Frame := frame;
  //注册全局js事件监听
  EventOnHandler := TV8EventOnHandler.Create;
  EventOnHandler.Browser := browser;
  EventOnHandler.Frame := frame;
  //windowMoveDragHandler
  windowMoveDragHandler := TV8WindowMoveDragHandler.Create;
  windowMoveDragHandler.Browser := browser;
  windowMoveDragHandler.Frame := frame;
  windowMoveDragHandler.Init;
  //borwserWindow
  browserWindowHandler := TBrowserWindowHandler.Create;
  browserWindowHandler.Browser := browser;
  browserWindowHandler.Frame := frame;
  browserWindowHandler.BrowserWindowObject := TCefv8ValueRef.NewObject(nil, nil);
  browserWindowHandler.Init();


  IPCObject := TCefv8ValueRef.NewObject(nil, nil);
  IPCObject.SetValueByKey(IPCExecuteName, TCefv8ValueRef.NewFunction(IPCExecuteName, EventEmitHandler), V8_PROPERTY_ATTRIBUTE_READONLY);
  IPCObject.SetValueByKey(IPCEventOnName, TCefv8ValueRef.NewFunction(IPCEventOnName, EventOnHandler), V8_PROPERTY_ATTRIBUTE_READONLY);

  //windowMoveDragHandler
  WindowDragObject := TCefv8ValueRef.NewObject(nil, nil);
  WindowDragObject.SetValueByKey(MoveDragDown, TCefv8ValueRef.NewFunction(MoveDragDown, windowMoveDragHandler), V8_PROPERTY_ATTRIBUTE_READONLY);
  WindowDragObject.SetValueByKey(MoveDragMove, TCefv8ValueRef.NewFunction(MoveDragMove, windowMoveDragHandler), V8_PROPERTY_ATTRIBUTE_READONLY);
  WindowDragObject.SetValueByKey(MoveDragUp, TCefv8ValueRef.NewFunction(MoveDragUp, windowMoveDragHandler), V8_PROPERTY_ATTRIBUTE_READONLY);


  context.Global.SetValueByKey(v8EmitKey, IPCObject, V8_PROPERTY_ATTRIBUTE_READONLY);
  context.Global.SetValueByKey(windowDrag, WindowDragObject, V8_PROPERTY_ATTRIBUTE_READONLY);
  context.Global.SetValueByKey(BrowserWindow, browserWindowHandler.BrowserWindowObject, V8_PROPERTY_ATTRIBUTE_READONLY);

  FrameId := nil;
  FrameName := nil;
  FrameUrl := nil;
  FreePRCEFFrame(cefFrame);
end;

//ObjectValueBindHandler 对象字段处理
procedure ObjectValueBindHandler(const ObjectAccessor: TV8ObjectAccessor; const ObjectHandler: TV8ObjectHandler; const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);
var
  i: integer;
  //object
  CefObject: PRCefObject;
  NewCefObjectBind: PRCEFObjectBind;
  ParentV8Object: PRCEFObjectBind;
begin
  //处理 PRCefObject 对象信息数据，将映射成 js 可调用的对象，包括属性和函数.
  for i := 0 to TObjectValueBindInfoClass.Size() - 1 do
  begin
    //取出每个对象
    CefObject := TObjectValueBindInfoClass.GetCefObjects.Items[i];
    //创建对象CefObject
    NewCefObjectBind := new(PRCEFObjectBind);
    NewCefObjectBind^.Id := CefObject^.Id;
    NewCefObjectBind^.ParentId := CefObject^.ParentId;
    NewCefObjectBind^.Name := CefObject^.Name;
    NewCefObjectBind^.CefV8ValueField := TCefv8ValueRef.NewObject(ObjectAccessor, nil);
    //对象类型
    NewCefObjectBind^.Fields := FieldBindInfoMap.Create;
    NewCefObjectBind^.Funcs := FieldBindInfoMap.Create;
    NewCefObjectBind^.Children := PCEFObjectBinds(CEFObjectBindMap.Create);
    NewCefObjectBind^.Parent := nil;//根节点的父节点是空
    //ParentId = 0 是根节点
    if integer(CefObject^.ParentId) = 0 then
    begin
      //添加到根节点中
      ObjectAccessor.Put(CefObject^.Name, NewCefObjectBind);
      //处理 field 和 func
      ObjectFieldFuncHandler(ObjectAccessor, ObjectHandler, CefObject, NewCefObjectBind);

      ObjectAccessor.RootObjectAccessor.SetValueByAccessor(CefObject^.Name, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
      ObjectAccessor.RootObjectAccessor.SetValueByKey(CefObject^.Name, NewCefObjectBind^.CefV8ValueField, V8_PROPERTY_ATTRIBUTE_NONE);
      //当前对象以根对象方式添加到查找Map对象中
      ObjectAccessor.PutLookupObjectsMap(CefObject^.Name, 0, NewCefObjectBind, nil, nil);
    end
    else
      //ParentId != 0 是子节点
    begin
      //添加到指定的父节点CefObject中
      ParentV8Object := ObjectAccessor.PutChildrenObject(CefObject^.FullObjName, CefObject^.Name, NewCefObjectBind);
      //添加到父节点的 ICefv8Value 中
      if not (ParentV8Object = nil) then
      begin
        ParentV8Object^.CefV8ValueField.SetValueByAccessor(CefObject^.Name, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
        ParentV8Object^.CefV8ValueField.SetValueByKey(CefObject^.Name, NewCefObjectBind^.CefV8ValueField, V8_PROPERTY_ATTRIBUTE_NONE);
        //处理 field 和 func
        ObjectFieldFuncHandler(ObjectAccessor, ObjectHandler, CefObject, NewCefObjectBind);
        //当前对象以字段对象方式添加到查找Map对象中
        ObjectAccessor.PutLookupObjectsMap(CefObject^.Name, 3, NewCefObjectBind, ParentV8Object, nil);
      end;
    end;
  end;
  //清空TList集合
  //TObjectValueBindInfoClass.Clear();
  context.Global.SetValueByKey(ObjectRootName, ObjectAccessor.RootObjectAccessor, V8_PROPERTY_ATTRIBUTE_NONE);
  ObjectAccessor.initState := 1;
end;

//处理每个对象的 field 和 func
procedure ObjectFieldFuncHandler(const ObjectAccessor: TV8ObjectAccessor; const ObjectHandler: TV8ObjectHandler; const CefObject: PRCefObject; const NewCefObjectBind: PRCEFObjectBind);
var
  idx: integer;
  //对象属性
  Field: PRFieldBindInfo;
  //cef v8 value
  v8Value: ICEFv8Value;
begin
  //处理 field
  for idx := 0 to CefObject^.FieldLen - 1 do
  begin
    //取出每个字段并放到新对象节点中
    Field := PRFieldBindInfo(CefObject^.Fields[idx]);
    NewCefObjectBind^.Fields.AddOrSetData(Field^.Name, Field);
    //根据字段类型创建 ICefv8Value
    case Field^.BindType of
      0://ustring
      begin
        v8Value := TCefv8ValueRef.NewString('');
      end;
      1://integer
      begin
        v8Value := TCefv8ValueRef.NewInt(0);
      end;
      2://double
      begin
        v8Value := TCefv8ValueRef.NewDouble(0.0);
      end;
      3://boolean
      begin
        v8Value := TCefv8ValueRef.NewBool(False);
      end;
      6://Object
      begin
      end;
    end;
    //只对普通类型字段处理
    if Field^.BindType < 4 then
    begin
      NewCefObjectBind^.CefV8ValueField.SetValueByAccessor(Field^.Name, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
      NewCefObjectBind^.CefV8ValueField.SetValueByKey(Field^.Name, v8Value, V8_PROPERTY_ATTRIBUTE_NONE);
      //当前字段添加到查找Map对象中
      ObjectAccessor.PutLookupObjectsMap(Field^.Name, 1, nil, NewCefObjectBind, Field);
    end;
  end;
  //处理 func
  for idx := 0 to integer(CefObject^.FuncLen) - 1 do
  begin
    Field := PRFieldBindInfo(CefObject^.Funcs[idx]);
    NewCefObjectBind^.Funcs.AddOrSetData(Field^.Name, Field);
    //new func ICefv8Value
    v8Value := TCefv8ValueRef.NewFunction(Field^.Name, ObjectHandler);
    //NewCefObjectBind^.CefV8ValueFunc.SetValueByAccessor(Field^.Name, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
    NewCefObjectBind^.CefV8ValueField.SetValueByKey(Field^.Name, v8Value, V8_PROPERTY_ATTRIBUTE_NONE);
    //当前函数添加到查找Map对象中
    ObjectAccessor.PutLookupObjectsMap(Field^.Name, 2, nil, NewCefObjectBind, Field);
  end;
end;

//CommonValueBindHandler 通用类型字段处理
procedure CommonValueBindHandler(const CommonAccessor: TV8CommonAccessor; const CommonHandler: TV8CommonHandler; const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);
var
  v8Value: ICEFv8Value;
  v8Name: ustring;
  commonValueBindInfo: PRFieldBindInfo;
  size: int64;
  idx: integer;
begin
  try
    CommonAccessor.V8Object := TCefv8ValueRef.NewObject(CommonAccessor, nil);
    size := TCommonValueBindInfoClass.Size();
    for idx := 0 to size - 1 do
    begin
      commonValueBindInfo := TCommonValueBindInfoClass.GetCommonValueBindInfos.Items[idx];
      //字段或函数名
      v8Name := StrToUStr(commonValueBindInfo^.Name);
      if commonValueBindInfo^.BindType = 8 then
      begin //函数
        case commonValueBindInfo^.BindType of
          8://function
          begin
            CommonHandler.Put(v8Name, commonValueBindInfo);
            v8Value := TCefv8ValueRef.NewFunction(v8Name, CommonHandler);
            CommonAccessor.V8Object.SetValueByKey(v8Name, v8Value, V8_PROPERTY_ATTRIBUTE_NONE);
          end
          else
        end;
      end
      else if commonValueBindInfo^.BindType < 6 then //变量属性
      begin
        case commonValueBindInfo^.BindType of
          0://ustring
          begin
            v8Value := TCefv8ValueRef.NewString('');
          end;
          1://integer
          begin
            v8Value := TCefv8ValueRef.NewInt(0);
          end;
          2://double
          begin
            v8Value := TCefv8ValueRef.NewDouble(0.0);
          end;
          3://boolean
          begin
            v8Value := TCefv8ValueRef.NewBool(False);
          end;
          4://null
          begin
            v8Value := TCefv8ValueRef.NewNull;
          end;
          5://undefined
          begin
            v8Value := TCefv8ValueRef.NewUndefined;
          end;
          else;
        end;
        CommonAccessor.V8Object.SetValueByAccessor(v8Name, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
        CommonAccessor.V8Object.SetValueByKey(v8Name, v8Value, V8_PROPERTY_ATTRIBUTE_NONE);
      end;
    end;
    context.Global.SetValueByKey(CommonRootName, CommonAccessor.V8Object, V8_PROPERTY_ATTRIBUTE_NONE);
    CommonAccessor.initState := 1;
  except
    on E: Exception do
    begin
    end;
  end;
end;

//TCefApplication OnWebKitInitialized
procedure GlobalCEFApp_OnWebKitInitialized;
begin
  SendEvent(OnWebKitInitialized_DataPtr, []);
end;

//render进程消息
procedure GlobalCEFApp_OnProcessMessageReceived(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId;
  const aMessage: ICefProcessMessage; var aHandled: boolean);
var
  processMessage: PRCEFProcessMessage;
  cefFrame: PRCEFFrame;
  binaryValue: ICefBinaryValue;
  binarySize: integer;
  binaryBuf: TBytes;
begin
  if aMessage.Name = IPC_JSEmitGoRet then//JS执行Go监听事件的返回值消息
  begin
    TCEFIPCClass.Render_JSEmitGoRet(frame, aMessage);
  end
  else if (aMessage.Name = IPC_GoEmitJS) then//Go执行JS监听的事件
  begin
    TCEFIPCClass.RenderProcessReceivedMessage(browser, frame, sourceProcess, aMessage);
  end
  else
  begin
    processMessage := new(PRCEFProcessMessage);
    cefFrame := new(PRCEFFrame);
    cefFrame^.Name := PChar(string(frame.Name));
    cefFrame^.Url := PChar(string(frame.Url));
    cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
    binarySize := aMessage.ArgumentList.GetInt(0);
    binaryValue := aMessage.ArgumentList.GetBinary(2);
    SetLength(binaryBuf, binarySize);
    binaryValue.GetData(@binaryBuf[0], nativeuint(binarySize), 0);
    processMessage^.Name := PChar(string(aMessage.Name));
    processMessage^.Data := @binaryBuf[0];
    processMessage^.DataLen := PInteger(binarySize);
    SendEvent(OnProcessMessageReceived_DataPtr, [browser.Identifier, cefFrame, sourceProcess, processMessage, @aHandled]);
    SetLength(binaryBuf, 0);
    processMessage^.Data := nil;
    processMessage := nil;
    cefFrame := nil;
  end;
  aHandled := True;
end;

//cefApp子进程启动命令行设置
procedure GlobalCEFApp_OnBeforeChildProcessLaunch(const commandLine: ICefCommandLine);
var
  idx: integer;
  commands: PChar;
  commandArray: TStringArray;
  commandItemArray: TStringArray;
begin
  SendEvent(OnBeforeChildProcessLaunch_DataPtr, [@commands]);
  commandArray := string(PCharToUStr(commands)).Split(' ');
  for idx := 0 to length(commandArray) - 1 do
  begin
    commandItemArray := commandArray[idx].Split('=');
    if length(commandItemArray) = 2 then
    begin
      commandLine.AppendSwitchWithValue(commandItemArray[0], commandItemArray[1]);
    end
    else if length(commandItemArray) = 1 then
    begin
      commandLine.AppendArgument(commandItemArray[0]);
    end;
  end;
end;

//browser 消毁事件
procedure GlobalCEFApp_OnBrowserDestroyed(const browser: ICefBrowser);
begin
  SendEvent(OnBrowserDestroyed_DataPtr, [browser.Identifier]);
end;

procedure GlobalCEFApp_OnRenderLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(UTF8Encode(frame.Name));
  cefFrame^.Url := PChar(UTF8Encode(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(OnRenderLoadStart_DataPtr, [browser.Identifier, cefFrame, transitionType]);
  FreePRCEFFrame(cefFrame);
end;

procedure GlobalCEFApp_OnRenderLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(UTF8Encode(frame.Name));
  cefFrame^.Url := PChar(UTF8Encode(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(OnRenderLoadEnd_DataPtr, [browser.Identifier, cefFrame, httpStatusCode]);
  FreePRCEFFrame(cefFrame);
end;

procedure GlobalCEFApp_OnRenderLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
var
  cefFrame: PRCEFFrame;
begin
  cefFrame := new(PRCEFFrame);
  cefFrame^.Name := PChar(UTF8Encode(frame.Name));
  cefFrame^.Url := PChar(UTF8Encode(frame.Url));
  cefFrame^.Identifier := PChar(IntToStr(frame.Identifier));
  SendEvent(OnRenderLoadError_DataPtr, [browser.Identifier, cefFrame, errorCode, PChar(UTF8Encode(errorText)), PChar(UTF8Encode(failedUrl))]);
  FreePRCEFFrame(cefFrame);
end;

procedure GlobalCEFApp_OnRenderLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  SendEvent(OnRenderLoadingStateChange_DataPtr, [browser.Identifier, isLoading, canGoBack, canGoForward]);
end;

procedure GlobalCEFApp_OnGetDefaultClient(var aClient: ICefClient);
begin
  SendEvent(OnGetDefaultClient_DataPtr, [aClient]);
end;

//应用主进程内执行函数
procedure TCEFApplicationClass.ApplicationQueueAsyncCall(Data: PtrInt);
begin
  ApplicationQueueAsyncCallEventClass.SendEvent(nativeuint(Data));
end;

end.
