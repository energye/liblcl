//----------------------------------------
// Copyright © yanghy. All Rights Reserved.
//
// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uCEF_LCL_Chromium;

{$mode objfpc}{$H+}
{$I cef.inc}

interface

uses
  uCEF_LCL_ConsoleWrite,
  {$ifdef DARWIN}
  uCEFLazarusCocoa,
  {$endif}
  Controls, uCEFChromium, uCEFInterfaces, uCEFTypes,
  uCEF_LCL_Entity, uCEF_LCL_DictionaryValue,
  fgl, Classes, SysUtils;

type

  {
   TPBrowserDownloadItemList
    Chromium Browser 下载集合，在浏览器有下载时添加进来，下载完成 和 关闭浏览器释放掉。
    Key=下载ID
    Value=下载项
  }
  TPBrowserDownloadItemList = specialize TFPGMap<integer, ICefDownloadItemCallback>;
  {
   浏览器frames
  }
  //TBrowserFrames = specialize TFPGMap<int64, ICefFrame>;

  {ChromiumBrowser 浏览器对象}
  PChromiumBrowser = ^ChromiumBrowser;

  ChromiumBrowser = record
    BrowserId: integer;//浏览器ID
    Browser: ICefBrowser;//浏览器对象
    //Frames: TBrowserFrames;//浏览器Frame对象
    RenderProcessMessage: ICefProcessMessage;//渲染进程message
    BrowserProcessMessage: ICefProcessMessage;//浏览器进程message
    BrowserDownloadItems: TPBrowserDownloadItemList;//浏览器下载对象集合
  end;
  {
   TMainChromiumBrowserList
   Chromium Browser 集合，在初始化时，存放所有浏览器，关闭某个浏览器时释放掉。
   关闭程序时全部释放掉
   Key 浏览器ID = browserId
   Value 浏览器对象 = ChromiumBrowser
  }
  TMainChromiumBrowserList = specialize TFPGMap<integer, PChromiumBrowser>;

  {TMainChromiumBrowserClass 维护浏览器对象操作类}
  TMainChromiumBrowserClass = class
  private
  class var
    TMainChromiumBrowsers: TMainChromiumBrowserList;
  public
    class constructor Create;
    class destructor Destroy;
    // Put Browser
    class function PutBrowser(const Browser: ICefBrowser): PChromiumBrowser;
    // Get ChromiumBrowser
    class function GetChromiumBrowserById(const BrowserId: integer): PChromiumBrowser;
    // Get rowserById
    class function GetBrowserById(const BrowserId: integer): ICefBrowser;
    // Get Frame
    class function GetFrameById(const BrowserId: integer; const FrameId: int64): ICefFrame;
    // Remove Browser
    class procedure RemoveBrowser(const BrowserId: integer);

    // Put DownloadItemCallback
    class procedure PutBrowserDownloadItemCallback(const BrowserId, downloadId: integer; const itemCallback: ICefDownloadItemCallback);
    // Get DownloadItemCallback
    class function GetBrowserDownloadItemCallback(const BrowserId, DownloadId: integer): ICefDownloadItemCallback;
    // Remove DownloadItem
    class procedure RemoveBrowserItemDownload(const BrowserId: integer; const downloadId: integer);
  end;

// function

//初始化chromium默认配置
procedure ChromiumInitDefault(const Chromium: TChromium; const Config: TCEFChromiumConfig);

procedure ChromiumExecDevToolsMethod(const Chromium: TChromium; const messageId: integer; const MethodName: PChar; const len: integer; const arguments: array of byte);


implementation

{TMainChromiumBrowserClass begin}
class constructor TMainChromiumBrowserClass.Create;
begin
  TMainChromiumBrowsers := TMainChromiumBrowserList.Create;
end;

class destructor TMainChromiumBrowserClass.Destroy;
begin
  TMainChromiumBrowsers.Clear;
  TMainChromiumBrowsers.Free;
end;

// Get PChromiumBrowser
class function TMainChromiumBrowserClass.GetChromiumBrowserById(const BrowserId: integer): PChromiumBrowser;
var
  chromiumBrowser: PChromiumBrowser;
begin
  TMainChromiumBrowsers.TryGetData(BrowserId, chromiumBrowser);
  Result := chromiumBrowser;
end;

class function TMainChromiumBrowserClass.GetBrowserById(const BrowserId: integer): ICefBrowser;
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    Result := chromiumBrowser^.Browser;
  end
  else
    Result := nil;
end;

