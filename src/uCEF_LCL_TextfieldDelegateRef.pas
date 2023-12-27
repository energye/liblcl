//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_TextfieldDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TTextfieldDelegateRef = class
  public
    KeyEventPtr: Pointer;
    AfterUserActionPtr: Pointer;
    constructor Create;
    destructor Destroy;
  end;

implementation

constructor TTextfieldDelegateRef.Create;
begin
end;

destructor TTextfieldDelegateRef.Destroy;
begin
end;

end.
