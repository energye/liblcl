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
  uCEFTypes, uCEFInterfaces, uCEFClient, uCEFAudioHandler, uCEFCommandHandler, uCEFContextMenuHandler, uCEFDialogHandler, uCEFDisplayHandler,
  uCEFDownloadHandler, uCEFDragHandler, uCEFFindHandler, uCEFFocusHandler, uCEFFrameHandler, uCEFPermissionHandler, uCEFJsdialogHandler, uCEFKeyboardHandler,
  uCEFLifeSpanHandler, uCEFLoadHandler, uCEFPrintHandler, uCEFRenderHandler, uCEFRequestHandler,
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

  {== CommandHandler ==}
  TCommandHandlerRef = class(TCefCommandHandlerOwn)
  public
    ChromeCommandPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnChromeCommand(const browser: ICefBrowser; command_id: integer; disposition: TCefWindowOpenDisposition): boolean; override;
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
    function RunQuickMenu(const browser: ICefBrowser; const frame: ICefFrame; location: PCefPoint; size: PCefSize; edit_state_flags: TCefQuickMenuEditStateFlags; const callback: ICefRunQuickMenuCallback): boolean; override;
    function OnQuickMenuCommand(const browser: ICefBrowser; const frame: ICefFrame; command_id: integer; event_flags: TCefEventFlags): boolean; override;
    procedure OnQuickMenuDismissed(const browser: ICefBrowser; const frame: ICefFrame); override;
    procedure RemoveReferences; override;
  end;

  {== DialogHandler ==}
  TDialogHandlerRef = class(TCefDialogHandlerOwn)
  public
    FileDialogPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; const callback: ICefFileDialogCallback): boolean; override;
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
    procedure OnMediaAccessChange(const browser: ICefBrowser; has_video_access, has_audio_access: boolean); override;
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
    function CanDownload(const browser: ICefBrowser; const url, request_method: ustring): boolean; override;
    procedure OnBeforeDownload(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback); override;
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

  {== FrameHandler ==}
  TFrameHandlerRef = class(TCefFrameHandlerOwn)
  public
    FrameCreatedPtr: Pointer;
    FrameAttachedPtr: Pointer;
    FrameDetachedPtr: Pointer;
    MainFrameChangedPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnFrameCreated(const browser: ICefBrowser; const frame: ICefFrame); override;
    procedure OnFrameAttached(const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean); override;
    procedure OnFrameDetached(const browser: ICefBrowser; const frame: ICefFrame); override;
    procedure OnMainFrameChanged(const browser: ICefBrowser; const old_frame, new_frame: ICefFrame); override;
    procedure RemoveReferences; override;
  end;

  {== PermissionHandler ==}
  TPermissionHandlerRef = class(TCefPermissionHandlerOwn)
  public
    RequestMediaAccessPermissionPtr: Pointer;
    ShowPermissionPromptPtr: Pointer;
    DismissPermissionPromptPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function OnRequestMediaAccessPermission(const browser: ICefBrowser; const frame: ICefFrame; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefMediaAccessCallback): boolean; override;
    function OnShowPermissionPrompt(const browser: ICefBrowser; prompt_id: uint64; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefPermissionPromptCallback): boolean; override;
    procedure OnDismissPermissionPrompt(const browser: ICefBrowser; prompt_id: uint64; Result: TCefPermissionRequestResult); override;
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
    procedure GetPDFPaperSize(const browser: ICefBrowser; deviceUnitsPerInch: integer; var aResult: TCefSize); override;
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
    procedure OnAcceleratedPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; shared_handle: Pointer); override;
    procedure GetTouchHandleSize(const browser: ICefBrowser; orientation: TCefHorizontalAlignment; var size: TCefSize); override;
    procedure OnTouchHandleStateChanged(const browser: ICefBrowser; const state: TCefTouchHandleState); override;
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
    function OnCertificateError(const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefCallback): boolean; override;
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
  end;
end;

procedure TAudioHandlerRef.OnAudioStreamStarted(const browser: ICefBrowser; const params: TCefAudioParameters; channels: integer);
begin
  if (AudioStreamStartedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamStartedPtr, [browser, @params, channels]);
  end;
end;

procedure TAudioHandlerRef.OnAudioStreamPacket(const browser: ICefBrowser; const Data: PPSingle; frames: integer; pts: int64);
begin
  if (AudioStreamPacketPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamPacketPtr, [browser, Data, frames, pts]);
  end;
