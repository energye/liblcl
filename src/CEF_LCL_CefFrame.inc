//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//CEFFrame_Undo
procedure CEFFrame_Undo(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Undo;
  end;
  handleExceptionEnd
end;

//CEFFrame_Redo
procedure CEFFrame_Redo(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Redo;
  end;
  handleExceptionEnd
end;

//CEFFrame_Cut
procedure CEFFrame_Cut(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Cut;
  end;
  handleExceptionEnd
end;

//CEFFrame_Copy
procedure CEFFrame_Copy(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Copy;
  end;
  handleExceptionEnd
end;

//CEFFrame_Paste
procedure CEFFrame_Paste(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Paste;
  end;
  handleExceptionEnd
end;

//CEFFrame_Del
procedure CEFFrame_Del(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.Del;
  end;
  handleExceptionEnd
end;

//CEFFrame_SelectAll
procedure CEFFrame_SelectAll(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.SelectAll;
  end;
  handleExceptionEnd
end;

//CEFFrame_ViewSource
procedure CEFFrame_ViewSource(browserId: Integer; FrameId: PInt64); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.ViewSource;
  end;
  handleExceptionEnd
end;

//CEFFrame_LoadUrl
procedure CEFFrame_LoadUrl(browserId: Integer; FrameId: PInt64; PUrl: PChar); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.LoadUrl(PCharToUStr(PUrl));
  end;
  handleExceptionEnd
end;

//CEFFrame_ExecuteJavaScript
procedure CEFFrame_ExecuteJavaScript(browserId: Integer; FrameId: PInt64; code, scriptUrl: PChar; startLine: Integer); extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    frame.ExecuteJavaScript(PCharToUStr(code), PCharToUStr(scriptUrl), startLine);
  end;
  handleExceptionEnd
end;

//CEFFrame_IsValid
function CEFFrame_IsValid(browserId: Integer; FrameId: PInt64): Boolean; extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  //ConsoleLn('CEFFrame_IsValid browserId: '+IntToStr(browserId)+'  FrameId: '+IntToStr(FrameId^));
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    Result := frame.IsValid;
  end
  else
    Result := False;
  handleExceptionEnd
end;

//CEFFrame_IsMain
function CEFFrame_IsMain(browserId: Integer; FrameId: PInt64): Boolean; extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  //ConsoleLn('CEFFrame_IsMain: ' + IntToStr(browserId) + '  FrameId: ' +IntToStr(FrameId^));
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    Result := frame.IsMain;
  end
  else
    Result := False;
  handleExceptionEnd
end;

//CEFFrame_IsFocused
function CEFFrame_IsFocused(browserId: Integer; FrameId: PInt64): Boolean; extdecl;
var
  frame: ICefFrame;
begin
  handleExceptionBegin
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    Result := frame.IsFocused;
  end
  else
    Result := False;
  handleExceptionEnd
end;

//进程发送消息
{$ifdef DARWIN}
function CEFFrame_SendProcessMessage(browserId: Integer; FrameId: PInt64; const PName: PChar; targetProcess, ItemLength: integer; const arguments: array of Byte; argumentsLength: integer): integer ; extdecl;
var
  args: array of Byte;
{$else}
function CEFFrame_SendProcessMessage(browserId: Integer; FrameId: PInt64; const PName: PChar; targetProcess, ItemLength: integer; const arguments: array of Byte): integer; stdcall;
{$endif}
var
  Name: string;
  frame: ICefFrame;
  processMessage: ICefProcessMessage;
  binaryValue: ICefBinaryValue;
begin
  handleExceptionBegin
  Name := string(PCharToUstr(PName));
  if (Name = '') then
  begin
    Result := -3; //消息名为空
    exit;
  end;
  //ConsoleLn('SendProcessMessage BrowserId: '+ IntToStr(browserId) + '  FrameId: ' + IntToStr(FrameId^) + '  Name: ' + Name +'  targetProcess: ' + IntToStr(targetProcess) + '  ItemLength: '+ IntToStr(ItemLength));
  if (TCefProcessId(targetProcess) <> PID_BROWSER) and (TCefProcessId(targetProcess) <> PID_RENDERER) then
  begin
    Result := -2; //消息目标进程不正确
    exit;
  end;
  frame := TMainChromiumBrowserClass.GetFrameById(browserId, FrameId^);
  if frame <> nil then
  begin
    if frame.IsValid then
    begin
      processMessage := TCefProcessMessageRef.New(StrToUStr(Name));
      {$ifdef DARWIN}
      binaryValue := TCefBinaryValueRef.New(@arguments[0], argumentsLength);
      processMessage.ArgumentList.SetInt(0, argumentsLength);
      {$else}
      binaryValue := TCefBinaryValueRef.New(@arguments[0], High(arguments));
      processMessage.ArgumentList.SetInt(0, High(arguments));
      {$endif}
      processMessage.ArgumentList.SetInt(1, ItemLength);
      processMessage.ArgumentList.SetBinary(2, binaryValue);
      frame.SendProcessMessage(TCefProcessId(targetProcess), processMessage);
      processMessage.ArgumentList.Clear;
      processMessage := nil;
      Result := 1;//成功
    end
    else
    begin
      Result := -4;//无效的Frame
    end;
  end
  else
  begin
    Result := -1;//未找到frame
  end;
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
  CEFFrame_SendProcessMessage
{end}
;

