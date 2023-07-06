//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== CookieVisitor ==}
procedure CefCookieVisitorRef_Create(var Result: ICefCookieVisitor); extdecl;
begin
  handleExceptionBegin
  Result := TCookieVisitorRef.Create;
  handleExceptionEnd
end;

procedure CefCookieVisitor_OnVisit(const AObj: ICefCookieVisitor; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TCookieVisitorRef).visitPtr := AEventData;
  handleExceptionEnd
end;

{== SetCookieCallback ==}
procedure CefSetCookieCallbackRef_Create(var Result: ICefSetCookieCallback); extdecl;
begin
  handleExceptionBegin
  Result := TSetCookieCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefSetCookieCallbackRef_CreateForChromium(const Chromium: TChromium; id: Integer; var Result: ICefSetCookieCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCefCustomSetCookieCallback.Create(Chromium, id);
  handleExceptionEnd
end;

procedure CefSetCookieCallback_OnComplete(const AObj: ICefSetCookieCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TSetCookieCallbackRef).CompletePtr := AEventData;
  handleExceptionEnd
end;

{== DeleteCookiesCallback ==}
procedure CefDeleteCookiesCallbackRef_Create(var Result: ICefDeleteCookiesCallback); extdecl;
begin
  handleExceptionBegin
  Result := TDeleteCookiesCallbackRef.Create;
  handleExceptionEnd
end;

procedure CefDeleteCookiesCallbackRef_CreateForChromium(const Chromium: TChromium; var Result: ICefDeleteCookiesCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCefCustomDeleteCookiesCallback.Create(Chromium);
  handleExceptionEnd
end;

procedure CefDeleteCookiesCallback_OnComplete(const AObj: ICefDeleteCookiesCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TDeleteCookiesCallbackRef).CompletePtr := AEventData;
  handleExceptionEnd
end;

exports
  {== CookieVisitor ==}
  CefCookieVisitorRef_Create,
  CefCookieVisitor_OnVisit,
  {== SetCookieCallback ==}
  CefSetCookieCallbackRef_Create,
  CefSetCookieCallbackRef_CreateForChromium,
  CefSetCookieCallback_OnComplete,
  {== DeleteCookiesCallback ==}
  CefDeleteCookiesCallbackRef_Create,
  CefDeleteCookiesCallbackRef_CreateForChromium,
  CefDeleteCookiesCallback_OnComplete
;
