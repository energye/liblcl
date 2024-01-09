//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure ScrollViewComponent_Create(AOwner: TComponent; out Result: TCEFScrollViewComponent) ; extdecl;
begin
  handleExceptionBegin
  Result := TCEFScrollViewComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure  ScrollViewComponent_CreateScrollView(const AObj: TCEFScrollViewComponent); extdecl;
begin
  handleExceptionBegin
  AObj.CreateScrollView;
  handleExceptionEnd
end;

procedure  ScrollViewComponent_GetContentView(const AObj: TCEFScrollViewComponent; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.ContentView;
  handleExceptionEnd
end;

procedure  ScrollViewComponent_SetContentView(const AObj: TCEFScrollViewComponent; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.ContentView := view;
  handleExceptionEnd
end;

procedure  ScrollViewComponent_VisibleContentRect(const AObj: TCEFScrollViewComponent; out Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AObj.VisibleContentRect;
  handleExceptionEnd
end;

function  ScrollViewComponent_HorizontalScrollbarHeight(const AObj: TCEFScrollViewComponent) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HorizontalScrollbarHeight;
  handleExceptionEnd
end;

function  ScrollViewComponent_VerticalScrollbarWidth(const AObj: TCEFScrollViewComponent) : Integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.VerticalScrollbarWidth;
  handleExceptionEnd
end;

function  ScrollViewComponent_HasHorizontalScrollbar(const AObj: TCEFScrollViewComponent) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasHorizontalScrollbar;
  handleExceptionEnd
end;

function  ScrollViewComponent_HasVerticalScrollbar(const AObj: TCEFScrollViewComponent) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.HasVerticalScrollbar;
  handleExceptionEnd
end;


exports
  ScrollViewComponent_Create,
  ScrollViewComponent_CreateScrollView,
  ScrollViewComponent_GetContentView,
  ScrollViewComponent_SetContentView,
  ScrollViewComponent_VisibleContentRect,
  ScrollViewComponent_HorizontalScrollbarHeight,
  ScrollViewComponent_VerticalScrollbarWidth,
  ScrollViewComponent_HasHorizontalScrollbar,
  ScrollViewComponent_HasVerticalScrollbar;
