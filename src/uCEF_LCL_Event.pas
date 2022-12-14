//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_Event;

{$mode objfpc}{$H+}
{$I cef.inc}
{$I ExtDecl.inc}

interface

uses
  fgl, Controls, uCEFTypes,
  SysUtils,
  uCEF_LCL_Entity;

const
  // call最长参数数，与导出的MySyscall一致，暂定为12个
  CEFCALL_MAX_PARAM = 12;

type // Cef Event
  //CEF事件回调函数指针-该事件集合不会清空
  TCEFEventCallbackPtr = function(fn: nativeuint; args: Pointer; argsCout: nativeint): Pointer; extdecl;
  //CEF事件回调函数存放集合
  TCEFEventList = specialize TFPGMap<ustring, nativeuint>;

  {定义CEF事件类}
  TCEFEventClass = class
  private
  class var
    FCEFEvents: TCEFEventList;
  public
    class constructor Create;
    class destructor Destroy;
    class procedure Add(AEventName: ustring; AEventId: nativeuint);
    class procedure Remove(AEventName: ustring);
    class procedure SendEvent(AEventName: ustring; AArgs: array of const);
    class function Size(): longint;
  end;

type //Window Bind
  //window 字段 函数 绑定函数指针
  //该事件集合每次刷新会清空，所以需要独立出来
  TCEFWindowBindPtr = function(fn: PChar; args: Pointer; argsCout: nativeint): Pointer; extdecl;
  {
    TCEFWindowBindList windowBind 集合
    key:函数名称  value:每个函数: 1.唯一ID 2.参数个数 3.每个参数类型 4.返回参数类型
    uCEF_LCL_V8Handler 处理函数，参数，返回值，错误信息
  }
  TCEFWindowBindList = specialize TFPGMap<ustring, nativeuint>;

  {定义CEF事件类}
  TCEFWindowBindClass = class
  private
  class var
    TCEFWindowBinds: TCEFWindowBindList;
  public
    class constructor Create;
    class destructor Destroy;
    //class procedure Add(AEventName: ustring; AEventId: nativeuint);
   // class function GetEventId(AEventName: ustring): nativeuint;
    class function SendEvent(const AEventName: ustring; AArgs: array of const): boolean;
    class function Size(): longint;
    class procedure Clear();
  end;

  PointerArray = array of Pointer;

type //IPC
  //CEF IPC 事件处理函数
  TCEFIPCEventCallbackPtr = function(fn: nativeuint; args: Pointer; argsCout: nativeint): Pointer; extdecl;
  //IPC事件类
  TIPCEventClass = class
    class function SendEvent(IPCID: nativeuint; AArgs: array of const): boolean;
  end;

function ArgsToParamsPtr(AArgs: array of const): PointerArray;

type//Application.QueueAsyncCall UI主程序异步调用回调事件
  ApplicationQueueAsyncCallPtr = function(id: nativeuint): Pointer; extdecl;
  ApplicationQueueAsyncCallEventClass = class
    class procedure SendEvent(id: nativeuint);
  end;

var
  //CEF IPC 事件处理函数指针变量
  GCEFIPCEventCallbackPtr: TCEFIPCEventCallbackPtr;
  //CEF 事件回调函数指针变量
  GCEFEventCallbackPtr: TCEFEventCallbackPtr;
  //WindowBind 回调函数指针变量
  GCEFWindowBindPtr: TCEFWindowBindPtr;
  //Application.QueueAsyncCall UI主程序异步调用回调指针
  GApplicationQueueAsyncCallPtr: ApplicationQueueAsyncCallPtr;

  //GlobalCEFApp TCefv8ValueRef 普通变量属性的所属默认对象名称 默认值 v8
  CommonRootName: ustring = v8cobj;
  ObjectRootName: ustring = v8obj;

implementation

function ArgsToParamsPtr(AArgs: array of const): PointerArray;
var
  LParams: array[0..CEFCALL_MAX_PARAM - 1] of Pointer;
  LArgLen: integer;
  LV: TVarRec;
  I: integer;
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
        vtString: LParams[I] := {$IFDEF MSWINDOWS}LV.VString{$ELSE}LV.VAnsiString{$ENDIF};
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
    Result := LParams;
    exit;
  end;
  Result := nil;
end;

{===Window Bind Events TCEFWindowBindClass===}
class constructor TCEFWindowBindClass.Create;
begin
  TCEFWindowBinds := TCEFWindowBindList.Create;
end;

class destructor TCEFWindowBindClass.Destroy;
begin
  TCEFWindowBinds.Clear;
  TCEFWindowBinds.Free;