// Put PChromiumBrowser
class function TMainChromiumBrowserClass.PutBrowser(const Browser: ICefBrowser): PChromiumBrowser;
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(Browser.Identifier);
  if chromiumBrowser = nil then
  begin
    //初始化PChromiumBrowser, TPBrowserDownloadItemList
    chromiumBrowser := new(PChromiumBrowser);
    chromiumBrowser^.BrowserId := Browser.Identifier;
    chromiumBrowser^.Browser := Browser;
    chromiumBrowser^.BrowserDownloadItems := TPBrowserDownloadItemList.Create;
    //chromiumBrowser^.Frames := TBrowserFrames.Create;
    TMainChromiumBrowsers.AddOrSetData(Browser.Identifier, chromiumBrowser);
  end;
  Result := chromiumBrowser;
end;

class function TMainChromiumBrowserClass.GetFrameById(const BrowserId: integer; const FrameId: int64): ICefFrame;
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    Result := chromiumBrowser^.Browser.GetFrameByident(FrameId);
    exit;
  end;
  Result := nil;
end;

// Put ICefDownloadItemCallback
class procedure TMainChromiumBrowserClass.PutBrowserDownloadItemCallback(const BrowserId, downloadId: integer; const itemCallback: ICefDownloadItemCallback);
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    if chromiumBrowser^.BrowserDownloadItems.IndexOf(downloadId) = -1 then
    begin
      chromiumBrowser^.BrowserDownloadItems.AddOrSetData(downloadId, itemCallback);
    end;
  end;
end;

// Get ICefDownloadItemCallback
class function TMainChromiumBrowserClass.GetBrowserDownloadItemCallback(const BrowserId, DownloadId: integer): ICefDownloadItemCallback;
var
  chromiumBrowser: PChromiumBrowser;
  DownloadItemCallback: ICefDownloadItemCallback;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    if (chromiumBrowser^.BrowserDownloadItems.TryGetData(DownloadId, DownloadItemCallback)) then
    begin
      Result := DownloadItemCallback;
      exit;
    end;
  end;
  Result := nil;
end;

// Remove RemoveBrowserDownloadItem
class procedure TMainChromiumBrowserClass.RemoveBrowserItemDownload(const BrowserId: integer; const downloadId: integer);
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    chromiumBrowser^.BrowserDownloadItems.Remove(downloadId);
  end;
end;

// Remove PChromiumBrowser
class procedure TMainChromiumBrowserClass.RemoveBrowser(const BrowserId: integer);
var
  chromiumBrowser: PChromiumBrowser;
begin
  chromiumBrowser := GetChromiumBrowserById(BrowserId);
  if chromiumBrowser <> nil then
  begin
    chromiumBrowser^.BrowserDownloadItems.Clear;
    chromiumBrowser^.BrowserDownloadItems.Free;
    chromiumBrowser^.BrowserDownloadItems := nil;
    //chromiumBrowser^.Frames.Clear;
    //chromiumBrowser^.Frames.Free;
    //chromiumBrowser^.Frames := nil;
    chromiumBrowser^.Browser := nil;
    chromiumBrowser^.BrowserId := 0;
  end;

  TMainChromiumBrowsers.Remove(BrowserId);
end;

{TMainChromiumBrowserClass end}


//初始化chromium默认配置
procedure ChromiumInitDefault(const Chromium: TChromium; const Config: TCEFChromiumConfig);
begin
  GChromiumConfig := Config;
  //一些配置
  //Chromium.JavascriptEnabled := Boolean(Config.EnabledJavascript);
  //通过设置这些首选项，可以降低/避免WebRTC的IP泄漏
  Chromium.WebRTCIPHandlingPolicy := hpDisableNonProxiedUDP;
  Chromium.WebRTCMultipleRoutes := STATE_DISABLED;
  Chromium.WebRTCNonproxiedUDP := STATE_DISABLED;
end;

procedure ChromiumExecDevToolsMethod(const Chromium: TChromium; const messageId: integer; const MethodName: PChar; const len: integer; const arguments: array of byte);
var
  method: ustring;
  dictValue: TDictValueList;
begin
  method := PCharToUStr(MethodName);
  try
    if len > 0 then
    begin
      dictValue := TDictValueList.Create;
      dictValue.UnPackage(arguments);
      Chromium.ExecuteDevToolsMethod(messageId, method, dictValue.GetDictValue());
      //dictValue.Destroy;//这个不能打开
    end
    else
    begin
      Chromium.ExecuteDevToolsMethod(messageId, method, nil);
    end;
  finally
    dictValue := nil;
  end;
end;

end.
