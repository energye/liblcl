//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ClientHandlersRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, uCEF_LCL_Entity,
  uCEFTypes, uCEFInterfaces, uCEFAudioHandler, uCEFContextMenuHandler, uCEFDialogHandler, uCEFDisplayHandler,
  uCEFDownloadHandler, uCEFDragHandler, uCEFFindHandler, uCEFFocusHandler, uCEFJsdialogHandler, uCEFKeyboardHandler,
  uCEFLifeSpanHandler, uCEFLoadHandler, uCEFPrintHandler, uCEFRenderHandler, uCEFRequestHandler, uCEFv8Value,
  uCEF_LCL_EventCallback;

type

  {== AudioHandler ==}
  TAudioHandlerRef = class(TCefAudioHandlerOwn)
  public
    GetAudioParametersPtr: Pointer;
    AudioStreamStartedPtr: Pointer;
    AudioStreamPacketPtr: Pointer;
    AudioStreamStoppedPtr: Pointer;
    AudioStreamErrorPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnGetAudioParameters(const browser: ICefBrowser; var params: TCefAudioParameters; var aResult: boolean); override;
    procedure OnAudioStreamStarted(const browser: ICefBrowser; const params: TCefAudioParameters; channels: integer); override;
    procedure OnAudioStreamPacket(const browser: ICefBrowser; const Data: PPSingle; frames: integer; pts: int64); override;
    procedure OnAudioStreamStopped(const browser: ICefBrowser); override;
    procedure OnAudioStreamError(const browser: ICefBrowser; const message_: ustring); override;
    procedure RemoveReferences; override;
  end;

  {== ContextMenuHandler ==}
  TContextMenuHandlerRef = class(TCefContextMenuHandlerOwn)
  public
    BeforeContextMenuPtr: Pointer;
    RunContextMenuPtr: Pointer;
    ContextMenuCommandPtr: Pointer;
    ContextMenuDismissedPtr: Pointer;
    RunQuickMenuPtr: Pointer;
    QuickMenuCommandPtr: Pointer;
    QuickMenuDismissedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnBeforeContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel); override;
    function RunContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback): boolean; override;
    function OnContextMenuCommand(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: integer; eventFlags: TCefEventFlags): boolean; override;
    procedure OnContextMenuDismissed(const browser: ICefBrowser; const frame: ICefFrame); override;
    procedure RemoveReferences; override;
  end;

  {== DialogHandler ==}
  TDialogHandlerRef = class(TCefDialogHandlerOwn)
  public
    FileDialogPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback): Boolean; override;
    procedure RemoveReferences; override;
  end;

  {== DisplayHandler ==}
  TDisplayHandlerRef = class(TCefDisplayHandlerOwn)
  public
    AddressChangePtr: Pointer;
    TitleChangePtr: Pointer;
    FaviconUrlChangePtr: Pointer;
    FullScreenModeChangePtr: Pointer;
    TooltipPtr: Pointer;
    StatusMessagePtr: Pointer;
    ConsoleMessagePtr: Pointer;
    AutoResizePtr: Pointer;
    LoadingProgressChangePtr: Pointer;
    CursorChangePtr: Pointer;
    MediaAccessChangePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnAddressChange(const browser: ICefBrowser; const frame: ICefFrame; const url: ustring); override;
    procedure OnTitleChange(const browser: ICefBrowser; const title: ustring); override;
    procedure OnFaviconUrlChange(const browser: ICefBrowser; const iconUrls: TStrings); override;
    procedure OnFullScreenModeChange(const browser: ICefBrowser; fullscreen: boolean); override;
    function OnTooltip(const browser: ICefBrowser; var Text: ustring): boolean; override;
    procedure OnStatusMessage(const browser: ICefBrowser; const Value: ustring); override;
    function OnConsoleMessage(const browser: ICefBrowser; level: TCefLogSeverity; const message_, Source: ustring; line: integer): boolean; override;
    function OnAutoResize(const browser: ICefBrowser; const new_size: PCefSize): boolean; override;
    procedure OnLoadingProgressChange(const browser: ICefBrowser; const progress: double); override;
    procedure OnCursorChange(const browser: ICefBrowser; cursor_: TCefCursorHandle; CursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo; var aResult: boolean); override;
    procedure RemoveReferences; override;
  end;

  {== DownloadHandler ==}
  TDownloadHandlerRef = class(TCefDownloadHandlerOwn)
  public
    CanDownloadPtr: Pointer;
    BeforeDownloadPtr: Pointer;
    DownloadUpdatedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure  OnBeforeDownload(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback); override;
    procedure OnDownloadUpdated(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback); override;
    procedure RemoveReferences; override;
  end;

  {== DragHandler ==}
  TDragHandlerRef = class(TCefDragHandlerOwn)
  public
    DragEnterPtr: Pointer;
    DraggableRegionsChangedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnDragEnter(const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations): boolean; override;
    procedure OnDraggableRegionsChanged(const browser: ICefBrowser; const frame: ICefFrame; regionsCount: nativeuint; const regions: PCefDraggableRegionArray); override;
    procedure RemoveReferences; override;
  end;

  {== FindHandler ==}
  TFindHandlerRef = class(TCefFindHandlerOwn)
  public
    FindResultPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnFindResult(const browser: ICefBrowser; identifier, Count: integer; const selectionRect: PCefRect; activeMatchOrdinal: integer; finalUpdate: boolean); override;
    procedure RemoveReferences; override;
  end;

  {== FocusHandler ==}
  TFocusHandlerRef = class(TCefFocusHandlerOwn)
  public
    TakeFocusPtr: Pointer;
    SetFocusPtr: Pointer;
    GotFocusPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnTakeFocus(const browser: ICefBrowser; Next: boolean); override;
    function OnSetFocus(const browser: ICefBrowser; Source: TCefFocusSource): boolean; override;
    procedure OnGotFocus(const browser: ICefBrowser); override;
    procedure RemoveReferences; override;
  end;

  {== JsDialogHandler ==}
  TJsDialogHandlerRef = class(TCefJsDialogHandlerOwn)
  public
    JsdialogPtr: Pointer;
    BeforeUnloadDialogPtr: Pointer;
    ResetDialogStatePtr: Pointer;
    DialogClosedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnJsdialog(const browser: ICefBrowser; const originUrl: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: boolean): boolean; override;
    function OnBeforeUnloadDialog(const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback): boolean; override;
    procedure OnResetDialogState(const browser: ICefBrowser); override;
    procedure OnDialogClosed(const browser: ICefBrowser); override;
    procedure RemoveReferences; override;
  end;

  {== KeyboardHandler ==}
  TKeyboardHandlerRef = class(TCefKeyboardHandlerOwn)
  public
    PreKeyEventPtr: Pointer;
    KeyEventPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnPreKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean): boolean; override;
    function OnKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle): boolean; override;
    procedure RemoveReferences; override;
  end;

  {== LifeSpanHandler ==}
  TLifeSpanHandlerRef = class(TCefLifeSpanHandlerOwn)
  public
    BeforePopupPtr: Pointer;
    AfterCreatedPtr: Pointer;
    DoClosePtr: Pointer;
    BeforeClosePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnBeforePopup(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var extra_info: ICefDictionaryValue; var noJavascriptAccess: boolean): boolean; override;
    procedure OnAfterCreated(const browser: ICefBrowser); override;
    function DoClose(const browser: ICefBrowser): boolean; override;
    procedure OnBeforeClose(const browser: ICefBrowser); override;
    procedure RemoveReferences; override;
  end;

  {== LoadHandler ==}
  TLoadHandlerRef = class(TCefLoadHandlerOwn)
  public
    LoadingStateChangePtr: Pointer;
    LoadStartPtr: Pointer;
    LoadEndPtr: Pointer;
    LoadErrorPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean); override;
    procedure OnLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType); override;
    procedure OnLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer); override;
    procedure OnLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring); override;
    procedure RemoveReferences; override;
  end;

  {== PrintHandler ==}
  TPrintHandlerRef = class(TCefPrintHandlerOwn)
  public
    PrintStartPtr: Pointer;
    PrintSettingsPtr: Pointer;
    PrintDialogPtr: Pointer;
    PrintJobPtr: Pointer;
    PrintResetPtr: Pointer;
    PDFPaperSizePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnPrintStart(const browser: ICefBrowser); override;
    procedure OnPrintSettings(const browser: ICefBrowser; const settings: ICefPrintSettings; getDefaults: boolean); override;
    procedure OnPrintDialog(const browser: ICefBrowser; hasSelection: boolean; const callback: ICefPrintDialogCallback; var aResult: boolean); override;
    procedure OnPrintJob(const browser: ICefBrowser; const documentName, PDFFilePath: ustring; const callback: ICefPrintJobCallback; var aResult: boolean); override;
    procedure OnPrintReset(const browser: ICefBrowser); override;
    procedure GetPDFPaperSize(deviceUnitsPerInch: Integer; var aResult: TCefSize); override;
    procedure RemoveReferences; override;
  end;

  {== RenderHandler ==}
  TRenderHandlerRef = class(TCefRenderHandlerOwn)
  public
    AccessibilityHandlerPtr: Pointer;
    RootScreenRectPtr: Pointer;
    ViewRectPtr: Pointer;
    ScreenPointPtr: Pointer;
    ScreenInfoPtr: Pointer;
    PopupShowPtr: Pointer;
    PopupSizePtr: Pointer;
    PaintPtr: Pointer;
    AcceleratedPaintPtr: Pointer;
    TouchHandleSizePtr: Pointer;
    TouchHandleStateChangedPtr: Pointer;
    StartDraggingPtr: Pointer;
    UpdateDragCursorPtr: Pointer;
    ScrollOffsetChangedPtr: Pointer;
    IMECompositionRangeChangedPtr: Pointer;
    TextSelectionChangedPtr: Pointer;
    VirtualKeyboardRequestedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure GetAccessibilityHandler(var aAccessibilityHandler: ICefAccessibilityHandler); override;
    function GetRootScreenRect(const browser: ICefBrowser; var rect: TCefRect): boolean; override;
    procedure GetViewRect(const browser: ICefBrowser; var rect: TCefRect); override;
    function GetScreenPoint(const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer): boolean; override;
    function GetScreenInfo(const browser: ICefBrowser; var screenInfo: TCefScreenInfo): boolean; override;
    procedure OnPopupShow(const browser: ICefBrowser; Show: boolean); override;
    procedure OnPopupSize(const browser: ICefBrowser; const rect: PCefRect); override;
    procedure OnPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer); override;
    procedure OnAcceleratedPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: NativeUInt; const dirtyRects: PCefRectArray; shared_handle: Pointer); override;
    function OnStartDragging(const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer): boolean; override;
    procedure OnUpdateDragCursor(const browser: ICefBrowser; operation: TCefDragOperation); override;
    procedure OnScrollOffsetChanged(const browser: ICefBrowser; x, y: double); override;
    procedure OnIMECompositionRangeChanged(const browser: ICefBrowser; const selected_range: PCefRange; character_boundsCount: nativeuint; const character_bounds: PCefRect); override;
    procedure OnTextSelectionChanged(const browser: ICefBrowser; const selected_text: ustring; const selected_range: PCefRange); override;
    procedure OnVirtualKeyboardRequested(const browser: ICefBrowser; input_mode: TCefTextInpuMode); override;
    procedure RemoveReferences; override;
  end;

  {== RequestHandler ==}
  TRequestHandlerRef = class(TCefRequestHandlerOwn)
  public
    BeforeBrowsePtr: Pointer;
    OpenUrlFromTabPtr: Pointer;
    GetResourceRequestHandlerPtr: Pointer;
    GetAuthCredentialsPtr: Pointer;
    CertificateErrorPtr: Pointer;
    SelectClientCertificatePtr: Pointer;
    RenderViewReadyPtr: Pointer;
    RenderProcessTerminatedPtr: Pointer;
    DocumentAvailableInMainFramePtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnBeforeBrowse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: boolean): boolean; override;
    function OnOpenUrlFromTab(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean): boolean; override;
    procedure GetResourceRequestHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aResourceRequestHandler: ICefResourceRequestHandler); override;
    function GetAuthCredentials(const browser: ICefBrowser; const originUrl: ustring; isProxy: boolean; const host: ustring; port: integer; const realm, scheme: ustring; const callback: ICefAuthCallback): boolean; override;
    function OnCertificateError(const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback): Boolean; override;
    function OnSelectClientCertificate(const browser: ICefBrowser; isProxy: boolean; const host: ustring; port: integer; certificatesCount: nativeuint; const certificates: TCefX509CertificateArray; const callback: ICefSelectClientCertificateCallback): boolean; override;
    procedure OnRenderViewReady(const browser: ICefBrowser); override;
    procedure OnRenderProcessTerminated(const browser: ICefBrowser; status: TCefTerminationStatus); override;
    procedure OnDocumentAvailableInMainFrame(const browser: ICefBrowser); override;
    procedure RemoveReferences; override;
  end;

