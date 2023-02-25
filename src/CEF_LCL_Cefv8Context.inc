//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefV8Context_Eval(const TObj: ICefv8Context; const code: PChar; const script_url: PChar; start_line: integer; out retval: ICefv8Value; out exception: ICefV8Exception): Boolean; extdecl;
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

function CefV8Context_Enter(const TObj: ICefv8Context): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Enter();
  handleExceptionEnd
end;

function CefV8Context_Exit(const TObj: ICefv8Context): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.Exit();
  handleExceptionEnd
end;

function CefV8Context_IsSame(const TObj: ICefv8Context; const that: ICefv8Context): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(that);
  handleExceptionEnd
end;

procedure CefV8Context_Browser(const TObj: ICefv8Context; out Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser;
  handleExceptionEnd
end;

procedure CefV8Context_Frame(const TObj: ICefv8Context; out Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Frame;
  handleExceptionEnd
end;

procedure CefV8Context_Global(const TObj: ICefv8Context; out Result: ICefv8Value); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Global;
  handleExceptionEnd
end;

procedure CefV8ContextRef_Current(out Result: ICefv8Context); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ContextRef.Current;
  handleExceptionEnd
end;

procedure CefV8ContextRef_Entered(out Result: ICefv8Context); extdecl;
begin
  handleExceptionBegin
  Result := TCefv8ContextRef.Entered;
  handleExceptionEnd
end;

exports
    CefV8Context_Eval,
    CefV8Context_Enter,
    CefV8Context_Exit,
    CefV8Context_IsSame,
    CefV8Context_Browser,
    CefV8Context_Frame,
    CefV8Context_Global,
    CefV8ContextRef_Current,
    CefV8ContextRef_Entered
;
