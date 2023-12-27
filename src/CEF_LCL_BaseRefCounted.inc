//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBaseRefCounted_Wrap(const Ref: ICefBase; var Result: Pointer); extdecl;
begin
  handleExceptionBegin
  Result := Ref.Wrap;
  handleExceptionEnd
end;

procedure CefBaseRefCounted_Free(var Ref: ICefBase); extdecl;
begin
  Ref := nil;
end;

function CefBaseRefCounted_SameAs(const Ref: ICefBase; aData : Pointer):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := Ref.SameAs(aData);
  handleExceptionEnd
end;

function CefBaseRefCounted_HasOneRef(const Ref: ICefBase):LongBool ; extdecl;
begin
end;

function CefBaseRefCounted_HasAtLeastOneRef(const Ref: ICefBase):LongBool ; extdecl;
begin
end;

procedure CefBaseRefCounted_DestroyOtherRefs(const Ref: ICefBase); extdecl;
begin
end;

exports
  CefBaseRefCounted_Wrap,
  CefBaseRefCounted_Free,
  CefBaseRefCounted_SameAs,
  CefBaseRefCounted_HasOneRef,
  CefBaseRefCounted_HasAtLeastOneRef,
  CefBaseRefCounted_DestroyOtherRefs;