end;

class procedure TCEFWindowBindClass.Clear();
begin
  TCEFWindowBinds.Clear;
end;

//class procedure TCEFWindowBindClass.Add(AEventName: ustring; AEventId: nativeuint);
//begin
//  TCEFWindowBinds.AddOrSetData(AEventName, AEventId);
//end;

class function TCEFWindowBindClass.Size(): longint;
begin
  Result := TCEFWindowBinds.Count;
end;

//class function TCEFWindowBindClass.GetEventId(AEventName: ustring): nativeuint;
//var
//  LEventId: nativeuint = 0;
//begin
//  if TCEFWindowBinds.TryGetData(AEventName, LEventId) then
//  begin
//    Result := LEventId;
//    exit;
//  end;
//  Result := 0;
//end;

class function TCEFWindowBindClass.SendEvent(const AEventName: ustring; AArgs: array of const): boolean;

  procedure SendWindowBindEventSrc(const PEventName: PChar; AArgs: array of const);
  var
    LParams: PointerArray;
    LArgLen: integer;
  begin
    if Assigned(GCEFWindowBindPtr) then
    begin
      LArgLen := Length(AArgs);
      LParams := ArgsToParamsPtr(AArgs);
      if not (LParams = nil) then
      begin
        GCEFWindowBindPtr(PEventName, @LParams[0], LArgLen);
      end;
    end;
  end;

begin
  SendWindowBindEventSrc(PChar(string(AEventName)), AArgs);
  Result := True;
end;

{===Window Bind Events TCEFWindowBindClass===}

{===CEF Events TCEFEventClass===}
class constructor TCEFEventClass.Create;
begin
  FCEFEvents := TCEFEventList.Create;
end;

class destructor TCEFEventClass.Destroy;
begin
  FCEFEvents.Clear;
  FCEFEvents.Free;
end;

class procedure TCEFEventClass.Add(AEventName: ustring; AEventId: nativeuint);
var
  LEventId: nativeuint = 0;
begin

  if Assigned(FCEFEvents) and (not FCEFEvents.TryGetData(AEventName, LEventId)) then
  begin
    FCEFEvents.AddOrSetData(AEventName, AEventId);
  end;
end;

class procedure TCEFEventClass.Remove(AEventName: ustring);
begin
  if Assigned(FCEFEvents) then
    FCEFEvents.Remove(AEventName);
end;

class function TCEFEventClass.Size(): longint;
begin
  if Assigned(FCEFEvents) then
    Result := FCEFEvents.Count;
end;

//CEF发送事件回调函数
class procedure TCEFEventClass.SendEvent(AEventName: ustring; AArgs: array of const);

  procedure SendCEFEventSrc(EventId: nativeuint; AArgs: array of const);
  var
    LParams: PointerArray;
    LArgLen: integer;
  begin
    if Assigned(GCEFEventCallbackPtr) and (EventId > 0) then
    begin
      LArgLen := Length(AArgs);
      LParams := ArgsToParamsPtr(AArgs);
      if not (LParams = nil) then
      begin
        GCEFEventCallbackPtr(EventId, @LParams[0], LArgLen);
      end;
    end;
  end;

var
  LEventId: nativeuint = 0;
begin
  if FCEFEvents.TryGetData(AEventName, LEventId) then
  begin
    SendCEFEventSrc(LEventId, AArgs);
    Exit;
  end;
end;
{===CEF Events TCEFEventClass===}


{===CEF IPC Events TIPCEventClass===}
class function TIPCEventClass.SendEvent(IPCID: nativeuint; AArgs: array of const): boolean;
  procedure SendEventSrc(IPCID: nativeuint; AArgs: array of const);
  var
    LParams: PointerArray;
    LArgLen: integer;
  begin
    if Assigned(GCEFIPCEventCallbackPtr) then
    begin
      LArgLen := Length(AArgs);
      LParams := ArgsToParamsPtr(AArgs);
      if not (LParams = nil) then
      begin
        GCEFIPCEventCallbackPtr(IPCID, @LParams[0], LArgLen);
      end;
    end;
  end;
begin
  SendEventSrc(IPCID, AArgs);
  Result := True;
end;
{===CEF IPC Events TIPCEventClass===}

class procedure ApplicationQueueAsyncCallEventClass.SendEvent(id: nativeuint);
begin
  if Assigned(GApplicationQueueAsyncCallPtr) and (id > 0) then
  begin
    GApplicationQueueAsyncCallPtr(id);
  end;
end;
end.
