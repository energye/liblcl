//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure ScrollViewRef_NewCreateScrollView(const delegate: ICefViewDelegate; out Result: ICefScrollView) ; extdecl;
begin
  handleExceptionBegin
  Result := TCefScrollViewRef.CreateScrollView(delegate);
  handleExceptionEnd
end;

procedure ScrollView_SetContentView(const AObj: ICefScrollView; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.SetContentView(view);
  handleExceptionEnd
end;

procedure  ScrollView_GetContentView(const AObj: ICefScrollView; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetContentView;
  handleExceptionEnd
end;

procedure  ScrollView_GetVisibleContentRect(const AObj: ICefScrollView; out Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetVisibleContentRect;
  handleExceptionEnd
end;

function  ScrollView_HasHorizontalScrollbar(const AObj: ICefScrollView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasHorizontalScrollbar;
  handleExceptionEnd
end;

function  ScrollView_GetHorizontalScrollbarHeight(const AObj: ICefScrollView) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetHorizontalScrollbarHeight;
  handleExceptionEnd
end;

function  ScrollView_HasVerticalScrollbar(const AObj: ICefScrollView) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasVerticalScrollbar;
  handleExceptionEnd
end;

function  ScrollView_GetVerticalScrollbarWidth(const AObj: ICefScrollView) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetVerticalScrollbarWidth;
  handleExceptionEnd
end;


exports
  ScrollViewRef_NewCreateScrollView,
  ScrollView_SetContentView,
  ScrollView_GetContentView,
  ScrollView_GetVisibleContentRect,
  ScrollView_HasHorizontalScrollbar,
  ScrollView_GetHorizontalScrollbarHeight,
  ScrollView_HasVerticalScrollbar,
  ScrollView_GetVerticalScrollbarWidth
;

