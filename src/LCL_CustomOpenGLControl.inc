
//property
function CustomOpenGLControl_SharingControls(AObj: TCustomOpenGLControl; Index: integer): TCustomOpenGLControl; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SharingControls[Index];
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_FrameDiffTimeInMSecs(AObj: TCustomOpenGLControl): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.FrameDiffTimeInMSecs;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_SharedControl(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: TCustomOpenGLControl): TCustomOpenGLControl; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.SharedControl := AValue;
  end else
    Result := AObj.SharedControl;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_AutoResizeViewport(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.AutoResizeViewport := AValue;
  end else
    Result := AObj.AutoResizeViewport;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_DebugContext(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.DebugContext := AValue;
  end else
    Result := AObj.DebugContext;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_RGBA(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.RGBA := AValue;
  end else
    Result := AObj.RGBA;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_RedBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.RedBits := AValue;
  end else
    Result := AObj.RedBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_GreenBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.GreenBits := AValue;
  end else
    Result := AObj.GreenBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_BlueBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.BlueBits := AValue;
  end else
    Result := AObj.BlueBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_OpenGLMajorVersion(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.OpenGLMajorVersion := AValue;
  end else
    Result := AObj.OpenGLMajorVersion;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_OpenGLMinorVersion(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.OpenGLMinorVersion := AValue;
  end else
    Result := AObj.OpenGLMinorVersion;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_MultiSampling(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.MultiSampling := AValue;
  end else
    Result := AObj.MultiSampling;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_AlphaBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.AlphaBits := AValue;
  end else
    Result := AObj.AlphaBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_DepthBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.DepthBits := AValue;
  end else
    Result := AObj.DepthBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_StencilBits(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.StencilBits := AValue;
  end else
    Result := AObj.StencilBits;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_AUXBuffers(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: uint32): uint32; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.AUXBuffers := AValue;
  end else
    Result := AObj.AUXBuffers;
  handleExceptionEnd
end;

//property
function CustomOpenGLControl_Options(AIsSet: LongBool; AObj: TCustomOpenGLControl; AValue: TOpenGLControlOptions): TOpenGLControlOptions; extdecl;
begin
  handleExceptionBegin
  if AIsSet then
  begin
    AObj.Options := AValue;
  end else
    Result := AObj.Options;
  handleExceptionEnd
end;

//function
function CustomOpenGLControl_MakeCurrent(AObj: TCustomOpenGLControl; SaveOldToStack: LongBool): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.MakeCurrent(SaveOldToStack);
  handleExceptionEnd
end;

//function
function CustomOpenGLControl_ReleaseContext(AObj: TCustomOpenGLControl): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.ReleaseContext();
  handleExceptionEnd
end;

//function
function CustomOpenGLControl_RestoreOldOpenGLControl(AObj: TCustomOpenGLControl): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.RestoreOldOpenGLControl();
  handleExceptionEnd
end;

//function
function CustomOpenGLControl_SharingControlCount(AObj: TCustomOpenGLControl): integer; extdecl;
begin
  handleExceptionBegin
  Result := AObj.SharingControlCount();
  handleExceptionEnd
end;

//procedure
procedure CustomOpenGLControl_Paint(AObj: TCustomOpenGLControl); extdecl;
begin
  handleExceptionBegin
  AObj.Paint();
  handleExceptionEnd
end;

//procedure
procedure CustomOpenGLControl_RealizeBounds(AObj: TCustomOpenGLControl); extdecl;
begin
  handleExceptionBegin
  AObj.RealizeBounds();
  handleExceptionEnd
end;

//procedure
procedure CustomOpenGLControl_DoOnPaint(AObj: TCustomOpenGLControl); extdecl;
begin
  handleExceptionBegin
  AObj.DoOnPaint();
  handleExceptionEnd
end;

//procedure
procedure CustomOpenGLControl_SwapBuffers(AObj: TCustomOpenGLControl); extdecl;
begin
  handleExceptionBegin
  AObj.SwapBuffers();
  handleExceptionEnd
end;

//property event
procedure CustomOpenGLControl_SetOnMakeCurrent(AObj: TCustomOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTOpenGlCtrlMakeCurrentEvent}
  {$DEFINE EventName := OnMakeCurrent}
  EventMethodCode
end;

//property event
procedure CustomOpenGLControl_SetOnPaint(AObj: TCustomOpenGLControl; AEventData: Pointer); extdecl;
begin
  {$DEFINE EventMethodName := OnTNotifyEvent}
  {$DEFINE EventName := OnPaint}
  EventMethodCode
end;


exports
  CustomOpenGLControl_SharingControls,
  CustomOpenGLControl_FrameDiffTimeInMSecs,
  CustomOpenGLControl_SharedControl,
  CustomOpenGLControl_AutoResizeViewport,
  CustomOpenGLControl_DebugContext,
  CustomOpenGLControl_RGBA,
  CustomOpenGLControl_RedBits,
  CustomOpenGLControl_GreenBits,
  CustomOpenGLControl_BlueBits,
  CustomOpenGLControl_OpenGLMajorVersion,
  CustomOpenGLControl_OpenGLMinorVersion,
  CustomOpenGLControl_MultiSampling,
  CustomOpenGLControl_AlphaBits,
  CustomOpenGLControl_DepthBits,
  CustomOpenGLControl_StencilBits,
  CustomOpenGLControl_AUXBuffers,
  CustomOpenGLControl_Options,
  CustomOpenGLControl_MakeCurrent,
  CustomOpenGLControl_ReleaseContext,
  CustomOpenGLControl_RestoreOldOpenGLControl,
  CustomOpenGLControl_SharingControlCount,
  CustomOpenGLControl_Paint,
  CustomOpenGLControl_RealizeBounds,
  CustomOpenGLControl_DoOnPaint,
  CustomOpenGLControl_SwapBuffers,
  CustomOpenGLControl_SetOnMakeCurrent,
  CustomOpenGLControl_SetOnPaint;
