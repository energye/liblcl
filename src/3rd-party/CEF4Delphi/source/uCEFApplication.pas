// ************************************************************************
// ***************************** CEF4Delphi ****************************
// ************************************************************************

// CEF4Delphi is based on DCEF3 which uses CEF3 to embed a chromium-based
// browser in Delphi applications.

// The original license of DCEF3 still applies to CEF4Delphi.

// For more information about CEF4Delphi visit :
//         https://www.briskbard.com/index.php?lang=en&pageid=cef

//        Copyright 2019 Salvador D�az Fau. All rights reserved.

// ************************************************************************
// ************ vvvv Original license and comments below vvvv *************
// ************************************************************************
(*
 *                       Delphi Chromium Embedded 3
 *
 * Usage allowed under the restrictions of the Lesser GNU General Public License
 * or alternatively the restrictions of the Mozilla Public License 1.1
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for
 * the specific language governing rights and limitations under the License.
 *
 * Unit owner : Henri Gourvest <hgourvest@gmail.com>
 * Web site   : http://www.progdigy.com
 * Repository : http://code.google.com/p/delphichromiumembedded/
 * Group      : http://groups.google.com/group/delphichromiumembedded
 *
 * Embarcadero Technologies, Inc is not permitted to use or redistribute
 * this source code without explicit permission.
 *
 *)

unit uCEFApplication;

{$IFNDEF CPUX64}{$ALIGN ON}{$ENDIF}
{$MINENUMSIZE 4}

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

interface

uses
  {$IFDEF DELPHI16_UP}
    {$IFDEF MSWINDOWS}
      WinApi.Windows, {$IFNDEF FMX}Vcl.Forms,{$ENDIF}
    {$ENDIF}
    System.Classes, System.UITypes,
  {$ELSE}
  Windows, Forms, Classes,
  {$ENDIF}
  uCEFTypes, uCEFInterfaces, uCEFBase, uCEFSchemeRegistrar;

const
  CEF_SUPPORTED_VERSION_MAJOR = 3;
  CEF_SUPPORTED_VERSION_MINOR = 2623;
  CEF_SUPPORTED_VERSION_RELEASE = 1401;
  CEF_SUPPORTED_VERSION_BUILD = 0;

  LIBCEF_DLL = 'libcef.dll';

