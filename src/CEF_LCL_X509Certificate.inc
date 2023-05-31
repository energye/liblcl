//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

{== TCefX509CertificateArray ==}
procedure CefX509CertificateArray_Get(const X509CertificateArray: PTCefX509CertificateArray; index: NativeUint; var Result: ICefX509Certificate); extdecl;
begin
  handleExceptionBegin
  Result := X509CertificateArray^[index];
  handleExceptionEnd
end;

{== ICefX509Certificate ==}
procedure  CefX509Certificate_GetSubject(const AObj: ICefX509Certificate; var Result: ICefX509CertPrincipal); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSubject;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetIssuer(const AObj: ICefX509Certificate; var Result: ICefX509CertPrincipal); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetIssuer;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetSerialNumber(const AObj: ICefX509Certificate; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSerialNumber;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetValidStart(const AObj: ICefX509Certificate; var Result: TCefBaseTime); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetValidStart;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetValidExpiry(const AObj: ICefX509Certificate; var Result: TCefBaseTime); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetValidExpiry;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetValidStartAsDateTime(const AObj: ICefX509Certificate; var Result: TDateTime); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetValidStartAsDateTime;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetValidExpiryAsDateTime(const AObj: ICefX509Certificate; var Result: TDateTime); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetValidExpiryAsDateTime;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetDerEncoded(const AObj: ICefX509Certificate; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetDerEncoded;
  handleExceptionEnd
end;

procedure  CefX509Certificate_GetPemEncoded(const AObj: ICefX509Certificate; var Result: ICefBinaryValue); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetPemEncoded;
  handleExceptionEnd
end;

function  CefX509Certificate_GetIssuerChainSize(const AObj: ICefX509Certificate): NativeUInt; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetIssuerChainSize;
  handleExceptionEnd
end;

procedure CefX509Certificate_GetDEREncodedIssuerChain(const AObj: ICefX509Certificate; chainCount: NativeUInt; var chain : TCefBinaryValueArray); extdecl;
var
  RetChan: TCefBinaryValueArray;
begin
  handleExceptionBegin
  AObj.GetDEREncodedIssuerChain(chainCount, RetChan);
  chain := RetChan;
  handleExceptionEnd
end;

procedure CefX509Certificate_GetPEMEncodedIssuerChain(const AObj: ICefX509Certificate; chainCount: NativeUInt; var chain : TCefBinaryValueArray); extdecl;
var
  RetChan: TCefBinaryValueArray;
begin
  handleExceptionBegin
  AObj.GetPEMEncodedIssuerChain(chainCount, RetChan);
  chain := RetChan;
  handleExceptionEnd
end;

{== ICefX509CertPrincipal ==}
function  CefX509CertPrincipal_GetDisplayName(const AObj: ICefX509CertPrincipal): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetDisplayName));
  handleExceptionEnd
end;

function  CefX509CertPrincipal_GetCommonName(const AObj: ICefX509CertPrincipal): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetCommonName));
  handleExceptionEnd
end;

function  CefX509CertPrincipal_GetLocalityName(const AObj: ICefX509CertPrincipal): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetLocalityName));
  handleExceptionEnd
end;

function  CefX509CertPrincipal_GetStateOrProvinceName(const AObj: ICefX509CertPrincipal): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetStateOrProvinceName));
  handleExceptionEnd
end;

function  CefX509CertPrincipal_GetCountryName(const AObj: ICefX509CertPrincipal): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(AObj.GetCountryName));
  handleExceptionEnd
end;

procedure CefX509CertPrincipal_GetStreetAddresses(const AObj: ICefX509CertPrincipal; const addresses: TStrings); extdecl;
begin
  handleExceptionBegin
  AObj.GetStreetAddresses(addresses);
  handleExceptionEnd
end;

procedure CefX509CertPrincipal_GetOrganizationNames(const AObj: ICefX509CertPrincipal; const names: TStrings); extdecl;
begin
  handleExceptionBegin
  AObj.GetOrganizationNames(names);
  handleExceptionEnd
end;

procedure CefX509CertPrincipal_GetOrganizationUnitNames(const AObj: ICefX509CertPrincipal; const names: TStrings); extdecl;
begin
  handleExceptionBegin
  AObj.GetOrganizationUnitNames(names);
  handleExceptionEnd
end;

procedure CefX509CertPrincipal_GetDomainComponents(const AObj: ICefX509CertPrincipal; const components: TStrings); extdecl;
begin
  handleExceptionBegin
  AObj.GetDomainComponents(components);
  handleExceptionEnd
end;

{== ICefSelectClientCertificateCallback ==}
procedure CefSelectClientCertificateCallback_Select(const AObj: ICefSelectClientCertificateCallback; const cert: ICefX509Certificate); extdecl;
begin
  handleExceptionBegin
  AObj.Select(cert);
  handleExceptionEnd
end;

{== ICefSslInfo ==}
function CefSslInfo_GetCertStatus(const AObj: ICefSslInfo): TCefCertStatus;
begin
  handleExceptionBegin
  Result := AObj.GetCertStatus;
  handleExceptionEnd
end;

procedure CefSslInfo_GetX509Certificate(const AObj: ICefSslInfo; var Result: ICefX509Certificate);
begin
  handleExceptionBegin
  Result := AObj.GetX509Certificate();
  handleExceptionEnd
end;

exports
    {== TCefX509CertificateArray ==}
    CefX509CertificateArray_Get,
    {== ICefX509Certificate ==}
    CefX509Certificate_GetSubject,
    CefX509Certificate_GetIssuer,
    CefX509Certificate_GetSerialNumber,
    CefX509Certificate_GetValidStart,
    CefX509Certificate_GetValidExpiry,
    CefX509Certificate_GetValidStartAsDateTime,
    CefX509Certificate_GetValidExpiryAsDateTime,
    CefX509Certificate_GetDerEncoded,
    CefX509Certificate_GetPemEncoded,
    CefX509Certificate_GetIssuerChainSize,
    CefX509Certificate_GetDEREncodedIssuerChain,
    CefX509Certificate_GetPEMEncodedIssuerChain,
    {== ICefX509CertPrincipal ==}
    CefX509CertPrincipal_GetDisplayName,
    CefX509CertPrincipal_GetCommonName,
    CefX509CertPrincipal_GetLocalityName,
    CefX509CertPrincipal_GetStateOrProvinceName,
    CefX509CertPrincipal_GetCountryName,
    CefX509CertPrincipal_GetStreetAddresses,
    CefX509CertPrincipal_GetOrganizationNames,
    CefX509CertPrincipal_GetOrganizationUnitNames,
    CefX509CertPrincipal_GetDomainComponents,
    {== ICefSelectClientCertificateCallback ==}
    CefSelectClientCertificateCallback_Select,
    {== ICefSslInfo ==}
    CefSslInfo_GetCertStatus,
    CefSslInfo_GetX509Certificate
;
