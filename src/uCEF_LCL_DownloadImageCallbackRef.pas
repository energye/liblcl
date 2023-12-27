//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_DownloadImageCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFTypes, uCEFInterfaces,
  uCEF_LCL_EventCallback;

type

  TDownloadImageCallbackRef = class
  public
    DownloadImageFinishedPtr: Pointer;
    constructor Create;
    destructor Destroy;

  end;

implementation


constructor TDownloadImageCallbackRef.Create;
begin
end;

destructor TDownloadImageCallbackRef.Destroy;
begin
end;

end.