implementation

{== AudioHandler ==}
procedure TAudioHandlerRef.OnGetAudioParameters(const browser: ICefBrowser; var params: TCefAudioParameters; var aResult: boolean);
begin
  if (GetAudioParametersPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetAudioParametersPtr, [browser, @params, @aResult]);
  end
  else
    inherited OnGetAudioParameters(browser, params, aResult);
end;

procedure TAudioHandlerRef.OnAudioStreamStarted(const browser: ICefBrowser; const params: TCefAudioParameters; channels: integer);
begin
  if (AudioStreamStartedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamStartedPtr, [browser, @params, channels]);
  end
  else
    inherited OnAudioStreamStarted(browser, params, channels);
end;

procedure TAudioHandlerRef.OnAudioStreamPacket(const browser: ICefBrowser; const Data: PPSingle; frames: integer; pts: int64);
begin
  if (AudioStreamPacketPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamPacketPtr, [browser, Data, frames, pts]);
  end
  else
    inherited OnAudioStreamPacket(browser, Data, frames, pts);
end;

procedure TAudioHandlerRef.OnAudioStreamStopped(const browser: ICefBrowser);
begin
  if (AudioStreamStoppedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamStoppedPtr, [browser]);
  end
  else
    inherited OnAudioStreamStopped(browser);
