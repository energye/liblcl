//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8InterceptorRef_Create(var Result: TV8InterceptorRef); extdecl;
begin
  handleExceptionBegin
  Result := TV8InterceptorRef.Create;
  handleExceptionEnd
end;

procedure CefV8Interceptor_GetByName(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetByNamePtr := AEventData;
end;

procedure CefV8Interceptor_GetByIndex(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetByIndexPtr := AEventData;
end;

procedure CefV8Interceptor_SetByName(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetByNamePtr := AEventData;
end;

procedure CefV8Interceptor_SetByIndex(const AObj: TV8InterceptorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetByIndexPtr := AEventData;
end;

procedure CefV8Interceptor_Destroy(const AObj: TV8InterceptorRef); extdecl;
begin
    AObj.Destroy();
end;

exports
    CefV8InterceptorRef_Create,
    CefV8Interceptor_GetByName,
    CefV8Interceptor_GetByIndex,
    CefV8Interceptor_SetByName,
    CefV8Interceptor_SetByIndex,
    CefV8Interceptor_Destroy
;
