//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBaseRefCounted_Wrap(const Ref: ICefBaseRefCounted; var Result: Pointer); extdecl;
begin
  handleExceptionBegin
  Result := Ref.Wrap;
  handleExceptionEnd
end;

procedure CefBaseRefCounted_Free(var Ref: ICefBaseRefCounted); extdecl;
begin
  handleExceptionBegin
  Ref := nil;
  handleExceptionEnd
end;

function CefBaseRefCounted_SameAs(const Ref: ICefBaseRefCounted; aData : Pointer):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := Ref.SameAs(aData);
  handleExceptionEnd
end;

function CefBaseRefCounted_HasOneRef(const Ref: ICefBaseRefCounted):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := Ref.HasOneRef();
  handleExceptionEnd
end;

function CefBaseRefCounted_HasAtLeastOneRef(const Ref: ICefBaseRefCounted):LongBool ; extdecl;
begin
  handleExceptionBegin
  Result := Ref.HasAtLeastOneRef();
  handleExceptionEnd
end;

procedure CefBaseRefCounted_DestroyOtherRefs(const Ref: ICefBaseRefCounted); extdecl;
begin
  handleExceptionBegin
  Ref.DestroyOtherRefs();
  handleExceptionEnd
end;

exports
  CefBaseRefCounted_Wrap,
  CefBaseRefCounted_Free,
  CefBaseRefCounted_SameAs,
  CefBaseRefCounted_HasOneRef,
  CefBaseRefCounted_HasAtLeastOneRef,
  CefBaseRefCounted_DestroyOtherRefs;
