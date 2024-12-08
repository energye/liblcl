// ************************************************************************
// ***************************** CEF4Delphi *******************************
// ************************************************************************

// CEF4Delphi is based on DCEF3 which uses CEF3 to embed a chromium-based
// browser in Delphi applications.

// The original license of DCEF3 still applies to CEF4Delphi.

// For more information about CEF4Delphi visit :
//         https://www.briskbard.com/index.php?lang=en&pageid=cef

//        Copyright 2018 Salvador D韆z Fau. All rights reserved.

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

program SimpleBrowser2;


{$I cef.inc}

uses
  {$IFDEF DELPHI16_UP}
  Vcl.Forms,
  WinApi.Windows,
  {$ELSE}
  Forms,
  Interfaces,
  Windows,
  {$ENDIF }
  uCEFApplication,
  uSimpleBrowser2 in 'uSimpleBrowser2.pas' {Form1};

begin
  GlobalCEFApp := TCefApplication.Create;
  GlobalCEFApp.FrameworkDirPath := 'D:\app.exe\energy\EnergyFramework32_49\';

  // In case you want to use custom directories for the CEF3 binaries, cache, cookies and user data.
  // If you don't set a cache directory the browser will use in-memory cache.
{
  GlobalCEFApp.FrameworkDirPath     := 'cef';
  GlobalCEFApp.ResourcesDirPath     := 'cef';
  GlobalCEFApp.LocalesDirPath       := 'cef\locales';
  GlobalCEFApp.EnableGPU            := True;      // Enable hardware acceleration
  GlobalCEFApp.DisableGPUCache      := True;      // Disable the creation of a 'GPUCache' directory in the hard drive.
  GlobalCEFApp.cache                := 'cef\cache';
  GlobalCEFApp.cookies              := 'cef\cookies';
  GlobalCEFApp.UserDataPath         := 'cef\User Data';
}

  // You *MUST* call GlobalCEFApp.StartMainProcess in a if..then clause
  // with the Application initialization inside the begin..end.
  // Read this https://www.briskbard.com/index.php?lang=en&pageid=cef
  if GlobalCEFApp.StartMainProcess then
  begin
    Application.Initialize;
    {$IFDEF DELPHI11_UP}
      Application.MainFormOnTaskbar := True;
    {$ENDIF}
    Application.CreateForm(TForm1, Form1);
    Application.Run;
  end;

  GlobalCEFApp.Free;
end.