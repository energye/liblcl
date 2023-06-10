//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_WinAPICallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
{$ifdef WINDOWS}
  windows,
{$endif WINDOWS}
  LCLType,
  uCEF_LCL_EventCallback;

type

  TWinApiCallback = class
  protected
    FEnumDisplayMonitorsProcPtr: Pointer;
    FEnumFontFamiliesProcPtr: Pointer;
    FEnumFontFamiliesExProcPtr: Pointer;
  public
    function EnumDisplayMonitorsProc(hMonitor: HMONITOR; hdcMonitor: HDC; lprcMonitor: PRect; dwData: LPARAM): longbool;
    function EnumFontFamiliesProc(var ELogFont: TEnumLogFont; var Metric: TNewTextMetric; FontType: longint; Data: LParam): longint;
    function EnumFontFamiliesExProc(var ELogFont: TEnumLogFontEx; var Metric: TNewTextMetricEx; FontType: Longint; Data: LParam): longint;
    property EnumDisplayMonitorsProcPtr: Pointer read FEnumDisplayMonitorsProcPtr write FEnumDisplayMonitorsProcPtr;
    property EnumFontFamiliesProcPtr: Pointer read FEnumFontFamiliesProcPtr write FEnumFontFamiliesProcPtr;
    property EnumFontFamiliesExProcPtr: Pointer read FEnumFontFamiliesExProcPtr write FEnumFontFamiliesExProcPtr;
  end;

var
  WinApiCallback: TWinApiCallback;


implementation

function TWinApiCallback.EnumDisplayMonitorsProc(hMonitor: HMONITOR; hdcMonitor: HDC; lprcMonitor: PRect; dwData: LPARAM): longbool;
begin
  if (EnumDisplayMonitorsProcPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(EnumDisplayMonitorsProcPtr, [hMonitor, hdcMonitor, lprcMonitor, dwData, @Result]);
  end;
end;

function TWinApiCallback.EnumFontFamiliesProc(var ELogFont: TEnumLogFont; var Metric: TNewTextMetric; FontType: longint; Data: LParam): longint;
begin
  if (FEnumFontFamiliesProcPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FEnumFontFamiliesProcPtr, [@ELogFont, @Metric, FontType, Data, @Result]);
  end;
end;

function TWinApiCallback.EnumFontFamiliesExProc(var ELogFont: TEnumLogFontEx; var Metric: TNewTextMetricEx; FontType: Longint; Data: LParam): longint;
begin
  if (FEnumFontFamiliesExProcPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FEnumFontFamiliesExProcPtr, [@ELogFont, @Metric, FontType, Data, @Result]);
  end;
end;


initialization
  begin
    if WinApiCallback = nil then
      WinApiCallback := TWinApiCallback.Create;
  end;


finalization
  begin
    if WinApiCallback <> nil then
      WinApiCallback.Destroy;
  end;

end.
