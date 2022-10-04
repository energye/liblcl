//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_V8Accessor;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils,
  uCEFInterfaces, uCEFTypes,
  uCEF_LCL_Entity, uCEF_LCL_Event;

type
  //V8 Get Set 处理器 通用单元类
  TV8Accessor = class
  private
  class var
  public
    class  function GetFieldValue(const Name: ustring): RRetBindValue;
    class  function SetFieldValue(const Name: ustring; const object_, Value: ICefv8Value; var Exception: ustring): boolean;
  end;

implementation

{
 变量属性值获取
}
class function TV8Accessor.GetFieldValue(const Name: ustring): RRetBindValue;
var
  RetValue: RRetBindValue;
begin
  try
    //RetValue := PRRetBindValue;
    //变量类型 0:string 1:int 2:double 3:bool 4:null 5:undefined 6:obje
    TCEFWindowBindClass.SendEvent(Name, [event_get, @RetValue.PVType, @RetValue.PStringValue, @RetValue.PIntValue, @RetValue.DoubleValue,
      @RetValue.PBooleanValue, @RetValue.PException]);
    //ConsoleLn('GetFieldValue PVType: ' + IntToStr(integer(RetValue.PVType)) + '  RetValue: '+ PCharToUstr(PChar(RetValue.PStringValue)));
    Result := RetValue;
    exit;
  except
    on E: Exception do
    begin
      //ConsoleLn('Get Exception: ' + string(E.ToString));
    end;
  end;
end;

{
 变量属性值设置
 javascript 设置值时会触发该函数
 会将新值同步更新到go对应的配置变量属性
}
class function TV8Accessor.SetFieldValue(const Name: ustring; const object_: ICefv8Value; const Value: ICefv8Value; var Exception: ustring): boolean;
var
  PException: Pointer;
  ExceptionMessage: ustring = '';
  //temp value
  StringValue: string;
  IntValue: integer;
  DoubleValue: double;
  BooleanValue: boolean;
begin
  //fieldName event_set newValue  type
  //变量类型 0:string 1:int 2:double 3:bool 4:null 5:undefined 6:object 7:array 8:function
  try
    if Value.IsArray or Value.IsObject or Value.IsFunction or Value.IsArrayBuffer then
    begin
      Exception := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_CANNOT_CHANGE);
      Result := False;
      exit;
    end
    else
    begin
      if Value.IsString then
      begin
        StringValue := string(Value.GetStringValue);
        TCEFWindowBindClass.SendEvent(Name, [event_set, 0, StringValue, @PException]);
      end
      else if Value.IsInt then
      begin
        IntValue := Value.GetIntValue;
        TCEFWindowBindClass.SendEvent(Name, [event_set, 1, IntValue, @PException]);
      end
      else if Value.IsDouble then
      begin
        DoubleValue := Value.GetDoubleValue;
        TCEFWindowBindClass.SendEvent(Name, [event_set, 2, @DoubleValue, @PException]);
      end
      else if Value.IsBool then
      begin
        BooleanValue := Value.GetBoolValue;
        TCEFWindowBindClass.SendEvent(Name, [event_set, 3, BooleanValue, @PException]);
      end
      else if Value.IsNull then
      begin
        TCEFWindowBindClass.SendEvent(Name, [event_set, 4, 'null', @PException]);
      end
      else if Value.IsUndefined then
      begin
        TCEFWindowBindClass.SendEvent(Name, [event_set, 5, 'undefined', @PException]);
      end
      else
      begin
        ExceptionMessage := Name + ErrorCodeToMessage(CVE_ERROR_TYPE_INVALID);
      end;
    end;
    if (ExceptionMessage = '') then
    begin
      ExceptionMessage := PCharToUstr(PChar(PException));
    end;
    if not (ExceptionMessage = '') then
    begin
      Exception := ExceptionMessage;
    end;
  except
    on E: Exception do
    begin
      Exception := StrToUstr(E.ToString);
    end;
  end;
  Result := True;
end;

end.
