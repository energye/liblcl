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

procedure CefAudioHandler_OnGetAudioParameters(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TAudioHandlerRef).GetAudioParametersPtr := AEventData;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnAudioStreamStarted(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TAudioHandlerRef).AudioStreamStartedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnAudioStreamPacket(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TAudioHandlerRef).AudioStreamPacketPtr := AEventData;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnAudioStreamStopped(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TAudioHandlerRef).AudioStreamStoppedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnAudioStreamError(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TAudioHandlerRef).AudioStreamErrorPtr := AEventData;
  handleExceptionEnd
end;

{== CommandHandler ==}
procedure CefCommandHandlerRef_Create(var Result: TCommandHandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TCommandHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefCommandHandler_OnChromeCommand(const AObj: ICefCommandHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TCommandHandlerRef).ChromeCommandPtr := AEventData;
  handleExceptionEnd
end;

{== ContextMenuHandler ==}
procedure CefContextMenuHandlerRef_Create(var Result: ICefContextMenuHandler); extdecl;
begin
  handleExceptionBegin
  Result := TContextMenuHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnBeforeContextMenu(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).BeforeContextMenuPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_RunContextMenu(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).RunContextMenuPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnContextMenuCommand(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).ContextMenuCommandPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnContextMenuDismissed(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).ContextMenuDismissedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_RunQuickMenu(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).RunQuickMenuPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnQuickMenuCommand(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).QuickMenuCommandPtr := AEventData;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnQuickMenuDismissed(const AObj: ICefContextMenuHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TContextMenuHandlerRef).QuickMenuDismissedPtr := AEventData;
  handleExceptionEnd
end;

{== DialogHandler ==}
procedure CefDialogHandlerRef_Create(var Result: ICefDialogHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDialogHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDialogHandler_OnFileDialog(const AObj: ICefDialogHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDialogHandlerRef).FileDialogPtr := AEventData;
  handleExceptionEnd
end;

{== DisplayHandler ==}
procedure CefDisplayHandlerRef_Create(var Result: ICefDisplayHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDisplayHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnAddressChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).AddressChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnTitleChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).TitleChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnFaviconUrlChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).FaviconUrlChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnFullScreenModeChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).FullScreenModeChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnTooltip(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).TooltipPtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnStatusMessage(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).StatusMessagePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnConsoleMessage(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).ConsoleMessagePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnAutoResize(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).AutoResizePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnLoadingProgressChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).LoadingProgressChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnCursorChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).CursorChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefDisplayHandler_OnMediaAccessChange(const AObj: ICefDisplayHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDisplayHandlerRef).MediaAccessChangePtr := AEventData;
  handleExceptionEnd
end;

