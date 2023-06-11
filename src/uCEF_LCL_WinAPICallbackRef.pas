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
  uCEF_LCL_Entity,
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
    function EnumFontFamiliesExProc(var ELogFont: TEnumLogFontEx; var Metric: TNewTextMetricEx; FontType: longint; Data: LParam): longint;
    property EnumDisplayMonitorsProcPtr: Pointer read FEnumDisplayMonitorsProcPtr write FEnumDisplayMonitorsProcPtr;
    property EnumFontFamiliesProcPtr: Pointer read FEnumFontFamiliesProcPtr write FEnumFontFamiliesProcPtr;
    property EnumFontFamiliesExProcPtr: Pointer read FEnumFontFamiliesExProcPtr write FEnumFontFamiliesExProcPtr;
  end;

  REnumLogFont = record
    elfLogFont: Pointer;
    lfFaceName: Pointer;  //32
    elfFullName: Pointer; //64
    elfStyle: Pointer;    //32
  end;

  REnumLogFontEx = record
    elfLogFont: Pointer;
    lfFaceName: Pointer;  //32
    elfFullName: Pointer; //64
    elfStyle: Pointer;    //32
    elfScript: Pointer;   //32
  end;


  RFontSignature = record
    fsUsb: Pointer; // 4
    fsCsb: Pointer; // 2
  end;

  RNewTextMetricEx = record
    ntmentm: Pointer;
    ntmeFontSignature: Pointer; // RFontSignature
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
var
  EnumLogFont: REnumLogFont;
begin
  if (FEnumFontFamiliesProcPtr <> nil) then
  begin
    EnumLogFont.elfLogFont := @ELogFont.elfLogFont;
    EnumLogFont.lfFaceName := @ELogFont.elfLogFont.lfFaceName[0];
    EnumLogFont.elfFullName := @ELogFont.elfFullName[0];
    EnumLogFont.elfStyle := @ELogFont.elfStyle[0];
    TCEFEventCallback.SendEvent(FEnumFontFamiliesProcPtr, [@EnumLogFont, @Metric, FontType, Data, @Result]);
  end;
end;

function TWinApiCallback.EnumFontFamiliesExProc(var ELogFont: TEnumLogFontEx; var Metric: TNewTextMetricEx; FontType: longint; Data: LParam): longint;
var
  EnumLogFont: REnumLogFontEx;
  NewTextMetricEx: RNewTextMetricEx;
  FontSignature: RFontSignature;
begin
  if (FEnumFontFamiliesExProcPtr <> nil) then
  begin
    EnumLogFont.elfLogFont := @ELogFont.elfLogFont;
    EnumLogFont.lfFaceName := @ELogFont.elfLogFont.lfFaceName[0];
    EnumLogFont.elfFullName := @ELogFont.elfFullName[0];
    EnumLogFont.elfStyle := @ELogFont.elfStyle[0];
    EnumLogFont.elfScript := @ELogFont.elfScript[0];
    // ----
    NewTextMetricEx.ntmentm := @Metric.ntmentm;
    FontSignature.fsUsb := @Metric.ntmeFontSignature.fsUsb[0];
    FontSignature.fsCsb := @Metric.ntmeFontSignature.fsCsb[0];
    NewTextMetricEx.ntmeFontSignature := @FontSignature;
    TCEFEventCallback.SendEvent(FEnumFontFamiliesExProcPtr, [@EnumLogFont, @NewTextMetricEx, FontType, Data, @Result]);
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
