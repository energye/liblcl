//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefBaseRefCounted_Wrap(const Ref: ICefBaseRefCounted; var Result: Pointer); extdecl;
begin
  Result := Ref.Wrap;
end;

procedure CefBaseRefCounted_Free(var Ref: ICefBaseRefCounted); extdecl;
begin
  Ref := nil;
end;

exports
    CefBaseRefCounted_Wrap,
    CefBaseRefCounted_Free
;
