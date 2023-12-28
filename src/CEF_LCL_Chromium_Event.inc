//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{====== events ======}
procedure CEFChromium_SetOnCookiesDeleted(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesDeleted}
  {$DEFINE EventName := OnCookiesDeleted}
  EventMethodCode
end;

procedure CEFChromium_SetOnAfterCreated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAfterCreated}
  {$DEFINE EventName := OnAfterCreated}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeBrowse(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeBrowse}
  {$DEFINE EventName := OnBeforeBrowse}
  EventMethodCode
end;

procedure CEFChromium_SetOnAddressChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAddressChange}
  {$DEFINE EventName := OnAddressChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeClose(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeClose}
  {$DEFINE EventName := OnBeforeClose}
  EventMethodCode
end;

procedure CEFChromium_SetOnClose(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnClose}
  {$DEFINE EventName := OnClose}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeContextMenu(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeContextMenu}
  {$DEFINE EventName := OnBeforeContextMenu}
  EventMethodCode
end;

procedure CEFChromium_SetOnContextMenuCommand(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuCommand}
  {$DEFINE EventName := OnContextMenuCommand}
  EventMethodCode
end;

procedure CEFChromium_SetOnContextMenuDismissed(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuDismissed}
  {$DEFINE EventName := OnContextMenuDismissed}
  EventMethodCode
end;

procedure CEFChromium_SetOnPdfPrintFinished(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPdfPrintFinished}
  {$DEFINE EventName := OnPdfPrintFinished}
  EventMethodCode
end;

procedure CEFChromium_SetOnLoadStart(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadStart}
  {$DEFINE EventName := OnLoadStart}
  EventMethodCode
end;

procedure CEFChromium_SetOnLoadingStateChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadingStateChange}
  {$DEFINE EventName := OnLoadingStateChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnLoadError(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadError}
  {$DEFINE EventName := OnLoadError}
  EventMethodCode
end;

procedure CEFChromium_SetOnLoadEnd(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadEnd}
  {$DEFINE EventName := OnLoadEnd}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeDownload(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeDownload}
  {$DEFINE EventName := OnBeforeDownload}
  EventMethodCode
end;

procedure CEFChromium_SetOnDownloadUpdated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDownloadUpdated}
  {$DEFINE EventName := OnDownloadUpdated}
  EventMethodCode
end;

procedure CEFChromium_SetOnFullScreenModeChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFullScreenModeChange}
  {$DEFINE EventName := OnFullScreenModeChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnKeyEvent(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnKeyEvent}
  {$DEFINE EventName := OnKeyEvent}
  EventMethodCode
end;

procedure CEFChromium_SetOnTitleChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnTitleChange}
  {$DEFINE EventName := OnTitleChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnRenderCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderCompMsg}
  {$DEFINE EventName := OnRenderCompMsg}
  EventMethodCode
  {$endif}
end;

procedure CEFChromium_SetOnWidgetCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnWidgetCompMsg}
  {$DEFINE EventName := OnWidgetCompMsg}
  EventMethodCode
  {$endif}
end;

procedure CEFChromium_SetOnBrowserCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnBrowserCompMsg}
  {$DEFINE EventName := OnBrowserCompMsg}
  EventMethodCode
  {$endif}
end;

procedure CEFChromium_SetOnRenderProcessTerminated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderProcessTerminated}
  {$DEFINE EventName := OnRenderProcessTerminated}
  EventMethodCode
end;

procedure CEFChromium_SetOnRenderViewReady(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderViewReady}
  {$DEFINE EventName := OnRenderViewReady}
  EventMethodCode
end;

procedure CEFChromium_SetOnScrollOffsetChanged(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnScrollOffsetChanged}
  {$DEFINE EventName := OnScrollOffsetChanged}
  EventMethodCode
end;

procedure CEFChromium_SetOnProcessMessageReceived(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnProcessMessageReceived}
  {$DEFINE EventName := OnProcessMessageReceived}
  EventMethodCode
end;

procedure CEFChromium_SetOnFindResult(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFindResult}
  {$DEFINE EventName := OnFindResult}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeResourceLoad(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeResourceLoad}
  {$DEFINE EventName := OnBeforeResourceLoad}
  EventMethodCode
end;

procedure CEFChromium_SetOnResourceResponse(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceResponse}
  {$DEFINE EventName := OnResourceResponse}
  EventMethodCode
end;