end;

procedure TAudioHandlerRef.OnAudioStreamError(const browser: ICefBrowser; const message_: ustring);
begin
  if (AudioStreamErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamErrorPtr, [browser, PChar(string(message_))]);
  end
  else
    inherited OnAudioStreamError(browser, message_);
end;

procedure TAudioHandlerRef.RemoveReferences;
begin
  GetAudioParametersPtr := nil;
  AudioStreamStartedPtr := nil;
  AudioStreamPacketPtr := nil;
  AudioStreamStoppedPtr := nil;
  AudioStreamErrorPtr := nil;
  inherited RemoveReferences;
end;

constructor TAudioHandlerRef.Create;
begin
  inherited Create;
end;

destructor TAudioHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;


{== ContextMenuHandler ==}
procedure TContextMenuHandlerRef.OnBeforeContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
begin
  if (BeforeContextMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeContextMenuPtr, [browser, frame, params, model]);
  end
  else
    inherited OnBeforeContextMenu(browser, frame, params, model);
end;

function TContextMenuHandlerRef.RunContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback): boolean;
begin
  Result := False;
  if (RunContextMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RunContextMenuPtr, [browser, frame, params, model, callback, @Result]);
  end
  else
    Result := inherited RunContextMenu(browser, frame, params, model, callback);
end;

function TContextMenuHandlerRef.OnContextMenuCommand(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: integer; eventFlags: TCefEventFlags): boolean;
begin
  Result := False;
  if (ContextMenuCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ContextMenuCommandPtr, [browser, frame, params, commandId, eventFlags, @Result]);
  end
  else
    Result := inherited OnContextMenuCommand(browser, frame, params, commandId, eventFlags);
end;

procedure TContextMenuHandlerRef.OnContextMenuDismissed(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (ContextMenuDismissedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ContextMenuDismissedPtr, [browser, frame]);
  end
  else
    inherited OnContextMenuDismissed(browser, frame);
end;

procedure TContextMenuHandlerRef.RemoveReferences;
begin
  BeforeContextMenuPtr := nil;
  RunContextMenuPtr := nil;
  ContextMenuCommandPtr := nil;
  ContextMenuDismissedPtr := nil;
  RunQuickMenuPtr := nil;
  QuickMenuCommandPtr := nil;
  QuickMenuDismissedPtr := nil;
  inherited RemoveReferences;
end;

constructor TContextMenuHandlerRef.Create;
begin
  inherited Create;
end;

destructor TContextMenuHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== DialogHandler ==}
function TDialogHandlerRef.OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback): Boolean;
begin
  Result := False;
  if (FileDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FileDialogPtr, [browser, mode, PChar(string(title)), PChar(string(defaultFilePath)), acceptFilters, Pointer(nil), Pointer(nil), callback, @Result]);
  end
  else
    Result := inherited OnFileDialog(browser, mode, title, defaultFilePath, acceptFilters, selectedAcceptFilter, callback);
