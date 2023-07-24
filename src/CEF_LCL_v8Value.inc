//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefV8Value_IsValid(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid;
  handleExceptionEnd
end;

function CefV8Value_IsUndefined(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsUndefined;
  handleExceptionEnd
end;

function CefV8Value_IsNull(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsNull;
  handleExceptionEnd
end;

function CefV8Value_IsBool(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsBool;
  handleExceptionEnd
end;

function CefV8Value_IsInt(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsInt;
  handleExceptionEnd
end;

function CefV8Value_IsUInt(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsUInt;
  handleExceptionEnd
end;

function CefV8Value_IsDouble(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsDouble;
  handleExceptionEnd
end;

function CefV8Value_IsDate(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsDate;
  handleExceptionEnd
end;

function CefV8Value_IsString(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsString;
  handleExceptionEnd
end;

function CefV8Value_IsObject(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsObject;
  handleExceptionEnd
end;

function CefV8Value_IsArray(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsArray;
  handleExceptionEnd
end;

function CefV8Value_IsArrayBuffer(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsArrayBuffer;
  handleExceptionEnd
end;

function CefV8Value_IsFunction(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsFunction;
  handleExceptionEnd
end;

function CefV8Value_IsPromise(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  handleExceptionEnd
end;

function CefV8Value_IsSame(const TObj: ICefv8Value; const that: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(ICefv8Value(that));
  handleExceptionEnd
end;

function CefV8Value_GetBoolValue(TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetBoolValue();
  handleExceptionEnd
end;

function CefV8Value_GetIntValue(TObj: ICefv8Value): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetIntValue();
  handleExceptionEnd
end;

function CefV8Value_GetUIntValue(TObj: ICefv8Value): Cardinal; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetUIntValue();
  handleExceptionEnd
end;

procedure CefV8Value_GetDoubleValue(TObj: ICefv8Value; var Result: Double) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDoubleValue();
  handleExceptionEnd
end;

procedure CefV8Value_GetDateValue(TObj: ICefv8Value; var Result: TDateTime); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDateValue();
  handleExceptionEnd
end;

function CefV8Value_GetStringValue(TObj: ICefv8Value; const TValue: TString): PChar; extdecl;
begin
  handleExceptionBegin
  TValue.SetValue(string(TObj.GetStringValue()));
  handleExceptionEnd
end;

function CefV8Value_IsUserCreated(TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsUserCreated();
  handleExceptionEnd
end;

function CefV8Value_HasException(TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasException();
  handleExceptionEnd
end;

function CefV8Value_GetException(TObj: ICefv8Value): ICefV8Exception; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetException();
  handleExceptionEnd
end;

function CefV8Value_ClearException(TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.ClearException();
  handleExceptionEnd
end;

function CefV8Value_WillRethrowExceptions(TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.WillRethrowExceptions();
  handleExceptionEnd
end;

function CefV8Value_SetRethrowExceptions(const TObj: ICefv8Value; reThrow: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetRethrowExceptions(reThrow);
  handleExceptionEnd
end;

function CefV8Value_HasValueByKey(const TObj: ICefv8Value; const key: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasValueByKey(PCharToUStr(key));
  handleExceptionEnd
end;

function CefV8Value_HasValueByIndex(const TObj: ICefv8Value; index: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasValueByIndex(index);
  handleExceptionEnd
end;

function CefV8Value_DeleteValueByKey(const TObj: ICefv8Value; const key: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.DeleteValueByKey(PCharToUStr(key));
  handleExceptionEnd
end;

function CefV8Value_DeleteValueByIndex(const TObj: ICefv8Value; index: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.DeleteValueByIndex(index);
  handleExceptionEnd
end;

procedure CefV8Value_GetValueByKey(const TObj: ICefv8Value; const key: PChar; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetValueByKey(PCharToUStr(key));
  handleExceptionEnd
end;

procedure CefV8Value_GetValueByIndex(const TObj: ICefv8Value; index: Integer; var Result: ICefv8Value) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetValueByIndex(index);
  handleExceptionEnd
end;

function CefV8Value_SetValueByKey(const TObj: ICefv8Value; const key: PChar; const value: ICefv8Value; attribute: Cardinal): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValueByKey(PCharToUStr(key), value, TCefV8PropertyAttributes(attribute));
  handleExceptionEnd
end;

function CefV8Value_SetValueByIndex(const TObj: ICefv8Value; index: Integer; const value: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValueByIndex(index, value);
  handleExceptionEnd
end;

function CefV8Value_SetValueByAccessor(const TObj: ICefv8Value; const key: PChar; settings: Cardinal; attribute: Cardinal): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValueByAccessor(PCharToUStr(key), TCefV8AccessControls(settings), TCefV8PropertyAttributes(attribute));
  handleExceptionEnd
end;

function CefV8Value_GetKeys(const TObj: ICefv8Value; var ResultKeys: TStrings): Integer; extdecl;
begin
  handleExceptionBegin
  ResultKeys := TStringList.Create;
  Result := TObj.GetKeys(ResultKeys);
  handleExceptionEnd
end;

function CefV8Value_SetUserData(const TObj: ICefv8Value; const data: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetUserData(data);
  handleExceptionEnd
end;

procedure CefV8Value_GetUserData(const TObj: ICefv8Value; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetUserData();
  handleExceptionEnd
end;

function CefV8Value_GetExternallyAllocatedMemory(const TObj: ICefv8Value): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetExternallyAllocatedMemory();
  handleExceptionEnd
end;

function CefV8Value_AdjustExternallyAllocatedMemory(const TObj: ICefv8Value; changeInBytes: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.AdjustExternallyAllocatedMemory(changeInBytes);
  handleExceptionEnd
end;

function CefV8Value_GetArrayLength(const TObj: ICefv8Value): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetArrayLength();
  handleExceptionEnd
end;

procedure CefV8Value_GetArrayBufferReleaseCallback(const TObj: ICefv8Value; var Result: ICefv8ArrayBufferReleaseCallback); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetArrayBufferReleaseCallback();
  handleExceptionEnd
end;

function CefV8Value_NeuterArrayBuffer(const TObj: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.NeuterArrayBuffer();
  handleExceptionEnd
end;

function CefV8Value_GetFunctionName(const TObj: ICefv8Value): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFunctionName()));
  handleExceptionEnd
end;

procedure CefV8Value_GetFunctionHandler(const TObj: ICefv8Value; var Result: ICefv8Handler); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFunctionHandler();
  handleExceptionEnd
end;

procedure CefV8Value_ExecuteFunction(const TObj: ICefv8Value; const obj: ICefv8Value; const arguments: TCefv8ValueArray; argumentsLength: Integer; var Result: ICefv8Value); extdecl;
var
  i: integer;
  args: TCefv8ValueArray;
begin
  handleExceptionBegin
  if argumentsLength > 0 then
  begin
    SetLength(args, argumentsLength);
    for i := 0 to argumentsLength - 1 do
    begin
      args[i] := arguments[i];
    end;
    Result := TObj.ExecuteFunction(obj, args);
  end
  else
    Result := TObj.ExecuteFunction(obj, nil);
  SetLength(args, 0);
  args := nil;
  handleExceptionEnd
end;

procedure CefV8Value_ExecuteFunctionWithContext(const TObj: ICefv8Value; const context: ICefv8Context; const obj: ICefv8Value; const arguments: TCefv8ValueArray; argumentsLength: Integer; var Result: ICefv8Value); extdecl;
var
  i: integer;
  args: TCefv8ValueArray;
begin
  handleExceptionBegin
  if argumentsLength > 0 then
  begin
    SetLength(args, argumentsLength);
    for i := 0 to argumentsLength - 1 do
    begin
      args[i] := arguments[i];
    end;
    Result := TObj.ExecuteFunctionWithContext(context, obj, args);
  end
  else
  begin
    Result := TObj.ExecuteFunctionWithContext(context, obj, nil);
  end;
  SetLength(args, 0);
  args := nil;
  handleExceptionEnd
end;

procedure CefV8Value_ExecuteFunctionWithContextForArgsBytes(const TObj: ICefv8Value; const context: ICefv8Context; const obj: ICefv8Value; const argsBytes: Pointer; argsBytesSize: nativeuint; var Result: ICefv8Value); extdecl;
var
  arguments: TCefv8ValueArray;
begin
  handleExceptionBegin
  arguments := TValueConvert.BytesToV8ValueArray(argsBytes, argsBytesSize);
  Result := TObj.ExecuteFunctionWithContext(context, obj, arguments);
  SetLength(arguments, 0);
  arguments := nil;
  handleExceptionEnd
end;

function CefV8Value_ResolvePromise(const TObj: ICefv8Value; const arg: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  handleExceptionEnd
end;

function CefV8Value_RejectPromise(const TObj: ICefv8Value; const errorMsg: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := False;
  handleExceptionEnd
end;

procedure CefV8Value_Free(var data: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  (data as TCefv8ValueRef).Free;
  data := nil;
  handleExceptionEnd
end;

//CefV8ValueRef
procedure CefV8ValueRef_NewString(const value: PChar; var Result: ICefv8Value) ; extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewString(PCharToUStr(value));
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewUndefined(var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewUndefined;
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewNull(var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewNull;
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewBool(value: LongBool; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewBool(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewInt(value: integer; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewInt(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewUInt(value: Cardinal; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewUInt(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewDouble(value: PDouble; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewDouble(Double(PDouble(value)^));
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewDate(value: PDouble; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewDate(TDateTime(Double(PDouble(value)^)));
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewObject(const Accessor: ICefV8Accessor; const Interceptor: ICefV8Interceptor; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewObject(Accessor, Interceptor);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewArray(len: Integer; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewArray(len);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewArrayBuffer(buffer: Pointer; length: Integer; const callback : ICefv8ArrayBufferReleaseCallback; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewArrayBuffer(buffer, NativeUInt(length), callback);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewFunction(const name: PChar; const handler: ICefv8Handler; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewFunction(PCharToUStr(name), handler);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewPromise(var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := nil;
  handleExceptionEnd
end;

procedure CefV8ValueRef_UnWrap(const data: ICefv8Value; var Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

exports
  CefV8Value_IsValid,
  CefV8Value_IsUndefined,
  CefV8Value_IsNull,
  CefV8Value_IsBool,
  CefV8Value_IsInt,
  CefV8Value_IsUInt,
  CefV8Value_IsDouble,
  CefV8Value_IsDate,
  CefV8Value_IsString,
  CefV8Value_IsObject,
  CefV8Value_IsArray,
  CefV8Value_IsArrayBuffer,
  CefV8Value_IsFunction,
  CefV8Value_IsPromise,
  CefV8Value_IsSame,
  CefV8Value_GetBoolValue,
  CefV8Value_GetIntValue,
  CefV8Value_GetUIntValue,
  CefV8Value_GetDoubleValue,
  CefV8Value_GetDateValue,
  CefV8Value_GetStringValue,
  CefV8Value_IsUserCreated,
  CefV8Value_HasException,
  CefV8Value_GetException,
  CefV8Value_ClearException,
  CefV8Value_WillRethrowExceptions,
  CefV8Value_SetRethrowExceptions,
  CefV8Value_HasValueByKey,
  CefV8Value_HasValueByIndex,
  CefV8Value_DeleteValueByKey,
  CefV8Value_DeleteValueByIndex,
  CefV8Value_GetValueByKey,
  CefV8Value_GetValueByIndex,
  CefV8Value_SetValueByKey,
  CefV8Value_SetValueByIndex,
  CefV8Value_SetValueByAccessor,
  CefV8Value_GetKeys,
  CefV8Value_SetUserData,
  CefV8Value_GetUserData,
  CefV8Value_GetExternallyAllocatedMemory,
  CefV8Value_AdjustExternallyAllocatedMemory,
  CefV8Value_GetArrayLength,
  CefV8Value_GetArrayBufferReleaseCallback,
  CefV8Value_NeuterArrayBuffer,
  CefV8Value_GetFunctionName,
  CefV8Value_GetFunctionHandler,
  CefV8Value_ExecuteFunction,
  CefV8Value_ExecuteFunctionWithContext,
  CefV8Value_ExecuteFunctionWithContextForArgsBytes,
  CefV8Value_ResolvePromise,
  CefV8Value_RejectPromise,
  CefV8Value_Free,
  CefV8ValueRef_NewUndefined,
  CefV8ValueRef_NewNull,
  CefV8ValueRef_NewBool,
  CefV8ValueRef_NewInt,
  CefV8ValueRef_NewUInt,
  CefV8ValueRef_NewDouble,
  CefV8ValueRef_NewDate,
  CefV8ValueRef_NewString,
  CefV8ValueRef_NewObject,
  CefV8ValueRef_NewArray,
  CefV8ValueRef_NewArrayBuffer,
  CefV8ValueRef_NewFunction,
  CefV8ValueRef_NewPromise,
  CefV8ValueRef_UnWrap;
