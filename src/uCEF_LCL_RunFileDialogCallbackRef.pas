//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_RunFileDialogCallbackRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils,
  uCEFRunFileDialogCallback,
  uCEF_LCL_EventCallback;

type

  TRunFileDialogCallbackRef = class(TCefRunFileDialogCallbackOwn)
  public
    FileDialogDismissedPtr: Pointer;
    constructor Create;
    destructor Destroy; override;
  protected
    procedure OnFileDialogDismissed(selectedAcceptFilter: Integer; const filePaths: TStrings); override;

  end;

implementation

procedure TRunFileDialogCallbackRef.OnFileDialogDismissed(selectedAcceptFilter: Integer; const filePaths: TStrings);
begin
  if (FileDialogDismissedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FileDialogDismissedPtr, [filePaths]);
  end
  else
    inherited OnFileDialogDismissed(selectedAcceptFilter, filePaths);
end;

constructor TRunFileDialogCallbackRef.Create;
begin
  inherited Create;
end;

destructor TRunFileDialogCallbackRef.Destroy;
begin
  inherited Destroy;
  FileDialogDismissedPtr := nil;
end;

end.
