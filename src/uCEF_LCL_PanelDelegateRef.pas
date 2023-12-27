//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_PanelDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TPanelDelegateRef = class
  public
    constructor Create;
    destructor Destroy;
  protected

  end;

implementation

constructor TPanelDelegateRef.Create;
begin
end;

destructor TPanelDelegateRef.Destroy;
begin
end;

end.
