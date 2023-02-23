//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8Handler_Create(out Result: TV8HandlerRef); extdecl;
begin
  handleExceptionBegin
  Result := TV8HandlerRef.Create;
  handleExceptionEnd
end;

procedure CefV8Handler_Execute(AObj: TV8HandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ExecutePtr := AEventData;
end;

procedure CefV8Handler_Destroy(AObj: TV8HandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.DestroyPtr := AEventData;
end;

exports
    CefV8Handler_Create,
    CefV8Handler_Execute,
    CefV8Handler_Destroy
;
