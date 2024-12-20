//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------
unit uCEF_LCL_Entity;

{$mode objfpc}{$H+}
{$I cef.inc}
{$Z4+}

interface

uses
{$IFDEF FPC}
{$IFDEF LINUX}xlib,{$ENDIF}
{$IFnDEF MSWINDOWS}LCLType,{$ENDIF}
{$ENDIF}
{$IFDEF MSWINDOWS}Windows,{$ENDIF}
  fgl,
  Classes, SysUtils,
  uCEFTypes, uCEFInterfaces, uCEFMiscFunctions,
  {$ifdef MSWINDOWS}uCEFWindowParent{$else}uCEFLinkedWindowParent{$endif};

type
  PRFrameNames = ^RFrameNames;
  FrameNamesArray = array of PRFrameNames;

  RFrameNames = record
    Name: PChar;
    Value: PChar;
  end;

  //Cef Cookie
  PPMCefCookie = ^PMCefCookie;

  PMCefCookie = record
    url, Name, Value, domain, path         : PChar;   //string
    secure, httponly, has_expires          : PBoolean;  //boolean
    creation, last_access, expires         : PDouble;  //double
    Count, total, id, same_site, priority  : PInteger; //integer
    setImmediately                         : PBoolean;  //boolean
  end;

  //Proxy
  PPChromiumProxy = ^PChromiumProxy;

  PChromiumProxy = record
    ProxyType, ProxyScheme: PInteger;
    ProxyServer: PChar;
    ProxyPort: PInteger;
    ProxyUsername, ProxyPassword, ProxyScriptURL, ProxyByPassList: PChar;
    MaxConnectionsPerProxy: PInteger;
  end;

  //CustomHeader
  PRCustomHeader = ^RCustomHeader;

  RCustomHeader = record
    CustomHeaderName: PChar;
    CustomHeaderValue: PChar;
  end;

  // BeforePopup
  PRBeforePopupInfo = ^RBeforePopupInfo;

  RBeforePopupInfo = record
    TargetUrl: PChar;
    TargetFrameName: PChar;
    TargetDisposition: PInteger;
    UserGesture: PBoolean;
  end;

  PTCefRangeArray = ^TCefRangeArray;
  PTCefCompositionUnderlineDynArray = ^TCefCompositionUnderlineDynArray;
  PTCefBinaryValueArray = ^TCefBinaryValueArray;
  PTCefX509CertificateArray = ^TCefX509CertificateArray;

  PTCefWindowHandle = ^TCefWindowHandle;
  PHMENU = ^HMENU;
  PHWND = ^HWND;
  PTCefStringList = ^TCefStringList;

  PMCefPopupFeatures = record
    x: PInteger;
    xSet: PInteger;
    y: PInteger;
    ySet: PInteger;
    Width: PInteger;
    widthSet: PInteger;
    Height: PInteger;
    heightSet: PInteger;
    menuBarVisible: PInteger;
    statusBarVisible: PInteger;
    toolBarVisible: PInteger;
    locationBarVisible: PInteger;
    scrollbarsVisible: PInteger;
    isPopup: PInteger;
    resizable: PInteger;
    fullscreen: PInteger;
    dialog: PInteger;
    additionalFeatures: PTCefStringList;
  end;

  PMCefWindowInfo = record
    {$IFDEF MSWINDOWS}
    ex_style: PDWORD;
    window_name: PChar;
    style: PDWORD;
    x: PInteger;
    y: PInteger;
    Width: PInteger;
    Height: PInteger;
    parent_window: PTCefWindowHandle;
    menu: PHMENU;
    windowless_rendering_enabled: PInteger;
    transparent_painting_enabled: PInteger;
    shared_texture_enabled: PInteger;
    external_begin_frame_enabled: PInteger;
    window: PTCefWindowHandle;
    {$ENDIF}
    {$IFDEF MACOSX}
    window_name: PChar;
    x: PInteger;
    y: PInteger;
    Width: PInteger;
    Height: PInteger;
    hidden: PInteger;
    parent_view: PTCefWindowHandle;
    windowless_rendering_enabled: PInteger;
    shared_texture_enabled: PInteger;
    external_begin_frame_enabled: PInteger;
    view: PTCefWindowHandle;
    {$ENDIF}
    {$IFDEF LINUX}
    window_name: PChar;
    x: PInteger;
    y: PInteger;
    Width: PInteger;
    Height: PInteger;
    hidden: PInteger;
    parent_window: PTCefWindowHandle;
    windowless_rendering_enabled: PInteger;
    shared_texture_enabled: PInteger;
    external_begin_frame_enabled: PInteger;
    window: PTCefWindowHandle;
    {$ENDIF}
  end;

  PPMCefBrowserSettings = ^PMCefBrowserSettings;

  PMCefBrowserSettings = record
    windowless_frame_rate: PInteger;
    standard_font_family: PChar;
    fixed_font_family: PChar;
    serif_font_family: PChar;
    sans_serif_font_family: PChar;
    cursive_font_family: PChar;
    fantasy_font_family: PChar;
    default_font_size: PInteger;
    default_fixed_font_size: PInteger;
    minimum_font_size: PInteger;
    minimum_logical_font_size: PInteger;
    default_encoding: PChar;
    remote_fonts: PInteger;
    javascript: PInteger;
    javascript_close_windows: PInteger;
    javascript_access_clipboard: PInteger;
    javascript_dom_paste: PInteger;
    image_loading: PInteger;
    image_shrink_standalone_to_fit: PInteger;
    text_area_resize: PInteger;
    tab_to_links: PInteger;
    local_storage: PInteger;
    databases: PInteger;
    webgl: PInteger;
    background_color: PCardinal;
    chrome_status_bubble: PInteger;
    chrome_zoom_bubble: PInteger;
  end;

  PPMCefPdfPrintSettings = ^PMCefPdfPrintSettings;

  // TCefPdfPrintSettings
  PMCefPdfPrintSettings = record
    landscape: PInteger;
    print_background: PInteger;
    scale: PDouble;
    paper_width: PDouble;
    paper_height: PDouble;
    prefer_css_page_size: PInteger;
    margin_type: PInteger;
    margin_top: PDouble;
    margin_right: PDouble;
    margin_bottom: PDouble;
    margin_left: PDouble;
    page_ranges: PChar;
    display_header_footer: PInteger;
    header_template: PChar;
    footer_template: PChar;
    generate_tagged_pdf: PInteger;
    generate_document_outline : PInteger;
  end;

  PPMCefRequestContextSettings = ^PMCefRequestContextSettings;

  PMCefRequestContextSettings = record
    cachePath: PChar;
    persistSessionCookies: PInteger;
    acceptLanguageList: PChar;
    cookieableSchemesList: PChar;
    cookieableSchemesExcludeDefaults: PInteger;
  end;

  PPCefInsets = ^PCefInsets;
  PCefInsets = record
    top    : PInteger;
    left   : PInteger;
    bottom : PInteger;
    right  : PInteger;
  end;

  PCefBoxLayoutSettings = record
    horizontal                       : PInteger; //Integer;
    inside_border_horizontal_spacing : PInteger; //Integer;
    inside_border_vertical_spacing   : PInteger; //Integer;
    inside_border_insets             : PPCefInsets; //TCefInsets;
    between_child_spacing            : PInteger; //Integer;
    main_axis_alignment              : PInteger; //TCefAxisAlignment;
    cross_axis_alignment             : PInteger; //TCefAxisAlignment;
    minimum_cross_axis_size          : PInteger; //Integer;
    default_flex                     : PInteger; //Integer;
  end;

  PPMCefTouchHandleState = ^PMCefTouchHandleState;

  PMCefTouchHandleState = record
    touch_handle_id   : PInteger;
    flags             : PCardinal; //cardinal;
    enabled           : PInteger;
    orientation       : PInteger; // TCefHorizontalAlignment;
    mirror_vertical   : PInteger;
    mirror_horizontal : PInteger;
    origin            : PCefPoint; // TCefPoint;
    alpha             : PSingle;
  end;

  // 兼容新版本CEF结构
  TCefAcceleratedPaintInfo = record
    shared_texture_handle: Pointer;
    format: PInteger; // 无效字段
  end;

