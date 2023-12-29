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

  // string header
  PStringHeader = ^StringHeader;

  StringHeader = record
    PValue: PChar;
    ValueLength: nativeuint;
    Value: string;
  end;

  //CEFChromium 配置
  TCEFChromiumConfig = record
    EnableMenu: PBoolean;
    EnableViewSource: PBoolean;
    EnableDevTools: PBoolean;
    EnableWindowPopup: PBoolean;
    EnableOpenUrlTab: PBoolean;
    EnabledJavascript: PBoolean;
  end;//配置 end

  //键盘事件
  RChromiumKeyEvent = record
    KeyCode: integer; //键码
    Message: integer; //键 WM_KEYUP 257抬起、WM_KEYDOWN 256按下
  end;

  //TCEFv8Context
  RCEFV8Context = record
    V8Context: ICefv8Context;
    Browser: ICefBrowser;
    Frame: ICefFrame;
    Global: ICefv8Value;
  end;

  //ICefProcessMessage
  PRCEFProcessMessage = ^RCEFProcessMessage;

  RCEFProcessMessage = record
    Name: PChar;
    Data: Pointer;
    DataLen: PInteger;
  end;

  //ICefFrame
  PRCEFFrame = ^RCEFFrame;

  RCEFFrame = record
    Name: PChar;
    Url: PChar;
    Identifier: PChar;
  end;

  //ICefBrowser
  RCEFBrowser = record
    Identifier: integer;
  end;

  //函数调用 临时存放入参值
  PRArguments = ^RArguments;
  ArgumentsArray = array of PRArguments;
  PArgumentsArray = ^ArgumentsArray;

  RArguments = record
    PStringValue: PChar;
    StringValue: string;
    IntegerValue: integer;
    PDoubleValue: Pdouble;
    DoubleValue: double;
    BooleanValue: boolean;
  end;


  //Go to JS 绑定交互返回值
  PRRetBindValue = ^RRetBindValue;

  RRetBindValue = record
    PException: Pointer;
    PStringValue: Pointer;
    PIntValue: PInteger;
    DoubleValue: double;
    PBooleanValue: PBoolean;
    PVType: PInteger;
  end;

  PGoResult = ^GoResult;

  GoResult = record
    Value: Pointer;
    ValueType: PInteger;
    ValueLength: PInteger;
    BindType: PInteger;
    Exception: PInteger;
  end;

  //Cef Cookie
  PRCefCookie = ^RCefCookie;

  RCefCookie = record
    url, Name, Value, domain, path: PChar;//string
    secure, httponly, hasExpires: Pointer;//boolean
    creation, lastAccess, expires: Pointer;//double
    Count, total, aID, sameSite, priority: PInteger;//integer
    setImmediately, deleteCookie, Result: Pointer;//boolean
  end;

  //Proxy
  PRChromiumProxy = ^RChromiumProxy;

  RChromiumProxy = record
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

  PTCefRangeArray = ^TCefPageRangeArray;
  //PTCefCompositionUnderlineDynArray = ^TCefCompositionUnderlineDynArray;
  PTCefBinaryValueArray = ^TCefBinaryValueArray;
  //PTCefX509CertificateArray = ^TCefX509CertificateArray;

  PRTCefRect = ^RTCefRect;

  RTCefRect = record
    x: PInteger;
    y: PInteger;
    Width: PInteger;
    Height: PInteger;
  end;

  PTCefWindowHandle = ^TCefWindowHandle;
  PHMENU = ^HMENU;
  PHWND = ^HWND;

  RTCefWindowInfo = record
    ex_style: PDWORD;
    window_name: Pointer;
    style: PDWORD;
    bounds: PRTCefRect;
    parent_window: PTCefWindowHandle;
    menu: PHMENU;//HMENU
    //windowless_rendering_enabled: PInteger;
    //shared_texture_enabled: PInteger;
    //external_begin_frame_enabled: PInteger;
    window: PTCefWindowHandle;
  end;

  PRCefBrowserSettings = ^RCefBrowserSettings;

  RCefBrowserSettings = record
    size: PNativeuint;
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
    accept_language_list: PChar;
    chrome_status_bubble: PInteger;
  end;

  PRCefPdfPrintSettings = ^RCefPdfPrintSettings;

  RCefPdfPrintSettings = record
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
  end;

  PRCefRequestContextSettings = ^RCefRequestContextSettings;

  RCefRequestContextSettings = record
    size: PNativeuint;
    cachePath: PChar;
    persistSessionCookies: PInteger;
    persistUserPreferences: PInteger;
    acceptLanguageList: PChar;
    cookieableSchemesList: PChar;
    cookieableSchemesExcludeDefaults: PInteger;
  end;

function NewStringHeader(Data: ustring): PStringHeader;

//string to hash
function StrToHash(const SoureStr: string): cardinal;
//PChar 转 UnicodeString
function PCharToUStr(const Value: PChar): unicodestring;
//String 转 UnicodeString
function StrToUStr(const Value: string): unicodestring;

function ByteToInteger(const Data: array of byte; start: integer = 0): integer;
//复制Byte数组到Dest
function CopyByteArray(const Source: array of byte; Position, Count: integer): TBytes;

function CopyStringToNewString(old: string): string;
//释放VarRec数组
procedure FreeArrayTVarRec(argsArray: array of TVarRec);
//释放 PRCEFFrame
procedure FreePRCEFFrame(frame: PRCEFFrame);