end;

procedure TDialogHandlerRef.RemoveReferences;
begin
  FileDialogPtr := nil;
  inherited RemoveReferences;
end;

constructor TDialogHandlerRef.Create;
begin
  inherited Create;
end;

destructor TDialogHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== DisplayHandler ==}
procedure TDisplayHandlerRef.OnAddressChange(const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
begin
  if (AddressChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AddressChangePtr, [browser, frame, PChar(string(url))]);
  end
  else
    inherited OnAddressChange(browser, frame, url);
end;

procedure TDisplayHandlerRef.OnTitleChange(const browser: ICefBrowser; const title: ustring);
begin
  if (TitleChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TitleChangePtr, [browser, PChar(string(title))]);
  end
  else
    inherited OnTitleChange(browser, title);
end;

procedure TDisplayHandlerRef.OnFaviconUrlChange(const browser: ICefBrowser; const iconUrls: TStrings);
begin
  if (FaviconUrlChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FaviconUrlChangePtr, [browser, iconUrls]);
  end
  else
    inherited OnFaviconUrlChange(browser, iconUrls);
end;

procedure TDisplayHandlerRef.OnFullScreenModeChange(const browser: ICefBrowser; fullscreen: boolean);
begin
  if (FullScreenModeChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FullScreenModeChangePtr, [browser, fullscreen]);
  end
  else
    inherited OnFullScreenModeChange(browser, fullscreen);
end;

function TDisplayHandlerRef.OnTooltip(const browser: ICefBrowser; var Text: ustring): boolean;
var
  PRetText: PChar;
begin
    Result := False;
    if (TooltipPtr <> nil) then
    begin
      PRetText := new(PChar);
      TCEFEventCallback.SendEvent(TooltipPtr, [browser, @PRetText, @Result]);
      Text := PCharToUStr(PRetText);
      if PRetText <> nil then
         PRetText := nil;
    end
    else
      Result := inherited OnTooltip(browser, Text);
end;

procedure TDisplayHandlerRef.OnStatusMessage(const browser: ICefBrowser; const Value: ustring);
begin
  if (StatusMessagePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(StatusMessagePtr, [browser, PChar(string(Value))]);
  end
  else
    inherited OnStatusMessage(browser, Value);
end;

function TDisplayHandlerRef.OnConsoleMessage(const browser: ICefBrowser; level: TCefLogSeverity; const message_, Source: ustring; line: integer): boolean;
begin
  Result := False;
  if (ConsoleMessagePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ConsoleMessagePtr, [browser, level, PChar(string(message_)), PChar(string(Source)), line, @Result]);
  end
  else
    Result := inherited OnConsoleMessage(browser, level, message_, Source, line);
end;

function TDisplayHandlerRef.OnAutoResize(const browser: ICefBrowser; const new_size: PCefSize): boolean;
begin
  Result := False;
  if (AutoResizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AutoResizePtr, [browser, new_size, @Result]);
  end
  else
    Result := inherited OnAutoResize(browser, new_size);
end;

procedure TDisplayHandlerRef.OnLoadingProgressChange(const browser: ICefBrowser; const progress: double);
begin
  if (LoadingProgressChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadingProgressChangePtr, [browser, @progress]);
  end
  else
    inherited OnLoadingProgressChange(browser, progress);
end;

procedure TDisplayHandlerRef.OnCursorChange(const browser: ICefBrowser; cursor_: TCefCursorHandle; CursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo; var aResult: boolean);
begin
  if (CursorChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CursorChangePtr, [browser, cursor_, CursorType, customCursorInfo, @aResult]);
  end
  else
    inherited OnCursorChange(browser, cursor_, CursorType, customCursorInfo, aResult);
end;

procedure TDisplayHandlerRef.RemoveReferences;
begin
  AddressChangePtr := nil;
  TitleChangePtr := nil;
  FaviconUrlChangePtr := nil;
  FullScreenModeChangePtr := nil;
  TooltipPtr := nil;
  StatusMessagePtr := nil;
  ConsoleMessagePtr := nil;
  AutoResizePtr := nil;
  LoadingProgressChangePtr := nil;
  CursorChangePtr := nil;
  MediaAccessChangePtr := nil;
  inherited RemoveReferences;
end;

constructor TDisplayHandlerRef.Create;
begin
  inherited Create;
end;

destructor TDisplayHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== DownloadHandler ==}
procedure TDownloadHandlerRef.OnBeforeDownload(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
begin
  if (BeforeDownloadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeDownloadPtr, [browser, downloadItem, PChar(string(suggestedName)), callback, Pointer(nil)]);
  end
  else
    inherited OnBeforeDownload(browser, downloadItem, suggestedName, callback);
end;

procedure TDownloadHandlerRef.OnDownloadUpdated(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
begin
  if (DownloadUpdatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DownloadUpdatedPtr, [browser, downloadItem, callback]);
  end
  else
    inherited OnDownloadUpdated(browser, downloadItem, callback);
end;

procedure TDownloadHandlerRef.RemoveReferences;
begin
  CanDownloadPtr := nil;
  BeforeDownloadPtr := nil;
  DownloadUpdatedPtr := nil;
  inherited RemoveReferences;
end;

constructor TDownloadHandlerRef.Create;
begin
  inherited Create;
end;

destructor TDownloadHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;


{== DragHandler ==}
function TDragHandlerRef.OnDragEnter(const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations): boolean;
begin
  Result := False;
  if (DragEnterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DragEnterPtr, [browser, dragData, mask, @Result]);
  end
  else
    Result := inherited OnDragEnter(browser, dragData, mask);
end;

procedure TDragHandlerRef.OnDraggableRegionsChanged(const browser: ICefBrowser; const frame: ICefFrame; regionsCount: nativeuint; const regions: PCefDraggableRegionArray);
begin
  if (DraggableRegionsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DraggableRegionsChangedPtr, [browser, frame, integer(regionsCount), regions]);
  end
  else
    inherited OnDraggableRegionsChanged(browser, frame, regionsCount, regions);
end;

procedure TDragHandlerRef.RemoveReferences;
begin
  DragEnterPtr := nil;
  inherited RemoveReferences;
end;

constructor TDragHandlerRef.Create;
begin
  inherited Create;
end;

destructor TDragHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== FindHandler ==}
procedure TFindHandlerRef.OnFindResult(const browser: ICefBrowser; identifier, Count: integer; const selectionRect: PCefRect; activeMatchOrdinal: integer; finalUpdate: boolean);
begin
  if (FindResultPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FindResultPtr, [browser, identifier, Count, selectionRect, activeMatchOrdinal, finalUpdate]);
  end;
end;

procedure TFindHandlerRef.RemoveReferences;
begin
  FindResultPtr := nil;
  inherited RemoveReferences;
end;

constructor TFindHandlerRef.Create;
begin
  inherited Create;
end;

destructor TFindHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== FocusHandler ==}
procedure TFocusHandlerRef.OnTakeFocus(const browser: ICefBrowser; Next: boolean);
begin
  if (TakeFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TakeFocusPtr, [browser, Next]);
  end
  else
    inherited OnTakeFocus(browser, Next);
end;

function TFocusHandlerRef.OnSetFocus(const browser: ICefBrowser; Source: TCefFocusSource): boolean;
begin
  Result := False;
  if (SetFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SetFocusPtr, [browser, integer(Source), @Result]);
  end
  else
    Result := inherited OnSetFocus(browser, Source);
end;

procedure TFocusHandlerRef.OnGotFocus(const browser: ICefBrowser);
begin
  if (GotFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GotFocusPtr, [browser]);
  end
  else
    inherited OnGotFocus(browser);
end;

procedure TFocusHandlerRef.RemoveReferences;
begin
  TakeFocusPtr := nil;
  SetFocusPtr := nil;
  GotFocusPtr := nil;
  inherited RemoveReferences;
end;

constructor TFocusHandlerRef.Create;
begin
  inherited Create;
end;

destructor TFocusHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== JsDialogHandler ==}
function TJsDialogHandlerRef.OnJsdialog(const browser: ICefBrowser; const originUrl: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: boolean): boolean;
begin
  Result := False;
  if (JsdialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(JsdialogPtr, [browser, PChar(string(originUrl)), integer(dialogType), PChar(string(messageText)), PChar(string(defaultPromptText)), callback, @suppressMessage, @Result]);
  end
  else
    Result := inherited OnJsdialog(browser, originUrl, dialogType, messageText, defaultPromptText, callback, suppressMessage);
end;

function TJsDialogHandlerRef.OnBeforeUnloadDialog(const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback): boolean;
begin
  Result := False;
  if (BeforeUnloadDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeUnloadDialogPtr, [browser, PChar(string(messageText)), isReload, callback, @Result]);
  end
  else
    Result := inherited OnBeforeUnloadDialog(browser, messageText, isReload, callback);
end;

procedure TJsDialogHandlerRef.OnResetDialogState(const browser: ICefBrowser);
begin
  if (ResetDialogStatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResetDialogStatePtr, [browser]);
  end
  else
    inherited OnResetDialogState(browser);
end;

procedure TJsDialogHandlerRef.OnDialogClosed(const browser: ICefBrowser);
begin
  if (DialogClosedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DialogClosedPtr, [browser]);
  end
  else
    inherited OnDialogClosed(browser);
end;

procedure TJsDialogHandlerRef.RemoveReferences;
begin
  JsdialogPtr := nil;
  BeforeUnloadDialogPtr := nil;
  ResetDialogStatePtr := nil;
  DialogClosedPtr := nil;
  inherited RemoveReferences;
end;

constructor TJsDialogHandlerRef.Create;
begin
  inherited Create;
end;

destructor TJsDialogHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;


{== KeyboardHandler ==}
function TKeyboardHandlerRef.OnPreKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean): boolean;
begin
  Result := False;
  if (PreKeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PreKeyEventPtr, [browser, event, osEvent, @isKeyboardShortcut, @Result]);
  end
  else
    Result := inherited OnPreKeyEvent(browser, event, osEvent, isKeyboardShortcut);