//string to hash
function StrToHash(const SoureStr: string): cardinal;
//PChar 转 UnicodeString
function PCharToUStr(const Value: PChar): unicodestring;
//PChar 转 Int64
function PCharToInt64(const Value: PChar): int64;
//String 转 UnicodeString
function StrToUStr(const Value: string): unicodestring;

// 需要使用 inline，否则乱码
function ToPChar(AStr: string): PChar; inline;
function ToPChar(AStr: unicodestring): PChar; inline;
function IntToPChar(AVal: Int64): PChar; inline;

function ByteToInteger(const Data: array of byte; start: integer = 0): integer;
//复制Byte数组到Dest
function CopyByteArray(const Source: array of byte; Position, Count: integer): TBytes;

function CopyStringToNewString(old: string): string;
//释放VarRec数组
procedure FreeArrayTVarRec(argsArray: array of TVarRec);

function CefBrowserSettingsToGoBrowserSettings(const settings: TCefBrowserSettings): PMCefBrowserSettings;
function GoBrowserSettingsToCefBrowserSettings(const settings: PMCefBrowserSettings): TCefBrowserSettings;

function CefWindowInfoToGoCefWindowInfo(const settings: TCefWindowInfo): PMCefWindowInfo;
function GoCefWindowInfoToCefWindowInfo(const settings: PMCefWindowInfo): TCefWindowInfo;

