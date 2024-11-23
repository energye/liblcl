//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure V8StackTraceRef_UnWrap(const AObj: ICefV8StackTrace; out Result: ICefV8StackTrace); extdecl;
begin
  handleExceptionBegin
  Result := TCefV8StackTraceRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

procedure V8StackTraceRef_Current(frameLimit: Integer; out Result: ICefV8StackTrace); extdecl;
begin
  handleExceptionBegin
  Result := TCefV8StackTraceRef.Current(frameLimit);
  handleExceptionEnd
end;

function V8StackTrace_IsValid(const AObj: ICefV8StackTrace): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid();
  handleExceptionEnd
end;

function V8StackTrace_GetFrameCount(const AObj: ICefV8StackTrace): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetFrameCount();
  handleExceptionEnd
end;

procedure V8StackTrace_GetFrame(const AObj: ICefV8StackTrace; index: Integer; out Result: ICefV8StackFrame); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetFrame(index);
  handleExceptionEnd
end;

exports
  V8StackTraceRef_UnWrap,
  V8StackTraceRef_Current,
  V8StackTrace_IsValid,
  V8StackTrace_GetFrameCount,
  V8StackTrace_GetFrame;
