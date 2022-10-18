//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//macos 需要在go程序中单独设置 args 命令行参数, 原因是默认情况调用动态链接库启动获取不到args
procedure SetMacOSXCommandLine(PCommandLine: PChar); extdecl;
var
  i: integer;
begin
  handleExceptionBegin
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
  handleExceptionEnd
end;

// AddCrDelegate
procedure CEF_AddCrDelegate(); extdecl;
begin
  {$IFDEF DARWIN}
    AddCrDelegate;
  {$ENDIF}
end;

//创建 TCefApplication
function CEFApplication_Create(Config: PTCEFApplicationConfig):TCefApplication ; extdecl;
var
    FrameworkDirPath, ResourcesDirPath, LocalesDirPath, Cache, UserDataPath: ustring;
    LocalesRequired, Language: ustring;
    MainBundlePath, BrowserSubprocessPath: ustring;
    i: integer;
begin
  handleExceptionBegin
  {$IFDEF DARWIN}
    AddCrDelegate;
  {$ENDIF}
  //创建 TCefApplication
  GlobalCEFApp := TCefApplication.Create;
  {$IFDEF DARWIN}
    GlobalCEFWorkScheduler                 := TCEFWorkScheduler.Create(nil);
    MainBundlePath := PCharToUStr(Config^.MainBundlePath);
    if not (string(MainBundlePath) = '') then
       GlobalCEFApp.MainBundlePath         := MainBundlePath;
    GlobalCEFApp.ExternalMessagePump       := True;
    GlobalCEFApp.MultiThreadedMessageLoop  := False;
    GlobalCEFApp.OnScheduleMessagePumpWork := @GlobalCEFApp_OnScheduleMessagePumpWork;
  {$ELSE}
    GlobalCEFApp.MultiThreadedMessageLoop  := True;
  {$ENDIF}
  //cef chromium 参数配置
  //string
  FrameworkDirPath := PCharToUStr(Config^.FrameworkDirPath);
  ResourcesDirPath := PCharToUStr(Config^.ResourcesDirPath);
  LocalesDirPath := PCharToUStr(Config^.LocalesDirPath);
  Cache := PCharToUStr(Config^.Cache);
  UserDataPath := PCharToUStr(Config^.UserDataPath);
  Language := PCharToUStr(Config^.Language);
  LocalesRequired := PCharToUStr(Config^.LocalesRequired);
  if not (string(FrameworkDirPath) = '') then
     GlobalCEFApp.FrameworkDirPath := FrameworkDirPath;
  if not (string(ResourcesDirPath) = '') then
     GlobalCEFApp.ResourcesDirPath := ResourcesDirPath;
  if not (string(LocalesDirPath) = '') then
     GlobalCEFApp.LocalesDirPath := LocalesDirPath;
  if not (string(Cache) = '') then
     GlobalCEFApp.cache := Cache;
  if not (string(UserDataPath) = '') then
     GlobalCEFApp.UserDataPath := UserDataPath;
  if not (string(Language) = '') then
  begin
    GlobalCEFApp.AcceptLanguageList := Language;
    GlobalCEFApp.Locale := Language;
  end;
  if not (string(LocalesRequired) = '') then
  begin
    GlobalCEFApp.LocalesRequired := LocalesRequired;
  end;
  {$IFnDEF DARWIN}
  //sub process
  BrowserSubprocessPath := PCharToUStr(Config^.BrowserSubprocessPath);
  if not (string(BrowserSubprocessPath) = '') then
    GlobalCEFApp.BrowserSubprocessPath := BrowserSubprocessPath;
  {$ENDIF}
  GlobalCEFApp.LogFile := PCharToUStr(Config^.LogFile);
  GlobalCEFApp.LogSeverity := TCefLogSeverity(Config^.LogSeverity);
  //boolean
  GlobalCEFApp.NoSandbox := boolean(Config^.NoSandbox);
  {$IFDEF LINUX}
  // 这是一个解决“GPU不可用错误”问题的方法:
  // https://bitbucket.org/chromiumembedded/cef/issues/2964/gpu-is-not-usable-error-during-cef
  GlobalCEFApp.DisableZygote := boolean(Config^.DisableZygote); // 此属性添加了“——no-zygote”命令行开关
  {$ENDIF}
  //远程调式端口
  if (Integer(Config^.RemoteDebuggingPort) > 1024) and (Integer(Config^.RemoteDebuggingPort) < 65535) then
  begin
    GlobalCEFApp.RemoteDebuggingPort := Integer(Config^.RemoteDebuggingPort);
  end;
  GlobalCEFApp.EnableGPU := boolean(Config^.EnableGPU);
  GlobalCEFApp.SingleProcess := boolean(Config^.SingleProcess);
  SingleProcess := GlobalCEFApp.SingleProcess;
  GlobalCEFApp.UseMockKeyChain := boolean(Config^.UseMockKeyChain);
  GlobalCEFApp.CheckCEFFiles := boolean(Config^.CheckCEFFiles);
  GlobalCEFApp.DisableSafeBrowsing := True; //禁用安全浏览器:True
  GlobalCEFApp.DisableComponentUpdate := True;//禁用扩展组件更新
  GlobalCEFApp.EnablePrintPreview := True;
  //GlobalCEFApp.SitePerProcess := True;

  Result := GlobalCEFApp;
  handleExceptionEnd
