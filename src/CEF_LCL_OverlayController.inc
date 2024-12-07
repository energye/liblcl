//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure OverlayControllerRefRef_UnWrap(const AObj: ICefOverlayController; out Result: ICefOverlayController); extdecl;
begin
  handleExceptionBegin
  Result := TCefOverlayControllerRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function  OverlayController_IsValid(const AObj: ICefOverlayController): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsValid();
  handleExceptionEnd
end;

function  OverlayController_IsSame(const AObj: ICefOverlayController; const that: ICefOverlayController): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSame(that);
  handleExceptionEnd
end;

procedure  OverlayController_GetContentsView(const AObj: ICefOverlayController; out Result: ICefView); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetContentsView();
  handleExceptionEnd
end;

procedure  OverlayController_GetWindow(const AObj: ICefOverlayController; out Result: ICefWindow); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetWindow();
  handleExceptionEnd
end;

function  OverlayController_GetDockingMode(const AObj: ICefOverlayController): TCefDockingMode; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetDockingMode();
  handleExceptionEnd
end;

procedure OverlayController_DestroyOverlay(const AObj: ICefOverlayController); extdecl;
begin
  handleExceptionBegin
  AObj.DestroyOverlay();
  handleExceptionEnd
end;

procedure OverlayController_SetBounds(const AObj: ICefOverlayController; var bounds: TCefRect); extdecl;
begin
  handleExceptionBegin
  AObj.SetBounds(bounds);
  handleExceptionEnd
end;

procedure  OverlayController_GetBounds(const AObj: ICefOverlayController; out Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetBounds();
  handleExceptionEnd
end;

procedure  OverlayController_GetBoundsInScreen(const AObj: ICefOverlayController; out Result: TCefRect); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetBoundsInScreen();
  handleExceptionEnd
end;

procedure OverlayController_SetSize(const AObj: ICefOverlayController; var size: TCefSize); extdecl;
begin
  handleExceptionBegin
  AObj.SetSize(size);
  handleExceptionEnd
end;

procedure  OverlayController_GetSize(const AObj: ICefOverlayController; out Result: TCefSize); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSize();
  handleExceptionEnd
end;

procedure OverlayController_SetPosition(const AObj: ICefOverlayController; var position: TCefPoint); extdecl;
begin
  handleExceptionBegin
  AObj.SetPosition(position);
  handleExceptionEnd
end;

procedure  OverlayController_GetPosition(const AObj: ICefOverlayController; out Result: TCefPoint); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetPosition();
  handleExceptionEnd
end;

procedure OverlayController_SetInsets(const AObj: ICefOverlayController; var insets: TCefInsets); extdecl;
begin
  handleExceptionBegin
  AObj.SetInsets(insets);
  handleExceptionEnd
end;

procedure  OverlayController_GetInsets(const AObj: ICefOverlayController; out Result: TCefInsets) ; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetInsets();
  handleExceptionEnd
end;

procedure OverlayController_SizeToPreferredSize(const AObj: ICefOverlayController); extdecl;
begin
  handleExceptionBegin
 AObj.SizeToPreferredSize();
  handleExceptionEnd
end;

procedure OverlayController_SetVisible(const AObj: ICefOverlayController; visible: LongBool); extdecl;
begin
  handleExceptionBegin
  AObj.SetVisible(visible);
  handleExceptionEnd
end;

function  OverlayController_IsVisible(const AObj: ICefOverlayController): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsVisible();
  handleExceptionEnd
end;

function  OverlayController_IsDrawn(const AObj: ICefOverlayController): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsDrawn();
  handleExceptionEnd
end;


exports
  OverlayControllerRefRef_UnWrap,
  OverlayController_IsValid,
  OverlayController_IsSame,
  OverlayController_GetContentsView,
  OverlayController_GetWindow,
  OverlayController_GetDockingMode,
  OverlayController_DestroyOverlay,
  OverlayController_SetBounds,
  OverlayController_GetBounds,
  OverlayController_GetBoundsInScreen,
  OverlayController_SetSize,
  OverlayController_GetSize,
  OverlayController_SetPosition,
  OverlayController_GetPosition,
  OverlayController_SetInsets,
  OverlayController_GetInsets,
  OverlayController_SizeToPreferredSize,
  OverlayController_SetVisible,
  OverlayController_IsVisible,
  OverlayController_IsDrawn;
