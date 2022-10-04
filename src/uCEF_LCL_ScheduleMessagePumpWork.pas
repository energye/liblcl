//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ScheduleMessagePumpWork;

{$mode ObjFPC}{$H+}
{$I cef.inc}

interface

uses
  //uCEF_LCL_ConsoleWrite, SysUtils,
  uCEFWorkScheduler;

procedure GlobalCEFApp_OnScheduleMessagePumpWork(const aDelayMS: int64);

implementation

procedure GlobalCEFApp_OnScheduleMessagePumpWork(const aDelayMS: int64);
begin
  if (GlobalCEFWorkScheduler <> nil) then
  begin
    //ConsoleLn('OnScheduleMessagePumpWork aDelayMS: ' + IntToStr(aDelayMS) + '  time: ' +FloatToStr(now));
    GlobalCEFWorkScheduler.ScheduleMessagePumpWork(aDelayMS);
  end;
end;

end.
