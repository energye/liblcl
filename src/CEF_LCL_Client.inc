//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefClientRef_Create(var Result: ICefClient); extdecl;
begin
    Result := TClientRef.Create;
end;

procedure CefClient_GetAudioHandler(const TObj: ICefClient; var aHandler: ICefAudioHandler); extdecl;
var
  TempHandler : ICefAudioHandler;
begin
    handleExceptionBegin
    TObj.GetAudioHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetCommandHandler(const TObj: ICefClient; var aHandler: ICefCommandHandler); extdecl;
var
  TempHandler : ICefCommandHandler;
begin
    handleExceptionBegin
    TObj.GetCommandHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetContextMenuHandler(const TObj: ICefClient; var aHandler: ICefContextMenuHandler); extdecl;
var
  TempHandler : ICefContextMenuHandler;
begin
    handleExceptionBegin
    TObj.GetContextMenuHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDialogHandler(const TObj: ICefClient; var aHandler: ICefDialogHandler); extdecl;
var
  TempHandler : ICefDialogHandler;
begin
    handleExceptionBegin
    TObj.GetDialogHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDisplayHandler(const TObj: ICefClient; var aHandler: ICefDisplayHandler); extdecl;
var
  TempHandler : ICefDisplayHandler;
begin
    handleExceptionBegin
    TObj.GetDisplayHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDownloadHandler(const TObj: ICefClient; var aHandler: ICefDownloadHandler); extdecl;
var
  TempHandler : ICefDownloadHandler;
begin
    handleExceptionBegin
    TObj.GetDownloadHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetDragHandler(const TObj: ICefClient; var aHandler: ICefDragHandler); extdecl;
var
  TempHandler : ICefDragHandler;
begin
    handleExceptionBegin
    TObj.GetDragHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFindHandler(const TObj: ICefClient; var aHandler: ICefFindHandler); extdecl;
var
  TempHandler : ICefFindHandler;
begin
    handleExceptionBegin
    TObj.GetFindHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFocusHandler(const TObj: ICefClient; var aHandler: ICefFocusHandler); extdecl;
var
  TempHandler : ICefFocusHandler;
begin
    handleExceptionBegin
    TObj.GetFocusHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetFrameHandler(const TObj: ICefClient; var aHandler: ICefFrameHandler); extdecl;
var
  TempHandler : ICefFrameHandler;
begin
    handleExceptionBegin
    TObj.GetFrameHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetPermissionHandler(const TObj: ICefClient; var aHandler: ICefPermissionHandler); extdecl;
var
  TempHandler : ICefPermissionHandler;
begin
    handleExceptionBegin
    TObj.GetPermissionHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetJsdialogHandler(const TObj: ICefClient; var aHandler: ICefJsdialogHandler); extdecl;
var
  TempHandler : ICefJsdialogHandler;
begin
    handleExceptionBegin
    TObj.GetJsdialogHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetKeyboardHandler(const TObj: ICefClient; var aHandler: ICefKeyboardHandler); extdecl;
var
  TempHandler : ICefKeyboardHandler;
begin
    handleExceptionBegin
    TObj.GetKeyboardHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetLifeSpanHandler(const TObj: ICefClient; var aHandler: ICefLifeSpanHandler); extdecl;
var
  TempHandler : ICefLifeSpanHandler;
begin
    handleExceptionBegin
    TObj.GetLifeSpanHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetLoadHandler(const TObj: ICefClient; var aHandler: ICefLoadHandler); extdecl;
var
  TempHandler : ICefLoadHandler;
begin
    handleExceptionBegin
    TObj.GetLoadHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetPrintHandler(const TObj: ICefClient; var aHandler: ICefPrintHandler); extdecl;
var
  TempHandler : ICefPrintHandler;
begin
    handleExceptionBegin
    TObj.GetPrintHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetRenderHandler(const TObj: ICefClient; var aHandler: ICefRenderHandler); extdecl;
var
  TempHandler : ICefRenderHandler;
begin
    handleExceptionBegin
    TObj.GetRenderHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

procedure CefClient_GetRequestHandler(const TObj: ICefClient; var aHandler: ICefRequestHandler); extdecl;
var
  TempHandler : ICefRequestHandler;
begin
    handleExceptionBegin
    TObj.GetRequestHandler(TempHandler);
    aHandler := TempHandler;
    handleExceptionEnd
end;

function CefClient_OnProcessMessageReceived(const TObj: ICefClient; const browser: ICefBrowser; const frame: ICefFrame; sourceProcess: TCefProcessId; const message_: ICefProcessMessage): boolean; extdecl;
begin
    handleExceptionBegin
    Result := TObj.OnProcessMessageReceived(browser, frame, sourceProcess, message_);
    handleExceptionEnd
end;

procedure CefClient_RemoveReferences(const TObj: ICefClient); extdecl;
begin
    handleExceptionBegin
    TObj.RemoveReferences;
    handleExceptionEnd
end;

exports
    CefClientRef_Create,
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
