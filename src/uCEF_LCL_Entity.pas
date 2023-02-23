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
  uCEF_LCL_ConsoleWrite,
  fgl,
  Classes, SysUtils, uGoForm,
  uCEFTypes, uCEFInterfaces, uCEFChromium,
  {$ifdef MSWINDOWS}uCEFWindowParent{$else}uCEFLinkedWindowParent{$endif};

const
  //绑定变量事件类型
  BE_SET = 0;
  BE_GET = 1;
  BE_FUNC = 2;
  BE_CTX_CRT_BIND = 3;

  //绑定变量对象类型
  v8BindCommon = 'gocobj';// common key
  v8BindObject = 'goobj'; // object key
  v8EmitKey = 'ipc';//JS emit Go on event

  //区分64位系统和32位系统的整数大小
  intSize = SizeOf(nativeint);

  //窗口拖动消息名
  windowDrag: ustring = 'windowDrag';
  MoveDragDown: ustring = 'mousedown';
  MoveDragMove: ustring = 'mousemove';
  MoveDragUp: ustring = 'mouseup';

type
  // Golang 的数据类型
  GO_VALUE_TYPE = (
    GO_VALUE_STRING,
    GO_VALUE_INT,
    GO_VALUE_INT8,
    GO_VALUE_INT16,
    GO_VALUE_INT32,
    GO_VALUE_INT64,
    GO_VALUE_UINT,
    GO_VALUE_UINT8,
    GO_VALUE_UINT16,
    GO_VALUE_UINT32,
    GO_VALUE_UINT64,
    GO_VALUE_UINTPTR,
    GO_VALUE_FLOAT32,
    GO_VALUE_FLOAT64,
    GO_VALUE_BOOL,
    GO_VALUE_NIL,
    GO_VALUE_STRUCT,
    GO_VALUE_SLICE,
    GO_VALUE_FUNC,
    GO_VALUE_PTR,
    GO_VALUE_MAP,
    GO_VALUE_EXCEPTION,
    GO_VALUE_INVALID_TYPE, //无效类型
    GO_VALUE_ARGUMENT,     //argument
    GO_VALUE_DICTVALUE    //dictValue
    );

  {CEF Interface Pointer}
  PICefMenuModel = ^ICefMenuModel;
  PICefCallback = ^ICefCallback;
  PICefRequest = ^ICefRequest;

  PRFrameNames = ^RFrameNames;
  FrameNamesArray = array of PRFrameNames;

  RFrameNames = record
    Name: PChar;
    Value: PChar;
  end;

  {=====download begin======}
  {RDownloadItem 下载-事件 信息}
  PRDownloadItem = ^RDownloadItem;

  RDownloadItem = record
    Id: PInteger;
    CurrentSpeed: PInt64;
    PercentComplete: PInteger;
    TotalBytes: PInt64;
    ReceivedBytes: PInt64;
    StartTime: Pointer;
    EndTime: Pointer;
    FullPath: PChar;
    Url: PChar;
    OriginalUrl: PChar;
    SuggestedFileName: PChar;
    ContentDisposition: PChar;
    MimeType: PChar;
    IsValid: PBoolean;
    State: PInteger;
    //下载状态 -1:下载之前 0:下载中 1:下载取消 2:下载完成
  end;

  {RDownloadUpdate 下载更新-事件 信息}
  PRDownloadUpdate = ^RDownloadUpdate;

  RDownloadUpdate = record
    BrowserId: Pinteger;
    DownId: Pinteger;
    State: Pinteger; //state 下载状态 0:下载中 1:下载取消 2:下载完成
    FullPath: PChar;
    PercentComplete: Pinteger;
    ReceivedBytes: pint64;
    TotalBytes: pint64;
  end;

  {BrowserDownload 下载项}
  PBrowserDownload = ^BrowserDownload;

  BrowserDownload = record
    ItemCallback: ICefDownloadItemCallback;//下载更新时的回调
  end;
  {=====download end======}

  PTCEFApplicationConfig = ^TCEFApplicationConfig;
  //CEF Application 配置
  TCEFApplicationConfig = record
    FrameworkDirPath: PChar;
    ResourcesDirPath: PChar;
    LocalesDirPath: PChar;
    Cache: PChar;
    UserDataPath: PChar;
    Language: PChar;
    LocalesRequired: PChar;
    LogFile: PChar;
    MainBundlePath: PChar;
    BrowserSubprocessPath: PChar;
    LogSeverity: PUInt32;
    NoSandbox: PBoolean;
    DisableZygote: PBoolean;
    EnableGPU: PBoolean;
    SingleProcess: PBoolean;
    UseMockKeyChain: PBoolean;
    CheckCEFFiles: PBoolean;
    RemoteDebuggingPort: PInteger;
    ExternalMessagePump: PBoolean;
    MultiThreadedMessageLoop: PBoolean;
    ChromeRuntime: PBoolean;
  end;//配置 end;

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
    aSetImmediately, aDeleteCookie, Result: Pointer;//boolean
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

  //context menu
  PRContextMenuParams = ^RContextMenuParams;

  RContextMenuParams = record
    XCoord: PInteger;
    YCoord: PInteger;
    TypeFlags: PCardinal;
    LinkUrl: PChar;
    UnfilteredLinkUrl: PChar;
    SourceUrl: PChar;
    TitleText: PChar;
    PageUrl: PChar;
    FrameUrl: PChar;
    FrameCharset: PChar;
    MediaType: PInteger;
    MediaStateFlags: PCardinal;
    SelectionText: PChar;
    EditStateFlags: PCardinal;
  end;

  PRICefRequest = ^RICefRequest;

  RICefRequest = record
    Instance: Pointer;
    Url: PChar;
    Method: PChar;
    ReferrerUrl: PChar;
    ReferrerPolicy: PInteger;
    Flags: PCardinal;
    FirstPartyForCookies: PChar;
    ResourceType: PInteger;
    TransitionType: PCardinal;
    Identifier: Pointer;//uint64
  end;

  PRICefResponse = ^RICefResponse;

  RICefResponse = record
    Instance: Pointer;
    Status: PInteger;
    StatusText: PChar;
    MimeType: PChar;
    Charset: PChar;
    Error: PInteger;
    URL: PChar;
  end;

  // BeforePopup
  PRBeforePopupInfo = ^RBeforePopupInfo;

  RBeforePopupInfo = record
    TargetUrl: PChar;
    TargetFrameName: PChar;
    TargetDisposition: PInteger;
    UserGesture: PBoolean;
  end;

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

  //浏览器窗口
  TBrowserWindowMap = specialize TFPGMap<integer, TGoForm>;

  TBrowserWindowClass = class
  private
  class var
    BrowserWindows: TBrowserWindowMap;
  public
    class constructor Create;
    class destructor Destroy;
    class procedure Add(BrowserId: integer; Form: TGoForm);
    class procedure Remove(BrowserId: integer);
    class function Get(BrowserId: integer): TGoForm;
  end;

