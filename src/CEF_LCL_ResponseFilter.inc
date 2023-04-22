//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefResponseFilterRef_Create(var Result: TResponseFilterRef); extdecl;
begin
  handleExceptionBegin
  Result := TResponseFilterRef.Create;
  handleExceptionEnd
end;

procedure CefResponseFilter_InitFilter(const AObj: TResponseFilterRef; AEventData: Pointer); extdecl;
begin
    AObj.InitFilterPtr := AEventData;
end;

procedure CefResponseFilter_Filter(const AObj: TResponseFilterRef; AEventData: Pointer); extdecl;
begin
    AObj.FilterPtr := AEventData;
end;


exports
  CefResponseFilterRef_Create,
  CefResponseFilter_InitFilter,
  CefResponseFilter_Filter
;