type
  TCefApplication = class
  protected
    FCache: ustring;
    FCookies: ustring;
    FUserDataPath: ustring;
    FUserAgent: ustring;
    FProductVersion: ustring;
    FLocale: ustring;
    FLocalesRequired: ustring;
    FLogFile: ustring;
    FBrowserSubprocessPath: ustring;
    FCustomFlashPath: ustring;
    FLogSeverity: TCefLogSeverity;
    FJavaScriptFlags: ustring;
    FResourcesDirPath: ustring;
    FLocalesDirPath: ustring;
    FSingleProcess: boolean;
    FNoSandbox: boolean;
    FCommandLineArgsDisabled: boolean;
    FPackLoadingDisabled: boolean;
    FRemoteDebuggingPort: integer;
    FUncaughtExceptionStackSize: integer;
    FContextSafetyImplementation: TCefContextSafetyImplementation;
    FPersistSessionCookies: boolean;
    FPersistUserPreferences: boolean;
    FIgnoreCertificateErrors: boolean;
    FBackgroundColor: TCefColor;
    FAcceptLanguageList: ustring;
    FWindowsSandboxInfo: Pointer;
    FWindowlessRenderingEnabled: boolean;
    FMultiThreadedMessageLoop: boolean;
    FDeleteCache: boolean;
    FDeleteCookies: boolean;
    FCustomCommandLines: TStringList;
    FCustomCommandLineValues: TStringList;
    FFlashEnabled: boolean;
    FEnableMediaStream: boolean;
    FEnableSpeechInput: boolean;
    FEnableGPU: boolean;
    FCheckCEFFiles: boolean;
    FLibLoaded: boolean;
    FSmoothScrolling: TCefState;
    FFastUnload: boolean;
    FDisableSafeBrowsing: boolean;
    FEnableHighDPISupport: boolean;
    FMuteAudio: boolean;
    FReRaiseExceptions: boolean;
    FShowMessageDlg: boolean;
    FSetCurrentDir: boolean;
    FGlobalContextInitialized: boolean;
    FDisableWebSecurity: boolean;
    FLibHandle: THandle;
    FOnRegisterCustomSchemes: TOnRegisterCustomSchemes;
    FAppSettings: TCefSettings;
    FDeviceScaleFactor: single;
    FCheckDevToolsResources: boolean;
    FStatus: TCefAplicationStatus;
    FMissingLibFiles: string;
    FProcessType: TCefProcessType;
    FShutdownWaitTime: cardinal;
    FMustFreeLibrary: boolean;
    FLogProcessInfo: boolean;
    FDestroyAppWindows: boolean;

    FMustCreateResourceBundleHandler: boolean;
    FMustCreateBrowserProcessHandler: boolean;
    FMustCreateRenderProcessHandler: boolean;
    FMustCreateLoadHandler: boolean;

    // ICefBrowserProcessHandler
    FOnContextInitialized: TOnContextInitializedEvent;
    FOnBeforeChildProcessLaunch: TOnBeforeChildProcessLaunchEvent;
    FOnRenderProcessThreadCreated: TOnRenderProcessThreadCreatedEvent;

    // ICefResourceBundleHandler
    FOnGetLocalizedString: TOnGetLocalizedStringEvent;
    FOnGetDataResource: TOnGetDataResourceEvent;
    FOnGetDataResourceForScale: TOnGetDataResourceForScaleEvent;

    // ICefRenderProcessHandler
    FOnRenderThreadCreated: TOnRenderThreadCreatedEvent;
    FOnWebKitInitialized: TOnWebKitInitializedEvent;
    FOnBrowserCreated: TOnBrowserCreatedEvent;
    FOnBrowserDestroyed: TOnBrowserDestroyedEvent;
    FOnBeforeNavigation: TOnBeforeNavigationEvent;
    FOnContextCreated: TOnContextCreatedEvent;
    FOnContextReleased: TOnContextReleasedEvent;
    FOnUncaughtException: TOnUncaughtExceptionEvent;
    FOnFocusedNodeChanged: TOnFocusedNodeChangedEvent;
    FOnProcessMessageReceived: TOnProcessMessageReceivedEvent;

    // ICefLoadHandler
    FOnLoadingStateChange: TOnRenderLoadingStateChange;
    FOnLoadStart: TOnRenderLoadStart;
    FOnLoadEnd: TOnRenderLoadEnd;
    FOnLoadError: TOnRenderLoadError;

    procedure SetCache(const aValue: ustring);
    procedure SetCookies(const aValue: ustring);
    procedure SetUserDataPath(const aValue: ustring);
    procedure SetBrowserSubprocessPath(const aValue: ustring);
    procedure SetResourcesDirPath(const aValue: ustring);
    procedure SetLocalesDirPath(const aValue: ustring);
    procedure SetOsmodalLoop(aValue: boolean);

    function GetLibCefVersion: string;
    function GetLibCefPath: string;
    function GetMustCreateResourceBundleHandler: boolean;
    function GetMustCreateBrowserProcessHandler: boolean;
    function GetMustCreateRenderProcessHandler: boolean;
    function GetMustCreateLoadHandler: boolean;
    function GetGlobalContextInitialized: boolean;
    function GetChildProcessesCount: integer;
    function GetUsedMemory: cardinal;
    function GetTotalSystemMemory: uint64;
    function GetAvailableSystemMemory: uint64;
    function GetSystemMemoryLoad: cardinal;

    function LoadCEFlibrary: boolean; virtual;
    function Load_cef_app_capi_h: boolean;
    function Load_cef_browser_capi_h: boolean;
    function Load_cef_command_line_capi_h: boolean;
    function Load_cef_cookie_capi_h: boolean;
    function Load_cef_drag_data_capi_h: boolean;
    function Load_cef_geolocation_capi_h: boolean;
    function Load_cef_origin_whitelist_capi_h: boolean;
    function Load_cef_parser_capi_h: boolean;
    function Load_cef_path_util_capi_h: boolean;
    function Load_cef_print_settings_capi_h: boolean;
    function Load_cef_process_message_capi_h: boolean;
    function Load_cef_process_util_capi_h: boolean;
    function Load_cef_request_capi_h: boolean;
    function Load_cef_request_context_capi_h: boolean;
    function Load_cef_resource_bundle_capi_h: boolean;
    function Load_cef_response_capi_h: boolean;
    function Load_cef_scheme_capi_h: boolean;
    function Load_cef_stream_capi_h: boolean;
    function Load_cef_task_capi_h: boolean;
    function Load_cef_trace_capi_h: boolean;
    function Load_cef_urlrequest_capi_h: boolean;
    function Load_cef_v8_capi_h: boolean;
    function Load_cef_values_capi_h: boolean;
    function Load_cef_web_plugin_capi_h: boolean;
    function Load_cef_xml_reader_capi_h: boolean;
    function Load_cef_zip_reader_capi_h: boolean;
    function Load_cef_logging_internal_h: boolean;
    function Load_cef_string_list_h: boolean;
    function Load_cef_string_map_h: boolean;
    function Load_cef_string_multimap_h: boolean;
    function Load_cef_string_types_h: boolean;
    function Load_cef_thread_internal_h: boolean;
    function Load_cef_trace_event_internal_h: boolean;

    procedure ShutDown;
    procedure FreeLibcefLibrary;
    function ExecuteProcess(const aApp: ICefApp): integer;
    procedure InitializeSettings(var aSettings: TCefSettings);
    function InitializeLibrary(const aApp: ICefApp): boolean;
    function InitializeCookies: boolean;
    procedure RenameAndDeleteDir(const aDirectory: string);
    function MultiExeProcessing: boolean;
    function SingleExeProcessing: boolean;
    function CheckCEFLibrary: boolean;
    function FindFlashDLL(var aFileName: string): boolean;
    procedure ShowErrorMessageDlg(const aError: string); virtual;
    function ParseProcessType: TCefProcessType;
  public
    constructor Create;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure AddCustomCommandLine(const aCommandLine: string;
      const aValue: string = '');
    function StartMainProcess: boolean;
    function StartSubProcess: boolean;

    procedure DoMessageLoopWork;
    procedure RunMessageLoop;
    procedure QuitMessageLoop;
    procedure UpdateDeviceScaleFactor;

    // Internal procedures. Only TInternalApp, TCefCustomBrowserProcessHandler,
    // ICefResourceBundleHandler, ICefRenderProcessHandler and ICefLoadHandler should use them.
    procedure Internal_OnBeforeCommandLineProcessing(const processType: ustring;
      const commandLine: ICefCommandLine);
    procedure Internal_OnRegisterCustomSchemes(const registrar: ICefSchemeRegistrar);
    procedure Internal_OnContextInitialized;
    procedure Internal_OnBeforeChildProcessLaunch(
      const commandLine: ICefCommandLine);
    procedure Internal_OnRenderProcessThreadCreated(const extraInfo: ICefListValue);
    function Internal_GetLocalizedString(stringId: integer;
      var stringVal: ustring): boolean;
    function Internal_GetDataResource(resourceId: integer;
      var Data: Pointer; var dataSize: nativeuint): boolean;
    function Internal_GetDataResourceForScale(resourceId: integer;
      scaleFactor: TCefScaleFactor; var Data: Pointer; var dataSize: nativeuint): boolean;
    procedure Internal_OnRenderThreadCreated(const extraInfo: ICefListValue);
    procedure Internal_OnWebKitInitialized;
    procedure Internal_OnBrowserCreated(const browser: ICefBrowser);
    procedure Internal_OnBrowserDestroyed(const browser: ICefBrowser);
    procedure Internal_OnBeforeNavigation(const browser: ICefBrowser;
      const frame: ICefFrame; const request: ICefRequest; navigationType: TCefNavigationType;
      isRedirect: boolean; var aStopNavigation: boolean);
    procedure Internal_OnContextCreated(const browser: ICefBrowser;
      const frame: ICefFrame; const context: ICefv8Context);
    procedure Internal_OnContextReleased(const browser: ICefBrowser;
      const frame: ICefFrame; const context: ICefv8Context);
    procedure Internal_OnUncaughtException(const browser: ICefBrowser;
      const frame: ICefFrame; const context: ICefv8Context;
      const Exception: ICefV8Exception; const stackTrace: ICefV8StackTrace);
    procedure Internal_OnFocusedNodeChanged(const browser: ICefBrowser;
      const frame: ICefFrame; const node: ICefDomNode);
    procedure Internal_OnProcessMessageReceived(const browser: ICefBrowser;
      sourceProcess: TCefProcessId; const aMessage: ICefProcessMessage;
      var aHandled: boolean);
    procedure Internal_OnLoadingStateChange(const browser: ICefBrowser;
      isLoading, canGoBack, canGoForward: boolean);
    procedure Internal_OnLoadStart(const browser: ICefBrowser;
      const frame: ICefFrame);
    procedure Internal_OnLoadEnd(const browser: ICefBrowser;
      const frame: ICefFrame; httpStatusCode: integer);
    procedure Internal_OnLoadError(const browser: ICefBrowser;
      const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);

    property Cache: ustring
      read FCache write SetCache;
    property Cookies: ustring
      read FCookies write SetCookies;
    property UserDataPath: ustring
      read FUserDataPath write SetUserDataPath;
    property UserAgent: ustring
      read FUserAgent write FUserAgent;
    property ProductVersion: ustring
      read FProductVersion write FProductVersion;
    property Locale: ustring
      read FLocale write FLocale;
    property LogFile: ustring
      read FLogFile write FLogFile;
    property BrowserSubprocessPath: ustring
      read FBrowserSubprocessPath write SetBrowserSubprocessPath;
    property LogSeverity: TCefLogSeverity
      read FLogSeverity write FLogSeverity;
    property JavaScriptFlags: ustring
      read FJavaScriptFlags write FJavaScriptFlags;
    property ResourcesDirPath: ustring
      read FResourcesDirPath write SetResourcesDirPath;
    property LocalesDirPath: ustring
      read FLocalesDirPath write SetLocalesDirPath;
    property SingleProcess: boolean
      read FSingleProcess write FSingleProcess;
    property NoSandbox: boolean
      read FNoSandbox write FNoSandbox;
    property CommandLineArgsDisabled: boolean
      read FCommandLineArgsDisabled write FCommandLineArgsDisabled;
    property PackLoadingDisabled: boolean
      read FPackLoadingDisabled write FPackLoadingDisabled;
    property RemoteDebuggingPort: integer
      read FRemoteDebuggingPort write FRemoteDebuggingPort;
    property UncaughtExceptionStackSize: integer
      read FUncaughtExceptionStackSize write FUncaughtExceptionStackSize;
    property ContextSafetyImplementation: TCefContextSafetyImplementation
      read FContextSafetyImplementation write FContextSafetyImplementation;
    property PersistSessionCookies: boolean
      read FPersistSessionCookies write FPersistSessionCookies;
    property PersistUserPreferences: boolean
      read FPersistUserPreferences write FPersistUserPreferences;
    property IgnoreCertificateErrors: boolean
      read FIgnoreCertificateErrors write FIgnoreCertificateErrors;
    property BackgroundColor: TCefColor
      read FBackgroundColor write FBackgroundColor;
    property AcceptLanguageList: ustring
      read FAcceptLanguageList write FAcceptLanguageList;
    property WindowsSandboxInfo: Pointer
      read FWindowsSandboxInfo write FWindowsSandboxInfo;
    property WindowlessRenderingEnabled: boolean
      read FWindowlessRenderingEnabled write FWindowlessRenderingEnabled;
    property MultiThreadedMessageLoop: boolean
      read FMultiThreadedMessageLoop write FMultiThreadedMessageLoop;
    property DeleteCache: boolean
      read FDeleteCache write FDeleteCache;
    property DeleteCookies: boolean
      read FDeleteCookies write FDeleteCookies;
    property FlashEnabled: boolean
      read FFlashEnabled write FFlashEnabled;
    property EnableMediaStream: boolean
      read FEnableMediaStream write FEnableMediaStream;
    property EnableSpeechInput: boolean
      read FEnableSpeechInput write FEnableSpeechInput;
    property EnableGPU: boolean
      read FEnableGPU write FEnableGPU;
    property CheckCEFFiles: boolean
      read FCheckCEFFiles write FCheckCEFFiles;
    property ShowMessageDlg: boolean
      read FShowMessageDlg write FShowMessageDlg;
    property SetCurrentDir: boolean
      read FSetCurrentDir write FSetCurrentDir;
    property GlobalContextInitialized: boolean
      read GetGlobalContextInitialized;
    property LibCefVersion: string
      read GetLibCefVersion;
    property LibCefPath: string
      read GetLibCefPath;
    property SmoothScrolling: TCefState
      read FSmoothScrolling write FSmoothScrolling;
    property FastUnload: boolean
      read FFastUnload write FFastUnload;
    property DisableSafeBrowsing: boolean
      read FDisableSafeBrowsing write FDisableSafeBrowsing;
    property LibLoaded: boolean
      read FLibLoaded;
    property EnableHighDPISupport: boolean
      read FEnableHighDPISupport write FEnableHighDPISupport;
    property MuteAudio: boolean
      read FMuteAudio write FMuteAudio;
    property DisableWebSecurity: boolean
      read FDisableWebSecurity write FDisableWebSecurity;
    property ReRaiseExceptions: boolean
      read FReRaiseExceptions write FReRaiseExceptions;
    property DeviceScaleFactor: single
      read FDeviceScaleFactor;
    property CheckDevToolsResources: boolean
      read FCheckDevToolsResources write FCheckDevToolsResources;
    property LocalesRequired: ustring
      read FLocalesRequired write FLocalesRequired;
    property CustomFlashPath: ustring
      read FCustomFlashPath write FCustomFlashPath;
    property ProcessType: TCefProcessType
      read FProcessType;
    property MustCreateResourceBundleHandler: boolean
      read GetMustCreateResourceBundleHandler write FMustCreateResourceBundleHandler;
    property MustCreateBrowserProcessHandler: boolean
      read GetMustCreateBrowserProcessHandler write FMustCreateBrowserProcessHandler;
    property MustCreateRenderProcessHandler: boolean
      read GetMustCreateRenderProcessHandler write FMustCreateRenderProcessHandler;
    property MustCreateLoadHandler: boolean
      read GetMustCreateLoadHandler write FMustCreateLoadHandler;
    property OsmodalLoop:
      boolean
      write SetOsmodalLoop;
    property Status: TCefAplicationStatus
      read FStatus;
    property MissingLibFiles: string
      read FMissingLibFiles;
    property ShutdownWaitTime: cardinal
      read FShutdownWaitTime write FShutdownWaitTime;
    property MustFreeLibrary: boolean
      read FMustFreeLibrary write FMustFreeLibrary;
    property LogProcessInfo: boolean
      read FLogProcessInfo write FLogProcessInfo;
    property DestroyAppWindows: boolean
      read FDestroyAppWindows write FDestroyAppWindows;
    property ChildProcessesCount: integer
      read GetChildProcessesCount;
    property UsedMemory: cardinal
      read GetUsedMemory;
    property TotalSystemMemory: uint64
      read GetTotalSystemMemory;
    property AvailableSystemMemory: uint64
      read GetAvailableSystemMemory;
    property SystemMemoryLoad: cardinal
      read GetSystemMemoryLoad;

    property OnRegCustomSchemes: TOnRegisterCustomSchemes
      read FOnRegisterCustomSchemes write FOnRegisterCustomSchemes;

    // ICefBrowserProcessHandler
    property OnContextInitialized: TOnContextInitializedEvent
      read FOnContextInitialized write FOnContextInitialized;
    property OnBeforeChildProcessLaunch: TOnBeforeChildProcessLaunchEvent
      read FOnBeforeChildProcessLaunch write FOnBeforeChildProcessLaunch;
    property OnRenderProcessThreadCreated: TOnRenderProcessThreadCreatedEvent
      read FOnRenderProcessThreadCreated write FOnRenderProcessThreadCreated;

    // ICefResourceBundleHandler
    property OnGetLocalizedString: TOnGetLocalizedStringEvent
      read FOnGetLocalizedString write FOnGetLocalizedString;
    property OnGetDataResource: TOnGetDataResourceEvent
      read FOnGetDataResource write FOnGetDataResource;
    property OnGetDataResourceForScale: TOnGetDataResourceForScaleEvent
      read FOnGetDataResourceForScale write FOnGetDataResourceForScale;

    // ICefRenderProcessHandler
    property OnRenderThreadCreated: TOnRenderThreadCreatedEvent
      read FOnRenderThreadCreated write FOnRenderThreadCreated;
    property OnWebKitInitialized: TOnWebKitInitializedEvent
      read FOnWebKitInitialized write FOnWebKitInitialized;
    property OnBrowserCreated: TOnBrowserCreatedEvent
      read FOnBrowserCreated write FOnBrowserCreated;
    property OnBrowserDestroyed: TOnBrowserDestroyedEvent
      read FOnBrowserDestroyed write FOnBrowserDestroyed;
    property OnBeforeNavigation: TOnBeforeNavigationEvent
      read FOnBeforeNavigation write FOnBeforeNavigation;
    property OnContextCreated: TOnContextCreatedEvent
      read FOnContextCreated write FOnContextCreated;
    property OnContextReleased: TOnContextReleasedEvent
      read FOnContextReleased write FOnContextReleased;
    property OnUncaughtException: TOnUncaughtExceptionEvent
      read FOnUncaughtException write FOnUncaughtException;
    property OnFocusedNodeChanged: TOnFocusedNodeChangedEvent
      read FOnFocusedNodeChanged write FOnFocusedNodeChanged;
    property OnProcessMessageReceived: TOnProcessMessageReceivedEvent
      read FOnProcessMessageReceived write FOnProcessMessageReceived;
  end;

  TCEFDirectoryDeleterThread = class(TThread)
  protected
    FDirectory: string;

    procedure Execute; override;
  public
    constructor Create(const aDirectory: string);
  end;

