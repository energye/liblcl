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

exports
  CefBaseRefCounted_Wrap,
  CefBaseRefCounted_Free;
