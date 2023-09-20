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

procedure SetMacOSXCommandLine(PCommandLine: PChar); extdecl;
{$ifdef DARWIN}
var
  i: integer;
{$endif}
begin
  {$ifdef DARWIN}
  //argc:longint;
  //argv:PPchar;
  //envp:PPchar;
  MyPArgs := PCommandLine;
  MyArgsStr := strpas(MyPArgs);
  CmdLine := PCommandLine;
  MacOSXCommandLine := string(MyArgsStr).Split('|,|');
  MacOSXCommandCount := length(MacOSXCommandLine);
  SetLength(MyArgv, MacOSXCommandCount);
  for i:=0 to MacOSXCommandCount -1 do
  begin
  myArgv[i] := PChar(MacOSXCommandLine[i]);
  end;
  argc := MacOSXCommandCount;
  argv := PPAnsiChar(@myArgv[0]);
  {$endif}
end;

// AddCrDelegate
procedure CEF_AddCrDelegate(); extdecl;
begin
  {$IFDEF DARWIN}
  AddCrDelegate;
  {$ENDIF}
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
  {$IFDEF MACOSX}
  GlobalCEFApp.InitLibLocationFromArgs;
  {$ENDIF}
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

function CEFAppConfig_MainBundlePath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.MainBundlePath));
end;

procedure CEFAppConfig_SetMainBundlePath(value: PChar) ; extdecl;
begin
  GlobalCEFApp.MainBundlePath := PCharToUStr(value);
end;

