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
    (AObj as TV8AccessorRef).GetPtr := AEventData;
end;

procedure CefV8Accessor_Set(const AObj: ICefV8Accessor; AEventData: Pointer); extdecl;
begin
    (AObj as TV8AccessorRef).SetPtr := AEventData;
end;

procedure CefV8Accessor_Destroy(const AObj: ICefV8Accessor); extdecl;
begin
    (AObj as TV8AccessorRef).Destroy;
end;

exports
  CefV8Accessor_Create,
  CefV8Accessor_Get,
  CefV8Accessor_Set,
  CefV8Accessor_Destroy;