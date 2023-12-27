//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFApplication_QueueAsyncCall(EventId: PtrInt); extdecl;
begin
  Application.QueueAsyncCall(TCEFApplicationClass.ApplicationQueueAsyncCall, EventId);
end;

procedure SetApplicationQueueAsyncCallFunc(APtr: Pointer); extdecl;
begin
  GApplicationQueueAsyncCallPtr := ApplicationQueueAsyncCallPtr(APtr);
end;

procedure AddCustomCommandLine(CommandLine, Value: PChar); extdecl;
begin
  GlobalCEFApp.AddCustomCommandLine(CommandLine, Value);
end;

procedure CEFApplication_Create(out Result: TCefApplication); extdecl;
begin
  GlobalCEFApp := TCefApplication.Create;
  Result := GlobalCEFApp;
end;

procedure CEFApplication_Free(); extdecl;
begin
  GlobalCEFApp.Free;
  GlobalCEFApp := nil;
end;

procedure CEFApplication_Destroy(); extdecl;
begin
  DestroyGlobalCEFApp;
  //halt(0); // exit the subprocess
end;

//start main process
function CEFStartMainProcess(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.StartMainProcess;
end;

//start sub process
function CEFStartSubProcess(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.StartSubProcess;
end;

procedure CEFApplication_DoMessageLoopWork(); extdecl;
begin
  GlobalCEFApp.DoMessageLoopWork;
end;

procedure CEFApplication_RunMessageLoop(); extdecl;
begin
  GlobalCEFApp.RunMessageLoop;
end;

procedure CEFApplication_QuitMessageLoop(); extdecl;
begin
  GlobalCEFApp.QuitMessageLoop;
end;

function CEFAppConfig_NoSandbox(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.NoSandbox;
end;

procedure CEFAppConfig_SetNoSandbox(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.NoSandbox := value;
end;

function CEFAppConfig_BrowserSubprocessPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.BrowserSubprocessPath));
end;

procedure CEFAppConfig_SetBrowserSubprocessPath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.BrowserSubprocessPath := PCharToUStr(value);
end;

function CEFAppConfig_FrameworkDirPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.FrameworkDirPath));
end;

procedure CEFAppConfig_SetFrameworkDirPath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.FrameworkDirPath := PCharToUStr(value);
end;

function CEFAppConfig_MultiThreadedMessageLoop(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MultiThreadedMessageLoop;
end;

procedure CEFAppConfig_SetMultiThreadedMessageLoop(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.MultiThreadedMessageLoop := value;
end;

function CEFAppConfig_WindowlessRenderingEnabled(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.WindowlessRenderingEnabled;
end;

procedure CEFAppConfig_SetWindowlessRenderingEnabled(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.WindowlessRenderingEnabled := value;
end;

function CEFAppConfig_CommandLineArgsDisabled(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.CommandLineArgsDisabled;
end;

procedure CEFAppConfig_SetCommandLineArgsDisabled(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.CommandLineArgsDisabled := value;
end;

function CEFAppConfig_Cache(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.Cache));
end;

procedure CEFAppConfig_SetCache(value: PChar) ; extdecl;
begin
  GlobalCEFApp.Cache := PCharToUStr(value);
end;

function CEFAppConfig_UserDataPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.UserDataPath));
end;

procedure CEFAppConfig_SetUserDataPath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.UserDataPath := PCharToUStr(value);
end;

function CEFAppConfig_PersistSessionCookies(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.PersistSessionCookies;
end;

procedure CEFAppConfig_SetPersistSessionCookies(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.PersistSessionCookies := value;
end;

function CEFAppConfig_PersistUserPreferences(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.PersistUserPreferences;
end;

procedure CEFAppConfig_SetPersistUserPreferences(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.PersistUserPreferences := value;
end;

function CEFAppConfig_UserAgent(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.UserAgent));
end;

procedure CEFAppConfig_SetUserAgent(value: PChar) ; extdecl;
begin
  GlobalCEFApp.UserAgent := PCharToUStr(value);
end;

function CEFAppConfig_Locale(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.Locale));
end;

procedure CEFAppConfig_SetLocale(value: PChar) ; extdecl;
begin
  GlobalCEFApp.Locale := PCharToUStr(value);
end;

function CEFAppConfig_LogFile(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LogFile));
end;

procedure CEFAppConfig_SetLogFile(value: PChar) ; extdecl;
begin
  GlobalCEFApp.LogFile := PCharToUStr(value);
end;

function CEFAppConfig_LogSeverity(): TCefLogSeverity; extdecl;
begin
  Result := GlobalCEFApp.LogSeverity;
end;

procedure CEFAppConfig_SetLogSeverity(value: TCefLogSeverity) ; extdecl;
begin
  GlobalCEFApp.LogSeverity := value;
end;

function CEFAppConfig_JavaScriptFlags(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.JavaScriptFlags));
end;

procedure CEFAppConfig_SetJavaScriptFlags(value: PChar) ; extdecl;
begin
  GlobalCEFApp.JavaScriptFlags := PCharToUStr(value);
end;

function CEFAppConfig_ResourcesDirPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ResourcesDirPath));
end;

procedure CEFAppConfig_SetResourcesDirPath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.ResourcesDirPath := PCharToUStr(value);
end;

function CEFAppConfig_LocalesDirPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LocalesDirPath));
end;

