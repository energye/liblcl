//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

procedure CefDownloadItemRef_UnWrap(const data: ICefDownloadItem; var Result: ICefDownloadItem); extdecl;
begin
  handleExceptionBegin
  Result := TCefDownLoadItemRef.UnWrap(data.Wrap);
  handleExceptionEnd
end;

function CefDownloadItem_IsValid(const TObj: ICefDownloadItem): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsValid();
  handleExceptionEnd
end;

function CefDownloadItem_IsInProgress(const TObj: ICefDownloadItem): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsInProgress();
  handleExceptionEnd
end;

function CefDownloadItem_IsComplete(const TObj: ICefDownloadItem): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsComplete();
  handleExceptionEnd
end;

function CefDownloadItem_IsCanceled(const TObj: ICefDownloadItem): LongBool; extdecl;
begin
  handleExceptionBegin
  Result := TObj.IsCanceled();
  handleExceptionEnd
end;

function CefDownloadItem_CurrentSpeed(const TObj: ICefDownloadItem): Int64; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetCurrentSpeed();
  handleExceptionEnd
end;

function CefDownloadItem_PercentComplete(const TObj: ICefDownloadItem): Integer; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetPercentComplete();
  handleExceptionEnd
end;

function CefDownloadItem_TotalBytes(const TObj: ICefDownloadItem): Int64; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetTotalBytes();
  handleExceptionEnd
end;

function CefDownloadItem_ReceivedBytes(const TObj: ICefDownloadItem): Int64; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetReceivedBytes();
  handleExceptionEnd
end;

procedure CefDownloadItem_StartTime(const TObj: ICefDownloadItem; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetStartTime();
  handleExceptionEnd
end;

procedure CefDownloadItem_EndTime(const TObj: ICefDownloadItem; var Result: Double); extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetEndTime();
  handleExceptionEnd
end;

function CefDownloadItem_FullPath(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetFullPath()));
  handleExceptionEnd
end;

function CefDownloadItem_Id(const TObj: ICefDownloadItem): Cardinal; extdecl;
begin
  handleExceptionBegin
  Result := TObj.GetId();
  handleExceptionEnd
end;

function CefDownloadItem_Url(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetUrl()));
  handleExceptionEnd
end;

function CefDownloadItem_OriginalUrl(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetOriginalUrl()));
  handleExceptionEnd
end;

function CefDownloadItem_SuggestedFileName(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetSuggestedFileName()));
  handleExceptionEnd
end;

function CefDownloadItem_ContentDisposition(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetContentDisposition()));
  handleExceptionEnd
end;

function CefDownloadItem_MimeType(const TObj: ICefDownloadItem): PChar; extdecl;
begin
  handleExceptionBegin
  Result := PChar(string(TObj.GetMimeType()));
  handleExceptionEnd
end;


//设置下载目录
procedure CefBeforeDownloadCallback_Cont(const TObj: ICefBeforeDownloadCallback; downloadPath: PChar; showDialog: LongBool); extdecl;
begin
  handleExceptionBegin
  TObj.Cont(PCharToUStr(downloadPath), showDialog);
  handleExceptionEnd
end;

//下载暂停
procedure CefDownloadItemCallback_Pause(const TObj: ICefDownloadItemCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Pause;
  handleExceptionEnd
end;

//下载取消
procedure CefDownloadItemCallback_Cancel(const TObj: ICefDownloadItemCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Cancel;
  handleExceptionEnd
end;

//下载恢复
procedure CefDownloadItemCallback_Resume(const TObj: ICefDownloadItemCallback); extdecl;
begin
  handleExceptionBegin
  TObj.Resume;
  handleExceptionEnd
end;

procedure CefDownloadItemCallbackRef_UnWrap(const TObj: ICefDownloadItemCallback; var Result: ICefDownloadItemCallback); extdecl;
begin
  handleExceptionBegin
  Result := TCefDownloadItemCallbackRef.UnWrap(TObj.Wrap);
  handleExceptionEnd
end;

exports
    CefDownloadItemRef_UnWrap,
    CefDownloadItem_IsValid,
    CefDownloadItem_IsInProgress,
    CefDownloadItem_IsComplete,
    CefDownloadItem_IsCanceled,
    CefDownloadItem_CurrentSpeed,
    CefDownloadItem_PercentComplete,
    CefDownloadItem_TotalBytes,
    CefDownloadItem_ReceivedBytes,
    CefDownloadItem_StartTime,
    CefDownloadItem_EndTime,
    CefDownloadItem_FullPath,
    CefDownloadItem_Id,
    CefDownloadItem_Url,
    CefDownloadItem_OriginalUrl,
    CefDownloadItem_SuggestedFileName,
    CefDownloadItem_ContentDisposition,
    CefDownloadItem_MimeType,
    CefBeforeDownloadCallback_Cont,
    CefDownloadItemCallback_Pause,
    CefDownloadItemCallback_Cancel,
    CefDownloadItemCallback_Resume,
    CefDownloadItemCallbackRef_UnWrap
;
