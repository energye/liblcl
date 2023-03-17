//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//CEFFrame_Undo
procedure CEFFrame_Undo(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Undo;
  handleExceptionEnd
end;

//CEFFrame_Redo
procedure CEFFrame_Redo(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Redo;
  handleExceptionEnd
end;

//CEFFrame_Cut
procedure CEFFrame_Cut(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Cut;
  handleExceptionEnd
end;

//CEFFrame_Copy
procedure CEFFrame_Copy(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Copy;
  handleExceptionEnd
end;

//CEFFrame_Paste
procedure CEFFrame_Paste(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Paste;
  handleExceptionEnd
end;

//CEFFrame_Del
procedure CEFFrame_Del(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.Del;
  handleExceptionEnd
end;

//CEFFrame_SelectAll
procedure CEFFrame_SelectAll(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.SelectAll;
  handleExceptionEnd
end;

//CEFFrame_ViewSource
procedure CEFFrame_ViewSource(const TObj: ICefFrame); extdecl;
begin
  handleExceptionBegin
  TObj.ViewSource;
  handleExceptionEnd
end;

//CEFFrame_LoadUrl
procedure CEFFrame_LoadUrl(const TObj: ICefFrame; PUrl: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.LoadUrl(PCharToUStr(PUrl));
  handleExceptionEnd
end;

//CEFFrame_ExecuteJavaScript
procedure CEFFrame_ExecuteJavaScript(const TObj: ICefFrame; const PCode, PScriptUrl: PChar; startLine: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.ExecuteJavaScript(PCharToUStr(PCode), PCharToUStr(PScriptUrl), startLine);
  handleExceptionEnd
end;

//CEFFrame_IsValid
function CEFFrame_IsValid(const TObj: ICefFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid;
  handleExceptionEnd
end;

//CEFFrame_IsMain
function CEFFrame_IsMain(const TObj: ICefFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsMain;
  handleExceptionEnd
end;

//CEFFrame_IsFocused
function CEFFrame_IsFocused(const TObj: ICefFrame): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsFocused;
  handleExceptionEnd
end;

//进程发送消息
procedure CEFFrame_SendProcessMessage(const TObj: ICefFrame; targetProcess: Integer; const message_: ICefProcessMessage); extdecl;
begin
  handleExceptionBegin
  TObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  handleExceptionEnd
end;

procedure CEFFrame_SendProcessMessageForJSONBytes(const AObj: ICefFrame; const PName: PChar; targetProcess: Integer; const data: Pointer; dataSize: NativeUInt); extdecl;
var
  message_ : ICefProcessMessage;
begin
  handleExceptionBegin
  message_ := TCefProcessMessageRef.New(PCharToUStr(PName));
  message_.ArgumentList.SetBinary(0, TCefBinaryValueRef.New(data, dataSize));
  AObj.SendProcessMessage(TCefProcessId(targetProcess), message_);
  message_.ArgumentList.Clear;
  handleExceptionEnd
end;

procedure CEFFrame_LoadRequest(const TObj: ICefFrame; const request: ICefRequest); extdecl;
begin
  handleExceptionBegin
  TObj.LoadRequest(request);
  handleExceptionEnd
end;

procedure CEFFrame_Browser(const TObj: ICefFrame; var Result: ICefBrowser); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Browser;
  handleExceptionEnd
end;

procedure CEFFrame_GetV8Context(const TObj: ICefFrame; var Result: ICefv8Context); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetV8Context;
  handleExceptionEnd
end;

procedure CEFFrame_Identifier(const TObj: ICefFrame; var Result: Int64); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Identifier;
  handleExceptionEnd
end;

function CEFFrame_Name(const TObj: ICefFrame): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Name));
  handleExceptionEnd
end;

function CEFFrame_Url(const TObj: ICefFrame): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Url));
  handleExceptionEnd
end;

procedure CEFFrame_Parent(const TObj: ICefFrame; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Parent;
  handleExceptionEnd
end;

procedure CEFFrameRef_UnWrap(const data: ICefFrame; var Result: ICefFrame); extdecl;
begin
  handleExceptionBegin
  Result := TCefFrameRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

{exports}
exports
  CEFFrame_Undo,
  CEFFrame_Redo,
  CEFFrame_Cut,
  CEFFrame_Copy,
  CEFFrame_Paste,
  CEFFrame_Del,
  CEFFrame_SelectAll,
  CEFFrame_ViewSource,
  CEFFrame_LoadUrl,
  CEFFrame_ExecuteJavaScript,
  CEFFrame_IsValid,
  CEFFrame_IsMain,
  CEFFrame_IsFocused,
  CEFFrame_SendProcessMessage,
  CEFFrame_SendProcessMessageForJSONBytes,
  CEFFrame_LoadRequest,
  CEFFrame_Browser,
  CEFFrame_GetV8Context,
  CEFFrame_Identifier,
  CEFFrame_Name,
  CEFFrame_Url,
  CEFFrame_Parent,
  CEFFrameRef_UnWrap
{end}
;

