//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefClientRef_Create(var Result: TClientRef); extdecl;
begin
    Result := TClientRef.Create;
end;

procedure CefClientRef_CreateForChromium(const Chromium: TChromium; aDevToolsClient : boolean; var Result: ICefClient); extdecl;
begin
    Result := TCustomClientHandler.Create(Chromium, aDevToolsClient);
end;

procedure CefClient_GetAudioHandler(const TObj: TClientRef; var aHandler: ICefAudioHandler); extdecl;
var
  TempHandler : ICefAudioHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetAudioHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetCommandHandler(const TObj: TClientRef); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetContextMenuHandler(const TObj: TClientRef; var aHandler: ICefContextMenuHandler); extdecl;
var
  TempHandler : ICefContextMenuHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetContextMenuHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDialogHandler(const TObj: TClientRef; var aHandler: ICefDialogHandler); extdecl;
var
  TempHandler : ICefDialogHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetDialogHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDisplayHandler(const TObj: TClientRef; var aHandler: ICefDisplayHandler); extdecl;
var
  TempHandler : ICefDisplayHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetDisplayHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDownloadHandler(const TObj: TClientRef; var aHandler: ICefDownloadHandler); extdecl;
var
  TempHandler : ICefDownloadHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetDownloadHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDragHandler(const TObj: TClientRef; var aHandler: ICefDragHandler); extdecl;
var
  TempHandler : ICefDragHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetDragHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFindHandler(const TObj: TClientRef; var aHandler: ICefFindHandler); extdecl;
var
  TempHandler : ICefFindHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetFindHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFocusHandler(const TObj: TClientRef; var aHandler: ICefFocusHandler); extdecl;
var
  TempHandler : ICefFocusHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetFocusHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFrameHandler(const TObj: TClientRef); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetPermissionHandler(const TObj: TClientRef); extdecl;
begin
    handleExceptionBegin
    handleExceptionEnd
end;

procedure CefClient_GetJsdialogHandler(const TObj: TClientRef; var aHandler: ICefJsdialogHandler); extdecl;
var
  TempHandler : ICefJsdialogHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetJsdialogHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetKeyboardHandler(const TObj: TClientRef; var aHandler: ICefKeyboardHandler); extdecl;
var
  TempHandler : ICefKeyboardHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetKeyboardHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetLifeSpanHandler(const TObj: TClientRef; var aHandler: ICefLifeSpanHandler); extdecl;
var
  TempHandler : ICefLifeSpanHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetLifeSpanHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetLoadHandler(const TObj: TClientRef; var aHandler: ICefLoadHandler); extdecl;
var
  TempHandler : ICefLoadHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetLoadHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetPrintHandler(const TObj: TClientRef; var aHandler: ICefPrintHandler); extdecl;
var
  TempHandler : ICefPrintHandler;
begin
    handleExceptionBegin
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetRenderHandler(const TObj: TClientRef; var aHandler: ICefRenderHandler); extdecl;
var
  TempHandler : ICefRenderHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetRenderHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetRequestHandler(const TObj: TClientRef; var aHandler: ICefRequestHandler); extdecl;
var
  TempHandler : ICefRequestHandler;
begin
    handleExceptionBegin
    ICefClient(TObj).GetRequestHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

function CefClient_OnProcessMessageReceived(const TObj: TClientRef; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean; extdecl;
begin
    handleExceptionBegin
    Result := ICefClient(TObj).OnProcessMessageReceived(browser, frame, sourceProcess, message_);
    handleExceptionEnd
end;

procedure CefClient_RemoveReferences(const TObj: TClientRef); extdecl;
begin
    handleExceptionBegin
    ICefClient(TObj).RemoveReferences;
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
