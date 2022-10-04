//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//创建 TCEFWindowParent
function CEFWindow_Create(AOwner: TComponent): TCEFWindowParent; extdecl;
begin
  handleExceptionBegin
  Result := TCEFWindowParent.Create(AOwner);
  Result.Width := 300;
  Result.Height := 300;
  Result.Align := alNone; //default
  handleExceptionEnd
end;

//设置 CEFWindow_SetParent
procedure CEFWindow_SetParent(AObj: TCEFWindowParent; AValue: TWinControl); extdecl;
begin
  handleExceptionBegin
  AObj.Parent := AValue;
  handleExceptionEnd
end;

//设置 CEFWindow_SetAlign
procedure CEFWindow_SetAlign(AObj: TCEFWindowParent; AValue: TAlign); extdecl;
begin
  handleExceptionBegin
  AObj.Align := AValue;
  handleExceptionEnd
end;

//获取 CEFWindow_GetAlign
function CEFWindow_GetAlign(AObj: TCEFWindowParent): TAlign; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Align;
  handleExceptionEnd
end;

//Get 锚点定位
function CEFWindow_GetAnchors(AObj: TCEFWindowParent): TAnchors; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Anchors;
  handleExceptionEnd
end;

//Set 锚点定位
procedure CEFWindow_SetAnchors(AObj: TCEFWindowParent; AValue: TAnchors); extdecl;
begin
  handleExceptionBegin
  AObj.Anchors := AValue;
  handleExceptionEnd
end;

//Get 句柄
function CEFWindow_GetHandle(AObj: TCEFWindowParent): HWND; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Handle;
  handleExceptionEnd
end;

function CEFWindow_GetVisible(AObj: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Visible;
  handleExceptionEnd
end;

procedure CEFWindow_SetVisible(AObj: TCEFWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Visible := AValue;
  handleExceptionEnd
end;

function CEFWindow_GetEnabled(AObj: TCEFWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Enabled;
  handleExceptionEnd
end;

procedure CEFWindow_SetEnabled(AObj: TCEFWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Enabled := AValue;
  handleExceptionEnd
end;

//UpdateSize
procedure CEFWindow_UpdateSize(AObj: TCEFWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.UpdateSize;
  handleExceptionEnd
end;

//CEFWindow_Free
procedure CEFWindow_Free(AObj: TCEFWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

function CEFWindow_GetWidth(AObj: TCEFWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Width;
  handleExceptionEnd
end;

procedure CEFWindow_SetWidth(AObj: TCEFWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Width := AValue;
  handleExceptionEnd
end;

function CEFWindow_GetHeight(AObj: TCEFWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Height;
  handleExceptionEnd
end;

procedure CEFWindow_SetHeight(AObj: TCEFWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

function CEFWindow_GetTop(AObj: TCEFWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Top;
  handleExceptionEnd
end;

procedure CEFWindow_SetTop(AObj: TCEFWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Top := AValue;
  handleExceptionEnd
end;

function CEFWindow_GetLeft(AObj: TCEFWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Left;
  handleExceptionEnd
end;

procedure CEFWindow_SetLeft(AObj: TCEFWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Left := AValue;
  handleExceptionEnd
end;

procedure CEFWindow_GetBoundsRect(AObj: TCEFWindowParent; var Result: TRect); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.BoundsRect;
  handleExceptionEnd
end;

procedure CEFWindow_SetBoundsRect(AObj: TCEFWindowParent; var AValue: TRect); extdecl;
begin
  handleExceptionBegin
  AObj.BoundsRect := AValue;
  handleExceptionEnd
end;

procedure CEFWindow_SetName(AObj: TCEFWindowParent; PName: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Name := string(PName);
  handleExceptionEnd
end;

function CEFWindow_GetName(AObj: TCEFWindowParent): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.Name);
  handleExceptionEnd
end;

function CEFWindow_HandleAllocated(AObj: TCEFWindowParent): boolean ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HandleAllocated;
  //ConsoleLn('CEFWindow_HandleAllocated: '+BoolToStr(Result));
  handleExceptionEnd
end;

procedure CEFWindow_CreateHandle(AObj: TCEFWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.CreateHandle;
  handleExceptionEnd
end;

function CEFWindow_DestroyChildWindow(AObj: TCEFWindowParent): boolean; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DestroyChildWindow;
  handleExceptionEnd
end;

//EVENT_TYPE:WindowEventOnEnter
procedure CEFWindow_OnEnter(AObj: TCEFWindowParent; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := CEFWindowEvent_OnEnter}
  {$DEFINE EventName := OnEnter}
  EventMethodCode
end;

//EVENT_TYPE:WindowEventOnExit
procedure CEFWindow_OnExit(AObj: TCEFWindowParent; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := CEFWindowEvent_OnExit}
  {$DEFINE EventName := OnExit}
  EventMethodCode
end;


exports
  CEFWindow_Create,
  CEFWindow_SetName,
  CEFWindow_GetName,
  CEFWindow_SetParent,
  CEFWindow_GetAlign,
  CEFWindow_SetAlign,
  CEFWindow_GetAnchors,
  CEFWindow_SetAnchors,
  CEFWindow_GetHandle,
  CEFWindow_UpdateSize,
  CEFWindow_Free,
  CEFWindow_GetVisible,
  CEFWindow_SetVisible,
  CEFWindow_GetEnabled,
  CEFWindow_SetEnabled,
  CEFWindow_GetWidth,
  CEFWindow_SetWidth,
  CEFWindow_GetHeight,
  CEFWindow_SetHeight,
  CEFWindow_GetTop,
  CEFWindow_SetTop,
  CEFWindow_GetLeft,
  CEFWindow_SetLeft,
  CEFWindow_GetBoundsRect,
  CEFWindow_SetBoundsRect,
  CEFWindow_HandleAllocated,
  CEFWindow_CreateHandle,
  CEFWindow_DestroyChildWindow,
  CEFWindow_OnEnter,
  CEFWindow_OnExit
;
