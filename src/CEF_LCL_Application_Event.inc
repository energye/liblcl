//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

// ICefApp
procedure CEFGlobalApp_SetOnRegCustomSchemes(AEventData: Pointer); extdecl;
begin
  OnRegCustomSchemes_DataPtr := AEventData;
  GlobalCEFApp.OnRegCustomSchemes := GlobalCEFApp_OnRegCustomSchemes;
end;

// ICefBrowserProcessHandler
procedure CEFGlobalApp_SetOnRegisterCustomPreferences(AEventData: Pointer); extdecl;
begin
end;

procedure CEFGlobalApp_SetOnContextInitialized(AEventData: Pointer); extdecl;
begin
  OnContextInitialized_DataPtr := AEventData;
  GlobalCEFApp.OnContextInitialized := GlobalCEFApp_OnContextInitialized;
end;

procedure CEFGlobalApp_SetOnBeforeChildProcessLaunch(AEventData: Pointer); extdecl;
begin
  OnBeforeChildProcessLaunch_DataPtr := AEventData;
  GlobalCEFApp.OnBeforeChildProcessLaunch := GlobalCEFApp_OnBeforeChildProcessLaunch;
end;

procedure CEFGlobalApp_SetOnGetDefaultClient(AEventData: Pointer); extdecl;
begin
end;

// ICefResourceBundleHandler
procedure CEFGlobalApp_SetOnGetLocalizedString(AEventData: Pointer); extdecl;
begin
  OnGetLocalizedString_DataPtr := AEventData;
  GlobalCEFApp.OnGetLocalizedString := GlobalCEFApp_OnGetLocalizedString;
end;

procedure CEFGlobalApp_SetOnGetDataResource(AEventData: Pointer); extdecl;
begin
  OnGetDataResource_DataPtr := AEventData;
  GlobalCEFApp.OnGetDataResource := GlobalCEFApp_OnGetDataResource;
end;

procedure CEFGlobalApp_SetOnGetDataResourceForScale(AEventData: Pointer); extdecl;
begin
  OnGetDataResourceForScale_DataPtr := AEventData;
  GlobalCEFApp.OnGetDataResourceForScale := GlobalCEFApp_OnGetDataResourceForScale;
end;

// ICefRenderProcessHandler
procedure CEFGlobalApp_SetOnWebKitInitialized(AEventData: Pointer); extdecl;
begin
  OnWebKitInitialized_DataPtr := AEventData;
  GlobalCEFApp.OnWebKitInitialized := GlobalCEFApp_OnWebKitInitialized;
end;

procedure CEFGlobalApp_SetOnBrowserCreated(AEventData: Pointer); extdecl;
begin
  OnBrowserCreated_DataPtr := AEventData;
  GlobalCEFApp.OnBrowserCreated := GlobalCEFApp_OnBrowserCreated;
end;

procedure CEFGlobalApp_SetOnBrowserDestroyed(AEventData: Pointer); extdecl;
begin
  OnBrowserDestroyed_DataPtr := AEventData;
  GlobalCEFApp.OnBrowserDestroyed := GlobalCEFApp_OnBrowserDestroyed;
end;

procedure CEFGlobalApp_SetOnContextCreated(AEventData: Pointer); extdecl;
begin
  OnContextCreated_DataPtr := AEventData;
  GlobalCEFApp.OnContextCreated := GlobalCEFApp_OnContextCreated;
end;

procedure CEFGlobalApp_SetOnContextReleased(AEventData: Pointer); extdecl;
begin
  OnContextReleased_DataPtr := AEventData;
  GlobalCEFApp.OnContextReleased := GlobalCEFApp_OnContextReleased;
end;

procedure CEFGlobalApp_SetOnUncaughtException(AEventData: Pointer); extdecl;
begin
  OnUncaughtException_DataPtr := AEventData;
  GlobalCEFApp.OnUncaughtException := GlobalCEFApp_OnUncaughtException;
end;

procedure CEFGlobalApp_SetOnFocusedNodeChanged(AEventData: Pointer); extdecl;
begin
  OnFocusedNodeChanged_DataPtr := AEventData;
  GlobalCEFApp.OnFocusedNodeChanged := GlobalCEFApp_OnFocusedNodeChanged;
end;

procedure CEFGlobalApp_SetOnProcessMessageReceived(AEventData: Pointer); extdecl;
begin
  OnProcessMessageReceived_DataPtr := AEventData;
  GlobalCEFApp.OnProcessMessageReceived := GlobalCEFApp_OnProcessMessageReceived;
end;

exports
  CEFGlobalApp_SetOnRegCustomSchemes,
  CEFGlobalApp_SetOnRegisterCustomPreferences,
  CEFGlobalApp_SetOnContextInitialized,
  CEFGlobalApp_SetOnBeforeChildProcessLaunch,
  CEFGlobalApp_SetOnGetDefaultClient,
  CEFGlobalApp_SetOnGetLocalizedString,
  CEFGlobalApp_SetOnGetDataResource,
  CEFGlobalApp_SetOnGetDataResourceForScale,
  CEFGlobalApp_SetOnWebKitInitialized,
  CEFGlobalApp_SetOnBrowserCreated,
  CEFGlobalApp_SetOnBrowserDestroyed,
  CEFGlobalApp_SetOnContextCreated,
  CEFGlobalApp_SetOnContextReleased,
  CEFGlobalApp_SetOnUncaughtException,
  CEFGlobalApp_SetOnFocusedNodeChanged,
  CEFGlobalApp_SetOnProcessMessageReceived;
