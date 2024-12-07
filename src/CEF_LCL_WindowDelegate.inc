//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure WindowDelegate_Create(out Result: ICefWindowDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TWindowDelegateRef.Create();
  handleExceptionEnd
end;

procedure WindowDelegate_CreateForCustom(const events: ICefWindowDelegateEvents; out Result: ICefWindowDelegate) ; extdecl;
begin
  handleExceptionBegin
  Result := TCustomWindowDelegate.Create(events);
  handleExceptionEnd
end;

// ICefWindowDelegate
procedure WindowDelegate_SetOnWindowCreated(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnWindowCreatedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowClosing(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnWindowClosingPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowDestroyed(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnWindowDestroyedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowActivationChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnWindowActivationChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowBoundsChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnWindowBoundsChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetParentWindow(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnGetParentWindowPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnIsWindowModalDialog(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnIsWindowModalDialogPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetInitialBounds(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnGetInitialBoundsPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetInitialShowState(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnGetInitialShowStatePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnIsFrameless(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnIsFramelessPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanResize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnCanResizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanMaximize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnCanMaximizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanMinimize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnCanMinimizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanClose(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnCanClosePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnAccelerator(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnAcceleratorPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnKeyEvent(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).OnKeyEventPtr := AEventData;
  handleExceptionEnd
end;


exports
  WindowDelegate_Create,
  WindowDelegate_CreateForCustom,
  WindowDelegate_SetOnWindowCreated,
  WindowDelegate_SetOnWindowClosing,
  WindowDelegate_SetOnWindowDestroyed,
  WindowDelegate_SetOnWindowActivationChanged,
  WindowDelegate_SetOnWindowBoundsChanged,
  WindowDelegate_SetOnGetParentWindow,
  WindowDelegate_SetOnIsWindowModalDialog,
  WindowDelegate_SetOnGetInitialBounds,
  WindowDelegate_SetOnGetInitialShowState,
  WindowDelegate_SetOnIsFrameless,
  WindowDelegate_SetOnCanResize,
  WindowDelegate_SetOnCanMaximize,
  WindowDelegate_SetOnCanMinimize,
  WindowDelegate_SetOnCanClose,
  WindowDelegate_SetOnAccelerator,
  WindowDelegate_SetOnKeyEvent;