procedure CEFChromium_SetOnResourceRedirect(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceRedirect}
  {$DEFINE EventName := OnResourceRedirect}
  EventMethodCode
end;

procedure CEFChromium_SetOnResourceLoadComplete(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceLoadComplete}
  {$DEFINE EventName := OnResourceLoadComplete}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforePopup(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforePopup}
  {$DEFINE EventName := OnBeforePopup}
  EventMethodCode
end;

procedure CEFChromium_SetOnOpenUrlFromTab(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnOpenUrlFromTab}
  {$DEFINE EventName := OnOpenUrlFromTab}
  EventMethodCode
end;

procedure CEFChromium_SetOnDragEnter(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDragEnter}
  {$DEFINE EventName := OnDragEnter}
  EventMethodCode
end;

procedure CEFChromium_SetOnDraggableRegionsChanged(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDraggableRegionsChanged}
  {$DEFINE EventName := OnDraggableRegionsChanged}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetAuthCredentials(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetAuthCredentials}
  {$DEFINE EventName := OnGetAuthCredentials}
  EventMethodCode
end;

procedure CEFChromium_SetOnBeforeUnloadDialog(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeUnloadDialog}
  {$DEFINE EventName := OnBeforeUnloadDialog}
  EventMethodCode
end;

procedure CEFChromium_SetOnCertificateError(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCertificateError}
  {$DEFINE EventName := OnCertificateError}
  EventMethodCode
end;

procedure CEFChromium_SetOnConsoleMessage(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnConsoleMessage}
  {$DEFINE EventName := OnConsoleMessage}
  EventMethodCode
end;

procedure CEFChromium_SetOnCursorChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCursorChange}
  {$DEFINE EventName := OnCursorChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnDialogClosed(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDialogClosed}
  {$DEFINE EventName := OnDialogClosed}
  EventMethodCode
end;

procedure CEFChromium_SetOnFavIconUrlChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFavIconUrlChange}
  {$DEFINE EventName := OnFavIconUrlChange}
  EventMethodCode
end;

procedure CEFChromium_SetOnFileDialog(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFileDialog}
  {$DEFINE EventName := OnFileDialog}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetResourceHandler(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetResourceHandler}
  {$DEFINE EventName := OnGetResourceHandler}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetResourceResponseFilter(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetResourceResponseFilter}
  {$DEFINE EventName := OnGetResourceResponseFilter}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetRootScreenRect(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetRootScreenRect}
  {$DEFINE EventName := OnGetRootScreenRect}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetScreenInfo(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetScreenInfo}
  {$DEFINE EventName := OnGetScreenInfo}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetScreenPoint(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetScreenPoint}
  {$DEFINE EventName := OnGetScreenPoint}
  EventMethodCode
end;

procedure CEFChromium_SetOnGetViewRect(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetViewRect}
  {$DEFINE EventName := OnGetViewRect}
  EventMethodCode
end;

procedure CEFChromium_SetOnGotFocus(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGotFocus}
  {$DEFINE EventName := OnGotFocus}
  EventMethodCode
end;

procedure CEFChromium_SetOnJsDialog(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnJsDialog}
  {$DEFINE EventName := OnJsDialog}
  EventMethodCode
end;

procedure CEFChromium_SetOnPaint(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPaint}
  {$DEFINE EventName := OnPaint}
  EventMethodCode
end;

procedure CEFChromium_SetOnPopupShow(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPopupShow}
  {$DEFINE EventName := OnPopupShow}
  EventMethodCode
end;

procedure CEFChromium_SetOnPopupSize(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPopupSize}
  {$DEFINE EventName := OnPopupSize}
  EventMethodCode
end;

procedure CEFChromium_SetOnPrefsAvailable(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPrefsAvailable}
  {$DEFINE EventName := OnPrefsAvailable}
  EventMethodCode
end;

procedure CEFChromium_SetOnPreKeyEvent(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPreKeyEvent}
  {$DEFINE EventName := OnPreKeyEvent}
  EventMethodCode
end;

procedure CEFChromium_SetOnProtocolExecution(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnProtocolExecution}
  {$DEFINE EventName := OnProtocolExecution}
  EventMethodCode
end;

procedure CEFChromium_SetOnResetDialogState(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResetDialogState}
  {$DEFINE EventName := OnResetDialogState}
  EventMethodCode
end;

procedure CEFChromium_SetOnRunContextMenu(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRunContextMenu}
  {$DEFINE EventName := OnRunContextMenu}
  EventMethodCode
end;

