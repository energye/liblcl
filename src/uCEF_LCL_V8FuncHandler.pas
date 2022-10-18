//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8FuncHandler;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  fgl, SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFv8Value,
  uCEF_LCL_Entity, uCEF_LCL_V8ValueRef, uCEF_LCL_Event;

type

  TV8FuncHandler = class
  public
    constructor Create;
    destructor Destroy;
    function Execute(FieldBindInfo: PRFieldBindInfo; const arguments: TCefv8ValueArray; var Exception: ustring): ICefv8Value;
  end;

implementation

constructor TV8FuncHandler.Create;
begin
  inherited Create;
end;

destructor TV8FuncHandler.Destroy;
begin
  inherited Destroy;
end;

function TV8FuncHandler.Execute(FieldBindInfo: PRFieldBindInfo; const arguments: TCefv8ValueArray; var Exception: ustring): ICefv8Value;
var
  //result
  PExceptionMessage: Pointer;
  resExceptionMessage: ustring = '';
  res: boolean;
  retVType: integer = -1;
  PRetStringValue: Pointer;
  PRetIntValue: PInteger;
  RetDoubleValue: Double;
  PRetBooleanValue: PBoolean;

  //args
  idx: integer;
  argumentsLen: integer;
  args: ICefv8Value;
  argsDefLen: integer;
  argsArray: array of TVarRec;
  argsArrayIdx: integer;
  PRArgs: PRArguments;
begin
  try
    res := True;
    argumentsLen := Length(arguments);
    argsDefLen := 2 + FieldBindInfo^.FnOutNum;//argsArray 默认参数个数， [事件类型, 返回值-异常信息, 返回值, 入参(多个),...]
    //获取出参类型所在数组位置
    if integer(FieldBindInfo^.FnOutNum) = 1 then
    begin
      if not (FieldBindInfo^.FnOutParamType[0] = '9') then //9 = EXCEPTION
      begin
        retVType := StrToInt(FieldBindInfo^.FnOutParamType[0]);
        Inc(argsDefLen);
      end;
    end
    else if integer(FieldBindInfo^.FnOutNum) = 2 then
    begin
      if FieldBindInfo^.FnOutParamType[0] = '9' then
      begin
        retVType := StrToInt(FieldBindInfo^.FnOutParamType[1]);
      end
      else
      begin
        retVType := StrToInt(FieldBindInfo^.FnOutParamType[0]);
      end;
      Inc(argsDefLen);
    end;

    SetLength(argsArray, argumentsLen + argsDefLen);
    FieldBindInfo^.ArgumentsArr := new(PArgumentsArray);
    SetLength(FieldBindInfo^.ArgumentsArr^, argumentsLen);

    argsArray[0].VInteger := longint(event_func);//事件类型
    argsArray[0].VType := vtInteger;

    argsArray[1].VPointer := @PExceptionMessage;//返回值-异常信息
    argsArray[1].VType := vtPointer;

    if retVType > -1 then
    begin
      //出参类型
      case retVType of
        0:
        begin
          argsArray[2].VPointer := @PRetStringValue;//返回值 string
          argsArray[2].VType := vtPointer;
        end;
        1:
        begin
          argsArray[2].VPointer := @PRetIntValue;//返回值 int
          argsArray[2].VType := vtPointer;
        end;
        2:
        begin
          argsArray[2].VPointer := @RetDoubleValue;//返回值 double
          argsArray[2].VType := vtPointer;
        end;
        3:
        begin
          argsArray[2].VPointer := @PRetBooleanValue;//返回值 bool
          argsArray[2].VType := vtPointer;
        end;
      end;
    end;
    //遍历入参参数-最多只能有9个
    for idx := 0 to argumentsLen - 1 do
    begin
      args := arguments[idx];
      argsArrayIdx := idx + argsDefLen;
      FieldBindInfo^.ArgumentsArr^[idx] := new(PRArguments);
      PRArgs := FieldBindInfo^.ArgumentsArr^[idx];
      //判断每个参数类型
      if args.IsString then
      begin
        PRArgs^.StringValue := PChar(string(args.GetStringValue));
        argsArray[argsArrayIdx].VPChar := PRArgs^.StringValue;
        argsArray[argsArrayIdx].VType := vtPChar;
      end
      else if args.IsInt then
      begin
        PRArgs^.IntegerValue := args.GetIntValue;
        argsArray[argsArrayIdx].VInteger := PRArgs^.IntegerValue;
        argsArray[argsArrayIdx].VType := vtInteger;
      end
      else if args.IsDouble then
      begin
        PRArgs^.DoubleValue := args.GetDoubleValue;
        PRArgs^.PDoubleValue := @PRArgs^.DoubleValue;
        argsArray[argsArrayIdx].VPointer := PRArgs^.PDoubleValue;
        argsArray[argsArrayIdx].VType := vtPointer;
      end
      else if args.IsBool then
      begin
        PRArgs^.BooleanValue := args.GetBoolValue;
        argsArray[argsArrayIdx].VBoolean := PRArgs^.BooleanValue;
        argsArray[argsArrayIdx].VType := vtBoolean;
      end
      else
      begin
        Exception := ErrorCodeToMessage(CVE_ERROR_FUNC_IN_PAM);
        res := False;
        break;
      end;
    end;
    if res then//参数没有问题
    begin
      //发送调用函数事件
      TCEFWindowBindClass.SendEvent(FieldBindInfo^.FullName, argsArray);
      //得到异常结果 如果不为 '' 表示失败
      resExceptionMessage := PCharToUStr(PChar(PExceptionMessage));
      if not (resExceptionMessage = '') then
      begin//失败
        Exception := resExceptionMessage;
        Result := nil;
        exit;
      end
      else
      begin//成功
        //处理返回结果
        if retVType > -1 then
        begin// > -1 说明定义了出参
          case retVType of
            0:
            begin
              Result := TCefv8ValueRef.NewString(PCharToUStr(PChar(PRetStringValue)));
            end;
            1:
            begin
              Result := TCefv8ValueRef.NewInt(integer(PRetIntValue));
            end;
            2:
            begin
              Result := TCefv8ValueRef.NewDouble(RetDoubleValue);
            end;
            3:
            begin
              Result := TCefv8ValueRef.NewBool(boolean(PRetBooleanValue));
            end;
          end;
          exit;
        end;
      end;
    end;
    Result := nil;
  finally
    PExceptionMessage := nil;
    PRetStringValue := nil;
    PRetIntValue := nil;
    PRetBooleanValue := nil;
    PRArgs := nil;
    FreeArrayTVarRec(argsArray);
    SetLength(argsArray, 0);
    for idx := 0 to argumentsLen - 1 do
    begin
      FieldBindInfo^.ArgumentsArr^[idx]^.StringValue := nil;
      FieldBindInfo^.ArgumentsArr^[idx]^.PDoubleValue := nil;
      FieldBindInfo^.ArgumentsArr^[idx] := nil;
    end;
    SetLength(FieldBindInfo^.ArgumentsArr^, 0);
    FreeMemAndNil(argsArray);
    FreeMemAndNil(FieldBindInfo^.ArgumentsArr);
  end;
end;

end.
