//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaSourceRef_UnWrap(const AObj: ICefMediaSource; out Result: ICefMediaSource); extdecl;
begin
  handleExceptionBegin
  Result := TCefMediaSourceRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function MediaSource_GetId(const AObj: ICefMediaSource) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetId);
  handleExceptionEnd
end;

function MediaSource_IsCastSource(const AObj: ICefMediaSource) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsCastSource;
  handleExceptionEnd
end;

function MediaSource_IsDialSource(const AObj: ICefMediaSource) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsDialSource;
  handleExceptionEnd
end;

exports
  MediaSourceRef_UnWrap,
  MediaSource_GetId,
  MediaSource_IsCastSource,
  MediaSource_IsDialSource;
