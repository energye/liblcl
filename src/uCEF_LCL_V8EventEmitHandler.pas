//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8EventEmitHandler;

{
 字段取值，赋值，函数执行 只做异步操作处理
}
{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler,
  uCEF_LCL_Entity, uCEF_LCL_Event,
  uCEF_LCL_IPC;

type

  TV8EventEmitHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
  public
    constructor Create;
    destructor Destroy;
  protected
    function Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

var
  //渲染进程中 js使用的emit函数（ipc.emit）
  IPCExecuteName: string = 'emit';

implementation

//函数执行处理
function TV8EventEmitHandler.Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  paramType: integer; //1:只有名称 2:有入参无回调 3:无入参有回调 4:有入参 有回调
  argumentsLen: integer;
  //IPCId: integer;
  ret: integer;
begin

  //参数长度 最多3个，固定顺序: 参数1 字段名, 参数2 入参， 参数3 回调函数
  argumentsLen := length(arguments);
  if (Name = IPCExecuteName) and (argumentsLen >= 1) and arguments[0].IsString then
  begin
    // = 1 个参数只调用，没有入参和回调函数
    if argumentsLen = 1 then
    begin
      paramType := 1;
    end
    // = 2 个参数 有入参 没有回调函数
    else if (argumentsLen = 2) and (arguments[1].IsArray) then
    begin
      paramType := 2;
    end
    // = 2 个参数 没有入参 有回调函数
    else if (argumentsLen = 2) and (arguments[1].IsFunction) then
    begin
      paramType := 3;
    end
    // =3 个参数 有入参 有回调函数
    else if (argumentsLen = 3) and (arguments[1].IsArray) and (arguments[2].IsFunction) then
    begin
      paramType := 4;
    end
    else
    begin
      //IPCExecuteName 函数参数长度不正确 最多只能3个 1:名称 2:参数 3:回调函数
      Exception := IPCExecuteName + ', Error - Parameter Description 1:name 2:array type(in|value) 3:callback function';
      retval := TCefv8ValueRef.NewBool(False);
      Result := True;
      exit;
    end;
    if (paramType = 2) or (paramType = 4) then
    begin
      if arguments[1].GetArrayLength > 9 then
      begin
        Exception := 'The maximum number of input parameters is 9';
        retval := TCefv8ValueRef.NewBool(False);
        Result := True;
        exit;
      end;
    end;

    ret := TCEFIPCClass.RenderProcessJSEmitGoOn(Browser.Identifier, Frame, arguments[0].GetStringValue, paramType, arguments);
    if ret < 0 then
    begin
      //失败
      Exception := 'The parameter type is incorrect and only supported [string int double boolean]';
      retval := TCefv8ValueRef.NewBool(False);
      Result := True;
      exit;
    end
    else
    begin
      retval := TCefv8ValueRef.NewBool(True);
      Result := True;
    end;
  end
  else
  begin
    Exception := IPCExecuteName + ', Error - Parameter Description 1:name 2:array type(in|value) 3:callback function';
    retval := TCefv8ValueRef.NewBool(False);
    Result := False;
  end;
end;


constructor TV8EventEmitHandler.Create;
begin
  inherited Create;
end;

destructor TV8EventEmitHandler.Destroy;
begin
  inherited Destroy;
end;

end.
