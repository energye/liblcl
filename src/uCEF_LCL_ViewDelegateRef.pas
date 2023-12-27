//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ViewDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_EventCallback;

type

  TViewDelegateRef = class
    GetPreferredSizePtr: Pointer;
    GetMinimumSizePtr: Pointer;
    GetMaximumSizePtr: Pointer;
    GetHeightForWidthPtr: Pointer;
    ParentViewChangedPtr: Pointer;
    ChildViewChangedPtr: Pointer;
    WindowChangedPtr: Pointer;
    LayoutChangedPtr: Pointer;
    FocusPtr: Pointer;
    BlurPtr: Pointer;
    constructor Create;
    destructor Destroy;

  end;

implementation


constructor TViewDelegateRef.Create;
begin
end;

destructor TViewDelegateRef.Destroy;
begin
end;

end.
