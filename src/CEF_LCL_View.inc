//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  View_AsBrowserView(const AObj: ICefView; out Result: ICefBrowserView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsBrowserView;
  handleExceptionEnd
end;

procedure  View_AsButton(const AObj: ICefView; out Result: ICefButton); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsButton;
  handleExceptionEnd
end;

procedure  View_AsPanel(const AObj: ICefView; out Result: ICefPanel); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsPanel;
  handleExceptionEnd
end;

procedure  View_AsScrollView(const AObj: ICefView; out Result: ICefScrollView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsScrollView;
  handleExceptionEnd
end;

procedure  View_AsTextfield(const AObj: ICefView; out Result: ICefTextfield); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsTextfield;
  handleExceptionEnd
end;

function  View_GetTypeString(const AObj: ICefView) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetTypeString));
  handleExceptionEnd
end;

function  View_ToStringEx(const AObj: ICefView; include_children: LongBool): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.ToStringEx(include_children)));
  handleExceptionEnd
end;

function  View_IsValid(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid;
  handleExceptionEnd
end;

function  View_IsAttached(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsAttached;
  handleExceptionEnd
end;

function  View_IsSame(const AObj: ICefView; const that: ICefView): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSame(that);
  handleExceptionEnd
end;

procedure  View_GetDelegate(const AObj: ICefView; out Result: ICefViewDelegate); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetDelegate;
  handleExceptionEnd
end;

procedure  View_GetWindow(const AObj: ICefView; out Result: ICefWindow); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetWindow;
  handleExceptionEnd
end;

function  View_GetID(const AObj: ICefView) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetID;
  handleExceptionEnd
end;

procedure View_SetID(const AObj: ICefView; id_: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetID(id_);
  handleExceptionEnd
end;

function  View_GetGroupID(const AObj: ICefView) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetGroupID;
  handleExceptionEnd
end;

procedure View_SetGroupID(const AObj: ICefView; group_id: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.SetGroupID(group_id);
  handleExceptionEnd
end;

procedure  View_GetParentView(const AObj: ICefView; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetParentView;
  handleExceptionEnd
end;

procedure  View_GetViewForID(const AObj: ICefView; id_: Integer; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetViewForID(id_);
  handleExceptionEnd
end;

procedure View_SetBounds(const AObj: ICefView; const bounds_: TCefRect); extdecl;
begin
  handleExceptionBegin
  AObj.SetBounds(bounds_);
  handleExceptionEnd
end;

procedure  View_GetBounds(const AObj: ICefView; out Result: TCefRect) ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetBounds;
  handleExceptionEnd
end;

procedure  View_GetBoundsInScreen(const AObj: ICefView; out Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetBoundsInScreen;
  handleExceptionEnd
end;

procedure View_SetSize(const AObj: ICefView; const size_: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetSize(size_);
  handleExceptionEnd
end;

procedure  View_GetSize(const AObj: ICefView; out Result: TCefSize); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSize;
  handleExceptionEnd
end;

procedure View_SetPosition(const AObj: ICefView; const position_: TCefPoint); extdecl;
begin
  handleExceptionBegin
  AObj.SetPosition(position_);
  handleExceptionEnd
end;

procedure  View_GetPosition(const AObj: ICefView; out Result: TCefPoint); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetPosition;
  handleExceptionEnd
end;

procedure View_SetInsets(const AObj: ICefView; const insets: TCefInsets); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure  View_GetInsets(const AObj: ICefView; out Result: TCefInsets); extdecl;
begin
  handleExceptionBegin
  handleExceptionEnd
end;

procedure  View_GetPreferredSize(const AObj: ICefView; out Result: TCefSize); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetPreferredSize;
  handleExceptionEnd
end;

procedure View_SizeToPreferredSize(const AObj: ICefView) ; extdecl;
begin
  handleExceptionBegin
  AObj.SizeToPreferredSize;
  handleExceptionEnd
end;

procedure  View_GetMinimumSize(const AObj: ICefView; out Result: TCefSize) ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetMinimumSize;
  handleExceptionEnd
end;

procedure  View_GetMaximumSize(const AObj: ICefView; out Result: TCefSize); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetMaximumSize;
  handleExceptionEnd
end;

function  View_GetHeightForWidth(const AObj: ICefView; width: Integer): Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetHeightForWidth(width);
  handleExceptionEnd
end;

procedure View_InvalidateLayout(const AObj: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.InvalidateLayout;
  handleExceptionEnd
end;

procedure View_SetVisible(const AObj: ICefView; visible_: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetVisible(visible_);
  handleExceptionEnd
end;

function  View_IsVisible(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsVisible;
  handleExceptionEnd
end;

function  View_IsDrawn(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsDrawn;
  handleExceptionEnd
end;

procedure View_SetEnabled(const AObj: ICefView; enabled_: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetEnabled(enabled_);
  handleExceptionEnd
end;

function  View_IsEnabled(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsEnabled;
  handleExceptionEnd
end;

procedure View_SetFocusable(const AObj: ICefView; focusable_: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetFocusable(focusable_);
  handleExceptionEnd
end;

function  View_IsFocusable(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsFocusable;
  handleExceptionEnd
end;

function  View_IsAccessibilityFocusable(const AObj: ICefView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsAccessibilityFocusable;
  handleExceptionEnd
end;

procedure View_RequestFocus(const AObj: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.RequestFocus;
  handleExceptionEnd
end;

procedure View_SetBackgroundColor(const AObj: ICefView; color: TCefColor); extdecl;
begin
  handleExceptionBegin
  AObj.SetBackgroundColor(color);
  handleExceptionEnd
end;

function  View_GetBackgroundColor(const AObj: ICefView) : TCefColor; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetBackgroundColor;
  handleExceptionEnd
end;

function  View_ConvertPointToScreen(const AObj: ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToScreen(point);
  handleExceptionEnd
end;

function  View_ConvertPointFromScreen(const AObj: ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromScreen(point);
  handleExceptionEnd
end;

function  View_ConvertPointToWindow(const AObj: ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToWindow(point);
  handleExceptionEnd
end;

function  View_ConvertPointFromWindow(const AObj: ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromWindow(point);
  handleExceptionEnd
end;

function  View_ConvertPointToView(const AObj: ICefView; const view : ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointToView(view, point);
  handleExceptionEnd
end;

function  View_ConvertPointFromView(const AObj: ICefView; const view : ICefView; var point: TCefPoint): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ConvertPointFromView(view, point);
  handleExceptionEnd
end;


exports
  View_AsBrowserView,
  View_AsButton,
  View_AsPanel,
  View_AsScrollView,
  View_AsTextfield,
  View_GetTypeString,
  View_ToStringEx,
  View_IsValid,
  View_IsAttached,
  View_IsSame,
  View_GetDelegate,
  View_GetWindow,
  View_GetID,
  View_SetID,
  View_GetGroupID,
  View_SetGroupID,
  View_GetParentView,
  View_GetViewForID,
  View_SetBounds,
  View_GetBounds,
  View_GetBoundsInScreen,
  View_SetSize,
  View_GetSize,
  View_SetPosition,
  View_GetPosition,
  View_SetInsets,
  View_GetInsets,
  View_GetPreferredSize,
  View_SizeToPreferredSize,
  View_GetMinimumSize,
  View_GetMaximumSize,
  View_GetHeightForWidth,
  View_InvalidateLayout,
  View_SetVisible,
  View_IsVisible,
  View_IsDrawn,
  View_SetEnabled,
  View_IsEnabled,
  View_SetFocusable,
  View_IsFocusable,
  View_IsAccessibilityFocusable,
  View_RequestFocus,
  View_SetBackgroundColor,
  View_GetBackgroundColor,
  View_ConvertPointToScreen,
  View_ConvertPointFromScreen,
  View_ConvertPointToWindow,
  View_ConvertPointFromWindow,
  View_ConvertPointToView,
  View_ConvertPointFromView;