end;

function TKeyboardHandlerRef.OnKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle): boolean;
begin
  Result := False;
  if (KeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(KeyEventPtr, [browser, event, osEvent, @Result]);
  end
  else
    Result := inherited OnKeyEvent(browser, event, osEvent);
end;

procedure TKeyboardHandlerRef.RemoveReferences;
begin
  PreKeyEventPtr := nil;
  KeyEventPtr := nil;
  inherited RemoveReferences;
end;

constructor TKeyboardHandlerRef.Create;
begin
  inherited Create;
end;

destructor TKeyboardHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;


{== LifeSpanHandler ==}
function TLifeSpanHandlerRef.OnBeforePopup(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl,
  targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings;
  var extra_info: ICefDictionaryValue; var noJavascriptAccess: boolean): boolean;
var
  beforePopupInfo  : RBeforePopupInfo;
  rpopupFeatures   : PMCefPopupFeatures;
  rwindowInfo      : PMCefWindowInfo;
  rbrowserSettings : PMCefBrowserSettings;
  TempTargetDisposition: Integer;
begin
  Result := False;
  if (BeforePopupPtr <> nil) then
  begin
    //popup info
    beforePopupInfo.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo.TargetFrameName := PChar(string(targetFrameName));
    TempTargetDisposition := Integer(targetDisposition);
    beforePopupInfo.TargetDisposition := PInteger(@TempTargetDisposition);
    beforePopupInfo.UserGesture := @userGesture;
    // popupFeatures
    rpopupFeatures := CefPopupFeaturesToGoCefPopupFeatures(popupFeatures);
    // windowInfo
    rwindowInfo := CefWindowInfoToGoCefWindowInfo(windowInfo);
    // settings
    rbrowserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    //event
    TCEFEventCallback.SendEvent(BeforePopupPtr, [browser, frame, @beforePopupInfo, @rpopupFeatures, @rwindowInfo, @client, @rbrowserSettings, @extra_info, @noJavascriptAccess, @Result]);
    windowInfo := GoCefWindowInfoToCefWindowInfo(rwindowInfo);
  end
  else
    Result := inherited OnBeforePopup(browser, frame, targetUrl, targetFrameName, targetDisposition, userGesture, popupFeatures, windowInfo, client, settings, extra_info, noJavascriptAccess);
end;

procedure TLifeSpanHandlerRef.OnAfterCreated(const browser: ICefBrowser);
begin
  if (AfterCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AfterCreatedPtr, [browser]);
  end
  else
    inherited OnAfterCreated(browser);
end;

function TLifeSpanHandlerRef.DoClose(const browser: ICefBrowser): boolean;
begin
  Result := False;
  if (DoClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DoClosePtr, [browser, @Result]);
  end
  else
    Result := inherited DoClose(browser);
end;

procedure TLifeSpanHandlerRef.OnBeforeClose(const browser: ICefBrowser);
begin
  if (BeforeClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeClosePtr, [browser]);
  end
  else
    inherited OnBeforeClose(browser);
end;

procedure TLifeSpanHandlerRef.RemoveReferences;
begin
  BeforePopupPtr := nil;
  AfterCreatedPtr := nil;
  DoClosePtr := nil;
  BeforeClosePtr := nil;
  inherited RemoveReferences;
end;

constructor TLifeSpanHandlerRef.Create;
begin
  inherited Create;
end;

destructor TLifeSpanHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== LoadHandler ==}
procedure TLoadHandlerRef.OnLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  if (LoadingStateChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadingStateChangePtr, [browser, isLoading, canGoBack, canGoForward]);
  end
  else
    inherited OnLoadingStateChange(browser, isLoading, canGoBack, canGoForward);
