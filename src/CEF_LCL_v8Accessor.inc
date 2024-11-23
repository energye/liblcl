//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8Accessor_Create(var Result: ICefV8Accessor); extdecl;
begin
  handleExceptionBegin
  Result := TV8AccessorRef.Create;
  handleExceptionEnd
end;

procedure CefV8Accessor_Get(const AObj: ICefV8Accessor; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TV8AccessorRef).GetPtr := AEventData;
  handleExceptionEnd
end;

procedure CefV8Accessor_Set(const AObj: ICefV8Accessor; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TV8AccessorRef).SetPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefV8Accessor_Create,
  CefV8Accessor_Get,
  CefV8Accessor_Set
