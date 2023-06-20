//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure BufferPanel_Create(const AOwner: TComponent; var Result: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  Result := TBufferPanel.Create(AOwner);
  handleExceptionEnd
end;

procedure BufferPanel_Free(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_CanFocus(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.CanFocus;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ContainsControl(AObj: TBufferPanel; Control: TControl): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ContainsControl(Control);
  handleExceptionEnd
end;

//CLASSMETHOD:
//PARAMS:2=nonPtr
function BufferPanel_ControlAtPos(AObj: TBufferPanel; var Pos: TPoint; AllowDisabled: LongBool; AllowWinControls: LongBool): TControl; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.ControlAtPos(Pos, AllowDisabled, AllowWinControls);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_DisableAlign(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.DisableAlign;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_EnableAlign(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.EnableAlign;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_FindChildControl(AObj: TBufferPanel; ControlName: PChar): TControl; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.FindChildControl(ControlName);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_FlipChildren(AObj: TBufferPanel; AllLevels: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.FlipChildren(AllLevels);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Focused(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Focused;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_HandleAllocated(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.HandleAllocated;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_InsertControl(AObj: TBufferPanel; AControl: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.InsertControl(AControl);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Invalidate(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Invalidate;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_PaintTo(AObj: TBufferPanel; DC: HDC; X: Integer; Y: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.PaintTo(DC, X, Y);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_RemoveControl(AObj: TBufferPanel; AControl: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.RemoveControl(AControl);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Realign(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Realign;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Repaint(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Repaint;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_ScaleBy(AObj: TBufferPanel; M: Integer; D: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ScaleBy(M, D);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_ScrollBy(AObj: TBufferPanel; DeltaX: Integer; DeltaY: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ScrollBy(DeltaX, DeltaY);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_SetBounds(AObj: TBufferPanel; ALeft: Integer; ATop: Integer; AWidth: Integer; AHeight: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetBounds(ALeft, ATop, AWidth, AHeight);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_SetFocus(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.SetFocus;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Update(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Update;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_BringToFront(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.BringToFront;
  handleExceptionEnd
end;

//CLASSMETHOD:
//RETURNISLASTPARAM:
//PARAMS:2=nonPtr
procedure BufferPanel_ClientToScreen(AObj: TBufferPanel; var Point: TPoint; var Result: TPoint); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClientToScreen(Point);
  handleExceptionEnd
end;

//CLASSMETHOD:
//RETURNISLASTPARAM:
//PARAMS:2=nonPtr
procedure BufferPanel_ClientToParent(AObj: TBufferPanel; var Point: TPoint; AParent: TWinControl; var Result: TPoint); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClientToParent(Point, AParent);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Dragging(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Dragging;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_HasParent(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.HasParent;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Hide(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Hide;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Perform(AObj: TBufferPanel; Msg: Cardinal; WParam: NativeUInt; LParam: NativeInt): NativeInt; extdecl;
begin
{$ifdef UsehandleException}Result := NativeInt(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Perform(Msg, WParam, LParam);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Refresh(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Refresh;
  handleExceptionEnd
end;

//CLASSMETHOD:
//RETURNISLASTPARAM:
//PARAMS:2=nonPtr
procedure BufferPanel_ScreenToClient(AObj: TBufferPanel; var Point: TPoint; var Result: TPoint); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ScreenToClient(Point);
  handleExceptionEnd
end;

//CLASSMETHOD:
//RETURNISLASTPARAM:
//PARAMS:2=nonPtr
procedure BufferPanel_ParentToClient(AObj: TBufferPanel; var Point: TPoint; AParent: TWinControl; var Result: TPoint); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ParentToClient(Point, AParent);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_SendToBack(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.SendToBack;
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Show(AObj: TBufferPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Show;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_GetTextBuf(AObj: TBufferPanel; Buffer: PChar; BufSize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.GetTextBuf(Buffer, BufSize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_GetTextLen(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  {$ifdef darwin}Length(AObj.Caption){$else}AObj.GetTextLen{$endif};
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_SetTextBuf(AObj: TBufferPanel; Buffer: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SetTextBuf(Buffer);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_FindComponent(AObj: TBufferPanel; AName: PChar): TComponent; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.FindComponent(AName);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_GetNamePath(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.GetNamePath);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_Assign(AObj: TBufferPanel; Source: TPersistent); extdecl;
begin
  handleExceptionBegin
  AObj.Assign(Source);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ClassType(AObj: TBufferPanel): TClass; extdecl;
begin
{$ifdef UsehandleException}Result := TClass(nil);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClassType;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ClassName(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  ToPChar(AObj.ClassName);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_InstanceSize(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.InstanceSize;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_InheritsFrom(AObj: TBufferPanel; AClass: TClass): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.InheritsFrom(AClass);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Equals(AObj: TBufferPanel; Obj: TObject): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Equals(Obj);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_GetHashCode(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.GetHashCode;
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ToString(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.ToString);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorToNeighbour(AObj: TBufferPanel; ASide: TAnchorKind; ASpace: Integer; ASibling: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorToNeighbour(ASide, ASpace, ASibling);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorParallel(AObj: TBufferPanel; ASide: TAnchorKind; ASpace: Integer; ASibling: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorParallel(ASide, ASpace, ASibling);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorHorizontalCenterTo(AObj: TBufferPanel; ASibling: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorHorizontalCenterTo(ASibling);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorVerticalCenterTo(AObj: TBufferPanel; ASibling: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorVerticalCenterTo(ASibling);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorSame(AObj: TBufferPanel; ASide: TAnchorKind; ASibling: TControl); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorSame(ASide, ASibling);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorAsAlign(AObj: TBufferPanel; ATheAlign: TAlign; ASpace: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorAsAlign(ATheAlign, ASpace);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AnchorClient(AObj: TBufferPanel; ASpace: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorClient(ASpace);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleDesignToForm(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleDesignToForm(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleFormToDesign(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleFormToDesign(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Scale96ToForm(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Scale96ToForm(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleFormTo96(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleFormTo96(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Scale96ToFont(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Scale96ToFont(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleFontTo96(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleFontTo96(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleScreenToFont(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleScreenToFont(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleFontToScreen(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleFontToScreen(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_Scale96ToScreen(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Scale96ToScreen(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
function BufferPanel_ScaleScreenTo96(AObj: TBufferPanel; ASize: Integer): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ScaleScreenTo96(ASize);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_AutoAdjustLayout(AObj: TBufferPanel; AMode: TLayoutAdjustmentPolicy; AFromPPI: Integer; AToPPI: Integer; AOldFormWidth: Integer; ANewFormWidth: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.AutoAdjustLayout(AMode, AFromPPI, AToPPI, AOldFormWidth, ANewFormWidth);
  handleExceptionEnd
end;

//CLASSMETHOD:
procedure BufferPanel_FixDesignFontsPPI(AObj: TBufferPanel; ADesignTimePPI: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.FixDesignFontsPPI(ADesignTimePPI);
  handleExceptionEnd
end;

//CLASSMETHOD:
//PARAMS:3=nonPtr
procedure BufferPanel_ScaleFontsPPI(AObj: TBufferPanel; AToPPI: Integer; var AProportion: Double); extdecl;
begin
  handleExceptionBegin
  AObj.ScaleFontsPPI(AToPPI, AProportion);
  handleExceptionEnd
end;

function BufferPanel_GetCanvas(AObj: TBufferPanel): TCanvas; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Canvas;
  handleExceptionEnd
end;

procedure BufferPanel_SetCanvas(AObj: TBufferPanel; AValue: TCanvas); extdecl;
begin
  handleExceptionBegin
  AObj.Canvas := AValue;
  handleExceptionEnd
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnPaint(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnPaint}
  EventMethodCode
end;

function BufferPanel_GetAlign(AObj: TBufferPanel): TAlign; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TAlign);{$endif}
  handleExceptionBegin
  Result :=  AObj.Align;
  handleExceptionEnd
end;

procedure BufferPanel_SetAlign(AObj: TBufferPanel; AValue: TAlign); extdecl;
begin
  handleExceptionBegin
  AObj.Align := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAlignment(AObj: TBufferPanel): TAlignment; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TAlignment);{$endif}
  handleExceptionBegin
  Result :=  AObj.Alignment;
  handleExceptionEnd
end;

procedure BufferPanel_SetAlignment(AObj: TBufferPanel; AValue: TAlignment); extdecl;
begin
  handleExceptionBegin
  AObj.Alignment := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAnchors(AObj: TBufferPanel): TAnchors; extdecl;
begin
{$ifdef UsehandleException}Result := [];{$endif}
  handleExceptionBegin
  Result :=  AObj.Anchors;
  handleExceptionEnd
end;

procedure BufferPanel_SetAnchors(AObj: TBufferPanel; AValue: TAnchors); extdecl;
begin
  handleExceptionBegin
  AObj.Anchors := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAutoSize(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.AutoSize;
  handleExceptionEnd
end;

procedure BufferPanel_SetAutoSize(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.AutoSize := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBevelInner(AObj: TBufferPanel): TBevelCut; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TBevelCut);{$endif}
  handleExceptionBegin
  Result :=  AObj.BevelInner;
  handleExceptionEnd
end;

procedure BufferPanel_SetBevelInner(AObj: TBufferPanel; AValue: TBevelCut); extdecl;
begin
  handleExceptionBegin
  AObj.BevelInner := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBevelOuter(AObj: TBufferPanel): TBevelCut; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TBevelCut);{$endif}
  handleExceptionBegin
  Result :=  AObj.BevelOuter;
  handleExceptionEnd
end;

procedure BufferPanel_SetBevelOuter(AObj: TBufferPanel; AValue: TBevelCut); extdecl;
begin
  handleExceptionBegin
  AObj.BevelOuter := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBiDiMode(AObj: TBufferPanel): TBiDiMode; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TBiDiMode);{$endif}
  handleExceptionBegin
  Result :=  AObj.BiDiMode;
  handleExceptionEnd
end;

procedure BufferPanel_SetBiDiMode(AObj: TBufferPanel; AValue: TBiDiMode); extdecl;
begin
  handleExceptionBegin
  AObj.BiDiMode := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBorderWidth(AObj: TBufferPanel): TBorderWidth; extdecl;
begin
{$ifdef UsehandleException}Result := TBorderWidth(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.BorderWidth;
  handleExceptionEnd
end;

procedure BufferPanel_SetBorderWidth(AObj: TBufferPanel; AValue: TBorderWidth); extdecl;
begin
  handleExceptionBegin
  AObj.BorderWidth := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBorderStyle(AObj: TBufferPanel): TBorderStyle; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TBorderStyle);{$endif}
  handleExceptionBegin
  Result :=  AObj.BorderStyle;
  handleExceptionEnd
end;

procedure BufferPanel_SetBorderStyle(AObj: TBufferPanel; AValue: TBorderStyle); extdecl;
begin
  handleExceptionBegin
  AObj.BorderStyle := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetCaption(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.Caption);
  handleExceptionEnd
end;

procedure BufferPanel_SetCaption(AObj: TBufferPanel; AValue: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Caption := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetColor(AObj: TBufferPanel): TColor; extdecl;
begin
{$ifdef UsehandleException}Result := TColor(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Color;
  handleExceptionEnd
end;

procedure BufferPanel_SetColor(AObj: TBufferPanel; AValue: TColor); extdecl;
begin
  handleExceptionBegin
  AObj.Color := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetConstraints(AObj: TBufferPanel): TSizeConstraints; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Constraints;
  handleExceptionEnd
end;

procedure BufferPanel_SetConstraints(AObj: TBufferPanel; AValue: TSizeConstraints); extdecl;
begin
  handleExceptionBegin
  AObj.Constraints := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetUseDockManager(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.UseDockManager;
  handleExceptionEnd
end;

procedure BufferPanel_SetUseDockManager(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.UseDockManager := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDockSite(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.DockSite;
  handleExceptionEnd
end;

procedure BufferPanel_SetDockSite(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DockSite := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDoubleBuffered(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.DoubleBuffered;
  handleExceptionEnd
end;

procedure BufferPanel_SetDoubleBuffered(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.DoubleBuffered := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDragCursor(AObj: TBufferPanel): TCursor; extdecl;
begin
{$ifdef UsehandleException}Result := TCursor(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.DragCursor;
  handleExceptionEnd
end;

procedure BufferPanel_SetDragCursor(AObj: TBufferPanel; AValue: TCursor); extdecl;
begin
  handleExceptionBegin
  AObj.DragCursor := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDragKind(AObj: TBufferPanel): TDragKind; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TDragKind);{$endif}
  handleExceptionBegin
  Result :=  AObj.DragKind;
  handleExceptionEnd
end;

procedure BufferPanel_SetDragKind(AObj: TBufferPanel; AValue: TDragKind); extdecl;
begin
  handleExceptionBegin
  AObj.DragKind := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDragMode(AObj: TBufferPanel): TDragMode; extdecl;
begin
{$ifdef UsehandleException}Result := Low(TDragMode);{$endif}
  handleExceptionBegin
  Result :=  AObj.DragMode;
  handleExceptionEnd
end;

procedure BufferPanel_SetDragMode(AObj: TBufferPanel; AValue: TDragMode); extdecl;
begin
  handleExceptionBegin
  AObj.DragMode := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetEnabled(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Enabled;
  handleExceptionEnd
end;

procedure BufferPanel_SetEnabled(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Enabled := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetFullRepaint(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.FullRepaint;
  handleExceptionEnd
end;

procedure BufferPanel_SetFullRepaint(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.FullRepaint := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetFont(AObj: TBufferPanel): TFont; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Font;
  handleExceptionEnd
end;

procedure BufferPanel_SetFont(AObj: TBufferPanel; AValue: TFont); extdecl;
begin
  handleExceptionBegin
  AObj.Font := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetParentBackground(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentBackground;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentBackground(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ParentBackground := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetParentColor(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentColor;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentColor(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ParentColor := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetParentDoubleBuffered(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentDoubleBuffered;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentDoubleBuffered(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ParentDoubleBuffered := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetParentFont(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentFont;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentFont(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ParentFont := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetParentShowHint(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentShowHint;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentShowHint(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ParentShowHint := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetPopupMenu(AObj: TBufferPanel): TPopupMenu; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.PopupMenu;
  handleExceptionEnd
end;

procedure BufferPanel_SetPopupMenu(AObj: TBufferPanel; AValue: TPopupMenu); extdecl;
begin
  handleExceptionBegin
  AObj.PopupMenu := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetShowHint(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.ShowHint;
  handleExceptionEnd
end;

procedure BufferPanel_SetShowHint(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.ShowHint := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetTabOrder(AObj: TBufferPanel): TTabOrder; extdecl;
begin
{$ifdef UsehandleException}Result := TTabOrder(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.TabOrder;
  handleExceptionEnd
end;

procedure BufferPanel_SetTabOrder(AObj: TBufferPanel; AValue: TTabOrder); extdecl;
begin
  handleExceptionBegin
  AObj.TabOrder := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetTabStop(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.TabStop;
  handleExceptionEnd
end;

procedure BufferPanel_SetTabStop(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.TabStop := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetVisible(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Visible;
  handleExceptionEnd
end;

procedure BufferPanel_SetVisible(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Visible := AValue;
  handleExceptionEnd
end;

//EVENT_TYPE:TAlignPositionEvent
procedure BufferPanel_SetOnAlignPosition(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTAlignPositionEvent}
  {$DEFINE EventName := OnAlignPosition}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnClick(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnClick}
  EventMethodCode
end;

//EVENT_TYPE:TContextPopupEvent
procedure BufferPanel_SetOnContextPopup(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTContextPopupEvent}
  {$DEFINE EventName := OnContextPopup}
  EventMethodCode
end;

//EVENT_TYPE:TDockDropEvent
procedure BufferPanel_SetOnDockDrop(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTDockDropEvent}
  {$DEFINE EventName := OnDockDrop}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnDblClick(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnDblClick}
  EventMethodCode
end;

//EVENT_TYPE:TDragDropEvent
procedure BufferPanel_SetOnDragDrop(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTDragDropEvent}
  {$DEFINE EventName := OnDragDrop}
  EventMethodCode
end;

//EVENT_TYPE:TDragOverEvent
procedure BufferPanel_SetOnDragOver(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTDragOverEvent}
  {$DEFINE EventName := OnDragOver}
  EventMethodCode
end;

//EVENT_TYPE:TEndDragEvent
procedure BufferPanel_SetOnEndDock(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTEndDragEvent}
  {$DEFINE EventName := OnEndDock}
  EventMethodCode
end;

//EVENT_TYPE:TEndDragEvent
procedure BufferPanel_SetOnEndDrag(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTEndDragEvent}
  {$DEFINE EventName := OnEndDrag}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnEnter(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnEnter}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnExit(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnExit}
  EventMethodCode
end;

//EVENT_TYPE:TGetSiteInfoEvent
procedure BufferPanel_SetOnGetSiteInfo(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTGetSiteInfoEvent}
  {$DEFINE EventName := OnGetSiteInfo}
  EventMethodCode
end;

//EVENT_TYPE:TMouseEvent
procedure BufferPanel_SetOnMouseDown(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseDown}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnMouseEnter(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseEnter}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnMouseLeave(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnMouseLeave}
  EventMethodCode
end;

//EVENT_TYPE:TMouseMoveEvent
procedure BufferPanel_SetOnMouseMove(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseMoveEvent}
  {$DEFINE EventName := OnMouseMove}
  EventMethodCode
end;

//EVENT_TYPE:TMouseEvent
procedure BufferPanel_SetOnMouseUp(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseEvent}
  {$DEFINE EventName := OnMouseUp}
  EventMethodCode
end;

//EVENT_TYPE:TNotifyEvent
procedure BufferPanel_SetOnResize(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnResize}
  EventMethodCode
end;

//EVENT_TYPE:TStartDockEvent
procedure BufferPanel_SetOnStartDock(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTStartDockEvent}
  {$DEFINE EventName := OnStartDock}
  EventMethodCode
end;

//EVENT_TYPE:TUnDockEvent
procedure BufferPanel_SetOnUnDock(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTUnDockEvent}
  {$DEFINE EventName := OnUnDock}
  EventMethodCode
end;

function BufferPanel_GetDockClientCount(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.DockClientCount;
  handleExceptionEnd
end;

function BufferPanel_GetMouseInClient(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.MouseInClient;
  handleExceptionEnd
end;

function BufferPanel_GetVisibleDockClientCount(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.VisibleDockClientCount;
  handleExceptionEnd
end;

function BufferPanel_GetBrush(AObj: TBufferPanel): TBrush; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Brush;
  handleExceptionEnd
end;

function BufferPanel_GetControlCount(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ControlCount;
  handleExceptionEnd
end;

function BufferPanel_GetHandle(AObj: TBufferPanel): HWND; extdecl;
begin
{$ifdef UsehandleException}Result := HWND(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Handle;
  handleExceptionEnd
end;

function BufferPanel_GetParentWindow(AObj: TBufferPanel): HWND; extdecl;
begin
{$ifdef UsehandleException}Result := HWND(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ParentWindow;
  handleExceptionEnd
end;

procedure BufferPanel_SetParentWindow(AObj: TBufferPanel; AValue: HWND); extdecl;
begin
  handleExceptionBegin
  AObj.ParentWindow := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetShowing(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Showing;
  handleExceptionEnd
end;

function BufferPanel_GetAction(AObj: TBufferPanel): TBasicAction; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Action;
  handleExceptionEnd
end;

procedure BufferPanel_SetAction(AObj: TBufferPanel; AValue: TBasicAction); extdecl;
begin
  handleExceptionBegin
  AObj.Action := AValue;
  handleExceptionEnd
end;

//RETURNISLASTPARAM:
procedure BufferPanel_GetBoundsRect(AObj: TBufferPanel; var Result: TRect); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.BoundsRect;
  handleExceptionEnd
end;

//PARAMS:2=nonPtr
procedure BufferPanel_SetBoundsRect(AObj: TBufferPanel; var AValue: TRect); extdecl;
begin
  handleExceptionBegin
  AObj.BoundsRect := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetClientHeight(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClientHeight;
  handleExceptionEnd
end;

procedure BufferPanel_SetClientHeight(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ClientHeight := AValue;
  handleExceptionEnd
end;

//RETURNISLASTPARAM:
procedure BufferPanel_GetClientOrigin(AObj: TBufferPanel; var Result: TPoint); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClientOrigin;
  handleExceptionEnd
end;

//RETURNISLASTPARAM:
procedure BufferPanel_GetClientRect(AObj: TBufferPanel; var Result: TRect); extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.ClientRect;
  handleExceptionEnd
end;

function BufferPanel_GetClientWidth(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ClientWidth;
  handleExceptionEnd
end;

procedure BufferPanel_SetClientWidth(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ClientWidth := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetControlState(AObj: TBufferPanel): TControlState; extdecl;
begin
{$ifdef UsehandleException}Result := [];{$endif}
  handleExceptionBegin
  Result :=  AObj.ControlState;
  handleExceptionEnd
end;

procedure BufferPanel_SetControlState(AObj: TBufferPanel; AValue: TControlState); extdecl;
begin
  handleExceptionBegin
  AObj.ControlState := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetControlStyle(AObj: TBufferPanel): TControlStyle; extdecl;
begin
{$ifdef UsehandleException}Result := [];{$endif}
  handleExceptionBegin
  Result :=  AObj.ControlStyle;
  handleExceptionEnd
end;

procedure BufferPanel_SetControlStyle(AObj: TBufferPanel; AValue: TControlStyle); extdecl;
begin
  handleExceptionBegin
  AObj.ControlStyle := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetFloating(AObj: TBufferPanel): LongBool; extdecl;
begin
{$ifdef UsehandleException}Result := False;{$endif}
  handleExceptionBegin
  Result :=  AObj.Floating;
  handleExceptionEnd
end;

function BufferPanel_GetParent(AObj: TBufferPanel): TWinControl; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Parent;
  handleExceptionEnd
end;

procedure BufferPanel_SetParent(AObj: TBufferPanel; AValue: TWinControl); extdecl;
begin
  handleExceptionBegin
  AObj.Parent := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetLeft(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Left;
  handleExceptionEnd
end;

procedure BufferPanel_SetLeft(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Left := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetTop(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Top;
  handleExceptionEnd
end;

procedure BufferPanel_SetTop(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Top := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetWidth(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Width;
  handleExceptionEnd
end;

procedure BufferPanel_SetWidth(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Width := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetHeight(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Height;
  handleExceptionEnd
end;

procedure BufferPanel_SetHeight(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.Height := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetCursor(AObj: TBufferPanel): TCursor; extdecl;
begin
{$ifdef UsehandleException}Result := TCursor(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Cursor;
  handleExceptionEnd
end;

procedure BufferPanel_SetCursor(AObj: TBufferPanel; AValue: TCursor); extdecl;
begin
  handleExceptionBegin
  AObj.Cursor := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetHint(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.Hint);
  handleExceptionEnd
end;

procedure BufferPanel_SetHint(AObj: TBufferPanel; AValue: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Hint := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetComponentCount(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ComponentCount;
  handleExceptionEnd
end;

function BufferPanel_GetComponentIndex(AObj: TBufferPanel): Integer; extdecl;
begin
{$ifdef UsehandleException}Result := Integer(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.ComponentIndex;
  handleExceptionEnd
end;

procedure BufferPanel_SetComponentIndex(AObj: TBufferPanel; AValue: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ComponentIndex := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetOwner(AObj: TBufferPanel): TComponent; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Owner;
  handleExceptionEnd
end;

function BufferPanel_GetName(AObj: TBufferPanel): PChar; extdecl;
begin
{$ifdef UsehandleException}Result := PChar(nil);{$endif}
  handleExceptionBegin
  Result :=  PChar(AObj.Name);
  handleExceptionEnd
end;

procedure BufferPanel_SetName(AObj: TBufferPanel; AValue: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.Name := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetTag(AObj: TBufferPanel): NativeInt; extdecl;
begin
{$ifdef UsehandleException}Result := NativeInt(0);{$endif}
  handleExceptionBegin
  Result :=  AObj.Tag;
  handleExceptionEnd
end;

procedure BufferPanel_SetTag(AObj: TBufferPanel; AValue: NativeInt); extdecl;
begin
  handleExceptionBegin
  AObj.Tag := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAnchorSideLeft(AObj: TBufferPanel): TAnchorSide; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.AnchorSideLeft;
  handleExceptionEnd
end;

procedure BufferPanel_SetAnchorSideLeft(AObj: TBufferPanel; AValue: TAnchorSide); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorSideLeft := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAnchorSideTop(AObj: TBufferPanel): TAnchorSide; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.AnchorSideTop;
  handleExceptionEnd
end;

procedure BufferPanel_SetAnchorSideTop(AObj: TBufferPanel; AValue: TAnchorSide); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorSideTop := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAnchorSideRight(AObj: TBufferPanel): TAnchorSide; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.AnchorSideRight;
  handleExceptionEnd
end;

procedure BufferPanel_SetAnchorSideRight(AObj: TBufferPanel; AValue: TAnchorSide); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorSideRight := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetAnchorSideBottom(AObj: TBufferPanel): TAnchorSide; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.AnchorSideBottom;
  handleExceptionEnd
end;

procedure BufferPanel_SetAnchorSideBottom(AObj: TBufferPanel; AValue: TAnchorSide); extdecl;
begin
  handleExceptionBegin
  AObj.AnchorSideBottom := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetChildSizing(AObj: TBufferPanel): TControlChildSizing; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.ChildSizing;
  handleExceptionEnd
end;

procedure BufferPanel_SetChildSizing(AObj: TBufferPanel; AValue: TControlChildSizing); extdecl;
begin
  handleExceptionBegin
  AObj.ChildSizing := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetBorderSpacing(AObj: TBufferPanel): TControlBorderSpacing; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.BorderSpacing;
  handleExceptionEnd
end;

procedure BufferPanel_SetBorderSpacing(AObj: TBufferPanel; AValue: TControlBorderSpacing); extdecl;
begin
  handleExceptionBegin
  AObj.BorderSpacing := AValue;
  handleExceptionEnd
end;

function BufferPanel_GetDockClients(AObj: TBufferPanel; Index: Integer): TControl; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.DockClients[Index];
  handleExceptionEnd
end;

function BufferPanel_GetControls(AObj: TBufferPanel; Index: Integer): TControl; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Controls[Index];
  handleExceptionEnd
end;

function BufferPanel_GetComponents(AObj: TBufferPanel; AIndex: Integer): TComponent; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.Components[AIndex];
  handleExceptionEnd
end;

function BufferPanel_GetAnchorSide(AObj: TBufferPanel; AKind: TAnchorKind): TAnchorSide; extdecl;
begin
{$ifdef UsehandleException}Result := nil;{$endif}
  handleExceptionBegin
  Result :=  AObj.AnchorSide[AKind];
  handleExceptionEnd
end;

function BufferPanel_StaticClassType: TClass; extdecl;
begin
  Result := TBufferPanel;
end;

// add new

function BufferPanel_GetTransparent(AObj: TBufferPanel): LongBool; extdecl;
begin
  handleExceptionBegin
  Result :=  AObj.Transparent;
  handleExceptionEnd
end;

procedure BufferPanel_SetTransparent(AObj: TBufferPanel; AValue: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.Transparent := AValue;
  handleExceptionEnd
end;

function    BufferPanel_SaveToFile(AObj: TBufferPanel; const PFilename : PChar) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SaveToFile(StrPas(PFilename));
  handleExceptionEnd
end;

function    BufferPanel_InvalidatePanel(AObj: TBufferPanel) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.InvalidatePanel;
  handleExceptionEnd
end;

function    BufferPanel_BeginBufferDraw(AObj: TBufferPanel)  : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BeginBufferDraw;
  handleExceptionEnd
end;

procedure   BufferPanel_EndBufferDraw(AObj: TBufferPanel) ; extdecl;
begin
  handleExceptionBegin
  AObj.EndBufferDraw;
  handleExceptionEnd
end;

procedure   BufferPanel_BufferDrawPoint(AObj: TBufferPanel; x, y : integer; const aBitmap : TBitmap); extdecl;
begin
  handleExceptionBegin
  AObj.BufferDraw(x, y, aBitmap);
  handleExceptionEnd
end;

procedure   BufferPanel_BufferDrawRect(AObj: TBufferPanel; const aBitmap : TBitmap; const aSrcRect, aDstRect : TRect); extdecl;
begin
  handleExceptionBegin
  AObj.BufferDraw(aBitmap, aSrcRect, aDstRect);
  handleExceptionEnd
end;

function    BufferPanel_UpdateBufferDimensions(AObj: TBufferPanel; aWidth, aHeight : integer) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.UpdateBufferDimensions(aWidth, aHeight);
  handleExceptionEnd
end;

function    BufferPanel_UpdateOrigBufferDimensions(AObj: TBufferPanel; aWidth, aHeight : integer) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.UpdateOrigBufferDimensions(aWidth, aHeight);
  handleExceptionEnd
end;

function    BufferPanel_UpdateOrigPopupBufferDimensions(AObj: TBufferPanel; aWidth, aHeight : integer) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.UpdateOrigPopupBufferDimensions(aWidth, aHeight);
  handleExceptionEnd
end;

procedure   BufferPanel_UpdateDeviceScaleFactor(AObj: TBufferPanel) ; extdecl;
begin
  handleExceptionBegin
  AObj.UpdateDeviceScaleFactor;
  handleExceptionEnd
end;

function    BufferPanel_BufferIsResized(AObj: TBufferPanel; aUseMutex : LongBool) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferIsResized(aUseMutex);
  handleExceptionEnd
end;

procedure   BufferPanel_CreateIMEHandler(AObj: TBufferPanel) ; extdecl;
begin
  handleExceptionBegin
  AObj.CreateIMEHandler();
  handleExceptionEnd
end;

procedure   BufferPanel_ChangeCompositionRange(AObj: TBufferPanel; const selection_range : TCefRange; const character_bounds : TCefRectDynArray); extdecl;
begin
  handleExceptionBegin
  AObj.ChangeCompositionRange(selection_range, character_bounds);
  handleExceptionEnd
end;

procedure   BufferPanel_DrawOrigPopupBuffer(AObj: TBufferPanel; const aSrcRect, aDstRect : TRect); extdecl;
begin
  handleExceptionBegin
  AObj.DrawOrigPopupBuffer(aSrcRect, aDstRect);
  handleExceptionEnd
end;

function    BufferPanel_ScanlineSize(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ScanlineSize;
  handleExceptionEnd
end;

function    BufferPanel_BufferWidth(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferWidth;
  handleExceptionEnd
end;

function    BufferPanel_BufferHeight(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferHeight;
  handleExceptionEnd
end;

function    BufferPanel_BufferBits(AObj: TBufferPanel) : pointer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.BufferBits;
  handleExceptionEnd
end;

procedure    BufferPanel_ScreenScale(AObj: TBufferPanel; out Result: Single); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ScreenScale;
  handleExceptionEnd
end;

procedure    BufferPanel_GetForcedDeviceScaleFactor(AObj: TBufferPanel; out Result: Single); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ForcedDeviceScaleFactor;
  handleExceptionEnd
end;

procedure   BufferPanel_SetForcedDeviceScaleFactor(AObj: TBufferPanel; Value: PSingle); extdecl;
begin
  handleExceptionBegin
  AObj.ForcedDeviceScaleFactor := Single(Value^);
  handleExceptionEnd
end;

function    BufferPanel_GetMustInitBuffer(AObj: TBufferPanel) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.MustInitBuffer;
  handleExceptionEnd
end;

procedure    BufferPanel_SetMustInitBuffer(AObj: TBufferPanel; Value: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.MustInitBuffer := Value;
  handleExceptionEnd
end;

procedure    BufferPanel_Buffer(AObj: TBufferPanel; out Result: TBitmap); extdecl;
begin
  handleExceptionBegin
  Result := AObj.Buffer;
  handleExceptionEnd
end;

procedure    BufferPanel_OrigBuffer(AObj: TBufferPanel; out Result: TCEFBitmapBitBuffer); extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigBuffer;
  handleExceptionEnd
end;

function    BufferPanel_OrigBufferWidth(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigBufferWidth;
  handleExceptionEnd
end;

function    BufferPanel_OrigBufferHeight(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigBufferHeight;
  handleExceptionEnd
end;

procedure    BufferPanel_OrigPopupBuffer(AObj: TBufferPanel; out Result: TCEFBitmapBitBuffer); extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigPopupBuffer;
  handleExceptionEnd
end;

function    BufferPanel_OrigPopupBufferWidth(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigPopupBufferWidth;
  handleExceptionEnd
end;

function    BufferPanel_OrigPopupBufferHeight(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigPopupBufferHeight;
  handleExceptionEnd
end;

function    BufferPanel_OrigPopupBufferBits(AObj: TBufferPanel) : pointer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigPopupBufferBits;
  handleExceptionEnd
end;

function    BufferPanel_OrigPopupScanlineSize(AObj: TBufferPanel) : integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.OrigPopupScanlineSize;
  handleExceptionEnd
end;

{$IFDEF MSWINDOWS}
procedure BufferPanel_SetOnIMECancelComposition(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnIMECancelComposition}
  {$DEFINE EventName := OnIMECancelComposition}
  EventMethodCode
end;

procedure BufferPanel_SetOnIMECommitText(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnIMECommitText}
  {$DEFINE EventName := OnIMECommitText}
  EventMethodCode
end;

procedure BufferPanel_SetOnIMESetComposition(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnIMESetComposition}
  {$DEFINE EventName := OnIMESetComposition}
  EventMethodCode
end;

procedure BufferPanel_SetOnCustomTouch(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnCustomTouch}
  {$DEFINE EventName := OnCustomTouch}
  EventMethodCode
end;

procedure BufferPanel_SetOnPointerDown(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnPointerDown}
  {$DEFINE EventName := OnPointerDown}
  EventMethodCode
end;

procedure BufferPanel_SetOnPointerUp(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnPointerUp}
  {$DEFINE EventName := OnPointerUp}
  EventMethodCode
end;

procedure BufferPanel_SetOnPointerUpdate(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnPointerUpdate}
  {$DEFINE EventName := OnPointerUpdate}
  EventMethodCode
end;
{$ENDIF}

procedure BufferPanel_SetOnPaintParentBkg(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := BufferPanel_OnPaintParentBkg}
  {$DEFINE EventName := OnPaintParentBkg}
  EventMethodCode
end;

procedure BufferPanel_SetOnMouseWheel(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTMouseWheelEvent}
  {$DEFINE EventName := OnMouseWheel}
  EventMethodCode
end;

procedure BufferPanel_SetOnKeyDown(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyEvent}
  {$DEFINE EventName := OnKeyDown}
  EventMethodCode
end;

procedure BufferPanel_SetOnKeyUp(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyEvent}
  {$DEFINE EventName := OnKeyUp}
  EventMethodCode
end;

procedure BufferPanel_SetOnKeyPress(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTKeyPressEvent}
  {$DEFINE EventName := OnKeyPress}
  EventMethodCode
end;

procedure BufferPanel_SetOnUTF8KeyPress(AObj: TBufferPanel; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTUTF8KeyPressEvent}
  {$DEFINE EventName := OnUTF8KeyPress}
  EventMethodCode
end;

exports
  BufferPanel_Create,
  BufferPanel_Free,
  BufferPanel_CanFocus,
  BufferPanel_ContainsControl,
  BufferPanel_ControlAtPos,
  BufferPanel_DisableAlign,
  BufferPanel_EnableAlign,
  BufferPanel_FindChildControl,
  BufferPanel_FlipChildren,
  BufferPanel_Focused,
  BufferPanel_HandleAllocated,
  BufferPanel_InsertControl,
  BufferPanel_Invalidate,
  BufferPanel_PaintTo,
  BufferPanel_RemoveControl,
  BufferPanel_Realign,
  BufferPanel_Repaint,
  BufferPanel_ScaleBy,
  BufferPanel_ScrollBy,
  BufferPanel_SetBounds,
  BufferPanel_SetFocus,
  BufferPanel_Update,
  BufferPanel_BringToFront,
  BufferPanel_ClientToScreen,
  BufferPanel_ClientToParent,
  BufferPanel_Dragging,
  BufferPanel_HasParent,
  BufferPanel_Hide,
  BufferPanel_Perform,
  BufferPanel_Refresh,
  BufferPanel_ScreenToClient,
  BufferPanel_ParentToClient,
  BufferPanel_SendToBack,
  BufferPanel_Show,
  BufferPanel_GetTextBuf,
  BufferPanel_GetTextLen,
  BufferPanel_SetTextBuf,
  BufferPanel_FindComponent,
  BufferPanel_GetNamePath,
  BufferPanel_Assign,
  BufferPanel_ClassType,
  BufferPanel_ClassName,
  BufferPanel_InstanceSize,
  BufferPanel_InheritsFrom,
  BufferPanel_Equals,
  BufferPanel_GetHashCode,
  BufferPanel_ToString,
  BufferPanel_AnchorToNeighbour,
  BufferPanel_AnchorParallel,
  BufferPanel_AnchorHorizontalCenterTo,
  BufferPanel_AnchorVerticalCenterTo,
  BufferPanel_AnchorSame,
  BufferPanel_AnchorAsAlign,
  BufferPanel_AnchorClient,
  BufferPanel_ScaleDesignToForm,
  BufferPanel_ScaleFormToDesign,
  BufferPanel_Scale96ToForm,
  BufferPanel_ScaleFormTo96,
  BufferPanel_Scale96ToFont,
  BufferPanel_ScaleFontTo96,
  BufferPanel_ScaleScreenToFont,
  BufferPanel_ScaleFontToScreen,
  BufferPanel_Scale96ToScreen,
  BufferPanel_ScaleScreenTo96,
  BufferPanel_AutoAdjustLayout,
  BufferPanel_FixDesignFontsPPI,
  BufferPanel_ScaleFontsPPI,
  BufferPanel_GetCanvas,
  BufferPanel_SetCanvas,
  BufferPanel_SetOnPaint,
  BufferPanel_GetAlign,
  BufferPanel_SetAlign,
  BufferPanel_GetAlignment,
  BufferPanel_SetAlignment,
  BufferPanel_GetAnchors,
  BufferPanel_SetAnchors,
  BufferPanel_GetAutoSize,
  BufferPanel_SetAutoSize,
  BufferPanel_GetBevelInner,
  BufferPanel_SetBevelInner,
  BufferPanel_GetBevelOuter,
  BufferPanel_SetBevelOuter,
  BufferPanel_GetBiDiMode,
  BufferPanel_SetBiDiMode,
  BufferPanel_GetBorderWidth,
  BufferPanel_SetBorderWidth,
  BufferPanel_GetBorderStyle,
  BufferPanel_SetBorderStyle,
  BufferPanel_GetCaption,
  BufferPanel_SetCaption,
  BufferPanel_GetColor,
  BufferPanel_SetColor,
  BufferPanel_GetConstraints,
  BufferPanel_SetConstraints,
  BufferPanel_GetUseDockManager,
  BufferPanel_SetUseDockManager,
  BufferPanel_GetDockSite,
  BufferPanel_SetDockSite,
  BufferPanel_GetDoubleBuffered,
  BufferPanel_SetDoubleBuffered,
  BufferPanel_GetDragCursor,
  BufferPanel_SetDragCursor,
  BufferPanel_GetDragKind,
  BufferPanel_SetDragKind,
  BufferPanel_GetDragMode,
  BufferPanel_SetDragMode,
  BufferPanel_GetEnabled,
  BufferPanel_SetEnabled,
  BufferPanel_GetFullRepaint,
  BufferPanel_SetFullRepaint,
  BufferPanel_GetFont,
  BufferPanel_SetFont,
  BufferPanel_GetParentBackground,
  BufferPanel_SetParentBackground,
  BufferPanel_GetParentColor,
  BufferPanel_SetParentColor,
  BufferPanel_GetParentDoubleBuffered,
  BufferPanel_SetParentDoubleBuffered,
  BufferPanel_GetParentFont,
  BufferPanel_SetParentFont,
  BufferPanel_GetParentShowHint,
  BufferPanel_SetParentShowHint,
  BufferPanel_GetPopupMenu,
  BufferPanel_SetPopupMenu,
  BufferPanel_GetShowHint,
  BufferPanel_SetShowHint,
  BufferPanel_GetTabOrder,
  BufferPanel_SetTabOrder,
  BufferPanel_GetTabStop,
  BufferPanel_SetTabStop,
  BufferPanel_GetVisible,
  BufferPanel_SetVisible,
  BufferPanel_SetOnAlignPosition,
  BufferPanel_SetOnClick,
  BufferPanel_SetOnContextPopup,
  BufferPanel_SetOnDockDrop,
  BufferPanel_SetOnDblClick,
  BufferPanel_SetOnDragDrop,
  BufferPanel_SetOnDragOver,
  BufferPanel_SetOnEndDock,
  BufferPanel_SetOnEndDrag,
  BufferPanel_SetOnEnter,
  BufferPanel_SetOnExit,
  BufferPanel_SetOnGetSiteInfo,
  BufferPanel_SetOnMouseDown,
  BufferPanel_SetOnMouseEnter,
  BufferPanel_SetOnMouseLeave,
  BufferPanel_SetOnMouseMove,
  BufferPanel_SetOnMouseUp,
  BufferPanel_SetOnResize,
  BufferPanel_SetOnStartDock,
  BufferPanel_SetOnUnDock,
  BufferPanel_GetDockClientCount,
  BufferPanel_GetMouseInClient,
  BufferPanel_GetVisibleDockClientCount,
  BufferPanel_GetBrush,
  BufferPanel_GetControlCount,
  BufferPanel_GetHandle,
  BufferPanel_GetParentWindow,
  BufferPanel_SetParentWindow,
  BufferPanel_GetShowing,
  BufferPanel_GetAction,
  BufferPanel_SetAction,
  BufferPanel_GetBoundsRect,
  BufferPanel_SetBoundsRect,
  BufferPanel_GetClientHeight,
  BufferPanel_SetClientHeight,
  BufferPanel_GetClientOrigin,
  BufferPanel_GetClientRect,
  BufferPanel_GetClientWidth,
  BufferPanel_SetClientWidth,
  BufferPanel_GetControlState,
  BufferPanel_SetControlState,
  BufferPanel_GetControlStyle,
  BufferPanel_SetControlStyle,
  BufferPanel_GetFloating,
  BufferPanel_GetParent,
  BufferPanel_SetParent,
  BufferPanel_GetLeft,
  BufferPanel_SetLeft,
  BufferPanel_GetTop,
  BufferPanel_SetTop,
  BufferPanel_GetWidth,
  BufferPanel_SetWidth,
  BufferPanel_GetHeight,
  BufferPanel_SetHeight,
  BufferPanel_GetCursor,
  BufferPanel_SetCursor,
  BufferPanel_GetHint,
  BufferPanel_SetHint,
  BufferPanel_GetComponentCount,
  BufferPanel_GetComponentIndex,
  BufferPanel_SetComponentIndex,
  BufferPanel_GetOwner,
  BufferPanel_GetName,
  BufferPanel_SetName,
  BufferPanel_GetTag,
  BufferPanel_SetTag,
  BufferPanel_GetAnchorSideLeft,
  BufferPanel_SetAnchorSideLeft,
  BufferPanel_GetAnchorSideTop,
  BufferPanel_SetAnchorSideTop,
  BufferPanel_GetAnchorSideRight,
  BufferPanel_SetAnchorSideRight,
  BufferPanel_GetAnchorSideBottom,
  BufferPanel_SetAnchorSideBottom,
  BufferPanel_GetChildSizing,
  BufferPanel_SetChildSizing,
  BufferPanel_GetBorderSpacing,
  BufferPanel_SetBorderSpacing,
  BufferPanel_GetDockClients,
  BufferPanel_GetControls,
  BufferPanel_GetComponents,
  BufferPanel_GetAnchorSide,
  BufferPanel_StaticClassType,
  BufferPanel_GetTransparent,
  BufferPanel_SetTransparent,
  BufferPanel_SaveToFile,
  BufferPanel_InvalidatePanel,
  BufferPanel_BeginBufferDraw,
  BufferPanel_EndBufferDraw,
  BufferPanel_BufferDrawPoint,
  BufferPanel_BufferDrawRect,
  BufferPanel_UpdateBufferDimensions,
  BufferPanel_UpdateOrigBufferDimensions,
  BufferPanel_UpdateOrigPopupBufferDimensions,
  BufferPanel_UpdateDeviceScaleFactor,
  BufferPanel_BufferIsResized,
  BufferPanel_CreateIMEHandler,
  BufferPanel_ChangeCompositionRange,
  BufferPanel_DrawOrigPopupBuffer,
  BufferPanel_ScanlineSize,
  BufferPanel_BufferWidth,
  BufferPanel_BufferHeight,
  BufferPanel_BufferBits,
  BufferPanel_ScreenScale,
  BufferPanel_GetForcedDeviceScaleFactor,
  BufferPanel_SetForcedDeviceScaleFactor,
  BufferPanel_GetMustInitBuffer,
  BufferPanel_SetMustInitBuffer,
  BufferPanel_Buffer,
  BufferPanel_OrigBuffer,
  BufferPanel_OrigBufferWidth,
  BufferPanel_OrigBufferHeight,
  BufferPanel_OrigPopupBuffer,
  BufferPanel_OrigPopupBufferWidth,
  BufferPanel_OrigPopupBufferHeight,
  BufferPanel_OrigPopupBufferBits,
  BufferPanel_OrigPopupScanlineSize,
  // event
  {$IFDEF MSWINDOWS}
  BufferPanel_SetOnIMECancelComposition,
  BufferPanel_SetOnIMECommitText,
  BufferPanel_SetOnIMESetComposition,
  BufferPanel_SetOnCustomTouch,
  BufferPanel_SetOnPointerDown,
  BufferPanel_SetOnPointerUp,
  BufferPanel_SetOnPointerUpdate,
  {$ENDIF}
  BufferPanel_SetOnPaintParentBkg,
  BufferPanel_SetOnMouseWheel,
  BufferPanel_SetOnKeyDown,
  BufferPanel_SetOnKeyUp,
  BufferPanel_SetOnKeyPress,
  BufferPanel_SetOnUTF8KeyPress
;
