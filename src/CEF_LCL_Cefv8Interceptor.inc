//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8InterceptorRef_Create(out Result: TV8InterceptorRef); extdecl;
begin
  handleExceptionBegin
  Result := TV8InterceptorRef.Create;
  handleExceptionEnd
end;

procedure CefV8InterceptorRef_GetByName(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetByNamePtr := AEventData;
end;

procedure CefV8InterceptorRef_GetByIndex(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetByIndexPtr := AEventData;
end;

procedure CefV8InterceptorRef_SetByName(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetByNamePtr := AEventData;
end;

procedure CefV8InterceptorRef_SetByIndex(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetByIndexPtr := AEventData;
end;

procedure CefV8InterceptorRef_Destroy(const AObj: TV8InterceptorRef); extdecl;
begin
    AObj.Destroy();
end;

exports
    CefV8InterceptorRef_Create,
    CefV8InterceptorRef_GetByName,
    CefV8InterceptorRef_GetByIndex,
    CefV8InterceptorRef_SetByName,
    CefV8InterceptorRef_SetByIndex,
    CefV8InterceptorRef_Destroy
;
