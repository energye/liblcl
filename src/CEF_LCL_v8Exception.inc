//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

function CefV8Exception_Message(const TObj: ICefV8Exception): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Message));
  handleExceptionEnd
end;

function CefV8Exception_SourceLine(const TObj: ICefV8Exception): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.SourceLine));
  handleExceptionEnd
end;

function CefV8Exception_ScriptResourceName(const TObj: ICefV8Exception): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.ScriptResourceName));
  handleExceptionEnd
end;

function CefV8Exception_LineNumber(const TObj: ICefV8Exception): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.LineNumber;
  handleExceptionEnd
end;

function CefV8Exception_StartPosition(const TObj: ICefV8Exception): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.StartPosition;
  handleExceptionEnd
end;

function CefV8Exception_EndPosition(const TObj: ICefV8Exception): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.EndPosition;
  handleExceptionEnd
end;

function CefV8Exception_StartColumn(const TObj: ICefV8Exception): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.StartColumn;
  handleExceptionEnd
end;

function CefV8Exception_EndColumn(const TObj: ICefV8Exception): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.EndColumn;
  handleExceptionEnd
end;

exports
  CefV8Exception_Message,
  CefV8Exception_SourceLine,
  CefV8Exception_ScriptResourceName,
  CefV8Exception_LineNumber,
  CefV8Exception_StartPosition,
  CefV8Exception_EndPosition,
  CefV8Exception_StartColumn,
  CefV8Exception_EndColumn
;
