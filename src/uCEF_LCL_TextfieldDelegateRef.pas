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
    OnGetPreferredSizePtr: Pointer;
    OnGetMinimumSizePtr: Pointer;
    OnGetMaximumSizePtr: Pointer;
    OnGetHeightForWidthPtr: Pointer;
    OnParentViewChangedPtr: Pointer;
    OnChildViewChangedPtr: Pointer;
    OnWindowChangedPtr: Pointer;
    OnLayoutChangedPtr: Pointer;
    OnFocusPtr: Pointer;
    OnBlurPtr: Pointer;
    OnThemeChangedPtr: Pointer;
    OnKeyEventPtr: Pointer;
    OnAfterUserActionPtr: Pointer;
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure PtrSetNil;
    // ICefViewDelegate
    procedure OnGetPreferredSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetMinimumSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetMaximumSize(const view: ICefView; var aResult : TCefSize); override;
    procedure OnGetHeightForWidth(const view: ICefView; width: Integer; var aResult: Integer); override;
    procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
    procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
    procedure OnWindowChanged(const view: ICefView; added: boolean); override;
    procedure OnLayoutChanged(const view: ICefView; new_bounds: TCefRect); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;
    procedure OnThemeChanged(const view: ICefView); override;

    // ICefTextfieldDelegate
    procedure OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult : boolean); override;
    procedure OnAfterUserAction(const textfield: ICefTextfield); override;

  end;

implementation

constructor TTextfieldDelegateRef.Create;
begin
  inherited Create;
  PtrSetNil();
end;

destructor TTextfieldDelegateRef.Destroy;
begin
  inherited Destroy;
  PtrSetNil();
end;

procedure TTextfieldDelegateRef.PtrSetNil;
begin
  OnGetPreferredSizePtr := nil;
  OnGetMinimumSizePtr := nil;
  OnGetMaximumSizePtr := nil;
  OnGetHeightForWidthPtr := nil;
  OnParentViewChangedPtr := nil;
  OnChildViewChangedPtr := nil;
  OnWindowChangedPtr := nil;
  OnLayoutChangedPtr := nil;
  OnFocusPtr := nil;
  OnBlurPtr := nil;
  OnThemeChangedPtr := nil;
  OnKeyEventPtr := nil;
  OnAfterUserActionPtr := nil;
end;

// ICefViewDelegate
procedure TTextfieldDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (OnGetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (OnGetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnGetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (OnParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TTextfieldDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (OnChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TTextfieldDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (OnWindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnWindowChangedPtr, [view, added]);
  end;
end;

procedure TTextfieldDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (OnLayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnLayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TTextfieldDelegateRef.OnFocus(const view: ICefView);
begin
  if (OnFocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnFocusPtr, [view]);
  end;
end;

procedure TTextfieldDelegateRef.OnBlur(const view: ICefView);
begin
  if (OnBlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnBlurPtr, [view]);
  end;
end;

procedure TTextfieldDelegateRef.OnThemeChanged(const view: ICefView);
begin
  if (OnThemeChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnThemeChangedPtr, [view]);
  end;
end;

procedure TTextfieldDelegateRef.OnKeyEvent(const textfield: ICefTextfield; const event: TCefKeyEvent; var aResult: boolean);
begin
  if (OnKeyEventPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnKeyEventPtr, [textfield, @event, @aResult]);
  end;
end;

procedure TTextfieldDelegateRef.OnAfterUserAction(const textfield: ICefTextfield);
begin
  if (OnAfterUserActionPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(OnAfterUserActionPtr, [textfield]);
  end;
end;

end.
