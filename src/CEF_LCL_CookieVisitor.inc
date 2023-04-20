//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefCookieVisitorRef_Create(var Result: TCookieVisitorRef); extdecl;
begin
  handleExceptionBegin
  Result := TCookieVisitorRef.Create;
  handleExceptionEnd
end;

procedure CefCookieVisitor_OnVisit(const AObj: TCookieVisitorRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  AObj.visitPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefCookieVisitorRef_Create,
  CefCookieVisitor_OnVisit
;
