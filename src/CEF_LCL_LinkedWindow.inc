//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

//创建 TCEFLinkedWindowParent
function CEFLinkedWindow_Create(AOwner: TComponent): TCEFLinkedWindowParent; extdecl;
begin
  handleExceptionBegin
  Result := TCEFLinkedWindowParent.Create(AOwner);
  Result.Width := 300;
  Result.Height := 300;
  Result.Align := alNone; //default
  handleExceptionEnd
end;

//设置 CEFLinkedWindow_SetParent
procedure CEFLinkedWindow_SetParent(AObj: TCEFLinkedWindowParent; AValue: TWinControl); extdecl;
begin
  handleExceptionBegin
  AObj.Parent := AValue;
  handleExceptionEnd
end;

//设置 CEFLinkedWindow_SetChromium
procedure CEFLinkedWindow_SetChromium(AObj: TCEFLinkedWindowParent; Chromium: TChromium; Tag: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Chromium := Chromium;
  AObj.Tag := Int64(Tag);
  handleExceptionEnd
end;

//设置 CEFLinkedWindow_SetAlign
procedure CEFLinkedWindow_SetAlign(AObj: TCEFLinkedWindowParent; AValue: TAlign); extdecl;
begin
  handleExceptionBegin
  AObj.Align := AValue;
  handleExceptionEnd
end;

//获取 CEFLinkedWindow_GetAlign
function CEFLinkedWindow_GetAlign(AObj: TCEFLinkedWindowParent): TAlign; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Align;
  handleExceptionEnd
end;

//Get 锚点定位
function CEFLinkedWindow_GetAnchors(AObj: TCEFLinkedWindowParent): TAnchors; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Anchors;
  handleExceptionEnd
end;

//Set 锚点定位
procedure CEFLinkedWindow_SetAnchors(AObj: TCEFLinkedWindowParent; AValue: TAnchors); extdecl;
begin
  handleExceptionBegin
  AObj.Anchors := AValue;
  handleExceptionEnd
end;

//Get 句柄
function CEFLinkedWindow_GetHandle(AObj: TCEFLinkedWindowParent): HWND; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Handle;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetVisible(AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Visible;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetVisible(AObj: TCEFLinkedWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Visible := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetEnabled(AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Enabled;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetEnabled(AObj: TCEFLinkedWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Enabled := AValue;
  handleExceptionEnd
end;

//UpdateSize
procedure CEFLinkedWindow_UpdateSize(AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.UpdateSize;
  handleExceptionEnd
end;

//CEFLinkedWindow_Free
procedure CEFLinkedWindow_Free(AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetWidth(AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Width;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetWidth(AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Width := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetHeight(AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Height;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetHeight(AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetTop(AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Top;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetTop(AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Top := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetLeft(AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Left;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetLeft(AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Left := AValue;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_GetBoundsRect(AObj: TCEFLinkedWindowParent; var Result: TRect); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.BoundsRect;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetBoundsRect(AObj: TCEFLinkedWindowParent; var AValue: TRect); extdecl;
begin
  handleExceptionBegin
  AObj.BoundsRect := AValue;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetName(AObj: TCEFLinkedWindowParent; PName: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Name := string(PName);
  handleExceptionEnd
end;

function CEFLinkedWindow_GetName(AObj: TCEFLinkedWindowParent): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.Name);
  handleExceptionEnd
end;

function CEFLinkedWindow_HandleAllocated(AObj: TCEFLinkedWindowParent): boolean; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HandleAllocated;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_CreateHandle(AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.CreateHandle;
  handleExceptionEnd
end;

function CEFLinkedWindow_DestroyChildWindow(AObj: TCEFLinkedWindowParent): boolean; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DestroyChildWindow;
  handleExceptionEnd
end;


//EVENT_TYPE:LinkedWindowEventOnEnter
procedure CEFLinkedWindow_OnEnter(AObj: TCEFLinkedWindowParent; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := CEFWindowEvent_OnEnter}
  {$DEFINE EventName := OnEnter}
  EventMethodCode
end;

//EVENT_TYPE:LinkedWindowEventOnExit
procedure CEFLinkedWindow_OnExit(AObj: TCEFLinkedWindowParent; AEventId: NativeUInt); extdecl;
begin
  {$DEFINE EventMethodName := CEFWindowEvent_OnExit}
  {$DEFINE EventName := OnExit}
  EventMethodCode
end;

exports
  CEFLinkedWindow_Create,
  CEFLinkedWindow_SetName,
  CEFLinkedWindow_GetName,
  CEFLinkedWindow_SetParent,
  CEFLinkedWindow_SetChromium,
  CEFLinkedWindow_GetAlign,
  CEFLinkedWindow_SetAlign,
  CEFLinkedWindow_GetAnchors,
  CEFLinkedWindow_SetAnchors,
  CEFLinkedWindow_GetHandle,
  CEFLinkedWindow_UpdateSize,
  CEFLinkedWindow_Free,
  CEFLinkedWindow_GetVisible,
  CEFLinkedWindow_SetVisible,
  CEFLinkedWindow_GetEnabled,
  CEFLinkedWindow_SetEnabled,
  CEFLinkedWindow_GetWidth,
  CEFLinkedWindow_SetWidth,
  CEFLinkedWindow_GetHeight,
  CEFLinkedWindow_SetHeight,
  CEFLinkedWindow_GetTop,
  CEFLinkedWindow_SetTop,
  CEFLinkedWindow_GetLeft,
  CEFLinkedWindow_SetLeft,
  CEFLinkedWindow_GetBoundsRect,
  CEFLinkedWindow_SetBoundsRect,
  CEFLinkedWindow_HandleAllocated,
  CEFLinkedWindow_CreateHandle,
  CEFLinkedWindow_DestroyChildWindow,
  CEFLinkedWindow_OnEnter,
  CEFLinkedWindow_OnExit
;
