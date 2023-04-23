//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefX509CertificateArray_Get(const X509CertificateArray: PTCefX509CertificateArray; index: NativeUint; var Result: ICefX509Certificate); extdecl;
begin
  handleExceptionBegin
  Result := X509CertificateArray^[index];
  handleExceptionEnd
end;


exports
    CefX509CertificateArray_Get
;
