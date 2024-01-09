//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  LayoutRef_UnWrap(const data: Pointer; out Result: ICefLayout); extdecl;
begin
  handleExceptionBegin
  Result := TCefLayoutRef.UnWrap(data);
  handleExceptionEnd
end;

procedure  Layout_AsBoxLayout(const TObj: ICefLayout; out Result: ICefBoxLayout); extdecl;
begin
  handleExceptionBegin
  Result := TObj.AsBoxLayout();
  handleExceptionEnd
end;

procedure  Layout_AsFillLayout(const TObj: ICefLayout; out Result: ICefFillLayout); extdecl;
begin
  handleExceptionBegin
  Result := TObj.AsFillLayout();
  handleExceptionEnd
end;

function  Layout_IsValid(const TObj: ICefLayout): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid();
  handleExceptionEnd
end;

exports
  LayoutRef_UnWrap,
  Layout_AsBoxLayout,
  Layout_AsFillLayout,
  Layout_IsValid;