procedure CEFAppConfig_SetLocalesDirPath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.LocalesDirPath := PCharToUStr(value);
end;

function CEFAppConfig_PackLoadingDisabled(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.PackLoadingDisabled;
end;

procedure CEFAppConfig_SetPackLoadingDisabled(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.PackLoadingDisabled := value;
end;

function CEFAppConfig_RemoteDebuggingPort(): Integer; extdecl;
begin
  Result := GlobalCEFApp.RemoteDebuggingPort;
end;

procedure CEFAppConfig_SetRemoteDebuggingPort(value: Integer) ; extdecl;
begin
  GlobalCEFApp.RemoteDebuggingPort := value;
end;

function CEFAppConfig_UncaughtExceptionStackSize(): Integer; extdecl;
begin
  Result := GlobalCEFApp.UncaughtExceptionStackSize;
end;

procedure CEFAppConfig_SetUncaughtExceptionStackSize(value: Integer) ; extdecl;
begin
  GlobalCEFApp.UncaughtExceptionStackSize := value;
end;

function CEFAppConfig_IgnoreCertificateErrors(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.IgnoreCertificateErrors;
end;

procedure CEFAppConfig_SetIgnoreCertificateErrors(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.IgnoreCertificateErrors := value;
end;

function CEFAppConfig_BackgroundColor(): TCefColor; extdecl;
begin
  Result := GlobalCEFApp.BackgroundColor;
end;

procedure CEFAppConfig_SetBackgroundColor(value: TCefColor) ; extdecl;
begin
  GlobalCEFApp.BackgroundColor := value;
end;

function CEFAppConfig_AcceptLanguageList(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.AcceptLanguageList));
end;

procedure CEFAppConfig_SetAcceptLanguageList(value: PChar) ; extdecl;
begin
  GlobalCEFApp.AcceptLanguageList := PCharToUStr(value);
end;

function CEFAppConfig_SingleProcess(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.SingleProcess;
end;

procedure CEFAppConfig_SetSingleProcess(value: LongBool); extdecl;
begin
  GlobalCEFApp.SingleProcess := value;
end;

function CEFAppConfig_EnableMediaStream(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableMediaStream;
end;

procedure CEFAppConfig_SetEnableMediaStream(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableMediaStream := value;
end;

function CEFAppConfig_EnableSpeechInput(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableSpeechInput;
end;

procedure CEFAppConfig_SetEnableSpeechInput(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableSpeechInput := value;
end;

function CEFAppConfig_EnableGPU(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableGPU;
end;

procedure CEFAppConfig_SetEnableGPU(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableGPU := value;
end;

function CEFAppConfig_SmoothScrolling(): TCefState; extdecl;
begin
  Result := GlobalCEFApp.SmoothScrolling;
end;

procedure CEFAppConfig_SetSmoothScrolling(value: TCefState); extdecl;
begin
  GlobalCEFApp.SmoothScrolling := value;
end;

function CEFAppConfig_FastUnload(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.FastUnload;
end;

procedure CEFAppConfig_SetFastUnload(value: LongBool); extdecl;
begin
  GlobalCEFApp.FastUnload := value;
end;

function CEFAppConfig_DisableSafeBrowsing(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableSafeBrowsing;
end;

procedure CEFAppConfig_SetDisableSafeBrowsing(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableSafeBrowsing := value;
end;

function CEFAppConfig_MuteAudio(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MuteAudio;
end;

procedure CEFAppConfig_SetMuteAudio(value: LongBool); extdecl;
begin
  GlobalCEFApp.MuteAudio := value;
end;

function CEFAppConfig_DisableWebSecurity(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableWebSecurity;
end;

procedure CEFAppConfig_SetDisableWebSecurity(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableWebSecurity := value;
end;

function CEFAppConfig_EnableHighDPISupport(): LongBool; extdecl;
begin
  Result := False;
  {$IFDEF MSWINDOWS}
  Result := GlobalCEFApp.EnableHighDPISupport;
  {$ENDIF}
end;

procedure CEFAppConfig_SetEnableHighDPISupport(value: LongBool); extdecl;
begin
  {$IFDEF MSWINDOWS}
  GlobalCEFApp.EnableHighDPISupport := value;
  {$ENDIF}
end;

function CEFAppConfig_DeleteCache(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DeleteCache;
end;

procedure CEFAppConfig_SetDeleteCache(value: LongBool); extdecl;
begin
  GlobalCEFApp.DeleteCache := value;
end;

function CEFAppConfig_DeleteCookies(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DeleteCookies;
end;

procedure CEFAppConfig_SetDeleteCookies(value: LongBool); extdecl;
begin
  GlobalCEFApp.DeleteCookies := value;
end;

function CEFAppConfig_CheckCEFFiles(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.CheckCEFFiles;
end;

procedure CEFAppConfig_SetCheckCEFFiles(value: LongBool); extdecl;
begin
  GlobalCEFApp.CheckCEFFiles := value;
end;

function CEFAppConfig_ShowMessageDlg(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.ShowMessageDlg;
end;

procedure CEFAppConfig_SetShowMessageDlg(value: LongBool); extdecl;
begin
  GlobalCEFApp.ShowMessageDlg := value;
end;

function CEFAppConfig_SetCurrentDir(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.SetCurrentDir;
end;

procedure CEFAppConfig_SetSetCurrentDir(value: LongBool); extdecl;
begin
  GlobalCEFApp.SetCurrentDir := value;
end;

function CEFAppConfig_GlobalContextInitialized(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.GlobalContextInitialized;
end;

function CEFAppConfig_LibCefVersion(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LibCefVersion));
end;

function CEFAppConfig_LibCefPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LibCefPath));
end;

function CEFAppConfig_LibLoaded(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.LibLoaded;
end;

function CEFAppConfig_LogProcessInfo(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.LogProcessInfo;
end;

procedure CEFAppConfig_SetLogProcessInfo(value: LongBool); extdecl;
begin
  GlobalCEFApp.LogProcessInfo := value;
end;

function CEFAppConfig_ReRaiseExceptions(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.ReRaiseExceptions;
end;

procedure CEFAppConfig_SetReRaiseExceptions(value: LongBool); extdecl;
begin
  GlobalCEFApp.ReRaiseExceptions := value;
end;

procedure CEFAppConfig_DeviceScaleFactor(out Result: single); extdecl;
begin
  Result := GlobalCEFApp.DeviceScaleFactor;
end;

function CEFAppConfig_LocalesRequired(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LocalesRequired));
end;

procedure CEFAppConfig_SetLocalesRequired(value: PChar); extdecl;
begin
  GlobalCEFApp.LocalesRequired := PCharToUStr(value);
end;

function CEFAppConfig_ProcessType(): integer; extdecl;
begin
  // type = TCefProcessType = ptBrowser, ptRenderer, ptZygote, ptGPU, ptUtility, ptBroker, ptCrashpad, ptOther
  if GlobalCEFApp.ProcessType = TCefProcessType.ptBrowser then
    Result := 0
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptRenderer then
    Result := 1
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptZygote then
    Result := 2
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptGPU then
    Result := 3
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptOther then
    Result := 7
  else
    Result := 0;
end;

function CEFAppConfig_MustCreateResourceBundleHandler(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MustCreateResourceBundleHandler;
end;

procedure CEFAppConfig_SetMustCreateResourceBundleHandler(value: LongBool); extdecl;
begin
  GlobalCEFApp.MustCreateResourceBundleHandler := value;
end;

function CEFAppConfig_MustCreateBrowserProcessHandler(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MustCreateBrowserProcessHandler;
end;

procedure CEFAppConfig_SetMustCreateBrowserProcessHandler(value: LongBool); extdecl;
begin
  GlobalCEFApp.MustCreateBrowserProcessHandler := value;
end;

function CEFAppConfig_MustCreateRenderProcessHandler(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MustCreateRenderProcessHandler;
end;

procedure CEFAppConfig_SetMustCreateRenderProcessHandler(value: LongBool); extdecl;
begin
  GlobalCEFApp.MustCreateRenderProcessHandler := value;
end;

function CEFAppConfig_MustCreateLoadHandler(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MustCreateLoadHandler;
end;

procedure CEFAppConfig_SetMustCreateLoadHandler(value: LongBool); extdecl;
begin
  GlobalCEFApp.MustCreateLoadHandler := value;
end;

function CEFAppConfig_Status(): Integer; extdecl;
begin
  // type = TCefAplicationStatus = asLoading asLoaded asInitialized asShuttingDown asUnloaded asErrorMissingFiles asErrorDLLVersion asErrorLoadingLibrary asErrorInitializingLibrary asErrorExecutingProcess
  if GlobalCEFApp.Status = TCefAplicationStatus.asLoading then
  Result := 0
  else if GlobalCEFApp.Status = TCefAplicationStatus.asLoaded then
  Result := 1
  else if GlobalCEFApp.Status = TCefAplicationStatus.asInitialized then
  Result := 2
  else if GlobalCEFApp.Status = TCefAplicationStatus.asShuttingDown then
  Result := 3
  else if GlobalCEFApp.Status = TCefAplicationStatus.asUnloaded then
  Result := 4
  else if GlobalCEFApp.Status = TCefAplicationStatus.asErrorMissingFiles then
  Result := 5
  else if GlobalCEFApp.Status = TCefAplicationStatus.asErrorDLLVersion then
  Result := 6
  else if GlobalCEFApp.Status = TCefAplicationStatus.asErrorLoadingLibrary then
  Result := 7
  else if GlobalCEFApp.Status = TCefAplicationStatus.asErrorInitializingLibrary then
  Result := 8
  else if GlobalCEFApp.Status = TCefAplicationStatus.asErrorExecutingProcess then
  Result := 9
  else
  Result := 0;
end;

function CEFAppConfig_MissingLibFiles(): PChar; extdecl;
begin
  Result := PChar(GlobalCEFApp.MissingLibFiles);
end;

function CEFAppConfig_MustFreeLibrary(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MustFreeLibrary;
end;

procedure CEFAppConfig_SetMustFreeLibrary(value: LongBool); extdecl;
begin
  GlobalCEFApp.MustFreeLibrary := value;
end;

function CEFAppConfig_ChildProcessesCount(): integer; extdecl;
begin
  Result := GlobalCEFApp.ChildProcessesCount;
end;

function CEFAppConfig_UsedMemory(): uint64; extdecl;
begin
  Result := GlobalCEFApp.UsedMemory;
end;

function CEFAppConfig_TotalSystemMemory(): uint64; extdecl;
begin
  Result := GlobalCEFApp.TotalSystemMemory;
end;

function CEFAppConfig_AvailableSystemMemory(): uint64; extdecl;
begin
  Result := GlobalCEFApp.AvailableSystemMemory;
end;

function CEFAppConfig_SystemMemoryLoad(): cardinal; extdecl;
begin
  Result := GlobalCEFApp.SystemMemoryLoad;
end;

procedure CEFAppConfig_UpdateDeviceScaleFactor(); extdecl;
begin
  GlobalCEFApp.UpdateDeviceScaleFactor();
end;


exports
  CEFApplication_QueueAsyncCall,
  SetApplicationQueueAsyncCallFunc,
  AddCustomCommandLine,
  CEFApplication_DoMessageLoopWork,
  CEFApplication_RunMessageLoop,
  CEFApplication_QuitMessageLoop,
  CEFApplication_Create,
  CEFApplication_Free,
  CEFApplication_Destroy,
  CEFStartMainProcess,
  CEFStartSubProcess,
  CEFAppConfig_NoSandbox,
  CEFAppConfig_SetNoSandbox,
  CEFAppConfig_BrowserSubprocessPath,
  CEFAppConfig_SetBrowserSubprocessPath,
  CEFAppConfig_FrameworkDirPath,
  CEFAppConfig_SetFrameworkDirPath,
  CEFAppConfig_MultiThreadedMessageLoop,
  CEFAppConfig_SetMultiThreadedMessageLoop,
  CEFAppConfig_WindowlessRenderingEnabled,
  CEFAppConfig_SetWindowlessRenderingEnabled,
  CEFAppConfig_CommandLineArgsDisabled,
  CEFAppConfig_SetCommandLineArgsDisabled,
  CEFAppConfig_Cache,
  CEFAppConfig_SetCache,
  CEFAppConfig_UserDataPath,
  CEFAppConfig_SetUserDataPath,
  CEFAppConfig_PersistSessionCookies,
  CEFAppConfig_SetPersistSessionCookies,
  CEFAppConfig_PersistUserPreferences,
  CEFAppConfig_SetPersistUserPreferences,
  CEFAppConfig_UserAgent,
  CEFAppConfig_SetUserAgent,
  CEFAppConfig_Locale,
  CEFAppConfig_SetLocale,
  CEFAppConfig_LogFile,
  CEFAppConfig_SetLogFile,
  CEFAppConfig_LogSeverity,
  CEFAppConfig_SetLogSeverity,
  CEFAppConfig_JavaScriptFlags,
  CEFAppConfig_SetJavaScriptFlags,
  CEFAppConfig_ResourcesDirPath,
  CEFAppConfig_SetResourcesDirPath,
  CEFAppConfig_LocalesDirPath,
  CEFAppConfig_SetLocalesDirPath,
  CEFAppConfig_PackLoadingDisabled,
  CEFAppConfig_SetPackLoadingDisabled,
  CEFAppConfig_RemoteDebuggingPort,
  CEFAppConfig_SetRemoteDebuggingPort,
  CEFAppConfig_UncaughtExceptionStackSize,
  CEFAppConfig_SetUncaughtExceptionStackSize,
  CEFAppConfig_IgnoreCertificateErrors,
  CEFAppConfig_SetIgnoreCertificateErrors,
  CEFAppConfig_BackgroundColor,
  CEFAppConfig_SetBackgroundColor,
  CEFAppConfig_AcceptLanguageList,
  CEFAppConfig_SetAcceptLanguageList,
  CEFAppConfig_SingleProcess,
  CEFAppConfig_SetSingleProcess,
  CEFAppConfig_EnableMediaStream,
  CEFAppConfig_SetEnableMediaStream,
  CEFAppConfig_EnableSpeechInput,
  CEFAppConfig_SetEnableSpeechInput,
  CEFAppConfig_EnableGPU,
  CEFAppConfig_SetEnableGPU,
  CEFAppConfig_SmoothScrolling,
  CEFAppConfig_SetSmoothScrolling,
  CEFAppConfig_FastUnload,
  CEFAppConfig_SetFastUnload,
  CEFAppConfig_DisableSafeBrowsing,
  CEFAppConfig_SetDisableSafeBrowsing,
  CEFAppConfig_MuteAudio,
  CEFAppConfig_SetMuteAudio,
  CEFAppConfig_DisableWebSecurity,
  CEFAppConfig_SetDisableWebSecurity,
  CEFAppConfig_EnableHighDPISupport,
  CEFAppConfig_SetEnableHighDPISupport,
  CEFAppConfig_DeleteCache,
  CEFAppConfig_DeleteCookies,
  CEFAppConfig_CheckCEFFiles,
  CEFAppConfig_ShowMessageDlg,
  CEFAppConfig_SetCurrentDir,
  CEFAppConfig_GlobalContextInitialized,
  CEFAppConfig_LibCefVersion,
  CEFAppConfig_LibCefPath,
  CEFAppConfig_LibLoaded,
  CEFAppConfig_LogProcessInfo,
  CEFAppConfig_ReRaiseExceptions,
  CEFAppConfig_DeviceScaleFactor,
  CEFAppConfig_LocalesRequired,
  CEFAppConfig_ProcessType,
  CEFAppConfig_MustCreateResourceBundleHandler,
  CEFAppConfig_MustCreateBrowserProcessHandler,
  CEFAppConfig_MustCreateRenderProcessHandler,
  CEFAppConfig_MustCreateLoadHandler,
  CEFAppConfig_Status,
  CEFAppConfig_MissingLibFiles,
  CEFAppConfig_MustFreeLibrary,
  CEFAppConfig_ChildProcessesCount,
  CEFAppConfig_UsedMemory,
  CEFAppConfig_TotalSystemMemory,
  CEFAppConfig_AvailableSystemMemory,
  CEFAppConfig_SystemMemoryLoad,
  CEFAppConfig_SetDeleteCache,
  CEFAppConfig_SetDeleteCookies,
  CEFAppConfig_SetCheckCEFFiles,
  CEFAppConfig_SetShowMessageDlg,
  CEFAppConfig_SetSetCurrentDir,
  CEFAppConfig_SetLogProcessInfo,
  CEFAppConfig_SetReRaiseExceptions,
  CEFAppConfig_SetLocalesRequired,
  CEFAppConfig_SetMustCreateResourceBundleHandler,
  CEFAppConfig_SetMustCreateBrowserProcessHandler,
  CEFAppConfig_SetMustCreateRenderProcessHandler,
  CEFAppConfig_SetMustCreateLoadHandler,
  CEFAppConfig_SetMustFreeLibrary,
  CEFAppConfig_UpdateDeviceScaleFactor;