function CefPopupFeaturesToGoCefPopupFeatures(const popupFeatures: TCefPopupFeatures): PMCefPopupFeatures;
function GoCefPopupFeaturesToCefPopupFeatures(const popupFeatures: PMCefPopupFeatures): TCefPopupFeatures;

function CefBoxLayoutSettingsToGoBoxLayoutSettings(const value: TCefBoxLayoutSettings): PCefBoxLayoutSettings;
function GoBoxLayoutSettingsToCefBoxLayoutSettings(const value: PCefBoxLayoutSettings): TCefBoxLayoutSettings;
function CefInsetsToGoInsets(const value: TCefInsets): PCefInsets;
function GoInsetsToCefInsets(const value: PCefInsets): TCefInsets;

function InitCookie(): PMCefCookie;
function CefCookieToGoCookie(const value: TCefCookie): PMCefCookie;
function GoCookieToCefCookie(const value: PMCefCookie): TCefCookie;

function RequestContextSettingsToGo(const value: TCefRequestContextSettings): PMCefRequestContextSettings;
function RequestContextSettingsToPas(const value: PMCefRequestContextSettings): TCefRequestContextSettings;

function PdfPrintSettingsToGo(const AData: TCefPdfPrintSettings): PMCefPdfPrintSettings;
function PdfPrintSettingsToPas(const AData: PMCefPdfPrintSettings): TCefPdfPrintSettings;



var
  {$ifdef DARWIN}
  CommandLine: TStringArray;
  CommandCount: integer;
  MyArgv: array of PChar;
  {$endif}
  //const config
  SingleProcess: boolean = False;
  //error code
  CVE_ERROR_OK: integer = 0; //操作成功
  CVE_ERROR_NOT_FOUND_FIELD: integer = 1;//未找到字段
  CVE_ERROR_NOT_FOUND_FUNC: integer = 2;//未找到函数
  //不支持的变量类型, 变量类型只支持【string int double bool null undefined】
  CVE_ERROR_TYPE_NOT_SUPPORTED: integer = 3;
  //字段类型为[array, object, function]不支持变更
  CVE_ERROR_TYPE_CANNOT_CHANGE: integer = 4;
  CVE_ERROR_TYPE_INVALID: integer = 5;//类型无效
  CVE_ERROR_GET_STRING_FAIL: integer = 6;//获取string类型失败
  CVE_ERROR_GET_INT_FAIL: integer = 7;//获取int类型失败
  CVE_ERROR_GET_DOUBLE_FAIL: integer = 8;//获取double类型失败
  CVE_ERROR_GET_BOOL_FAIL: integer = 9; //获取bool类型失败
  //该函数非法, 类型不正确, 或参数个数大于9个
  CVE_ERROR_FUNC_INVALID_P_L_9: integer = 10;
  //入参类型不正确, 只能为string int double boolean
  CVE_ERROR_FUNC_IN_PAM: integer = 11;
  //出参类型不正确, 只能为EefError 或 可选的[string int double boolean]
  //error message
  CVE_ERROR_FUNC_OUT_PAM: integer = 12;


  {$ifdef MSWINDOWS}
//拖拽区域
//draggable_region: HRGN;
  {$endif}

implementation

function ToPChar(AStr: string): PChar; inline;
begin
  Result := PChar(AStr);
end;

function ToPChar(AStr: unicodestring): PChar; inline;
begin
  Result := PChar(UTF8Encode(AStr)); //PWideChar(AStr);
end;

