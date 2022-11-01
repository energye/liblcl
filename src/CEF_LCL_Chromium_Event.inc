//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{====== events ======}

//EVENT_TYPE:ChromiumEventOnCookieVisitorDestroyed
procedure CEFChromium_SetOnCookieVisitorDestroyed(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookieVisitorDestroyed}
  {$DEFINE EventName := OnCookieVisitorDestroyed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesVisited
procedure CEFChromium_SetOnCookiesVisited(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesVisited}
  {$DEFINE EventName := OnCookiesVisited}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesFlushed
procedure CEFChromium_SetOnCookiesFlushed(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesFlushed}
  {$DEFINE EventName := OnCookiesFlushed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookiesDeleted
procedure CEFChromium_SetOnCookiesDeleted(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookiesDeleted}
  {$DEFINE EventName := OnCookiesDeleted}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnCookieSet
procedure CEFChromium_SetOnCookieSet(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnCookieSet}
  {$DEFINE EventName := OnCookieSet}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnAfterCreated
procedure CEFChromium_SetOnAfterCreated(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAfterCreated}
  {$DEFINE EventName := OnAfterCreated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeBrowse
procedure CEFChromium_SetOnBeforeBrowse(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeBrowse}
  {$DEFINE EventName := OnBeforeBrowse}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnAddressChange
procedure CEFChromium_SetOnAddressChange(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnAddressChange}
  {$DEFINE EventName := OnAddressChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeClose
procedure CEFChromium_SetOnBeforeClose(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeClose}
  {$DEFINE EventName := OnBeforeClose}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnClose
procedure CEFChromium_SetOnClose(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnClose}
  {$DEFINE EventName := OnClose}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeContextMenu
procedure CEFChromium_SetOnBeforeContextMenu(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeContextMenu}
  {$DEFINE EventName := OnBeforeContextMenu}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnContextMenuCommand
procedure CEFChromium_SetOnContextMenuCommand(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuCommand}
  {$DEFINE EventName := OnContextMenuCommand}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnContextMenuDismissed
procedure CEFChromium_SetOnContextMenuDismissed(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnContextMenuDismissed}
  {$DEFINE EventName := OnContextMenuDismissed}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventResult
procedure CEFChromium_SetOnPdfPrintFinished(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnPdfPrintFinished}
  {$DEFINE EventName := OnPdfPrintFinished}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadStart
procedure CEFChromium_SetOnLoadStart(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadStart}
  {$DEFINE EventName := OnLoadStart}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadingStateChange
procedure CEFChromium_SetOnLoadingStateChange(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadingStateChange}
  {$DEFINE EventName := OnLoadingStateChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadingProgressChange
procedure CEFChromium_SetOnLoadingProgressChange(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadingProgressChange}
  {$DEFINE EventName := OnLoadingProgressChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnLoadError
procedure CEFChromium_SetOnLoadError(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadError}
  {$DEFINE EventName := OnLoadError}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnOnLoadEnd
procedure CEFChromium_SetOnLoadEnd(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnLoadEnd}
  {$DEFINE EventName := OnLoadEnd}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeDownload
procedure CEFChromium_SetOnBeforeDownload(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeDownload}
  {$DEFINE EventName := OnBeforeDownload}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnDownloadUpdated
procedure CEFChromium_SetOnDownloadUpdated(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnDownloadUpdated}
  {$DEFINE EventName := OnDownloadUpdated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResultFloat
procedure CEFChromium_SetOnZoomPctAvailable(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnZoomPctAvailable}
  {$DEFINE EventName := OnZoomPctAvailable}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFullScreenModeChange
procedure CEFChromium_SetOnFullScreenModeChange(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFullScreenModeChange}
  {$DEFINE EventName := OnFullScreenModeChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnKeyEvent 键盘事件
procedure CEFChromium_SetOnKeyEvent(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_KeyEvent}
  {$DEFINE EventName := OnKeyEvent}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnTitleChange
procedure CEFChromium_SetOnTitleChange(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnTitleChange}
  {$DEFINE EventName := OnTitleChange}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnRenderCompMsg
procedure CEFChromium_SetOnRenderCompMsg(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$ifdef windows}
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderCompMsg}
  {$DEFINE EventName := OnRenderCompMsg}
  EventMethodCode     
  {$endif}
end;

//EVENT_TYPE:ChromiumEventOnRenderProcessTerminated
procedure CEFChromium_SetOnRenderProcessTerminated(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderProcessTerminated}
  {$DEFINE EventName := OnRenderProcessTerminated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnRenderViewReady
procedure CEFChromium_SetOnRenderViewReady(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnRenderViewReady}
  {$DEFINE EventName := OnRenderViewReady}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnScrollOffsetChanged
procedure CEFChromium_SetOnScrollOffsetChanged(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnScrollOffsetChanged}
  {$DEFINE EventName := OnScrollOffsetChanged}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnProcessMessageReceived
procedure CEFChromium_SetOnProcessMessageReceived(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnProcessMessageReceived}
  {$DEFINE EventName := OnProcessMessageReceived}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFindResult
procedure CEFChromium_SetOnFindResult(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFindResult}
  {$DEFINE EventName := OnFindResult}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforeResourceLoad
procedure CEFChromium_SetOnBeforeResourceLoad(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforeResourceLoad}
  {$DEFINE EventName := OnBeforeResourceLoad}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceResponse
procedure CEFChromium_SetOnResourceResponse(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceResponse}
  {$DEFINE EventName := OnResourceResponse}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceRedirect
procedure CEFChromium_SetOnResourceRedirect(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceRedirect}
  {$DEFINE EventName := OnResourceRedirect}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnResourceLoadComplete
procedure CEFChromium_SetOnResourceLoadComplete(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnResourceLoadComplete}
  {$DEFINE EventName := OnResourceLoadComplete}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameAttached
procedure CEFChromium_SetOnFrameAttached(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameAttached}
  {$DEFINE EventName := OnFrameAttached}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameCreated
procedure CEFChromium_SetOnFrameCreated(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameCreated}
  {$DEFINE EventName := OnFrameCreated}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnFrameDetached
procedure CEFChromium_SetOnFrameDetached(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnFrameDetached}
  {$DEFINE EventName := OnFrameDetached}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnMainFrameChanged
procedure CEFChromium_SetOnMainFrameChanged(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnMainFrameChanged}
  {$DEFINE EventName := OnMainFrameChanged}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnBeforePopup
procedure CEFChromium_SetOnBeforePopup(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnBeforePopup}
  {$DEFINE EventName := OnBeforePopup}
  EventMethodCode
end;

//EVENT_TYPE:ChromiumEventOnOpenUrlFromTab
procedure CEFChromium_SetOnOpenUrlFromTab(AObj: TChromium; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := ChromiumEvent_OnOpenUrlFromTab}
  {$DEFINE EventName := OnOpenUrlFromTab}
  EventMethodCode
end;


exports
{ ====  events begin ====  }
   //other
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
   //chromium load loading
   CEFChromium_SetOnLoadStart, CEFChromium_SetOnLoadingStateChange, CEFChromium_SetOnLoadingProgressChange,
   CEFChromium_SetOnLoadError, CEFChromium_SetOnLoadEnd,
   //download
   CEFChromium_SetOnBeforeDownload, CEFChromium_SetOnDownloadUpdated,
   //Render
   CEFChromium_SetOnRenderCompMsg, CEFChromium_SetOnRenderProcessTerminated, CEFChromium_SetOnRenderViewReady,
   CEFChromium_SetOnScrollOffsetChanged,
   //ProcessMessage
   CEFChromium_SetOnProcessMessageReceived,
   CEFChromium_SetOnFindResult,
   //cookie
   CEFChromium_SetOnCookieVisitorDestroyed,
   CEFChromium_SetOnCookiesVisited,
   CEFChromium_SetOnCookiesFlushed,
   CEFChromium_SetOnCookiesDeleted,
   CEFChromium_SetOnCookieSet,
   //other
   CEFChromium_SetOnBeforeResourceLoad,
   CEFChromium_SetOnResourceResponse,
   CEFChromium_SetOnResourceRedirect,
   CEFChromium_SetOnResourceLoadComplete,
   //frame
   CEFChromium_SetOnFrameAttached,
   CEFChromium_SetOnFrameCreated,
   CEFChromium_SetOnFrameDetached,
   CEFChromium_SetOnMainFrameChanged
{ ==== events end ==== }
//结尾
;

