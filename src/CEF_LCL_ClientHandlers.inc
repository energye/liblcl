//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== AudioHandler ==}
procedure CefAudioHandlerRef_Create(var Result: ICefAudioHandler); extdecl;
begin
  handleExceptionBegin
  Result := TAudioHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefAudioHandler_OnGetAudioParameters(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
    TAudioHandlerRef(AObj).GetAudioParametersPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStarted(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
    TAudioHandlerRef(AObj).AudioStreamStartedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamPacket(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
    TAudioHandlerRef(AObj).AudioStreamPacketPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStopped(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
    TAudioHandlerRef(AObj).AudioStreamStoppedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamError(const AObj: ICefAudioHandler; AEventData: Pointer); extdecl;
begin
    TAudioHandlerRef(AObj).AudioStreamErrorPtr := AEventData;
end;


exports
  {== AudioHandler ==}
  CefAudioHandlerRef_Create,
  CefAudioHandler_OnGetAudioParameters,
  CefAudioHandler_OnAudioStreamStarted,
  CefAudioHandler_OnAudioStreamPacket,
  CefAudioHandler_OnAudioStreamStopped,
  CefAudioHandler_OnAudioStreamError
;
