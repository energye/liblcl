// ************************************************************************
// ***************************** CEF4Delphi *******************************
// ************************************************************************

// CEF4Delphi is based on DCEF3 which uses CEF3 to embed a chromium-based
// browser in Delphi applications.

// The original license of DCEF3 still applies to CEF4Delphi.

// For more information about CEF4Delphi visit :
//         https://www.briskbard.com/index.php?lang=en&pageid=cef

//        Copyright 2019 Salvador D韆z Fau. All rights reserved.

// ************************************************************************
// ************ vvvv Original license and comments below vvvv *************
// ************************************************************************
(*
 *                       Delphi Chromium Embedded 3
 *
 * Usage allowed under the restrictions of the Lesser GNU General Public License
 * or alternatively the restrictions of the Mozilla Public License 1.1
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for
 * the specific language governing rights and limitations under the License.
 *
 * Unit owner : Henri Gourvest <hgourvest@gmail.com>
 * Web site   : http://www.progdigy.com
 * Repository : http://code.google.com/p/delphichromiumembedded/
 * Group      : http://groups.google.com/group/delphichromiumembedded
 *
 * Embarcadero Technologies, Inc is not permitted to use or redistribute
 * this source code without explicit permission.
 *
 *)

unit uMainForm;

{$I cef.inc}

interface

uses
  {$IFDEF DELPHI16_UP}
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, System.SyncObjs,
  {$ELSE}
  Windows, Messages, SysUtils, Variants, Classes, Graphics,
  Controls, Forms, Dialogs, StdCtrls, ExtCtrls, SyncObjs,
  {$ENDIF}
  uCEFChromium, uCEFWindowParent, uCEFInterfaces, uCEFConstants, uCEFTypes, uChildForm;

const
  CEF_CREATENEXTCHILD = WM_APP + $A50;
  CEF_CHILDDESTROYED = WM_APP + $A51;

type
  TMainForm = class(TForm)
    AddressPnl: TPanel;
    AddressEdt: TEdit;
    GoBtn: TButton;
    Timer1: TTimer;
    Chromium1: TChromium;
    CEFWindowParent1: TCEFWindowParent;

    procedure GoBtnClick(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);

    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: boolean);

    procedure Chromium1AfterCreated(Sender: TObject; const browser: ICefBrowser);
    procedure Chromium1BeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl, targetFrameName: ustring;
      targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures; var windowInfo: TCefWindowInfo;
      var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: boolean; var Result: boolean);

  protected
    FChildForm: TChildForm;
    FCriticalSection: TCriticalSection;
    FClosing: boolean;

    function GetPopupChildCount: integer;

    procedure ClosePopupChildren;

    procedure WMMove(var aMessage: TWMMove); message WM_MOVE;
    procedure WMMoving(var aMessage: TMessage); message WM_MOVING;
    procedure WMEnterMenuLoop(var aMessage: TMessage); message WM_ENTERMENULOOP;
    procedure WMExitMenuLoop(var aMessage: TMessage); message WM_EXITMENULOOP;

    procedure BrowserCreatedMsg(var aMessage: TMessage); message CEF_AFTERCREATED;
    procedure CreateNextChildMsg(var aMessage: TMessage); message CEF_CREATENEXTCHILD;
    procedure ChildDestroyedMsg(var aMessage: TMessage); message CEF_CHILDDESTROYED;
  public
    function CreateClientHandler(var windowInfo: TCefWindowInfo; var client: ICefClient; const targetFrameName: string; const popupFeatures: TCefPopupFeatures): boolean;

    property PopupChildCount: integer read GetPopupChildCount;
  end;

var
  MainForm: TMainForm;

implementation

{$R *.lfm}

