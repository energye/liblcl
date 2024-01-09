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

// ICefViewDelegate
//procedure  WindowDelegate_SetOnGetPreferredSize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).GetPreferredSizePtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnGetMinimumSize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).GetMinimumSizePtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnGetMaximumSize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).GetMaximumSizePtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnGetHeightForWidth(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).GetHeightForWidthPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnParentViewChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).ParentViewChangedPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnChildViewChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).ChildViewChangedPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnWindowChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).WindowChangedPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnLayoutChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).LayoutChangedPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnFocus(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).FocusPtr := AEventData;
//  handleExceptionEnd
//end;
//
//procedure WindowDelegate_SetOnBlur(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
//begin
//  handleExceptionBegin
//  (AObj as TWindowDelegateRef).BlurPtr := AEventData;
//  handleExceptionEnd
//end;


// ICefWindowDelegate
procedure WindowDelegate_SetOnWindowCreated(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowCreatedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowClosing(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowClosingPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowDestroyed(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowDestroyedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowActivationChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowActivationChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowBoundsChanged(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowBoundsChangedPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetParentWindow(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).GetParentWindowPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnIsWindowModalDialog(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).IsWindowModalDialogPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetInitialBounds(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).GetInitialBoundsPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetInitialShowState(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).GetInitialShowStatePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnIsFrameless(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).IsFramelessPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWithStandardWindowButtons(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WithStandardWindowButtonsPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnGetTitlebarHeight(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).GetTitlebarHeightPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanResize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).CanResizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanMaximize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).CanMaximizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanMinimize(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).CanMinimizePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnCanClose(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).CanClosePtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnAccelerator(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).AcceleratorPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnKeyEvent(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).KeyEventPtr := AEventData;
  handleExceptionEnd
end;

procedure WindowDelegate_SetOnWindowFullscreenTransition(const AObj: ICefWindowDelegate; AEventData: Pointer); extdecl;
begin
  handleExceptionBegin
  (AObj as TWindowDelegateRef).WindowFullscreenTransitionPtr := AEventData;
  handleExceptionEnd
end;



exports
  WindowDelegate_Create,
  WindowDelegate_CreateForCustom,
  //WindowDelegate_SetOnGetPreferredSize,
  //WindowDelegate_SetOnGetMinimumSize,
  //WindowDelegate_SetOnGetMaximumSize,
  //WindowDelegate_SetOnGetHeightForWidth,
  //WindowDelegate_SetOnParentViewChanged,
  //WindowDelegate_SetOnChildViewChanged,
  //WindowDelegate_SetOnWindowChanged,
  //WindowDelegate_SetOnLayoutChanged,
  //WindowDelegate_SetOnFocus,
  //WindowDelegate_SetOnBlur,
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
  WindowDelegate_SetOnWithStandardWindowButtons,
  WindowDelegate_SetOnGetTitlebarHeight,
  WindowDelegate_SetOnCanResize,
  WindowDelegate_SetOnCanMaximize,
  WindowDelegate_SetOnCanMinimize,
  WindowDelegate_SetOnCanClose,
  WindowDelegate_SetOnAccelerator,
  WindowDelegate_SetOnKeyEvent,
  WindowDelegate_SetOnWindowFullscreenTransition;
