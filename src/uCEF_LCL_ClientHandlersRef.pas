//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ClientHandlersRef;

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

interface

uses
  Classes, uCEF_LCL_Entity,
  uCEFTypes, uCEFInterfaces, uCEFContextMenuHandler, uCEFDialogHandler, uCEFDisplayHandler,
  uCEFDownloadHandler, uCEFDragHandler, uCEFFindHandler, uCEFFocusHandler, uCEFJsdialogHandler, uCEFKeyboardHandler,
  uCEFLifeSpanHandler, uCEFLoadHandler, uCEFRenderHandler, uCEFRequestHandler, uCEFv8Value,
  uCEF_LCL_EventCallback;

type

  {== AudioHandler ==}
  TAudioHandlerRef = class
  public
    GetAudioParametersPtr: Pointer;
    AudioStreamStartedPtr: Pointer;
    AudioStreamPacketPtr: Pointer;
    AudioStreamStoppedPtr: Pointer;
    AudioStreamErrorPtr: Pointer;
    constructor Create;
    destructor Destroy;
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
    function OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback): boolean; override;
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
    function  OnConsoleMessage(const browser: ICefBrowser; const message_, source: ustring; line: Integer): Boolean; override;
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
    procedure OnDraggableRegionsChanged(const browser: ICefBrowser; regionsCount: NativeUInt; regions: PCefDraggableRegionArray); override;

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
    function OnJsdialog(const browser: ICefBrowser; const originUrl, accept_lang: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: Boolean): boolean; override;
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
    function OnBeforePopup(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: Boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: Boolean): Boolean; override;
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
    procedure OnLoadStart(const browser: ICefBrowser; const frame: ICefFrame); override;
    procedure OnLoadEnd(const browser: ICefBrowser; const frame: ICefFrame; httpStatusCode: integer); override;
    procedure OnLoadError(const browser: ICefBrowser; const frame: ICefFrame; errorCode: TCefErrorCode; const errorText, failedUrl: ustring); override;
    procedure RemoveReferences; override;
  end;

  {== PrintHandler ==}
  TPrintHandlerRef = class
  public
    PrintStartPtr: Pointer;
    PrintSettingsPtr: Pointer;
    PrintDialogPtr: Pointer;
    PrintJobPtr: Pointer;
    PrintResetPtr: Pointer;
    PDFPaperSizePtr: Pointer;
    constructor Create;
    destructor Destroy;
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
    function GetRootScreenRect(const browser: ICefBrowser; var rect: TCefRect): boolean; override;
    function  GetViewRect(const browser: ICefBrowser; var rect: TCefRect): Boolean; override;
    function GetScreenPoint(const browser: ICefBrowser; viewX, viewY: integer; var screenX, screenY: integer): boolean; override;
    function GetScreenInfo(const browser: ICefBrowser; var screenInfo: TCefScreenInfo): boolean; override;
    procedure OnPopupShow(const browser: ICefBrowser; Show: boolean); override;
    procedure OnPopupSize(const browser: ICefBrowser; const rect: PCefRect); override;
    procedure OnPaint(const browser: ICefBrowser; kind: TCefPaintElementType; dirtyRectsCount: nativeuint; const dirtyRects: PCefRectArray; const buffer: Pointer; Width, Height: integer); override;
    function OnStartDragging(const browser: ICefBrowser; const dragData: ICefDragData; allowedOps: TCefDragOperations; x, y: integer): boolean; override;
    procedure OnUpdateDragCursor(const browser: ICefBrowser; operation: TCefDragOperation); override;
    procedure OnScrollOffsetChanged(const browser: ICefBrowser; x, y: double); override;
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
    function OnBeforeBrowse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; isRedirect: Boolean): boolean; override;
    function OnOpenUrlFromTab(const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean): boolean; override;
    function GetAuthCredentials(const browser: ICefBrowser; const frame: ICefFrame; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback): boolean; override;
    function OnCertificateError(const browser: ICefBrowser; certError: TCefErrorcode; const requestUrl: ustring; const sslInfo: ICefSslInfo; const callback: ICefRequestCallback): Boolean; override;
    procedure OnRenderViewReady(const browser: ICefBrowser); override;
    procedure OnRenderProcessTerminated(const browser: ICefBrowser; status: TCefTerminationStatus); override;
    procedure RemoveReferences; override;
  end;

implementation

{== AudioHandler ==}
constructor TAudioHandlerRef.Create;
begin
end;

destructor TAudioHandlerRef.Destroy;
begin
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
function TDialogHandlerRef.OnFileDialog(const browser: ICefBrowser; mode: TCefFileDialogMode; const title, defaultFilePath: ustring; const acceptFilters: TStrings; selectedAcceptFilter: Integer; const callback: ICefFileDialogCallback): boolean;
begin
  Result := False;
  if (FileDialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FileDialogPtr, [browser, mode, PChar(string(title)), PChar(string(defaultFilePath)), acceptFilters, callback, @Result]);
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

