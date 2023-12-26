// ************************************************************************
// ***************************** CEF4Delphi *******************************
// ************************************************************************
//
// CEF4Delphi is based on DCEF3 which uses CEF3 to embed a chromium-based
// browser in Delphi applications.
//
// The original license of DCEF3 still applies to CEF4Delphi.
//
// For more information about CEF4Delphi visit :
//         https://www.briskbard.com/index.php?lang=en&pageid=cef
//
//        Copyright � 2019 Salvador D�az Fau. All rights reserved.
//
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

unit uCEFJsDialogCallback;

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

{$IFNDEF CPUX64}{$ALIGN ON}{$ENDIF}
{$MINENUMSIZE 4}

interface

uses
  uCEFBase, uCEFInterfaces, uCEFTypes;

type
  TCefJsDialogCallbackRef = class(TCefBaseRef, ICefJsDialogCallback)
    protected
      procedure Cont(success: Boolean; const userInput: ustring);
    public
      class function UnWrap(data: Pointer): ICefJsDialogCallback;
  end;


implementation

uses
  uCEFMiscFunctions, uCEFLibFunctions;

procedure TCefJsDialogCallbackRef.Cont(success: Boolean; const userInput: ustring);
var
  ui: TCefString;
begin
  ui := CefString(userInput);
  PCefJsDialogCallback(FData)^.cont(PCefJsDialogCallback(FData), Ord(success), @ui);
end;

class function TCefJsDialogCallbackRef.UnWrap(data: Pointer): ICefJsDialogCallback;
begin
  if (data <> nil) then
    Result := Create(data) as ICefJsDialogCallback
   else
    Result := nil;
end;

end.