var
  GlobalCEFApp: TCefApplication = nil;

procedure DestroyGlobalCEFApp;

implementation

uses
  {$IFDEF DELPHI16_UP}
  System.Math, System.IOUtils, System.SysUtils, {$IFDEF MSWINDOWS}WinApi.TlHelp32, PSAPI,{$ENDIF}
  {$ELSE}
  Math, {$IFDEF DELPHI14_UP}IOUtils,{$ENDIF} SysUtils, {$IFDEF MSWINDOWS}jwatlhelp32, jwapsapi,{$ENDIF}
  {$ENDIF}
  uCEFLibFunctions, uCEFMiscFunctions, uCEFCommandLine, uCEFConstants,
  uCEFSchemeHandlerFactory, uCEFCookieManager, uCEFApp;

procedure DestroyGlobalCEFApp;
begin
  if (GlobalCEFApp <> nil) then FreeAndNil(GlobalCEFApp);
end;

constructor TCefApplication.Create;
begin
  inherited Create;

  FStatus := asLoading;
  FMissingLibFiles := '';
  FLibHandle := 0;
  FCache := '';
  FCookies := '';
  FUserDataPath := '';
  FUserAgent := '';
  FProductVersion := '';
  FLocale := '';
  FLogFile := '';
  FBrowserSubprocessPath := '';
  FCustomFlashPath := '';
  FLogSeverity := LOGSEVERITY_DISABLE;
  FJavaScriptFlags := '';
  FResourcesDirPath := '';
  FLocalesDirPath := '';
  FSingleProcess := False;
  FNoSandbox := True;
  FCommandLineArgsDisabled := False;
  FPackLoadingDisabled := False;
  FRemoteDebuggingPort := 0;
  FUncaughtExceptionStackSize := 0;
  FContextSafetyImplementation := csiDefault;
  FPersistSessionCookies := False;
  FPersistUserPreferences := False;
  FIgnoreCertificateErrors := False;
  FBackgroundColor := 0;
  FAcceptLanguageList := '';
  FWindowsSandboxInfo := nil;
  FWindowlessRenderingEnabled := False;
  FMultiThreadedMessageLoop := True;
  FDeleteCache := False;
  FDeleteCookies := False;
  FFlashEnabled := True;
  FEnableMediaStream := True;
  FEnableSpeechInput := True;
  FEnableGPU := False;
  FCustomCommandLines := nil;
  FCustomCommandLineValues := nil;
  FCheckCEFFiles := True;
  FSmoothScrolling := STATE_DEFAULT;
  FFastUnload := False;
  FDisableSafeBrowsing := False;
  FOnRegisterCustomSchemes := nil;
  FEnableHighDPISupport := False;
  FMuteAudio := False;
  FDisableWebSecurity := False;
  FReRaiseExceptions := False;
  FLibLoaded := False;
  FShowMessageDlg := True;
  FSetCurrentDir := False;
  FGlobalContextInitialized := False;
  FCheckDevToolsResources := True;
  FLocalesRequired := '';
  FProcessType := ParseProcessType;
  FShutdownWaitTime := 0;
  FMustFreeLibrary := False;
  FLogProcessInfo := False;
  FDestroyAppWindows := True;

  FMustCreateResourceBundleHandler := False;
  FMustCreateBrowserProcessHandler := True;
  FMustCreateRenderProcessHandler := False;
  FMustCreateLoadHandler := False;

  // ICefBrowserProcessHandler
  FOnContextInitialized := nil;
  FOnBeforeChildProcessLaunch := nil;
  FOnRenderProcessThreadCreated := nil;

  // ICefResourceBundleHandler
  FOnGetLocalizedString := nil;
  FOnGetDataResource := nil;
  FOnGetDataResourceForScale := nil;

  // ICefRenderProcessHandler
  FOnRenderThreadCreated := nil;
  FOnWebKitInitialized := nil;
  FOnBrowserCreated := nil;
  FOnBrowserDestroyed := nil;
  FOnBeforeNavigation := nil;
  FOnContextCreated := nil;
  FOnContextReleased := nil;
  FOnUncaughtException := nil;
  FOnFocusedNodeChanged := nil;
  FOnProcessMessageReceived := nil;

  // ICefLoadHandler
  FOnLoadingStateChange := nil;
  FOnLoadStart := nil;
  FOnLoadEnd := nil;
  FOnLoadError := nil;

  UpdateDeviceScaleFactor;

  FAppSettings.size := SizeOf(TCefSettings);
  FillChar(FAppSettings, FAppSettings.size, 0);

  IsMultiThread := True;

  SetExceptionMask([exInvalidOp, exDenormalized, exZeroDivide,
    exOverflow, exUnderflow, exPrecision]);
end;

destructor TCefApplication.Destroy;
begin
  try
    if (FProcessType = ptBrowser) then
    begin
      if (FShutdownWaitTime > 0) then sleep(FShutdownWaitTime);

      ShutDown;
    end;

    FreeLibcefLibrary;

    if (FCustomCommandLines <> nil) then FreeAndNil(FCustomCommandLines);
    if (FCustomCommandLineValues <> nil) then FreeAndNil(FCustomCommandLineValues);
  finally
    inherited Destroy;
  end;
end;

procedure TCefApplication.AfterConstruction;
begin
  inherited AfterConstruction;

  FCustomCommandLines := TStringList.Create;
  FCustomCommandLineValues := TStringList.Create;
end;

procedure TCefApplication.AddCustomCommandLine(const aCommandLine, aValue: string);
begin
  if (FCustomCommandLines <> nil) then FCustomCommandLines.Add(aCommandLine);
  if (FCustomCommandLineValues <> nil) then FCustomCommandLineValues.Add(aValue);
end;

// This function must only be called by the main executable when the application
// is configured to use a different executable for the subprocesses.
// The process calling ths function must be the browser process.
function TCefApplication.MultiExeProcessing: boolean;
var
  TempApp: ICefApp;
begin
  Result := False;
  TempApp := nil;

  try
    try
      if (ProcessType = ptBrowser) and CheckCEFLibrary and
        LoadCEFlibrary then
      begin
        TempApp := TCustomCefApp.Create(self);
        Result := InitializeLibrary(TempApp);
      end;
    except
      on e: Exception do
        if CustomExceptionHandler('TCefApplication.MultiExeProcessing', e) then raise;
    end;
  finally
    TempApp := nil;
  end;
end;

// This function will be called by all processes when the application is configured
// to use the same executable for all the processes : browser, render, etc.
function TCefApplication.SingleExeProcessing: boolean;
var
  TempApp: ICefApp;
begin
  Result := False;
  TempApp := nil;

  try
    if CheckCEFLibrary and LoadCEFlibrary then
    begin
      {$IFNDEF FPC}
      {$IFNDEF FMX}
      if FDestroyAppWindows and (ProcessType <> ptBrowser) and
        (Application <> nil) then
      begin
        // This is the fix for the issue #139
        // https://github.com/salvadordf/CEF4Delphi/issues/139
        // Subprocesses will never use these window handles but TApplication creates them
        // before executing the code in the DPR file. Any other application trying to
        // initiate a DDE conversation will use SendMessage or SendMessageTimeout to
        // broadcast the WM_DDE_INITIATE to all top-level windows. The subprocesses never
        // call Application.Run so the SendMessage freezes the other applications.
        if (Application.Handle <> 0) then DestroyWindow(Application.Handle);
        {$IFDEF DELPHI9_UP}
            if (Application.PopupControlWnd <> 0) then DeallocateHWnd(Application.PopupControlWnd);
        {$ENDIF}
      end;
      {$ENDIF}
      {$ENDIF}

      TempApp := TCustomCefApp.Create(self);
      Result := (ExecuteProcess(TempApp) < 0) and InitializeLibrary(TempApp);
    end;
  finally
    TempApp := nil;
  end;
end;

function TCefApplication.GetLibCefVersion: string;
begin
  Result := IntToStr(CEF_SUPPORTED_VERSION_MAJOR) + '.' +
    IntToStr(CEF_SUPPORTED_VERSION_MINOR) + '.' +
    IntToStr(CEF_SUPPORTED_VERSION_RELEASE) + '.' +
    IntToStr(CEF_SUPPORTED_VERSION_BUILD);
end;

function TCefApplication.GetLibCefPath: string;
begin
  Result := LIBCEF_DLL;
end;

procedure TCefApplication.SetCache(const aValue: ustring);
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      FCache := GetModulePath + aValue
    else
      FCache := aValue;
  end
  else
    FCache := '';
end;

procedure TCefApplication.SetCookies(const aValue: ustring);
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      FCookies := GetModulePath + aValue
    else
      FCookies := aValue;
  end
  else
    FCookies := '';
end;

procedure TCefApplication.SetUserDataPath(const aValue: ustring);
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      FUserDataPath := GetModulePath + aValue
    else
      FUserDataPath := aValue;
  end
  else
    FUserDataPath := '';
end;

procedure TCefApplication.SetBrowserSubprocessPath(const aValue: ustring);
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      FBrowserSubprocessPath := GetModulePath + aValue
    else
      FBrowserSubprocessPath := aValue;
  end
  else
    FBrowserSubprocessPath := '';
end;

procedure TCefApplication.SetResourcesDirPath(const aValue: ustring);
var
  TempPath: string;
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      TempPath := GetModulePath + aValue
    else
      TempPath := aValue;

    if DirectoryExists(TempPath) then
      FResourcesDirPath := TempPath
    else
      FResourcesDirPath := '';
  end
  else
    FResourcesDirPath := '';
