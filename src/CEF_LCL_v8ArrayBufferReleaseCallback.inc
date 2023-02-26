//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8ArrayBufferReleaseCallback_Create(out Result: TV8ArrayBufferReleaseCallbackRef); extdecl;
begin
  handleExceptionBegin
  Result := TV8ArrayBufferReleaseCallbackRef.Create();
  handleExceptionEnd
end;

procedure CefV8ArrayBufferReleaseCallback_ReleaseBuffer(const TObj: TV8ArrayBufferReleaseCallbackRef; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  TObj.ReleaseBufferPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefV8ArrayBufferReleaseCallback_Create,
  CefV8ArrayBufferReleaseCallback_ReleaseBuffer
;
