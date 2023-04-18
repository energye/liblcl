//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== AudioHandler ==}
procedure CefAudioHandlerRef_Create(var Result: ICefAudioHandler); extdecl;
begin
  handleExceptionBegin
  Result := TAudioHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnGetAudioParameters(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.GetAudioParametersPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStarted(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamStartedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamPacket(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamPacketPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStopped(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamStoppedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamError(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamErrorPtr := AEventData;
end;

{== CommandHandler ==}
procedure CefCommandHandlerRef_Create(var Result: ICefCommandHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCommandHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefCommandHandler_OnChromeCommand(const AObj: TCommandHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ChromeCommandPtr := AEventData;
end;

{== ContextMenuHandler ==}
procedure CefContextMenuHandlerRef_Create(var Result: ICefContextMenuHandler); extdecl;
begin
  handleExceptionBegin
  Result := TContextMenuHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnBeforeContextMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforeContextMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_RunContextMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.RunContextMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_OnContextMenuCommand(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ContextMenuCommandPtr := AEventData;
end;

procedure CefContextMenuHandler_OnContextMenuDismissed(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ContextMenuDismissedPtr := AEventData;
end;

procedure CefContextMenuHandler_RunQuickMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.RunQuickMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_OnQuickMenuCommand(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.QuickMenuCommandPtr := AEventData;
end;

procedure CefContextMenuHandler_OnQuickMenuDismissed(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.QuickMenuDismissedPtr := AEventData;
end;

{== DialogHandler ==}
procedure CefDialogHandlerRef_Create(var Result: ICefDialogHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDialogHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDialogHandler_OnFileDialog(const AObj: TDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FileDialogPtr := AEventData;
end;

{== DisplayHandler ==}
procedure CefDisplayHandlerRef_Create(var Result: ICefDisplayHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDisplayHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnAddressChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AddressChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnTitleChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.TitleChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnFaviconUrlChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FaviconUrlChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnFullScreenModeChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FullScreenModeChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnTooltip(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.TooltipPtr := AEventData;
end;

procedure CefDisplayHandler_OnStatusMessage(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.StatusMessagePtr := AEventData;
end;

procedure CefDisplayHandler_OnConsoleMessage(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ConsoleMessagePtr := AEventData;
end;

procedure CefDisplayHandler_OnAutoResize(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AutoResizePtr := AEventData;
end;

procedure CefDisplayHandler_OnLoadingProgressChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.LoadingProgressChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnCursorChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.CursorChangePtr := AEventData;
end;

procedure CefDisplayHandler_OnMediaAccessChange(const AObj: TDisplayHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.MediaAccessChangePtr := AEventData;
end;

exports
  {== AudioHandler ==}
  CefAudioHandlerRef_Create,
  CefAudioHandler_OnGetAudioParameters,
  CefAudioHandler_OnAudioStreamStarted,
  CefAudioHandler_OnAudioStreamPacket,
  CefAudioHandler_OnAudioStreamStopped,
  CefAudioHandler_OnAudioStreamError,
  {== CommandHandler ==}
  CefCommandHandlerRef_Create,
  CefCommandHandler_OnChromeCommand,
  {== ContextMenuHandler ==}
  CefContextMenuHandlerRef_Create,
  CefContextMenuHandler_OnBeforeContextMenu,
  CefContextMenuHandler_RunContextMenu,
  CefContextMenuHandler_OnContextMenuCommand,
  CefContextMenuHandler_OnContextMenuDismissed,
  CefContextMenuHandler_RunQuickMenu,
  CefContextMenuHandler_OnQuickMenuCommand,
  CefContextMenuHandler_OnQuickMenuDismissed,
  {== DialogHandler ==}
  CefDialogHandlerRef_Create,
  CefDialogHandler_OnFileDialog,
  {== DisplayHandler ==}
  CefDisplayHandlerRef_Create,
  CefDisplayHandler_OnAddressChange,
  CefDisplayHandler_OnTitleChange,
  CefDisplayHandler_OnFaviconUrlChange,
  CefDisplayHandler_OnFullScreenModeChange,
  CefDisplayHandler_OnTooltip,
  CefDisplayHandler_OnStatusMessage,
  CefDisplayHandler_OnConsoleMessage,
  CefDisplayHandler_OnAutoResize,
  CefDisplayHandler_OnLoadingProgressChange,
  CefDisplayHandler_OnCursorChange,
  CefDisplayHandler_OnMediaAccessChange
;