uses
  uCEFApplication, uCEFMiscFunctions;

  // This is demo shows how to create popup windows in CEF.

  // You need to understand The SimpleBrowser2 and SimpleOSRBrowser demos completely before trying to understand this demo.

  // When TChromium needs to show a new popup window it executes TChromium.OnBeforePopup.

  // VCL components *MUST* be created and destroyed in the main thread but CEF executes the
  // TChromium.OnBeforePopup in a different thread.

  // For this reason this demo creates a hidden popup form (TChildForm) in case CEF needs to show a popup window.
  // TChromium.OnBeforePopup calls TChildForm.CreateClientHandler to initialize some parameters and create the new ICefClient.
  // After that, it sends a CEF_CREATENEXTCHILD message to show the popup form and create a new one.

  // All the child forms must be correctly destroyed before closing the main form. Read the code comments in uChildForm.pas
  // to know how the popup windows are destroyed.

  // The main form sends a WM_CLOSE to all active popup forms and waits until all of them have sent a CEF_CHILDDESTROYED message.


  // 这个演示将展示如何在CEF中创建弹出窗口。

  // 在尝试理解这个示例之前，你需要完全理解SimpleBrowser2和SimpleOSRBrowser这两个示例。

  // 当TChromium需要显示一个新的弹出窗口时，它会执行TChromium.OnBeforePopup。

  // VCL组件必须在主线程中创建和销毁，但CEF在另一个线程中执行TChromium.OnBeforePopup。

  // 因此，这个示例创建了一个隐藏的弹出表单（TChildForm），以防CEF需要显示弹出窗口。
  // TChromium.OnBeforePopup调用TChildForm.CreateClientHandler来初始化一些参数并创建新的ICefClient。
  // 然后，它发送一个CEF_CREATENEXTCHILD消息来显示弹出表单并创建一个新的弹出窗口。

  // 在关闭主表单之前，必须正确销毁所有子表单。阅读uChildForm.pas中的代码注释，了解如何销毁弹出窗口。
  // 主表单向所有活动的弹出窗口发送WM_CLOSE消息，并等待它们都发送CEF_CHILDDESTROYED消息。

procedure TMainForm.FormCloseQuery(Sender: TObject; var CanClose: boolean);
begin
  FClosing := True;
  Visible := False;

  if (PopupChildCount > 0) then
  begin
    ClosePopupChildren;
    CanClose := False;
  end
  else
    CanClose := True;
end;

procedure TMainForm.FormCreate(Sender: TObject);
begin
  FClosing := False;
  FCriticalSection := TCriticalSection.Create;

  Chromium1.Options.BackgroundColor := CefColorSetARGB($FF, $FF, $FF, $FF);
end;

procedure TMainForm.FormDestroy(Sender: TObject);
begin
  FreeAndNil(FCriticalSection);
end;

procedure TMainForm.FormShow(Sender: TObject);
begin
  // You *MUST* call CreateBrowser to create and initialize the browser.
  // This will trigger the AfterCreated event when the browser is fully
  // initialized and ready to receive commands.

  // GlobalCEFApp.GlobalContextInitialized has to be TRUE before creating any browser
  // If it's not initialized yet, we use a simple timer to create the browser later.
  if not (Chromium1.CreateBrowser(CEFWindowParent1)) then Timer1.Enabled := True;
end;

procedure TMainForm.Chromium1AfterCreated(Sender: TObject; const browser: ICefBrowser);
begin
  // Now the browser is fully initialized we can send a message to the main form to load the initial web page.
  // 现在浏览器已完全初始化，我们可以向主表单发送一条消息来加载初始网页。
  PostMessage(Handle, CEF_AFTERCREATED, 0, 0);
end;

procedure TMainForm.Chromium1BeforePopup(Sender: TObject; const browser: ICefBrowser; const frame: ICefFrame; const targetUrl: ustring;
  const targetFrameName: ustring; targetDisposition: TCefWindowOpenDisposition; userGesture: boolean; const popupFeatures: TCefPopupFeatures;
  var windowInfo: TCefWindowInfo; var client: ICefClient; var settings: TCefBrowserSettings; var noJavascriptAccess: boolean; var Result: boolean);
