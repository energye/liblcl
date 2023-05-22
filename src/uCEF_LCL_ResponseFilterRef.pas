//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ResponseFilterRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFResponseFilter,
  uCEF_LCL_EventCallback;

type

  TResponseFilterRef = class(TCefResponseFilterOwn)
  public
    InitFilterPtr: Pointer;
    FilterPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    function InitFilter: boolean; override;
    function Filter(data_in: Pointer; data_in_size: nativeuint; var data_in_read: nativeuint; data_out: Pointer; data_out_size: nativeuint; var data_out_written: nativeuint): TCefResponseFilterStatus; override;

  end;

implementation

function TResponseFilterRef.InitFilter(): boolean;
begin
  Result := False;
  if (InitFilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(InitFilterPtr, [@Result]);
  end;
end;

function TResponseFilterRef.Filter(data_in: Pointer; data_in_size: nativeuint; var data_in_read: nativeuint; data_out: Pointer; data_out_size: nativeuint; var data_out_written: nativeuint): TCefResponseFilterStatus;
var
  RetStatus: integer;
begin
  Result := RESPONSE_FILTER_DONE;
  if (FilterPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FilterPtr, [data_in, data_in_size, @data_in_read, data_out, data_out_size, @data_out_written, @RetStatus]);
    Result := TCefResponseFilterStatus(RetStatus);
  end;
end;

constructor TResponseFilterRef.Create;
begin
  inherited Create;
  InitFilterPtr := nil;
  FilterPtr := nil;
end;

destructor TResponseFilterRef.Destroy;
begin
  inherited Destroy;
  InitFilterPtr := nil;
  FilterPtr := nil;
end;

end.
