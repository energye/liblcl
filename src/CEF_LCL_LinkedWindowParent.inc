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
procedure CEFLinkedWindow_SetParent(const AObj: TCEFLinkedWindowParent; AValue: TWinControl); extdecl;
begin
  handleExceptionBegin
  AObj.Parent := AValue;
  handleExceptionEnd
end;

//设置 CEFLinkedWindow_SetChromium
procedure CEFLinkedWindow_SetChromium(const AObj: TCEFLinkedWindowParent; Chromium: TChromium; Tag: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Chromium := Chromium;
  AObj.Tag := Int64(Tag);
  handleExceptionEnd
end;

//设置 CEFLinkedWindow_SetAlign
procedure CEFLinkedWindow_SetAlign(const AObj: TCEFLinkedWindowParent; AValue: TAlign); extdecl;
begin
  handleExceptionBegin
  AObj.Align := AValue;
  handleExceptionEnd
end;

//获取 CEFLinkedWindow_GetAlign
function CEFLinkedWindow_GetAlign(const AObj: TCEFLinkedWindowParent): TAlign; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Align;
  handleExceptionEnd
end;

//Get 锚点定位
function CEFLinkedWindow_GetAnchors(const AObj: TCEFLinkedWindowParent): TAnchors; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Anchors;
  handleExceptionEnd
end;

//Set 锚点定位
procedure CEFLinkedWindow_SetAnchors(const AObj: TCEFLinkedWindowParent; AValue: TAnchors); extdecl;
begin
  handleExceptionBegin
  AObj.Anchors := AValue;
  handleExceptionEnd
end;

//Get 句柄
function CEFLinkedWindow_GetHandle(const AObj: TCEFLinkedWindowParent): HWND; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Handle;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetVisible(const AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Visible;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetVisible(const AObj: TCEFLinkedWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Visible := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetEnabled(const AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Enabled;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetEnabled(const AObj: TCEFLinkedWindowParent; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Enabled := AValue;
  handleExceptionEnd
end;

//UpdateSize
procedure CEFLinkedWindow_UpdateSize(const AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.UpdateSize;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_Repaint(const AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.Repaint;
  handleExceptionEnd
end;

//CEFLinkedWindow_Free
procedure CEFLinkedWindow_Free(const AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetWidth(const AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Width;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetWidth(const AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Width := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetHeight(const AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Height;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetHeight(const AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetTop(const AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Top;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetTop(const AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Top := AValue;
  handleExceptionEnd
end;

function CEFLinkedWindow_GetLeft(const AObj: TCEFLinkedWindowParent): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.Left;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetLeft(const AObj: TCEFLinkedWindowParent; AValue: integer); extdecl;
begin
  handleExceptionBegin
  AObj.Left := AValue;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_GetBoundsRect(const AObj: TCEFLinkedWindowParent; var Result: TRect); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.BoundsRect;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetBoundsRect(const AObj: TCEFLinkedWindowParent; var AValue: TRect); extdecl;
begin
  handleExceptionBegin
  AObj.BoundsRect := AValue;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetName(const AObj: TCEFLinkedWindowParent; PName: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Name := string(PName);
  handleExceptionEnd
end;

function CEFLinkedWindow_GetName(const AObj: TCEFLinkedWindowParent): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.Name);
  handleExceptionEnd
end;

function CEFLinkedWindow_HandleAllocated(const AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HandleAllocated;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_CreateHandle(const AObj: TCEFLinkedWindowParent); extdecl;
begin
  handleExceptionBegin
  AObj.CreateHandle;
  handleExceptionEnd
end;

function CEFLinkedWindow_DestroyChildWindow(const AObj: TCEFLinkedWindowParent): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.DestroyChildWindow;
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetTag(const AObj: TCEFLinkedWindowParent; tag: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Tag := PtrInt(tag);
  handleExceptionEnd
end;

function CEFLinkedWindow_GetTag(const AObj: TCEFLinkedWindowParent):Integer ; extdecl;
begin
  handleExceptionBegin
  Result := Integer(AObj.Tag);
  handleExceptionEnd
end;

procedure CEFLinkedWindow_SetFocus(const AObj: TCEFLinkedWindowParent) ; extdecl;
begin
  handleExceptionBegin
  AObj.SetFocus;
  handleExceptionEnd
end;

function CEFLinkedWindow_CanFocus(const AObj: TCEFLinkedWindowParent): LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.CanFocus;
  handleExceptionEnd
end;

//EVENT_TYPE:LinkedWindowEventOnEnter
procedure CEFLinkedWindow_OnEnter(const AObj: TCEFLinkedWindowParent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := CEFWindowEvent_OnEnter}
  {$DEFINE EventName := OnEnter}
  EventMethodCode
end;

//EVENT_TYPE:LinkedWindowEventOnExit
procedure CEFLinkedWindow_OnExit(const AObj: TCEFLinkedWindowParent; AEventData: Pointer); extdecl;
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
  CEFLinkedWindow_Repaint,
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
  CEFLinkedWindow_OnExit,
  CEFLinkedWindow_SetTag,
  CEFLinkedWindow_GetTag,
  CEFLinkedWindow_SetFocus,
  CEFLinkedWindow_CanFocus;
