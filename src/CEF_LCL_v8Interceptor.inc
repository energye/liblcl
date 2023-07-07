//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8InterceptorRef_Create(var Result: ICefV8Interceptor); extdecl;
begin
  handleExceptionBegin
  Result := TV8InterceptorRef.Create;
  handleExceptionEnd
end;

procedure CefV8Interceptor_GetByName(const AObj: ICefV8Interceptor; AEventData: Pointer); extdecl;
begin
  (AObj as TV8InterceptorRef).GetByNamePtr := AEventData;
end;

procedure CefV8Interceptor_GetByIndex(const AObj: ICefV8Interceptor; AEventData: Pointer); extdecl;
begin
  (AObj as TV8InterceptorRef).GetByIndexPtr := AEventData;
end;

procedure CefV8Interceptor_SetByName(const AObj: ICefV8Interceptor; AEventData: Pointer); extdecl;
begin
  (AObj as TV8InterceptorRef).SetByNamePtr := AEventData;
end;

procedure CefV8Interceptor_SetByIndex(const AObj: ICefV8Interceptor; AEventData: Pointer); extdecl;
begin
  (AObj as TV8InterceptorRef).SetByIndexPtr := AEventData;
end;

procedure CefV8Interceptor_Destroy(const AObj: ICefV8Interceptor); extdecl;
begin
  (AObj as TV8InterceptorRef).Destroy();
end;

exports
  CefV8InterceptorRef_Create,
  CefV8Interceptor_GetByName,
  CefV8Interceptor_GetByIndex,
  CefV8Interceptor_SetByName,
  CefV8Interceptor_SetByIndex,
  CefV8Interceptor_Destroy;