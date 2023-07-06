//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefV8ArrayBufferReleaseCallback_Create(var Result: ICefv8ArrayBufferReleaseCallback); extdecl;
begin
  handleExceptionBegin
  Result := TV8ArrayBufferReleaseCallbackRef.Create();
  handleExceptionEnd
end;

procedure CefV8ArrayBufferReleaseCallback_ReleaseBuffer(const TObj: ICefv8ArrayBufferReleaseCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (TObj as TV8ArrayBufferReleaseCallbackRef).ReleaseBufferPtr := AEventData;
  handleExceptionEnd
end;

exports
  CefV8ArrayBufferReleaseCallback_Create,
  CefV8ArrayBufferReleaseCallback_ReleaseBuffer
;
