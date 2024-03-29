unit uCEFDownloadImageCallBack;

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
  TCefDownloadImageCallbackOwn = class(TCefBaseRefCountedOwn, ICefDownloadImageCallback)
    protected
      procedure OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: Integer; const image: ICefImage); virtual; abstract;

    public
      constructor Create; virtual;
  end;

  TCefFastDownloadImageCallback = class(TCefDownloadImageCallbackOwn)
    protected
      FProc: TOnDownloadImageFinishedProc;

      procedure OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: Integer; const image: ICefImage); override;

    public
      constructor Create(const proc: TOnDownloadImageFinishedProc); reintroduce;
  end;

  TCefCustomDownloadImageCallback = class(TCefDownloadImageCallbackOwn)
    protected
      FEvents : Pointer;

      procedure OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: Integer; const image: ICefImage); override;

    public
      constructor Create(const aEvents : IChromiumEvents); reintroduce;
      destructor  Destroy; override;
  end;

implementation


uses
  {$IFDEF DELPHI16_UP}
  System.SysUtils,
  {$ELSE}
  SysUtils,
  {$ENDIF}
  uCEFMiscFunctions, uCEFLibFunctions, uCEFImage;


// TCefDownloadImageCallbackOwn

procedure cef_download_image_callback_on_download_image_finished(      self             : PCefDownloadImageCallback;
                                                                 const image_url        : PCefString;
                                                                       http_status_code : Integer;
                                                                       image            : PCefImage); stdcall;
var
  TempObject : TObject;
begin
  TempObject := CefGetObject(self);

  if (TempObject <> nil) and (TempObject is TCefDownloadImageCallbackOwn) then
    TCefDownloadImageCallbackOwn(TempObject).OnDownloadImageFinished(CefString(image_url),
                                                                     http_status_code,
                                                                     TCefImageRef.UnWrap(image));
end;

constructor TCefDownloadImageCallbackOwn.Create;
begin
  inherited CreateData(SizeOf(TCefDownloadImageCallback));

  with PCefDownloadImageCallback(FData)^ do
    on_download_image_finished := {$IFDEF FPC}@{$ENDIF}cef_download_image_callback_on_download_image_finished;
end;


// TCefFastDownloadImageCallback

constructor TCefFastDownloadImageCallback.Create(const proc: TOnDownloadImageFinishedProc);
begin
  inherited Create;

  FProc := proc;
end;

procedure TCefFastDownloadImageCallback.OnDownloadImageFinished(const imageUrl: ustring; httpStatusCode: Integer; const image: ICefImage);
begin
  FProc(imageUrl, httpStatusCode, image);
end;


// TCefCustomDownloadImageCallback

constructor TCefCustomDownloadImageCallback.Create(const aEvents : IChromiumEvents);
begin
  inherited Create;

  FEvents := Pointer(aEvents);
end;

destructor TCefCustomDownloadImageCallback.Destroy;
begin
  FEvents := nil;

  inherited Destroy;
end;

procedure TCefCustomDownloadImageCallback.OnDownloadImageFinished(const imageUrl       : ustring;
                                                                        httpStatusCode : Integer;
                                                                  const image          : ICefImage);
begin
  try
    try
      if (FEvents <> nil) then IChromiumEvents(FEvents).doDownloadImageFinished(imageUrl, httpStatusCode, image);
    except
      on e : exception do
        if CustomExceptionHandler('TCefCustomDownloadImageCallback.OnDownloadImageFinished', e) then raise;
    end;
  finally
    FEvents := nil;
  end;
end;

end.

