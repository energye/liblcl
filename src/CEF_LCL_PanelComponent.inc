//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure PanelComponent_Create(AOwner: TComponent; out Result: TCEFPanelComponent); extdecl;
begin
  handleExceptionBegin
  Result := TCEFPanelComponent.Create(AOwner);
  handleExceptionEnd
end;

procedure PanelComponent_CreatePanel(const AObj: TCEFPanelComponent); extdecl;
begin
  handleExceptionBegin
  AObj.CreatePanel;
  handleExceptionEnd
end;

procedure PanelComponent_SetToFillLayout(const AObj: TCEFPanelComponent; out Result: ICefFillLayout); extdecl;
begin
  handleExceptionBegin
  Result := AObj.SetToFillLayout;
  handleExceptionEnd
end;

procedure  PanelComponent_SetToBoxLayout(const AObj: TCEFPanelComponent; const settings: TCefBoxLayoutSettings; out Result: ICefBoxLayout); extdecl;
begin
  handleExceptionBegin
  Result := AObj.SetToBoxLayout(settings);
  handleExceptionEnd
end;

procedure PanelComponent_GetLayout(const AObj: TCEFPanelComponent; out Result: ICefLayout); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetLayout;
  handleExceptionEnd
end;

procedure PanelComponent_Layout(const AObj: TCEFPanelComponent); extdecl;
begin
  handleExceptionBegin
  AObj.Layout;
  handleExceptionEnd
end;

procedure PanelComponent_AddChildView(const AObj: TCEFPanelComponent; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.AddChildView(view);
  handleExceptionEnd
end;

procedure PanelComponent_AddChildViewAt(const AObj: TCEFPanelComponent; const view: ICefView; index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.AddChildViewAt(view, index);
  handleExceptionEnd
end;

procedure PanelComponent_ReorderChildView(const AObj: TCEFPanelComponent; const view: ICefView; index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ReorderChildView(view, index);
  handleExceptionEnd
end;

procedure PanelComponent_RemoveChildView(const AObj: TCEFPanelComponent; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.RemoveChildView(view);
  handleExceptionEnd
end;

procedure PanelComponent_RemoveAllChildViews(const AObj: TCEFPanelComponent); extdecl;
begin
  handleExceptionBegin
  AObj.RemoveAllChildViews;
  handleExceptionEnd
end;

function  PanelComponent_GetChildViewCount(const AObj: TCEFPanelComponent) : NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetChildViewCount;
  handleExceptionEnd
end;

procedure  PanelComponent_GetChildViewAt(const AObj: TCEFPanelComponent; index: Integer; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetChildViewAt(index);
  handleExceptionEnd
end;

procedure PanelComponent_AsWindow(const AObj: TCEFPanelComponent; out Result: ICefWindow); extdecl;
begin
  handleExceptionBegin
  Result := AObj.AsWindow;
  handleExceptionEnd
end;


exports
  PanelComponent_Create,
  PanelComponent_CreatePanel,
  PanelComponent_SetToFillLayout,
  PanelComponent_SetToBoxLayout,
  PanelComponent_GetLayout,
  PanelComponent_Layout,
  PanelComponent_AddChildView,
  PanelComponent_AddChildViewAt,
  PanelComponent_ReorderChildView,
  PanelComponent_RemoveChildView,
  PanelComponent_RemoveAllChildViews,
  PanelComponent_GetChildViewCount,
  PanelComponent_GetChildViewAt,
  PanelComponent_AsWindow;