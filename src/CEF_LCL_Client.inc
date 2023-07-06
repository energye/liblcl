//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefClientRef_Create(var Result: ICefClient); extdecl;
begin
    Result := TClientRef.Create;
end;

procedure CefClientRef_CreateForChromium(const Chromium: TChromium; aDevToolsClient : boolean; var Result: ICefClient); extdecl;
begin
    Result := TCustomClientHandler.Create(Chromium, aDevToolsClient);
end;

procedure CefClient_GetAudioHandler(const TObj: ICefClient; var aHandler: ICefAudioHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetAudioHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetCommandHandler(const TObj: ICefClient); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetContextMenuHandler(const TObj: ICefClient; var aHandler: ICefContextMenuHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetContextMenuHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetDialogHandler(const TObj: ICefClient; var aHandler: ICefDialogHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetDialogHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetDisplayHandler(const TObj: ICefClient; var aHandler: ICefDisplayHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetDisplayHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetDownloadHandler(const TObj: ICefClient; var aHandler: ICefDownloadHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetDownloadHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetDragHandler(const TObj: ICefClient; var aHandler: ICefDragHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetDragHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetFindHandler(const TObj: ICefClient; var aHandler: ICefFindHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetFindHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetFocusHandler(const TObj: ICefClient; var aHandler: ICefFocusHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetFocusHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetFrameHandler(const TObj: ICefClient); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetPermissionHandler(const TObj: ICefClient); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetJsdialogHandler(const TObj: ICefClient; var aHandler: ICefJsdialogHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetJsdialogHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetKeyboardHandler(const TObj: ICefClient; var aHandler: ICefKeyboardHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetKeyboardHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetLifeSpanHandler(const TObj: ICefClient; var aHandler: ICefLifeSpanHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetLifeSpanHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetLoadHandler(const TObj: ICefClient; var aHandler: ICefLoadHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetLoadHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetPrintHandler(const TObj: ICefClient; var aHandler: ICefPrintHandler); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetRenderHandler(const TObj: ICefClient; var aHandler: ICefRenderHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetRenderHandler(aHandler);
    handleExceptionEnd
end;

procedure CefClient_GetRequestHandler(const TObj: ICefClient; var aHandler: ICefRequestHandler); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).GetRequestHandler(aHandler);
    handleExceptionEnd
end;

function CefClient_OnProcessMessageReceived(const TObj: ICefClient; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean; extdecl;
begin
    handleExceptionBegin
    Result := (TObj as TClientRef).OnProcessMessageReceived(browser, frame, sourceProcess, message_);
    handleExceptionEnd
end;

procedure CefClient_RemoveReferences(const TObj: ICefClient); extdecl;
begin
    handleExceptionBegin
    (TObj as TClientRef).RemoveReferences;
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
    CefClient_RemoveReferences
;