procedure CEFChromium_SetOnSetFocus(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnSetFocus}
  {$DEFINE EventName := OnSetFocus}
  EventMethodCode
end;

procedure CEFChromium_SetOnStartDragging(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnStartDragging}
  {$DEFINE EventName := OnStartDragging}
  EventMethodCode
end;

procedure CEFChromium_SetOnStatusMessage(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnStatusMessage}
  {$DEFINE EventName := OnStatusMessage}
  EventMethodCode
end;

procedure CEFChromium_SetOnTakeFocus(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnTakeFocus}
  {$DEFINE EventName := OnTakeFocus}
  EventMethodCode
end;

procedure CEFChromium_SetOnTooltip(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnTooltip}
  {$DEFINE EventName := OnTooltip}
  EventMethodCode
end;

procedure CEFChromium_SetOnUpdateDragCursor(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnUpdateDragCursor}
  {$DEFINE EventName := OnUpdateDragCursor}
  EventMethodCode
end;


exports
  CEFChromium_SetOnAfterCreated,
  CEFChromium_SetOnBeforeBrowse,
  CEFChromium_SetOnAddressChange,
  CEFChromium_SetOnBeforeClose,
  CEFChromium_SetOnClose,
  CEFChromium_SetOnPdfPrintFinished,
  CEFChromium_SetOnFullScreenModeChange,
  CEFChromium_SetOnKeyEvent,
  CEFChromium_SetOnTitleChange,
  CEFChromium_SetOnBeforeContextMenu,
  CEFChromium_SetOnContextMenuCommand,
  CEFChromium_SetOnContextMenuDismissed,
  CEFChromium_SetOnBeforePopup,
  CEFChromium_SetOnOpenUrlFromTab,
  CEFChromium_SetOnDragEnter,
  CEFChromium_SetOnDraggableRegionsChanged,//drag - css [-webkit-app-region： drag/no-drag]
  CEFChromium_SetOnLoadStart,
  CEFChromium_SetOnLoadingStateChange,
  CEFChromium_SetOnLoadError,
  CEFChromium_SetOnLoadEnd,
  CEFChromium_SetOnBeforeDownload,
  CEFChromium_SetOnDownloadUpdated,
  CEFChromium_SetOnRenderCompMsg,
  CEFChromium_SetOnWidgetCompMsg,
  CEFChromium_SetOnBrowserCompMsg,
  CEFChromium_SetOnRenderProcessTerminated,
  CEFChromium_SetOnRenderViewReady,
  CEFChromium_SetOnScrollOffsetChanged,
  CEFChromium_SetOnProcessMessageReceived,
  CEFChromium_SetOnFindResult,
  CEFChromium_SetOnCookiesDeleted,
  CEFChromium_SetOnBeforeResourceLoad,
  CEFChromium_SetOnResourceResponse,
  CEFChromium_SetOnResourceRedirect,
  CEFChromium_SetOnResourceLoadComplete,
  CEFChromium_SetOnGetAuthCredentials,
  CEFChromium_SetOnBeforeUnloadDialog,
  CEFChromium_SetOnCertificateError,
  CEFChromium_SetOnConsoleMessage,
  CEFChromium_SetOnCursorChange,
  CEFChromium_SetOnDialogClosed,
  CEFChromium_SetOnFavIconUrlChange,
  CEFChromium_SetOnFileDialog,
  CEFChromium_SetOnGetResourceHandler,
  CEFChromium_SetOnGetResourceResponseFilter,
  CEFChromium_SetOnGetRootScreenRect,
  CEFChromium_SetOnGetScreenInfo,
  CEFChromium_SetOnGetScreenPoint,
  CEFChromium_SetOnGetViewRect,
  CEFChromium_SetOnGotFocus,
  CEFChromium_SetOnJsDialog,
  CEFChromium_SetOnPaint,
  CEFChromium_SetOnPopupShow,
  CEFChromium_SetOnPopupSize,
  CEFChromium_SetOnPrefsAvailable,
  CEFChromium_SetOnPreKeyEvent,
  CEFChromium_SetOnProtocolExecution,
  CEFChromium_SetOnResetDialogState,
  CEFChromium_SetOnRunContextMenu,
  CEFChromium_SetOnSetFocus,
  CEFChromium_SetOnStartDragging,
  CEFChromium_SetOnStatusMessage,
  CEFChromium_SetOnTakeFocus,
  CEFChromium_SetOnTooltip,
  CEFChromium_SetOnUpdateDragCursor;
