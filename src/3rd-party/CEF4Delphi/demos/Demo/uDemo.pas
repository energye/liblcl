unit uDemo;

{$mode objfpc}{$H+}

{$I cef.inc}

{$APPTYPE CONSOLE}
interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics,
  Controls, Forms, Dialogs, StdCtrls, ExtCtrls,
  uCEFChromium, uCEFWindowParent, uCEFInterfaces, uCEFConstants, uCEFTypes, uCEFChromiumEvents;

type

  { TForm1 }

  TForm1 = class(TForm)
    AddressEdt: TEdit;
    GoBtn: TButton;
    AddressPnl: TPanel;
    Timer1: TTimer;
    Chromium1: TChromium;
    CEFWindowParent1: TCEFWindowParent;
    procedure Chromium1BeforeContextMenu(Sender: TObject;
      const browser: ICefBrowser; const frame: ICefFrame;
      const params: ICefContextMenuParams; const model: ICefMenuModel);
    procedure Chromium1KeyEvent(Sender: TObject; const browser: ICefBrowser;
      const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: Boolean);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure GoBtnClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Chromium1AfterCreated(Sender: TObject; const browser: ICefBrowser);
    procedure Chromium1BeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring;
      targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo;
      var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: boolean; var Result: boolean);
    procedure FormCreate(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: boolean);
    procedure Chromium1Close(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
    procedure Chromium1BeforeClose(Sender: TObject; const browser: ICefBrowser);
  protected
    // Variables to control when can we destroy the form safely
    FCanClose: boolean;  // Set to True in TChromium.OnBeforeClose
    FClosing: boolean;  // Set to True in the CloseQuery event.

    // You have to handle this two messages to call NotifyMoveOrResizeStarted or some page elements will be misaligned.
    procedure WMMove(var aMessage: TWMMove); message WM_MOVE;
    procedure WMMoving(var aMessage: TMessage); message WM_MOVING;
    // You also have to handle these two messages to set GlobalCEFApp.OsmodalLoop
    procedure WMEnterMenuLoop(var aMessage: TMessage); message WM_ENTERMENULOOP;
    procedure WMExitMenuLoop(var aMessage: TMessage); message WM_EXITMENULOOP;

    procedure BrowserCreatedMsg(var aMessage: TMessage); message CEF_AFTERCREATED;
    procedure BrowserDestroyMsg(var aMessage: TMessage); message CEF_DESTROY;
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}


uses
  uCEFApplication;

  // This is a demo with the simplest web browser you can build using CEF4Delphi and
  // it doesn't show any sign of progress like other web browsers do.

  // Remember that it may take a few seconds to load if Windows update, your antivirus or
  // any other windows service is using your hard drive.

  // Depending on your internet connection it may take longer than expected.

  // Please check that your firewall or antivirus are not blocking this application
  // or the domain "google.com". If you don't live in the US, you'll be redirected to
  // another domain which will take a little time too.

  // This demo uses a TChromium and a TCEFWindowParent

  // Destruction steps
  // =================
  // 1. FormCloseQuery sets CanClose to FALSE calls TChromium.CloseBrowser which triggers the TChromium.OnClose event.
  // 2. TChromium.OnClose sends a CEFBROWSER_DESTROY message to destroy CEFWindowParent1 in the main thread, which triggers the TChromium.OnBeforeClose event.
  // 3. TChromium.OnBeforeClose sets FCanClose := True and sends WM_CLOSE to the form.

procedure TForm1.FormCloseQuery(Sender: TObject; var CanClose: boolean);
begin
  WriteLn('FormCloseQuery');
  CanClose := FCanClose;

  if not (FClosing) then
  begin
    FClosing := True;
    Visible := False;
    Chromium1.CloseBrowser(True);
  end;
end;

procedure TForm1.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin

end;

procedure TForm1.Chromium1BeforeContextMenu(Sender: TObject;
  const browser: ICefBrowser; const frame: ICefFrame;
  const params: ICefContextMenuParams; const model: ICefMenuModel);
begin
  WriteLn('Chromium1BeforeContextMenu');
end;