end;

procedure TLoadHandlerRef.OnLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
begin
  if (LoadStartPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadStartPtr, [browser, frame, transitionType]);
  end
  else
    inherited OnLoadStart(browser, frame, transitionType);
end;

procedure TLoadHandlerRef.OnLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
begin
  if (LoadEndPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadEndPtr, [browser, frame, httpStatusCode]);
  end
  else
    inherited OnLoadEnd(browser, frame, httpStatusCode);
end;

procedure TLoadHandlerRef.OnLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
begin
  if (LoadErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadErrorPtr, [browser, frame, errorCode, PChar(string(errorText)), PChar(string(failedUrl))]);
  end
  else
    inherited OnLoadError(browser, frame, errorCode, errorText, failedUrl);
end;

procedure TLoadHandlerRef.RemoveReferences;
begin
  LoadingStateChangePtr := nil;
  LoadStartPtr := nil;
  LoadEndPtr := nil;
  LoadErrorPtr := nil;
  inherited RemoveReferences;
end;

constructor TLoadHandlerRef.Create;
begin
  inherited Create;
end;

destructor TLoadHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;


{== PrintHandler ==}
procedure TPrintHandlerRef.OnPrintStart(const browser: ICefBrowser);
begin
  if (PrintStartPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintStartPtr, [browser]);
  end;
end;

procedure TPrintHandlerRef.OnPrintSettings(const browser: ICefBrowser; const settings: ICefPrintSettings; getDefaults: boolean);
begin
  if (PrintSettingsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintSettingsPtr, [browser, settings, getDefaults]);
  end;
end;

procedure TPrintHandlerRef.OnPrintDialog(const browser: ICefBrowser; hasSelection: boolean; const callback: ICefPrintDialogCallback; var aResult: boolean);
begin
  if (PrintDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintDialogPtr, [browser, hasSelection, callback, @aResult]);
  end
  else
    inherited OnPrintDialog(browser, hasSelection, callback, aResult);
end;

procedure TPrintHandlerRef.OnPrintJob(const browser: ICefBrowser; const documentName, PDFFilePath: ustring; const callback: ICefPrintJobCallback; var aResult: boolean);
begin
  if (PrintJobPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintJobPtr, [browser, PChar(string(documentName)), PChar(string(PDFFilePath)), callback, @aResult]);
  end
  else
    inherited OnPrintJob(browser, documentName, PDFFilePath, callback, aResult);
end;

procedure TPrintHandlerRef.OnPrintReset(const browser: ICefBrowser);
begin
  if (PrintResetPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintResetPtr, [browser]);
  end;
end;

