//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_IPCWindowMoveDrag;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  SysUtils, uGoForm, Forms, SyncObjs,
  uCEFTypes, uCEFInterfaces,
  uCEF_LCL_Entity;

type

  TIPCWindowMoveDrag = class
  private
    GoForm: TGoForm;
    BrowserId: integer;
    DX, DY: integer;
    WinTop, WinLeft, WinWidth, WinHeight: integer;
    CriticalSection: TCriticalSection;
  public
    constructor Create;
    destructor Destroy;
  public
    //procedure SendCompMessage(aData: PtrInt);
    procedure Move(aData: PtrInt);
    function Execute(const Name: ustring; const message: ICefProcessMessage): boolean;
  end;



implementation

//函数执行处理
function TIPCWindowMoveDrag.Execute(const Name: ustring; const message: ICefProcessMessage): boolean;
var
  mex, mey: integer;
  MX, MY: integer;
begin
  browserId := message.ArgumentList.GetInt(0);
  if Name = MoveDragDown then
  begin
    GoForm := TBrowserWindowClass.Get(browserId);
    if GoForm <> nil then
    begin
      DX := message.ArgumentList.GetInt(1);
      DY := message.ArgumentList.GetInt(2);
      WinTop := GoForm.Top;
      WinLeft := GoForm.Left;
      //WinWidth := GoForm.Width;
      //WinHeight := GoForm.Height;
    end;
  end
  else if Name = MoveDragMove then
  begin
    if (GoForm <> nil) and (browserId <> 0) then
    begin
      MX := message.ArgumentList.GetInt(1);
      MY := message.ArgumentList.GetInt(2);
      mex := MX - (DX - WinLeft);
      mey := MY - (DY - WinTop);
      WinLeft := mex;
      WinTop := mey;
      Application.QueueAsyncCall(@Move, 0);
    end;
  end
  else if Name = MoveDragUp then
  begin
    browserId := 0;
  end
  else
  begin
    Result := False;
    exit;
  end;
  Result := True;
end;

procedure TIPCWindowMoveDrag.Move(aData: PtrInt);
begin
  try
    CriticalSection.Acquire;
    GoForm.Top := WinTop;
    GoForm.Left := WinLeft;
  finally
    CriticalSection.Release;
  end;
end;

constructor TIPCWindowMoveDrag.Create;
begin
  GoForm := nil;
  BrowserId := 0;
  DX := 0;
  DY := 0;
  WinTop := 0;
  WinLeft := 0;
  WinWidth := 0;
  WinHeight := 0;
  CriticalSection := TCriticalSection.Create;
end;

destructor TIPCWindowMoveDrag.Destroy;
begin
  GoForm := nil;
  BrowserId := 0;
  DX := 0;
  DY := 0;
  WinTop := 0;
  WinLeft := 0;
  WinWidth := 0;
  WinHeight := 0;
  FreeAndNil(CriticalSection);
end;

end.
