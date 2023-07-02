//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_MenuModelDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils,uCEFInterfaces, uCEFTypes,
  uCEFMenuModelDelegate,
  uCEF_LCL_EventCallback;

type

  TMenuModelDelegateRef = class(TCefMenuModelDelegateOwn)
  public
    ExecuteCommandPtr: Pointer;
    MouseOutsideMenuPtr: Pointer;
    UnhandledOpenSubmenuPtr: Pointer;
    UnhandledCloseSubmenuPtr: Pointer;
    MenuWillShowPtr: Pointer;
    MenuClosedPtr: Pointer;
    FormatLabelPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure ExecuteCommand(const menuModel: ICefMenuModel; commandId: Integer; eventFlags: TCefEventFlags); override;
    procedure MouseOutsideMenu(const menuModel: ICefMenuModel; const screenPoint: PCefPoint); override;
    procedure UnhandledOpenSubmenu(const menuModel: ICefMenuModel; isRTL: boolean); override;
    procedure UnhandledCloseSubmenu(const menuModel: ICefMenuModel; isRTL: boolean); override;
    procedure MenuWillShow(const menuModel: ICefMenuModel); override;
    procedure MenuClosed(const menuModel: ICefMenuModel); override;
    function  FormatLabel(const menuModel: ICefMenuModel; var label_ : ustring) : boolean; override;

  end;

implementation

procedure TMenuModelDelegateRef.ExecuteCommand(const menuModel: ICefMenuModel; commandId: Integer; eventFlags: TCefEventFlags);
begin
  if (ExecuteCommandPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ExecuteCommandPtr, [menuModel, commandId, eventFlags]);
  end;
end;

procedure TMenuModelDelegateRef.MouseOutsideMenu(const menuModel: ICefMenuModel; const screenPoint: PCefPoint);
begin
  if (MouseOutsideMenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MouseOutsideMenuPtr, [menuModel, screenPoint]);
  end;
end;

procedure TMenuModelDelegateRef.UnhandledOpenSubmenu(const menuModel: ICefMenuModel; isRTL: boolean);
begin
  if (UnhandledOpenSubmenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(UnhandledOpenSubmenuPtr, [menuModel, isRTL]);
  end;
end;

procedure TMenuModelDelegateRef.UnhandledCloseSubmenu(const menuModel: ICefMenuModel; isRTL: boolean);
begin
  if (UnhandledCloseSubmenuPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(UnhandledCloseSubmenuPtr, [menuModel, isRTL]);
  end;
end;

procedure TMenuModelDelegateRef.MenuWillShow(const menuModel: ICefMenuModel);
begin
  if (MenuWillShowPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MenuWillShowPtr, [menuModel]);
  end;
end;

procedure TMenuModelDelegateRef.MenuClosed(const menuModel: ICefMenuModel);
begin
  if (MenuClosedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(MenuClosedPtr, [menuModel]);
  end;
end;

function  TMenuModelDelegateRef.FormatLabel(const menuModel: ICefMenuModel; var label_ : ustring) : boolean;
var
  ResultLabel: PChar;
begin
  Result := False;
  if (FormatLabelPtr <> nil) then
  begin
    ResultLabel := new(PChar);
    TCEFEventCallback.SendEvent(FormatLabelPtr, [menuModel, @ResultLabel, @Result]);
    label_ := UTF8Decode(StrPas(ResultLabel));
    ResultLabel := nil;
  end;
end;


constructor TMenuModelDelegateRef.Create;
begin
  inherited Create;
end;

destructor TMenuModelDelegateRef.Destroy;
begin
  inherited Destroy;
  ExecuteCommandPtr := nil;
  MouseOutsideMenuPtr := nil;
  UnhandledOpenSubmenuPtr := nil;
  UnhandledCloseSubmenuPtr := nil;
  MenuWillShowPtr := nil;
  MenuClosedPtr := nil;
  FormatLabelPtr := nil;
end;

end.
