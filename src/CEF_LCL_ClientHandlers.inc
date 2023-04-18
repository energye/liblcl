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

{== CommandHandler ==}
procedure CefCommandHandlerRef_Create(var Result: ICefCommandHandler); extdecl;
begin
  handleExceptionBegin
  Result := TCommandHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefCommandHandler_OnChromeCommand(const AObj: TCommandHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ChromeCommandPtr := AEventData;
end;

{== ContextMenuHandler ==}
procedure CefContextMenuHandlerRef_Create(var Result: ICefContextMenuHandler); extdecl;
begin
  handleExceptionBegin
  Result := TContextMenuHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefContextMenuHandler_OnBeforeContextMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.BeforeContextMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_RunContextMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.RunContextMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_OnContextMenuCommand(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ContextMenuCommandPtr := AEventData;
end;

procedure CefContextMenuHandler_OnContextMenuDismissed(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.ContextMenuDismissedPtr := AEventData;
end;

procedure CefContextMenuHandler_RunQuickMenu(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.RunQuickMenuPtr := AEventData;
end;

procedure CefContextMenuHandler_OnQuickMenuCommand(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.QuickMenuCommandPtr := AEventData;
end;

procedure CefContextMenuHandler_OnQuickMenuDismissed(const AObj: TContextMenuHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.QuickMenuDismissedPtr := AEventData;
end;

{== DialogHandler ==}
procedure CefDialogHandlerRef_Create(var Result: ICefDialogHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDialogHandlerRef.Create;
  handleExceptionEnd
end;

procedure CefDialogHandler_OnFileDialog(const AObj: TDialogHandlerRef; AEventData: Pointer); extdecl;
begin
    AObj.FileDialogPtr := AEventData;
end;

{== DisplayHandler ==}
procedure CefDisplayHandlerRef_Create(var Result: ICefDisplayHandler); extdecl;
begin
  handleExceptionBegin
  Result := TDisplayHandlerRef.Create;
  handleExceptionEnd
end;

exports
  {== AudioHandler ==}
  CefAudioHandlerRef_Create,
  CefAudioHandler_OnGetAudioParameters,
  CefAudioHandler_OnAudioStreamStarted,
  CefAudioHandler_OnAudioStreamPacket,
  CefAudioHandler_OnAudioStreamStopped,
  CefAudioHandler_OnAudioStreamError,
  {== CommandHandler ==}
  CefCommandHandlerRef_Create,
  CefCommandHandler_OnChromeCommand,
  {== ContextMenuHandler ==}
  CefContextMenuHandlerRef_Create,
  CefContextMenuHandler_OnBeforeContextMenu,
  CefContextMenuHandler_RunContextMenu,
  CefContextMenuHandler_OnContextMenuCommand,
  CefContextMenuHandler_OnContextMenuDismissed,
  CefContextMenuHandler_RunQuickMenu,
  CefContextMenuHandler_OnQuickMenuCommand,
  CefContextMenuHandler_OnQuickMenuDismissed,
  {== DialogHandler ==}
  CefDialogHandlerRef_Create,
  CefDialogHandler_OnFileDialog,
  {== DisplayHandler ==}
  CefDisplayHandlerRef_Create
;