procedure TPrintHandlerRef.GetPDFPaperSize(deviceUnitsPerInch: Integer; var aResult: TCefSize);
begin
  if (PDFPaperSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PDFPaperSizePtr, [Pointer(0), deviceUnitsPerInch, @aResult]);
  end
  else
    inherited GetPDFPaperSize(deviceUnitsPerInch, aResult);
end;

procedure TPrintHandlerRef.RemoveReferences;
begin
  PrintStartPtr := nil;
  PrintSettingsPtr := nil;
  PrintDialogPtr := nil;
  PrintJobPtr := nil;
  PrintResetPtr := nil;
  PDFPaperSizePtr := nil;
  //inherited RemoveReferences;
end;

constructor TPrintHandlerRef.Create;
begin
  inherited Create;
end;

destructor TPrintHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== RenderHandler ==}
procedure TRenderHandlerRef.GetAccessibilityHandler(var aAccessibilityHandler: ICefAccessibilityHandler);
begin
  if (AccessibilityHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AccessibilityHandlerPtr, [@aAccessibilityHandler]);
  end
  else
    inherited GetAccessibilityHandler(aAccessibilityHandler);
end;

function TRenderHandlerRef.GetRootScreenRect(const browser: ICefBrowser; var rect: TCefRect): boolean;
begin
  Result := False;
  if (RootScreenRectPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RootScreenRectPtr, [browser, @rect, @Result]);
  end
  else
    Result := inherited GetRootScreenRect(browser, rect);
end;

procedure TRenderHandlerRef.GetViewRect(const browser: ICefBrowser; var rect: TCefRect);
begin
  if (ViewRectPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ViewRectPtr, [browser, @rect]);
  end
  else
    inherited GetViewRect(browser, rect);
end;

function TRenderHandlerRef.GetScreenPoint(const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer): boolean;
begin
  Result := False;
  if (ScreenPointPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScreenPointPtr, [browser, viewX, viewY, @screenX, @screenY, @Result]);
  end
  else
    Result := inherited GetScreenPoint(browser, viewX, viewY, screenX, screenY);
end;

function TRenderHandlerRef.GetScreenInfo(const browser: ICefBrowser; var screenInfo: TCefScreenInfo): boolean;
begin
  Result := False;
  if (ScreenInfoPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScreenInfoPtr, [browser, @screenInfo, @Result]);
  end
  else
    Result := inherited GetScreenInfo(browser, screenInfo);
end;

procedure TRenderHandlerRef.OnPopupShow(const browser: ICefBrowser; Show: boolean);
begin
  if (PopupShowPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupShowPtr, [browser, Show]);
  end
  else
    inherited OnPopupShow(browser, Show);
end;

procedure TRenderHandlerRef.OnPopupSize(const browser: ICefBrowser; const rect: PCefRect);
begin
  if (PopupSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupSizePtr, [browser, rect]);
  end
  else
    inherited OnPopupSize(browser, rect);
end;

procedure TRenderHandlerRef.OnPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
begin
  if (PaintPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PaintPtr, [browser, kind, dirtyRectsCount, dirtyRects, buffer, Width, Height]);
  end
  else
    inherited OnPaint(browser, kind, dirtyRectsCount, dirtyRects, buffer, Width, Height);
end;

procedure TRenderHandlerRef.OnAcceleratedPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; shared_handle: Pointer);
var
  TempPaintInfo: TCefAcceleratedPaintInfo;
begin
  if (AcceleratedPaintPtr <> nil) then
  begin
    TempPaintInfo.shared_texture_handle := shared_handle;
    TempPaintInfo.format := nil;
    TCEFEventCallback.SendEvent(AcceleratedPaintPtr, [browser, kind, dirtyRectsCount, dirtyRects, @TempPaintInfo]);
  end
  else
    inherited OnAcceleratedPaint(browser, kind, dirtyRectsCount, dirtyRects, shared_handle);
end;

