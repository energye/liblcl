unit uCEFResourceBundle;

{$IFDEF FPC}
  {$MODE OBJFPC}{$H+}
{$ENDIF}

{$I cef.inc}

{$IFNDEF TARGET_64BITS}{$ALIGN ON}{$ENDIF}
{$MINENUMSIZE 4}

interface

uses
  uCEFBaseRefCounted, uCEFInterfaces, uCEFTypes;

type
  TCefResourceBundleRef = class(TCefBaseRefCountedRef, ICefResourceBundle)
    protected
      function GetLocalizedString(stringId: Integer): ustring;
      function GetDataResource(resourceId: Integer): ICefBinaryValue;
      function GetDataResourceForScale(resourceId: Integer; scaleFactor: TCefScaleFactor): ICefBinaryValue;
    public
      class function UnWrap(data: Pointer): ICefResourceBundle;
      class function Global: ICefResourceBundle;
  end;

implementation

uses
  uCEFMiscFunctions, uCEFLibFunctions, uCEFBinaryValue;


function TCefResourceBundleRef.GetDataResource(resourceId: Integer): ICefBinaryValue;
begin
  Result := TCefBinaryValueRef.UnWrap(PCefResourceBundle(FData)^.get_data_resource(PCefResourceBundle(FData),
                                                                                   resourceId));
end;

function TCefResourceBundleRef.GetDataResourceForScale(resourceId  : Integer;
                                                       scaleFactor : TCefScaleFactor): ICefBinaryValue;
begin
  Result := TCefBinaryValueRef.UnWrap(PCefResourceBundle(FData)^.get_data_resource_for_scale(PCefResourceBundle(FData),
                                                                                             resourceId,
                                                                                             scaleFactor));
end;

function TCefResourceBundleRef.GetLocalizedString(stringId: Integer): ustring;
begin
  Result := CefStringFreeAndGet(PCefResourceBundle(FData)^.get_localized_string(PCefResourceBundle(FData), stringId));
end;

class function TCefResourceBundleRef.Global: ICefResourceBundle;
begin
  Result := UnWrap(cef_resource_bundle_get_global());
end;

class function TCefResourceBundleRef.UnWrap(data: Pointer): ICefResourceBundle;
begin
  if (data <> nil) then
    Result := Create(data) as ICefResourceBundle
   else
    Result := nil;
end;

end.
