//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_ButtonDelegateRef;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  Classes, SysUtils, uCEFInterfaces, uCEFTypes,
  uCEFButtonDelegate,
  uCEF_LCL_EventCallback;

type

  TButtonDelegateRef = class(TCefButtonDelegateOwn)
  public
    // ICefViewDelegate
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

    ButtonPressedPtr: Pointer;
    ButtonStateChangedPtr: Pointer;
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
    procedure OnWindowChanged(const view: ICefView; added: boolean); override;
    procedure OnLayoutChanged(const view: ICefView; new_bounds: TCefRect); override;
    procedure OnFocus(const view: ICefView); override;
    procedure OnBlur(const view: ICefView); override;


    procedure OnButtonPressed(const button: ICefButton); override;
    procedure OnButtonStateChanged(const button: ICefButton); override;

  end;

implementation

// ICefViewDelegate
procedure TButtonDelegateRef.OnGetPreferredSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetPreferredSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetPreferredSizePtr, [view, @aResult]);
  end;
end;

procedure TButtonDelegateRef.OnGetMinimumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMinimumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMinimumSizePtr, [view, @aResult]);
  end;
end;

procedure TButtonDelegateRef.OnGetMaximumSize(const view: ICefView; var aResult: TCefSize);
begin
  if (GetMaximumSizePtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetMaximumSizePtr, [view, @aResult]);
  end;
end;

procedure TButtonDelegateRef.OnGetHeightForWidth(const view: ICefView; Width: integer; var aResult: integer);
begin
  if (GetHeightForWidthPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(GetHeightForWidthPtr, [view, Width, @aResult]);
  end;
end;

procedure TButtonDelegateRef.OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView);
begin
  if (ParentViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ParentViewChangedPtr, [view, added, parent]);
  end;
end;

procedure TButtonDelegateRef.OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView);
begin
  if (ChildViewChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ChildViewChangedPtr, [view, added, child]);
  end;
end;

procedure TButtonDelegateRef.OnWindowChanged(const view: ICefView; added: boolean);
begin
  if (WindowChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(WindowChangedPtr, [view, added]);
  end;
end;

procedure TButtonDelegateRef.OnLayoutChanged(const view: ICefView; new_bounds: TCefRect);
begin
  if (LayoutChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(LayoutChangedPtr, [view, @new_bounds]);
  end;
end;

procedure TButtonDelegateRef.OnFocus(const view: ICefView);
begin
  if (FocusPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(FocusPtr, [view]);
  end;
end;

procedure TButtonDelegateRef.OnBlur(const view: ICefView);
begin
  if (BlurPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(BlurPtr, [view]);
  end;
end;


procedure TButtonDelegateRef.OnButtonPressed(const button: ICefButton);
begin
  if (ButtonPressedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ButtonPressedPtr, [button]);
  end;
end;

procedure TButtonDelegateRef.OnButtonStateChanged(const button: ICefButton);
begin
  if (ButtonStateChangedPtr <> nil) then
  begin
    TCEFEventCallback.SendEvent(ButtonStateChangedPtr, [button]);
  end;
end;

constructor TButtonDelegateRef.Create;
begin
  inherited Create;
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  WindowChangedPtr := nil;
  LayoutChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;

  ButtonPressedPtr := nil;
  ButtonStateChangedPtr := nil;
end;

destructor TButtonDelegateRef.Destroy;
begin
  inherited Destroy;
  GetPreferredSizePtr := nil;
  GetMinimumSizePtr := nil;
  GetMaximumSizePtr := nil;
  GetHeightForWidthPtr := nil;
  ParentViewChangedPtr := nil;
  ChildViewChangedPtr := nil;
  WindowChangedPtr := nil;
  LayoutChangedPtr := nil;
  FocusPtr := nil;
  BlurPtr := nil;

  ButtonPressedPtr := nil;
  ButtonStateChangedPtr := nil;
end;

end.