function TDisplayHandlerRef.OnConsoleMessage(const browser: ICefBrowser; const message_, source: ustring; line: Integer): boolean;
begin
  Result := False;
  if (ConsoleMessagePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ConsoleMessagePtr, [browser, 0, PChar(string(message_)), PChar(string(Source)), line, @Result]);
  end
  else
    Result := inherited OnConsoleMessage(browser,  message_, Source, line);
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
    TCEFEventCallback.SendEvent(BeforeDownloadPtr, [browser, downloadItem, PChar(string(suggestedName)), callback]);
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

procedure TDragHandlerRef.OnDraggableRegionsChanged(const browser: ICefBrowser; regionsCount: NativeUInt; regions: PCefDraggableRegionArray);
begin
  if (DraggableRegionsChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(DraggableRegionsChangedPtr, [browser, nil, integer(regionsCount), regions]);
  end
  else
    inherited OnDraggableRegionsChanged(browser, regionsCount, regions);
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
function TJsDialogHandlerRef.OnJsdialog(const browser: ICefBrowser; const originUrl, accept_lang: ustring; dialogType: TCefJsDialogType; const messageText, defaultPromptText: ustring; const callback: ICefJsDialogCallback; out suppressMessage: Boolean): boolean;
begin
  Result := False;
  if (JsdialogPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(JsdialogPtr, [browser, PChar(string(originUrl)), integer(dialogType), PChar(string(messageText)), PChar(string(defaultPromptText)), callback, @suppressMessage, @Result]);
  end
  else
    Result := inherited OnJsdialog(browser, originUrl, accept_lang, dialogType, messageText, defaultPromptText, callback, suppressMessage);
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
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: boolean): boolean;
var
  beforePopupInfo  : RBeforePopupInfo;
  rpopupFeatures   : PTCefPopupFeatures;
  rwindowInfo      : RTCefWindowInfo;
  rbrowserSettings : RCefBrowserSettings;
begin
  Result := False;
  if (BeforePopupPtr <> nil) then
  begin
    //popup info
    beforePopupInfo.TargetUrl := PChar(string(targetUrl));
    beforePopupInfo.TargetFrameName := PChar(string(targetFrameName));
    beforePopupInfo.TargetDisposition := PInteger(Integer(targetDisposition));
    beforePopupInfo.UserGesture := @userGesture;
    // popupFeatures
    rpopupFeatures := CefPopupFeaturesToGoCefPopupFeatures(popupFeatures);
    // windowInfo
    rwindowInfo := CefWindowInfoToGoCefWindowInfo(windowInfo);
    // settings
    rbrowserSettings := CefBrowserSettingsToGoBrowserSettings(settings);
    //event
    TCEFEventCallback.SendEvent(BeforePopupPtr, [browser, frame, @beforePopupInfo, @rpopupFeatures, @rwindowInfo, @client, @rbrowserSettings, Pointer(0), @noJavascriptAccess, @Result]);
    windowInfo := GoCefWindowInfoToCefWindowInfo(rwindowInfo);
  end
  else
    Result := inherited OnBeforePopup(browser, frame, targetUrl, targetFrameName, targetDisposition, userGesture, popupFeatures, windowInfo, client, settings, noJavascriptAccess);
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

procedure TLoadHandlerRef.OnLoadStart(const browser: ICefBrowser; const frame: ICefFrame);
begin
  if (LoadStartPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LoadStartPtr, [browser, frame, 0]);
  end
  else
    inherited OnLoadStart(browser, frame);
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
constructor TPrintHandlerRef.Create;
begin
end;

destructor TPrintHandlerRef.Destroy;
begin
end;

{== RenderHandler ==}
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

function TRenderHandlerRef.GetViewRect(const browser: ICefBrowser; var rect: TCefRect): Boolean;
begin
  Result := True;
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
function TRequestHandlerRef.OnBeforeBrowse(const browser: ICefBrowser; const frame: ICefFrame; const request: ICefRequest; isRedirect: Boolean): boolean;
begin
  Result := False;
  if (BeforeBrowsePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BeforeBrowsePtr, [browser, frame, request, false, isRedirect, @Result]);
  end
  else
    Result := inherited OnBeforeBrowse(browser, frame, request, isRedirect);
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

function TRequestHandlerRef.GetAuthCredentials(const browser: ICefBrowser; const frame: ICefFrame; isProxy: Boolean; const host: ustring; port: Integer; const realm, scheme: ustring; const callback: ICefAuthCallback): boolean;
begin
  Result := False;
  if (GetAuthCredentialsPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetAuthCredentialsPtr, [browser, PChar(string(frame.Url)), isProxy, PChar(string(host)), port, PChar(string(realm)), PChar(string(scheme)), callback, @Result]);
  end
  else
    Result := inherited GetAuthCredentials(browser, frame, isProxy, host, port, realm, scheme, callback);
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
    TCEFEventCallback.SendEvent(RenderProcessTerminatedPtr, [browser, status]);
  end
  else
    inherited OnRenderProcessTerminated(browser, status);
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