function IntToPChar(AVal: Int64): PChar; inline;
begin
  Result := PChar(IntToStr(AVal)); //PWideChar(AStr);
end;

function ByteToInteger(const Data: array of byte; start: integer = 0): integer;
var
  byt: TBytes;
  Pint: PInteger;
begin
  try
    SetLength(byt, 4);
    byt[3] := Data[start + 0];
    byt[2] := Data[start + 1];
    byt[1] := Data[start + 2];
    byt[0] := Data[start + 3];
    Pint := PInteger(@byt[0]);
    Result := Pint^;
  finally
    SetLength(byt, 0);
    Pint := nil;
  end;
end;

//PChar 转 UnicodeString
function PCharToUStr(const Value: PChar): unicodestring;
begin
  Result := '';
  if Value <> nil then
    //关于PChar 默认编码不是UTF8
    Result := StrToUStr(StrPas(Value));
end;

function PCharToInt64(const Value: PChar): int64;
begin
  Result := 0;
  if Value <> nil then
    Result := StrToInt64(StrPas(Value));
end;

//String 转 UnicodeString
function StrToUStr(const Value: string): unicodestring;
begin
  Result := UTF8Decode(Value);
end;

// string to hash
function StrToHash(const SoureStr: string): cardinal;
const
  cOneEight = 4;
  cThreeFourths = 24;
  cHighBits = $F0000000;
var
  I: integer;
  P: PChar;
  Temp: cardinal;
begin
  Result := 0;
  P := PChar(SoureStr);
  I := Length(SoureStr);
  while I > 0 do
  begin
    Result := (Result shl cOneEight) + Ord(P^);
    Temp := Result and cHighBits;
    if Temp <> 0 then
      Result := (Result xor (Temp shr cThreeFourths)) and (not cHighBits);
    Dec(I);
    Inc(P);
  end;
end;

{
 bytes: [4 0 0 0 4 0 1 4 106 0 0 0 0 15 230 157 168 231 186 162 229 178 169 230 181 139 232 175 149]
}
function CopyByteArray(const Source: array of byte; Position, Count: integer): TBytes;
var
  i, idx: integer;
  Dest: TBytes;
begin
  i := 0;
  SetLength(Dest, Count - Position);
  for idx := Position to Count - 1 do
  begin
    Dest[i] := Source[idx];
    Inc(i);
  end;
  Result := Dest;
end;

function CopyStringToNewString(old: string): string;
var
  i: integer;
  B: array of byte;
begin
  SetLength(B, Length(old) + 1);
  for i := 0 to length(old) do
  begin
    B[i] := byte(old[i]);
  end;
  Result := string(B);
end;

procedure FreeArrayTVarRec(argsArray: array of TVarRec);
var
  idx: integer;
begin
  for idx := 0 to length(argsArray) - 1 do
  begin
    case argsArray[idx].VType of
      vtPChar:
      begin
        argsArray[idx].VPChar := nil;
      end;
      vtPointer:
      begin
        argsArray[idx].VPointer := nil;
      end;
    end;
  end;
end;

function CefBrowserSettingsToGoBrowserSettings(const settings: TCefBrowserSettings): PMCefBrowserSettings;
begin
  Result.windowless_frame_rate              := @settings.windowless_frame_rate;
  Result.standard_font_family               := ToPChar(CefString(@settings.standard_font_family));
  Result.fixed_font_family                  := ToPChar(CefString(@settings.fixed_font_family));
  Result.serif_font_family                  := ToPChar(CefString(@settings.serif_font_family));
  Result.sans_serif_font_family             := ToPChar(CefString(@settings.sans_serif_font_family));
  Result.cursive_font_family                := ToPChar(CefString(@settings.cursive_font_family));
  Result.fantasy_font_family                := ToPChar(CefString(@settings.fantasy_font_family));
  Result.default_font_size                  := @settings.default_font_size;
  Result.default_fixed_font_size            := @settings.default_fixed_font_size;
  Result.minimum_font_size                  := @settings.minimum_font_size;
  Result.minimum_logical_font_size          := @settings.minimum_logical_font_size;
  Result.default_encoding                   := ToPChar(CefString(@settings.default_encoding));
  Result.remote_fonts                       := @settings.remote_fonts;
  Result.javascript                         := @settings.javascript;
  Result.javascript_close_windows           := @settings.javascript_close_windows;
  Result.javascript_access_clipboard        := @settings.javascript_access_clipboard;
  Result.javascript_dom_paste               := @settings.javascript_dom_paste;
  Result.image_loading                      := @settings.image_loading;
  Result.image_shrink_standalone_to_fit     := @settings.image_shrink_standalone_to_fit;
  Result.text_area_resize                   := @settings.text_area_resize;
  Result.tab_to_links                       := @settings.tab_to_links;
  Result.local_storage                      := @settings.local_storage;
  Result.databases                          := @settings.databases;
  Result.webgl                              := @settings.webgl;
  Result.background_color                   := @settings.background_color;
  Result.chrome_status_bubble               := @settings.chrome_status_bubble;
  Result.chrome_zoom_bubble                 := nil;
