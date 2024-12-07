//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaSinkDeviceInfoCallbackRef_Create(out Result: ICefMediaSinkDeviceInfoCallback); extdecl;
begin
  handleExceptionBegin
  Result := TMediaSinkDeviceInfoCallbackRef.Create();
  handleExceptionEnd
end;

procedure MediaSinkDeviceInfoCallbackRef_CustomCreate(const events: IChromiumEvents; out Result: ICefMediaSinkDeviceInfoCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCefCustomMediaSinkDeviceInfoCallback.Create(events);
  handleExceptionEnd
end;

procedure MediaSinkDeviceInfoCallback_OnMediaSinkDeviceInfo(const AObj: ICefMediaSinkDeviceInfoCallback; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TMediaSinkDeviceInfoCallbackRef).OnMediaSinkDeviceInfoPtr := AEventData;
  handleExceptionEnd
end;

exports
  MediaSinkDeviceInfoCallbackRef_Create,
  MediaSinkDeviceInfoCallbackRef_CustomCreate,
  MediaSinkDeviceInfoCallback_OnMediaSinkDeviceInfo;
