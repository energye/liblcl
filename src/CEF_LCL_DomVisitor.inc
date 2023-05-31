//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefDomVisitorRef_Create(var Result: ICefDomVisitor); extdecl;
begin
  handleExceptionBegin
  Result := TDomVisitorRef.Create;
  handleExceptionEnd
end;

procedure CefDomVisitor_Visit(const TObj: ICefDomVisitor; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TDomVisitorRef).VisitPtr := AEventData;
  handleExceptionEnd
end;

exports
   CefDomVisitorRef_Create,
   CefDomVisitor_Visit
;
