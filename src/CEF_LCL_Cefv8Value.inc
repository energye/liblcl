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
  Result := TObj.IsPromise;
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

procedure CefV8Value_GetDoubleValue(TObj: ICefv8Value; out Result: Double) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDoubleValue();
  handleExceptionEnd
end;

procedure CefV8Value_GetDateValue(TObj: ICefv8Value; out Result: TDateTime); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetDateValue();
  handleExceptionEnd
end;

function CefV8Value_GetStringValue(TObj: ICefv8Value): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetStringValue()));
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

function CefV8Value_SetRethrowExceptions(const TObj: ICefv8Value; reThrow: Boolean): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetRethrowExceptions(reThrow);
  handleExceptionEnd
end;

function CefV8Value_HasValueByKey(const TObj: ICefv8Value; const key: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasValueByKey(StrPas(key));
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
  Result := TObj.DeleteValueByKey(StrPas(key));
  handleExceptionEnd
end;

function CefV8Value_DeleteValueByIndex(const TObj: ICefv8Value; index: Integer): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.DeleteValueByIndex(index);
  handleExceptionEnd
end;

procedure CefV8Value_GetValueByKey(const TObj: ICefv8Value; const key: PChar; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetValueByKey(StrPas(key));
  handleExceptionEnd
end;

procedure CefV8Value_GetValueByIndex(const TObj: ICefv8Value; index: Integer; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetValueByIndex(index);
  handleExceptionEnd
end;

function CefV8Value_SetValueByKey(const TObj: ICefv8Value; const key: PChar; const value: ICefv8Value; attribute: Cardinal): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetValueByKey(StrPas(key), value, TCefV8PropertyAttributes(attribute));
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
  Result := TObj.SetValueByAccessor(StrPas(key), TCefV8AccessControls(settings), TCefV8PropertyAttributes(attribute));
  handleExceptionEnd
end;

function CefV8Value_GetKeys(const TObj: ICefv8Value; const keys: TStrings): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetKeys(keys);
  handleExceptionEnd
end;

function CefV8Value_SetUserData(const TObj: ICefv8Value; const data: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.SetUserData(data);
  handleExceptionEnd
end;

procedure CefV8Value_GetUserData(const TObj: ICefv8Value; out Result: ICefv8Value); extdecl;
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

function CefV8Value_GetArrayBufferReleaseCallback(const TObj: ICefv8Value): ICefv8ArrayBufferReleaseCallback; extdecl;
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

procedure CefV8Value_GetFunctionHandler(const TObj: ICefv8Value; out Result: ICefv8Handler); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetFunctionHandler();
  handleExceptionEnd
end;

procedure CefV8Value_ExecuteFunction(const TObj: ICefv8Value; const obj: ICefv8Value; out Result: ICefv8Value; const arguments: TCefv8ValueArray); extdecl;
begin
  handleExceptionBegin
  Result := TObj.ExecuteFunction(obj, arguments);
  handleExceptionEnd
end;

procedure CefV8Value_ExecuteFunctionWithContext(const TObj: ICefv8Value; const context: ICefv8Context; const obj: ICefv8Value; out Result: ICefv8Value; const arguments: TCefv8ValueArray); extdecl;
begin
  handleExceptionBegin
  if context.Enter then
  begin
    Result := TObj.ExecuteFunctionWithContext(context, obj, arguments);
    context.Exit;
  end;
  handleExceptionEnd
end;

function CefV8Value_ResolvePromise(const TObj: ICefv8Value; const arg: ICefv8Value): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.ResolvePromise(arg);
  handleExceptionEnd
end;

function CefV8Value_RejectPromise(const TObj: ICefv8Value; const errorMsg: PChar): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.RejectPromise(StrPas(errorMsg));
  handleExceptionEnd
end;

//CefV8ValueRef
procedure CefV8ValueRef_NewUndefined(out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewUndefined;
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewNull(out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewNull;
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewBool(value: LongBool; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewBool(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewInt(value: integer; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewInt(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewUInt(value: Cardinal; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewUInt(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewDouble(value: Double; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewDouble(value);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewDate(value: Double; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewDate(TDateTime(value));
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewString(value: PChar; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewString(StrPas(value));
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewObject(const Accessor: TV8AccessorRef; const Interceptor: TV8InterceptorRef; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewObject(Accessor, Interceptor);
  handleExceptionEnd

end;

procedure CefV8ValueRef_NewArray(len: Integer; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewArray(len);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewArrayBuffer(buffer: Pointer; length: NativeUInt; const callback : ICefv8ArrayBufferReleaseCallback; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewArrayBuffer(buffer, length, callback);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewFunction(const name: PChar; const handler: TV8HandlerRef; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewFunction(StrPas(name), handler);
  handleExceptionEnd
end;

procedure CefV8ValueRef_NewPromise(out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ValueRef.NewPromise();
  handleExceptionEnd
end;

exports
    //CefV8Value
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
    CefV8Value_ResolvePromise,
    CefV8Value_RejectPromise,
    //CefV8ValueRef
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
    CefV8ValueRef_NewPromise
;