function CEFAppConfig_ChromeRuntime(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.ChromeRuntime;
end;

procedure CEFAppConfig_SetChromeRuntime(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.ChromeRuntime := value;
end;

function CEFAppConfig_MultiThreadedMessageLoop(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MultiThreadedMessageLoop;
end;

procedure CEFAppConfig_SetMultiThreadedMessageLoop(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.MultiThreadedMessageLoop := value;
end;

function CEFAppConfig_ExternalMessagePump(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.ExternalMessagePump;
end;

procedure CEFAppConfig_SetExternalMessagePump(value: LongBool) ; extdecl;
begin
  GlobalCEFApp.ExternalMessagePump := value;
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

function CEFAppConfig_RootCache(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.RootCache));
end;

procedure CEFAppConfig_SetRootCache(value: PChar) ; extdecl;
begin
  GlobalCEFApp.RootCache := PCharToUStr(value);
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

function CEFAppConfig_UserAgentProduct(): PChar; extdecl;
begin
  Result := PChar('');
end;

procedure CEFAppConfig_SetUserAgentProduct(value: PChar) ; extdecl;
begin
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

function CEFAppConfig_CookieableSchemesList(): PChar; extdecl;
begin
  Result := PChar('');
end;

procedure CEFAppConfig_SetCookieableSchemesList(value: PChar) ; extdecl;
begin
end;

function CEFAppConfig_CookieableSchemesExcludeDefaults(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetCookieableSchemesExcludeDefaults(value: LongBool) ; extdecl;
begin
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

function CEFAppConfig_UseFakeUIForMediaStream(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.UseFakeUIForMediaStream;
end;

procedure CEFAppConfig_SetUseFakeUIForMediaStream(value: LongBool); extdecl;
begin
  GlobalCEFApp.UseFakeUIForMediaStream := value;
end;

function CEFAppConfig_EnableUsermediaScreenCapturing(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableUsermediaScreenCapturing;
end;

procedure CEFAppConfig_SetEnableUsermediaScreenCapturing(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableUsermediaScreenCapturing := value;
end;

function CEFAppConfig_EnableGPU(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableGPU;
end;

procedure CEFAppConfig_SetEnableGPU(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableGPU := value;
end;

function CEFAppConfig_EnableFeatures(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.EnableFeatures));
end;

procedure CEFAppConfig_SetEnableFeatures(value: PChar); extdecl;
begin
  GlobalCEFApp.EnableFeatures := PCharToUStr(value);
end;

function CEFAppConfig_DisableFeatures(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.DisableFeatures));
end;

procedure CEFAppConfig_SetDisableFeatures(value: PChar); extdecl;
begin
  GlobalCEFApp.DisableFeatures := PCharToUStr(value);
end;

function CEFAppConfig_EnableBlinkFeatures(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.EnableBlinkFeatures));
end;

procedure CEFAppConfig_SetEnableBlinkFeatures(value: PChar); extdecl;
begin
  GlobalCEFApp.EnableBlinkFeatures := PCharToUStr(value);
end;

function CEFAppConfig_DisableBlinkFeatures(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.DisableBlinkFeatures));
end;

procedure CEFAppConfig_SetDisableBlinkFeatures(value: PChar); extdecl;
begin
  GlobalCEFApp.DisableBlinkFeatures := PCharToUStr(value);
end;

function CEFAppConfig_BlinkSettings(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.BlinkSettings));
end;

procedure CEFAppConfig_SetBlinkSettings(value: PChar); extdecl;
begin
  GlobalCEFApp.BlinkSettings := PCharToUStr(value);
end;

function CEFAppConfig_ForceFieldTrials(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ForceFieldTrials));
end;

procedure CEFAppConfig_SetForceFieldTrials(value: PChar); extdecl;
begin
  GlobalCEFApp.ForceFieldTrials := PCharToUStr(value);
end;

function CEFAppConfig_ForceFieldTrialParams(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ForceFieldTrialParams));
end;

procedure CEFAppConfig_SetForceFieldTrialParams(value: PChar); extdecl;
begin
  GlobalCEFApp.ForceFieldTrialParams := PCharToUStr(value);
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

function CEFAppConfig_SitePerProcess(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.SitePerProcess;
end;

procedure CEFAppConfig_SetSitePerProcess(value: LongBool); extdecl;
begin
  GlobalCEFApp.SitePerProcess := value;
end;

function CEFAppConfig_DisableWebSecurity(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableWebSecurity;
end;

procedure CEFAppConfig_SetDisableWebSecurity(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableWebSecurity := value;
end;

function CEFAppConfig_DisablePDFExtension(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisablePDFExtension;
end;

procedure CEFAppConfig_SetDisablePDFExtension(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisablePDFExtension := value;
end;

function CEFAppConfig_DisableSiteIsolationTrials(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableSiteIsolationTrials;
end;

procedure CEFAppConfig_SetDisableSiteIsolationTrials(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableSiteIsolationTrials := value;
end;

function CEFAppConfig_DisableChromeLoginPrompt(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableChromeLoginPrompt;
end;

procedure CEFAppConfig_SetDisableChromeLoginPrompt(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableChromeLoginPrompt := value;
end;

function CEFAppConfig_DisableExtensions(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableExtensions;
end;

procedure CEFAppConfig_SetDisableExtensions(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableExtensions := value;
end;

function CEFAppConfig_AutoplayPolicy(): Integer; extdecl;
begin
  // type = TCefAutoplayPolicy
  if GlobalCEFApp.AutoplayPolicy = TCefAutoplayPolicy.appDefault then
  Result := 0
  else if GlobalCEFApp.AutoplayPolicy = TCefAutoplayPolicy.appDocumentUserActivationRequired then
  Result := 1
  else if GlobalCEFApp.AutoplayPolicy = TCefAutoplayPolicy.appNoUserGestureRequired then
  Result := 2
  else if GlobalCEFApp.AutoplayPolicy = TCefAutoplayPolicy.appUserGestureRequired then
  Result := 3
  else
  Result := -1;
end;

procedure CEFAppConfig_SetAutoplayPolicy(value: Integer); extdecl;
begin
  // type = TCefAutoplayPolicy
  if value = 0 then
  GlobalCEFApp.AutoplayPolicy := TCefAutoplayPolicy.appDefault
  else if value = 1 then
  GlobalCEFApp.AutoplayPolicy := TCefAutoplayPolicy.appDocumentUserActivationRequired
  else if value = 2 then
  GlobalCEFApp.AutoplayPolicy := TCefAutoplayPolicy.appNoUserGestureRequired
  else if value = 3 then
  GlobalCEFApp.AutoplayPolicy := TCefAutoplayPolicy.appUserGestureRequired
end;

function CEFAppConfig_DisableBackgroundNetworking(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableBackgroundNetworking;
end;

procedure CEFAppConfig_SetDisableBackgroundNetworking(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableBackgroundNetworking := value;
end;

function CEFAppConfig_MetricsRecordingOnly(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MetricsRecordingOnly;
end;

procedure CEFAppConfig_SetMetricsRecordingOnly(value: LongBool); extdecl;
begin
  GlobalCEFApp.MetricsRecordingOnly := value;
end;

function CEFAppConfig_AllowFileAccessFromFiles(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.AllowFileAccessFromFiles;
end;

procedure CEFAppConfig_SetAllowFileAccessFromFiles(value: LongBool); extdecl;
begin
  GlobalCEFApp.AllowFileAccessFromFiles := value;
end;

function CEFAppConfig_AllowRunningInsecureContent(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.AllowRunningInsecureContent;
end;

procedure CEFAppConfig_SetAllowRunningInsecureContent(value: LongBool); extdecl;
begin
  GlobalCEFApp.AllowRunningInsecureContent := value;
end;

function CEFAppConfig_EnablePrintPreview(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnablePrintPreview;
end;

procedure CEFAppConfig_SetEnablePrintPreview(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnablePrintPreview := value;
end;

function CEFAppConfig_DefaultEncoding(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.DefaultEncoding));
end;

procedure CEFAppConfig_SetDefaultEncoding(value: PChar); extdecl;
begin
  GlobalCEFApp.DefaultEncoding := value;
end;

function CEFAppConfig_DisableJavascript(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableJavascript;
end;

procedure CEFAppConfig_SetDisableJavascript(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableJavascript := value;
end;

function CEFAppConfig_DisableJavascriptCloseWindows(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableJavascriptCloseWindows;
end;

procedure CEFAppConfig_SetDisableJavascriptCloseWindows(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableJavascriptCloseWindows := value;
end;

function CEFAppConfig_DisableJavascriptAccessClipboard(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableJavascriptAccessClipboard;
end;

procedure CEFAppConfig_SetDisableJavascriptAccessClipboard(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableJavascriptAccessClipboard := value;
end;

function CEFAppConfig_DisableJavascriptDomPaste(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableJavascriptDomPaste;
end;

procedure CEFAppConfig_SetDisableJavascriptDomPaste(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableJavascriptDomPaste := value;
end;

function CEFAppConfig_AllowUniversalAccessFromFileUrls(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.AllowUniversalAccessFromFileUrls;
end;

procedure CEFAppConfig_SetAllowUniversalAccessFromFileUrls(value: LongBool); extdecl;
begin
  GlobalCEFApp.AllowUniversalAccessFromFileUrls := value;
end;

function CEFAppConfig_DisableImageLoading(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableImageLoading;
end;

procedure CEFAppConfig_SetDisableImageLoading(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableImageLoading := value;
end;

function CEFAppConfig_ImageShrinkStandaloneToFit(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.ImageShrinkStandaloneToFit;
end;

procedure CEFAppConfig_SetImageShrinkStandaloneToFit(value: LongBool); extdecl;
begin
  GlobalCEFApp.ImageShrinkStandaloneToFit := value;
end;

function CEFAppConfig_DisableTextAreaResize(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableTextAreaResize;
end;

procedure CEFAppConfig_SetDisableTextAreaResize(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableTextAreaResize := value;
end;

function CEFAppConfig_DisableTabToLinks(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableTabToLinks;
end;

procedure CEFAppConfig_SetDisableTabToLinks(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableTabToLinks := value;
end;

function CEFAppConfig_EnableProfanityFilter(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.EnableProfanityFilter;
end;

procedure CEFAppConfig_SetEnableProfanityFilter(value: LongBool); extdecl;
begin
  GlobalCEFApp.EnableProfanityFilter := value;
end;

function CEFAppConfig_DisableSpellChecking(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableSpellChecking;
end;

procedure CEFAppConfig_SetDisableSpellChecking(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableSpellChecking := value;
end;

function CEFAppConfig_OverrideSpellCheckLang(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.OverrideSpellCheckLang));
end;

procedure CEFAppConfig_SetOverrideSpellCheckLang(value: PChar); extdecl;
begin
  GlobalCEFApp.OverrideSpellCheckLang := PCharToUStr(value);
end;

function CEFAppConfig_TouchEvents(): TCefState; extdecl;
begin
  Result := GlobalCEFApp.TouchEvents;
end;

procedure CEFAppConfig_SetTouchEvents(value: TCefState); extdecl;
begin
  GlobalCEFApp.TouchEvents := value;
end;

function CEFAppConfig_DisableReadingFromCanvas(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableReadingFromCanvas;
end;

procedure CEFAppConfig_SetDisableReadingFromCanvas(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableReadingFromCanvas := value;
end;

function CEFAppConfig_HyperlinkAuditing(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.HyperlinkAuditing;
end;

procedure CEFAppConfig_SetHyperlinkAuditing(value: LongBool); extdecl;
begin
  GlobalCEFApp.HyperlinkAuditing := value;
end;

function CEFAppConfig_DisableNewBrowserInfoTimeout(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableNewBrowserInfoTimeout;
end;

procedure CEFAppConfig_SetDisableNewBrowserInfoTimeout(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableNewBrowserInfoTimeout := value;
end;

function CEFAppConfig_DevToolsProtocolLogFile(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.DevToolsProtocolLogFile));
end;

procedure CEFAppConfig_SetDevToolsProtocolLogFile(value: PChar); extdecl;
begin
  GlobalCEFApp.DevToolsProtocolLogFile := PCharToUStr(value);
end;

procedure CEFAppConfig_ForcedDeviceScaleFactor(out Result: single); extdecl;
begin
  Result := GlobalCEFApp.ForcedDeviceScaleFactor;
end;

procedure CEFAppConfig_SetForcedDeviceScaleFactor(value: PSingle); extdecl;
begin
  GlobalCEFApp.ForcedDeviceScaleFactor := Single(value^);
end;

function CEFAppConfig_DisableZygote(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.DisableZygote;
end;

procedure CEFAppConfig_SetDisableZygote(value: LongBool); extdecl;
begin
  GlobalCEFApp.DisableZygote := value;
end;

function CEFAppConfig_UseMockKeyChain(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.UseMockKeyChain;
end;

procedure CEFAppConfig_SetUseMockKeyChain(value: LongBool); extdecl;
begin
  GlobalCEFApp.UseMockKeyChain := value;
end;

function CEFAppConfig_DisableRequestHandlingForTesting(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetDisableRequestHandlingForTesting(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_DisablePopupBlocking(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetDisablePopupBlocking(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_DisableBackForwardCache(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetDisableBackForwardCache(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_DisableComponentUpdate(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetDisableComponentUpdate(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_AllowInsecureLocalhost(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetAllowInsecureLocalhost(value: LongBool); extdecl;
begin

end;

function CEFAppConfig_KioskPrinting(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetKioskPrinting(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_TreatInsecureOriginAsSecure(): PChar; extdecl;
begin
  Result := PChar('');
end;

procedure CEFAppConfig_SetTreatInsecureOriginAsSecure(value: PChar); extdecl;
begin
end;

function CEFAppConfig_NetLogEnabled(): LongBool; extdecl;
begin
  Result := False;
end;

procedure CEFAppConfig_SetNetLogEnabled(value: LongBool); extdecl;
begin
end;

function CEFAppConfig_NetLogFile(): PChar; extdecl;
begin
  Result := PChar('');
end;

procedure CEFAppConfig_SetNetLogFile(value: PChar); extdecl;
begin
end;

function CEFAppConfig_NetLogCaptureMode(): Integer; extdecl;
begin
  Result := -1;
end;

procedure CEFAppConfig_SetNetLogCaptureMode(value: Integer); extdecl;
begin
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

function CEFAppConfig_MissingBinariesException(): LongBool; extdecl;
begin
  Result := GlobalCEFApp.MissingBinariesException;
end;

procedure CEFAppConfig_SetMissingBinariesException(value: LongBool); extdecl;
begin
  GlobalCEFApp.MissingBinariesException := value;
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

function CEFAppConfig_ChromeMajorVer(): uint16; extdecl;
begin
  Result := GlobalCEFApp.ChromeMajorVer;
end;

function CEFAppConfig_ChromeMinorVer(): uint16; extdecl;
begin
  Result := GlobalCEFApp.ChromeMinorVer;
end;

function CEFAppConfig_ChromeRelease(): uint16; extdecl;
begin
  Result := GlobalCEFApp.ChromeRelease;
end;

function CEFAppConfig_ChromeBuild(): uint16; extdecl;
begin
  Result := GlobalCEFApp.ChromeBuild;
end;

function CEFAppConfig_ChromeVersion(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ChromeVersion));
end;

function CEFAppConfig_LibCefVersion(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LibCefVersion));
end;

function CEFAppConfig_LibCefPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LibCefPath));
end;

function CEFAppConfig_ChromeElfPath(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ChromeElfPath));
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
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptUtility then
    Result := 4
  else if GlobalCEFApp.ProcessType = TCefProcessType.ptBroker then
    Result := 5
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

function CEFAppConfig_ApiHashUniversal(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ApiHashUniversal));
end;

function CEFAppConfig_ApiHashPlatform(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ApiHashPlatform));
end;

function CEFAppConfig_ApiHashCommit(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.ApiHashCommit));
end;

function CEFAppConfig_LastErrorMessage(): PChar; extdecl;
begin
  Result := PChar(string(GlobalCEFApp.LastErrorMessage));
end;


procedure CEFAppConfig_UpdateDeviceScaleFactor(); extdecl;
begin
  GlobalCEFApp.UpdateDeviceScaleFactor();
end;


exports
  CEFApplication_QueueAsyncCall,
  SetApplicationQueueAsyncCallFunc,
  AddCustomCommandLine,
  CEF_AddCrDelegate,
  SetMacOSXCommandLine,
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
  CEFAppConfig_MainBundlePath,
  CEFAppConfig_SetMainBundlePath,
  CEFAppConfig_ChromeRuntime,
  CEFAppConfig_SetChromeRuntime,
  CEFAppConfig_MultiThreadedMessageLoop,
  CEFAppConfig_SetMultiThreadedMessageLoop,
  CEFAppConfig_ExternalMessagePump,
  CEFAppConfig_SetExternalMessagePump,
  CEFAppConfig_WindowlessRenderingEnabled,
  CEFAppConfig_SetWindowlessRenderingEnabled,
  CEFAppConfig_CommandLineArgsDisabled,
  CEFAppConfig_SetCommandLineArgsDisabled,
  CEFAppConfig_Cache,
  CEFAppConfig_SetCache,
  CEFAppConfig_RootCache,
  CEFAppConfig_SetRootCache,
  CEFAppConfig_UserDataPath,
  CEFAppConfig_SetUserDataPath,
  CEFAppConfig_PersistSessionCookies,
  CEFAppConfig_SetPersistSessionCookies,
  CEFAppConfig_PersistUserPreferences,
  CEFAppConfig_SetPersistUserPreferences,
  CEFAppConfig_UserAgent,
  CEFAppConfig_SetUserAgent,
  CEFAppConfig_UserAgentProduct,
  CEFAppConfig_SetUserAgentProduct,
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
  CEFAppConfig_CookieableSchemesList,
  CEFAppConfig_SetCookieableSchemesList,
  CEFAppConfig_CookieableSchemesExcludeDefaults,
  CEFAppConfig_SetCookieableSchemesExcludeDefaults,
  CEFAppConfig_SingleProcess,
  CEFAppConfig_SetSingleProcess,
  CEFAppConfig_EnableMediaStream,
  CEFAppConfig_SetEnableMediaStream,
  CEFAppConfig_EnableSpeechInput,
  CEFAppConfig_SetEnableSpeechInput,
  CEFAppConfig_UseFakeUIForMediaStream,
  CEFAppConfig_SetUseFakeUIForMediaStream,
  CEFAppConfig_EnableUsermediaScreenCapturing,
  CEFAppConfig_SetEnableUsermediaScreenCapturing,
  CEFAppConfig_EnableGPU,
  CEFAppConfig_SetEnableGPU,
  CEFAppConfig_EnableFeatures,
  CEFAppConfig_SetEnableFeatures,
  CEFAppConfig_DisableFeatures,
  CEFAppConfig_SetDisableFeatures,
  CEFAppConfig_EnableBlinkFeatures,
  CEFAppConfig_SetEnableBlinkFeatures,
  CEFAppConfig_DisableBlinkFeatures,
  CEFAppConfig_SetDisableBlinkFeatures,
  CEFAppConfig_BlinkSettings,
  CEFAppConfig_SetBlinkSettings,
  CEFAppConfig_ForceFieldTrials,
  CEFAppConfig_SetForceFieldTrials,
  CEFAppConfig_ForceFieldTrialParams,
  CEFAppConfig_SetForceFieldTrialParams,
  CEFAppConfig_SmoothScrolling,
  CEFAppConfig_SetSmoothScrolling,
  CEFAppConfig_FastUnload,
  CEFAppConfig_SetFastUnload,
  CEFAppConfig_DisableSafeBrowsing,
  CEFAppConfig_SetDisableSafeBrowsing,
  CEFAppConfig_MuteAudio,
  CEFAppConfig_SetMuteAudio,
  CEFAppConfig_SitePerProcess,
  CEFAppConfig_SetSitePerProcess,
  CEFAppConfig_DisableWebSecurity,
  CEFAppConfig_SetDisableWebSecurity,
  CEFAppConfig_DisablePDFExtension,
  CEFAppConfig_SetDisablePDFExtension,
  CEFAppConfig_DisableSiteIsolationTrials,
  CEFAppConfig_SetDisableSiteIsolationTrials,
  CEFAppConfig_DisableChromeLoginPrompt,
  CEFAppConfig_SetDisableChromeLoginPrompt,
  CEFAppConfig_DisableExtensions,
  CEFAppConfig_SetDisableExtensions,
  CEFAppConfig_AutoplayPolicy,
  CEFAppConfig_SetAutoplayPolicy,
  CEFAppConfig_DisableBackgroundNetworking,
  CEFAppConfig_SetDisableBackgroundNetworking,
  CEFAppConfig_MetricsRecordingOnly,
  CEFAppConfig_SetMetricsRecordingOnly,
  CEFAppConfig_AllowFileAccessFromFiles,
  CEFAppConfig_SetAllowFileAccessFromFiles,
  CEFAppConfig_AllowRunningInsecureContent,
  CEFAppConfig_SetAllowRunningInsecureContent,
  CEFAppConfig_EnablePrintPreview,
  CEFAppConfig_SetEnablePrintPreview,
  CEFAppConfig_DefaultEncoding,
  CEFAppConfig_SetDefaultEncoding,
  CEFAppConfig_DisableJavascript,
  CEFAppConfig_SetDisableJavascript,
  CEFAppConfig_DisableJavascriptCloseWindows,
  CEFAppConfig_SetDisableJavascriptCloseWindows,
  CEFAppConfig_DisableJavascriptAccessClipboard,
  CEFAppConfig_SetDisableJavascriptAccessClipboard,
  CEFAppConfig_DisableJavascriptDomPaste,
  CEFAppConfig_SetDisableJavascriptDomPaste,
  CEFAppConfig_AllowUniversalAccessFromFileUrls,
  CEFAppConfig_SetAllowUniversalAccessFromFileUrls,
  CEFAppConfig_DisableImageLoading,
  CEFAppConfig_SetDisableImageLoading,
  CEFAppConfig_ImageShrinkStandaloneToFit,
  CEFAppConfig_SetImageShrinkStandaloneToFit,
  CEFAppConfig_DisableTextAreaResize,
  CEFAppConfig_SetDisableTextAreaResize,
  CEFAppConfig_DisableTabToLinks,
  CEFAppConfig_SetDisableTabToLinks,
  CEFAppConfig_EnableProfanityFilter,
  CEFAppConfig_SetEnableProfanityFilter,
  CEFAppConfig_DisableSpellChecking,
  CEFAppConfig_SetDisableSpellChecking,
  CEFAppConfig_OverrideSpellCheckLang,
  CEFAppConfig_SetOverrideSpellCheckLang,
  CEFAppConfig_TouchEvents,
  CEFAppConfig_SetTouchEvents,
  CEFAppConfig_DisableReadingFromCanvas,
  CEFAppConfig_SetDisableReadingFromCanvas,
  CEFAppConfig_HyperlinkAuditing,
  CEFAppConfig_SetHyperlinkAuditing,
  CEFAppConfig_DisableNewBrowserInfoTimeout,
  CEFAppConfig_SetDisableNewBrowserInfoTimeout,
  CEFAppConfig_DevToolsProtocolLogFile,
  CEFAppConfig_SetDevToolsProtocolLogFile,
  CEFAppConfig_ForcedDeviceScaleFactor,
  CEFAppConfig_SetForcedDeviceScaleFactor,
  CEFAppConfig_DisableZygote,
  CEFAppConfig_SetDisableZygote,
  CEFAppConfig_UseMockKeyChain,
  CEFAppConfig_SetUseMockKeyChain,
  CEFAppConfig_DisableRequestHandlingForTesting,
  CEFAppConfig_SetDisableRequestHandlingForTesting,
  CEFAppConfig_DisablePopupBlocking,
  CEFAppConfig_SetDisablePopupBlocking,
  CEFAppConfig_DisableBackForwardCache,
  CEFAppConfig_SetDisableBackForwardCache,
  CEFAppConfig_DisableComponentUpdate,
  CEFAppConfig_SetDisableComponentUpdate,
  CEFAppConfig_AllowInsecureLocalhost,
  CEFAppConfig_SetAllowInsecureLocalhost,
  CEFAppConfig_KioskPrinting,
  CEFAppConfig_SetKioskPrinting,
  CEFAppConfig_TreatInsecureOriginAsSecure,
  CEFAppConfig_SetTreatInsecureOriginAsSecure,
  CEFAppConfig_NetLogEnabled,
  CEFAppConfig_SetNetLogEnabled,
  CEFAppConfig_NetLogFile,
  CEFAppConfig_SetNetLogFile,
  CEFAppConfig_NetLogCaptureMode,
  CEFAppConfig_SetNetLogCaptureMode,
  CEFAppConfig_EnableHighDPISupport,
  CEFAppConfig_SetEnableHighDPISupport,
  CEFAppConfig_DeleteCache,
  CEFAppConfig_DeleteCookies,
  CEFAppConfig_CheckCEFFiles,
  CEFAppConfig_ShowMessageDlg,
  CEFAppConfig_MissingBinariesException,
  CEFAppConfig_SetCurrentDir,
  CEFAppConfig_GlobalContextInitialized,
  CEFAppConfig_ChromeMajorVer,
  CEFAppConfig_ChromeMinorVer,
  CEFAppConfig_ChromeRelease,
  CEFAppConfig_ChromeBuild,
  CEFAppConfig_ChromeVersion,
  CEFAppConfig_LibCefVersion,
  CEFAppConfig_LibCefPath,
  CEFAppConfig_ChromeElfPath,
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
  CEFAppConfig_ApiHashUniversal,
  CEFAppConfig_ApiHashPlatform,
  CEFAppConfig_ApiHashCommit,
  CEFAppConfig_LastErrorMessage,
  CEFAppConfig_SetDeleteCache,
  CEFAppConfig_SetDeleteCookies,
  CEFAppConfig_SetCheckCEFFiles,
  CEFAppConfig_SetShowMessageDlg,
  CEFAppConfig_SetMissingBinariesException,
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