end;

function GoBrowserSettingsToCefBrowserSettings(const settings: PMCefBrowserSettings): TCefBrowserSettings;
begin
  Result.size                               := SizeOf(TCefBrowserSettings);
  Result.windowless_frame_rate              := settings.windowless_frame_rate^;
  Result.standard_font_family               := CefStringAlloc(PCharToUStr(settings.standard_font_family));
  Result.fixed_font_family                  := CefStringAlloc(PCharToUStr(settings.fixed_font_family));
  Result.serif_font_family                  := CefStringAlloc(PCharToUStr(settings.serif_font_family));
  Result.sans_serif_font_family             := CefStringAlloc(PCharToUStr(settings.sans_serif_font_family));
  Result.cursive_font_family                := CefStringAlloc(PCharToUStr(settings.cursive_font_family));
  Result.fantasy_font_family                := CefStringAlloc(PCharToUStr(settings.fantasy_font_family));
  Result.default_font_size                  := settings.default_font_size^;
  Result.default_fixed_font_size            := settings.default_fixed_font_size^;
  Result.minimum_font_size                  := settings.minimum_font_size^;
  Result.minimum_logical_font_size          := settings.minimum_logical_font_size^;
  Result.default_encoding                   := CefStringAlloc(PCharToUStr(settings.default_encoding));
  Result.remote_fonts                       := TCefState(settings.remote_fonts^);
  Result.javascript                         := TCefState(settings.javascript^);
  Result.javascript_close_windows           := TCefState(settings.javascript_close_windows^);
  Result.javascript_access_clipboard        := TCefState(settings.javascript_access_clipboard^);
  Result.javascript_dom_paste               := TCefState(settings.javascript_dom_paste^);
  Result.image_loading                      := TCefState(settings.image_loading^);
  Result.image_shrink_standalone_to_fit     := TCefState(settings.image_shrink_standalone_to_fit^);
  Result.text_area_resize                   := TCefState(settings.text_area_resize^);
  Result.tab_to_links                       := TCefState(settings.tab_to_links^);
  Result.local_storage                      := TCefState(settings.local_storage^);
  Result.databases                          := TCefState(settings.databases^);
  Result.webgl                              := TCefState(settings.webgl^);
  Result.background_color                   := TCefColor(settings.background_color^);
  Result.chrome_status_bubble               := TCefState(settings.chrome_status_bubble^);
end;

function CefWindowInfoToGoCefWindowInfo(const settings: TCefWindowInfo): PMCefWindowInfo;
begin
  {$IFDEF MSWINDOWS}
  Result.ex_style                           := @settings.ex_style;
  Result.window_name                        := ToPChar(CefString(@settings.window_name));
  Result.style                              := @settings.style;
  Result.x                                  := @settings.bounds.x;
  Result.y                                  := @settings.bounds.y;
  Result.Width                              := @settings.bounds.Width;
  Result.Height                             := @settings.bounds.Height;
  Result.parent_window                      := @settings.parent_window;
  Result.menu                               := @settings.menu;
  Result.windowless_rendering_enabled       := @settings.windowless_rendering_enabled;
  Result.transparent_painting_enabled       := PInteger(0);
  Result.shared_texture_enabled             := @settings.shared_texture_enabled;
  Result.external_begin_frame_enabled       := @settings.external_begin_frame_enabled;
  Result.window                             := @settings.window;
  {$ENDIF}
  {$IFDEF MACOSX}
  Result.window_name                        := ToPChar(CefString(@settings.window_name));
  Result.x                                  := @settings.bounds.x;
  Result.y                                  := @settings.bounds.y;
  Result.Width                              := @settings.bounds.Width;
  Result.Height                             := @settings.bounds.Height;
  Result.hidden                             := @settings.hidden;
  Result.parent_view                        := @settings.parent_view;
  Result.windowless_rendering_enabled       := @settings.windowless_rendering_enabled;
  Result.shared_texture_enabled             := @settings.shared_texture_enabled;
  Result.external_begin_frame_enabled       := @settings.external_begin_frame_enabled;
  Result.view                               := @settings.view;
  {$ENDIF}
  {$IFDEF LINUX}
  Result.window_name                        := ToPChar(CefString(@settings.window_name));
  Result.x                                  := @settings.bounds.x;
  Result.y                                  := @settings.bounds.y;
  Result.Width                              := @settings.bounds.Width;
  Result.Height                             := @settings.bounds.Height;
  Result.parent_window                      := @settings.parent_window;
  Result.windowless_rendering_enabled       := @settings.windowless_rendering_enabled;
  Result.shared_texture_enabled             := @settings.shared_texture_enabled;
  Result.external_begin_frame_enabled       := @settings.external_begin_frame_enabled;
  Result.window                             := @settings.window;
  {$ENDIF}