end;

procedure TCefApplication.SetLocalesDirPath(const aValue: ustring);
var
  TempPath: string;
begin
  if (length(aValue) > 0) then
  begin
    if CustomPathIsRelative(aValue) then
      TempPath := GetModulePath + aValue
    else
      TempPath := aValue;

    if DirectoryExists(TempPath) then
      FLocalesDirPath := TempPath
    else
      FLocalesDirPath := '';
  end
  else
    FLocalesDirPath := '';
end;

function TCefApplication.CheckCEFLibrary: boolean;
var
  TempString, TempOldDir: string;
  TempMissingFrm, TempMissingRsc, TempMissingLoc, TempMissingSubProc: boolean;
  TempMachine: integer;
  TempVersionInfo: TFileVersionInfo;
begin
  Result := False;

  if not (FCheckCEFFiles) or (FProcessType <> ptBrowser) then
    Result := True
  else
  begin
    if FSetCurrentDir then
    begin
      TempOldDir := GetCurrentDir;
      chdir(GetModulePath);
    end;

    TempMissingSubProc := not
      (CheckSubprocessPath(FBrowserSubprocessPath, FMissingLibFiles));
    TempMissingFrm := not (CheckDLLs('', FMissingLibFiles));
    TempMissingRsc := not
      (CheckResources(FResourcesDirPath, FMissingLibFiles, FCheckDevToolsResources));
    TempMissingLoc := not
      (CheckLocales(FLocalesDirPath, FMissingLibFiles, FLocalesRequired));

    if TempMissingFrm or TempMissingRsc or TempMissingLoc or TempMissingSubProc then
    begin
      FStatus := asErrorMissingFiles;
      TempString := 'CEF3 binaries missing !';

      if (length(FMissingLibFiles) > 0) then
        TempString := TempString + CRLF + CRLF +
          'The missing files are :' + CRLF +
          trim(FMissingLibFiles);

      ShowErrorMessageDlg(TempString);
    end
    else
    if CheckDLLVersion(LibCefPath,
      CEF_SUPPORTED_VERSION_MAJOR,
      CEF_SUPPORTED_VERSION_MINOR,
      CEF_SUPPORTED_VERSION_RELEASE,
      CEF_SUPPORTED_VERSION_BUILD) then
    begin
      if GetDLLHeaderMachine(LibCefPath, TempMachine) then
        {$IFDEF MSWINDOWS}
        case TempMachine of
          CEF_IMAGE_FILE_MACHINE_I386:
            if Is32BitProcess then
              Result := True
            else
            begin
              FStatus := asErrorDLLVersion;
              TempString :=
                'Wrong CEF3 binaries !' + CRLF +
                CRLF +
                'Use the 32 bit CEF3 binaries with 32 bits applications only.';

              ShowErrorMessageDlg(TempString);
            end;

          CEF_IMAGE_FILE_MACHINE_AMD64:
            if not (Is32BitProcess) then
              Result := True
            else
            begin
              FStatus := asErrorDLLVersion;
              TempString :=
                'Wrong CEF3 binaries !' + CRLF +
                CRLF +
                'Use the 64 bit CEF3 binaries with 64 bits applications only.';

              ShowErrorMessageDlg(TempString);
            end;

          else
          begin
            FStatus := asErrorDLLVersion;
            TempString :=
              'Unknown CEF3 binaries !' + CRLF +
              CRLF +
              'Use only the CEF3 binaries specified in the CEF4Delphi Readme.md file at ' +
              CEF4DELPHI_URL;

            ShowErrorMessageDlg(TempString);
          end;
        end
      else
        Result := True;
      {$ELSE}
            Result := True;
      {$ENDIF}
    end
    else
    begin
      FStatus := asErrorDLLVersion;
      TempString := 'Unsupported CEF version !' +
        CRLF + CRLF +
        'Use only the CEF3 binaries specified in the CEF4Delphi Readme.md file at '
        +
        CEF4DELPHI_URL;

      if GetDLLVersion(LibCefPath, TempVersionInfo) then
        TempString := TempString + CRLF + CRLF +
          'Expected ' + LIBCEF_DLL + ' version : ' +
          LibCefVersion + CRLF + 'Found ' +
          LIBCEF_DLL + ' version : ' + FileVersionInfoToString(TempVersionInfo);

      ShowErrorMessageDlg(TempString);
    end;

    if FSetCurrentDir then chdir(TempOldDir);
  end;
end;

function TCefApplication.StartMainProcess: boolean;
begin
  if (FStatus <> asLoading) then
    Result := False
  else
  if not (FSingleProcess) and (length(FBrowserSubprocessPath) > 0) then
    Result := MultiExeProcessing
  else
    Result := SingleExeProcessing;
end;

// This function can only be called by the executable used for the subprocesses.
// The application must be configured to use different executables for the subprocesses.
// The process calling this function can't be the browser process.
function TCefApplication.StartSubProcess: boolean;
var
  TempApp: ICefApp;
begin
  Result := False;
  TempApp := nil;

  try
    if not (FSingleProcess) and (FStatus = asLoading) and
      (ProcessType <> ptBrowser) and LoadCEFlibrary then
    begin
      TempApp := TCustomCefApp.Create(self);
      Result := (ExecuteProcess(TempApp) >= 0);
    end;
  finally
    TempApp := nil;
  end;
end;

procedure TCefApplication.DoMessageLoopWork;
begin
  if FLibLoaded and not (FMultiThreadedMessageLoop) then cef_do_message_loop_work;
end;

procedure TCefApplication.RunMessageLoop;
begin
  if FLibLoaded and not (FMultiThreadedMessageLoop) then cef_run_message_loop;
end;

procedure TCefApplication.QuitMessageLoop;
begin
  if FLibLoaded and not (FMultiThreadedMessageLoop) then cef_quit_message_loop;
end;

procedure TCefApplication.SetOsmodalLoop(aValue: boolean);
begin
  if FLibLoaded then cef_set_osmodal_loop(Ord(aValue));
end;

procedure TCefApplication.UpdateDeviceScaleFactor;
begin
  FDeviceScaleFactor := GetDeviceScaleFactor;
end;

procedure TCefApplication.ShutDown;
begin
  try
    FStatus := asShuttingDown;
    if FLibLoaded then cef_shutdown;
  except
    on e: Exception do
      if CustomExceptionHandler('TCefApplication.ShutDown', e) then raise;
  end;
end;

procedure TCefApplication.FreeLibcefLibrary;
begin
  try
    try
      if FMustFreeLibrary and (FLibHandle <> 0) then FreeLibrary(FLibHandle);
    except
      on e: Exception do
        if CustomExceptionHandler('TCefApplication.FreeLibcefLibrary', e) then raise;
    end;
  finally
    FLibHandle := 0;
    FLibLoaded := False;
    FStatus := asUnloaded;
  end;
end;

function TCefApplication.ExecuteProcess(const aApp: ICefApp): integer;
var
  TempArgs: TCefMainArgs;
begin
  Result := -1;
  try
    if (aApp <> nil) then
    begin
      TempArgs.instance := HINSTANCE;
      Result := cef_execute_process(@TempArgs, aApp.Wrap,
        FWindowsSandboxInfo);
    end;
  except
    on e: Exception do
    begin
      FStatus := asErrorExecutingProcess;
      if CustomExceptionHandler('TCefApplication.ExecuteProcess', e) then raise;
    end;
  end;
end;

procedure TCefApplication.InitializeSettings(var aSettings: TCefSettings);
begin
  aSettings.size := SizeOf(TCefSettings);
  aSettings.single_process := Ord(FSingleProcess);
  aSettings.no_sandbox := Ord(FNoSandbox);
  aSettings.browser_subprocess_path := CefString(FBrowserSubprocessPath);
  aSettings.multi_threaded_message_loop := Ord(FMultiThreadedMessageLoop);
  aSettings.windowless_rendering_enabled := Ord(FWindowlessRenderingEnabled);
  aSettings.command_line_args_disabled := Ord(FCommandLineArgsDisabled);
  aSettings.cache_path := CefString(FCache);
  aSettings.user_data_path := CefString(FUserDataPath);
  aSettings.persist_session_cookies := Ord(FPersistSessionCookies);
  aSettings.persist_user_preferences := Ord(FPersistUserPreferences);
  aSettings.user_agent := CefString(FUserAgent);
  aSettings.product_version := CefString(FProductVersion);
  aSettings.locale := CefString(FLocale);
  aSettings.log_file := CefString(FLogFile);
  aSettings.log_severity := FLogSeverity;
  aSettings.javascript_flags := CefString(FJavaScriptFlags);
  aSettings.resources_dir_path := CefString(FResourcesDirPath);
  aSettings.locales_dir_path := CefString(FLocalesDirPath);
  aSettings.pack_loading_disabled := Ord(FPackLoadingDisabled);
  aSettings.remote_debugging_port := FRemoteDebuggingPort;
  aSettings.uncaught_exception_stack_size := FUncaughtExceptionStackSize;

  case FContextSafetyImplementation of
    csiManyContexts: aSettings.context_safety_implementation := 1;
    csiDisabled: aSettings.context_safety_implementation := -1;
    else
      aSettings.context_safety_implementation := 0;
  end;

  aSettings.ignore_certificate_errors := Ord(FIgnoreCertificateErrors);
  aSettings.background_color := FBackgroundColor;
  aSettings.accept_language_list := CefString(FAcceptLanguageList);
end;

function TCefApplication.InitializeLibrary(const aApp: ICefApp): boolean;
var
  TempArgs: TCefMainArgs;
begin
  Result := False;

  try
    try
      if (aApp <> nil) then
      begin
        if FDeleteCache then RenameAndDeleteDir(FCache);
        if FDeleteCookies then RenameAndDeleteDir(FCookies);

        InitializeSettings(FAppSettings);

        TempArgs.instance := HINSTANCE;

        if (cef_initialize(@TempArgs, @FAppSettings, aApp.Wrap,
          FWindowsSandboxInfo) <> 0) then
        begin
          Result := True;
          FStatus := asInitialized;
        end;
      end;
    except
      on e: Exception do
        if CustomExceptionHandler('TCefApplication.InitializeLibrary', e) then raise;
    end;
  finally
    if not (Result) then FStatus := asErrorInitializingLibrary;
  end;
end;

function TCefApplication.InitializeCookies: boolean;
var
  TempCookieManager: ICefCookieManager;
