//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------


procedure ICEFWindowRef_CreateTopLevel(const delegate: ICefWindowDelegate; out Result: ICefWindow); extdecl;
begin
  handleExceptionBegin
  Result := TCefWindowRef.CreateTopLevel(delegate);
  handleExceptionEnd
end;

procedure ICEFWindow_Show(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Show;
  handleExceptionEnd
end;

procedure ICEFWindow_ShowAsBrowserModalDialog(const AWindow: ICefWindow; const browser_view: ICefBrowserView); extdecl;
begin
  handleExceptionBegin
  AWindow.ShowAsBrowserModalDialog(browser_view);
  handleExceptionEnd
end;

procedure ICEFWindow_Hide(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Hide;
  handleExceptionEnd
end;

procedure ICEFWindow_CenterWindow(const AWindow: ICefWindow; var AValue: TCefSize); extdecl;
begin
  handleExceptionBegin
  AWindow.CenterWindow(AValue);
  handleExceptionEnd
end;

procedure ICEFWindow_Close(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Close;
  handleExceptionEnd
end;

function ICEFWindow_IsClosed(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsClosed;
  handleExceptionEnd
end;

procedure ICEFWindow_Activate(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Activate;
  handleExceptionEnd
end;

procedure ICEFWindow_Deactivate(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Deactivate;
  handleExceptionEnd
end;

function ICEFWindow_IsActive(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsActive;
  handleExceptionEnd
end;

procedure ICEFWindow_BringToTop(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.BringToTop;
  handleExceptionEnd
end;

procedure ICEFWindow_SetAlwaysOnTop(const AWindow: ICefWindow; on_top: LongBool); extdecl;
begin
  handleExceptionBegin
  AWindow.SetAlwaysOnTop(on_top);
  handleExceptionEnd
end;

function ICEFWindow_IsAlwaysOnTop(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsAlwaysOnTop;
  handleExceptionEnd
end;

procedure ICEFWindow_Maximize(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Maximize;
  handleExceptionEnd
end;

procedure ICEFWindow_Minimize(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Minimize;
  handleExceptionEnd
end;

procedure ICEFWindow_Restore(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.Restore;
  handleExceptionEnd
end;

procedure ICEFWindow_SetFullscreen(const AWindow: ICefWindow; fullscreen: LongBool); extdecl;
begin
  handleExceptionBegin
  AWindow.SetFullscreen(fullscreen);
  handleExceptionEnd
end;

procedure ICEFWindow_SetBackgroundColor(const AWindow: ICefWindow; var AValue : TCefColor); extdecl;
begin
  handleExceptionBegin
  AWindow.BackgroundColor := AValue;
  handleExceptionEnd
end;

procedure ICEFWindow_SetBounds(const AWindow: ICefWindow; var AValue : TCefRect); extdecl;
begin
  handleExceptionBegin
  AWindow.Bounds := AValue;
  handleExceptionEnd
end;

procedure ICEFWindow_SetSize(const AWindow: ICefWindow; var AValue : TCefSize); extdecl;
begin
  handleExceptionBegin
  AWindow.Size := AValue;
  handleExceptionEnd
end;

procedure ICEFWindow_SetPosition(const AWindow: ICefWindow; var AValue : TCefPoint); extdecl;
begin
  handleExceptionBegin
  AWindow.Position := AValue;
  handleExceptionEnd
end;

function ICEFWindow_IsMaximized(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsMaximized;
  handleExceptionEnd
end;

function ICEFWindow_IsMinimized(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsMinimized;
  handleExceptionEnd
end;

function ICEFWindow_IsFullscreen(const AWindow: ICefWindow): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.IsFullscreen;
  handleExceptionEnd
end;

procedure ICEFWindow_SetTitle(const AWindow: ICefWindow; const PTitle: PChar); extdecl;
begin
  handleExceptionBegin
  AWindow.SetTitle(PCharToUStr(PTitle));
  handleExceptionEnd
end;

function ICEFWindow_GetTitle(const AWindow: ICefWindow): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AWindow.Title));
  handleExceptionEnd
end;

{$ifdef DARWIN}
procedure ICEFWindow_SetWindowIcon(const AWindow: ICefWindow; scaleFactor: PSingle; const data: array of Byte; dataSize: NativeUInt); extdecl;
var
  tmpData: array of Byte;
{$else}
procedure ICEFWindow_SetWindowIcon(const AWindow: ICefWindow; scaleFactor: PSingle; const data: array of Byte); stdcall;
var
{$endif}
  icon: ICefImage;
begin
  handleExceptionBegin
  icon := TCefImageRef.New;
  {$ifdef DARWIN}
  if dataSize >0 then
  begin
  try
  SetLength(tmpData, dataSize);
  Move(data[0], tmpData[0], dataSize);
  icon.AddPng(scaleFactor^, @tmpData[0], dataSize);
  finally
  SetLength(tmpData, 0);
  end;
  end;
  {$else}
  icon.AddPng(scaleFactor^, @data[0], length(data));
  {$endif}
  AWindow.WindowIcon := icon;
  handleExceptionEnd
end;

procedure ICEFWindow_GetWindowIcon(const AWindow: ICefWindow; var Result: Pointer); extdecl;
var
  icon: ICefImage;
begin
  handleExceptionBegin
  icon := AWindow.WindowIcon;
  if (icon <> nil) and not(icon.IsEmpty) then
  begin
  Result := icon.Wrap;
  end;
  handleExceptionEnd
end;

{$ifdef DARWIN}
procedure ICEFWindow_SetWindowAppIcon(const AWindow: ICefWindow; scaleFactor: PSingle; const data: array of Byte; dataSize: NativeUInt); extdecl;
var
  tmpData: array of Byte;
{$else}
procedure ICEFWindow_SetWindowAppIcon(const AWindow: ICefWindow; scaleFactor: PSingle; const data: array of Byte); stdcall;
var
{$endif}
  icon: ICefImage;
begin
  handleExceptionBegin
  icon := TCefImageRef.New;
  {$ifdef DARWIN}
  if dataSize >0 then
  begin
  try
  SetLength(tmpData, dataSize);
  Move(data[0], tmpData[0], dataSize);
  icon.AddPng(scaleFactor^, @tmpData[0], dataSize);
  finally
  SetLength(tmpData, 0);
  end;
  end;
  {$else}
  icon.AddPng(scaleFactor^, @data[0], length(data));
  {$endif}
  AWindow.WindowAppIcon := icon;
  handleExceptionEnd
end;

procedure ICEFWindow_GetWindowAppIcon(const AWindow: ICefWindow; var Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := AWindow.WindowAppIcon;
  handleExceptionEnd
end;

procedure ICEFWindow_AddOverlayView(const AWindow: ICefWindow; const view: ICefView; docking_mode: TCefDockingMode; out Result: ICefOverlayController); extdecl;
begin
  handleExceptionBegin
  Result := AWindow.AddOverlayView(view, docking_mode);
  handleExceptionEnd
end;

procedure ICEFWindow_ShowMenu(const AWindow: ICefWindow; const menu_model: ICefMenuModel; const screen_point: TCefPoint; anchor_position : TCefMenuAnchorPosition); extdecl;
begin
  handleExceptionBegin
  AWindow.ShowMenu(menu_model, screen_point, anchor_position);
  handleExceptionEnd
end;

procedure ICEFWindow_CancelMenu(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.CancelMenu;
  handleExceptionEnd
end;

procedure ICEFWindow_GetDisplay(const AWindow: ICefWindow; var Result: ICefDisplay); extdecl;
begin
  handleExceptionBegin
  Result := AWindow.GetDisplay;
  handleExceptionEnd
end;

procedure ICEFWindow_GetClientAreaBoundsInScreen(const AWindow: ICefWindow; var Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AWindow.GetClientAreaBoundsInScreen;
  handleExceptionEnd
end;

procedure ICEFWindow_SetDraggableRegions(const AWindow: ICefWindow; regionsCount: NativeUInt; const regions: TCefDraggableRegionArray); extdecl;
begin
  handleExceptionBegin
  AWindow.SetDraggableRegions(regionsCount, @regions[0]);
  handleExceptionEnd
end;

function ICEFWindow_GetWindowHandle(const AWindow: ICefWindow): TCefWindowHandle; extdecl;
begin
  handleExceptionBegin
  Result := AWindow.GetWindowHandle;
  handleExceptionEnd
end;

procedure ICEFWindow_SendKeyPress(const AWindow: ICefWindow; key_code: Integer; event_flags: cardinal); extdecl;
begin
  handleExceptionBegin
  AWindow.SendKeyPress(key_code, event_flags);
  handleExceptionEnd
end;

procedure ICEFWindow_SendMouseMove(const AWindow: ICefWindow; screen_x, screen_y: Integer); extdecl;
begin
  handleExceptionBegin
  AWindow.SendMouseMove(screen_x, screen_y);
  handleExceptionEnd
end;

procedure ICEFWindow_SendMouseEvents(const AWindow: ICefWindow; button: TCefMouseButtonType; mouse_down, mouse_up: LongBool); extdecl;
begin
  handleExceptionBegin
  AWindow.SendMouseEvents(button, mouse_down, mouse_up);
  handleExceptionEnd
end;

procedure ICEFWindow_SetAccelerator(const AWindow: ICefWindow; command_id, key_code : Integer; shift_pressed, ctrl_pressed, alt_pressed: LongBool); extdecl;
begin
  handleExceptionBegin
  AWindow.SetAccelerator(command_id, key_code, shift_pressed, ctrl_pressed, alt_pressed);
  handleExceptionEnd
end;

procedure ICEFWindow_RemoveAccelerator(const AWindow: ICefWindow; command_id: Integer); extdecl;
begin
  handleExceptionBegin
  AWindow.RemoveAccelerator(command_id);
  handleExceptionEnd
end;

procedure ICEFWindow_RemoveAllAccelerators(const AWindow: ICefWindow); extdecl;
begin
  handleExceptionBegin
  AWindow.RemoveAllAccelerators();
  handleExceptionEnd
end;

exports
  ICEFWindowRef_CreateTopLevel,
  ICEFWindow_Show,
  ICEFWindow_ShowAsBrowserModalDialog,
  ICEFWindow_Hide,
  ICEFWindow_CenterWindow,
  ICEFWindow_Close,
  ICEFWindow_IsClosed,
  ICEFWindow_Activate,
  ICEFWindow_Deactivate,
  ICEFWindow_IsActive,
  ICEFWindow_BringToTop,
  ICEFWindow_SetAlwaysOnTop,
  ICEFWindow_IsAlwaysOnTop,
  ICEFWindow_Maximize,
  ICEFWindow_Minimize,
  ICEFWindow_Restore,
  ICEFWindow_SetFullscreen,
  ICEFWindow_SetBackgroundColor,
  ICEFWindow_SetBounds,
  ICEFWindow_SetSize,
  ICEFWindow_SetPosition,
  ICEFWindow_IsMaximized,
  ICEFWindow_IsMinimized,
  ICEFWindow_IsFullscreen,
  ICEFWindow_SetTitle,
  ICEFWindow_GetTitle,
  ICEFWindow_SetWindowIcon,
  ICEFWindow_GetWindowIcon,
  ICEFWindow_SetWindowAppIcon,
  ICEFWindow_GetWindowAppIcon,
  ICEFWindow_AddOverlayView,
  ICEFWindow_ShowMenu,
  ICEFWindow_CancelMenu,
  ICEFWindow_GetDisplay,
  ICEFWindow_GetClientAreaBoundsInScreen,
  ICEFWindow_SetDraggableRegions,
  ICEFWindow_GetWindowHandle,
  ICEFWindow_SendKeyPress,
  ICEFWindow_SendMouseMove,
  ICEFWindow_SendMouseEvents,
  ICEFWindow_SetAccelerator,
  ICEFWindow_RemoveAccelerator,
  ICEFWindow_RemoveAllAccelerators;
