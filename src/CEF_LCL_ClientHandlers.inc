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

procedure CefAudioHandler_OnGetAudioParameters(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.GetAudioParametersPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStarted(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamStartedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamPacket(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamPacketPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamStopped(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamStoppedPtr := AEventData;
end;

procedure CefAudioHandler_OnAudioStreamError(const AObj: TAudioHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.AudioStreamErrorPtr := AEventData;
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
