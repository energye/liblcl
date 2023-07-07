//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefResponseFilterRef_Create(var Result: ICefResponseFilter); extdecl;
begin
  handleExceptionBegin
  Result := TResponseFilterRef.Create;
  handleExceptionEnd
end;

procedure CefResponseFilter_InitFilter(const AObj: ICefResponseFilter; AEventData: Pointer); extdecl;
begin
  (AObj as TResponseFilterRef).InitFilterPtr := AEventData;
end;

procedure CefResponseFilter_Filter(const AObj: ICefResponseFilter; AEventData: Pointer); extdecl;
begin
  (AObj as TResponseFilterRef).FilterPtr := AEventData;
end;

exports
  CefResponseFilterRef_Create,
  CefResponseFilter_InitFilter,
  CefResponseFilter_Filter;