begin
  Result := False;

  try
    if (length(FCookies) > 0) then
    begin
      TempCookieManager := TCefCookieManagerRef.Global(nil);

      if (TempCookieManager <> nil) and
        TempCookieManager.SetStoragePath(FCookies, FPersistSessionCookies, nil) then
        Result := True
      else
        OutputDebugMessage(
          'TCefApplication.InitializeCookies error : cookies cannot be accessed');
    end
    else
      Result := True;
  except
    on e: Exception do
      if CustomExceptionHandler('TCefApplication.InitializeCookies', e) then raise;
  end;
end;

procedure TCefApplication.RenameAndDeleteDir(const aDirectory: string);
var
  TempOldDir, TempNewDir: string;
  i: integer;
  TempThread: TCEFDirectoryDeleterThread;
begin
  try
    if (length(aDirectory) = 0) or not (DirectoryExists(aDirectory)) then exit;

    TempOldDir := ExcludeTrailingPathDelimiter(aDirectory);

    if (Pos(PathDelim, TempOldDir) > 0) and
      (length(ExtractFileName(TempOldDir)) > 0) then
    begin
      i := 0;

      repeat
        Inc(i);
        TempNewDir := TempOldDir + '(' + IntToStr(i) + ')';
      until not (DirectoryExists(TempNewDir));

      if MoveFileW(pwidechar(TempOldDir + chr(0)), pwidechar(TempNewDir + chr(0))) then
      begin
        TempThread := TCEFDirectoryDeleterThread.Create(TempNewDir);
        {$IFDEF DELPHI14_UP}
            TempThread.Start;
        {$ELSE}
        TempThread.Resume;
        {$ENDIF}
      end
      else
        DeleteDirContents(aDirectory);
    end
    else
      DeleteDirContents(aDirectory);
  except
    on e: Exception do
      if CustomExceptionHandler('TCefApplication.RenameAndDeleteDir', e) then raise;
  end;
end;

function TCefApplication.FindFlashDLL(var aFileName: string): boolean;
var
  TempSearchRec: TSearchRec;
  TempProductName, TempPath: string;
begin
  Result := False;
  aFileName := '';

  try
    if (length(FCustomFlashPath) > 0) then
    begin
      TempPath := IncludeTrailingPathDelimiter(FCustomFlashPath);

      if (FindFirst(TempPath + '*.dll', faAnyFile, TempSearchRec) = 0) then
      begin
        repeat
          if (TempSearchRec.Attr <> faDirectory) and
            GetStringFileInfo(TempPath + TempSearchRec.Name,
            'ProductName', TempProductName) and
            (CompareText(TempProductName, 'Shockwave Flash') = 0) then
          begin
            aFileName := TempPath + TempSearchRec.Name;
            Result := True;
          end;
        until Result or (FindNext(TempSearchRec) <> 0);

        FindClose(TempSearchRec);
      end;
    end;
  except
    on e: Exception do
      if CustomExceptionHandler('TCefApplication.FindFlashDLL', e) then raise;
  end;
end;

