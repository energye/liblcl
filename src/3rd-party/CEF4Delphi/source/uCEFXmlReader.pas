// ************************************************************************
// ***************************** OldCEF4Delphi *******************************
// ************************************************************************
//
// OldCEF4Delphi is based on DCEF3 which uses CEF3 to embed a chromium-based
// browser in Delphi applications.
//
// The original license of DCEF3 still applies to OldCEF4Delphi.
//
// For more information about OldCEF4Delphi visit :
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

unit uCEFXmlReader;

{$IFNDEF CPUX64}{$ALIGN ON}{$ENDIF}
{$MINENUMSIZE 4}

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

interface

uses
  uCEFBase, uCEFInterfaces, uCEFTypes;

type
  TCefXmlReaderRef = class(TCefBaseRef, ICefXmlReader)
  protected
    function MoveToNextNode: Boolean;
    function Close: Boolean;
    function HasError: Boolean;
    function GetError: ustring;
    function GetType: TCefXmlNodeType;
    function GetDepth: Integer;
    function GetLocalName: ustring;
    function GetPrefix: ustring;
    function GetQualifiedName: ustring;
    function GetNamespaceUri: ustring;
    function GetBaseUri: ustring;
    function GetXmlLang: ustring;
    function IsEmptyElement: Boolean;
    function HasValue: Boolean;
    function GetValue: ustring;
    function HasAttributes: Boolean;
    function GetAttributeCount: NativeUInt;
    function GetAttributeByIndex(index: Integer): ustring;
    function GetAttributeByQName(const qualifiedName: ustring): ustring;
    function GetAttributeByLName(const localName, namespaceURI: ustring): ustring;
    function GetInnerXml: ustring;
    function GetOuterXml: ustring;
    function GetLineNumber: Integer;
    function MoveToAttributeByIndex(index: Integer): Boolean;
    function MoveToAttributeByQName(const qualifiedName: ustring): Boolean;
    function MoveToAttributeByLName(const localName, namespaceURI: ustring): Boolean;
    function MoveToFirstAttribute: Boolean;
    function MoveToNextAttribute: Boolean;
    function MoveToCarryingElement: Boolean;
  public
    class function UnWrap(data: Pointer): ICefXmlReader;
    class function New(const stream: ICefStreamReader;
      encodingType: TCefXmlEncodingType; const URI: ustring): ICefXmlReader;
  end;

implementation

uses
  uCEFMiscFunctions, uCEFLibFunctions;

function TCefXmlReaderRef.Close: Boolean;
begin
  Result := PCefXmlReader(FData).close(FData) <> 0;
end;

class function TCefXmlReaderRef.New(const stream: ICefStreamReader;
  encodingType: TCefXmlEncodingType; const URI: ustring): ICefXmlReader;
var
  u: TCefString;
begin
  u := CefString(URI);
  Result := UnWrap(cef_xml_reader_create(CefGetData(stream), encodingType, @u));
end;

function TCefXmlReaderRef.GetAttributeByIndex(index: Integer): ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_attribute_byindex(FData, index));
end;

function TCefXmlReaderRef.GetAttributeByLName(const localName,
  namespaceURI: ustring): ustring;
var
  l, n: TCefString;
begin
  l := CefString(localName);
  n := CefString(namespaceURI);
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_attribute_bylname(FData, @l, @n));
end;

function TCefXmlReaderRef.GetAttributeByQName(
  const qualifiedName: ustring): ustring;
var
  q: TCefString;
begin
  q := CefString(qualifiedName);
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_attribute_byqname(FData, @q));
end;

function TCefXmlReaderRef.GetAttributeCount: NativeUInt;
begin
  Result := PCefXmlReader(FData).get_attribute_count(FData);
end;

function TCefXmlReaderRef.GetBaseUri: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_base_uri(FData));
end;

function TCefXmlReaderRef.GetDepth: Integer;
begin
  Result := PCefXmlReader(FData).get_depth(FData);
end;

function TCefXmlReaderRef.GetError: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_error(FData));
end;

function TCefXmlReaderRef.GetInnerXml: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_inner_xml(FData));
end;

function TCefXmlReaderRef.GetLineNumber: Integer;
begin
  Result := PCefXmlReader(FData).get_line_number(FData);
end;

function TCefXmlReaderRef.GetLocalName: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_local_name(FData));
end;

function TCefXmlReaderRef.GetNamespaceUri: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_namespace_uri(FData));
end;

function TCefXmlReaderRef.GetOuterXml: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_outer_xml(FData));
end;

function TCefXmlReaderRef.GetPrefix: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_prefix(FData));
end;

function TCefXmlReaderRef.GetQualifiedName: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_qualified_name(FData));
end;

function TCefXmlReaderRef.GetType: TCefXmlNodeType;
begin
  Result := PCefXmlReader(FData).get_type(FData);
end;

function TCefXmlReaderRef.GetValue: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_value(FData));
end;

function TCefXmlReaderRef.GetXmlLang: ustring;
begin
  Result := CefStringFreeAndGet(PCefXmlReader(FData).get_xml_lang(FData));
end;

function TCefXmlReaderRef.HasAttributes: Boolean;
begin
  Result := PCefXmlReader(FData).has_attributes(FData) <> 0;
end;

function TCefXmlReaderRef.HasError: Boolean;
begin
  Result := PCefXmlReader(FData).has_error(FData) <> 0;
end;

function TCefXmlReaderRef.HasValue: Boolean;
begin
  Result := PCefXmlReader(FData).has_value(FData) <> 0;
end;

function TCefXmlReaderRef.IsEmptyElement: Boolean;
begin
  Result := PCefXmlReader(FData).is_empty_element(FData) <> 0;
end;

function TCefXmlReaderRef.MoveToAttributeByIndex(index: Integer): Boolean;
begin
  Result := PCefXmlReader(FData).move_to_attribute_byindex(FData, index) <> 0;
end;

function TCefXmlReaderRef.MoveToAttributeByLName(const localName,
  namespaceURI: ustring): Boolean;
var
  l, n: TCefString;
begin
  l := CefString(localName);
  n := CefString(namespaceURI);
  Result := PCefXmlReader(FData).move_to_attribute_bylname(FData, @l, @n) <> 0;
end;

function TCefXmlReaderRef.MoveToAttributeByQName(
  const qualifiedName: ustring): Boolean;
var
  q: TCefString;
begin
  q := CefString(qualifiedName);
  Result := PCefXmlReader(FData).move_to_attribute_byqname(FData, @q) <> 0;
end;

function TCefXmlReaderRef.MoveToCarryingElement: Boolean;
begin
  Result := PCefXmlReader(FData).move_to_carrying_element(FData) <> 0;
end;

function TCefXmlReaderRef.MoveToFirstAttribute: Boolean;
begin
  Result := PCefXmlReader(FData).move_to_first_attribute(FData) <> 0;
end;

function TCefXmlReaderRef.MoveToNextAttribute: Boolean;
begin
  Result := PCefXmlReader(FData).move_to_next_attribute(FData) <> 0;
end;

function TCefXmlReaderRef.MoveToNextNode: Boolean;
begin
  Result := PCefXmlReader(FData).move_to_next_node(FData) <> 0;
end;

class function TCefXmlReaderRef.UnWrap(data: Pointer): ICefXmlReader;
begin
  if data <> nil then
    Result := Create(data) as ICefXmlReader else
    Result := nil;
end;

end.
