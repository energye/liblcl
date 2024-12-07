//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaSinkRef_UnWrap(const AObj: ICefMediaSink; out Result: ICefMediaSink); extdecl;
begin
  handleExceptionBegin
  Result := TCefMediaSinkRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function  MediaSink_GetId(const AObj: ICefMediaSink): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetId());
  handleExceptionEnd
end;

function  MediaSink_GetName(const AObj: ICefMediaSink): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetName());
  handleExceptionEnd
end;

function  MediaSink_GetIconType(const AObj: ICefMediaSink): TCefMediaSinkIconType; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetIconType();
  handleExceptionEnd
end;

procedure MediaSink_GetDeviceInfo(const AObj: ICefMediaSink; const callback: ICefMediaSinkDeviceInfoCallback); extdecl;
begin
  handleExceptionBegin
  AObj.GetDeviceInfo(callback);
  handleExceptionEnd
end;

function  MediaSink_IsCastSink(const AObj: ICefMediaSink): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsCastSink();
  handleExceptionEnd
end;

function  MediaSink_IsDialSink(const AObj: ICefMediaSink): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsDialSink();
  handleExceptionEnd
end;

function  MediaSink_IsCompatibleWith(const AObj: ICefMediaSink; const source: ICefMediaSource): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsCompatibleWith(source);
  handleExceptionEnd
end;

exports
  MediaSinkRef_UnWrap,
  MediaSink_GetId,
  MediaSink_GetName,
  MediaSink_GetIconType,
  MediaSink_GetDeviceInfo,
  MediaSink_IsCastSink,
  MediaSink_IsDialSink,
  MediaSink_IsCompatibleWith;
