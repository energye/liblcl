//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefClientRef_Create(var Result: ICefClient); extdecl;
begin
  handleExceptionBegin
  Result := TClientRef.Create;
  handleExceptionEnd
end;

procedure CefClientRef_CreateForChromium(const Chromium: TChromium; aDevToolsClient : boolean; var Result: ICefClient); extdecl;
begin
  handleExceptionBegin
  Result := TCustomClientHandler.Create(Chromium, aDevToolsClient);
  handleExceptionEnd
end;

procedure CefClient_GetAudioHandler(const TObj: ICefClient; var aHandler: ICefAudioHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetAudioHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetCommandHandler(const TObj: ICefClient; var aHandler: ICefCommandHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetCommandHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetContextMenuHandler(const TObj: ICefClient; var aHandler: ICefContextMenuHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetContextMenuHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetDialogHandler(const TObj: ICefClient; var aHandler: ICefDialogHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetDialogHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetDisplayHandler(const TObj: ICefClient; var aHandler: ICefDisplayHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetDisplayHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetDownloadHandler(const TObj: ICefClient; var aHandler: ICefDownloadHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetDownloadHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetDragHandler(const TObj: ICefClient; var aHandler: ICefDragHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetDragHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetFindHandler(const TObj: ICefClient; var aHandler: ICefFindHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetFindHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetFocusHandler(const TObj: ICefClient; var aHandler: ICefFocusHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetFocusHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetFrameHandler(const TObj: ICefClient; var aHandler: ICefFrameHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetFrameHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetPermissionHandler(const TObj: ICefClient; var aHandler: ICefPermissionHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetPermissionHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetJsdialogHandler(const TObj: ICefClient; var aHandler: ICefJsdialogHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetJsdialogHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetKeyboardHandler(const TObj: ICefClient; var aHandler: ICefKeyboardHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetKeyboardHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetLifeSpanHandler(const TObj: ICefClient; var aHandler: ICefLifeSpanHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetLifeSpanHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetLoadHandler(const TObj: ICefClient; var aHandler: ICefLoadHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetLoadHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetPrintHandler(const TObj: ICefClient; var aHandler: ICefPrintHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetPrintHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetRenderHandler(const TObj: ICefClient; var aHandler: ICefRenderHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetRenderHandler(aHandler);
  end;
  handleExceptionEnd
end;

procedure CefClient_GetRequestHandler(const TObj: ICefClient; var aHandler: ICefRequestHandler); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).GetRequestHandler(aHandler);
  end;
  handleExceptionEnd
end;

function CefClient_OnProcessMessageReceived(const TObj: ICefClient; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean; extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    Result := (TObj as TClientRef).OnProcessMessageReceived(browser, frame, sourceProcess, message_);
  end;
  handleExceptionEnd
end;

procedure CefClient_RemoveReferences(const TObj: ICefClient); extdecl;
begin
  handleExceptionBegin
  if TObj is TClientRef then
  begin
    (TObj as TClientRef).RemoveReferences;
  end;
  handleExceptionEnd
end;

exports
  CefClientRef_Create,
  CefClientRef_CreateForChromium,
  CefClient_GetAudioHandler,
  CefClient_GetCommandHandler,
  CefClient_GetContextMenuHandler,
  CefClient_GetDialogHandler,
  CefClient_GetDisplayHandler,
  CefClient_GetDownloadHandler,
  CefClient_GetDragHandler,
  CefClient_GetFindHandler,
  CefClient_GetFocusHandler,
  CefClient_GetFrameHandler,
  CefClient_GetPermissionHandler,
  CefClient_GetJsdialogHandler,
  CefClient_GetKeyboardHandler,
  CefClient_GetLifeSpanHandler,
  CefClient_GetLoadHandler,
  CefClient_GetPrintHandler,
  CefClient_GetRenderHandler,
  CefClient_GetRequestHandler,
  CefClient_OnProcessMessageReceived,
  CefClient_RemoveReferences;