procedure TForm1.Chromium1KeyEvent(Sender: TObject; const browser: ICefBrowser;
  const event: PCefKeyEvent; osEvent: TCefEventHandle; out Result: Boolean);
begin
  WriteLn('Chromium1KeyEvent');
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  WriteLn('FormCreate');
  FCanClose := False;
  FClosing := False;
  Timer1 := TTimer.Create(self);

  CEFWindowParent1 := TCEFWindowParent.Create(self);
  CEFWindowParent1.Parent := self;
  CEFWindowParent1.Top := 25;
  CEFWindowParent1.Width := self.Width;
  CEFWindowParent1.Height := self.Height - 25;
  //CEFWindowParent1.Align := alClient;
  CEFWindowParent1.Anchors := TAnchors([akTop, akLeft, akRight, akBottom]);
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  WriteLn('FormShow');
  Timer1.Enabled := False;
  // You *MUST* call CreateBrowser to create and initialize the browser.
  // This will trigger the AfterCreated event when the browser is fully
  // initialized and ready to receive commands.

  // GlobalCEFApp.GlobalContextInitialized has to be TRUE before creating any browser
  // If it's not initialized yet, we use a simple timer to create the browser later.
  if not (Chromium1.CreateBrowser(CEFWindowParent1)) and not (Chromium1.Initialized) then
    Timer1.Enabled := True;
end;

procedure TForm1.Chromium1AfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  WriteLn('Chromium1AfterCreated');
  // Now the browser is fully initialized we can send a message to the main form to load the initial web page.
  PostMessage(Handle, CEF_AFTERCREATED, 0, 0);
end;

procedure TForm1.Chromium1BeforeClose(Sender: TObject; const browser: ICefBrowser);
begin
  WriteLn('Chromium1BeforeClose');
  FCanClose := True;
  PostMessage(Handle, WM_CLOSE, 0, 0);
end;

procedure TForm1.Chromium1BeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring;
  targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo;
  var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: boolean; var Result: boolean);
begin
  // For simplicity, this demo blocks all popup windows and new tabs
  Result := (targetDisposition in [WOD_NEW_FOREGROUND_TAB, WOD_NEW_BACKGROUND_TAB, WOD_NEW_POPUP, WOD_NEW_WINDOW]);
end;

procedure TForm1.Chromium1Close(Sender: TObject; const browser: ICefBrowser; var aAction: TCefCloseBrowserAction);
begin
  WriteLn('Chromium1Close');
  PostMessage(Handle, CEF_DESTROY, 0, 0);
  aAction := cbaDelay;
end;

procedure TForm1.BrowserCreatedMsg(var aMessage: TMessage);
begin
  Caption := 'WindowsXP测试 32和64位';
  AddressPnl.Enabled := True;
  GoBtn.Click;
end;

procedure TForm1.BrowserDestroyMsg(var aMessage: TMessage);
begin
  WriteLn('BrowserDestroyMsg');
  CEFWindowParent1.Free;
end;

procedure TForm1.GoBtnClick(Sender: TObject);
begin
  // This will load the URL in the edit box
  Chromium1.LoadURL(AddressEdt.Text);
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  Timer1.Enabled := False;
  if not (Chromium1.CreateBrowser(CEFWindowParent1)) and not (Chromium1.Initialized) then
    Timer1.Enabled := True;
end;

procedure TForm1.WMMove(var aMessage: TWMMove);
begin
  inherited;

  if (Chromium1 <> nil) then Chromium1.NotifyMoveOrResizeStarted;
end;

procedure TForm1.WMMoving(var aMessage: TMessage);
begin
  inherited;

  if (Chromium1 <> nil) then Chromium1.NotifyMoveOrResizeStarted;
end;

procedure TForm1.WMEnterMenuLoop(var aMessage: TMessage);
begin
  inherited;

  if (aMessage.wParam = 0) and (GlobalCEFApp <> nil) then GlobalCEFApp.OsmodalLoop := True;
end;

procedure TForm1.WMExitMenuLoop(var aMessage: TMessage);
begin
  inherited;

  if (aMessage.wParam = 0) and (GlobalCEFApp <> nil) then GlobalCEFApp.OsmodalLoop := False;
end;

end.