end;

function GoCefWindowInfoToCefWindowInfo(const settings: PMCefWindowInfo): TCefWindowInfo;
begin
  {$IFDEF MSWINDOWS}
  Result.ex_style                       := settings.ex_style^;
  Result.window_name                    := CefStringAlloc(PCharToUStr(settings.window_name));
  Result.style                          := settings.style^;
  Result.bounds.x                       := settings.x^;
  Result.bounds.y                       := settings.y^;
  Result.bounds.Width                   := settings.Width^;
  Result.bounds.Height                  := settings.Height^;
  Result.parent_window                  := settings.parent_window^;
  Result.menu                           := settings.menu^;
  Result.windowless_rendering_enabled   := settings.windowless_rendering_enabled^;
  Result.shared_texture_enabled         := settings.shared_texture_enabled^;
  Result.external_begin_frame_enabled   := settings.external_begin_frame_enabled^;
  Result.window                         := settings.window^;
  {$ENDIF}
  {$IFDEF MACOSX}
  Result.window_name                    := CefStringAlloc(PCharToUStr(settings.window_name));
  Result.bounds.x                       := settings.x^;
  Result.bounds.y                       := settings.y^;
  Result.bounds.Width                   := settings.Width^;
  Result.bounds.Height                  := settings.Height^;
  Result.hidden                         := settings.hidden^;
  Result.parent_view                    := settings.parent_view^;
  Result.windowless_rendering_enabled   := settings.windowless_rendering_enabled^;
  Result.shared_texture_enabled         := settings.shared_texture_enabled^;
  Result.external_begin_frame_enabled   := settings.external_begin_frame_enabled^;
  Result.view                           := settings.view^;
  {$ENDIF}
  {$IFDEF LINUX}
  Result.window_name                    := CefStringAlloc(PCharToUStr(settings.window_name));
  Result.bounds.x                       := settings.x^;
  Result.bounds.y                       := settings.y^;
  Result.bounds.Width                   := settings.Width^;
  Result.bounds.Height                  := settings.Height^;
  Result.parent_window                  := settings.parent_window^;
  Result.windowless_rendering_enabled   := settings.windowless_rendering_enabled^;
  Result.shared_texture_enabled         := settings.shared_texture_enabled^;
  Result.external_begin_frame_enabled   := settings.external_begin_frame_enabled^;
  Result.window                         := settings.window^;
  {$ENDIF}
end;

function CefPopupFeaturesToGoCefPopupFeatures(const popupFeatures: TCefPopupFeatures): PMCefPopupFeatures;
begin
  Result.x                          := @popupFeatures.x;
  Result.xSet                       := @popupFeatures.xSet;
  Result.y                          := @popupFeatures.y;
  Result.ySet                       := @popupFeatures.ySet;
  Result.Width                      := @popupFeatures.Width;
  Result.widthSet                   := @popupFeatures.widthSet;
  Result.Height                     := @popupFeatures.Height;
  Result.heightSet                  := @popupFeatures.heightSet;
  Result.menuBarVisible             := @popupFeatures.menuBarVisible;
  Result.statusBarVisible           := @popupFeatures.statusBarVisible;
  Result.toolBarVisible             := @popupFeatures.toolBarVisible;
  Result.scrollbarsVisible          := @popupFeatures.scrollbarsVisible;
  Result.locationBarVisible         := nil;
  Result.isPopup                    := nil;
  Result.resizable                  := nil;
  Result.fullscreen                 := nil;
  Result.dialog                     := nil;
  Result.additionalFeatures         := nil;