function CefBrowserSettingsToGoBrowserSettings(const settings: TCefBrowserSettings): RCefBrowserSettings;
function GoBrowserSettingsToCefBrowserSettings(const settings: RCefBrowserSettings): TCefBrowserSettings;

//function GetCommonInstance(): CommonObject;

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

function NewStringHeader(Data: ustring): PStringHeader;
var
  PH: PStringHeader;
begin
  PH := new(PStringHeader);
  PH^.Value := UTF8Encode(Data);
  PH^.PValue := PChar(PH^.Value);
  PH^.ValueLength := Length(PH^.PValue);
  Result := PH;
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

//释放 PRCEFFrame
procedure FreePRCEFFrame(frame: PRCEFFrame);
begin
  if frame <> nil then
  begin
    frame^.Name := nil;
    frame^.Url := nil;
    frame^.Identifier := nil;
    frame := nil;
  end;
end;


function CefBrowserSettingsToGoBrowserSettings(const settings: TCefBrowserSettings): RCefBrowserSettings;
//var
  //browserSettings: RCefBrowserSettings;
begin
  //browserSettings := new(PRCefBrowserSettings);
  Result.size := @settings.size;
  Result.windowless_frame_rate := @settings.windowless_frame_rate;
  Result.standard_font_family := PChar(string(CefString(@settings.standard_font_family)));
  Result.fixed_font_family := PChar(string(CefString(@settings.fixed_font_family)));
  Result.serif_font_family := PChar(string(CefString(@settings.serif_font_family)));
  Result.sans_serif_font_family := PChar(string(CefString(@settings.sans_serif_font_family)));
  Result.cursive_font_family := PChar(string(CefString(@settings.cursive_font_family)));
  Result.fantasy_font_family := PChar(string(CefString(@settings.fantasy_font_family)));
  Result.default_font_size := @settings.default_font_size;
  Result.default_fixed_font_size := @settings.default_fixed_font_size;
  Result.minimum_font_size := @settings.minimum_font_size;
  Result.minimum_logical_font_size := @settings.minimum_logical_font_size;
  Result.default_encoding := PChar(string(CefString(@settings.default_encoding)));
  Result.remote_fonts := @(integer(settings.remote_fonts));
  Result.javascript := @(integer(settings.javascript));
  Result.javascript_close_windows := @(integer(settings.javascript_close_windows));
  Result.javascript_access_clipboard := @(integer(settings.javascript_access_clipboard));
  Result.javascript_dom_paste := @(integer(settings.javascript_dom_paste));
  Result.image_loading := @(integer(settings.image_loading));
  Result.image_shrink_standalone_to_fit := @(integer(settings.image_shrink_standalone_to_fit));
  Result.text_area_resize := @(integer(settings.text_area_resize));
  Result.tab_to_links := @(integer(settings.tab_to_links));
  Result.local_storage := @(integer(settings.local_storage));
  Result.databases := @(integer(settings.databases));
  Result.webgl := @(integer(settings.webgl));
  Result.background_color := @(cardinal(settings.background_color));
  Result.accept_language_list := PChar(string(CefString(@settings.accept_language_list)));
  Result.chrome_status_bubble := PInteger(0);
  //Result := browserSettings;
end;

function GoBrowserSettingsToCefBrowserSettings(const settings: RCefBrowserSettings): TCefBrowserSettings;
//var
  //browserSettings: TCefBrowserSettings;
begin

  Result.size := settings.size^;
  Result.windowless_frame_rate := settings.windowless_frame_rate^;
  Result.standard_font_family := CefString(PCharToUStr(settings.standard_font_family));
  Result.fixed_font_family := CefString(PCharToUStr(settings.fixed_font_family));
  Result.serif_font_family := CefString(PCharToUStr(settings.serif_font_family));
  Result.sans_serif_font_family := CefString(PCharToUStr(settings.sans_serif_font_family));
  Result.cursive_font_family := CefString(PCharToUStr(settings.cursive_font_family));
  Result.fantasy_font_family := CefString(PCharToUStr(settings.fantasy_font_family));
  Result.default_font_size := settings.default_font_size^;
  Result.default_fixed_font_size := settings.default_fixed_font_size^;
  Result.minimum_font_size := settings.minimum_font_size^;
  Result.minimum_logical_font_size := settings.minimum_logical_font_size^;
  Result.default_encoding := CefString(PCharToUStr(settings.default_encoding));
  Result.remote_fonts := TCefState(settings.remote_fonts^);
  Result.javascript := TCefState(settings.javascript^);
  Result.javascript_close_windows := TCefState(settings.javascript_close_windows^);
  Result.javascript_access_clipboard := TCefState(settings.javascript_access_clipboard^);
  Result.javascript_dom_paste := TCefState(settings.javascript_dom_paste^);
  Result.image_loading := TCefState(settings.image_loading^);
  Result.image_shrink_standalone_to_fit := TCefState(settings.image_shrink_standalone_to_fit^);
  Result.text_area_resize := TCefState(settings.text_area_resize^);
  Result.tab_to_links := TCefState(settings.tab_to_links^);
  Result.local_storage := TCefState(settings.local_storage^);
  Result.databases := TCefState(settings.databases^);
  Result.webgl := TCefState(settings.webgl^);
  Result.background_color := TCefColor(settings.background_color^);
  Result.accept_language_list := CefString(PCharToUStr(settings.accept_language_list));

  //Result := browserSettings;
end;

end.