//string to hash
function StrToHash(const SoureStr: string): cardinal;
//PChar 转 UnicodeString
function PCharToUStr(const Value: PChar): unicodestring;
//String 转 UnicodeString
function StrToUStr(const Value: string): unicodestring;
//错误信息转换
function ErrorCodeToMessage(const Code: integer): unicodestring;

function ByteToInteger(const Data: array of byte; start: integer = 0): integer;
//复制Byte数组到Dest
function CopyByteArray(const Source: array of byte; Position, Count: integer): TBytes;

function CopyStringToNewString(old: string): string;
//释放VarRec数组
procedure FreeArrayTVarRec(argsArray: array of TVarRec);
//释放 PRCEFFrame
procedure FreePRCEFFrame(frame: PRCEFFrame);

//function GetCommonInstance(): CommonObject;

var
  {$ifdef DARWIN}
  MacOSXCommandLine: TStringArray;
  MacOSXCommandCount: integer;
  MyArgsStr: ustring;
  MyArgv: array of PChar;
  MyPArgs: PChar;
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

  //全局变量
  GChromiumConfig: TCEFChromiumConfig;//chromium 全局配置


  {$ifdef MSWINDOWS}
//拖拽区域
//draggable_region: HRGN;
  {$endif}

implementation


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
var
  val: string;
begin
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

//错误信息转换
function ErrorCodeToMessage(const Code: integer): unicodestring;
begin
  case Code of
    0: Result := ' successful';
    1: Result := ' Field not found';
    2: Result := ' Function not found';
    3: Result :=
        ' The variable type is not supported. Only the variable type is supported [string int double bool null undefined]';
    4: Result := ' The field or value of type [array, object, function] cannot be changed';
    5: Result := ' Type is invalid';
    6: Result := ' Failed to get string';
    7: Result := ' Failed to get int';
    8: Result := ' Failed to get a double';
    9: Result := ' Failed to get a boolean';
    10: Result := ' The type is incorrect or the number of parameters is greater than 9';
    11: Result := ' The input parameter type is incorrect [string int double boolean]';
    12: Result :=
        ' The parameter type is incorrect and can only be [string int double boolean]';
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



class constructor TBrowserWindowClass.Create;
begin
  BrowserWindows := TBrowserWindowMap.Create;
end;

class destructor TBrowserWindowClass.Destroy;
begin
  BrowserWindows.Clear;
  BrowserWindows.Free;
end;

class procedure TBrowserWindowClass.Add(BrowserId: integer; Form: TGoForm);
begin
  BrowserWindows.AddOrSetData(BrowserId, Form);
end;

class procedure TBrowserWindowClass.Remove(BrowserId: integer);
begin
  BrowserWindows.Remove(BrowserId);
end;

class function TBrowserWindowClass.Get(BrowserId: integer): TGoForm;
var
  Form: TGoForm;
begin
  if BrowserWindows.TryGetData(BrowserId, Form) then
  begin
    Result := Form;
  end
  else
    Result := nil;
end;

end.
