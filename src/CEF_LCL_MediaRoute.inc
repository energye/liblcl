//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure MediaRouteRef_UnWrap(const AObj: ICefMediaRoute; out Result: ICefMediaRoute); extdecl;
begin
  handleExceptionBegin
  Result := TCefMediaRouteRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function  MediaRoute_GetId(const AObj: ICefMediaRoute): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(AObj.GetId());
  handleExceptionEnd
end;

procedure  MediaRoute_GetSource(const AObj: ICefMediaRoute; out Result: ICefMediaSource); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSource();
  handleExceptionEnd
end;

procedure  MediaRoute_GetSink(const AObj: ICefMediaRoute; out Result: ICefMediaSink); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSink();
  handleExceptionEnd
end;

procedure MediaRoute_SendRouteMessage(const AObj: ICefMediaRoute; const message_: PChar); extdecl;
begin
  handleExceptionBegin
  AObj.SendRouteMessage(PCharToUStr(message_));
  handleExceptionEnd
end;

procedure MediaRoute_Terminate(const AObj: ICefMediaRoute); extdecl;
begin
  handleExceptionBegin
  AObj.Terminate();
  handleExceptionEnd
end;


exports
  MediaRouteRef_UnWrap,
  MediaRoute_GetId,
  MediaRoute_GetSource,
  MediaRoute_GetSink,
  MediaRoute_SendRouteMessage,
  MediaRoute_Terminate;
