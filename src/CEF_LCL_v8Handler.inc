//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8Handler_Create(var Result: ICefv8Handler); extdecl;
begin
  handleExceptionBegin
  Result := TV8HandlerRef.Create;
  handleExceptionEnd
end;

procedure CefV8Handler_Execute(const AObj: ICefv8Handler; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TV8HandlerRef).ExecutePtr := AEventData;
  handleExceptionEnd
end;

procedure CefV8Handler_Destroy(const AObj: ICefv8Handler); extdecl;
begin
  handleExceptionBegin
  (AObj as TV8HandlerRef).Destroy();
  handleExceptionEnd
end;

exports
  CefV8Handler_Create,
  CefV8Handler_Execute,
  CefV8Handler_Destroy;