//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_PdfPrintCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEFTypes, uCEFPDFPrintCallback,
  uCEF_LCL_EventCallback;

type

  TPdfPrintCallbackRef = class(TCefPdfPrintCallbackOwn)
  public
    PdfPrintFinishedPtr: Pointer;
    constructor Create;
    destructor Destroy;
  protected
    procedure OnPdfPrintFinished(const path: ustring; ok: Boolean); override;
  end;

implementation

procedure TPdfPrintCallbackRef.OnPdfPrintFinished(const path: ustring; ok: Boolean);
begin
  if (PdfPrintFinishedPtr <> nil) then
  begin
    SendEvent(PdfPrintFinishedPtr, [PChar(string(path)), ok]);
  end;
end;

constructor TPdfPrintCallbackRef.Create;
begin
  inherited Create;
end;

destructor TPdfPrintCallbackRef.Destroy;
begin
  inherited Destroy;
end;

end.