end;

//释放 TCefApplication
procedure CEFApplication_Free(); extdecl;
begin
  handleExceptionBegin
  GlobalCEFApp.Free;
  GlobalCEFApp := nil;
  handleExceptionEnd
end;

//启动主进程
function CEFStartMainProcess(): integer; extdecl;
var
  ret : boolean;
begin
  handleExceptionBegin
  ret := GlobalCEFApp.StartMainProcess;
  if ret then
  begin
    {$ifdef Linux}
    //CustomWidgetSetInitialization();
    {$endif}
    Result := 1;
  end
  else
  begin
    DestroyGlobalCEFApp;
    {$IFDEF MACOSX}
    DestroyGlobalCEFWorkScheduler;
    {$ENDIF}
    halt(0); // exit the subprocess
    Result := 0;
  end;
handleExceptionEnd
end;

//启动主进程
function CEFStartSubProcess(): integer; extdecl;
var
  ret : boolean;
begin
  handleExceptionBegin
  {$IFDEF MACOSX}
  GlobalCEFApp.InitLibLocationFromArgs;
  {$ENDIF}
  ret := GlobalCEFApp.StartSubProcess;
  if ret then
  begin
    {$ifdef Linux}
    //CustomWidgetSetInitialization();
    {$endif}
    Result := 1;
  end
  else
    Result := 0;
  handleExceptionEnd
end;

{====== events ======}

procedure AddCustomCommandLine(CommandLine, Value: PChar); extdecl;
begin
  GlobalCEFApp.AddCustomCommandLine(PCharToUStr(CommandLine), PCharToUStr(Value));
end;

//执行JS
procedure CEFApplication_ExecuteJS(browserId: integer; jsCode: PChar); extdecl;
var
  pReturnValue: ICefv8Value;
  pException: ICefV8Exception;
begin
  try
  except
    on E: Exception do
    begin
    end;
  end;
end;

function CEFApplication_GetCommonInstance(): CommonObject; extdecl;
begin
  if CommonInstance = nil then
  begin
    CommonInstance := CommonObject.Create;
  end;
  Result := CommonInstance;
end;

procedure CEFApplication_QueueAsyncCall(EventId: PtrInt); extdecl;
begin
  Application.QueueAsyncCall(TCEFApplicationClass.ApplicationQueueAsyncCall, EventId);
end;

exports
  CEF_AddCrDelegate,
  SetMacOSXCommandLine,
  CEFApplication_Create,
  CEFApplication_Free,
  CEFStartMainProcess,
  CEFStartSubProcess,
  AddCustomCommandLine,
  {events}
  CEFApplication_ExecuteJS,
  CEFApplication_QueueAsyncCall,
  CEFApplication_GetCommonInstance
{end}
;

