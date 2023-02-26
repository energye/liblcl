//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8Accessor_Create(out Result: TV8AccessorRef); extdecl;
begin
  handleExceptionBegin
  Result := TV8AccessorRef.Create;
  handleExceptionEnd
end;

procedure CefV8Accessor_Get(const AObj: TV8AccessorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetPtr := AEventData;
end;

procedure CefV8Accessor_Set(const AObj: TV8AccessorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetPtr := AEventData;
end;

procedure CefV8Accessor_Destroy(const AObj: TV8AccessorRef); extdecl;
begin
    AObj.Destroy;
end;

exports
    CefV8Accessor_Create,
    CefV8Accessor_Get,
    CefV8Accessor_Set,
    CefV8Accessor_Destroy
;
