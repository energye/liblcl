//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  BoxLayoutRef_UnWrap(const data: Pointer; out Result: ICefBoxLayout); extdecl;
begin
  handleExceptionBegin
  Result := TCefBoxLayoutRef.UnWrap(data);
  handleExceptionEnd
end;

procedure  BoxLayout_SetFlexForView(const TObj: ICefBoxLayout; const view: ICefView; flex: Integer); extdecl;
begin
  handleExceptionBegin
  TObj.SetFlexForView(view, flex);
  handleExceptionEnd
end;

procedure  BoxLayout_ClearFlexForView(const TObj: ICefBoxLayout; const view: ICefView); extdecl;
begin
  handleExceptionBegin
  TObj.ClearFlexForView(view);
  handleExceptionEnd
end;

exports
  BoxLayoutRef_UnWrap,
  BoxLayout_SetFlexForView,
  BoxLayout_ClearFlexForView;
