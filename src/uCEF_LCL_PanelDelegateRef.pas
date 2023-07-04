//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_PanelDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils,uCEFInterfaces, uCEFTypes,
  uCEFPanelDelegate,
  uCEF_LCL_EventCallback;

type

  TPanelDelegateRef = class(TCefPanelDelegateOwn)
  public
    constructor Create; override;
    destructor Destroy; override;
  protected

  end;

implementation

constructor TPanelDelegateRef.Create;
begin
  inherited Create;
end;

destructor TPanelDelegateRef.Destroy;
begin
  inherited Destroy;
end;

end.
