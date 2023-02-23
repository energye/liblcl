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

procedure CefV8Accessor_Get(AObj: TV8AccessorRef; AEventData: Pointer); extdecl;
begin
    AObj.GetPtr := AEventData;
end;

procedure CefV8Accessor_Set(AObj: TV8AccessorRef; AEventData: Pointer); extdecl;
begin
    AObj.SetPtr := AEventData;
end;

exports
    CefV8Accessor_Create,
    CefV8Accessor_Get,
    CefV8Accessor_Set
;
