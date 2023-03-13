//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefCommandLineRef_New(var Result: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  Result := TCefCommandLineRef.New;
  handleExceptionEnd
end;

procedure CefCommandLineRef_UnWrap(const data: ICefCommandLine; var Result: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  Result := TCefCommandLineRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

procedure CefCommandLineRef_Global(const TObj: TCefCommandLineRef; var Result: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Global;
  handleExceptionEnd
end;

function CefCommandLine_IsValid(const TObj: ICefCommandLine): Boolean; extdecl;
begin
     Result := TObj.IsValid;
end;

function CefCommandLine_IsReadOnly(const TObj: ICefCommandLine): Boolean; extdecl;
begin
     Result := TObj.IsReadOnly;
end;

procedure CefCommandLine_Copy(const TObj: ICefCommandLine; var Result: ICefCommandLine); extdecl;
begin
     Result := TObj.Copy;
end;

procedure CefCommandLine_InitFromArgv(const TObj: ICefCommandLine; argc: Integer; const argv: PChar); extdecl;
begin
     TObj.InitFromArgv(argc, @argv);
end;

procedure CefCommandLine_InitFromString(const TObj: ICefCommandLine; const commandLine: PChar); extdecl;
begin
     TObj.InitFromString(PCharToUStr(commandLine));
end;

procedure CefCommandLine_Reset(const TObj: ICefCommandLine); extdecl;
begin
     TObj.Reset;
end;

function  CefCommandLine_GetCommandLineString(const TObj: ICefCommandLine): PChar; extdecl;
begin
     Result := PChar(string(TObj.GetCommandLineString));
end;

procedure CefCommandLine_GetArgv(const TObj: ICefCommandLine; var args: TStrings); extdecl;
begin
     TObj.GetArgv(args);
end;

function  CefCommandLine_GetProgram(const TObj: ICefCommandLine): PChar; extdecl;
begin
     Result := PChar(string(TObj.GetProgram));
end;

procedure CefCommandLine_SetProgram(const TObj: ICefCommandLine; const prog: PChar); extdecl;
begin
     TObj.SetProgram(PCharTOUstr(prog));
end;

function  CefCommandLine_HasSwitches(const TObj: ICefCommandLine): Boolean; extdecl;
begin

end;

function  CefCommandLine_HasSwitch(const TObj: ICefCommandLine; const name: PChar): Boolean; extdecl;
begin

end;

function  CefCommandLine_GetSwitchValue(const TObj: ICefCommandLine; const name: PChar): PChar; extdecl;
begin

end;

function  CefCommandLine_GetSwitches(const TObj: ICefCommandLine; var switches: TStrings): boolean; overload; extdecl;
begin

end;

function  CefCommandLine_GetSwitchesList(const TObj: ICefCommandLine; var SwitchKeys, SwitchValues: TStringList): boolean; overload; extdecl;
begin

end;

procedure CefCommandLine_AppendSwitch(const TObj: ICefCommandLine; const name: PChar); extdecl;
begin

end;

procedure CefCommandLine_AppendSwitchWithValue(const TObj: ICefCommandLine; const name, value: PChar); extdecl;
begin

end;

function  CefCommandLine_HasArguments(const TObj: ICefCommandLine): Boolean; extdecl;
begin

end;

procedure CefCommandLine_GetArguments(const TObj: ICefCommandLine; var arguments: TStrings); extdecl;
begin

end;

procedure CefCommandLine_AppendArgument(const TObj: ICefCommandLine; const argument: PChar); extdecl;
begin

end;

procedure CefCommandLine_PrependWrapper(const TObj: ICefCommandLine; const wrapper: PChar); extdecl;
begin

end;

exports
    CefCommandLineRef_New,
    CefCommandLineRef_UnWrap,
    CefCommandLineRef_Global,
    CefCommandLine_IsValid,
    CefCommandLine_IsReadOnly,
    CefCommandLine_Copy,
    CefCommandLine_InitFromArgv,
    CefCommandLine_InitFromString,
    CefCommandLine_Reset,
    CefCommandLine_GetCommandLineString,
    CefCommandLine_GetArgv,
    CefCommandLine_GetProgram,
    CefCommandLine_SetProgram,
    CefCommandLine_HasSwitches,
    CefCommandLine_HasSwitch,
    CefCommandLine_GetSwitchValue,
    CefCommandLine_GetSwitches,
    CefCommandLine_GetSwitchesList,
    CefCommandLine_AppendSwitch,
    CefCommandLine_AppendSwitchWithValue,
    CefCommandLine_HasArguments,
    CefCommandLine_GetArguments,
    CefCommandLine_AppendArgument,
    CefCommandLine_PrependWrapper
;