{== DownloadHandler ==}
procedure CefDownloadHandlerRef_Create(var Result: ICefDownloadHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDownloadHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDownloadHandler_CanDownload(const AObj: ICefDownloadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDownloadHandlerRef).CanDownloadPtr := AEventData;
  handleExceptionEnd
end;

procedure CefDownloadHandler_OnBeforeDownload(const AObj: ICefDownloadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDownloadHandlerRef).BeforeDownloadPtr := AEventData;
  handleExceptionEnd
end;

procedure CefDownloadHandler_OnDownloadUpdated(const AObj: ICefDownloadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDownloadHandlerRef).DownloadUpdatedPtr := AEventData;
  handleExceptionEnd
end;

{== DragHandler ==}
procedure CefDragHandlerRef_Create(var Result: ICefDragHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDragHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDragHandler_OnDragEnter(const AObj: ICefDragHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDragHandlerRef).DragEnterPtr := AEventData;
  handleExceptionEnd
end;

procedure CefDragHandler_OnDraggableRegionsChanged(const AObj: ICefDragHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDragHandlerRef).DraggableRegionsChangedPtr := AEventData;
  handleExceptionEnd
end;

{== FindHandler ==}
procedure CefFindHandlerRef_Create(var Result: ICefFindHandler); extdecl;
begin
  handleExceptionBegin
  Result := TFindHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefFindHandler_OnFindResult(const AObj: ICefFindHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TFindHandlerRef).FindResultPtr := AEventData;
  handleExceptionEnd
end;

{== FocusHandler ==}
procedure CefFocusHandlerRef_Create(var Result: ICefFocusHandler); extdecl;
begin
  handleExceptionBegin
  Result := TFocusHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefFocusHandler_OnTakeFocus(const AObj: ICefFocusHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TFocusHandlerRef).TakeFocusPtr := AEventData;
  handleExceptionEnd
end;

procedure CefFocusHandler_OnSetFocus(const AObj: ICefFocusHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TFocusHandlerRef).SetFocusPtr := AEventData;
  handleExceptionEnd
end;

procedure CefFocusHandler_OnGotFocus(const AObj: ICefFocusHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TFocusHandlerRef).GotFocusPtr := AEventData;
  handleExceptionEnd
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
  handleExceptionBegin
  AObj.FrameCreatedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefFrameHandler_OnFrameAttached(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.FrameAttachedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefFrameHandler_OnFrameDetached(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.FrameDetachedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefFrameHandler_OnMainFrameChanged(const AObj: TFrameHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.MainFrameChangedPtr := AEventData;
  handleExceptionEnd
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
  handleExceptionBegin
  AObj.RequestMediaAccessPermissionPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPermissionHandler_OnShowPermissionPrompt(const AObj: TPermissionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.ShowPermissionPromptPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPermissionHandler_OnDismissPermissionPrompt(const AObj: TPermissionHandlerRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.DismissPermissionPromptPtr := AEventData;
  handleExceptionEnd
end;

{== JsDialogHandler ==}
procedure CefJsDialogHandlerRef_Create(var Result: ICefJsDialogHandler); extdecl;
begin
  handleExceptionBegin
  Result := TJsDialogHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefJsDialogHandler_OnJsdialog(const AObj: ICefJsDialogHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TJsDialogHandlerRef).JsdialogPtr := AEventData;
  handleExceptionEnd
end;

procedure CefJsDialogHandler_OnBeforeUnloadDialog(const AObj: ICefJsDialogHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TJsDialogHandlerRef).BeforeUnloadDialogPtr := AEventData;
  handleExceptionEnd
end;

procedure CefJsDialogHandler_OnResetDialogState(const AObj: ICefJsDialogHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TJsDialogHandlerRef).ResetDialogStatePtr := AEventData;
  handleExceptionEnd
end;

procedure CefJsDialogHandler_OnDialogClosed(const AObj: ICefJsDialogHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TJsDialogHandlerRef).DialogClosedPtr := AEventData;
  handleExceptionEnd
end;

{== KeyboardHandler ==}
procedure CefKeyboardHandlerRef_Create(var Result: ICefKeyboardHandler); extdecl;
begin
  handleExceptionBegin
  Result := TKeyboardHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefKeyboardHandler_OnPreKeyEvent(const AObj: ICefKeyboardHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TKeyboardHandlerRef).PreKeyEventPtr := AEventData;
  handleExceptionEnd
end;

procedure CefKeyboardHandler_OnKeyEvent(const AObj: ICefKeyboardHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TKeyboardHandlerRef).KeyEventPtr := AEventData;
  handleExceptionEnd
end;

{== LifeSpanHandler ==}
procedure CefLifeSpanHandlerRef_Create(var Result: ICefLifeSpanHandler); extdecl;
begin
  handleExceptionBegin
  Result := TLifeSpanHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefLifeSpanHandler_OnBeforePopup(const AObj: ICefLifeSpanHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLifeSpanHandlerRef).BeforePopupPtr := AEventData;
  handleExceptionEnd
end;

procedure CefLifeSpanHandler_OnAfterCreated(const AObj: ICefLifeSpanHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLifeSpanHandlerRef).AfterCreatedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefLifeSpanHandler_DoClose(const AObj: ICefLifeSpanHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLifeSpanHandlerRef).DoClosePtr := AEventData;
  handleExceptionEnd
end;

procedure CefLifeSpanHandler_OnBeforeClose(const AObj: ICefLifeSpanHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLifeSpanHandlerRef).BeforeClosePtr := AEventData;
  handleExceptionEnd
end;

{== LoadHandler ==}
procedure CefLoadHandlerRef_Create(var Result: ICefLoadHandler); extdecl;
begin
  handleExceptionBegin
  Result := TLoadHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefLoadHandler_OnLoadingStateChange(const AObj: ICefLoadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLoadHandlerRef).LoadingStateChangePtr := AEventData;
  handleExceptionEnd
end;

procedure CefLoadHandler_OnLoadStart(const AObj: ICefLoadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLoadHandlerRef).LoadStartPtr := AEventData;
  handleExceptionEnd
end;

procedure CefLoadHandler_OnLoadEnd(const AObj: ICefLoadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLoadHandlerRef).LoadEndPtr := AEventData;
  handleExceptionEnd
end;

procedure CefLoadHandler_OnLoadError(const AObj: ICefLoadHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TLoadHandlerRef).LoadErrorPtr := AEventData;
  handleExceptionEnd
end;

{== PrintHandler ==}
procedure CefPrintHandlerRef_Create(var Result: ICefPrintHandler); extdecl;
begin
  handleExceptionBegin
  Result := TPrintHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintStart(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PrintStartPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintSettings(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PrintSettingsPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintDialog(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PrintDialogPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintJob(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PrintJobPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPrintHandler_OnPrintReset(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PrintResetPtr := AEventData;
  handleExceptionEnd
end;

procedure CefPrintHandler_GetPDFPaperSize(const AObj: ICefPrintHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TPrintHandlerRef).PDFPaperSizePtr := AEventData;
  handleExceptionEnd
end;

{== RenderHandler ==}
procedure CefRenderHandlerRef_Create(var Result: ICefRenderHandler); extdecl;
begin
  handleExceptionBegin
  Result := TRenderHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetAccessibilityHandler(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).AccessibilityHandlerPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetRootScreenRect(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).RootScreenRectPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetViewRect(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).ViewRectPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetScreenPoint(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).ScreenPointPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetScreenInfo(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).ScreenInfoPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnPopupShow(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).PopupShowPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnPopupSize(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).PopupSizePtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnPaint(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).PaintPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnAcceleratedPaint(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).AcceleratedPaintPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_GetTouchHandleSize(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).TouchHandleSizePtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnTouchHandleStateChanged(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).TouchHandleStateChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnStartDragging(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).StartDraggingPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnUpdateDragCursor(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).UpdateDragCursorPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnScrollOffsetChanged(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).ScrollOffsetChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnIMECompositionRangeChanged(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).IMECompositionRangeChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnTextSelectionChanged(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).TextSelectionChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRenderHandler_OnVirtualKeyboardRequested(const AObj: ICefRenderHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRenderHandlerRef).VirtualKeyboardRequestedPtr := AEventData;
  handleExceptionEnd
end;

{== RequestHandler ==}
procedure CefRequestHandlerRef_Create(var Result: ICefRequestHandler); extdecl;
begin
  handleExceptionBegin
  Result := TRequestHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnBeforeBrowse(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).BeforeBrowsePtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnOpenUrlFromTab(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).OpenUrlFromTabPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_GetResourceRequestHandler(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).GetResourceRequestHandlerPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_GetAuthCredentials(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).GetAuthCredentialsPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnCertificateError(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).CertificateErrorPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnSelectClientCertificate(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).SelectClientCertificatePtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnRenderViewReady(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).RenderViewReadyPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnRenderProcessTerminated(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).RenderProcessTerminatedPtr := AEventData;
  handleExceptionEnd
end;

procedure CefRequestHandler_OnDocumentAvailableInMainFrame(const AObj: ICefRequestHandler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TRequestHandlerRef).DocumentAvailableInMainFramePtr := AEventData;
  handleExceptionEnd
end;

exports
  CefAudioHandlerRef_Create,
  CefAudioHandler_OnGetAudioParameters,
  CefAudioHandler_OnAudioStreamStarted,
  CefAudioHandler_OnAudioStreamPacket,
  CefAudioHandler_OnAudioStreamStopped,
  CefAudioHandler_OnAudioStreamError,
  CefCommandHandlerRef_Create,
  CefCommandHandler_OnChromeCommand,
  CefContextMenuHandlerRef_Create,
  CefContextMenuHandler_OnBeforeContextMenu,
  CefContextMenuHandler_RunContextMenu,
  CefContextMenuHandler_OnContextMenuCommand,
  CefContextMenuHandler_OnContextMenuDismissed,
  CefContextMenuHandler_RunQuickMenu,
  CefContextMenuHandler_OnQuickMenuCommand,
  CefContextMenuHandler_OnQuickMenuDismissed,
  CefDialogHandlerRef_Create,
  CefDialogHandler_OnFileDialog,
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
  CefDownloadHandlerRef_Create,
  CefDownloadHandler_CanDownload,
  CefDownloadHandler_OnBeforeDownload,
  CefDownloadHandler_OnDownloadUpdated,
  CefDragHandlerRef_Create,
  CefDragHandler_OnDragEnter,
  CefDragHandler_OnDraggableRegionsChanged,
  CefFindHandlerRef_Create,
  CefFindHandler_OnFindResult,
  CefFocusHandlerRef_Create,
  CefFocusHandler_OnTakeFocus,
  CefFocusHandler_OnSetFocus,
  CefFocusHandler_OnGotFocus,
  CefFrameHandlerRef_Create,
  CefFrameHandler_OnFrameCreated,
  CefFrameHandler_OnFrameAttached,
  CefFrameHandler_OnFrameDetached,
  CefFrameHandler_OnMainFrameChanged,
  CefPermissionHandlerRef_Create,
  CefPermissionHandler_OnRequestMediaAccessPermission,
  CefPermissionHandler_OnShowPermissionPrompt,
  CefPermissionHandler_OnDismissPermissionPrompt,
  CefJsDialogHandlerRef_Create,
  CefJsDialogHandler_OnJsdialog,
  CefJsDialogHandler_OnBeforeUnloadDialog,
  CefJsDialogHandler_OnResetDialogState,
  CefJsDialogHandler_OnDialogClosed,
  CefKeyboardHandlerRef_Create,
  CefKeyboardHandler_OnPreKeyEvent,
  CefKeyboardHandler_OnKeyEvent,
  CefLifeSpanHandlerRef_Create,
  CefLifeSpanHandler_OnBeforePopup,
  CefLifeSpanHandler_OnAfterCreated,
  CefLifeSpanHandler_DoClose,
  CefLifeSpanHandler_OnBeforeClose,
  CefLoadHandlerRef_Create,
  CefLoadHandler_OnLoadingStateChange,
  CefLoadHandler_OnLoadStart,
  CefLoadHandler_OnLoadEnd,
  CefLoadHandler_OnLoadError,
  CefPrintHandlerRef_Create,
  CefPrintHandler_OnPrintStart,
  CefPrintHandler_OnPrintSettings,
  CefPrintHandler_OnPrintDialog,
  CefPrintHandler_OnPrintJob,
  CefPrintHandler_OnPrintReset,
  CefPrintHandler_GetPDFPaperSize,
  CefRenderHandlerRef_Create,
  CefRenderHandler_GetAccessibilityHandler,
  CefRenderHandler_GetRootScreenRect,
  CefRenderHandler_GetViewRect,
  CefRenderHandler_GetScreenPoint,
  CefRenderHandler_GetScreenInfo,
  CefRenderHandler_OnPopupShow,
  CefRenderHandler_OnPopupSize,
  CefRenderHandler_OnPaint,
  CefRenderHandler_OnAcceleratedPaint,
  CefRenderHandler_GetTouchHandleSize,
  CefRenderHandler_OnTouchHandleStateChanged,
  CefRenderHandler_OnStartDragging,
  CefRenderHandler_OnUpdateDragCursor,
  CefRenderHandler_OnScrollOffsetChanged,
  CefRenderHandler_OnIMECompositionRangeChanged,
  CefRenderHandler_OnTextSelectionChanged,
  CefRenderHandler_OnVirtualKeyboardRequested,
  CefRequestHandlerRef_Create,
  CefRequestHandler_OnBeforeBrowse,
  CefRequestHandler_OnOpenUrlFromTab,
  CefRequestHandler_GetResourceRequestHandler,
  CefRequestHandler_GetAuthCredentials,
  CefRequestHandler_OnCertificateError,
  CefRequestHandler_OnSelectClientCertificate,
  CefRequestHandler_OnRenderViewReady,
  CefRequestHandler_OnRenderProcessTerminated,
  CefRequestHandler_OnDocumentAvailableInMainFrame;
