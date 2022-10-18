//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8CommonHandler;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  fgl, SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value, uCEFv8Handler,
  uCEF_LCL_Entity, uCEF_LCL_V8ValueRef, uCEF_LCL_Event,
  uCEF_LCL_V8FuncHandler;

type
  //处理的函数信息
  //RFuncHandlerInfo = record
  //  VType: integer; //0:string 1:int 2:double 3:bool 4:null 5:undefined 6:object 7:array 8:function
  //  FnInNum: integer;
  //  FnInParamType: TStringArray;
  //  FnOutNum: integer;
  //  FnOutParamType: TStringArray;
  //  ArgumentsArr: PArgumentsArray;
  //end;
  //PRFuncHandlerInfo = ^RFuncHandlerInfo;
  TFuncHandlerInfoList = specialize TFPGMap<ustring, PRFieldBindInfo>;

  TV8CommonHandler = class(TCefv8HandlerOwn)
  public
    Browser: ICefBrowser;
    Frame: ICefFrame;
    TFuncHandlerInfos: TFuncHandlerInfoList;
    V8FuncHandler: TV8FuncHandler;
    constructor Create;
    destructor Destroy;
    procedure Put(Name: ustring; Value: PRFieldBindInfo);
  protected
    function Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean; override;
  end;

implementation

constructor TV8CommonHandler.Create;
begin
  inherited Create;
  TFuncHandlerInfos := TFuncHandlerInfoList.Create;
  V8FuncHandler := TV8FuncHandler.Create;
end;

destructor TV8CommonHandler.Destroy;
begin
  inherited Destroy;
  TFuncHandlerInfos.Clear;
  TFuncHandlerInfos.Free;
  V8FuncHandler.Destroy;
  V8FuncHandler.Free;
  V8FuncHandler := nil;
end;

procedure TV8CommonHandler.Put(Name: ustring; Value: PRFieldBindInfo);
begin
  TFuncHandlerInfos.AddOrSetData(Name, Value);
end;


//函数执行处理
function TV8CommonHandler.Execute(const Name: ustring; const obj: ICefv8Value; const arguments: TCefv8ValueArray; var retval: ICefv8Value; var Exception: ustring): boolean;
var
  FieldBindInfo: PRFieldBindInfo;
  argumentsLen: integer;
begin
  FieldBindInfo := new(PRFieldBindInfo);
  if TFuncHandlerInfos.TryGetData(Name, FieldBindInfo) then
  begin
    argumentsLen := Length(arguments);
    //判断入参个数
    if not (FieldBindInfo^.FnInNum = argumentsLen) then
    begin
      Exception := 'The input parameter is incorrect. The input parameter should be: ' + IntToStr(FieldBindInfo^.FnInNum) + ', which is actually ' + IntToStr(argumentsLen);
      retval := TCefv8ValueRef.NewString(Exception);
      Result := True;
      exit;
    end;

    //函数类型8，参数个数最多只能有9个
    if (integer(FieldBindInfo^.BindType) = 8) and (argumentsLen < 10) then
    begin
        {
          1.分析参数类型、参数个数
          2.返回参数类型，返回结果
          3.返回错误信息
        }
      retval := V8FuncHandler.Execute(FieldBindInfo, arguments, Exception);
      if not (Exception = '') then
      begin
        Exception := Name + Exception;
      end;
    end
    else
    begin
      Exception := Name + ErrorCodeToMessage(CVE_ERROR_FUNC_INVALID_P_L_9);
    end;
  end
  else
  begin
    Exception := Name + ErrorCodeToMessage(CVE_ERROR_NOT_FOUND_FUNC);
  end;
  Result := True;
end;

end.
