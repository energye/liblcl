
//constructor
function OpenGLControl_Create(TheOwner: TComponent): TOpenGLControl; extdecl;
begin
  handleExceptionBegin
  Result := TOpenGLControl.Create(TheOwner);
  handleExceptionEnd
end;

//function
function OpenGLControl_Class(): TClass; extdecl;
begin
  Result := TOpenGLControl;
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
  OpenGLControl_SetOnMouseWheelUp;
