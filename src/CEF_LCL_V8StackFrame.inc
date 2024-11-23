//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure V8StackFrameRef_UnWrap(const AObj: ICefV8StackFrame; out Result: ICefV8StackFrame); extdecl;
begin
  handleExceptionBegin
  Result := TCefV8StackFrameRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function V8StackFrame_IsValid(const AObj: ICefV8StackFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid();
  handleExceptionEnd
end;

function V8StackFrame_GetScriptName(const AObj: ICefV8StackFrame): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetScriptName());
  handleExceptionEnd
end;

function V8StackFrame_GetScriptNameOrSourceUrl(const AObj: ICefV8StackFrame): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetScriptNameOrSourceUrl());
  handleExceptionEnd
end;

function V8StackFrame_GetFunctionName(const AObj: ICefV8StackFrame): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetFunctionName());
  handleExceptionEnd
end;

function V8StackFrame_GetLineNumber(const AObj: ICefV8StackFrame): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetLineNumber();
  handleExceptionEnd
end;

function V8StackFrame_GetColumn(const AObj: ICefV8StackFrame): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetColumn();
  handleExceptionEnd
end;

function V8StackFrame_IsEval(const AObj: ICefV8StackFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsEval();
  handleExceptionEnd
end;

function V8StackFrame_IsConstructor(const AObj: ICefV8StackFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsConstructor();
  handleExceptionEnd
end;


exports
  V8StackFrameRef_UnWrap,
  V8StackFrame_IsValid,
  V8StackFrame_GetScriptName,
  V8StackFrame_GetScriptNameOrSourceUrl,
  V8StackFrame_GetFunctionName,
  V8StackFrame_GetLineNumber,
  V8StackFrame_GetColumn,
  V8StackFrame_IsEval,
  V8StackFrame_IsConstructor;
