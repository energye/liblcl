//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{====== events ======}

//EVENT_TYPE:ChromiumEventOnCookieVisitorDestroyed
procedure CEFChromium_SetOnCookieVisitorDestroyed(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookieVisitorDestroyed}
  {$DEFINE EventName := OnCookieVisitorDestroyed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesVisited
procedure CEFChromium_SetOnCookiesVisited(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesVisited}
  {$DEFINE EventName := OnCookiesVisited}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesFlushed
procedure CEFChromium_SetOnCookiesFlushed(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesFlushed}
  {$DEFINE EventName := OnCookiesFlushed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesDeleted
procedure CEFChromium_SetOnCookiesDeleted(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesDeleted}
  {$DEFINE EventName := OnCookiesDeleted}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookieSet
procedure CEFChromium_SetOnCookieSet(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookieSet}
  {$DEFINE EventName := OnCookieSet}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnAfterCreated
procedure CEFChromium_SetOnAfterCreated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAfterCreated}
  {$DEFINE EventName := OnAfterCreated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeBrowse
procedure CEFChromium_SetOnBeforeBrowse(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeBrowse}
  {$DEFINE EventName := OnBeforeBrowse}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnAddressChange
procedure CEFChromium_SetOnAddressChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAddressChange}
  {$DEFINE EventName := OnAddressChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeClose
procedure CEFChromium_SetOnBeforeClose(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeClose}
  {$DEFINE EventName := OnBeforeClose}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnClose
procedure CEFChromium_SetOnClose(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnClose}
  {$DEFINE EventName := OnClose}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeContextMenu
procedure CEFChromium_SetOnBeforeContextMenu(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeContextMenu}
  {$DEFINE EventName := OnBeforeContextMenu}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnContextMenuCommand
procedure CEFChromium_SetOnContextMenuCommand(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuCommand}
  {$DEFINE EventName := OnContextMenuCommand}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnContextMenuDismissed
procedure CEFChromium_SetOnContextMenuDismissed(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuDismissed}
  {$DEFINE EventName := OnContextMenuDismissed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventResult
procedure CEFChromium_SetOnPdfPrintFinished(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPdfPrintFinished}
  {$DEFINE EventName := OnPdfPrintFinished}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadStart
procedure CEFChromium_SetOnLoadStart(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadStart}
  {$DEFINE EventName := OnLoadStart}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadingStateChange
procedure CEFChromium_SetOnLoadingStateChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadingStateChange}
  {$DEFINE EventName := OnLoadingStateChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadingProgressChange
procedure CEFChromium_SetOnLoadingProgressChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadingProgressChange}
  {$DEFINE EventName := OnLoadingProgressChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadError
procedure CEFChromium_SetOnLoadError(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadError}
  {$DEFINE EventName := OnLoadError}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnOnLoadEnd
procedure CEFChromium_SetOnLoadEnd(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadEnd}
  {$DEFINE EventName := OnLoadEnd}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeDownload
procedure CEFChromium_SetOnBeforeDownload(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeDownload}
  {$DEFINE EventName := OnBeforeDownload}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnDownloadUpdated
procedure CEFChromium_SetOnDownloadUpdated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDownloadUpdated}
  {$DEFINE EventName := OnDownloadUpdated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResultFloat
procedure CEFChromium_SetOnZoomPctAvailable(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnZoomPctAvailable}
  {$DEFINE EventName := OnZoomPctAvailable}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFullScreenModeChange
procedure CEFChromium_SetOnFullScreenModeChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFullScreenModeChange}
  {$DEFINE EventName := OnFullScreenModeChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnKeyEvent 键盘事件
procedure CEFChromium_SetOnKeyEvent(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_KeyEvent}
  {$DEFINE EventName := OnKeyEvent}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnTitleChange
procedure CEFChromium_SetOnTitleChange(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnTitleChange}
  {$DEFINE EventName := OnTitleChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnRenderCompMsg
procedure CEFChromium_SetOnRenderCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderCompMsg}
  {$DEFINE EventName := OnRenderCompMsg}
  EventMethodCode
  {$endif}
end;

//EVENT_TYPE:ChromiumEventOnWidgetCompMsg
procedure CEFChromium_SetOnWidgetCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnWidgetCompMsg}
  {$DEFINE EventName := OnWidgetCompMsg}
  EventMethodCode
  {$endif}
end;

//EVENT_TYPE:ChromiumEventOnBrowserCompMsg
procedure CEFChromium_SetOnBrowserCompMsg(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnBrowserCompMsg}
  {$DEFINE EventName := OnBrowserCompMsg}
  EventMethodCode
  {$endif}
end;

//EVENT_TYPE:ChromiumEventOnRenderProcessTerminated
procedure CEFChromium_SetOnRenderProcessTerminated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderProcessTerminated}
  {$DEFINE EventName := OnRenderProcessTerminated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnRenderViewReady
procedure CEFChromium_SetOnRenderViewReady(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderViewReady}
  {$DEFINE EventName := OnRenderViewReady}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnScrollOffsetChanged
procedure CEFChromium_SetOnScrollOffsetChanged(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnScrollOffsetChanged}
  {$DEFINE EventName := OnScrollOffsetChanged}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnProcessMessageReceived
procedure CEFChromium_SetOnProcessMessageReceived(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnProcessMessageReceived}
  {$DEFINE EventName := OnProcessMessageReceived}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFindResult
procedure CEFChromium_SetOnFindResult(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFindResult}
  {$DEFINE EventName := OnFindResult}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeResourceLoad
procedure CEFChromium_SetOnBeforeResourceLoad(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeResourceLoad}
  {$DEFINE EventName := OnBeforeResourceLoad}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceResponse
procedure CEFChromium_SetOnResourceResponse(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceResponse}
  {$DEFINE EventName := OnResourceResponse}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceRedirect
procedure CEFChromium_SetOnResourceRedirect(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceRedirect}
  {$DEFINE EventName := OnResourceRedirect}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceLoadComplete
procedure CEFChromium_SetOnResourceLoadComplete(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceLoadComplete}
  {$DEFINE EventName := OnResourceLoadComplete}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameAttached
procedure CEFChromium_SetOnFrameAttached(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameAttached}
  {$DEFINE EventName := OnFrameAttached}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameCreated
procedure CEFChromium_SetOnFrameCreated(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameCreated}
  {$DEFINE EventName := OnFrameCreated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameDetached
procedure CEFChromium_SetOnFrameDetached(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameDetached}
  {$DEFINE EventName := OnFrameDetached}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnMainFrameChanged
procedure CEFChromium_SetOnMainFrameChanged(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnMainFrameChanged}
  {$DEFINE EventName := OnMainFrameChanged}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforePopup
procedure CEFChromium_SetOnBeforePopup(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforePopup}
  {$DEFINE EventName := OnBeforePopup}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnOpenUrlFromTab
procedure CEFChromium_SetOnOpenUrlFromTab(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnOpenUrlFromTab}
  {$DEFINE EventName := OnOpenUrlFromTab}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnDragEnter
procedure CEFChromium_SetOnDragEnter(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDragEnter}
  {$DEFINE EventName := OnDragEnter}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnDraggableRegionsChanged
procedure CEFChromium_SetOnDraggableRegionsChanged(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDraggableRegionsChanged}
  {$DEFINE EventName := OnDraggableRegionsChanged}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnGetAuthCredentials
procedure CEFChromium_SetOnGetAuthCredentials(const AObj: TChromium; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnGetAuthCredentials}
  {$DEFINE EventName := OnGetAuthCredentials}
  EventMethodCode
end;


exports
   CEFChromium_SetOnAfterCreated,
   CEFChromium_SetOnBeforeBrowse,
   CEFChromium_SetOnAddressChange,
   CEFChromium_SetOnBeforeClose,
   CEFChromium_SetOnClose,
   CEFChromium_SetOnPdfPrintFinished,
   CEFChromium_SetOnZoomPctAvailable,
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
   CEFChromium_SetOnLoadingProgressChange,
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
   CEFChromium_SetOnCookieVisitorDestroyed,
   CEFChromium_SetOnCookiesVisited,
   CEFChromium_SetOnCookiesFlushed,
   CEFChromium_SetOnCookiesDeleted,
   CEFChromium_SetOnCookieSet,
   CEFChromium_SetOnBeforeResourceLoad,
   CEFChromium_SetOnResourceResponse,
   CEFChromium_SetOnResourceRedirect,
   CEFChromium_SetOnResourceLoadComplete,
   CEFChromium_SetOnFrameAttached,
   CEFChromium_SetOnFrameCreated,
   CEFChromium_SetOnFrameDetached,
   CEFChromium_SetOnMainFrameChanged,
   CEFChromium_SetOnGetAuthCredentials
;

