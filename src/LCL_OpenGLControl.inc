
//constructor
function OpenGLControl_Create(TheOwner: TComponent): TOpenGLControl; extdecl;
begin
  handleExceptionBegin
  Result := TOpenGLControl.Create(TheOwner);
  handleExceptionEnd
end;

//property event
procedure OpenGLControl_SetOnConstrainedResize(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTConstrainedResizeEvent}
  {$DEFINE EventName := OnConstrainedResize}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnDblClick(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnDblClick}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnDragDrop(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTDragDropEvent}
  {$DEFINE EventName := OnDragDrop}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnDragOver(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTDragOverEvent}
  {$DEFINE EventName := OnDragOver}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseDown(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseDown}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseEnter(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseEnter}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseLeave(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseLeave}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseMove(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseMoveEvent}
  {$DEFINE EventName := OnMouseMove}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseUp(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseUp}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseWheel(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseWheelEvent}
  {$DEFINE EventName := OnMouseWheel}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseWheelDown(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseWheelUpDownEvent}
  {$DEFINE EventName := OnMouseWheelDown}
  EventMethodCode
end;

//property event
procedure OpenGLControl_SetOnMouseWheelUp(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseWheelUpDownEvent}
  {$DEFINE EventName := OnMouseWheelUp}
  EventMethodCode
end;

procedure OpenGLControl_SetOnClick(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnClick}
  EventMethodCode
end;

procedure OpenGLControl_SetOnEnter(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnEnter}
  EventMethodCode
end;

procedure OpenGLControl_SetOnExit(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnExit}
  EventMethodCode
end;

procedure OpenGLControl_SetOnKeyDown(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyEvent}
  {$DEFINE EventName := OnKeyDown}
  EventMethodCode
end;

procedure OpenGLControl_SetOnKeyPress(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyPressEvent}
  {$DEFINE EventName := OnKeyPress}
  EventMethodCode
end;

procedure OpenGLControl_SetOnKeyUp(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyEvent}
  {$DEFINE EventName := OnKeyUp}
  EventMethodCode
end;

procedure OpenGLControl_SetOnResize(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnResize}
  EventMethodCode
end;

procedure OpenGLControl_SetOnUTF8KeyPress(AObj: TOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTUTF8KeyPressEvent}
  {$DEFINE EventName := OnUTF8KeyPress}
  EventMethodCode
end;


exports
  OpenGLControl_Create,
  OpenGLControl_SetOnConstrainedResize,
  OpenGLControl_SetOnDblClick,
  OpenGLControl_SetOnDragDrop,
  OpenGLControl_SetOnDragOver,
  OpenGLControl_SetOnMouseDown,
  OpenGLControl_SetOnMouseEnter,
  OpenGLControl_SetOnMouseLeave,
  OpenGLControl_SetOnMouseMove,
  OpenGLControl_SetOnMouseUp,
  OpenGLControl_SetOnMouseWheel,
  OpenGLControl_SetOnMouseWheelDown,
  OpenGLControl_SetOnMouseWheelUp,
  OpenGLControl_SetOnClick,
  OpenGLControl_SetOnEnter,
  OpenGLControl_SetOnExit,
  OpenGLControl_SetOnKeyDown,
  OpenGLControl_SetOnKeyPress,
  OpenGLControl_SetOnKeyUp,
  OpenGLControl_SetOnResize,
  OpenGLControl_SetOnUTF8KeyPress;
