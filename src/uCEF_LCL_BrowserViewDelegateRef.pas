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
  uCEFBrowserViewDelegate,
  uCEF_LCL_EventCallback;

type

  TBrowserViewDelegateRef = class(TCefBrowserViewDelegateOwn)
  public
    constructor Create; override;
    destructor Destroy; override;
  protected
    procedure OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser); override;
    procedure OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate); override;
    procedure OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean); override;
    function GetChromeToolbarType: TCefChromeToolbarType; override;
    procedure InitializeCEFMethods; override;

  end;

implementation


procedure TBrowserViewDelegateRef.OnBrowserCreated(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
end;

procedure TBrowserViewDelegateRef.OnBrowserDestroyed(const browser_view: ICefBrowserView; const browser: ICefBrowser);
begin
end;

procedure TBrowserViewDelegateRef.OnGetDelegateForPopupBrowserView(const browser_view: ICefBrowserView; const settings: TCefBrowserSettings; const client: ICefClient; is_devtools: boolean; var aResult: ICefBrowserViewDelegate);
begin
end;

procedure TBrowserViewDelegateRef.OnPopupBrowserViewCreated(const browser_view, popup_browser_view: ICefBrowserView; is_devtools: boolean; var aResult: boolean);
begin
end;

function TBrowserViewDelegateRef.GetChromeToolbarType: TCefChromeToolbarType;
begin
  Result := inherited GetChromeToolbarType;

end;

procedure TBrowserViewDelegateRef.InitializeCEFMethods;
begin
  inherited InitializeCEFMethods;
end;


constructor TBrowserViewDelegateRef.Create;
begin
  inherited Create;
end;

destructor TBrowserViewDelegateRef.Destroy;
begin
  inherited Destroy;
end;

end.