end;

function GoCefPopupFeaturesToCefPopupFeatures(const popupFeatures: PMCefPopupFeatures): TCefPopupFeatures;
begin
  Result.x                      := popupFeatures.x^;
  Result.xSet                   := popupFeatures.xSet^;
  Result.y                      := popupFeatures.y^;
  Result.ySet                   := popupFeatures.ySet^;
  Result.Width                  := popupFeatures.Width^;
  Result.widthSet               := popupFeatures.widthSet^;
  Result.Height                 := popupFeatures.Height^;
  Result.heightSet              := popupFeatures.heightSet^;
  Result.menuBarVisible         := popupFeatures.menuBarVisible^;
  Result.statusBarVisible       := popupFeatures.statusBarVisible^;
  Result.toolBarVisible         := popupFeatures.toolBarVisible^;
  Result.scrollbarsVisible      := popupFeatures.scrollbarsVisible^;
end;

function CefBoxLayoutSettingsToGoBoxLayoutSettings(const value: TCefBoxLayoutSettings): PCefBoxLayoutSettings;
var
  TempGoInsets: PCefInsets;
begin
    TempGoInsets                            := CefInsetsToGoInsets(value.inside_border_insets);
    Result.horizontal                       := @value.horizontal;
    Result.inside_border_horizontal_spacing := @value.inside_border_horizontal_spacing;
    Result.inside_border_vertical_spacing   := @value.inside_border_vertical_spacing;
    Result.inside_border_insets             := @TempGoInsets;
    Result.between_child_spacing            := @value.between_child_spacing;
    Result.main_axis_alignment              := @value.main_axis_alignment;
    Result.cross_axis_alignment             := @value.cross_axis_alignment;
    Result.minimum_cross_axis_size          := @value.minimum_cross_axis_size;
    Result.default_flex                     := @value.default_flex;
end;

function GoBoxLayoutSettingsToCefBoxLayoutSettings(const value: PCefBoxLayoutSettings): TCefBoxLayoutSettings;
begin
    Result.horizontal                       := value.horizontal^;
    Result.inside_border_horizontal_spacing := value.inside_border_horizontal_spacing^;
    Result.inside_border_vertical_spacing   := value.inside_border_vertical_spacing^;
    Result.inside_border_insets             := GoInsetsToCefInsets(PPCefInsets(value.inside_border_insets)^);
    Result.between_child_spacing            := value.between_child_spacing^;
    Result.main_axis_alignment              := TCefMainAxisAlignment(value.main_axis_alignment^);
    Result.cross_axis_alignment             := TCefCrossAxisAlignment(value.cross_axis_alignment^);
    Result.minimum_cross_axis_size          := value.minimum_cross_axis_size^;
    Result.default_flex                     := value.default_flex^;
end;

function CefInsetsToGoInsets(const value: TCefInsets): PCefInsets;
begin
  Result.top    := @value.top;
  Result.left   := @value.left;
  Result.bottom := @value.bottom;
  Result.right  := @value.right;
end;

function GoInsetsToCefInsets(const value: PCefInsets): TCefInsets;
begin
  Result.top    := value.top^;
  Result.left   := value.left^;
  Result.bottom := value.bottom^;
  Result.right  := value.right^;
end;

function InitCookie(): PMCefCookie;
begin
  Result.url            := nil;
  Result.Name           := nil;
  Result.Value          := nil;
  Result.domain         := nil;
  Result.path           := nil;
  Result.secure         := nil;
  Result.httponly       := nil;
  Result.creation       := nil;
  Result.last_access    := nil;
  Result.has_expires    := nil;
  Result.expires        := nil;
  Result.same_site      := nil;
  Result.priority       := nil;
  Result.Count          := nil;
  Result.total          := nil;
  Result.id             := nil;
  Result.setImmediately := nil;
end;

