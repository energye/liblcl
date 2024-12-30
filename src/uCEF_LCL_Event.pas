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
  Messages, fgl, Controls, uCEFTypes,
  SysUtils,
  uCEF_LCL_Entity;

const
  CEFCALL_MAX_PARAM = 12;


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
    class function SendEvent(const AEventName: ustring; AArgs: array of const): boolean;
    class function Size(): longint;
    class procedure Clear();
  end;

  PointerArray = array of Pointer;



type//Chromium Windows Comp Message
  TChromiumWindowsCompMsg = function(var aMessage: TMessage; var aHandled: boolean): Pointer; extdecl;


function ArgsToParamsPtr(AArgs: array of const): Pointer;

type//Application.QueueAsyncCall UI主程序异步调用回调事件
  ApplicationQueueAsyncCallPtr = function(id: nativeuint): Pointer; extdecl;
  ApplicationQueueAsyncCallEventClass = class
    class procedure SendEvent(id: nativeuint);
  end;

var
  //WindowBind 回调函数指针变量
  GCEFWindowBindPtr: TCEFWindowBindPtr;
  //Application.QueueAsyncCall UI主程序异步调用回调指针
  GApplicationQueueAsyncCallPtr: ApplicationQueueAsyncCallPtr;

implementation

function ArgsToParamsPtr(AArgs: array of const): Pointer;
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
        vtInterface: LParams[I] := LV.VInterface;
        vtWideString: LParams[I] := LV.VWideString;
        vtInt64: LParams[I] := LV.VInt64;
        vtUnicodeString: LParams[I] := LV.VUnicodeString;
      end;
    end;
    Result := @LParams[0];
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

class function TCEFWindowBindClass.Size(): longint;
begin
  Result := TCEFWindowBinds.Count;
end;


class function TCEFWindowBindClass.SendEvent(const AEventName: ustring; AArgs: array of const): boolean;

  procedure SendWindowBindEventSrc(const PEventName: PChar; AArgs: array of const);
  var
    LParams: Pointer;
    LArgLen: integer;
  begin
    if Assigned(GCEFWindowBindPtr) then
    begin
      LArgLen := Length(AArgs);
      LParams := ArgsToParamsPtr(AArgs);
      if not (LParams = nil) then
      begin
        GCEFWindowBindPtr(PEventName, LParams, LArgLen);
      end;
    end;
  end;

begin
  SendWindowBindEventSrc(PChar(string(AEventName)), AArgs);
  Result := True;
end;

{===Window Bind Events TCEFWindowBindClass===}


{===CEF IPC Events TIPCEventClass===}

class procedure ApplicationQueueAsyncCallEventClass.SendEvent(id: nativeuint);
begin
  if Assigned(GApplicationQueueAsyncCallPtr) then
  begin
    GApplicationQueueAsyncCallPtr(id);
  end;
end;
end.
