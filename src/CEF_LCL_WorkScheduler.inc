//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFWorkScheduler_StopScheduler(); extdecl;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
    GlobalCEFWorkScheduler.StopScheduler;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_Create(const AOwner: TComponent; out Result: TCEFWorkScheduler); extdecl;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler = nil then
    GlobalCEFWorkScheduler := TCEFWorkScheduler.Create(AOwner);
  Result := GlobalCEFWorkScheduler;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_CreateDelayed(out Result: TCEFWorkScheduler); extdecl;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler = nil then
    GlobalCEFWorkScheduler := TCEFWorkScheduler.CreateDelayed;
  Result := GlobalCEFWorkScheduler;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_CreateThread(); extdecl;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
    GlobalCEFWorkScheduler.CreateThread;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_Destroy(); extdecl;
begin
  handleExceptionBegin
  DestroyGlobalCEFWorkScheduler;
  handleExceptionEnd
end;

function CEFWorkScheduler_GetPriority(): TThreadPriority; extdecl;// default  tpNormal;
begin
  Result := tpNormal;
  handleExceptionBegin
    {$IFDEF MSWINDOWS}
    {$WARN SYMBOL_PLATFORM OFF}
      if GlobalCEFWorkScheduler <> nil then
      begin
        Result := GlobalCEFWorkScheduler.Priority;
      end;
    {$WARN SYMBOL_PLATFORM ON}
    {$ENDIF}
  handleExceptionEnd
end;

procedure CEFWorkScheduler_SetPriority(AValue: Integer); extdecl;// default  tpNormal;
begin
  handleExceptionBegin
    {$IFDEF MSWINDOWS}
    {$WARN SYMBOL_PLATFORM OFF}
      if GlobalCEFWorkScheduler <> nil then
      begin
        GlobalCEFWorkScheduler.Priority := TThreadPriority(AValue);
      end;
    {$WARN SYMBOL_PLATFORM ON}
    {$ENDIF}
  handleExceptionEnd
end;

function CEFWorkScheduler_GetDefaultInterval(): integer; extdecl; // default  CEF_TIMER_MAXDELAY;
begin
  Result := CEF_TIMER_MAXDELAY;
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DefaultInterval;
  end;
  handleExceptionEnd
end;

function CEFWorkScheduler_GetDepleteWorkCycles(): cardinal; extdecl; // default  CEF_TIMER_DEPLETEWORK_CYCLES;
begin
  Result := CEF_TIMER_DEPLETEWORK_CYCLES;
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DepleteWorkCycles;
  end;
  handleExceptionEnd
end;

function CEFWorkScheduler_GetDepleteWorkDelay(): cardinal; extdecl; // default  CEF_TIMER_DEPLETEWORK_DELAY;
begin
  Result := CEF_TIMER_DEPLETEWORK_DELAY;
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DepleteWorkDelay;
  end;
  handleExceptionEnd
end;

function CEFWorkScheduler_GetUseQueueThread(): LongBool; extdecl; // default  False;
begin
  Result := False;
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.UseQueueThread;
  end;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_SetDefaultInterval(AValue:  integer); extdecl; // default  CEF_TIMER_MAXDELAY;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DefaultInterval := AValue;
  end;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_SetDepleteWorkCycles(AValue:  cardinal); extdecl; // default  CEF_TIMER_DEPLETEWORK_CYCLES;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DepleteWorkCycles := AValue;
  end;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_SetDepleteWorkDelay(AValue:  cardinal); extdecl; // default  CEF_TIMER_DEPLETEWORK_DELAY;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DepleteWorkDelay := AValue;
  end;
  handleExceptionEnd
end;

procedure CEFWorkScheduler_SetUseQueueThread(AValue:  LongBool); extdecl; // default  False;
begin
  handleExceptionBegin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.UseQueueThread := AValue;
  end;
  handleExceptionEnd
end;

exports
  CEFWorkScheduler_StopScheduler,
  CEFWorkScheduler_Create,
  CEFWorkScheduler_CreateDelayed,
  CEFWorkScheduler_CreateThread,
  CEFWorkScheduler_Destroy,
  CEFWorkScheduler_GetPriority,
  CEFWorkScheduler_SetPriority,
  CEFWorkScheduler_GetDefaultInterval,
  CEFWorkScheduler_GetDepleteWorkCycles,
  CEFWorkScheduler_GetDepleteWorkDelay,
  CEFWorkScheduler_GetUseQueueThread,
  CEFWorkScheduler_SetDefaultInterval,
  CEFWorkScheduler_SetDepleteWorkCycles,
  CEFWorkScheduler_SetDepleteWorkDelay,
  CEFWorkScheduler_SetUseQueueThread;