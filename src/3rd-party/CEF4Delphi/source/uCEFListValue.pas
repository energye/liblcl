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

unit uCEFListValue;

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
  TCefListValueRef = class(TCefBaseRef, ICefListValue)
    protected
      function IsValid: Boolean;
      function IsOwned: Boolean;
      function IsReadOnly: Boolean;
      function IsSame(const that: ICefListValue): Boolean;
      function IsEqual(const that: ICefListValue): Boolean;
      function Copy: ICefListValue;
      function SetSize(size: NativeUInt): Boolean;
      function GetSize: NativeUInt;
      function Clear: Boolean;
      function Remove(index: Integer): Boolean;
      function GetType(index: Integer): TCefValueType;
      function GetValue(index: Integer): ICefValue;
      function GetBool(index: Integer): Boolean;
      function GetInt(index: Integer): Integer;
      function GetDouble(index: Integer): Double;
      function GetString(index: Integer): ustring;
      function GetBinary(index: Integer): ICefBinaryValue;
      function GetDictionary(index: Integer): ICefDictionaryValue;
      function GetList(index: Integer): ICefListValue;
      function SetValue(index: Integer; const value: ICefValue): Boolean;
      function SetNull(index: Integer): Boolean;
      function SetBool(index: Integer; value: Boolean): Boolean;
      function SetInt(index: Integer; value: Integer): Boolean;
      function SetDouble(index: Integer; value: Double): Boolean;
      function SetString(index: Integer; const value: ustring): Boolean;
      function SetBinary(index: Integer; const value: ICefBinaryValue): Boolean;
      function SetDictionary(index: Integer; const value: ICefDictionaryValue): Boolean;
      function SetList(index: Integer; const value: ICefListValue): Boolean;

    public
      class function UnWrap(data: Pointer): ICefListValue;
      class function New: ICefListValue;
  end;

implementation

uses
  uCEFMiscFunctions, uCEFLibFunctions, uCEFBinaryValue, uCEFValue, uCEFDictionaryValue;

function TCefListValueRef.Clear: Boolean;
begin
  Result := PCefListValue(FData)^.clear(PCefListValue(FData)) <> 0;
end;

function TCefListValueRef.Copy: ICefListValue;
begin
  Result := UnWrap(PCefListValue(FData)^.copy(PCefListValue(FData)));
end;

class function TCefListValueRef.New: ICefListValue;
begin
  Result := UnWrap(cef_list_value_create);
end;

function TCefListValueRef.GetBinary(index: Integer): ICefBinaryValue;
begin
  Result := TCefBinaryValueRef.UnWrap(PCefListValue(FData)^.get_binary(PCefListValue(FData), index));
end;

function TCefListValueRef.GetBool(index: Integer): Boolean;
begin
  Result := PCefListValue(FData)^.get_bool(PCefListValue(FData), index) <> 0;
end;

function TCefListValueRef.GetDictionary(index: Integer): ICefDictionaryValue;
begin
  Result := TCefDictionaryValueRef.UnWrap(PCefListValue(FData)^.get_dictionary(PCefListValue(FData), index));
end;

function TCefListValueRef.GetDouble(index: Integer): Double;
begin
  Result := PCefListValue(FData)^.get_double(PCefListValue(FData), index);
end;

function TCefListValueRef.GetInt(index: Integer): Integer;
begin
  Result := PCefListValue(FData)^.get_int(PCefListValue(FData), index);
end;

function TCefListValueRef.GetList(index: Integer): ICefListValue;
begin
  Result := UnWrap(PCefListValue(FData)^.get_list(PCefListValue(FData), index));
end;

function TCefListValueRef.GetSize: NativeUInt;
begin
  Result := PCefListValue(FData)^.get_size(PCefListValue(FData));
end;

function TCefListValueRef.GetString(index: Integer): ustring;
begin
  Result := CefStringFreeAndGet(PCefListValue(FData)^.get_string(PCefListValue(FData), index));
