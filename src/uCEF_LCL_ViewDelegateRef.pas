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
  uCEFViewDelegate,
  uCEF_LCL_EventCallback;

type

  TViewDelegateRef = class(TCefViewDelegateOwn)
    GetPreferredSizePtr: Pointer;
    GetMinimumSizePtr: Pointer;
    GetMaximumSizePtr: Pointer;
    GetHeightForWidthPtr: Pointer;
    ParentViewChangedPtr: Pointer;
    ChildViewChangedPtr: Pointer;
    FocusPtr: Pointer;
    BlurPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnGetPreferredSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMinimumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMaximumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer); override;
    procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
    procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;

  end;

implementation

procedure TViewDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TViewDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TViewDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TViewDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TViewDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TViewDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TViewDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TViewDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;


constructor TViewDelegateRef.Create;
begin
  inherited Create;
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;
end;

destructor TViewDelegateRef.Destroy;
begin
  inherited Destroy;
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;
end;

end.