function TRenderHandlerRef.OnStartDragging(const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer): boolean;
begin
  Result := False;
  if (StartDraggingPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(StartDraggingPtr, [browser, dragData, allowedOps, x, y, @Result]);
  end
  else
    Result := inherited OnStartDragging(browser, dragData, allowedOps, x, y);
end;

procedure TRenderHandlerRef.OnUpdateDragCursor(const browser: ICefBrowser; operation: TCefDragOperation);
begin
  if (UpdateDragCursorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(UpdateDragCursorPtr, [browser, operation]);
  end
  else
    inherited OnUpdateDragCursor(browser, operation);
end;

procedure TRenderHandlerRef.OnScrollOffsetChanged(const browser: ICefBrowser; x, y: double);
begin
  if (ScrollOffsetChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScrollOffsetChangedPtr, [browser, @x, @y]);
  end
  else
    inherited OnScrollOffsetChanged(browser, x, y);
end;

procedure TRenderHandlerRef.OnIMECompositionRangeChanged(const browser: ICefBrowser; const selected_range: PCefRange; character_boundsCount: nativeuint; const character_bounds: PCefRect);
begin
  if (IMECompositionRangeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(IMECompositionRangeChangedPtr, [browser, selected_range, character_boundsCount, character_bounds]);
  end
  else
    inherited OnIMECompositionRangeChanged(browser, selected_range, character_boundsCount, character_bounds);
end;

procedure TRenderHandlerRef.OnTextSelectionChanged(const browser: ICefBrowser; const selected_text: ustring; const selected_range: PCefRange);
begin
  if (TextSelectionChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TextSelectionChangedPtr, [browser, PChar(string(selected_text)), selected_range]);
  end
  else
    inherited OnTextSelectionChanged(browser, selected_text, selected_range);
end;

procedure TRenderHandlerRef.OnVirtualKeyboardRequested(const browser: ICefBrowser; input_mode: TCefTextInpuMode);
begin
  if (VirtualKeyboardRequestedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(VirtualKeyboardRequestedPtr, [browser, input_mode]);
  end
  else
    inherited OnVirtualKeyboardRequested(browser, input_mode);
end;

procedure TRenderHandlerRef.RemoveReferences;
begin
  AccessibilityHandlerPtr := nil;
  RootScreenRectPtr := nil;
  ViewRectPtr := nil;
  ScreenPointPtr := nil;
  ScreenInfoPtr := nil;
  PopupShowPtr := nil;
  PopupSizePtr := nil;
  PaintPtr := nil;
  AcceleratedPaintPtr := nil;
  TouchHandleSizePtr := nil;
  TouchHandleStateChangedPtr := nil;
  StartDraggingPtr := nil;
  UpdateDragCursorPtr := nil;
  ScrollOffsetChangedPtr := nil;
  IMECompositionRangeChangedPtr := nil;
  TextSelectionChangedPtr := nil;
  VirtualKeyboardRequestedPtr := nil;
  inherited RemoveReferences;
end;

constructor TRenderHandlerRef.Create;
begin
  inherited Create;
end;

destructor TRenderHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

{== RequestHandler ==}
function TRequestHandlerRef.OnBeforeBrowse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: boolean): boolean;
begin
  Result := False;
  if (BeforeBrowsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeBrowsePtr, [browser, frame, request, user_gesture, isRedirect, @Result]);
  end
  else
    Result := inherited OnBeforeBrowse(browser, frame, request, user_gesture, isRedirect);
end;

function TRequestHandlerRef.OnOpenUrlFromTab(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean): boolean;
begin
  Result := False;
  if (OpenUrlFromTabPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OpenUrlFromTabPtr, [browser, frame, PChar(string(targetUrl)), targetDisposition, userGesture, @Result]);
  end
  else
    Result := inherited OnOpenUrlFromTab(browser, frame, targetUrl, targetDisposition, userGesture);
end;

procedure TRequestHandlerRef.GetResourceRequestHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aResourceRequestHandler: ICefResourceRequestHandler);
begin
  if (GetResourceRequestHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceRequestHandlerPtr, [browser, frame, request, is_navigation, is_download, PChar(string(request_initiator)), @disable_default_handling, @aResourceRequestHandler]);
  end
  else
    inherited GetResourceRequestHandler(browser, frame, request, is_navigation, is_download, request_initiator, disable_default_handling, aResourceRequestHandler);
end;

function TRequestHandlerRef.GetAuthCredentials(const browser: ICefBrowser; const originUrl: ustring; isProxy: boolean; const host: ustring; port: integer; const realm, scheme: ustring; const callback: ICefAuthCallback): boolean;
begin
  Result := False;
  if (GetAuthCredentialsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetAuthCredentialsPtr, [browser, PChar(string(originUrl)), isProxy, PChar(string(host)), port, PChar(string(realm)), PChar(string(scheme)), callback, @Result]);
  end
  else
    Result := inherited GetAuthCredentials(browser, originUrl, isProxy, host, port, realm, scheme, callback);
end;

function TRequestHandlerRef.OnCertificateError(const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback): Boolean;
begin
  Result := False;
  if (CertificateErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CertificateErrorPtr, [browser, certError, PChar(string(requestUrl)), sslInfo, callback, @Result]);
  end
  else
    Result := inherited OnCertificateError(browser, certError, requestUrl, sslInfo, callback);
end;

function TRequestHandlerRef.OnSelectClientCertificate(const browser: ICefBrowser; isProxy: boolean; const host: ustring; port: integer; certificatesCount: nativeuint; const certificates: TCefX509CertificateArray; const callback: ICefSelectClientCertificateCallback): boolean;
begin
  Result := False;
  if (SelectClientCertificatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SelectClientCertificatePtr, [browser, isProxy, PChar(string(host)), port, certificatesCount, @certificates, callback, @Result]);
  end
  else
    Result := inherited OnSelectClientCertificate(browser, isProxy, host, port, certificatesCount, certificates, callback);
end;

procedure TRequestHandlerRef.OnRenderViewReady(const browser: ICefBrowser);
begin
  if (RenderViewReadyPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RenderViewReadyPtr, [browser]);
  end
  else
    inherited OnRenderViewReady(browser);
end;

procedure TRequestHandlerRef.OnRenderProcessTerminated(const browser: ICefBrowser; status: TCefTerminationStatus);
begin
  if (RenderProcessTerminatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RenderProcessTerminatedPtr, [browser, status, 0, PChar('')]);
  end
  else
    inherited OnRenderProcessTerminated(browser, status);
end;

procedure TRequestHandlerRef.OnDocumentAvailableInMainFrame(const browser: ICefBrowser);
begin
  if (DocumentAvailableInMainFramePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DocumentAvailableInMainFramePtr, [browser]);
  end
  else
    inherited OnDocumentAvailableInMainFrame(browser);
end;

procedure TRequestHandlerRef.RemoveReferences;
begin
  BeforeBrowsePtr := nil;
  OpenUrlFromTabPtr := nil;
  GetResourceRequestHandlerPtr := nil;
  GetAuthCredentialsPtr := nil;
  CertificateErrorPtr := nil;
  SelectClientCertificatePtr := nil;
  RenderViewReadyPtr := nil;
  RenderProcessTerminatedPtr := nil;
  DocumentAvailableInMainFramePtr := nil;
  inherited RemoveReferences;
end;

constructor TRequestHandlerRef.Create;
begin
  inherited Create;
end;

destructor TRequestHandlerRef.Destroy;
begin
  RemoveReferences;
  inherited Destroy;
end;

end.
