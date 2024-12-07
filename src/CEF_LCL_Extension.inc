//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure  CefExtensionRef_UnWrap(const TObj: ICefExtension; var Result: ICefExtension); extdecl;
begin
  handleExceptionBegin
  Result := TCefExtensionRef.UnWrap(TObj.Wrap);
  handleExceptionEnd
end;

function  CefExtension_GetIdentifier(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := ToPChar(TObj.GetIdentifier);
  handleExceptionEnd
end;

function  CefExtension_GetPath(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetPath));
  handleExceptionEnd
end;

procedure  CefExtension_GetManifest(const TObj: ICefExtension; var Result: ICefDictionaryValue); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetManifest;
  handleExceptionEnd
end;

function  CefExtension_IsSame(const TObj: ICefExtension; const that : ICefExtension) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsSame(that);
  handleExceptionEnd
end;

procedure  CefExtension_GetHandler(const TObj: ICefExtension; var Result: ICefExtensionHandler) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetHandler;
  handleExceptionEnd
end;

procedure  CefExtension_GetLoaderContext(const TObj: ICefExtension; var Result: ICefRequestContext) ; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetLoaderContext;
  handleExceptionEnd
end;

function  CefExtension_IsLoaded(const TObj: ICefExtension) : LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsLoaded;
  handleExceptionEnd
end;

procedure CefExtension_unload(const TObj: ICefExtension); extdecl;
begin
  handleExceptionBegin
  TObj.unload;
  handleExceptionEnd
end;

function  CefExtension_GetBrowserActionPopup(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetBrowserActionPopup));
  handleExceptionEnd
end;

function  CefExtension_GetBrowserActionIcon(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetBrowserActionIcon));
  handleExceptionEnd
end;

function  CefExtension_GetPageActionPopup(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetPageActionPopup));
  handleExceptionEnd
end;

function  CefExtension_GetPageActionIcon(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetPageActionIcon));
  handleExceptionEnd
end;

function  CefExtension_GetOptionsPage(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetOptionsPage));
  handleExceptionEnd
end;

function  CefExtension_GetOptionsUIPage(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetOptionsUIPage));
  handleExceptionEnd
end;

function  CefExtension_GetBackgroundPage(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetBackgroundPage));
  handleExceptionEnd
end;

function  CefExtension_GetURL(const TObj: ICefExtension) : PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetURL));
  handleExceptionEnd
end;

exports
  CefExtensionRef_UnWrap,
  CefExtension_GetIdentifier,
  CefExtension_GetPath,
  CefExtension_GetManifest,
  CefExtension_IsSame,
  CefExtension_GetHandler,
  CefExtension_GetLoaderContext,
  CefExtension_IsLoaded,
  CefExtension_unload,
  CefExtension_GetBrowserActionPopup,
  CefExtension_GetBrowserActionIcon,
  CefExtension_GetPageActionPopup,
  CefExtension_GetPageActionIcon,
  CefExtension_GetOptionsPage,
  CefExtension_GetOptionsUIPage,
  CefExtension_GetBackgroundPage,
  CefExtension_GetURL;
