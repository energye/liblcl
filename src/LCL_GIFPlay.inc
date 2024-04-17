//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------


function GIFPlay_Create(const AOwner: TComponent): TGIFPlay; extdecl;
begin
  handleExceptionBegin
  Result := TGIFPlay.Create(AOwner);
  handleExceptionEnd
end;

procedure GIFPlay_SetParent(AObj: TGIFPlay; AValue: TWinControl); extdecl;
begin
  handleExceptionBegin
  AObj.Parent := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_Free(AObj: TGIFPlay); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

procedure GIFPlay_SetColor(AObj: TGIFPlay; AValue: TColor); extdecl;
begin
  handleExceptionBegin
  AObj.Color := AValue;
  handleExceptionEnd
end;

function GIFPlay_Dragging(AObj: TGIFPlay): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Dragging;
  handleExceptionEnd
end;

procedure GIFPlay_Animate(AObj: TGIFPlay; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Animate := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_NextFrame(AObj: TGIFPlay); extdecl;
begin
  handleExceptionBegin
  AObj.NextFrame();
  handleExceptionEnd
end;

procedure GIFPlay_PriorFrame(AObj: TGIFPlay); extdecl;
begin
  handleExceptionBegin
  AObj.PriorFrame();
  handleExceptionEnd
end;

function GIFPlay_Empty(AObj: TGIFPlay): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Empty;
  handleExceptionEnd
end;

function GIFPlay_CurrentImageIndex(AObj: TGIFPlay): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CurrentImageIndex;
  handleExceptionEnd
end;

procedure GIFPlay_LoadFromFile(AObj: TGIFPlay; AValue: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.FileName := string(AValue);
  handleExceptionEnd
end;

procedure GIFPlay_LoadFromStream(AObj: TGIFPlay; AStream: TMemoryStream); extdecl;
begin
  handleExceptionBegin
  AObj.FileStream := AStream;
  handleExceptionEnd
end;

function GIFPlay_GetLeft(AObj: TGIFPlay): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Left;
  handleExceptionEnd
end;

procedure GIFPlay_SetLeft(AObj: TGIFPlay; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Left := AValue;
  handleExceptionEnd
end;

function GIFPlay_GetTop(AObj: TGIFPlay): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Top;
  handleExceptionEnd
end;

procedure GIFPlay_SetTop(AObj: TGIFPlay; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Top := AValue;
  handleExceptionEnd
end;

function GIFPlay_GetWidth(AObj: TGIFPlay): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Width;
  handleExceptionEnd
end;

procedure GIFPlay_SetWidth(AObj: TGIFPlay; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Width := AValue;
  handleExceptionEnd
end;

function GIFPlay_GetHeight(AObj: TGIFPlay): Integer; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Height;
  handleExceptionEnd
end;

procedure GIFPlay_SetHeight(AObj: TGIFPlay; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_SetBounds(AObj: TGIFPlay; ALeft: Integer; ATop: Integer; AWidth: Integer; AHeight: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetBounds(ALeft, ATop, AWidth, AHeight);
  handleExceptionEnd
end;

procedure GIFPlay_Update(AObj: TGIFPlay); extdecl;
begin
  handleExceptionBegin
  AObj.Update;
  handleExceptionEnd
end;

procedure GIFPlay_SetAlign(AObj: TGIFPlay; AValue: TAlign); extdecl;
begin
  handleExceptionBegin
  AObj.Align := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_SetAnchors(AObj: TGIFPlay; AValue: TAnchors); extdecl;
begin
  handleExceptionBegin
  AObj.Anchors := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_SetAutoSize(AObj: TGIFPlay; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AutoSize := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_SetVisible(AObj: TGIFPlay; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Visible := AValue;
  handleExceptionEnd
end;

procedure GIFPlay_SetOnClick(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnClick}
  EventMethodCode
end;

procedure GIFPlay_SetOnFrameChanged(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnFrameChanged}
  EventMethodCode
end;

procedure GIFPlay_SetOnDblClick(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnDblClick}
  EventMethodCode
end;

procedure GIFPlay_SetOnMouseDown(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseDown}
  EventMethodCode
end;

procedure GIFPlay_SetOnMouseEnter(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseEnter}
  EventMethodCode
end;

procedure GIFPlay_SetOnMouseLeave(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseLeave}
  EventMethodCode
end;

procedure GIFPlay_SetOnMouseMove(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseMoveEvent}
  {$DEFINE EventName := OnMouseMove}
  EventMethodCode
end;

procedure GIFPlay_SetOnMouseUp(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseUp}
  EventMethodCode
end;

procedure GIFPlay_SetOnStart(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnStart}
  EventMethodCode
end;

procedure GIFPlay_SetOnStop(AObj: TGIFPlay; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnStop}
  EventMethodCode
end;


exports
  GIFPlay_Create,
  GIFPlay_SetParent,
  GIFPlay_Free,
  GIFPlay_SetColor,
  GIFPlay_Dragging,
  GIFPlay_Animate,
  GIFPlay_NextFrame,
  GIFPlay_PriorFrame,
  GIFPlay_Empty,
  GIFPlay_CurrentImageIndex,
  GIFPlay_LoadFromFile,
  GIFPlay_LoadFromStream,
  GIFPlay_GetLeft,
  GIFPlay_SetLeft,
  GIFPlay_GetTop,
  GIFPlay_SetTop,
  GIFPlay_GetWidth,
  GIFPlay_SetWidth,
  GIFPlay_GetHeight,
  GIFPlay_SetHeight,
  GIFPlay_SetBounds,
  GIFPlay_Update,
  GIFPlay_SetAlign,
  GIFPlay_SetAnchors,
  GIFPlay_SetAutoSize,
  GIFPlay_SetVisible,
  GIFPlay_SetOnClick,
  GIFPlay_SetOnFrameChanged,
  GIFPlay_SetOnDblClick,
  GIFPlay_SetOnMouseDown,
  GIFPlay_SetOnMouseEnter,
  GIFPlay_SetOnMouseLeave,
  GIFPlay_SetOnMouseMove,
  GIFPlay_SetOnMouseUp,
  GIFPlay_SetOnStart,
  GIFPlay_SetOnStop
  ;
