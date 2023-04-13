//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_IPC;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  Classes, SysUtils, fgl, SyncObjs,
  uCEFTypes, uCEFInterfaces, uCEFProcessMessage, uCEFv8Value, uCEFv8Context,
  uCEF_LCL_Entity, uCEF_LCL_Event;

const
  IPC_FN_TYPE_IPCJSEmitGo = 1;
  IPC_FN_TYPE_IPCGoEmitJSRet = 2;

type

  RIPCEventParam = record
    BrowserId: integer;
    IPCId: integer;
    FullName: PChar;
    FrameId: PChar;
    ParamType: integer;
    ValueTypeArrLen: integer;
    ValueTypeArr: array of byte;
  end;

type

  {
   Render IPC 变量Get和函数执行时用到的全局回调函数调用
   用于返回 Get 变量的值，和执行函数的返回值
   Get和执行函数都是Go中的绑定变量
   适用于异步取值操作
  }
  PRGlobalCallback = ^RGlobalCallback;

  RGlobalCallback = record
    GlobalCallbackFunc: ICefv8Value;
    GlobalCallbackContext: ICefv8Context;
  end;
  TPREmitCallbackMap = specialize TFPGMap<int64, PRGlobalCallback>;
  TPROnCallbackMap = specialize TFPGMap<ustring, PRGlobalCallback>;
  TV8ObjectAccessorMap = specialize TFPGMap<int64, TV8ObjectAccessor>;
  TV8CommonAccessorMap = specialize TFPGMap<int64, TV8CommonAccessor>;

  //进程IPC处理类
  TCEFIPCClass = class
  private
  class var
    ObjectAccessors: TV8ObjectAccessorMap;
    CommonAccessors: TV8CommonAccessorMap;
    emitMutex: TCriticalSection;
    onMutex: TCriticalSection;
    TPREmitCallbacks: TPREmitCallbackMap;
    TPROnCallbacks: TPROnCallbackMap;
    IPC_ID: integer;
    WindowMoveDrag: TIPCWindowMoveDrag;
  public
    class constructor Create;
    class destructor Destroy;
    //browser
    class function BrowserProcessReceivedMessage(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage): boolean;
    //render
    //渲染进程 js 触发 go on事件
    class function RenderProcessJSEmitGoOn(browserId: integer; const Frame: ICefFrame; Name: string; paramType: integer; const arguments: TCefv8ValueArray): integer;
    class function RenderProcessReceivedMessage(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage): boolean;
    class function RenderProcessExecuteEmitJS(Name: ustring; const message: ICefProcessMessage): ICefv8Value;
    class function Render_JSEmitGoRet(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
    //Emit Callback
    class procedure PutEmitCallback(Id: integer; const Callback: PRGlobalCallback);
    class function GetEmitCallback(Id: integer): PRGlobalCallback;
    class procedure RemoveEmitCallback(Id: integer);
    class function GetIPCId(): integer;
    //On Callback
    class procedure PutOnCallback(Key: ustring; const Callback: PRGlobalCallback);
    class function GetOnCallback(Key: ustring): PRGlobalCallback;
    class procedure RemoveOnCallback(Key: ustring);

    //accessor
    class procedure SetObjectAccessor(frameId: int64; const accessor: TV8ObjectAccessor);
    class procedure SetCommonAccessor(frameId: int64; const accessor: TV8CommonAccessor);
    class function GetObjectAccessor(frameId: int64): TV8ObjectAccessor;
    class function GetCommonAccessor(frameId: int64): TV8CommonAccessor;
  protected
    //borwser进程处理js emit go on
    class function Browser_JSEmitGo(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
    class function Browser_GoEmitJSRet(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
    class function Render_GoEmitJS(const frame: ICefFrame; const message: ICefProcessMessage): boolean;

  end;

var
  //go执行js ON的事件
  IPC_GoEmitJS: ustring = 'IPCGoEmitJS';
  //go执行js ON的事件-返回
  IPC_GoEmitJSRet: ustring = 'IPCGoEmitJSRet';
  //js执行Go ON的事件
  IPC_JSEmitGo: ustring = 'IPCJSEmitGo';
  //js执行Go ON的事件-返回
  IPC_JSEmitGoRet: ustring = 'IPCJSEmitGoRet';
  // go/js emit accIdx
  accIdx: integer = 5;

implementation

//borwser进程处理js emit go on
class function TCEFIPCClass.Browser_JSEmitGo(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
var
  IPCEventParam: RIPCEventParam;
  argsItem: ICefValue;
  argsItemValueType: TCefValueType;
  idx: integer;
  argsArray: array of TVarRec;
  tempArrayDouble: array of double;
  //IPC_FieldMessage
  browserId, IPCId: integer;
  FullName: ustring;
  ParamType, ArgsArrayLength: integer;
  bIdx: integer = 2;
  //out 出参
  ret: PGoResult;
  outMessage: ICefProcessMessage;
begin
  //得到消息参数
  browserId := message.ArgumentList.GetInt(0);
  IPCId := message.ArgumentList.GetInt(1);
  FullName := message.ArgumentList.GetString(2);
  ParamType := message.ArgumentList.GetInt(3);
  ArgsArrayLength := message.ArgumentList.GetInt(4);
  //调用Go函数参数
  IPCEventParam.BrowserId := browserId;
  IPCEventParam.IPCId := IPCId;
  IPCEventParam.FullName := PChar(string(FullName));
  IPCEventParam.ParamType := ParamType;
  IPCEventParam.FrameId := PChar(IntToStr(frame.Identifier));
  IPCEventParam.ValueTypeArrLen := ArgsArrayLength;
  try
    SetLength(argsArray, IPCEventParam.ValueTypeArrLen + bIdx);
    if IPCEventParam.ValueTypeArrLen > 0 then
    begin
      SetLength(IPCEventParam.ValueTypeArr, IPCEventParam.ValueTypeArrLen);
      SetLength(tempArrayDouble, IPCEventParam.ValueTypeArrLen);
    end;
    //拿到参数
    for idx := 0 to IPCEventParam.ValueTypeArrLen - 1 do
    begin
      argsItem := message.ArgumentList.GetValue(idx + accIdx);
      argsItemValueType := argsItem.GetType;
      if argsItemValueType = VTYPE_STRING then
      begin
        IPCEventParam.ValueTypeArr[idx] := 0;
        argsArray[idx + bIdx].VPChar := PChar(string(argsItem.GetString));
        argsArray[idx + bIdx].VType := vtPChar;
      end
      else if argsItemValueType = VTYPE_INT then
      begin
        IPCEventParam.ValueTypeArr[idx] := 1;
        argsArray[idx + bIdx].VInteger := argsItem.GetInt;
        argsArray[idx + bIdx].VType := vtInteger;
      end
      else if argsItemValueType = VTYPE_DOUBLE then
      begin
        IPCEventParam.ValueTypeArr[idx] := 2;
        tempArrayDouble[idx] := argsItem.GetDouble;
        argsArray[idx + bIdx].VPointer := @tempArrayDouble[idx];
        argsArray[idx + bIdx].VType := vtPointer;
      end
      else if argsItemValueType = VTYPE_BOOL then
      begin
        IPCEventParam.ValueTypeArr[idx] := 3;
        argsArray[idx + bIdx].VBoolean := argsItem.GetBool;
        argsArray[idx + bIdx].VType := vtBoolean;
      end
      else
      begin
        Result := True;
        exit;//类型不正确直接跳出返回
      end;
    end;
    //new result pointer
    ret := new(PGoResult);
    ret^.Value := new(Pointer);
    ret^.ValueType := new(PInteger);
    ret^.ValueLength := new(PInteger);
    ret^.BindType := new(PInteger);
    ret^.Exception := new(PInteger);
    argsArray[0].VPointer := @IPCEventParam;
    argsArray[0].VType := vtPointer;
    argsArray[1].VPointer := ret;
    argsArray[1].VType := vtPointer;

    //in event
    TIPCEventClass.SendEvent(nativeuint(IPC_FN_TYPE_IPCJSEmitGo), argsArray);
    //emit 参数类型 > 2 有回调，组装消息发回给渲染进程
    if ParamType > 2 then
    begin
      //out result
      outMessage := TCefProcessMessageRef.New(IPC_JSEmitGoRet);
      outMessage.ArgumentList.SetInt(0, IPCId);
      outMessage.ArgumentList.SetInt(1, integer(ret^.Exception));//Exception
      outMessage.ArgumentList.SetInt(2, integer(ret^.BindType));//bindType
      outMessage.ArgumentList.SetInt(3, integer(ret^.ValueType));//vType
      if integer(ret^.Exception) = 0 then
      begin
        case integer(ret^.ValueType) of
          0: //ret string
            outMessage.ArgumentList.SetString(4, StrToUStr(string(PChar(ret^.Value))));
          1: //ret int
            outMessage.ArgumentList.SetInt(4, integer(PInteger(ret^.Value)));
          2: //ret double
            outMessage.ArgumentList.SetDouble(4, (PDouble(ret^.Value))^);
          3: //ret boolean
            outMessage.ArgumentList.SetBool(4, boolean(PBoolean(ret^.Value)));
          6, 10:// ret object, value = full name
            outMessage.ArgumentList.SetString(4, StrToUStr(string(PChar(ret^.Value))));
        end;
      end
      else//exception > 0
      begin
        outMessage.ArgumentList.SetString(4, StrToUStr(string(PChar(ret^.Value))));
      end;
      //发送返回消息
      frame.SendProcessMessage(PID_RENDERER, outMessage);
    end;
  finally
    SetLength(IPCEventParam.ValueTypeArr, 0);
    FreeArrayTVarRec(argsArray);
    SetLength(tempArrayDouble, 0);
    SetLength(argsArray, 0);
    IPCEventParam.FullName := nil;
    ret^.Value := nil;
    ret^.ValueType := nil;
    ret^.ValueLength := nil;
    ret^.BindType := nil;
    ret^.Exception := nil;
    ret := nil;
  end;

  Result := True;
end;

class function TCEFIPCClass.Render_GoEmitJS(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
var
  //出参
  processMessage: ICefProcessMessage;
  returnValue: ICefv8Value;
  //入参
  goExecType: integer;//goExecType 是在go中调用时执行类型 0:异步 1:异步-带回调函数返回结果 2:同步-阻塞等待结果返回值
  IPCID: integer;
  onName: ustring;
  arguments: TCefv8ValueArray;
  onCallback: PRGlobalCallback;
  argsLen: int64;
  //binary
  binaryValue: ICefBinaryValue;
  binarySize: integer;
  binaryBuf: array of byte;
  argumentList: TArgumentList;
  dataItems: TDataItems;
  dataItem: TDataItem;
  idx, itemLength: integer;
begin
  try
    binarySize := message.ArgumentList.GetInt(0);
    itemLength := message.ArgumentList.GetInt(1);
    binaryValue := message.ArgumentList.GetBinary(2);
    SetLength(binaryBuf, binarySize);
    binaryValue.GetData(@binaryBuf[0], nativeuint(binarySize), 0);
    argumentList := TArgumentList.Create;
    argumentList.UnPackage(itemLength, binaryBuf, 0);//解包
    dataItems := argumentList.DataItems();
    argsLen := Length(dataItems);
    //取值，0~len-3 是入参，最后三个是固定参数用于判断使用
    goExecType := dataItems[argsLen - 3].GetInt();
    IPCID := dataItems[argsLen - 2].GetInt();
    onName := dataItems[argsLen - 1].GetString();
    onCallback := GetOnCallback(onName);
    if goExecType > 0 then
    begin
      {
       message 参数说明
               0:IPCId
               1:goExecType
               2:错误码(0:成功 1:不支持的参数返回值 2:事件未注册)
               3:返回值类型(V8_JS_VALUE_TYPE)
               4:返回值
      }
      processMessage := TCefProcessMessageRef.New(IPC_GoEmitJSRet);
      processMessage.ArgumentList.SetInt(0, IPCID);
      processMessage.ArgumentList.SetInt(1, goExecType);
      processMessage.ArgumentList.SetInt(2, 0);//错误状态码 成功
    end;
    if not (onCallback = nil) then
    begin
      //取入参 从0取到减3个参数下标
      argsLen := argsLen - 3;
      SetLength(arguments, argsLen);
      for idx := 0 to argsLen - 1 do
      begin
        dataItem := dataItems[idx];
        if dataItem.IsString() then
        begin
          arguments[idx] := TCefv8ValueRef.NewString(UTF8Decode(dataItem.GetString()));
        end
        else if dataItem.IsInt() then
        begin
          arguments[idx] := TCefv8ValueRef.NewInt(dataItem.GetInt());
        end
        else if dataItem.IsDouble() then
        begin
          arguments[idx] := TCefv8ValueRef.NewDouble(dataItem.GetDouble());
        end
        else if dataItem.IsBoolean() then
        begin
          arguments[idx] := TCefv8ValueRef.NewBool(dataItem.GetBoolean());
        end
        else;
      end;

      //执行js on回调
      returnValue := onCallback^.GlobalCallbackFunc.ExecuteFunctionWithContext(onCallback^.GlobalCallbackContext, nil, arguments);
      if (not (returnValue = nil)) and (returnValue.IsValid) and (goExecType > 0) then
      begin
        if returnValue.IsString then
        begin
          processMessage.ArgumentList.SetInt(3, 0);//返回值类型
          processMessage.ArgumentList.SetString(4, returnValue.GetStringValue);//返回的参数
        end
        else if returnValue.IsInt then
        begin
          processMessage.ArgumentList.SetInt(3, 1);//返回值类型
          processMessage.ArgumentList.SetInt(4, returnValue.GetIntValue);//返回的参数
        end
        else if returnValue.IsDouble then
        begin
          processMessage.ArgumentList.SetInt(3, 2);//返回值类型
          processMessage.ArgumentList.SetDouble(4, returnValue.GetDoubleValue);//返回的参数
        end
        else if returnValue.IsBool then
        begin
          processMessage.ArgumentList.SetInt(3, 3);//返回值类型
          processMessage.ArgumentList.SetBool(4, returnValue.GetBoolValue);//返回的参数
        end
        else //不支持的参数返回值
        begin
          processMessage.ArgumentList.SetInt(2, 1);//错误状态码 不支持的参数返回类型
          processMessage.ArgumentList.SetInt(3, 0);//返回值类型
          processMessage.ArgumentList.SetString(4, onName + StrToUStr(', unsupported parameter return type.'));//返回的参数
        end;
      end;
    end
    else
    begin
      if goExecType > 0 then
      begin
        processMessage.ArgumentList.SetInt(2, 2);//错误状态码 事件未注册
        processMessage.ArgumentList.SetInt(3, 0);//类型
        processMessage.ArgumentList.SetString(4, onName + StrToUStr(', events are not registered.'));//返回的参数
      end;
    end;
    if goExecType > 0 then
    begin
      frame.SendProcessMessage(PID_BROWSER, processMessage);
      processMessage.ArgumentList.Clear;
    end;
  finally
    SetLength(arguments, 0);
    SetLength(binaryBuf, 0);
    processMessage := nil;
  end;
  Result := True;
end;

//browser接收进程消息 来自 <= render
class function TCEFIPCClass.BrowserProcessReceivedMessage(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage): boolean;
var
  ret: boolean;
  Name: ustring;
begin
  Name := message.Name;
  if WindowMoveDrag.Execute(Name, message) then
  begin //js中窗口移动消息
    ret := True;
  end
  else if Name = IPC_JSEmitGo then
  begin//js 执行 Go
    ret := Browser_JSEmitGo(frame, message);
  end
  else if Name = IPC_GoEmitJSRet then
  begin //Go执行emit js返回
    ret := Browser_GoEmitJSRet(frame, message);
  end
  else
  begin
    ret := False;
  end;
  Result := ret;
end;


//render进程 js 触发 go on事件
class function TCEFIPCClass.RenderProcessJSEmitGoOn(browserId: integer; const Frame: ICefFrame; Name: string; paramType: integer;
  const arguments: TCefv8ValueArray): integer;
var
  v8Value: ICefv8Value;
  idx, arrayLength: integer;
  processMessage: ICefProcessMessage;
  Callback: PRGlobalCallback;
  IPCId: integer;
begin
  processMessage := TCefProcessMessageRef.New(IPC_JSEmitGo);
  processMessage.ArgumentList.SetInt(0, browserId);//browserId
  processMessage.ArgumentList.SetInt(1, 0);//IPCId
  processMessage.ArgumentList.SetString(2, StrToUStr(Name));//FullName
  processMessage.ArgumentList.SetInt(3, paramType);//paramType
  try
    //2 或 4有参数
    if (paramType = 2) or (paramType = 4) then
    begin
      arrayLength := arguments[1].GetArrayLength;
    end
    else
    begin
      arrayLength := 0;
    end;
    processMessage.ArgumentList.SetInt(4, arrayLength);//ArgsArrayLength

    //拿到参数
    for idx := 0 to arrayLength - 1 do
    begin
      v8Value := arguments[1].GetValueByIndex(idx);
      if v8Value.IsString then
      begin
        processMessage.ArgumentList.SetString(idx + accIdx, v8Value.GetStringValue);
      end
      else if v8Value.IsInt then
      begin
        processMessage.ArgumentList.SetInt(idx + accIdx, v8Value.GetIntValue);
      end
      else if v8Value.IsDouble then
      begin
        processMessage.ArgumentList.SetDouble(idx + accIdx, v8Value.GetDoubleValue);
      end
      else if v8Value.IsBool then
      begin
        processMessage.ArgumentList.SetBool(idx + accIdx, v8Value.GetBoolValue);
      end
      else
      begin
        Result := -1;//类型不正确直接跳出返回
        exit;
      end;
    end;
    if (paramType > 2) then// > 2有回调 3和4是有回调的
    begin
      IPCId := TCEFIPCClass.GetIPCId();
      processMessage.ArgumentList.SetInt(1, IPCId);//IPCId
      //创建回调对象 这个map非常影响性能
      Callback := new(PRGlobalCallback);
      Callback^.GlobalCallbackContext := TCefv8ContextRef.Current;
      Callback^.GlobalCallbackFunc := arguments[paramType - 2];//回调函数所在的下标位置-2正好在第1个或第2个位置
      //添加到回调处理类
      TCEFIPCClass.PutEmitCallback(IPCId, Callback);
    end;
    //给browser进程发送消息
    Frame.SendProcessMessage(PID_BROWSER, processMessage);
  finally
    processMessage.ArgumentList.Clear;
    processMessage := nil;
    v8Value := nil;
  end;
  Result := 1;
end;

//处理 go emit js 事件的返回值
class function TCEFIPCClass.Browser_GoEmitJSRet(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
var
  IPCId: int64;
  goExecType, ValueType, Exception: integer;
  Value: ICefValue;
  //out 出参
  ret: PGoResult;
  eventArgsArray: array of TVarRec;
  retString: PChar;
  retInteger: integer;
  retDouble: double;
  retBoolean: boolean;
begin
  {
   message 参数说明
           0:IPCId
           1:goExecType
           2:错误码(0:成功 1:不支持的参数返回值 2:事件未注册)
           3:返回值类型(V8_JS_VALUE_TYPE)
           4:返回值
  }
  IPCId := message.ArgumentList.GetInt(0);
  goExecType := message.ArgumentList.GetInt(1);
  Exception := message.ArgumentList.GetInt(2);
  ValueType := message.ArgumentList.GetInt(3);
  Value := message.ArgumentList.GetValue(4);
  try
    ret := new(PGoResult);
    ret^.Value := new(Pointer);
    ret^.Exception := PInteger(Exception);
    ret^.ValueLength := PInteger(0);
    ret^.BindType := PInteger(0);
    SetLength(eventArgsArray, 3);
    if Value.GetType = VTYPE_STRING then
    begin
      ret^.ValueType := PInteger(0);
      ret^.Value := PChar(string(Value.GetString));
    end
    else if Value.GetType = VTYPE_INT then
    begin
      ret^.ValueType := PInteger(1);
      ret^.Value := Pinteger(Value.GetInt);
    end
    else if Value.GetType = VTYPE_DOUBLE then
    begin
      retDouble := Value.GetDouble;
      ret^.ValueType := PInteger(2);
      ret^.Value := @retDouble;
    end
    else if Value.GetType = VTYPE_BOOL then
    begin
      retBoolean := Value.GetBool;
      ret^.ValueType := PInteger(3);
      ret^.Value := @retBoolean;
    end;
    eventArgsArray[0].VPointer := @IPCId;
    eventArgsArray[0].VType := vtPointer;
    eventArgsArray[1].VPointer := @goExecType;
    eventArgsArray[1].VType := vtPointer;
    eventArgsArray[2].VPointer := ret;
    eventArgsArray[2].VType := vtPointer;
    TIPCEventClass.SendEvent(nativeuint(IPC_FN_TYPE_IPCGoEmitJSRet), eventArgsArray);
  finally
    SetLength(eventArgsArray, 0);
    ret^.Value := nil;
    ret^.ValueType := nil;
    ret^.Exception := nil;
    ret^.ValueLength := nil;
    ret^.BindType := nil;
    ret := nil;
  end;
  Result := True;
end;

//处理js emit go 事件的返回值
class function TCEFIPCClass.Render_JSEmitGoRet(const frame: ICefFrame; const message: ICefProcessMessage): boolean;
var
  FullNameArray: TStringArray;
  CallFnArgs: TCefv8ValueArray;
  Callback: PRGlobalCallback;
  RetObjectBind: PRCEFObjectBind;
  IPCId: integer;
  FullName: ustring;
  BindType, ValueType, Exception: integer;
begin
  IPCId := message.ArgumentList.GetInt(0);
  Exception := message.ArgumentList.GetInt(1);//Exception
  BindType := message.ArgumentList.GetInt(2);//bindType
  ValueType := message.ArgumentList.GetInt(3);//vType
  Callback := GetEmitCallback(IPCID);
  if not (Callback = nil) then
  begin
    try
      SetLength(CallFnArgs, 3);
      if Exception = 0 then
      begin
        //数据类型判断
        case ValueType of
          0:
          begin
            CallFnArgs[0] := TCefv8ValueRef.NewString(message.ArgumentList.GetString(4));
          end;
          1:
          begin
            CallFnArgs[0] := TCefv8ValueRef.NewInt(message.ArgumentList.GetInt(4));
          end;
          2:
          begin
            CallFnArgs[0] := TCefv8ValueRef.NewDouble(message.ArgumentList.GetDouble(4));
          end;
          3:
          begin
            CallFnArgs[0] := TCefv8ValueRef.NewBool(message.ArgumentList.GetBool(4));
          end
        end;
        //成功
        CallFnArgs[1] := TCefv8ValueRef.NewBool(True);
        CallFnArgs[2] := TCefv8ValueRef.NewInt(0);
        //对象类型
        if (ValueType = 6) or (ValueType = 10) then//6:object 10:rootObject
        begin
          FullName := message.ArgumentList.GetString(4);//FullName
          if BindType = 0 then//0:commonObject
          begin
            CallFnArgs[0] := TCEFIPCClass.GetCommonAccessor(frame.Identifier).V8Object;
          end
          else if BindType = 1 then//1:object
          begin
            if ValueType = 6 then // 6=子对象
            begin
              CallFnArgs[0] := TCEFIPCClass.GetObjectAccessor(frame.Identifier).RootObjectAccessor;
            end
            else if ValueType = 10 then // 10=根对象
            begin
              FullNameArray := string(FullName).Split('.');
              if (length(FullNameArray) = 1) and (FullName = ObjectRootName) then//根对象
              begin
                CallFnArgs[0] := TCEFIPCClass.GetObjectAccessor(frame.Identifier).RootObjectAccessor;
              end
              else
              begin//遍历出子属性(或对象)
                RetObjectBind := TCEFIPCClass.GetObjectAccessor(frame.Identifier).GetObjectByFullName(FullNameArray);
                if not (RetObjectBind = nil) then
                begin
                  CallFnArgs[0] := RetObjectBind^.CefV8ValueField;
                end;
              end;
              SetLength(FullNameArray, 0);
            end;
          end;
        end;
      end
      else
      begin //失败
        //CallFnArgs[0] := TCefv8ValueRef.NewString(message.ArgumentList.GetString(4) + ', ErrorCode: ' + IntToStr(Exception));
        CallFnArgs[0] := TCefv8ValueRef.NewString(message.ArgumentList.GetString(4));
        CallFnArgs[1] := TCefv8ValueRef.NewBool(False);
        CallFnArgs[2] := TCefv8ValueRef.NewInt(Exception);
      end;
    finally
      if Callback^.GlobalCallbackContext.Enter then
      begin
        Callback^.GlobalCallbackFunc.ExecuteFunctionWithContext(Callback^.GlobalCallbackContext, nil, CallFnArgs);
        Callback^.GlobalCallbackContext.Exit;
      end;
      SetLength(CallFnArgs, 0);
      Callback^.GlobalCallbackFunc := nil;
      Callback^.GlobalCallbackContext := nil;
      RemoveEmitCallback(IPCId);
    end;
  end;
end;


class function TCEFIPCClass.RenderProcessExecuteEmitJS(Name: ustring; const message: ICefProcessMessage): ICefv8Value;
var
  //入参
  argsLen: int64;
  idx: integer;
  valueType: TCefValueType;
  arguments: TCefv8ValueArray;
  onCallback: PRGlobalCallback;
begin
  try
    onCallback := GetOnCallback(Name);
    if not (onCallback = nil) then
    begin
      //取-3个的参数，后3个是固定参数值
      argsLen := message.ArgumentList.GetSize - 3;
      SetLength(arguments, argsLen);
      for idx := 0 to argsLen - 1 do
      begin
        valueType := message.ArgumentList.GetType(idx);
        case valueType of
          VTYPE_STRING:
          begin
            arguments[idx] := TCefv8ValueRef.NewString(message.ArgumentList.GetString(idx));
          end;
          VTYPE_INT:
          begin
            arguments[idx] := TCefv8ValueRef.NewInt(message.ArgumentList.GetInt(idx));
          end;
          VTYPE_DOUBLE:
          begin
            arguments[idx] := TCefv8ValueRef.NewDouble(message.ArgumentList.GetDouble(idx));
          end;
          VTYPE_BOOL:
          begin
            arguments[idx] := TCefv8ValueRef.NewBool(message.ArgumentList.GetBool(idx));
          end;
          else;
        end;
      end;
      Result := onCallback^.GlobalCallbackFunc.ExecuteFunctionWithContext(onCallback^.GlobalCallbackContext, nil, arguments);
      exit;
    end;
  finally
    SetLength(arguments, 0);
  end;
  Result := nil;
end;


//render进程接收消息,来自 <= browser
class function TCEFIPCClass.RenderProcessReceivedMessage(const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message: ICefProcessMessage): boolean;
var
  //出参
  ret: boolean;
begin
  //go执行js on emit
  if message.Name = IPC_GoEmitJS then
  begin
    ret := Render_GoEmitJS(frame, message);
  end;
  Result := ret;
end;

//添加一个回调 GlobalCallback
class procedure TCEFIPCClass.PutEmitCallback(Id: integer; const Callback: PRGlobalCallback);
begin
  try
    emitMutex.Acquire;
    TPREmitCallbacks.AddOrSetData(Id, Callback);
  finally
    emitMutex.Release;
  end;
end;

class function TCEFIPCClass.GetEmitCallback(Id: integer): PRGlobalCallback;
var
  Callback: PRGlobalCallback;
begin
  if TPREmitCallbacks.TryGetData(Id, Callback) then
  begin
    Result := Callback;
    exit;
  end;
  Result := nil;
end;

//移除一个回调 GlobalCallback
class procedure TCEFIPCClass.RemoveEmitCallback(Id: integer);
begin
  try
    emitMutex.Acquire;
    TPREmitCallbacks.Remove(Id);
  finally
    emitMutex.Release;
  end;
end;


class function TCEFIPCClass.GetIPCId(): integer;
begin
  Inc(IPC_ID);
  Result := IPC_ID;
end;


class procedure TCEFIPCClass.PutOnCallback(Key: ustring; const Callback: PRGlobalCallback);
begin
  try
    onMutex.Acquire;
    TPROnCallbacks.AddOrSetData(Key, Callback);
  finally
    onMutex.Release;
  end;
end;

class function TCEFIPCClass.GetOnCallback(Key: ustring): PRGlobalCallback;
var
  Callback: PRGlobalCallback;
begin
  if TPROnCallbacks.TryGetData(Key, Callback) then
  begin
    Result := Callback;
    exit;
  end;
  Result := nil;
end;

class procedure TCEFIPCClass.RemoveOnCallback(Key: ustring);
begin
  try
    onMutex.Acquire;
    TPROnCallbacks.Remove(Key);
  finally
    onMutex.Release;
  end;
end;

class constructor TCEFIPCClass.Create;
begin
  ObjectAccessors := TV8ObjectAccessorMap.Create;
  CommonAccessors := TV8CommonAccessorMap.Create;
  WindowMoveDrag := TIPCWindowMoveDrag.Create;
  TPREmitCallbacks := TPREmitCallbackMap.Create;
  TPROnCallbacks := TPROnCallbackMap.Create;
  emitMutex := TCriticalSection.Create;
  onMutex := TCriticalSection.Create;
  IPC_ID := 0;
end;

class destructor TCEFIPCClass.Destroy;
begin
  ObjectAccessors.Clear;
  ObjectAccessors.Free;
  ObjectAccessors := nil;
  CommonAccessors.Clear;
  CommonAccessors.Free;
  CommonAccessors := nil;
  TPREmitCallbacks.Clear;
  TPREmitCallbacks.Free;
  TPREmitCallbacks := nil;
  TPROnCallbacks.Clear;
  TPROnCallbacks.Free;
  TPROnCallbacks := nil;
  FreeAndNil(emitMutex);
  FreeAndNil(onMutex);
end;

class function TCEFIPCClass.GetObjectAccessor(frameId: int64): TV8ObjectAccessor;
var
  ObjectAccessor: TV8ObjectAccessor;
begin
  if ObjectAccessors.TryGetData(frameId, ObjectAccessor) then
  begin
    Result := ObjectAccessor;
  end
  else
    Result := nil;
end;

class function TCEFIPCClass.GetCommonAccessor(frameId: int64): TV8CommonAccessor;
var
  CommonAccessor: TV8CommonAccessor;
begin
  if CommonAccessors.TryGetData(frameId, CommonAccessor) then
  begin
    Result := CommonAccessor;
  end
  else
    Result := nil;
end;

class procedure TCEFIPCClass.SetObjectAccessor(frameId: int64; const accessor: TV8ObjectAccessor);
begin
  ObjectAccessors.AddOrSetData(frameId, accessor);
end;

class procedure TCEFIPCClass.SetCommonAccessor(frameId: int64; const accessor: TV8CommonAccessor);
begin
  CommonAccessors.AddOrSetData(frameId, accessor);
end;



end.