function CefCookieToGoCookie(const value: TCefCookie): PMCefCookie;
begin
  Result                := InitCookie();
  Result.Name           := ToPChar(CefString(@value.name));
  Result.Value          := ToPChar(CefString(@value.value));
  Result.domain         := ToPChar(CefString(@value.domain));
  Result.path           := ToPChar(CefString(@value.path));
  Result.secure         := @value.secure;
  Result.httponly       := @value.httponly;
  Result.creation       := @value.creation;
  Result.last_access    := @value.last_access;
  Result.has_expires    := @value.has_expires;
  Result.expires        := @value.expires;
  Result.same_site      := @value.same_site;
  Result.priority       := @value.priority;
end;

function GoCookieToCefCookie(const value: PMCefCookie): TCefCookie;
begin
  Result.name           := CefStringAlloc(PCharToUStr(value.Name));
  Result.value          := CefStringAlloc(PCharToUStr(value.Value));
  Result.domain         := CefStringAlloc(PCharToUStr(value.Domain));
  Result.path           := CefStringAlloc(PCharToUStr(value.Path));
  Result.secure         := Integer(value.secure^);
  Result.httponly       := Integer(value.httponly^);
  Result.creation       := DateTimeToCefTime(value.creation^);
  Result.last_access    := DateTimeToCefTime(value.last_access^);
  Result.has_expires    := Integer(value.has_expires^);
  Result.expires        := DateTimeToCefTime(value.expires^);
  Result.same_site      := TCefCookieSameSite(value.same_site^);
  Result.priority       := TCefCookiePriority(value.priority^);
end;

function RequestContextSettingsToGo(const value: TCefRequestContextSettings): PMCefRequestContextSettings;
begin
  Result.CachePath                          := ToPChar(CefString(@value.cache_path));
  Result.PersistSessionCookies              := @value.persist_session_cookies;
  Result.AcceptLanguageList                 := ToPChar(CefString(@value.accept_language_list));
  Result.CookieableSchemesList              := ToPChar(CefString(@value.cookieable_schemes_list));
  Result.CookieableSchemesExcludeDefaults   := @value.cookieable_schemes_exclude_defaults;
end;

function RequestContextSettingsToPas(const value: PMCefRequestContextSettings): TCefRequestContextSettings;
begin
  Result.size                                   := SizeOf(TCefRequestContextSettings);
  Result.cache_path                             := CefStringAlloc(PCharToUStr(value.CachePath));
  Result.persist_session_cookies                := Integer(value.PersistSessionCookies^);
  Result.accept_language_list                   := CefStringAlloc(PCharToUStr(value.AcceptLanguageList));
  Result.cookieable_schemes_list                := CefStringAlloc(PCharToUStr(value.CookieableSchemesList));
  Result.cookieable_schemes_exclude_defaults    := integer(value.CookieableSchemesExcludeDefaults^);
end;

function PdfPrintSettingsToGo(const AData: TCefPdfPrintSettings): PMCefPdfPrintSettings;
begin
  Result.landscape                  := @AData.landscape;
  Result.scale                      := @AData.scale_factor;
  Result.paper_width                := @AData.page_width;
  Result.paper_height               := @AData.page_height;
  Result.prefer_css_page_size       := nil;
  Result.margin_type                := @AData.margin_type;
  Result.margin_top                 := @AData.margin_top;
  Result.margin_right               := @AData.margin_right;
  Result.margin_bottom              := @AData.margin_bottom;
  Result.margin_left                := @AData.margin_left;
  Result.print_background           := @AData.backgrounds_enabled;
  Result.page_ranges                := nil;
  Result.display_header_footer      := nil;
  Result.header_template            := nil;
  Result.footer_template            := nil;
  Result.generate_tagged_pdf        := nil;
  Result.generate_document_outline  := nil;
end;

function PdfPrintSettingsToPas(const AData: PMCefPdfPrintSettings): TCefPdfPrintSettings;
begin
  Result.landscape              := Integer(AData.landscape^);
  Result.scale_factor           := Trunc(double(AData.scale^));
  Result.page_width             := Trunc(double(AData.paper_width^));
  Result.page_height            := Trunc(double(AData.paper_height^));
  Result.margin_type            := TCefPdfPrintMarginType(AData.margin_type^);
  Result.margin_top             := Trunc(double(AData.margin_top^));
  Result.margin_right           := Trunc(double(AData.margin_right^));
  Result.margin_bottom          := Trunc(double(AData.margin_bottom^));
  Result.margin_left            := Trunc(double(AData.margin_left^));
  Result.backgrounds_enabled    := Integer(AData.print_background^);
end;


end.