begin
  case targetDisposition of
    WOD_NEW_FOREGROUND_TAB,
    WOD_NEW_BACKGROUND_TAB,
    WOD_NEW_WINDOW: Result := True;  // For simplicity, this demo blocks new tabs and new windows.

    WOD_NEW_POPUP: Result := not (CreateClientHandler(windowInfo, client, targetFrameName, popupFeatures));

    else
      Result := False;
  end;
end;

function TMainForm.CreateClientHandler(var windowInfo: TCefWindowInfo; var client: ICefClient; const targetFrameName: string; const popupFeatures: TCefPopupFeatures): boolean;
begin
  try
    FCriticalSection.Acquire;

    Result := (FChildForm <> nil) and FChildForm.CreateClientHandler(windowInfo, client, targetFrameName, popupFeatures) and PostMessage(Handle, CEF_CREATENEXTCHILD, 0, 0);
  finally
    FCriticalSection.Release;
  end;
end;

function TMainForm.GetPopupChildCount: integer;
var
  i: integer;
  TempForm: TCustomForm;
begin
  Result := 0;
  i := pred(screen.CustomFormCount);

  while (i >= 0) do
  begin
    TempForm := screen.CustomForms[i];

    // Only count the fully initialized child forms and not the one waiting to be used.

    if (TempForm is TChildForm) and TChildForm(TempForm).ClientInitialized then
      Inc(Result);

    Dec(i);
  end;
end;

procedure TMainForm.ClosePopupChildren;
var
  i: integer;
  TempForm: TCustomForm;
begin
  i := pred(screen.CustomFormCount);

  while (i >= 0) do
  begin
    TempForm := screen.CustomForms[i];

    // Only send WM_CLOSE to fully initialized child forms.

    if (TempForm is TChildForm) and TChildForm(TempForm).ClientInitialized and not (TChildForm(TempForm).Closing) then
      PostMessage(TChildForm(TempForm).Handle, WM_CLOSE, 0, 0);

    Dec(i);
  end;
end;

procedure TMainForm.BrowserCreatedMsg(var aMessage: TMessage);
begin
  FChildForm := TChildForm.Create(self);
  Caption := 'Popup Browser';
  AddressPnl.Enabled := True;
  GoBtn.Click;
end;

procedure TMainForm.CreateNextChildMsg(var aMessage: TMessage);
begin
  try
    FCriticalSection.Acquire;

    if (FChildForm <> nil) then
    begin
      FChildForm.ApplyPopupFeatures;
      FChildForm.Show;
    end;

    FChildForm := TChildForm.Create(self);
  finally
    FCriticalSection.Release;
  end;
end;

procedure TMainForm.ChildDestroyedMsg(var aMessage: TMessage);
begin
  if FClosing and (PopupChildCount = 0) then Close;
end;

procedure TMainForm.GoBtnClick(Sender: TObject);
begin
  // This will load the URL in the edit box
  Chromium1.LoadURL(AddressEdt.Text);
end;

procedure TMainForm.Timer1Timer(Sender: TObject);
begin
  Timer1.Enabled := False;
  if not (Chromium1.CreateBrowser(CEFWindowParent1)) and not (Chromium1.Initialized) then
    Timer1.Enabled := True;
end;

procedure TMainForm.WMMove(var aMessage: TWMMove);
begin
  inherited;

  if (Chromium1 <> nil) then Chromium1.NotifyMoveOrResizeStarted;
end;

procedure TMainForm.WMMoving(var aMessage: TMessage);
begin
  inherited;

  if (Chromium1 <> nil) then Chromium1.NotifyMoveOrResizeStarted;
end;

procedure TMainForm.WMEnterMenuLoop(var aMessage: TMessage);
begin
  inherited;

  if (aMessage.wParam = 0) and (GlobalCEFApp <> nil) then GlobalCEFApp.OsmodalLoop := True;
end;

procedure TMainForm.WMExitMenuLoop(var aMessage: TMessage);
begin
  inherited;

  if (aMessage.wParam = 0) and (GlobalCEFApp <> nil) then GlobalCEFApp.OsmodalLoop := False;
end;

end.
