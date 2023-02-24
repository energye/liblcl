//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefV8Context_Eval(const TObj: ICefv8Context; const code: PChar; const script_url: PChar; start_line: integer; out retval: ICefv8Value; out exception: ICefV8Exception): LongBool; extdecl;
var
  pReturnValue : ICefv8Value;
  pReturnException: ICefV8Exception;
begin
  handleExceptionBegin
  Result := TObj.Eval(PCharToUStr(code), PCharToUStr(script_url), start_line, pReturnValue, pReturnException);
  retval := pReturnValue;
  exception := pReturnException;
  handleExceptionEnd
end;

function CefV8Context_Enter(const TObj: ICefv8Context): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Enter();
  handleExceptionEnd
end;

function CefV8Context_Exit(const TObj: ICefv8Context): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Exit();
  handleExceptionEnd
end;

function CefV8Context_IsSame(const TObj: ICefv8Context; const that: ICefv8Context): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(that);
  handleExceptionEnd
end;

exports
    CefV8Context_Eval,
    CefV8Context_Enter,
    CefV8Context_Exit,
    CefV8Context_IsSame
;
