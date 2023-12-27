//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_BrowserViewDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_Entity,
  uCEF_LCL_EventCallback;

type

  TBrowserViewDelegateRef = class
  public
    BrowserCreatedPtr: Pointer;
    BrowserDestroyedPtr: Pointer;
    GetDelegateForPopupBrowserViewPtr: Pointer;
    PopupBrowserViewCreatedPtr: Pointer;
    constructor Create;
    destructor Destroy;

  end;

implementation


constructor TBrowserViewDelegateRef.Create;
begin
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
end;

end.
