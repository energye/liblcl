//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CEFWorkScheduler_Stop(); extdecl;
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

exports
  CEFWorkScheduler_Stop,
  CEFWorkScheduler_Create,
  CEFWorkScheduler_CreateDelayed,
  CEFWorkScheduler_CreateThread,
  CEFWorkScheduler_Destroy
;