end;

procedure TAudioHandlerRef.OnAudioStreamStopped(const browser: ICefBrowser);
begin
  if (AudioStreamStoppedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamStoppedPtr, [browser]);
  end;
end;

procedure TAudioHandlerRef.OnAudioStreamError(const browser: ICefBrowser; const message_: ustring);
begin
  if (AudioStreamErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AudioStreamErrorPtr, [browser, PChar(string(message_))]);
  end;
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
  inherited Destroy;
end;

{== CommandHandler ==}
function TCommandHandlerRef.OnChromeCommand(const browser: ICefBrowser; command_id: integer; disposition: TCefWindowOpenDisposition): boolean;
begin
  Result := False;
  if (ChromeCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChromeCommandPtr, [browser, command_id, disposition, @Result]);
  end;
end;

procedure TCommandHandlerRef.RemoveReferences;
begin
  ChromeCommandPtr := nil;
  inherited RemoveReferences;
end;

constructor TCommandHandlerRef.Create;
begin
  inherited Create;
end;

destructor TCommandHandlerRef.Destroy;
begin
  inherited Destroy;
end;

{== ContextMenuHandler ==}
procedure TContextMenuHandlerRef.OnBeforeContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel);
begin
  if (BeforeContextMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeContextMenuPtr, [browser, frame, params, model]);
  end;
end;

function TContextMenuHandlerRef.RunContextMenu(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; const model: ICefMenuModel; const callback: ICefRunContextMenuCallback): boolean;
begin
  Result := False;
  if (RunContextMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RunContextMenuPtr, [browser, frame, params, model, callback, @Result]);
  end;
end;

function TContextMenuHandlerRef.OnContextMenuCommand(const browser: ICefBrowser; const frame: ICefFrame; const params: ICefContextMenuParams; commandId: integer; eventFlags: TCefEventFlags): boolean;
begin
  Result := False;
  if (ContextMenuCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ContextMenuCommandPtr, [browser, frame, params, commandId, eventFlags, @Result]);
  end;
end;

