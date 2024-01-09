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
  uCEFTextfieldDelegate,
  uCEF_LCL_EventCallback;

type

  TTextfieldDelegateRef = class(TCefTextfieldDelegateOwn)
  public
    // ICefViewDelegate
    GetPreferredSizePtr: Pointer;
    GetMinimumSizePtr: Pointer;
    GetMaximumSizePtr: Pointer;
    GetHeightForWidthPtr: Pointer;
    ParentViewChangedPtr: Pointer;
    ChildViewChangedPtr: Pointer;
    FocusPtr: Pointer;
    BlurPtr: Pointer;

    KeyEventPtr: Pointer;
    AfterUserActionPtr: Pointer;
    constructor Create; override;
    destructor Destroy; override;
  protected
    // ICefViewDelegate
    procedure OnGetPreferredSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMinimumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetMaximumSize(const view: ICefView; var aResult: TCefSize); override;
    procedure OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer); override;
    procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
    procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;

    procedure OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean); override;
    procedure OnAfterUserAction(const textfield: ICefTextfield); override;

  end;

implementation

// ICefViewDelegate
procedure TTextfieldDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TTextfieldDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TTextfieldDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TTextfieldDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;


procedure TTextfieldDelegateRef.OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (KeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(KeyEventPtr, [textfield, @event, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnAfterUserAction(const textfield: ICefTextfield);
begin
  if (AfterUserActionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(AfterUserActionPtr, [textfield]);
  end;
end;


constructor TTextfieldDelegateRef.Create;
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

  KeyEventPtr := nil;
  AfterUserActionPtr := nil;
end;

destructor TTextfieldDelegateRef.Destroy;
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

  KeyEventPtr := nil;
  AfterUserActionPtr := nil;
end;

end.
