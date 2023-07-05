// ************************************************************************
// ***************************** CEF4Delphi *******************************
// ************************************************************************
//
// CEF4Delphi is based on DCEF3 which uses CEF to embed a chromium-based
// browser in Delphi applications.
//
// The original license of DCEF3 still applies to CEF4Delphi.
//
// For more information about CEF4Delphi visit :
//         https://www.briskbard.com/index.php?lang=en&pageid=cef
//
//        Copyright � 2023 Salvador Diaz Fau. All rights reserved.
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

unit uCEFPreferenceManager;

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

{$IFNDEF TARGET_64BITS}{$ALIGN ON}{$ENDIF}
{$MINENUMSIZE 4}

interface

uses
  {$IFDEF DELPHI16_UP}
  System.Classes, System.SysUtils,
  {$ELSE}
  Classes, SysUtils,
  {$ENDIF}
  uCEFBaseRefCounted, uCEFInterfaces, uCEFTypes;

type
  TCefPreferenceManagerRef = class(TCefBaseRefCountedRef, ICefPreferenceManager)
    protected
      function  HasPreference(const name: ustring): Boolean;
      function  GetPreference(const name: ustring): ICefValue;
      function  GetAllPreferences(includeDefaults: Boolean): ICefDictionaryValue;
      function  CanSetPreference(const name: ustring): Boolean;
      function  SetPreference(const name: ustring; const value: ICefValue; out error: ustring): Boolean;
    public
      class function UnWrap(data: Pointer): ICefPreferenceManager;
      class function Global: ICefPreferenceManager;
  end;

implementation

uses
  uCEFLibFunctions, uCEFMiscFunctions, uCEFValue, uCEFDictionaryValue;

class function TCefPreferenceManagerRef.UnWrap(data: Pointer): ICefPreferenceManager;
begin
  if (data <> nil) then
    Result := Create(data) as ICefPreferenceManager
   else
    Result := nil;
end;

class function TCefPreferenceManagerRef.Global: ICefPreferenceManager;
begin
  Result := UnWrap(cef_preference_manager_get_global());
end;

function TCefPreferenceManagerRef.HasPreference(const name: ustring): Boolean;
var
  TempName : TCefString;
begin
  TempName := CefString(name);
  Result   := PCefPreferenceManager(FData)^.has_preference(PCefPreferenceManager(FData), @TempName) <> 0;
end;

function TCefPreferenceManagerRef.GetPreference(const name: ustring): ICefValue;
var
  TempName : TCefString;
begin
  TempName := CefString(name);
  Result   := TCefValueRef.UnWrap(PCefPreferenceManager(FData)^.get_preference(PCefPreferenceManager(FData), @TempName));
end;

function TCefPreferenceManagerRef.GetAllPreferences(includeDefaults: Boolean): ICefDictionaryValue;
begin
  Result := TCefDictionaryValueRef.UnWrap(PCefPreferenceManager(FData)^.get_all_preferences(PCefPreferenceManager(FData), Ord(includeDefaults)));
end;

function TCefPreferenceManagerRef.CanSetPreference(const name: ustring): Boolean;
var
  TempName : TCefString;
begin
  TempName := CefString(name);
  Result   := PCefPreferenceManager(FData)^.can_set_preference(PCefPreferenceManager(FData), @TempName) <> 0;
end;

function TCefPreferenceManagerRef.SetPreference(const name  : ustring;
                                                const value : ICefValue;
                                                out   error : ustring): Boolean;
var
  TempName, TempError : TCefString;
begin
  CefStringInitialize(@TempError);

  TempName := CefString(name);
  Result   := PCefPreferenceManager(FData)^.set_preference(PCefPreferenceManager(FData), @TempName, CefGetData(value), @TempError) <> 0;
  error    := CefStringClearAndGet(@TempError);
end;

end.