procedure TContextMenuHandlerRef.OnContextMenuDismissed(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (ContextMenuDismissedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ContextMenuDismissedPtr, [browser, frame]);
  end;
end;

function TContextMenuHandlerRef.RunQuickMenu(const browser: ICefBrowser; const frame: ICefFrame; location: PCefPoint; size: PCefSize; edit_state_flags: TCefQuickMenuEditStateFlags; const callback: ICefRunQuickMenuCallback): boolean;
begin
  Result := False;
  if (RunQuickMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RunQuickMenuPtr, [browser, frame, location, size, edit_state_flags, callback, @Result]);
  end;
end;

function TContextMenuHandlerRef.OnQuickMenuCommand(const browser: ICefBrowser; const frame: ICefFrame; command_id: integer; event_flags: TCefEventFlags): boolean;
begin
  Result := False;
  if (QuickMenuCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(QuickMenuCommandPtr, [browser, frame, command_id, event_flags, @Result]);
  end;
end;

procedure TContextMenuHandlerRef.OnQuickMenuDismissed(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (QuickMenuDismissedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(QuickMenuDismissedPtr, [browser, frame]);
  end;
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
  inherited Destroy;
end;

{== DialogHandler ==}
function TDialogHandlerRef.OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; const callback: ICefFileDialogCallback): boolean;
begin
  if (FileDialogPtr <> nil) then
  begin
    Result := False;
    TCEFEventCallback.SendEvent(FileDialogPtr, [browser, mode, PChar(string(title)), PChar(string(defaultFilePath)), acceptFilters, callback, @Result]);
  end;
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
  inherited Destroy;
end;

{== DisplayHandler ==}
procedure TDisplayHandlerRef.OnAddressChange(const browser: ICefBrowser; const frame: ICefFrame; const url: ustring);
begin
  if (AddressChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AddressChangePtr, [browser, frame, PChar(string(url))]);
  end;
end;

procedure TDisplayHandlerRef.OnTitleChange(const browser: ICefBrowser; const title: ustring);
begin
  if (TitleChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TitleChangePtr, [browser, PChar(string(title))]);
  end;
end;

procedure TDisplayHandlerRef.OnFaviconUrlChange(const browser: ICefBrowser; const iconUrls: TStrings);
begin
  if (FaviconUrlChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FaviconUrlChangePtr, [browser, iconUrls]);
  end;
end;

procedure TDisplayHandlerRef.OnFullScreenModeChange(const browser: ICefBrowser; fullscreen: boolean);
begin
  if (FullScreenModeChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FullScreenModeChangePtr, [browser, fullscreen]);
  end;
end;

function TDisplayHandlerRef.OnTooltip(const browser: ICefBrowser; var Text: ustring): boolean;
var
  PRetText: PChar;
begin
  if (TooltipPtr <> nil) then
  begin
    PRetText := new(PChar);
    TCEFEventCallback.SendEvent(TooltipPtr, [browser, @PRetText]);
    Text := PCharToUStr(PRetText);
    PRetText := nil;
  end;
end;

procedure TDisplayHandlerRef.OnStatusMessage(const browser: ICefBrowser; const Value: ustring);
begin
  if (StatusMessagePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(StatusMessagePtr, [browser, PChar(string(Value))]);
  end;
end;

function TDisplayHandlerRef.OnConsoleMessage(const browser: ICefBrowser; level: TCefLogSeverity; const message_, Source: ustring; line: integer): boolean;
begin
  if (ConsoleMessagePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ConsoleMessagePtr, [browser, level, PChar(string(message_)), PChar(string(Source)), line]);
  end;
end;

function TDisplayHandlerRef.OnAutoResize(const browser: ICefBrowser; const new_size: PCefSize): boolean;
begin
  if (AutoResizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AutoResizePtr, [browser, new_size]);
  end;
end;

procedure TDisplayHandlerRef.OnLoadingProgressChange(const browser: ICefBrowser; const progress: double);
begin
  if (LoadingProgressChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadingProgressChangePtr, [browser, @progress]);
  end;
end;

procedure TDisplayHandlerRef.OnCursorChange(const browser: ICefBrowser; cursor_: TCefCursorHandle; CursorType: TCefCursorType; const customCursorInfo: PCefCursorInfo; var aResult: boolean);
begin
  if (CursorChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CursorChangePtr, [browser, cursor_, CursorType, customCursorInfo, @aResult]);
  end;
end;

procedure TDisplayHandlerRef.OnMediaAccessChange(const browser: ICefBrowser; has_video_access, has_audio_access: boolean);
begin
  if (MediaAccessChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MediaAccessChangePtr, [browser, has_video_access, has_audio_access]);
  end;
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
  inherited Destroy;
end;

{== DownloadHandler ==}
function TDownloadHandlerRef.CanDownload(const browser: ICefBrowser; const url, request_method: ustring): boolean;
begin
  if (CanDownloadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CanDownloadPtr, []);
  end;
end;

procedure TDownloadHandlerRef.OnBeforeDownload(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const suggestedName: ustring; const callback: ICefBeforeDownloadCallback);
begin
  if (BeforeDownloadPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeDownloadPtr, []);
  end;
end;

procedure TDownloadHandlerRef.OnDownloadUpdated(const browser: ICefBrowser; const downloadItem: ICefDownloadItem; const callback: ICefDownloadItemCallback);
begin
  if (DownloadUpdatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DownloadUpdatedPtr, []);
  end;
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
  inherited Destroy;
end;


{== DragHandler ==}
function TDragHandlerRef.OnDragEnter(const browser: ICefBrowser; const dragData: ICefDragData; mask: TCefDragOperations): boolean;
begin
  if (DragEnterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DragEnterPtr, []);
  end;
end;

procedure TDragHandlerRef.OnDraggableRegionsChanged(const browser: ICefBrowser; const frame: ICefFrame; regionsCount: nativeuint; const regions: PCefDraggableRegionArray);
begin
  if (DraggableRegionsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DraggableRegionsChangedPtr, []);
  end;
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
  inherited Destroy;
end;

{== FindHandler ==}
procedure TFindHandlerRef.OnFindResult(const browser: ICefBrowser; identifier, Count: integer; const selectionRect: PCefRect; activeMatchOrdinal: integer; finalUpdate: boolean);
begin
  if (FindResultPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FindResultPtr, []);
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
  inherited Destroy;
end;

{== FocusHandler ==}
procedure TFocusHandlerRef.OnTakeFocus(const browser: ICefBrowser; Next: boolean);
begin
  if (TakeFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TakeFocusPtr, []);
  end;
end;

function TFocusHandlerRef.OnSetFocus(const browser: ICefBrowser; Source: TCefFocusSource): boolean;
begin
  if (SetFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SetFocusPtr, []);
  end;
end;

procedure TFocusHandlerRef.OnGotFocus(const browser: ICefBrowser);
begin
  if (GotFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GotFocusPtr, []);
  end;
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
  inherited Destroy;
end;

{== FrameHandler ==}
procedure TFrameHandlerRef.OnFrameCreated(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (FrameCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FrameCreatedPtr, []);
  end;
end;

procedure TFrameHandlerRef.OnFrameAttached(const browser: ICefBrowser; const frame: ICefFrame; reattached: boolean);
begin
  if (FrameAttachedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FrameAttachedPtr, []);
  end;
end;

procedure TFrameHandlerRef.OnFrameDetached(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (FrameDetachedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FrameDetachedPtr, []);
  end;
end;

procedure TFrameHandlerRef.OnMainFrameChanged(const browser: ICefBrowser; const old_frame, new_frame: ICefFrame);
begin
  if (MainFrameChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MainFrameChangedPtr, []);
  end;
end;

procedure TFrameHandlerRef.RemoveReferences;
begin
  FrameCreatedPtr := nil;
  FrameAttachedPtr := nil;
  FrameDetachedPtr := nil;
  MainFrameChangedPtr := nil;
  inherited RemoveReferences;
end;

constructor TFrameHandlerRef.Create;
begin
  inherited Create;
end;

destructor TFrameHandlerRef.Destroy;
begin
  inherited Destroy;
end;


{== PermissionHandler ==}
function TPermissionHandlerRef.OnRequestMediaAccessPermission(const browser: ICefBrowser; const frame: ICefFrame; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefMediaAccessCallback): boolean;
begin
  if (RequestMediaAccessPermissionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RequestMediaAccessPermissionPtr, []);
  end;
end;

function TPermissionHandlerRef.OnShowPermissionPrompt(const browser: ICefBrowser; prompt_id: uint64; const requesting_origin: ustring; requested_permissions: cardinal; const callback: ICefPermissionPromptCallback): boolean;
begin
  if (ShowPermissionPromptPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ShowPermissionPromptPtr, []);
  end;
end;

procedure TPermissionHandlerRef.OnDismissPermissionPrompt(const browser: ICefBrowser; prompt_id: uint64; Result: TCefPermissionRequestResult);
begin
  if (DismissPermissionPromptPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DismissPermissionPromptPtr, []);
  end;
end;

procedure TPermissionHandlerRef.RemoveReferences;
begin
  RequestMediaAccessPermissionPtr := nil;
  ShowPermissionPromptPtr := nil;
  DismissPermissionPromptPtr := nil;
  inherited RemoveReferences;
end;

constructor TPermissionHandlerRef.Create;
begin
  inherited Create;
end;

destructor TPermissionHandlerRef.Destroy;
begin
  inherited Destroy;
end;


{== JsDialogHandler ==}
function TJsDialogHandlerRef.OnJsdialog(const browser: ICefBrowser; const originUrl: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: boolean): boolean;
begin
  if (JsdialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(JsdialogPtr, []);
  end;
end;

function TJsDialogHandlerRef.OnBeforeUnloadDialog(const browser: ICefBrowser; const messageText: ustring; isReload: boolean; const callback: ICefJsDialogCallback): boolean;
begin
  if (BeforeUnloadDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeUnloadDialogPtr, []);
  end;
end;

procedure TJsDialogHandlerRef.OnResetDialogState(const browser: ICefBrowser);
begin
  if (ResetDialogStatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ResetDialogStatePtr, []);
  end;
end;

procedure TJsDialogHandlerRef.OnDialogClosed(const browser: ICefBrowser);
begin
  if (DialogClosedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DialogClosedPtr, []);
  end;
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
  inherited Destroy;
end;


{== KeyboardHandler ==}
function TKeyboardHandlerRef.OnPreKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle; out isKeyboardShortcut: boolean): boolean;
begin
  if (PreKeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PreKeyEventPtr, []);
  end;
end;

function TKeyboardHandlerRef.OnKeyEvent(const browser: ICefBrowser; const event: PCefKeyEvent; osEvent: TCefEventHandle): boolean;
begin
  if (KeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(KeyEventPtr, []);
  end;
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
  inherited Destroy;
end;


{== LifeSpanHandler ==}
function TLifeSpanHandlerRef.OnBeforePopup(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var extra_info: ICefDictionaryValue; var noJavascriptAccess: boolean): boolean;
begin
  if (BeforePopupPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforePopupPtr, []);
  end;
end;

procedure TLifeSpanHandlerRef.OnAfterCreated(const browser: ICefBrowser);
begin
  if (AfterCreatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AfterCreatedPtr, []);
  end;
end;

function TLifeSpanHandlerRef.DoClose(const browser: ICefBrowser): boolean;
begin
  if (DoClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DoClosePtr, []);
  end;
end;

procedure TLifeSpanHandlerRef.OnBeforeClose(const browser: ICefBrowser);
begin
  if (BeforeClosePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeClosePtr, []);
  end;
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
  inherited Destroy;
end;


{== LoadHandler ==}
procedure TLoadHandlerRef.OnLoadingStateChange(const browser: ICefBrowser; isLoading, canGoBack, canGoForward: boolean);
begin
  if (LoadingStateChangePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadingStateChangePtr, []);
  end;
end;

procedure TLoadHandlerRef.OnLoadStart(const browser: ICefBrowser; const frame: ICefFrame; transitionType: TCefTransitionType);
begin
  if (LoadStartPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadStartPtr, []);
  end;
end;

procedure TLoadHandlerRef.OnLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer);
begin
  if (LoadEndPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadEndPtr, []);
  end;
end;

procedure TLoadHandlerRef.OnLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring);
begin
  if (LoadErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadErrorPtr, []);
  end;
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
  inherited Destroy;
end;


{== PrintHandler ==}
procedure TPrintHandlerRef.OnPrintStart(const browser: ICefBrowser);
begin
  if (PrintStartPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintStartPtr, []);
  end;
end;

procedure TPrintHandlerRef.OnPrintSettings(const browser: ICefBrowser; const settings: ICefPrintSettings; getDefaults: boolean);
begin
  if (PrintSettingsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintSettingsPtr, []);
  end;
end;

procedure TPrintHandlerRef.OnPrintDialog(const browser: ICefBrowser; hasSelection: boolean; const callback: ICefPrintDialogCallback; var aResult: boolean);
begin
  if (PrintDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintDialogPtr, []);
  end;
end;

procedure TPrintHandlerRef.OnPrintJob(const browser: ICefBrowser; const documentName, PDFFilePath: ustring; const callback: ICefPrintJobCallback; var aResult: boolean);
begin
  if (PrintJobPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintJobPtr, []);
  end;
end;

procedure TPrintHandlerRef.OnPrintReset(const browser: ICefBrowser);
begin
  if (PrintResetPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PrintResetPtr, []);
  end;
end;

procedure TPrintHandlerRef.GetPDFPaperSize(const browser: ICefBrowser; deviceUnitsPerInch: integer; var aResult: TCefSize);
begin
  if (PDFPaperSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PDFPaperSizePtr, []);
  end;
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
  inherited Destroy;
end;


{== RenderHandler ==}
procedure TRenderHandlerRef.GetAccessibilityHandler(var aAccessibilityHandler: ICefAccessibilityHandler);
begin
  if (AccessibilityHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AccessibilityHandlerPtr, []);
  end;
end;

function TRenderHandlerRef.GetRootScreenRect(const browser: ICefBrowser; var rect: TCefRect): boolean;
begin
  if (RootScreenRectPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RootScreenRectPtr, []);
  end;
end;

procedure TRenderHandlerRef.GetViewRect(const browser: ICefBrowser; var rect: TCefRect);
begin
  if (ViewRectPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ViewRectPtr, []);
  end;
end;

function TRenderHandlerRef.GetScreenPoint(const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer): boolean;
begin
  if (ScreenPointPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScreenPointPtr, []);
  end;
end;

function TRenderHandlerRef.GetScreenInfo(const browser: ICefBrowser; var screenInfo: TCefScreenInfo): boolean;
begin
  if (ScreenInfoPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScreenInfoPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnPopupShow(const browser: ICefBrowser; Show: boolean);
begin
  if (PopupShowPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupShowPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnPopupSize(const browser: ICefBrowser; const rect: PCefRect);
begin
  if (PopupSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PopupSizePtr, []);
  end;
end;

procedure TRenderHandlerRef.OnPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer);
begin
  if (PaintPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(PaintPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnAcceleratedPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; shared_handle: Pointer);
begin
  if (AcceleratedPaintPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AcceleratedPaintPtr, []);
  end;
end;

procedure TRenderHandlerRef.GetTouchHandleSize(const browser: ICefBrowser; orientation: TCefHorizontalAlignment; var size: TCefSize);
begin
  if (TouchHandleSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TouchHandleSizePtr, []);
  end;
end;

procedure TRenderHandlerRef.OnTouchHandleStateChanged(const browser: ICefBrowser; const state: TCefTouchHandleState);
begin
  if (TouchHandleStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TouchHandleStateChangedPtr, []);
  end;
end;

function TRenderHandlerRef.OnStartDragging(const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer): boolean;
begin
  if (StartDraggingPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(StartDraggingPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnUpdateDragCursor(const browser: ICefBrowser; operation: TCefDragOperation);
begin
  if (UpdateDragCursorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(UpdateDragCursorPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnScrollOffsetChanged(const browser: ICefBrowser; x, y: double);
begin
  if (ScrollOffsetChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ScrollOffsetChangedPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnIMECompositionRangeChanged(const browser: ICefBrowser; const selected_range: PCefRange; character_boundsCount: nativeuint; const character_bounds: PCefRect);
begin
  if (IMECompositionRangeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(IMECompositionRangeChangedPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnTextSelectionChanged(const browser: ICefBrowser; const selected_text: ustring; const selected_range: PCefRange);
begin
  if (TextSelectionChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(TextSelectionChangedPtr, []);
  end;
end;

procedure TRenderHandlerRef.OnVirtualKeyboardRequested(const browser: ICefBrowser; input_mode: TCefTextInpuMode);
begin
  if (VirtualKeyboardRequestedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(VirtualKeyboardRequestedPtr, []);
  end;
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
  inherited Destroy;
end;


{== RequestHandler ==}
function TRequestHandlerRef.OnBeforeBrowse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; user_gesture, isRedirect: boolean): boolean;
begin
  if (BeforeBrowsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeBrowsePtr, []);
  end;
end;

function TRequestHandlerRef.OnOpenUrlFromTab(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean): boolean;
begin
  if (OpenUrlFromTabPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OpenUrlFromTabPtr, []);
  end;
end;

procedure TRequestHandlerRef.GetResourceRequestHandler(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; is_navigation, is_download: boolean; const request_initiator: ustring; var disable_default_handling: boolean; var aResourceRequestHandler: ICefResourceRequestHandler);
begin
  if (GetResourceRequestHandlerPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetResourceRequestHandlerPtr, []);
  end;
end;

function TRequestHandlerRef.GetAuthCredentials(const browser: ICefBrowser; const originUrl: ustring; isProxy: boolean; const host: ustring; port: integer; const realm, scheme: ustring; const callback: ICefAuthCallback): boolean;
begin
  if (GetAuthCredentialsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetAuthCredentialsPtr, []);
  end;
end;

function TRequestHandlerRef.OnCertificateError(const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefCallback): boolean;
begin
  if (CertificateErrorPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(CertificateErrorPtr, []);
  end;
end;

function TRequestHandlerRef.OnSelectClientCertificate(const browser: ICefBrowser; isProxy: boolean; const host: ustring; port: integer; certificatesCount: nativeuint; const certificates: TCefX509CertificateArray; const callback: ICefSelectClientCertificateCallback): boolean;
begin
  if (SelectClientCertificatePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(SelectClientCertificatePtr, []);
  end;
end;

procedure TRequestHandlerRef.OnRenderViewReady(const browser: ICefBrowser);
begin
  if (RenderViewReadyPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RenderViewReadyPtr, []);
  end;
end;

procedure TRequestHandlerRef.OnRenderProcessTerminated(const browser: ICefBrowser; status: TCefTerminationStatus);
begin
  if (RenderProcessTerminatedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(RenderProcessTerminatedPtr, []);
  end;
end;

procedure TRequestHandlerRef.OnDocumentAvailableInMainFrame(const browser: ICefBrowser);
begin
  if (DocumentAvailableInMainFramePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DocumentAvailableInMainFramePtr, []);
  end;
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
  inherited Destroy;
end;

end.
