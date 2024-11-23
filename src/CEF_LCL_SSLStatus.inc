//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure SSLStatusRef_UnWrap(const AObj: ICefSSLStatus; out Result: ICefSSLStatus); extdecl;
begin
  handleExceptionBegin
  Result := TCefSSLStatusRef.UnWrap(AObj.Wrap);
  handleExceptionEnd
end;

function SSLStatus_IsSecureConnection(const AObj: ICefSSLStatus): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := AObj.IsSecureConnection();
  handleExceptionEnd
end;

function SSLStatus_GetCertStatus(const AObj: ICefSSLStatus): TCefCertStatus; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetCertStatus();
  handleExceptionEnd
end;

function SSLStatus_GetSSLVersion(const AObj: ICefSSLStatus): TCefSSLVersion; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetSSLVersion();
  handleExceptionEnd
end;

function SSLStatus_GetContentStatus(const AObj: ICefSSLStatus): TCefSSLContentStatus; extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetContentStatus();
  handleExceptionEnd
end;

procedure SSLStatus_GetX509Certificate(const AObj: ICefSSLStatus; out Result: ICefX509Certificate); extdecl;
begin
  handleExceptionBegin
  Result := AObj.GetX509Certificate();
  handleExceptionEnd
end;


exports
  SSLStatusRef_UnWrap,
  SSLStatus_IsSecureConnection,
  SSLStatus_GetCertStatus,
  SSLStatus_GetSSLVersion,
  SSLStatus_GetContentStatus,
  SSLStatus_GetX509Certificate;
