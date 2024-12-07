//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MediaSinkDeviceInfoCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFInterfaces, uCEFMediaSinkDeviceInfoCallback, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TMediaSinkDeviceInfoCallbackRef = class(TCefMediaSinkDeviceInfoCallbackOwn)
  public
    OnMediaSinkDeviceInfoPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
      procedure OnMediaSinkDeviceInfo(const ip_address: ustring; port: integer; const model_name: ustring); override;
  end;

implementation

procedure TMediaSinkDeviceInfoCallbackRef.OnMediaSinkDeviceInfo(const ip_address: ustring; port: integer; const model_name: ustring);
begin
  if (OnMediaSinkDeviceInfoPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnMediaSinkDeviceInfoPtr, [PChar(ip_address), port, PChar(model_name)]);
  end;
end;

constructor TMediaSinkDeviceInfoCallbackRef.Create;
begin
  inherited Create;
  OnMediaSinkDeviceInfoPtr := nil;
end;

destructor TMediaSinkDeviceInfoCallbackRef.Destroy;
begin
  OnMediaSinkDeviceInfoPtr := nil;
  inherited Destroy;
end;

end.
