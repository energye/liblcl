//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//function
function CEFWindowComponent_Create(AOwner: TComponent):TCEFWindowComponent ; extdecl;
begin
    handleExceptionBegin
    Result := TCEFWindowComponent.Create(AOwner);
    handleExceptionEnd
end;

procedure CEFWindowComponent_CreateTopLevelWindow(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.CreateTopLevelWindow;
    handleExceptionEnd
end;

procedure CEFWindowComponent_Show(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Show;
    handleExceptionEnd
end;

procedure CEFWindowComponent_Hide(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Hide;
    handleExceptionEnd
end;


procedure CEFWindowComponent_CenterWindow(TObj: TCEFWindowComponent; size_: TCefSize); extdecl;
begin
    handleExceptionBegin
    TObj.CenterWindow(size_);
    handleExceptionEnd
end;


procedure CEFWindowComponent_Close(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Close;
    handleExceptionEnd
end;


procedure CEFWindowComponent_Activate(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Activate;
    handleExceptionEnd
end;


procedure CEFWindowComponent_Deactivate(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Deactivate;
    handleExceptionEnd
end;


procedure CEFWindowComponent_BringToTop(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.BringToTop;
    handleExceptionEnd
end;


procedure CEFWindowComponent_Maximize(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Maximize;
    handleExceptionEnd
end;


procedure CEFWindowComponent_Minimize(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Minimize;
    handleExceptionEnd
end;


procedure CEFWindowComponent_Restore(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.Restore;
    handleExceptionEnd
end;


function CEFWindowComponent_AddOverlayView(TObj: TCEFWindowComponent; const view: ICefView; docking_mode: TCefDockingMode): ICefOverlayController; extdecl;
begin
    handleExceptionBegin
    Result := TObj.AddOverlayView(view, docking_mode);
    handleExceptionEnd
end;


procedure CEFWindowComponent_ShowMenu(TObj: TCEFWindowComponent; const menu_model: ICefMenuModel; const screen_point: TCefPoint; anchor_position : TCefMenuAnchorPosition); extdecl;
begin
    handleExceptionBegin
    TObj.ShowMenu(menu_model, screen_point, anchor_position);
    handleExceptionEnd
end;


procedure CEFWindowComponent_CancelMenu(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.CancelMenu;
    handleExceptionEnd
end;


procedure CEFWindowComponent_SetDraggableRegions(TObj: TCEFWindowComponent; regionsCount: NativeUInt; const regions: PCefDraggableRegionArray); extdecl;
begin
    handleExceptionBegin
    TObj.SetDraggableRegions(regionsCount, regions);
    handleExceptionEnd
end;


procedure CEFWindowComponent_SendKeyPress(TObj: TCEFWindowComponent; key_code: Integer; event_flags: cardinal); extdecl;
begin
    handleExceptionBegin
    TObj.SendKeyPress(key_code, event_flags);
    handleExceptionEnd
end;


procedure CEFWindowComponent_SendMouseMove(TObj: TCEFWindowComponent; screen_x, screen_y: Integer); extdecl;
begin
    handleExceptionBegin
    TObj.SendMouseMove(screen_x, screen_y);
    handleExceptionEnd
end;


procedure CEFWindowComponent_SendMouseEvents(TObj: TCEFWindowComponent; button: TCefMouseButtonType; mouse_down, mouse_up: boolean); extdecl;
begin
    handleExceptionBegin
    TObj.SendMouseEvents(button, mouse_down, mouse_up);
    handleExceptionEnd
end;


procedure CEFWindowComponent_SetAccelerator(TObj: TCEFWindowComponent; command_id, key_code : Integer; shift_pressed, ctrl_pressed, alt_pressed: boolean); extdecl;
begin
    handleExceptionBegin
    TObj.SetAccelerator(command_id, key_code, shift_pressed, ctrl_pressed, alt_pressed);
    handleExceptionEnd
end;


procedure CEFWindowComponent_RemoveAccelerator(TObj: TCEFWindowComponent; command_id: Integer); extdecl;
begin
    handleExceptionBegin
    TObj.RemoveAccelerator(command_id);
    handleExceptionEnd
end;


procedure CEFWindowComponent_RemoveAllAccelerators(TObj: TCEFWindowComponent); extdecl;
begin
    handleExceptionBegin
    TObj.RemoveAllAccelerators;
    handleExceptionEnd
end;

//property
procedure CEFWindowComponent_SetTitle(TObj: TCEFWindowComponent; PTitle: PChar); extdecl;
begin
    handleExceptionBegin
    TObj.Title := PCharToUstr(PTitle);
    handleExceptionEnd
end;

function CEFWindowComponent_Title(TObj: TCEFWindowComponent): PChar; extdecl;
begin
    handleExceptionBegin
    Result := PChar(string(TObj.Title));
    handleExceptionEnd
end;

procedure CEFWindowComponent_WindowIcon(TObj: TCEFWindowComponent; out ret: ICefImage); extdecl;
begin
    handleExceptionBegin
    ret := TObj.WindowIcon;
    handleExceptionEnd
end;

procedure CEFWindowComponent_WindowAppIcon(TObj: TCEFWindowComponent; out ret: ICefImage); extdecl;
begin
    handleExceptionBegin
    ret := TObj.WindowAppIcon;
    handleExceptionEnd
end;

procedure CEFWindowComponent_Display(TObj: TCEFWindowComponent; out ret: ICefDisplay); extdecl;
begin
    handleExceptionBegin
    ret := TObj.Display;
    handleExceptionEnd
end;

function CEFWindowComponent_ClientAreaBoundsInScreen(TObj: TCEFWindowComponent): TCefRect; extdecl;
begin
    handleExceptionBegin
    Result := TObj.ClientAreaBoundsInScreen;
    handleExceptionEnd
end;

function CEFWindowComponent_WindowHandle(TObj: TCEFWindowComponent): TCefWindowHandle; extdecl;
begin
    handleExceptionBegin
    Result := TObj.WindowHandle;
    handleExceptionEnd
end;

function CEFWindowComponent_IsClosed(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsClosed;
    handleExceptionEnd
end;

function CEFWindowComponent_IsActive(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsActive;
    handleExceptionEnd
end;

function CEFWindowComponent_IsAlwaysOnTop(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsAlwaysOnTop;
    handleExceptionEnd
end;

function CEFWindowComponent_IsFullscreen(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsFullscreen;
    handleExceptionEnd
end;

function CEFWindowComponent_IsMaximized(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsMaximized;
    handleExceptionEnd
end;

function CEFWindowComponent_IsMinimized(TObj: TCEFWindowComponent): LongBool; extdecl;
begin
    handleExceptionBegin
    Result := TObj.IsMinimized;
    handleExceptionEnd
end;

procedure CEFWindowComponent_NIL();
begin
    //handleExceptionBegin
    //没搞懂，要加一个空函数编译才不报错
    //handleExceptionEnd
end;


//event
procedure CEFWindowComponent_SetOnWindowCreated(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnWindowCreated}
    {$DEFINE EventName := OnWindowCreated}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowDestroyed(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnWindowDestroyed}
    {$DEFINE EventName := OnWindowDestroyed}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnWindowActivationChanged(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnWindowActivationChanged}
    {$DEFINE EventName := OnWindowActivationChanged}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetParentWindow(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnGetParentWindow}
    {$DEFINE EventName := OnGetParentWindow}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetInitialBounds(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnGetInitialBounds}
    {$DEFINE EventName := OnGetInitialBounds}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnGetInitialShowState(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnGetInitialShowState}
    {$DEFINE EventName := OnGetInitialShowState}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnIsFrameless(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnIsFrameless}
    {$DEFINE EventName := OnIsFrameless}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanResize(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnCanResize}
    {$DEFINE EventName := OnCanResize}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanMaximize(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnCanMaximize}
    {$DEFINE EventName := OnCanMaximize}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanMinimize(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnCanMinimize}
    {$DEFINE EventName := OnCanMinimize}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnCanClose(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnCanClose}
    {$DEFINE EventName := OnCanClose}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnAccelerator(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnAccelerator}
    {$DEFINE EventName := OnAccelerator}
    EventMethodCode
end;

procedure CEFWindowComponent_SetOnKeyEvent(AObj: TCEFWindowComponent; AEventData: Pointer); extdecl;
begin
    {$DEFINE EventMethodName := WindowComponent_OnKeyEvent}
    {$DEFINE EventName := OnKeyEvent}
    EventMethodCode
end;

exports
    //function
    CEFWindowComponent_Create,
    CEFWindowComponent_CreateTopLevelWindow,
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
    //property
    CEFWindowComponent_SetTitle,
    CEFWindowComponent_Title,
    CEFWindowComponent_WindowIcon,
    CEFWindowComponent_WindowAppIcon,
    CEFWindowComponent_Display,
    CEFWindowComponent_ClientAreaBoundsInScreen,
    CEFWindowComponent_WindowHandle,
    CEFWindowComponent_IsClosed,
    CEFWindowComponent_IsActive,
    CEFWindowComponent_IsAlwaysOnTop,
    CEFWindowComponent_IsFullscreen,
    CEFWindowComponent_IsMaximized,
    CEFWindowComponent_IsMinimized,
    //event
    CEFWindowComponent_SetOnWindowCreated,
    CEFWindowComponent_SetOnWindowDestroyed,
    CEFWindowComponent_SetOnWindowActivationChanged,
    CEFWindowComponent_SetOnGetParentWindow,
    CEFWindowComponent_SetOnGetInitialBounds,
    CEFWindowComponent_SetOnGetInitialShowState,
    CEFWindowComponent_SetOnIsFrameless,
    CEFWindowComponent_SetOnCanResize,
    CEFWindowComponent_SetOnCanMaximize,
    CEFWindowComponent_SetOnCanMinimize,
    CEFWindowComponent_SetOnCanClose,
    CEFWindowComponent_SetOnAccelerator,
    CEFWindowComponent_SetOnKeyEvent
;
