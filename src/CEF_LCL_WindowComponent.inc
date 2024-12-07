//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//function
function CEFWindowComponent_Create(AOwner: TComponent): TCEFWindowComponent ; extdecl;
begin
  handleExceptionBegin
  Result := TCEFWindowComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure CEFWindowComponent_CreateTopLevelWindow(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.CreateTopLevelWindow;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Show(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Show;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Hide(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Hide;
  handleExceptionEnd
end;

procedure CEFWindowComponent_CenterWindow(const TObj: TCEFWindowComponent; var AValue: TCefSize); extdecl;
begin
  handleExceptionBegin
  TObj.CenterWindow(AValue);
  handleExceptionEnd
end;

procedure CEFWindowComponent_Close(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Close;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Activate(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Activate;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Deactivate(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Deactivate;
  handleExceptionEnd
end;

procedure CEFWindowComponent_BringToTop(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.BringToTop;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Maximize(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Maximize;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Minimize(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Minimize;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetFullscreen(const TObj: TCEFWindowComponent; fullscreen: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.IsFullscreen := fullscreen;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetBackgroundColor(const TObj: TCEFWindowComponent; AValue : TCefColor); extdecl;
begin
  handleExceptionBegin
  TObj.BackgroundColor := AValue;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Bounds(const TObj: TCEFWindowComponent; var Result : TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Bounds;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Size(const TObj: TCEFWindowComponent; var Result : TCefSize); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Size;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Position(const TObj: TCEFWindowComponent; var Result : TCefPoint); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Position;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetBounds(const TObj: TCEFWindowComponent; var AValue : TCefRect); extdecl;
begin
  handleExceptionBegin
  TObj.Bounds := AValue;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetSize(const TObj: TCEFWindowComponent; var AValue : TCefSize); extdecl;
begin
  handleExceptionBegin
  TObj.Size := AValue;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetPosition(const TObj: TCEFWindowComponent; var AValue : TCefPoint); extdecl;
begin
  handleExceptionBegin
  TObj.Position := AValue;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetAlwaysOnTop(const TObj: TCEFWindowComponent; onTop: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.IsAlwaysOnTop := onTop;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Restore(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.Restore;
  handleExceptionEnd
end;

procedure CEFWindowComponent_AddOverlayView(const TObj: TCEFWindowComponent; const view: ICefView; docking_mode: TCefDockingMode; can_activate: boolean; out Result: ICefOverlayController); extdecl;
begin
  handleExceptionBegin
  Result := TObj.AddOverlayView(view, docking_mode);
  handleExceptionEnd
end;

procedure CEFWindowComponent_ShowMenu(const TObj: TCEFWindowComponent; const menu_model: ICefMenuModel; var screen_point: TCefPoint; anchor_position : TCefMenuAnchorPosition); extdecl;
begin
  handleExceptionBegin
  TObj.ShowMenu(menu_model, screen_point, anchor_position);
  handleExceptionEnd
end;

procedure CEFWindowComponent_CancelMenu(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.CancelMenu;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SendKeyPress(const TObj: TCEFWindowComponent; key_code: Integer; event_flags: cardinal); extdecl;
begin
  handleExceptionBegin
  TObj.SendKeyPress(key_code, event_flags);
  handleExceptionEnd
end;

procedure CEFWindowComponent_SendMouseMove(const TObj: TCEFWindowComponent; screen_x, screen_y: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseMove(screen_x, screen_y);
  handleExceptionEnd
end;

procedure CEFWindowComponent_SendMouseEvents(const TObj: TCEFWindowComponent; button: TCefMouseButtonType; mouse_down, mouse_up: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SendMouseEvents(button, mouse_down, mouse_up);
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetAccelerator(const TObj: TCEFWindowComponent; command_id, key_code : Integer; shift_pressed, ctrl_pressed, alt_pressed, high_priority: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.SetAccelerator(command_id, key_code, shift_pressed, ctrl_pressed, alt_pressed);
  handleExceptionEnd
end;

procedure CEFWindowComponent_RemoveAccelerator(const TObj: TCEFWindowComponent; command_id: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.RemoveAccelerator(command_id);
  handleExceptionEnd
end;

procedure CEFWindowComponent_RemoveAllAccelerators(const TObj: TCEFWindowComponent); extdecl;
begin
  handleExceptionBegin
  TObj.RemoveAllAccelerators;
  handleExceptionEnd
end;

//property
procedure CEFWindowComponent_SetTitle(const TObj: TCEFWindowComponent; PTitle: PChar); extdecl;
begin
  handleExceptionBegin
  TObj.Title := PCharToUstr(PTitle);
  handleExceptionEnd
end;

function CEFWindowComponent_Title(const TObj: TCEFWindowComponent): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.Title));
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetDraggableRegions(const TObj: TCEFWindowComponent; regionsCount: NativeUInt; const regions: TCefDraggableRegionArray); extdecl;
begin
  handleExceptionBegin
  TObj.SetDraggableRegions(regionsCount, @regions[0]);
  handleExceptionEnd
end;

procedure CEFWindowComponent_WindowIcon(const TObj: TCEFWindowComponent; var Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := TObj.WindowIcon;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetWindowIcon(const TObj: TCEFWindowComponent; const icon: ICefImage); extdecl;
begin
  handleExceptionBegin
  TObj.WindowIcon := icon;
  handleExceptionEnd
end;

procedure CEFWindowComponent_WindowAppIcon(const TObj: TCEFWindowComponent; var Result: ICefImage); extdecl;
begin
  handleExceptionBegin
  Result := TObj.WindowAppIcon;
  handleExceptionEnd
end;

procedure CEFWindowComponent_SetWindowAppIcon(const TObj: TCEFWindowComponent; const icon: ICefImage); extdecl;
begin
  handleExceptionBegin
  TObj.WindowAppIcon := icon;
  handleExceptionEnd
end;

procedure CEFWindowComponent_Display(const TObj: TCEFWindowComponent; var Result: ICefDisplay); extdecl;
begin
  handleExceptionBegin
  Result := TObj.Display;
  handleExceptionEnd
end;

procedure CEFWindowComponent_ClientAreaBoundsInScreen(const TObj: TCEFWindowComponent; var Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := TObj.ClientAreaBoundsInScreen;
  handleExceptionEnd
end;

function CEFWindowComponent_WindowHandle(const TObj: TCEFWindowComponent): TCefWindowHandle; extdecl;
begin
  handleExceptionBegin
  Result := TObj.WindowHandle;
  handleExceptionEnd
end;

function CEFWindowComponent_IsClosed(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsClosed;
  handleExceptionEnd
end;

function CEFWindowComponent_IsActive(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsActive;
  handleExceptionEnd
end;

function CEFWindowComponent_IsAlwaysOnTop(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsAlwaysOnTop;
  handleExceptionEnd
end;

function CEFWindowComponent_IsFullscreen(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsFullscreen;
  handleExceptionEnd
end;

function CEFWindowComponent_IsMaximized(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsMaximized;
  handleExceptionEnd
end;

function CEFWindowComponent_IsMinimized(const TObj: TCEFWindowComponent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsMinimized;
  handleExceptionEnd
end;

procedure CEFWindowComponent_AddChildView(const TObj: TCEFWindowComponent; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  TObj.AddChildView(view);
  handleExceptionEnd
end;

//event
procedure CEFWindowComponent_SetOnWindowCreated(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnWindowCreated}
  {$DEFINE EventName := OnWindowCreated}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowClosing(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnWindowClosing}
  {$DEFINE EventName := OnWindowClosing}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowDestroyed(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnWindowDestroyed}
  {$DEFINE EventName := OnWindowDestroyed}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowActivationChanged(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnWindowActivationChanged}
  {$DEFINE EventName := OnWindowActivationChanged}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowBoundsChanged(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnWindowBoundsChanged}
  {$DEFINE EventName := OnWindowBoundsChanged}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetParentWindow(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnGetParentWindow}
  {$DEFINE EventName := OnGetParentWindow}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetInitialBounds(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnGetInitialBounds}
  {$DEFINE EventName := OnGetInitialBounds}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetInitialShowState(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnGetInitialShowState}
  {$DEFINE EventName := OnGetInitialShowState}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnIsFrameless(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnIsFrameless}
  {$DEFINE EventName := OnIsFrameless}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanResize(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnCanResize}
  {$DEFINE EventName := OnCanResize}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanMaximize(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnCanMaximize}
  {$DEFINE EventName := OnCanMaximize}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanMinimize(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnCanMinimize}
  {$DEFINE EventName := OnCanMinimize}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanClose(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnCanClose}
  {$DEFINE EventName := OnCanClose}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnAccelerator(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnAccelerator}
  {$DEFINE EventName := OnAccelerator}
  EventMethodCode
end;

procedure CEFWindowComponent_SetOnKeyEvent(const AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := WindowComponent_OnKeyEvent}
  {$DEFINE EventName := OnKeyEvent}
  EventMethodCode
end;

exports
  CEFWindowComponent_Create,
  CEFWindowComponent_Show,
  CEFWindowComponent_Hide,
  CEFWindowComponent_CenterWindow,
  CEFWindowComponent_Close,
  CEFWindowComponent_Activate,
  CEFWindowComponent_Deactivate,
  CEFWindowComponent_BringToTop,
  CEFWindowComponent_Maximize,
  CEFWindowComponent_Minimize,
  CEFWindowComponent_Restore,
  CEFWindowComponent_AddOverlayView,
  CEFWindowComponent_ShowMenu,
  CEFWindowComponent_CancelMenu,
  CEFWindowComponent_SetDraggableRegions,
  CEFWindowComponent_SendKeyPress,
  CEFWindowComponent_SendMouseMove,
  CEFWindowComponent_SendMouseEvents,
  CEFWindowComponent_SetAccelerator,
  CEFWindowComponent_RemoveAccelerator,
  CEFWindowComponent_RemoveAllAccelerators,
  CEFWindowComponent_SetAlwaysOnTop,
  CEFWindowComponent_SetFullscreen,
  CEFWindowComponent_SetBackgroundColor,
  CEFWindowComponent_Bounds,
  CEFWindowComponent_Size,
  CEFWindowComponent_Position,
  CEFWindowComponent_SetBounds,
  CEFWindowComponent_SetSize,
  CEFWindowComponent_SetPosition,
  CEFWindowComponent_SetTitle,
  CEFWindowComponent_Title,
  CEFWindowComponent_WindowIcon,
  CEFWindowComponent_SetWindowIcon,
  CEFWindowComponent_WindowAppIcon,
  CEFWindowComponent_SetWindowAppIcon,
  CEFWindowComponent_Display,
  CEFWindowComponent_ClientAreaBoundsInScreen,
  CEFWindowComponent_WindowHandle,
  CEFWindowComponent_IsClosed,
  CEFWindowComponent_IsActive,
  CEFWindowComponent_IsAlwaysOnTop,
  CEFWindowComponent_IsFullscreen,
  CEFWindowComponent_IsMaximized,
  CEFWindowComponent_IsMinimized,
  CEFWindowComponent_AddChildView,
  CEFWindowComponent_SetOnWindowCreated,
  CEFWindowComponent_SetOnWindowClosing,
  CEFWindowComponent_SetOnWindowDestroyed,
  CEFWindowComponent_SetOnWindowActivationChanged,
  CEFWindowComponent_SetOnWindowBoundsChanged,
  CEFWindowComponent_SetOnGetParentWindow,
  CEFWindowComponent_SetOnGetInitialBounds,
  CEFWindowComponent_SetOnGetInitialShowState,
  CEFWindowComponent_SetOnIsFrameless,
  CEFWindowComponent_SetOnCanResize,
  CEFWindowComponent_SetOnCanMaximize,
  CEFWindowComponent_SetOnCanMinimize,
  CEFWindowComponent_SetOnCanClose,
  CEFWindowComponent_SetOnAccelerator,
  CEFWindowComponent_SetOnKeyEvent;