end;

function TCefListValueRef.GetType(index: Integer): TCefValueType;
begin
  Result := PCefListValue(FData)^.get_type(PCefListValue(FData), index);
end;

function TCefListValueRef.GetValue(index: Integer): ICefValue;
begin
  Result := TCefValueRef.UnWrap(PCefListValue(FData)^.get_value(PCefListValue(FData), index));
end;

function TCefListValueRef.IsEqual(const that: ICefListValue): Boolean;
begin
  Result := PCefListValue(FData)^.is_equal(PCefListValue(FData), CefGetData(that)) <> 0;
end;

function TCefListValueRef.IsOwned: Boolean;
begin
  Result := PCefListValue(FData)^.is_owned(PCefListValue(FData)) <> 0;
end;

function TCefListValueRef.IsReadOnly: Boolean;
begin
  Result := PCefListValue(FData)^.is_read_only(PCefListValue(FData)) <> 0;
end;

function TCefListValueRef.IsSame(const that: ICefListValue): Boolean;
begin
  Result := PCefListValue(FData)^.is_same(PCefListValue(FData), CefGetData(that)) <> 0;
end;

function TCefListValueRef.IsValid: Boolean;
begin
  Result := PCefListValue(FData)^.is_valid(PCefListValue(FData)) <> 0;
end;

function TCefListValueRef.Remove(index: Integer): Boolean;
begin
  Result := PCefListValue(FData)^.remove(PCefListValue(FData), index) <> 0;
end;

function TCefListValueRef.SetBinary(index: Integer; const value: ICefBinaryValue): Boolean;
begin
  Result := PCefListValue(FData)^.set_binary(PCefListValue(FData), index, CefGetData(value)) <> 0;
end;

function TCefListValueRef.SetBool(index: Integer; value: Boolean): Boolean;
begin
  Result := PCefListValue(FData)^.set_bool(PCefListValue(FData), index, Ord(value)) <> 0;
end;

function TCefListValueRef.SetDictionary(index: Integer; const value: ICefDictionaryValue): Boolean;
begin
  Result := PCefListValue(FData)^.set_dictionary(PCefListValue(FData), index, CefGetData(value)) <> 0;
end;

function TCefListValueRef.SetDouble(index: Integer; value: Double): Boolean;
begin
  Result := PCefListValue(FData)^.set_double(PCefListValue(FData), index, value) <> 0;
end;

function TCefListValueRef.SetInt(index: Integer; value: Integer): Boolean;
begin
  Result := PCefListValue(FData)^.set_int(PCefListValue(FData), index, value) <> 0;
end;

function TCefListValueRef.SetList(index: Integer; const value: ICefListValue): Boolean;
begin
  Result := PCefListValue(FData)^.set_list(PCefListValue(FData), index, CefGetData(value)) <> 0;
end;

function TCefListValueRef.SetNull(index: Integer): Boolean;
begin
  Result := PCefListValue(FData)^.set_null(PCefListValue(FData), index) <> 0;
end;

function TCefListValueRef.SetSize(size: NativeUInt): Boolean;
begin
  Result := PCefListValue(FData)^.set_size(PCefListValue(FData), size) <> 0;
end;

function TCefListValueRef.SetString(index: Integer; const value: ustring): Boolean;
var
  v: TCefString;
begin
  v := CefString(value);
  Result := PCefListValue(FData)^.set_string(PCefListValue(FData), index, @v) <> 0;
end;

function TCefListValueRef.SetValue(index: Integer; const value: ICefValue): Boolean;
begin
  Result := PCefListValue(FData)^.set_value(PCefListValue(FData), index, CefGetData(value)) <> 0;
end;

class function TCefListValueRef.UnWrap(data: Pointer): ICefListValue;
begin
  if data <> nil then
    Result := Create(data) as ICefListValue else
    Result := nil;
end;

end.
