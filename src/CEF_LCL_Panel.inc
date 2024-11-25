//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFPanelRef_New(const delegate: ICefPanelDelegate; out Result: ICefPanel) ; extdecl;
begin
  handleExceptionBegin
  Result := TCefPanelRef.CreatePanel(delegate);
  handleExceptionEnd
end;

procedure CEFPanel_GetAsWindow(const AObj: ICefPanel; out Result: ICefWindow); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetAsWindow;
  handleExceptionEnd
end;

procedure CEFPanel_SetToFillLayout(const AObj: ICefPanel; out Result: ICefFillLayout) ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SetToFillLayout;
  handleExceptionEnd
end;

procedure CEFPanel_SetToBoxLayout(const AObj: ICefPanel; var settings: PCefBoxLayoutSettings; out Result: ICefBoxLayout); extdecl;
var
  TempSettings: TCefBoxLayoutSettings;
begin
  handleExceptionBegin
  TempSettings := GoBoxLayoutSettingsToCefBoxLayoutSettings(settings);
  Result := AObj.SetToBoxLayout(TempSettings);
  handleExceptionEnd
end;

procedure CEFPanel_GetLayout(const AObj: ICefPanel; out Result: ICefLayout); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetLayout;
  handleExceptionEnd
end;

procedure CEFPanel_Layout(const AObj: ICefPanel); extdecl;
begin
  handleExceptionBegin
  AObj.Layout;
  handleExceptionEnd
end;

procedure CEFPanel_AddChildView(const AObj: ICefPanel; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.AddChildView(view);
  handleExceptionEnd
end;

procedure CEFPanel_AddChildViewAt(const AObj: ICefPanel; const view: ICefView; index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.AddChildViewAt(view, index);
  handleExceptionEnd
end;

procedure CEFPanel_ReorderChildView(const AObj: ICefPanel; const view: ICefView; index: Integer); extdecl;
begin
  handleExceptionBegin
  AObj.ReorderChildView(view, index);
  handleExceptionEnd
end;

procedure CEFPanel_RemoveChildView(const AObj: ICefPanel; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  AObj.RemoveChildView(view);
  handleExceptionEnd
end;

procedure CEFPanel_RemoveAllChildViews(const AObj: ICefPanel); extdecl;
begin
  handleExceptionBegin
  AObj.RemoveAllChildViews;
  handleExceptionEnd
end;

function  CEFPanel_GetChildViewCount(const AObj: ICefPanel) : NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetChildViewCount;
  handleExceptionEnd
end;

procedure CEFPanel_GetChildViewAt(const AObj: ICefPanel; index: Integer; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetChildViewAt(index);
  handleExceptionEnd
end;


exports
  CEFPanelRef_New,
  CEFPanel_GetAsWindow,
  CEFPanel_SetToFillLayout,
  CEFPanel_SetToBoxLayout,
  CEFPanel_GetLayout,
  CEFPanel_Layout,
  CEFPanel_AddChildView,
  CEFPanel_AddChildViewAt,
  CEFPanel_ReorderChildView,
  CEFPanel_RemoveChildView,
  CEFPanel_RemoveAllChildViews,
  CEFPanel_GetChildViewCount,
  CEFPanel_GetChildViewAt;
