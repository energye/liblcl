//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBaseRefCountedOwn_Destroy(const Own: TCefBaseRefCountedOwn); extdecl;
begin
  Own.Destroy;
end;

procedure CefBaseRefCountedOwn_DestroyOtherRefs(const Own: TCefBaseRefCountedOwn); extdecl;
begin
  Own.DestroyOtherRefs;
end;

procedure CefBaseRefCountedOwn_Wrap(const Own: TCefBaseRefCountedOwn; out Result: Pointer); extdecl;
begin
  Result := Own.Wrap;
end;

procedure CefBaseRefCountedOwn_Free(const Own: TCefBaseRefCountedOwn); extdecl;
begin
  Own.Free;
end;

procedure CefBaseRefCountedRef_Destroy(const Ref: TCefBaseRefCountedRef); extdecl;
begin
  Ref.Destroy;
end;

procedure CefBaseRefCountedRef_Wrap(const Ref: TCefBaseRefCountedRef; out Result: Pointer); extdecl;
begin
  Result := Ref.Wrap;
end;

procedure CefBaseRefCountedRef_Free(const Ref: TCefBaseRefCountedRef); extdecl;
begin
  Ref.Free;
end;

exports
    CefBaseRefCountedOwn_Destroy,
    CefBaseRefCountedOwn_DestroyOtherRefs,
    CefBaseRefCountedOwn_Wrap,
    CefBaseRefCountedOwn_Free,
    CefBaseRefCountedRef_Destroy,
    CefBaseRefCountedRef_Wrap,
    CefBaseRefCountedRef_Free
;