procedure TCefApplication.ShowErrorMessageDlg(const aError: string);
begin
  OutputDebugMessage(aError);

  if FShowMessageDlg then
  begin
    {$IFDEF MSWINDOWS}
    MessageBox(0, PChar(aError + #0), PChar('Error' + #0), MB_ICONERROR or
      MB_OK or MB_TOPMOST);
    {$ENDIF}
  end;
end;

function TCefApplication.ParseProcessType: TCefProcessType;
const
  TYPE_PARAMETER_NAME = '--type=';
var
  i, TempLen: integer;
  TempName, TempValue: string;
begin
  Result := ptBrowser;
  i := pred(paramCount);
  TempLen := length(TYPE_PARAMETER_NAME);

  while (i >= 0) and (Result = ptBrowser) do
  begin
    TempName := copy(ParamStr(i), 1, TempLen);

    if (CompareText(TempName, TYPE_PARAMETER_NAME) = 0) then
    begin
      TempValue := copy(ParamStr(i), succ(TempLen), length(ParamStr(i)));

      if (CompareText(TempValue, 'renderer') = 0) then
        Result := ptRenderer
      else
      if (CompareText(TempValue, 'zygote') = 0) then
        Result := ptZygote
      else
      if (CompareText(TempValue, 'gpu-process') = 0) then
        Result := ptGPU
      else
        Result := ptOther;
    end;

    Dec(i);
  end;
end;

procedure TCefApplication.Internal_OnContextInitialized;
begin
  InitializeCookies;
  FGlobalContextInitialized := True;

  if assigned(FOnContextInitialized) then FOnContextInitialized;
end;

procedure TCefApplication.Internal_OnBeforeChildProcessLaunch(
  const commandLine: ICefCommandLine);
begin
  if assigned(FOnBeforeChildProcessLaunch) then FOnBeforeChildProcessLaunch(commandLine);
end;

procedure TCefApplication.Internal_OnRenderProcessThreadCreated(
  const extraInfo: ICefListValue);
begin
  if assigned(FOnRenderProcessThreadCreated) then
    FOnRenderProcessThreadCreated(extraInfo);
end;

function TCefApplication.Internal_GetLocalizedString(stringid: integer;
  var stringVal: ustring): boolean;
begin
  Result := False;

  if assigned(FOnGetLocalizedString) then
    FOnGetLocalizedString(stringId, stringVal, Result);
end;

function TCefApplication.Internal_GetDataResource(resourceId: integer;
  var Data: Pointer; var dataSize: nativeuint): boolean;
begin
  Result := False;

  if assigned(FOnGetDataResource) then
    FOnGetDataResource(resourceId, Data, dataSize, Result);
end;

function TCefApplication.Internal_GetDataResourceForScale(resourceId: integer;
  scaleFactor: TCefScaleFactor; var Data: Pointer; var dataSize: nativeuint): boolean;
begin
  Result := False;

  if assigned(FOnGetDataResourceForScale) then
    FOnGetDataResourceForScale(resourceId, scaleFactor, Data, dataSize, Result);
end;

procedure TCefApplication.Internal_OnRenderThreadCreated(const extraInfo: ICefListValue);
begin
  if assigned(FOnRenderThreadCreated) then FOnRenderThreadCreated(extraInfo);
end;

procedure TCefApplication.Internal_OnWebKitInitialized;
begin
  if assigned(FOnWebKitInitialized) then FOnWebKitInitialized;
end;

procedure TCefApplication.Internal_OnBrowserCreated(const browser: ICefBrowser);
begin
  if assigned(FOnBrowserCreated) then FOnBrowserCreated(browser);
end;

procedure TCefApplication.Internal_OnBrowserDestroyed(const browser: ICefBrowser);
begin
  if assigned(FOnBrowserDestroyed) then FOnBrowserDestroyed(browser);
end;

procedure TCefApplication.Internal_OnBeforeNavigation(const browser: ICefBrowser;
  const frame: ICefFrame; const request: ICefRequest; navigationType: TCefNavigationType;
  isRedirect: boolean; var aStopNavigation: boolean);
begin
  if assigned(FOnBeforeNavigation) then
    FOnBeforeNavigation(browser, frame, request, navigationType, isRedirect,
      aStopNavigation);
end;

procedure TCefApplication.Internal_OnContextCreated(const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);
begin
  if assigned(FOnContextCreated) then FOnContextCreated(browser, frame, context);
end;

procedure TCefApplication.Internal_OnContextReleased(const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context);
begin
  if assigned(FOnContextReleased) then FOnContextReleased(browser, frame, context);
end;

procedure TCefApplication.Internal_OnUncaughtException(const browser: ICefBrowser;
  const frame: ICefFrame; const context: ICefv8Context;
  const Exception: ICefV8Exception; const stackTrace: ICefV8StackTrace);
begin
  if assigned(FOnUncaughtException) then
    FOnUncaughtException(browser, frame, context, Exception, stackTrace);
end;

procedure TCefApplication.Internal_OnFocusedNodeChanged(const browser: ICefBrowser;
  const frame: ICefFrame; const node: ICefDomNode);
begin
  if assigned(FOnFocusedNodeChanged) then FOnFocusedNodeChanged(browser, frame, node);
end;

procedure TCefApplication.Internal_OnProcessMessageReceived(
  const browser: ICefBrowser; sourceProcess: TCefProcessId;
  const aMessage: ICefProcessMessage; var aHandled: boolean);
begin
  if assigned(FOnProcessMessageReceived) then
    FOnProcessMessageReceived(browser, sourceProcess, aMessage, aHandled)
  else
    aHandled := False;
end;

procedure TCefApplication.Internal_OnLoadingStateChange(const browser: ICefBrowser;
  isLoading, canGoBack, canGoForward: boolean);
begin
  if assigned(FOnLoadingStateChange) then
    FOnLoadingStateChange(browser, isLoading, canGoBack, canGoForward);
end;

procedure TCefApplication.Internal_OnLoadStart(const browser: ICefBrowser;
  const frame: ICefFrame);
begin
  if assigned(FOnLoadStart) then FOnLoadStart(browser, frame);
end;

procedure TCefApplication.Internal_OnLoadEnd(const browser: ICefBrowser;
  const frame: ICefFrame; httpStatusCode: integer);
begin
  if assigned(FOnLoadEnd) then FOnLoadEnd(browser, frame, httpStatusCode);
end;

procedure TCefApplication.Internal_OnLoadError(const browser: ICefBrowser;
  const frame: ICefFrame; errorCode: integer; const errorText, failedUrl: ustring);
begin
  if assigned(FOnLoadError) then
    FOnLoadError(browser, frame, errorCode, errorText, failedUrl);
end;

procedure TCefApplication.Internal_OnBeforeCommandLineProcessing(
  const processType: ustring;
  const commandLine:
  ICefCommandLine);
var
  i: integer;
  TempVersionInfo: TFileVersionInfo;
  TempFileName: string;
begin
  if (commandLine <> nil) and (FProcessType = ptBrowser) and (processType = '') then
  begin
    if FindFlashDLL(TempFileName) and GetDLLVersion(TempFileName,
      TempVersionInfo) then
    begin
      if FEnableGPU then commandLine.AppendSwitch('--enable-gpu-plugin');

      commandLine.AppendSwitch('--enable-accelerated-plugins');
      commandLine.AppendSwitchWithValue('--ppapi-flash-path', TempFileName);
      commandLine.AppendSwitchWithValue('--ppapi-flash-version',
        FileVersionInfoToString(TempVersionInfo));
    end
    else
    if FFlashEnabled then
    begin
      if FEnableGPU then commandLine.AppendSwitch('--enable-gpu-plugin');

      commandLine.AppendSwitch('--enable-accelerated-plugins');
      commandLine.AppendSwitch('--enable-system-flash');
    end;

    commandLine.AppendSwitchWithValue('--enable-media-stream',
      IntToStr(Ord(FEnableMediaStream)));
    commandLine.AppendSwitchWithValue('--enable-speech-input',
      IntToStr(Ord(FEnableSpeechInput)));

    if not (FEnableGPU) then
    begin
      commandLine.AppendSwitch('--disable-gpu');
      commandLine.AppendSwitch('--disable-gpu-compositing');
    end;

    case FSmoothScrolling of
      STATE_ENABLED: commandLine.AppendSwitch('--enable-smooth-scrolling');
      STATE_DISABLED: commandLine.AppendSwitch('--disable-smooth-scrolling');
    end;

    if FFastUnload then
      commandLine.AppendSwitch('--enable-fast-unload');

    if FDisableSafeBrowsing then
    begin
      commandLine.AppendSwitch('--disable-client-side-phishing-detection');
      commandLine.AppendSwitch('--safebrowsing-disable-auto-update');
      commandLine.AppendSwitch('--safebrowsing-disable-download-protection');
    end;

    if FMuteAudio then
      commandLine.AppendSwitch('--mute-audio');

    if FDisableWebSecurity then
      commandLine.AppendSwitch('--disable-web-security');

    if (FCustomCommandLines <> nil) and
      (FCustomCommandLineValues <> nil) and
      (FCustomCommandLines.Count = FCustomCommandLineValues.Count) then
    begin
      i := 0;

      while (i < FCustomCommandLines.Count) do
      begin
        if (length(FCustomCommandLines[i]) > 0) then
        begin
          if (length(FCustomCommandLineValues[i]) > 0) then
            commandLine.AppendSwitchWithValue(FCustomCommandLines[i],
              FCustomCommandLineValues[i])
          else
            commandLine.AppendSwitch(FCustomCommandLines[i]);
        end;

        Inc(i);
      end;
    end;
  end;
end;

procedure TCefApplication.Internal_OnRegisterCustomSchemes(
  const registrar: ICefSchemeRegistrar);
begin
  if assigned(FOnRegisterCustomSchemes) then FOnRegisterCustomSchemes(registrar);
end;

function TCefApplication.GetMustCreateResourceBundleHandler: boolean;
begin
  Result := FSingleProcess or ((FProcessType in [ptBrowser, ptRenderer]) and
    (FMustCreateResourceBundleHandler or
    assigned(FOnGetLocalizedString) or
    assigned(FOnGetDataResource) or
    assigned(FOnGetDataResourceForScale)));
end;

function TCefApplication.GetMustCreateBrowserProcessHandler: boolean;
begin
  Result := FSingleProcess or ((FProcessType = ptBrowser) and
    (FMustCreateBrowserProcessHandler or
    assigned(FOnContextInitialized) or
    assigned(FOnBeforeChildProcessLaunch) or
    assigned(FOnRenderProcessThreadCreated)));
end;

function TCefApplication.GetMustCreateRenderProcessHandler: boolean;
begin
  Result := FSingleProcess or ((FProcessType = ptRenderer) and
    (FMustCreateRenderProcessHandler or
    MustCreateLoadHandler or
    assigned(FOnRenderThreadCreated) or
    assigned(FOnWebKitInitialized) or
    assigned(FOnBrowserCreated) or
    assigned(FOnBrowserDestroyed) or
    assigned(FOnContextCreated) or
    assigned(FOnContextReleased) or
    assigned(FOnUncaughtException) or
    assigned(FOnFocusedNodeChanged) or
    assigned(FOnProcessMessageReceived)));
end;

function TCefApplication.GetMustCreateLoadHandler: boolean;
begin
  Result := FSingleProcess or ((FProcessType = ptRenderer) and
    (FMustCreateLoadHandler or
    assigned(FOnLoadingStateChange) or
    assigned(FOnLoadStart) or
    assigned(FOnLoadEnd) or assigned(FOnLoadError)));
end;

function TCefApplication.GetGlobalContextInitialized: boolean;
begin
  Result := FGlobalContextInitialized or not (MustCreateBrowserProcessHandler);
end;

function TCefApplication.GetChildProcessesCount: integer;
  {$IFDEF MSWINDOWS}
var
  TempHandle: THandle;
  TempProcess: TProcessEntry32;
  TempPID: DWORD;
  TempMain, TempSubProc, TempName: string;
  {$ENDIF}
begin
  Result := 0;

  {$IFDEF MSWINDOWS}
  TempHandle := CreateToolHelp32SnapShot(TH32CS_SNAPPROCESS, 0);
  if (TempHandle = INVALID_HANDLE_VALUE) then exit;

  TempProcess.dwSize := Sizeof(TProcessEntry32);
  TempPID := GetCurrentProcessID;
  TempMain := ExtractFileName(ParamStr(0));
  TempSubProc := ExtractFileName(FBrowserSubprocessPath);

  Process32First(TempHandle, TempProcess);

  repeat
    if (TempProcess.th32ProcessID <> TempPID) and
      (TempProcess.th32ParentProcessID = TempPID) then
    begin
      TempName := TempProcess.szExeFile;
      TempName := ExtractFileName(TempName);

      if (CompareText(TempName, TempMain) = 0) or
        ((length(TempSubProc) > 0) and (CompareText(TempName, TempSubProc) = 0)) then
        Inc(Result);
    end;
  until not (Process32Next(TempHandle, TempProcess));

  CloseHandle(TempHandle);
  {$ENDIF}
end;

function TCefApplication.GetUsedMemory: cardinal;
  {$IFDEF MSWINDOWS}
var
  TempHandle: THandle;
  TempProcess: TProcessEntry32;
  TempPID: DWORD;
  TempProcHWND: HWND;
  TempMemCtrs: TProcessMemoryCounters;
  TempMain, TempSubProc, TempName: string;
  {$ENDIF}
begin
  Result := 0;

  {$IFDEF MSWINDOWS}
  TempHandle := CreateToolHelp32SnapShot(TH32CS_SNAPPROCESS, 0);
  if (TempHandle = INVALID_HANDLE_VALUE) then exit;

  ZeroMemory(@TempProcess, SizeOf(TProcessEntry32));
  TempProcess.dwSize := Sizeof(TProcessEntry32);
  TempPID := GetCurrentProcessID;
  TempMain := ExtractFileName(ParamStr(0));
  TempSubProc := ExtractFileName(FBrowserSubprocessPath);

  Process32First(TempHandle, TempProcess);

  repeat
    if (TempProcess.th32ProcessID = TempPID) or
      (TempProcess.th32ParentProcessID = TempPID) then
    begin
      TempName := TempProcess.szExeFile;
      TempName := ExtractFileName(TempName);

      if (CompareText(TempName, TempMain) = 0) or
        ((length(TempSubProc) > 0) and (CompareText(TempName, TempSubProc) = 0)) then
      begin
        TempProcHWND := OpenProcess(PROCESS_QUERY_INFORMATION or
          PROCESS_VM_READ, False, TempProcess.th32ProcessID);

        if (TempProcHWND <> 0) then
        begin
          ZeroMemory(@TempMemCtrs, SizeOf(TProcessMemoryCounters));
          TempMemCtrs.cb := SizeOf(TProcessMemoryCounters);

          if GetProcessMemoryInfo(TempProcHWND, {$IFNDEF FPC}@{$ENDIF}TempMemCtrs, TempMemCtrs.cb) then
            Inc(Result, TempMemCtrs.WorkingSetSize);

          CloseHandle(TempProcHWND);
        end;
      end;
    end;
  until not (Process32Next(TempHandle, TempProcess));

  CloseHandle(TempHandle);
  {$ENDIF}
end;

function TCefApplication.GetTotalSystemMemory: uint64;
  {$IFDEF MSWINDOWS}
var
  TempMemStatus: TMyMemoryStatusEx;
  {$ENDIF}
begin
  Result := 0;

  {$IFDEF MSWINDOWS}
  ZeroMemory(@TempMemStatus, SizeOf(TMyMemoryStatusEx));
  TempMemStatus.dwLength := SizeOf(TMyMemoryStatusEx);
  if GetGlobalMemoryStatusEx(TempMemStatus) then Result := TempMemStatus.ullTotalPhys;
  {$ENDIF}
end;

function TCefApplication.GetAvailableSystemMemory: uint64;
  {$IFDEF MSWINDOWS}
var
  TempMemStatus: TMyMemoryStatusEx;
  {$ENDIF}
begin
  Result := 0;

  {$IFDEF MSWINDOWS}
  ZeroMemory(@TempMemStatus, SizeOf(TMyMemoryStatusEx));
  TempMemStatus.dwLength := SizeOf(TMyMemoryStatusEx);
  if GetGlobalMemoryStatusEx(TempMemStatus) then Result := TempMemStatus.ullAvailPhys;
  {$ENDIF}
end;

function TCefApplication.GetSystemMemoryLoad: cardinal;
  {$IFDEF MSWINDOWS}
var
  TempMemStatus: TMyMemoryStatusEx;
  {$ENDIF}
begin
  Result := 0;

  {$IFDEF MSWINDOWS}
  ZeroMemory(@TempMemStatus, SizeOf(TMyMemoryStatusEx));
  TempMemStatus.dwLength := SizeOf(TMyMemoryStatusEx);
  if GetGlobalMemoryStatusEx(TempMemStatus) then Result := TempMemStatus.dwMemoryLoad;
  {$ENDIF}
end;

function TCefApplication.LoadCEFlibrary: boolean;
var
  TempOldDir, TempString: string;
begin
  Result := False;

  if (FStatus <> asLoading) or FLibLoaded or (FLibHandle <> 0) then
  begin
    FStatus := asErrorLoadingLibrary;
    TempString := 'GlobalCEFApp can only be initialized once per process.';

    ShowErrorMessageDlg(TempString);
    exit;
  end;

  if FSetCurrentDir then
  begin
    TempOldDir := GetCurrentDir;
    chdir(GetModulePath);
  end;

  FLibHandle := LoadLibraryEx(PChar(LibCefPath), 0, LOAD_WITH_ALTERED_SEARCH_PATH);

  if (FLibHandle = 0) then
  begin
    FStatus := asErrorLoadingLibrary;
    TempString := 'Error loading libcef.dll' + CRLF + CRLF +
      'Error code : 0x' + inttohex(GetLastError, 8);

    ShowErrorMessageDlg(TempString);
    exit;
  end;


  if Load_cef_app_capi_h and Load_cef_browser_capi_h and
    Load_cef_command_line_capi_h and Load_cef_cookie_capi_h and
    Load_cef_drag_data_capi_h and Load_cef_geolocation_capi_h and
    Load_cef_origin_whitelist_capi_h and Load_cef_parser_capi_h and
    Load_cef_path_util_capi_h and Load_cef_print_settings_capi_h and
    Load_cef_process_message_capi_h and Load_cef_process_util_capi_h and
    Load_cef_request_capi_h and Load_cef_request_context_capi_h and
    Load_cef_resource_bundle_capi_h and Load_cef_response_capi_h and
    Load_cef_scheme_capi_h and Load_cef_stream_capi_h and
    Load_cef_task_capi_h and Load_cef_trace_capi_h and
    Load_cef_urlrequest_capi_h and Load_cef_v8_capi_h and
    Load_cef_values_capi_h and Load_cef_web_plugin_capi_h and
    Load_cef_xml_reader_capi_h and Load_cef_zip_reader_capi_h and
    Load_cef_logging_internal_h and Load_cef_string_list_h and
    Load_cef_string_map_h and Load_cef_string_multimap_h and
    Load_cef_string_types_h and Load_cef_thread_internal_h and
    Load_cef_trace_event_internal_h then
  begin
    FStatus := asLoaded;
    FLibLoaded := True;
    Result := True;

    if FLogProcessInfo then
      CefDebugLog('Process started', CEF_LOG_SEVERITY_INFO);
    if FEnableHighDPISupport then cef_enable_highdpi_support;
  end
  else
  begin
    FStatus := asErrorDLLVersion;
    TempString := 'Unsupported CEF version !' + CRLF +
      CRLF +
      'Use only the CEF3 binaries specified in the CEF4Delphi Readme.md file at ' +
      CRLF + CEF4DELPHI_URL;

    ShowErrorMessageDlg(TempString);
  end;

  if FSetCurrentDir then chdir(TempOldDir);
end;

function TCefApplication.Load_cef_app_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_initialize{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_initialize');
  {$IFDEF FPC}Pointer({$ENDIF}cef_shutdown{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_shutdown');
  {$IFDEF FPC}Pointer({$ENDIF}cef_execute_process{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_execute_process');
  {$IFDEF FPC}Pointer({$ENDIF}cef_do_message_loop_work{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_do_message_loop_work');
  {$IFDEF FPC}Pointer({$ENDIF}cef_run_message_loop{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_run_message_loop');
  {$IFDEF FPC}Pointer({$ENDIF}cef_quit_message_loop{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_quit_message_loop');
  {$IFDEF FPC}Pointer({$ENDIF}cef_set_osmodal_loop{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_set_osmodal_loop');
  {$IFDEF FPC}Pointer({$ENDIF}cef_enable_highdpi_support{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_enable_highdpi_support');

  Result := assigned(cef_initialize) and assigned(cef_shutdown) and
    assigned(cef_execute_process) and assigned(
    cef_do_message_loop_work) and assigned(cef_run_message_loop) and
    assigned(cef_quit_message_loop) and
    assigned(cef_set_osmodal_loop) and
    assigned(cef_enable_highdpi_support);
end;

function TCefApplication.Load_cef_browser_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_browser_host_create_browser{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_browser_host_create_browser');
  {$IFDEF FPC}Pointer({$ENDIF}cef_browser_host_create_browser_sync{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_browser_host_create_browser_sync');

  Result := assigned(cef_browser_host_create_browser) and assigned(cef_browser_host_create_browser_sync);
end;

function TCefApplication.Load_cef_command_line_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_command_line_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_command_line_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_command_line_get_global{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_command_line_get_global');

  Result := assigned(cef_command_line_create) and assigned(cef_command_line_get_global);
end;

function TCefApplication.Load_cef_cookie_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_cookie_manager_get_global_manager{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_cookie_manager_get_global_manager');
  {$IFDEF FPC}Pointer({$ENDIF}cef_cookie_manager_create_manager{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_cookie_manager_create_manager');

  Result := assigned(cef_cookie_manager_get_global_manager) and assigned(cef_cookie_manager_create_manager);
end;

function TCefApplication.Load_cef_drag_data_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_drag_data_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_drag_data_create');

  Result := assigned(cef_drag_data_create);
end;

function TCefApplication.Load_cef_geolocation_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_geolocation{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_geolocation');

  Result := assigned(cef_get_geolocation);
end;

function TCefApplication.Load_cef_origin_whitelist_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_add_cross_origin_whitelist_entry{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_add_cross_origin_whitelist_entry');
  {$IFDEF FPC}Pointer({$ENDIF}cef_remove_cross_origin_whitelist_entry{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_remove_cross_origin_whitelist_entry');
  {$IFDEF FPC}Pointer({$ENDIF}cef_clear_cross_origin_whitelist{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_clear_cross_origin_whitelist');

  Result := assigned(cef_add_cross_origin_whitelist_entry) and assigned(cef_remove_cross_origin_whitelist_entry) and assigned(cef_clear_cross_origin_whitelist);
end;

function TCefApplication.Load_cef_parser_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_parse_url{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_parse_url');
  {$IFDEF FPC}Pointer({$ENDIF}cef_create_url{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_create_url');
  {$IFDEF FPC}Pointer({$ENDIF}cef_format_url_for_security_display{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_format_url_for_security_display');
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_mime_type{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_mime_type');
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_extensions_for_mime_type{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_extensions_for_mime_type');
  {$IFDEF FPC}Pointer({$ENDIF}cef_base64encode{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_base64encode');
  {$IFDEF FPC}Pointer({$ENDIF}cef_base64decode{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_base64decode');
  {$IFDEF FPC}Pointer({$ENDIF}cef_uriencode{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_uriencode');
  {$IFDEF FPC}Pointer({$ENDIF}cef_uridecode{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_uridecode');
  {$IFDEF FPC}Pointer({$ENDIF}cef_parse_csscolor{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_parse_csscolor');
  {$IFDEF FPC}Pointer({$ENDIF}cef_parse_json{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_parse_json');
  {$IFDEF FPC}Pointer({$ENDIF}cef_parse_jsonand_return_error{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_parse_jsonand_return_error');
  {$IFDEF FPC}Pointer({$ENDIF}cef_write_json{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_write_json');

  Result := assigned(cef_parse_url) and assigned(cef_create_url) and
    assigned(cef_format_url_for_security_display) and
    assigned(cef_get_mime_type) and assigned(
    cef_get_extensions_for_mime_type) and assigned(cef_base64encode) and
    assigned(cef_base64decode) and assigned(cef_uriencode) and
    assigned(cef_uridecode) and assigned(cef_parse_csscolor) and
    assigned(cef_parse_json) and assigned(
    cef_parse_jsonand_return_error) and assigned(cef_write_json);
end;

function TCefApplication.Load_cef_path_util_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_path{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_path');

  Result := assigned(cef_get_path);
end;

function TCefApplication.Load_cef_print_settings_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_print_settings_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_print_settings_create');

  Result := assigned(cef_print_settings_create);
end;

function TCefApplication.Load_cef_process_message_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_process_message_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_process_message_create');

  Result := assigned(cef_process_message_create);
end;

function TCefApplication.Load_cef_process_util_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_launch_process{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_launch_process');

  Result := assigned(cef_launch_process);
end;

function TCefApplication.Load_cef_request_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_request_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_request_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_post_data_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_post_data_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_post_data_element_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_post_data_element_create');

  Result := assigned(cef_request_create) and assigned(
    cef_post_data_create) and assigned(cef_post_data_element_create);
end;

function TCefApplication.Load_cef_request_context_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_request_context_get_global_context{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_request_context_get_global_context');
  {$IFDEF FPC}Pointer({$ENDIF}cef_request_context_create_context{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_request_context_create_context');
  {$IFDEF FPC}Pointer({$ENDIF}create_context_shared{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'create_context_shared');

  Result := assigned(cef_request_context_get_global_context) and
    assigned(cef_request_context_create_context) and
    assigned(create_context_shared);
end;

function TCefApplication.Load_cef_resource_bundle_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_resource_bundle_get_global{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_resource_bundle_get_global');

  Result := assigned(cef_resource_bundle_get_global);
end;

function TCefApplication.Load_cef_response_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_response_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_response_create');

  Result := assigned(cef_response_create);
end;

function TCefApplication.Load_cef_scheme_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_register_scheme_handler_factory{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_register_scheme_handler_factory');
  {$IFDEF FPC}Pointer({$ENDIF}cef_clear_scheme_handler_factories{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_clear_scheme_handler_factories');

  Result := assigned(cef_register_scheme_handler_factory) and
    assigned(cef_clear_scheme_handler_factories);
end;

function TCefApplication.Load_cef_stream_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_stream_reader_create_for_file{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_stream_reader_create_for_file');
  {$IFDEF FPC}Pointer({$ENDIF}cef_stream_reader_create_for_data{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_stream_reader_create_for_data');
  {$IFDEF FPC}Pointer({$ENDIF}cef_stream_reader_create_for_handler{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_stream_reader_create_for_handler');
  {$IFDEF FPC}Pointer({$ENDIF}cef_stream_writer_create_for_file{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_stream_writer_create_for_file');
  {$IFDEF FPC}Pointer({$ENDIF}cef_stream_writer_create_for_handler{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_stream_writer_create_for_handler');

  Result := assigned(cef_stream_reader_create_for_file) and
    assigned(cef_stream_reader_create_for_data) and
    assigned(cef_stream_reader_create_for_handler) and
    assigned(cef_stream_writer_create_for_file) and
    assigned(cef_stream_writer_create_for_handler);
end;

function TCefApplication.Load_cef_task_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_task_runner_get_for_current_thread{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_task_runner_get_for_current_thread');
  {$IFDEF FPC}Pointer({$ENDIF}cef_task_runner_get_for_thread{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_task_runner_get_for_thread');
  {$IFDEF FPC}Pointer({$ENDIF}cef_currently_on{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_currently_on');
  {$IFDEF FPC}Pointer({$ENDIF}cef_post_task{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_post_task');
  {$IFDEF FPC}Pointer({$ENDIF}cef_post_delayed_task{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_post_delayed_task');

  Result := assigned(cef_task_runner_get_for_current_thread) and
    assigned(cef_task_runner_get_for_thread) and
    assigned(cef_currently_on) and assigned(cef_post_task) and
    assigned(cef_post_delayed_task);
end;

function TCefApplication.Load_cef_trace_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_begin_tracing{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_begin_tracing');
  {$IFDEF FPC}Pointer({$ENDIF}cef_end_tracing{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_end_tracing');
  {$IFDEF FPC}Pointer({$ENDIF}cef_now_from_system_trace_time{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_now_from_system_trace_time');

  Result := assigned(cef_begin_tracing) and assigned(cef_end_tracing) and
    assigned(cef_now_from_system_trace_time);
end;

function TCefApplication.Load_cef_urlrequest_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_urlrequest_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_urlrequest_create');

  Result := assigned(cef_urlrequest_create);
end;

function TCefApplication.Load_cef_v8_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8context_get_current_context{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8context_get_current_context');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8context_get_entered_context{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8context_get_entered_context');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8context_in_context{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8context_in_context');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_undefined{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_undefined');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_null{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_null');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_bool{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_bool');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_int{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_int');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_uint{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_uint');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_double{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_double');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_date{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_date');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_string{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_string');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_object{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_object');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_array{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_array');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8value_create_function{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8value_create_function');
  {$IFDEF FPC}Pointer({$ENDIF}cef_v8stack_trace_get_current{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_v8stack_trace_get_current');
  {$IFDEF FPC}Pointer({$ENDIF}cef_register_extension{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_register_extension');

  Result := assigned(cef_v8context_get_current_context) and
    assigned(cef_v8context_get_entered_context) and
    assigned(cef_v8context_in_context) and
    assigned(cef_v8value_create_undefined) and
    assigned(cef_v8value_create_null) and
    assigned(cef_v8value_create_bool) and
    assigned(cef_v8value_create_int) and
    assigned(cef_v8value_create_uint) and
    assigned(cef_v8value_create_double) and
    assigned(cef_v8value_create_date) and
    assigned(cef_v8value_create_string) and
    assigned(cef_v8value_create_object) and
    assigned(cef_v8value_create_array) and
    assigned(cef_v8value_create_function) and
    assigned(cef_v8stack_trace_get_current) and
    assigned(cef_register_extension);
end;

function TCefApplication.Load_cef_values_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_value_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_value_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_binary_value_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_binary_value_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_dictionary_value_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_dictionary_value_create');
  {$IFDEF FPC}Pointer({$ENDIF}cef_list_value_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_list_value_create');

  Result := assigned(cef_value_create) and assigned(
    cef_binary_value_create) and assigned(cef_v8stack_trace_get_current) and
    assigned(cef_list_value_create);
end;

function TCefApplication.Load_cef_web_plugin_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_visit_web_plugin_info{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_visit_web_plugin_info');
  {$IFDEF FPC}Pointer({$ENDIF}cef_refresh_web_plugins{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_refresh_web_plugins');
  {$IFDEF FPC}Pointer({$ENDIF}cef_add_web_plugin_path{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_add_web_plugin_path');
  {$IFDEF FPC}Pointer({$ENDIF}cef_add_web_plugin_directory{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_add_web_plugin_directory');
  {$IFDEF FPC}Pointer({$ENDIF}cef_remove_web_plugin_path{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_remove_web_plugin_path');
  {$IFDEF FPC}Pointer({$ENDIF}cef_unregister_internal_web_plugin{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_unregister_internal_web_plugin');
  {$IFDEF FPC}Pointer({$ENDIF}cef_force_web_plugin_shutdown{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_force_web_plugin_shutdown');
  {$IFDEF FPC}Pointer({$ENDIF}cef_register_web_plugin_crash{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_register_web_plugin_crash');
  {$IFDEF FPC}Pointer({$ENDIF}cef_is_web_plugin_unstable{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_is_web_plugin_unstable');

  Result := assigned(cef_visit_web_plugin_info) and
    assigned(cef_refresh_web_plugins) and
    assigned(cef_add_web_plugin_path) and
    assigned(cef_add_web_plugin_directory) and
    assigned(cef_remove_web_plugin_path) and
    assigned(cef_unregister_internal_web_plugin) and
    assigned(cef_force_web_plugin_shutdown) and
    assigned(cef_register_web_plugin_crash) and
    assigned(cef_is_web_plugin_unstable);
end;

function TCefApplication.Load_cef_xml_reader_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_xml_reader_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_xml_reader_create');

  Result := assigned(cef_xml_reader_create);
end;

function TCefApplication.Load_cef_zip_reader_capi_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_zip_reader_create{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_zip_reader_create');

  Result := assigned(cef_zip_reader_create);
end;

function TCefApplication.Load_cef_logging_internal_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_min_log_level{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_min_log_level');
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_vlog_level{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_vlog_level');
  {$IFDEF FPC}Pointer({$ENDIF}cef_log{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_log');

  Result := assigned(cef_get_min_log_level) and
    assigned(cef_get_vlog_level) and assigned(cef_log);
end;

function TCefApplication.Load_cef_string_list_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_size{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_size');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_value{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_value');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_append{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_append');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_free');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_list_copy{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_list_copy');

  Result := assigned(cef_string_list_alloc) and
    assigned(cef_string_list_size) and
    assigned(cef_string_list_value) and
    assigned(cef_string_list_append) and
    assigned(cef_string_list_clear) and
    assigned(cef_string_list_free) and assigned(cef_string_list_copy);
end;

function TCefApplication.Load_cef_string_map_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_size{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_size');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_find{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_find');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_key{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_key');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_value{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_value');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_append{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_append');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_map_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_map_free');

  Result := assigned(cef_string_map_alloc) and
    assigned(cef_string_map_size) and assigned(
    cef_string_map_find) and assigned(cef_string_map_key) and
    assigned(cef_string_map_value) and
    assigned(cef_string_map_append) and
    assigned(cef_string_map_clear) and assigned(cef_string_map_free);
end;

function TCefApplication.Load_cef_string_multimap_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_size{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_size');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_find_count{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_find_count');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_enumerate{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_enumerate');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_key{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_key');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_value{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_value');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_append{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_append');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_multimap_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_multimap_free');

  Result := assigned(cef_string_multimap_alloc) and
    assigned(cef_string_multimap_size) and
    assigned(cef_string_multimap_find_count) and
    assigned(cef_string_multimap_enumerate) and
    assigned(cef_string_multimap_key) and
    assigned(cef_string_multimap_value) and
    assigned(cef_string_multimap_append) and
    assigned(cef_string_multimap_clear) and
    assigned(cef_string_multimap_free);
end;

function TCefApplication.Load_cef_string_types_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_wide_set{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_wide_set');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf8_set{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf8_set');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf16_set{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf16_set');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_wide_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_wide_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf8_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf8_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf16_clear{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf16_clear');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_wide_cmp{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_wide_cmp');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf8_cmp{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf8_cmp');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf16_cmp{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf16_cmp');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_wide_to_utf8{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_wide_to_utf8');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf8_to_wide{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf8_to_wide');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_wide_to_utf16{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_wide_to_utf16');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf16_to_wide{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf16_to_wide');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf8_to_utf16{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf8_to_utf16');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_utf16_to_utf8{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_utf16_to_utf8');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_ascii_to_wide{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_ascii_to_wide');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_ascii_to_utf16{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_ascii_to_utf16');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_wide_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_wide_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_utf8_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_utf8_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_utf16_alloc{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_utf16_alloc');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_wide_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_wide_free');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_utf8_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_utf8_free');
  {$IFDEF FPC}Pointer({$ENDIF}cef_string_userfree_utf16_free{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_string_userfree_utf16_free');

  Result := assigned(cef_string_wide_set) and assigned(
    cef_string_utf8_set) and assigned(cef_string_utf16_set) and
    assigned(cef_string_wide_clear) and
    assigned(cef_string_utf8_clear) and
    assigned(cef_string_utf16_clear) and
    assigned(cef_string_wide_cmp) and assigned(
    cef_string_utf8_cmp) and assigned(cef_string_utf16_cmp) and
    assigned(cef_string_wide_to_utf8) and
    assigned(cef_string_utf8_to_wide) and
    assigned(cef_string_wide_to_utf16) and
    assigned(cef_string_utf16_to_wide) and
    assigned(cef_string_utf8_to_utf16) and
    assigned(cef_string_utf16_to_utf8) and
    assigned(cef_string_ascii_to_wide) and
    assigned(cef_string_ascii_to_utf16) and
    assigned(cef_string_userfree_wide_alloc) and
    assigned(cef_string_userfree_utf8_alloc) and
    assigned(cef_string_userfree_utf16_alloc) and
    assigned(cef_string_userfree_wide_free) and
    assigned(cef_string_userfree_utf8_free) and
    assigned(cef_string_userfree_utf16_free);
end;

function TCefApplication.Load_cef_thread_internal_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_current_platform_thread_id{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_current_platform_thread_id');
  {$IFDEF FPC}Pointer({$ENDIF}cef_get_current_platform_thread_handle{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_get_current_platform_thread_handle');

  Result := assigned(cef_get_current_platform_thread_id) and
    assigned(cef_get_current_platform_thread_handle);
end;

function TCefApplication.Load_cef_trace_event_internal_h: boolean;
begin
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_instant{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_instant');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_begin{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_begin');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_end{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_end');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_counter{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_counter');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_counter_id{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_counter_id');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_async_begin{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_async_begin');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_async_step_into{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_async_step_into');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_async_step_past{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_async_step_past');
  {$IFDEF FPC}Pointer({$ENDIF}cef_trace_event_async_end{$IFDEF FPC}){$ENDIF} := GetProcAddress(FLibHandle, 'cef_trace_event_async_end');

  Result := assigned(cef_trace_event_instant) and
    assigned(cef_trace_event_begin) and
    assigned(cef_trace_event_end) and assigned(cef_trace_counter) and
    assigned(cef_trace_counter_id) and
    assigned(cef_trace_event_async_begin) and
    assigned(cef_trace_event_async_step_into) and
    assigned(cef_trace_event_async_step_past) and
    assigned(cef_trace_event_async_end);
end;


// TCEFDirectoryDeleterThread

constructor TCEFDirectoryDeleterThread.Create(const aDirectory: string);
begin
  inherited Create(True);

  FDirectory := aDirectory;
  FreeOnTerminate := True;
end;

procedure TCEFDirectoryDeleterThread.Execute;
begin

  try
    {$IFDEF DELPHI14_UP}
    TDirectory.Delete(FDirectory, True);
    {$ELSE}
    if DeleteDirContents(FDirectory) then RemoveDir(FDirectory);
    {$ENDIF}
  except
    on e: Exception do
      if CustomExceptionHandler('TCEFDirectoryDeleterThread.Execute', e) then raise;
  end;
end;

end.
