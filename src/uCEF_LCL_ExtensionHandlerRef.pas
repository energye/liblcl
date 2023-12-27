//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ExtensionHandlerRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFInterfaces,
  uCEF_LCL_EventCallback;

type

  TExtensionHandlerRef = class
  public
    ExtensionLoadFailedPtr: Pointer;
    ExtensionLoadedPtr: Pointer;
    ExtensionUnloadedPtr: Pointer;
    BeforeBackgroundBrowserPtr: Pointer;
    BeforeBrowserPtr: Pointer;
    GetActiveBrowserPtr: Pointer;
    CanAccessBrowserPtr: Pointer;
    GetExtensionResourcePtr: Pointer;
    constructor Create;
    destructor Destroy;
  protected

  end;

implementation


constructor TExtensionHandlerRef.Create;
begin
end;

destructor TExtensionHandlerRef.Destroy;
begin
end;

end.
