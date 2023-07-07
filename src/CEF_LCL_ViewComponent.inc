//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  ViewComponent_Create(const AOwner: TComponent; out Result: TCEFViewComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFViewComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure  ViewComponent_Free(const AObj: TCEFViewComponent); extdecl;
begin
  handleExceptionBegin
  AObj.Free;
  handleExceptionEnd
end;

function  ViewComponent_ToStringEx(const AObj: TCEFViewComponent; include_children: LongBool): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.ToStringEx(include_children)));
  handleExceptionEnd
end;

function  ViewComponent_IsSame(const AObj: TCEFViewComponent; const that: ICefView): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSame(that);
  handleExceptionEnd
end;

procedure  ViewComponent_SizeToPreferredSize(const AObj: TCEFViewComponent); extdecl;
begin
  handleExceptionBegin
  AObj.SizeToPreferredSize;
  handleExceptionEnd
end;

procedure  ViewComponent_InvalidateLayout(const AObj: TCEFViewComponent); extdecl;
begin
  handleExceptionBegin
  AObj.InvalidateLayout;
  handleExceptionEnd
end;

procedure  ViewComponent_RequestFocus(const AObj: TCEFViewComponent); extdecl;
begin
  handleExceptionBegin
  AObj.RequestFocus;
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointToScreen(const AObj: TCEFViewComponent; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToScreen(point);
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointFromScreen(const AObj: TCEFViewComponent; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromScreen(point);
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointToWindow(const AObj: TCEFViewComponent; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToWindow(point);
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointFromWindow(const AObj: TCEFViewComponent; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromWindow(point);
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointToView(const AObj: TCEFViewComponent; const view : ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToView(view, point);
  handleExceptionEnd
end;

function  ViewComponent_ConvertPointFromView(const AObj: TCEFViewComponent; const view : ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromView(view, point);
  handleExceptionEnd
end;

function  ViewComponent_GetInitialized(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Initialized;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsView(const AObj: TCEFViewComponent; out Result: ICefView);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsView;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsBrowserView(const AObj: TCEFViewComponent; out Result: ICefBrowserView);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsBrowserView;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsButton(const AObj: TCEFViewComponent; out Result: ICefButton);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsButton;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsPanel(const AObj: TCEFViewComponent; out Result: ICefPanel);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsPanel;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsScrollView(const AObj: TCEFViewComponent; out Result: ICefScrollView);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsScrollView;
  handleExceptionEnd
end;

procedure  ViewComponent_GetAsTextfield(const AObj: TCEFViewComponent; out Result: ICefTextfield);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsTextfield;
  handleExceptionEnd
end;

procedure  ViewComponent_GetViewForID(const AObj: TCEFViewComponent; id_: Integer; out Result: ICefView);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.ViewForID[id_];
  handleExceptionEnd
end;

function  ViewComponent_GetValid(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Valid;
  handleExceptionEnd
end;

function  ViewComponent_GetAttached(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Attached;
  handleExceptionEnd
end;

procedure  ViewComponent_GetDelegate(const AObj: TCEFViewComponent; out Result: ICefViewDelegate);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Delegate;
  handleExceptionEnd
end;

procedure  ViewComponent_GetWindow(const AObj: TCEFViewComponent; out Result: ICefWindow);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Window;
  handleExceptionEnd
end;

procedure  ViewComponent_GetParentView(const AObj: TCEFViewComponent; out Result: ICefView);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.ParentView;
  handleExceptionEnd
end;

procedure  ViewComponent_GetBoundsInScreen(const AObj: TCEFViewComponent; out Result: TCefRect);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.BoundsInScreen;
  handleExceptionEnd
end;

procedure  ViewComponent_GetPreferredSize(const AObj: TCEFViewComponent; out Result: TCefSize);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.PreferredSize;
  handleExceptionEnd
end;

procedure  ViewComponent_GetMinimumSize(const AObj: TCEFViewComponent; out Result: TCefSize);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.MinimumSize;
  handleExceptionEnd
end;

procedure  ViewComponent_GetMaximumSize(const AObj: TCEFViewComponent; out Result: TCefSize);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.MaximumSize;
  handleExceptionEnd
end;

function  ViewComponent_GetVisible(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Visible;
  handleExceptionEnd
end;

procedure  ViewComponent_SetVisible(const AObj: TCEFViewComponent; visible_: LongBool);  extdecl;
begin
  handleExceptionBegin
  AObj.Visible := visible_;
  handleExceptionEnd
end;

function  ViewComponent_GetDrawn(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Drawn;
  handleExceptionEnd
end;

function  ViewComponent_GetEnabled(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Enabled;
  handleExceptionEnd
end;

procedure  ViewComponent_SetEnabled(const AObj: TCEFViewComponent; enabled_: LongBool);  extdecl;
begin
  handleExceptionBegin
  AObj.Enabled := enabled_;
  handleExceptionEnd
end;

function  ViewComponent_GetFocusable(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Focusable;
  handleExceptionEnd
end;

procedure  ViewComponent_SetFocusable(const AObj: TCEFViewComponent; focusable_: LongBool);  extdecl;
begin
  handleExceptionBegin
  AObj.Focusable := focusable_;
  handleExceptionEnd
end;

function  ViewComponent_GetAccessibilityFocusable(const AObj: TCEFViewComponent) : LongBool;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.AccessibilityFocusable;
  handleExceptionEnd
end;

procedure  ViewComponent_GetBackgroundColor(const AObj: TCEFViewComponent; out Result: TCefColor);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.BackgroundColor;
  handleExceptionEnd
end;

procedure  ViewComponent_SetBackgroundColor(const AObj: TCEFViewComponent; color: TCefColor);  extdecl;
begin
  handleExceptionBegin
  AObj.BackgroundColor := color;
  handleExceptionEnd
end;

function  ViewComponent_GetID(const AObj: TCEFViewComponent) : integer;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.ID;
  handleExceptionEnd
end;

procedure  ViewComponent_SetID(const AObj: TCEFViewComponent; id_: Integer);  extdecl;
begin
  handleExceptionBegin
  AObj.ID := id_;
  handleExceptionEnd
end;

function  ViewComponent_GetGroupID(const AObj: TCEFViewComponent) : integer;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.GroupID;
  handleExceptionEnd
end;

procedure  ViewComponent_SetGroupID(const AObj: TCEFViewComponent; group_id: Integer);  extdecl;
begin
  handleExceptionBegin
  AObj.GroupID := group_id;
  handleExceptionEnd
end;

procedure  ViewComponent_GetBounds(const AObj: TCEFViewComponent; out Result: TCefRect);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Bounds;
  handleExceptionEnd
end;

procedure  ViewComponent_SetBounds(const AObj: TCEFViewComponent; const bounds_: TCefRect);  extdecl;
begin
  handleExceptionBegin
  AObj.Bounds := bounds_;
  handleExceptionEnd
end;

procedure  ViewComponent_GetSize(const AObj: TCEFViewComponent; out Result: TCefSize);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Size;
  handleExceptionEnd
end;

procedure  ViewComponent_SetSize(const AObj: TCEFViewComponent; const size_: TCefSize);  extdecl;
begin
  handleExceptionBegin
  AObj.Size := size_;
  handleExceptionEnd
end;

procedure  ViewComponent_GetPosition(const AObj: TCEFViewComponent; out Result: TCefPoint);  extdecl;
begin
  handleExceptionBegin
  Result := AObj.Position;
  handleExceptionEnd
end;

procedure  ViewComponent_SetPosition(const AObj: TCEFViewComponent; const position_: TCefPoint);  extdecl;
begin
  handleExceptionBegin
  AObj.Position := position_;
  handleExceptionEnd
end;

function  ViewComponent_GetTypeString(const AObj: TCEFViewComponent) : PChar;  extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.TypeString));
  handleExceptionEnd
end;

function  ViewComponent_GetHeightForWidth(const AObj: TCEFViewComponent; width: Integer) : Integer;  extdecl;
begin
  handleExceptionBegin
  Result := AObj.HeightForWidth[width];
  handleExceptionEnd
end;

procedure  ViewComponent_SetOnGetPreferredSize(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnGetPreferredSize}
  {$DEFINE EventName := OnGetPreferredSize}
  EventMethodCode
end;

procedure  ViewComponent_SetOnGetMinimumSize(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnGetMinimumSize}
  {$DEFINE EventName := OnGetMinimumSize}
  EventMethodCode
end;

procedure  ViewComponent_SetOnGetMaximumSize(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnGetMaximumSize}
  {$DEFINE EventName := OnGetMaximumSize}
  EventMethodCode
end;

procedure  ViewComponent_SetOnGetHeightForWidth(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnGetHeightForWidth}
  {$DEFINE EventName := OnGetHeightForWidth}
  EventMethodCode
end;

procedure  ViewComponent_SetOnParentViewChanged(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnParentViewChanged}
  {$DEFINE EventName := OnParentViewChanged}
  EventMethodCode
end;

procedure  ViewComponent_SetOnChildViewChanged(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnChildViewChanged}
  {$DEFINE EventName := OnChildViewChanged}
  EventMethodCode
end;

procedure  ViewComponent_SetOnWindowChanged(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnWindowChanged}
  {$DEFINE EventName := OnWindowChanged}
  EventMethodCode
end;

procedure  ViewComponent_SetOnLayoutChanged(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnLayoutChanged}
  {$DEFINE EventName := OnLayoutChanged}
  EventMethodCode
end;

procedure  ViewComponent_SetOnFocus(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnFocus}
  {$DEFINE EventName := OnFocus}
  EventMethodCode
end;

procedure  ViewComponent_SetOnBlur(const AObj: TCEFViewComponent; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := ViewComponent_OnBlur}
  {$DEFINE EventName := OnBlur}
  EventMethodCode
end;


exports
  ViewComponent_Create,
  ViewComponent_Free,
  ViewComponent_ToStringEx,
  ViewComponent_IsSame,
  ViewComponent_SizeToPreferredSize,
  ViewComponent_InvalidateLayout,
  ViewComponent_RequestFocus,
  ViewComponent_ConvertPointToScreen,
  ViewComponent_ConvertPointFromScreen,
  ViewComponent_ConvertPointToWindow,
  ViewComponent_ConvertPointFromWindow,
  ViewComponent_ConvertPointToView,
  ViewComponent_ConvertPointFromView,
  ViewComponent_GetInitialized,
  ViewComponent_GetAsView,
  ViewComponent_GetAsBrowserView,
  ViewComponent_GetAsButton,
  ViewComponent_GetAsPanel,
  ViewComponent_GetAsScrollView,
  ViewComponent_GetAsTextfield,
  ViewComponent_GetViewForID,
  ViewComponent_GetValid,
  ViewComponent_GetAttached,
  ViewComponent_GetDelegate,
  ViewComponent_GetWindow,
  ViewComponent_GetParentView,
  ViewComponent_GetBoundsInScreen,
  ViewComponent_GetPreferredSize,
  ViewComponent_GetMinimumSize,
  ViewComponent_GetMaximumSize,
  ViewComponent_GetVisible,
  ViewComponent_SetVisible,
  ViewComponent_GetDrawn,
  ViewComponent_GetEnabled,
  ViewComponent_SetEnabled,
  ViewComponent_GetFocusable,
  ViewComponent_SetFocusable,
  ViewComponent_GetAccessibilityFocusable,
  ViewComponent_GetBackgroundColor,
  ViewComponent_SetBackgroundColor,
  ViewComponent_GetID,
  ViewComponent_SetID,
  ViewComponent_GetGroupID,
  ViewComponent_SetGroupID,
  ViewComponent_GetBounds,
  ViewComponent_SetBounds,
  ViewComponent_GetSize,
  ViewComponent_SetSize,
  ViewComponent_GetPosition,
  ViewComponent_SetPosition,
  ViewComponent_GetTypeString,
  ViewComponent_GetHeightForWidth,
  ViewComponent_SetOnGetPreferredSize,
  ViewComponent_SetOnGetMinimumSize,
  ViewComponent_SetOnGetMaximumSize,
  ViewComponent_SetOnGetHeightForWidth,
  ViewComponent_SetOnParentViewChanged,
  ViewComponent_SetOnChildViewChanged,
  ViewComponent_SetOnWindowChanged,
  ViewComponent_SetOnLayoutChanged,
  ViewComponent_SetOnFocus,
  ViewComponent_SetOnBlur;