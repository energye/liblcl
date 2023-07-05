//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFWorkScheduler_StopScheduler(); extdecl;
begin
  if GlobalCEFWorkScheduler <> nil then
     GlobalCEFWorkScheduler.StopScheduler;
end;

procedure CEFWorkScheduler_Create(const AOwner: TComponent; out Result: TCEFWorkScheduler); extdecl;
begin
  if GlobalCEFWorkScheduler = nil then
   GlobalCEFWorkScheduler := TCEFWorkScheduler.Create(AOwner);
  Result := GlobalCEFWorkScheduler;
end;

procedure CEFWorkScheduler_CreateDelayed(out Result: TCEFWorkScheduler); extdecl;
begin
  if GlobalCEFWorkScheduler = nil then
   GlobalCEFWorkScheduler := TCEFWorkScheduler.CreateDelayed;
  Result := GlobalCEFWorkScheduler;
end;

procedure CEFWorkScheduler_CreateThread(); extdecl;
begin
  if GlobalCEFWorkScheduler <> nil then
    GlobalCEFWorkScheduler.CreateThread;
end;

procedure CEFWorkScheduler_Destroy(); extdecl;
begin
  DestroyGlobalCEFWorkScheduler;
end;

function CEFWorkScheduler_GetPriority(): TThreadPriority; // default  tpNormal;
begin
  Result := tpNormal;
{$IFDEF MSWINDOWS}
{$WARN SYMBOL_PLATFORM OFF}
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.Priority;
  end;
{$WARN SYMBOL_PLATFORM ON}
{$ENDIF}
end;

procedure CEFWorkScheduler_SetPriority(AValue: Integer); // default  tpNormal;
begin
{$IFDEF MSWINDOWS}
{$WARN SYMBOL_PLATFORM OFF}
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.Priority := TThreadPriority(AValue);
  end;
{$WARN SYMBOL_PLATFORM ON}
{$ENDIF}
end;

function CEFWorkScheduler_GetDefaultInterval(): integer; extdecl; // default  CEF_TIMER_MAXDELAY;
begin
  Result := CEF_TIMER_MAXDELAY;
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DefaultInterval;
  end;
end;

function CEFWorkScheduler_GetDepleteWorkCycles(): cardinal; extdecl; // default  CEF_TIMER_DEPLETEWORK_CYCLES;
begin
  Result := CEF_TIMER_DEPLETEWORK_CYCLES;
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DepleteWorkCycles;
  end;
end;

function CEFWorkScheduler_GetDepleteWorkDelay(): cardinal; extdecl; // default  CEF_TIMER_DEPLETEWORK_DELAY;
begin
  Result := CEF_TIMER_DEPLETEWORK_DELAY;
  if GlobalCEFWorkScheduler <> nil then
  begin
    Result := GlobalCEFWorkScheduler.DepleteWorkDelay;
  end;
end;

function CEFWorkScheduler_GetUseQueueThread(): LongBool; extdecl; // default  False;
begin
  Result := False;
  if GlobalCEFWorkScheduler <> nil then
  begin
  end;
end;

procedure CEFWorkScheduler_SetDefaultInterval(AValue:  integer); extdecl; // default  CEF_TIMER_MAXDELAY;
begin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DefaultInterval := AValue;
  end;
end;

procedure CEFWorkScheduler_SetDepleteWorkCycles(AValue:  cardinal); extdecl; // default  CEF_TIMER_DEPLETEWORK_CYCLES;
begin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DepleteWorkCycles := AValue;
  end;
end;

procedure CEFWorkScheduler_SetDepleteWorkDelay(AValue:  cardinal); extdecl; // default  CEF_TIMER_DEPLETEWORK_DELAY;
begin
  if GlobalCEFWorkScheduler <> nil then
  begin
    GlobalCEFWorkScheduler.DepleteWorkDelay := AValue;
  end;
end;

procedure CEFWorkScheduler_SetUseQueueThread(AValue:  LongBool); extdecl; // default  False;
begin
  if GlobalCEFWorkScheduler <> nil then
  begin
  end;
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
  CEFWorkScheduler_SetUseQueueThread
;

