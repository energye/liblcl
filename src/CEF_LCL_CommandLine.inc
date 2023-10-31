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

procedure CefCommandLineRef_Global(var Result: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  Result := TCefCommandLineRef.Global;
  handleExceptionEnd
end;

function CefCommandLine_IsValid(const TObj: ICefCommandLine): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid;
  handleExceptionEnd
end;

function CefCommandLine_IsReadOnly(const TObj: ICefCommandLine): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsReadOnly;
  handleExceptionEnd
end;

procedure CefCommandLine_Copy(const TObj: ICefCommandLine; var Result: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Copy;
  handleExceptionEnd
end;

procedure CefCommandLine_InitFromArgv(const TObj: ICefCommandLine; argc: Integer; const argv: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.InitFromArgv(argc, @argv);
  handleExceptionEnd
end;

procedure CefCommandLine_InitFromString(const TObj: ICefCommandLine; const commandLine: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.InitFromString(PCharToUStr(commandLine));
  handleExceptionEnd
end;

procedure CefCommandLine_Reset(const TObj: ICefCommandLine); extdecl;
begin
  handleExceptionBegin
  TObj.Reset;
  handleExceptionEnd
end;

function  CefCommandLine_GetCommandLineString(const TObj: ICefCommandLine): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetCommandLineString));
  handleExceptionEnd
end;

procedure CefCommandLine_GetArgv(const TObj: ICefCommandLine; var ResultArgv: TStrings); extdecl;
begin
  handleExceptionBegin
  ResultArgv := TStringList.Create;
  TObj.GetArgv(ResultArgv);
  handleExceptionEnd
end;

function  CefCommandLine_GetProgram(const TObj: ICefCommandLine): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetProgram));
  handleExceptionEnd
end;

procedure CefCommandLine_SetProgram(const TObj: ICefCommandLine; const prog: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.SetProgram(PCharTOUstr(prog));
  handleExceptionEnd
end;

function  CefCommandLine_HasSwitches(const TObj: ICefCommandLine): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasSwitches;
  handleExceptionEnd
end;

function  CefCommandLine_HasSwitch(const TObj: ICefCommandLine; const PName: PChar): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasSwitch(PCharToUStr(PName));
  handleExceptionEnd
end;

function  CefCommandLine_GetSwitchValue(const TObj: ICefCommandLine; const PName: PChar): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetSwitchValue(PCharToUStr(PName))));
  handleExceptionEnd
end;

function  CefCommandLine_GetSwitches(const TObj: ICefCommandLine; var ResultSwitches: TStrings): boolean; extdecl;
begin
  handleExceptionBegin
  ResultSwitches := TStringList.Create;
  Result := TObj.GetSwitches(ResultSwitches);
  handleExceptionEnd
end;

function  CefCommandLine_GetSwitchesList(const TObj: ICefCommandLine; var ResultSwitchKeys, ResultSwitchValues: TStringList): boolean; extdecl;
begin
  handleExceptionBegin
  ResultSwitchKeys := TStringList.Create;
  ResultSwitchValues := TStringList.Create;
  Result := TObj.GetSwitches(ResultSwitchKeys, ResultSwitchValues);
  handleExceptionEnd
end;

procedure CefCommandLine_AppendSwitch(const TObj: ICefCommandLine; const PName: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.AppendSwitch(PCharToUStr(PName));
  handleExceptionEnd
end;

procedure CefCommandLine_AppendSwitchWithValue(const TObj: ICefCommandLine; const PName, PValue: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.AppendSwitchWithValue(PCharToUStr(PName), PCharToUStr(PValue));
  handleExceptionEnd
end;

function  CefCommandLine_HasArguments(const TObj: ICefCommandLine): Boolean; extdecl;
begin
  handleExceptionBegin
  Result := TObj.HasArguments;
  handleExceptionEnd
end;

procedure CefCommandLine_GetArguments(const TObj: ICefCommandLine; var ResultArguments: TStrings); extdecl;
begin
  handleExceptionBegin
  ResultArguments := TStringList.Create;
  TObj.GetArguments(ResultArguments);
  handleExceptionEnd
end;

procedure CefCommandLine_AppendArgument(const TObj: ICefCommandLine; const argument: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.AppendArgument(PCharToUStr(argument));
  handleExceptionEnd
end;

procedure CefCommandLine_PrependWrapper(const TObj: ICefCommandLine; const wrapper: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.PrependWrapper(PCharToUStr(wrapper));
  handleExceptionEnd
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
  CefCommandLine_PrependWrapper;