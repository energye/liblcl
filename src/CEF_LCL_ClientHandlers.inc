//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== AudioHandler ==}
procedure CefAudioHandlerRef_Create(var Result: TAudioHandlerRef); extdecl;
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
procedure CefCommandHandlerRef_Create(var Result: TCommandHandlerRef); extdecl;
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
procedure CefContextMenuHandlerRef_Create(var Result: TContextMenuHandlerRef); extdecl;
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
procedure CefDialogHandlerRef_Create(var Result: TDialogHandlerRef); extdecl;
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
procedure CefDisplayHandlerRef_Create(var Result: TDisplayHandlerRef); extdecl;
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

{== DownloadHandler ==}
procedure CefDownloadHandlerRef_Create(var Result: TDownloadHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TDownloadHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDownloadHandler_CanDownload(const AObj: TDownloadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.CanDownloadPtr := AEventData;
end;

procedure CefDownloadHandler_OnBeforeDownload(const AObj: TDownloadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforeDownloadPtr := AEventData;
end;

procedure CefDownloadHandler_OnDownloadUpdated(const AObj: TDownloadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DownloadUpdatedPtr := AEventData;
end;

{== DragHandler ==}
procedure CefDragHandlerRef_Create(var Result: TDragHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TDragHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDragHandler_OnDragEnter(const AObj: TDragHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DragEnterPtr := AEventData;
end;

procedure CefDragHandler_OnDraggableRegionsChanged(const AObj: TDragHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DraggableRegionsChangedPtr := AEventData;
end;

{== FindHandler ==}
procedure CefFindHandlerRef_Create(var Result: TFindHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TFindHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefFindHandler_OnFindResult(const AObj: TFindHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FindResultPtr := AEventData;
end;

{== FocusHandler ==}
procedure CefFocusHandlerRef_Create(var Result: TFocusHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TFocusHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefFocusHandler_OnTakeFocus(const AObj: TFocusHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.TakeFocusPtr := AEventData;
end;

procedure CefFocusHandler_OnSetFocus(const AObj: TFocusHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.SetFocusPtr := AEventData;
end;

procedure CefFocusHandler_OnGotFocus(const AObj: TFocusHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.GotFocusPtr := AEventData;
end;

{== FrameHandler ==}
procedure CefFrameHandlerRef_Create(var Result: TFrameHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TFrameHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefFrameHandler_OnFrameCreated(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FrameCreatedPtr := AEventData;
end;

procedure CefFrameHandler_OnFrameAttached(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FrameAttachedPtr := AEventData;
end;

procedure CefFrameHandler_OnFrameDetached(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FrameDetachedPtr := AEventData;
end;

procedure CefFrameHandler_OnMainFrameChanged(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.MainFrameChangedPtr := AEventData;
end;

{== PermissionHandler ==}
procedure CefPermissionHandlerRef_Create(var Result: TPermissionHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TPermissionHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefPermissionHandler_OnRequestMediaAccessPermission(const AObj: TPermissionHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.RequestMediaAccessPermissionPtr := AEventData;
end;

procedure CefPermissionHandler_OnShowPermissionPrompt(const AObj: TPermissionHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ShowPermissionPromptPtr := AEventData;
end;

procedure CefPermissionHandler_OnDismissPermissionPrompt(const AObj: TPermissionHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DismissPermissionPromptPtr := AEventData;
end;

{== JsDialogHandler ==}
procedure CefJsDialogHandlerRef_Create(var Result: TJsDialogHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TJsDialogHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefJsDialogHandler_OnJsdialog(const AObj: TJsDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.JsdialogPtr := AEventData;
end;

procedure CefJsDialogHandler_OnBeforeUnloadDialog(const AObj: TJsDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforeUnloadDialogPtr := AEventData;
end;

procedure CefJsDialogHandler_OnResetDialogState(const AObj: TJsDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ResetDialogStatePtr := AEventData;
end;

procedure CefJsDialogHandler_OnDialogClosed(const AObj: TJsDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DialogClosedPtr := AEventData;
end;

{== KeyboardHandler ==}
procedure CefKeyboardHandlerRef_Create(var Result: TKeyboardHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TKeyboardHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefKeyboardHandler_OnPreKeyEvent(const AObj: TKeyboardHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PreKeyEventPtr := AEventData;
end;

procedure CefKeyboardHandler_OnKeyEvent(const AObj: TKeyboardHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.KeyEventPtr := AEventData;
end;

{== LifeSpanHandler ==}
procedure CefLifeSpanHandlerRef_Create(var Result: TLifeSpanHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TLifeSpanHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefLifeSpanHandler_OnBeforePopup(const AObj: TLifeSpanHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforePopupPtr := AEventData;
end;

procedure CefLifeSpanHandler_OnAfterCreated(const AObj: TLifeSpanHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AfterCreatedPtr := AEventData;
end;

procedure CefLifeSpanHandler_DoClose(const AObj: TLifeSpanHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DoClosePtr := AEventData;
end;

procedure CefLifeSpanHandler_OnBeforeClose(const AObj: TLifeSpanHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforeClosePtr := AEventData;
end;

{== LoadHandler ==}
procedure CefLoadHandlerRef_Create(var Result: TLoadHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TLoadHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefLoadHandler_OnLoadingStateChange(const AObj: TLoadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.LoadingStateChangePtr := AEventData;
end;

procedure CefLoadHandler_OnLoadStart(const AObj: TLoadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.LoadStartPtr := AEventData;
end;

procedure CefLoadHandler_OnLoadEnd(const AObj: TLoadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.LoadEndPtr := AEventData;
end;

procedure CefLoadHandler_OnLoadError(const AObj: TLoadHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.LoadErrorPtr := AEventData;
end;

{== PrintHandler ==}
procedure CefPrintHandlerRef_Create(var Result: TPrintHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TPrintHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintStart(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PrintStartPtr := AEventData;
end;

procedure CefPrintHandler_OnPrintSettings(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PrintSettingsPtr := AEventData;
end;

procedure CefPrintHandler_OnPrintDialog(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PrintDialogPtr := AEventData;
end;

procedure CefPrintHandler_OnPrintJob(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PrintJobPtr := AEventData;
end;

procedure CefPrintHandler_OnPrintReset(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PrintResetPtr := AEventData;
end;

procedure CefPrintHandler_GetPDFPaperSize(const AObj: TPrintHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.PDFPaperSizePtr := AEventData;
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
  CefDisplayHandler_OnMediaAccessChange,
  {== DownloadHandler ==}
  CefDownloadHandlerRef_Create,
  CefDownloadHandler_CanDownload,
  CefDownloadHandler_OnBeforeDownload,
  CefDownloadHandler_OnDownloadUpdated,
  {== DragHandler ==}
  CefDragHandlerRef_Create,
  CefDragHandler_OnDragEnter,
  CefDragHandler_OnDraggableRegionsChanged,
  {== FindHandler ==}
  CefFindHandlerRef_Create,
  CefFindHandler_OnFindResult,
  {== FocusHandler ==}
  CefFocusHandlerRef_Create,
  CefFocusHandler_OnTakeFocus,
  CefFocusHandler_OnSetFocus,
  CefFocusHandler_OnGotFocus,
  {== FrameHandler ==}
  CefFrameHandlerRef_Create,
  CefFrameHandler_OnFrameCreated,
  CefFrameHandler_OnFrameAttached,
  CefFrameHandler_OnFrameDetached,
  CefFrameHandler_OnMainFrameChanged,
  {== PermissionHandler ==}
  CefPermissionHandlerRef_Create,
  CefPermissionHandler_OnRequestMediaAccessPermission,
  CefPermissionHandler_OnShowPermissionPrompt,
  CefPermissionHandler_OnDismissPermissionPrompt,
  {== JsDialogHandler ==}
  CefJsDialogHandlerRef_Create,
  CefJsDialogHandler_OnJsdialog,
  CefJsDialogHandler_OnBeforeUnloadDialog,
  CefJsDialogHandler_OnResetDialogState,
  CefJsDialogHandler_OnDialogClosed,
  {== KeyboardHandler ==}
  CefKeyboardHandlerRef_Create,
  CefKeyboardHandler_OnPreKeyEvent,
  CefKeyboardHandler_OnKeyEvent,
  {== LifeSpanHandler ==}
  CefLifeSpanHandlerRef_Create,
  CefLifeSpanHandler_OnBeforePopup,
  CefLifeSpanHandler_OnAfterCreated,
  CefLifeSpanHandler_DoClose,
  CefLifeSpanHandler_OnBeforeClose,
  {== LoadHandler ==}
  CefLoadHandlerRef_Create,
  CefLoadHandler_OnLoadingStateChange,
  CefLoadHandler_OnLoadStart,
  CefLoadHandler_OnLoadEnd,
  CefLoadHandler_OnLoadError,
  {== PrintHandler ==}
  CefPrintHandlerRef_Create,
  CefPrintHandler_OnPrintStart,
  CefPrintHandler_OnPrintSettings,
  CefPrintHandler_OnPrintDialog,
  CefPrintHandler_OnPrintJob,
  CefPrintHandler_OnPrintReset,
  CefPrintHandler_GetPDFPaperSize
;
