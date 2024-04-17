//----------------------------------------
// Copyright © yanghy. All Rights Reserved.

// Licensed under Lazarus.modifiedLGPL
//----------------------------------------

unit uGIFPlay;

{$mode objfpc}{$H+}

interface

uses
  Classes, LCLProc, Lresources, SysUtils, Controls, Graphics, ExtCtrls, IntfGraphics, FPimage, Contnrs, GraphType, Dialogs, types;

const
  EXT_INTRODUCER = $21;
  EXT_GRAPHICS_CONTROL = $F9;
  EXT_PLAIN_TEXT = $01;
  EXT_APPLICATION = $FF;
  EXT_COMMENT = $FE;

  DSC_LOCAL_IMAGE = $2C;

  ID_TRANSPARENT = $01;
  ID_COLOR_TABLE_SIZE = $07;
  ID_SORT = $20;
  ID_INTERLACED = $40;
  ID_COLOR_TABLE = $80;
  ID_IMAGE_DESCRIPTOR = $2C;
  ID_TRAILER = $3B;

  CODE_TABLE_SIZE = 4096;

type
  TRGB = packed record
    Red, Green, Blue: byte;
  end;

  TGIFPlayHeader = packed record
    Signature: array[0..2] of char;  // 页眉签名（始终为“GIF”）
    Version: array[0..2] of char;    // GIF格式版本（“87a”或“89a”）
    ScreenWidth: word;               // 以像素为单位的显示屏宽度
    ScreenHeight: word;              // 以像素为单位的显示屏高度
    Packedbit,                       // 屏幕和彩色地图信息
    BackgroundColor,                 // 背景色索引
    AspectRatio: byte;               // 像素纵横比
  end;

  TGIFPlayImageDescriptor = packed record
    Left,                 // 显示器上图像的X位置
    Top,                  // 显示器上图像的Y位置
    Width,                // 图像的宽度（像素）
    Height: word;         // 图像的高度（像素）
    Packedbit: byte;      // 图像和颜色表数据信息
  end;

  TGIFPlayGraphicsControlExtension = packed record
    BlockSize,          // 剩余字段的大小（始终为04h）
    Packedbit: byte;    // 要使用的图形处理方法
    DelayTime: word;    // 等待数十秒
    ColorIndex,         // 透明颜色索引
    Terminator: byte;   // 块终止符（始终为0）
  end;

  TGIFPlay = class;

  { TGIFPlayImage }
  TGIFPlayImage = class
  private
    FBitmap: TBitmap;
    FPosX: word;
    FPosY: word;
    FDelay: word;
    FMethod: byte;
  public
    constructor Create;
    destructor Destroy; override;
    property Bitmap: TBitmap read FBitmap;
    property Delay: word read FDelay;
    property Method: byte read FMethod;
    property PosX: word read FPosX;
    property PosY: word read FPosY;
  end;

  { TGIFPlayList }
  TGIFPlayList = class(TObjectList)
  private
  protected
    function GetItems(Index: integer): TGIFPlayImage;
    procedure SetItems(Index: integer; AGifImage: TGIFPlayImage);
  public
    function Add(AGifImage: TGIFPlayImage): integer;
    function Extract(Item: TGIFPlayImage): TGIFPlayImage;
    function Remove(AGifImage: TGIFPlayImage): integer;
    function IndexOf(AGifImage: TGIFPlayImage): integer;
    function First: TGIFPlayImage;
    function Last: TGIFPlayImage;
    procedure Insert(Index: integer; AGifImage: TGIFPlayImage);
    property Items[Index: integer]: TGIFPlayImage read GetItems write SetItems; default;
  end;

  { TGIFPlayLoader }
  TGIFPlayLoader = class
  private
    FGifHeader: TGIFPlayHeader;
    FGifDescriptor: TGIFPlayImageDescriptor;
    FGifGraphicsCtrlExt: TGIFPlayGraphicsControlExtension;
    FGifUseGraphCtrlExt: boolean;
    FGifBackgroundColor: byte;
    FInterlaced: boolean;
    FScanLine: pbyte;
    FLineSize: integer;
    FDisposalMethod: byte;
    FEmpty: boolean;
    FFileName: string;
    FGifStream: TMemoryStream;
    FHeight: integer;
    FIsTransparent: boolean;
    FWidth: integer;
    FPalette: TFPPalette;
    FLocalHeight: integer;
    FLocalWidth: integer;
    procedure ReadPalette(Stream: TStream; Size: integer);
    procedure ReadScanLine(Stream: TStream);
    procedure ReadHeader(Stream: TStream);
    procedure ReadGlobalPalette(Stream: TStream);
    procedure ReadGraphCtrlExt;
    procedure SetInterlaced(const AValue: boolean);
    procedure SetTransparent(const AValue: boolean);
    function SkipBlock(Stream: TStream): byte;
    procedure WriteScanLine(Img: TFPCustomImage);
    procedure ReadGifBitmap(Stream: TStream);
  public
    constructor Create(const FileName: string);
    constructor Create(GifStream: TMemoryStream);
    destructor Destroy; override;
    function LoadAllBitmap(var AGifList: TGIFPlayList): boolean;
    function LoadFromLazarusResource(const ResName: string; var AGifList: TGIFPlayList): boolean;
    function LoadFirstBitmap(var ABitmap: TBitmap): boolean;
    property Empty: boolean read FEmpty;
    property Height: integer read FHeight;
    property Width: integer read FWidth;
    property IsTransparent: boolean read FIsTransparent write SetTransparent;
    property Interlaced: boolean read FInterlaced write SetInterlaced;
  end;

  { TGIFPlay }
  TGIFPlay = class(TGraphicControl)
  private
    { Private declarations }
    FAnimate: boolean;
    FEmpty: boolean;
    FFileName: string;
    FGifBitmaps: TGIFPlayList;
    FOnFrameChanged: TNotifyEvent;
    FOnStart: TNotifyEvent;
    FOnStop: TNotifyEvent;
    FWait: TTimer;
    FCurrentImage: integer;
    FGifHeight: integer;
    FGifWidth: integer;
    procedure OnTime(Sender: TObject);
    procedure SetAnimate(const AValue: boolean);
    procedure SetFileName(const AValue: string);
    procedure SetFileStream(const GifStream: TMemoryStream);
    procedure DefineSize(AWidth, AHeight: integer);
  protected
    BufferImg: TBitmap;
    CurrentView: TBitmap;
    procedure CalculatePreferredSize(var PreferredWidth, PreferredHeight: integer; WithThemeSpace: boolean); override;
    procedure DoAutoSize; override;
    procedure DoStart;
    procedure DoStop;
    class function GetControlClassDefaultSize: TSize; override;
    procedure GifChanged;
    procedure LoadFromFile(const Filename: string); virtual;
    procedure Paint; override;
    procedure ResetImage;
    procedure SetColor(Value: TColor); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure NextFrame;
    procedure PriorFrame;
    property Empty: boolean read FEmpty;
    property GifBitmaps: TGIFPlayList read FGifBitmaps;
    property CurrentImageIndex: integer read FCurrentImage;
    function LoadFromLazarusResource(const ResName: string): boolean;
    procedure LoadFromStream(GifStream: TMemoryStream); virtual;
  published
    property Anchors;
    property AutoSize default True;
    property Animate: boolean read FAnimate write SetAnimate default True;
    property BorderSpacing;
    property Color default clDefault;
    property Constraints;
    property FileName: string read FFileName write SetFileName;
    property FileStream: TMemoryStream write SetFileStream;
    property Height;
    property OnClick;
    property OnDblClick;
    property OnFrameChanged: TNotifyEvent read FOnFrameChanged write FOnFrameChanged;
    property OnMouseDown;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnMouseMove;
    property OnMouseUp;
    property OnStart: TNotifyEvent read FOnStart write FOnStart;
    property OnStop: TNotifyEvent read FOnStop write FOnStop;
    property ParentShowHint;
    property ShowHint;
    property Visible;
    property Width;
  end;

implementation

{ TGIFPlay }
constructor TGIFPlay.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := [csCaptureMouse, csClickEvents, csDoubleClicks];
  AutoSize := True;
  SetInitialBounds(0, 0, GetControlClassDefaultSize.CX, GetControlClassDefaultSize.CY);
  FEmpty := True;
  FCurrentImage := 0;
  CurrentView := TBitmap.Create;
  if not (csDesigning in ComponentState) then
  begin
    BufferImg := TBitmap.Create;
    FWait := TTimer.Create(Self);
    with FWait do
    begin
      Interval := 100;
      OnTimer := @OnTime;
      Enabled := False;
    end;
  end;
  Animate := True;
end;

destructor TGIFPlay.Destroy;
begin
  inherited Destroy;
  if assigned(FGifBitmaps) then
    FreeAndNil(FGifBitmaps);
  BufferImg.Free;
  CurrentView.Free;
end;

procedure TGIFPlay.NextFrame;
begin
  if (not FEmpty) and Visible and (not FAnimate) then
  begin
    if FCurrentImage >= GifBitmaps.Count - 1 then
      FCurrentImage := 0
    else
      Inc(FCurrentImage);
    if Assigned(FOnFrameChanged) then
      FOnFrameChanged(Self);
    Repaint;
  end;
end;

procedure TGIFPlay.PriorFrame;
var
  DesiredImage: integer;
begin
  if (not FEmpty) and Visible and (not FAnimate) then
  begin
    if FCurrentImage = 0 then
      DesiredImage := GifBitmaps.Count - 1
    else
      DesiredImage := FCurrentImage - 1;
    // 为了正确显示，将图像从第一帧重新绘制到所需帧
    FCurrentImage := 0;
    while FCurrentImage < DesiredImage do
    begin
      with GifBitmaps.Items[FCurrentImage] do
      begin
        BufferImg.Canvas.Brush.Color := (Self.Color);
        if FCurrentImage = 0 then
          BufferImg.Canvas.FillRect(Rect(0, 0, Width, Height));
        if Delay <> 0 then
          FWait.Interval := Delay * 10;
        BufferImg.Canvas.Draw(PosX, PosY, Bitmap);
        case Method of
          //0 : Not specified...
          //1 : No change Background
          2: BufferImg.Canvas.FillRect(
              Rect(PosX, PosY, Bitmap.Width + PosX, Bitmap.Height + PosY));

          3: BufferImg.Canvas.FillRect(Rect(0, 0, Width, Height));
        end;
      end;
      Inc(FCurrentImage);
    end;
    if Assigned(FOnFrameChanged) then
      FOnFrameChanged(Self);
    Repaint;
  end;
end;

function TGIFPlay.LoadFromLazarusResource(const ResName: string): boolean;
var
  GifLoader: TGIFPlayLoader;
  StateAnimate: boolean;
  Resource: TLResource;
begin
  Result := False;
  StateAnimate := Animate;
  FWait.Enabled := False;
  ResetImage;
  Resource := nil;
  Resource := LazarusResources.Find(ResName);
  if Resource <> nil then
    if CompareText(LazarusResources.Find(ResName).ValueType, 'gif') = 0 then
    begin
      GifLoader := TGIFPlayLoader.Create(Filename);
      FEmpty := not GifLoader.LoadFromLazarusResource(ResName, FGifBitmaps);
      DefineSize(GifLoader.Width, GifLoader.Height);
      GifLoader.Free;
      Result := FEmpty;
    end;
  if not Empty then
    GifChanged;
  FWait.Enabled := StateAnimate;
end;

procedure TGIFPlay.LoadFromStream(GifStream: TMemoryStream);
var
  GifLoader: TGIFPlayLoader;
begin
  FEmpty := True;
  if not assigned(GifStream) then
    exit;
  GifLoader := TGIFPlayLoader.Create(GifStream);
  if (csDesigning in ComponentState) then
    FEmpty := not GifLoader.LoadFirstBitmap(CurrentView)
  else
    FEmpty := not GifLoader.LoadAllBitmap(FGifBitmaps);
  DefineSize(GifLoader.Width, GifLoader.Height);
  GifLoader.Free;
end;

procedure TGIFPlay.LoadFromFile(const Filename: string);
var
  GifLoader: TGIFPlayLoader;
begin
  FEmpty := True;
  if not FileExists(Filename) then
    exit;
  GifLoader := TGIFPlayLoader.Create(Filename);
  if (csDesigning in ComponentState) then
    FEmpty := not GifLoader.LoadFirstBitmap(CurrentView)
  else
    FEmpty := not GifLoader.LoadAllBitmap(FGifBitmaps);
  DefineSize(GifLoader.Width, GifLoader.Height);
  GifLoader.Free;
end;

procedure TGIFPlay.OnTime(Sender: TObject);
begin
  if (not Empty) and Visible then
  begin
    if FCurrentImage >= GifBitmaps.Count - 1 then
      FCurrentImage := 0
    else
      Inc(FCurrentImage);
    if Assigned(FOnFrameChanged) then
      FOnFrameChanged(Self);
    Repaint;
  end;
end;

procedure TGIFPlay.SetAnimate(const AValue: boolean);
begin
  if FAnimate = AValue then
    exit;
  FAnimate := AValue;
  if not (csDesigning in ComponentState) then
  begin
    FWait.Enabled := Animate;
    if Animate then
      DoStart
    else
      DoStop;
  end;
end;

procedure TGIFPlay.SetFileStream(const GifStream: TMemoryStream);
begin
  ResetImage;
  if not assigned(GifStream) then
    exit;
  LoadFromStream(GifStream);
  if not Empty then
    GifChanged;
end;

procedure TGIFPlay.SetFileName(const AValue: string);
begin
  if (FFileName = AValue) then Exit;
  FFileName := AValue;
  ResetImage;
  if (FFileName = '') then Exit;
  LoadFromFile(FFileName);
  if not Empty then
    GifChanged;
end;

procedure TGIFPlay.DefineSize(AWidth, AHeight: integer);
begin
  if (AWidth = FGifWidth) and (AHeight = FGifHeight) then
    Exit;
  FGifWidth := AWidth;
  FGifHeight := AHeight;
  Height := FGifHeight;
  Width := FGifWidth;
  if not (csDesigning in ComponentState) then
  begin
    BufferImg.Height := Height;
    BufferImg.Width := Width;
  end;
end;

procedure TGIFPlay.CalculatePreferredSize(var PreferredWidth, PreferredHeight: integer; WithThemeSpace: boolean);
begin
  PreferredWidth := FGifWidth;
  PreferredHeight := FGifHeight;
end;

procedure TGIFPlay.DoAutoSize;
var
  ModifyWidth, ModifyHeight: boolean;
  NewWidth: integer;
  NewHeight: integer;
begin
  if AutoSizing then
    Exit; // 我们一开始就不应该来这里

  BeginAutoSizing;
  try
    GetPreferredSize(NewWidth, NewHeight);
    ModifyWidth := [akLeft, akRight] * (Anchors + AnchorAlign[Align]) <> [akLeft, akRight];
    ModifyHeight := [akTop, akBottom] * (Anchors + AnchorAlign[Align]) <> [akTop, akBottom];

    if not ModifyWidth then
      NewWidth := Width;
    if not ModifyHeight then
      NewHeight := Height;

    if (NewWidth <> Width) or (NewHeight <> Height) then
    begin
      SetBounds(Left, Top, NewWidth, NewHeight);
    end;
  finally
    EndAutoSizing;
  end;
end;

class function TGIFPlay.GetControlClassDefaultSize: TSize;
begin
  Result.CX := 90;
  Result.CY := 90;
end;

procedure TGIFPlay.GifChanged;
begin
  if not (csDesigning in ComponentState) then
  begin
    //BufferImg.Canvas.Brush.Color := (self.Color);
    BufferImg.Canvas.FillRect(Rect(0, 0, Width, Height));
    with GifBitmaps.Items[FCurrentImage] do
      BufferImg.Canvas.Draw(PosX, PosY, Bitmap);
    CurrentView.Assign(BufferImg);
  end;
  InvalidatePreferredSize;
  AdjustSize;
end;

procedure TGIFPlay.Paint;
begin
  if (not Empty) and Visible then
  begin
    if not (csDesigning in ComponentState) then
    begin
      if (FCurrentImage < GifBitmaps.Count) then
        with GifBitmaps.Items[FCurrentImage] do
        begin
          BufferImg.Canvas.Brush.Color := (self.Color);
          if FCurrentImage = 0 then
            BufferImg.Canvas.FillRect(Rect(0, 0, Width, Height));
          if Delay <> 0 then
            FWait.Interval := Delay * 10;
          BufferImg.Canvas.Draw(PosX, PosY, Bitmap);
          CurrentView.Assign(BufferImg);
          case Method of
            //0 : Not specified...
            //1 : No change Background
            2: BufferImg.Canvas.FillRect(Rect(PosX, PosY, Bitmap.Width + PosX, Bitmap.Height + PosY));
            3: BufferImg.Canvas.FillRect(Rect(0, 0, Width, Height));
          end;
        end;
    end
    else
    begin
      Canvas.Brush.Color := (self.Color);
      Canvas.FillRect(Rect(0, 0, Width, Height));
    end;
    Canvas.Draw(0, 0, CurrentView);
  end;
  inherited Paint;
end;

procedure TGIFPlay.ResetImage;
begin
  if assigned(FGifBitmaps) then
    FreeAndNil(FGifBitmaps);
  FCurrentImage := 0;
  with CurrentView do
  begin
    Canvas.Brush.Color := (self.Color);
    Canvas.FillRect(Rect(0, 0, Width, Height));
  end;
end;

procedure TGIFPlay.SetColor(Value: TColor);
begin
  inherited SetColor(Value);
end;

procedure TGIFPlay.DoStart;
begin
  if assigned(OnStart) then
    OnStart(Self);
end;

procedure TGIFPlay.DoStop;
begin
  if assigned(OnStop) then
    OnStop(Self);
end;

{ TGIFPlayLoader }
constructor TGIFPlayLoader.Create(const FileName: string);
begin
  FFileName := FileName;
  FGifStream := nil;
  FGifUseGraphCtrlExt := False;
  FPalette := TFPPalette.Create(0);
  FHeight := 20;
  FWidth := 20;
end;

constructor TGIFPlayLoader.Create(GifStream: TMemoryStream);
begin
  FGifStream := GifStream;
  FFileName := '';
  FGifUseGraphCtrlExt := False;
  FPalette := TFPPalette.Create(0);
  FHeight := 20;
  FWidth := 20;
end;

destructor TGIFPlayLoader.Destroy;
begin
  inherited Destroy;
  FPalette.Free;
end;

function TGIFPlayLoader.LoadAllBitmap(var AGifList: TGIFPlayList): boolean;
var
  GifStream: TMemoryStream;
  Introducer: byte;
  FPImage: TLazIntfImage;
  ImgFormatDescription: TRawImageDescription;
  GifBitmap: TGIFPlayImage;
begin
  Result := False;
  if not FileExists(FFileName) and (FGifStream = nil) then
    exit;
  if not assigned(AGifList) then
    AGifList := TGIFPlayList.Create(True);

  if FGifStream <> nil then
    GifStream := FGifStream
  else
  begin
    GifStream := TMemoryStream.Create;
    GifStream.LoadFromFile(FFileName);
    GifStream.Position := 0;
  end;

  ReadHeader(GifStream);
  if (FGifHeader.Version <> '89a') then
    Exit;

  // 跳过第一个块扩展（如果存在）
  repeat
    Introducer := SkipBlock(GifStream);
  until (Introducer = ID_IMAGE_DESCRIPTOR) or (Introducer = ID_TRAILER);

  repeat
    ReadGifBitmap(GifStream);
    // 解码扫描线缓冲区中的Gif位图
    ReadScanLine(GifStream);
    // 为放置扫描线像素创建临时Fp图像
    FPImage := TLazIntfImage.Create(FLocalWidth, FLocalHeight);
    ImgFormatDescription.Init_BPP32_B8G8R8A8_BIO_TTB(FLocalWidth,
      FLocalHeight);
    FPImage.DataDescription := ImgFormatDescription;

    WriteScanLine(FPImage);

    GifBitmap := TGIFPlayImage.Create;
    GifBitmap.FBitmap.LoadFromIntfImage(FPImage);
    GifBitmap.FPosX := FGifDescriptor.Left;
    GifBitmap.FPosY := FGifDescriptor.Top;
    GifBitmap.FMethod := FDisposalMethod;
    GifBitmap.FDelay := FGifGraphicsCtrlExt.DelayTime;

    AGifList.Add(GifBitmap);

    FPImage.Free;
    FreeMem(FScanLine, FLineSize);
    FGifUseGraphCtrlExt := False;

    repeat
      Introducer := SkipBlock(GifStream);
    until (Introducer = ID_IMAGE_DESCRIPTOR) or (Introducer = ID_TRAILER);

  until (Introducer = ID_TRAILER);

  if FGifStream = nil then
    GifStream.Free;

  Result := True;

end;

function TGIFPlayLoader.LoadFromLazarusResource(const ResName: string; var AGifList: TGIFPlayList): boolean;
var
  GifStream: TLazarusResourceStream;
  Introducer: byte;
  FPImage: TLazIntfImage;
  ImgFormatDescription: TRawImageDescription;
  GifBitmap: TGIFPlayImage;
begin
  Result := False;
  if not assigned(AGifList) then
    AGifList := TGIFPlayList.Create(True);

  GifStream := TLazarusResourceStream.Create(ResName, nil);
  GifStream.Position := 0;

  ReadHeader(GifStream);
  if (FGifHeader.Version <> '89a') then
    Exit;

  // 跳过第一个块扩展（如果存在）
  repeat
    Introducer := SkipBlock(GifStream);
  until (Introducer = ID_IMAGE_DESCRIPTOR) or (Introducer = ID_TRAILER);

  repeat
    ReadGifBitmap(GifStream);
    // 解码扫描线缓冲区中的Gif位图
    ReadScanLine(GifStream);
    // 为放置扫描线像素创建临时Fp图像
    FPImage := TLazIntfImage.Create(FLocalWidth, FLocalHeight);
    ImgFormatDescription.Init_BPP32_B8G8R8A8_BIO_TTB(FLocalWidth,
      FLocalHeight);
    FPImage.DataDescription := ImgFormatDescription;

    WriteScanLine(FPImage);

    GifBitmap := TGIFPlayImage.Create;
    GifBitmap.FBitmap.LoadFromIntfImage(FPImage);
    GifBitmap.FPosX := FGifDescriptor.Left;
    GifBitmap.FPosY := FGifDescriptor.Top;
    GifBitmap.FMethod := FDisposalMethod;
    GifBitmap.FDelay := FGifGraphicsCtrlExt.DelayTime;

    AGifList.Add(GifBitmap);

    FPImage.Free;
    FreeMem(FScanLine, FLineSize);
    // 重置FGifUseGraphCtrlExt标志
    FGifUseGraphCtrlExt := False;

    repeat
      Introducer := SkipBlock(GifStream);
    until (Introducer = ID_IMAGE_DESCRIPTOR) or (Introducer = ID_TRAILER);

  until (Introducer = ID_TRAILER);
  GifStream.Free;
  Result := True;
end;

function TGIFPlayLoader.LoadFirstBitmap(var ABitmap: TBitmap): boolean;
var
  GifStream: TMemoryStream;
  Introducer: byte;
  FPImage: TLazIntfImage;
  ImgFormatDescription: TRawImageDescription;
begin
  Result := False;
  if not FileExists(FFileName) and (FGifStream = nil) then
    exit;
  if not assigned(ABitmap) then
    ABitmap := TBitmap.Create;

  if FGifStream <> nil then
    GifStream := FGifStream
  else
  begin
    GifStream := TMemoryStream.Create;
    GifStream.LoadFromFile(FFileName);
    GifStream.Position := 0;
  end;

  ReadHeader(GifStream);
  if (FGifHeader.Version <> '89a') then
    Exit;

  // 跳过第一个块扩展（如果存在）
  repeat
    Introducer := SkipBlock(GifStream);
  until (Introducer = ID_IMAGE_DESCRIPTOR) or (Introducer = ID_TRAILER);

  ReadGifBitmap(GifStream);
  // 解码扫描线缓冲区中的Gif位图
  ReadScanLine(GifStream);
  // 为放置扫描线像素创建临时Fp图像
  FPImage := TLazIntfImage.Create(FLocalWidth, FLocalHeight);
  ImgFormatDescription.Init_BPP32_B8G8R8A8_BIO_TTB(FLocalWidth, FLocalHeight);
  FPImage.DataDescription := ImgFormatDescription;

  WriteScanLine(FPImage);

  ABitmap.LoadFromIntfImage(FPImage);
  FPImage.Free;
  FreeMem(FScanLine, FLineSize);
  // 重置FGifUseGraphCtrlExt标志
  FGifUseGraphCtrlExt := False;

  // 不是 Stream 加载的释放掉
  if FGifStream = nil then
    GifStream.Free;
  Result := True;
end;

procedure TGIFPlayLoader.SetTransparent(const AValue: boolean);
begin
  if FIsTransparent = AValue then
    exit;
  FIsTransparent := AValue;
end;

function TGIFPlayLoader.SkipBlock(Stream: TStream): byte;
var
  Introducer, Labels, SkipByte: byte;
begin
  Introducer := 0;
  Labels := 0;
  SkipByte := 0;
  Stream.Read(Introducer, 1);
  if Introducer = EXT_INTRODUCER then
  begin
    Stream.Read(Labels, 1);
    case Labels of
      EXT_COMMENT,
      EXT_APPLICATION:
        while True do
        begin
          Stream.Read(SkipByte, 1);
          if SkipByte = 0 then
            Break;
          Stream.Seek(SkipByte, soFromCurrent);
        end;
      EXT_GRAPHICS_CONTROL:
      begin
        Stream.Read(FGifGraphicsCtrlExt, SizeOf(FGifGraphicsCtrlExt));
        FGifUseGraphCtrlExt := True;
      end;
      EXT_PLAIN_TEXT:
      begin
        Stream.Read(SkipByte, 1);
        Stream.Seek(SkipByte, soFromCurrent);
        while True do
        begin
          Stream.Read(SkipByte, 1);
          if SkipByte = 0 then
            Break;
          Stream.Seek(SkipByte, soFromCurrent);
        end;
      end;
    end;
  end;
  Result := Introducer;
end;

procedure TGIFPlayLoader.ReadScanLine(Stream: TStream);
var
  OldPos, UnpackedSize, PackedSize: longint;
  I: integer;
  Data, Bits, Code: cardinal;
  SourcePtr: pbyte;
  InCode: cardinal;

  CodeSize: cardinal;
  CodeMask: cardinal;
  FreeCode: cardinal;
  OldCode: cardinal;
  Prefix: array[0..CODE_TABLE_SIZE - 1] of cardinal;
  Suffix, Stack: array [0..CODE_TABLE_SIZE - 1] of byte;
  StackPointer: pbyte;
  DataComp, Target: pbyte;
  B, FInitialCodeSize, FirstChar: byte;
  ClearCode, EOICode: word;
begin
  FInitialCodeSize := 0;
  B := 0;
  DataComp := nil;

  // 解压缩字典的初始化
  Stream.Read(FInitialCodeSize, 1);

  // 压缩尾部
  OldPos := Stream.Position;
  PackedSize := 0;
  repeat
    Stream.Read(B, 1);
    if B > 0 then
    begin
      Inc(PackedSize, B);
      Stream.Seek(B, soFromCurrent);
    end;
  until B = 0;

  Getmem(DataComp, PackedSize);
  SourcePtr := DataComp;
  Stream.Position := OldPos;
  repeat
    Stream.Read(B, 1);
    if B > 0 then
    begin
      Stream.ReadBuffer(SourcePtr^, B);
      Inc(SourcePtr, B);
    end;
  until B = 0;

  SourcePtr := DataComp;
  Target := FScanLine;
  CodeSize := FInitialCodeSize + 1;
  ClearCode := 1 shl FInitialCodeSize;
  EOICode := ClearCode + 1;
  FreeCode := ClearCode + 2;
  OldCode := CODE_TABLE_SIZE;
  CodeMask := (1 shl CodeSize) - 1;
  UnpackedSize := FLocalWidth * FLocalHeight;
  for I := 0 to ClearCode - 1 do
  begin
    Prefix[I] := CODE_TABLE_SIZE;
    Suffix[I] := I;
  end;
  StackPointer := @Stack;
  FirstChar := 0;
  Data := 0;
  Bits := 0;
  //解压缩LZW gif
  while (UnpackedSize > 0) and (PackedSize > 0) do
  begin
    Inc(Data, SourcePtr^ shl Bits);
    Inc(Bits, 8);
    while Bits >= CodeSize do
    begin
      Code := Data and CodeMask;
      Data := Data shr CodeSize;
      Dec(Bits, CodeSize);
      if Code = EOICode then
        Break;
      if Code = ClearCode then
      begin
        CodeSize := FInitialCodeSize + 1;
        CodeMask := (1 shl CodeSize) - 1;
        FreeCode := ClearCode + 2;
        OldCode := CODE_TABLE_SIZE;
        Continue;
      end;
      if Code > FreeCode then
        Break;
      if OldCode = CODE_TABLE_SIZE then
      begin
        FirstChar := Suffix[Code];
        Target^ := FirstChar;
        Inc(Target);
        Dec(UnpackedSize);
        OldCode := Code;
        Continue;
      end;
      InCode := Code;
      if Code = FreeCode then
      begin
        StackPointer^ := FirstChar;
        Inc(StackPointer);
        Code := OldCode;
      end;
      while Code > ClearCode do
      begin
        StackPointer^ := Suffix[Code];
        Inc(StackPointer);
        Code := Prefix[Code];
      end;
      FirstChar := Suffix[Code];
      StackPointer^ := FirstChar;
      Inc(StackPointer);
      Prefix[FreeCode] := OldCode;
      Suffix[FreeCode] := FirstChar;
      if (FreeCode = CodeMask) and (CodeSize < 12) then
      begin
        Inc(CodeSize);
        CodeMask := (1 shl CodeSize) - 1;
      end;
      if FreeCode < CODE_TABLE_SIZE - 1 then
        Inc(FreeCode);
      OldCode := InCode;
      repeat
        Dec(StackPointer);
        Target^ := StackPointer^;
        Inc(Target);
        Dec(UnpackedSize);
      until StackPointer = @Stack;
    end;
    Inc(SourcePtr);
    Dec(PackedSize);
  end;
  FreeMem(DataComp);
end;

procedure TGIFPlayLoader.ReadHeader(Stream: TStream);
begin
  Stream.Read(FGifHeader, SizeOf(FGifHeader));

  with FGifHeader do
  begin
    FGifBackgroundColor := BackgroundColor;

    FWidth := ScreenWidth;
    FHeight := ScreenHeight;

    FLocalWidth := ScreenWidth;
    FLocalHeight := ScreenHeight;

    IsTransparent := False;
  end;
  ReadGlobalPalette(Stream);
end;

procedure TGIFPlayLoader.ReadGlobalPalette(Stream: TStream);
var
  ColorTableSize: integer;
begin
  if (FGifHeader.Packedbit and ID_COLOR_TABLE) <> 0 then
  begin
    ColorTableSize := FGifHeader.Packedbit and ID_COLOR_TABLE_SIZE + 1;
    ReadPalette(Stream, 1 shl ColorTableSize);
  end;
end;

procedure TGIFPlayLoader.ReadGraphCtrlExt;
var
  C: TFPColor;
begin
  IsTransparent := (FGifGraphicsCtrlExt.Packedbit and ID_TRANSPARENT) <> 0;

  FDisposalMethod := (FGifGraphicsCtrlExt.Packedbit and $1C) shr 2;

  if IsTransparent then
  begin
    // 如果透明位图更改alpha通道
    FGifBackgroundColor := FGifGraphicsCtrlExt.ColorIndex;
    C := FPalette[FGifBackgroundColor];
    C.alpha := alphaTransparent;
    FPalette[FGifBackgroundColor] := C;
  end;
end;

procedure TGIFPlayLoader.SetInterlaced(const AValue: boolean);
begin
  if FInterlaced = AValue then
    exit;
  FInterlaced := AValue;
end;

procedure TGIFPlayLoader.ReadPalette(Stream: TStream; Size: integer);
var
  RGBEntry: TRGB;
  I: integer;
  C: TFPColor;
begin
  FPalette.Clear;
  FPalette.Count := 0;
  Fillchar(RGBEntry, SizeOf(RGBEntry), 0);
  for I := 0 to Size - 1 do
  begin
    Stream.Read(RGBEntry, SizeOf(RGBEntry));
    with C do
    begin
      Red := RGBEntry.Red or (RGBEntry.Red shl 8);
      Green := RGBEntry.Green or (RGBEntry.Green shl 8);
      Blue := RGBEntry.Blue or (RGBEntry.Blue shl 8);
      Alpha := alphaOpaque;
    end;
    FPalette.Add(C);
  end;
end;

procedure TGIFPlayLoader.WriteScanLine(Img: TFPCustomImage);
var
  Row, Col: integer;
  Pass, Every: byte;
  P: pbyte;
begin
  P := FScanLine;
  if Interlaced then
  begin
    for Pass := 1 to 4 do
    begin
      case Pass of
        1:
        begin
          Row := 0;
          Every := 8;
        end;
        2:
        begin
          Row := 4;
          Every := 8;
        end;
        3:
        begin
          Row := 2;
          Every := 4;
        end;
        4:
        begin
          Row := 1;
          Every := 2;
        end;
      end;
      repeat
        for Col := 0 to FLocalWidth - 1 do
        begin
          Img.Colors[Col, Row] := FPalette[P^];
          Inc(P);
        end;
        Inc(Row, Every);
      until Row >= FLocalHeight;
    end;
  end
  else
  begin
    for Row := 0 to FLocalHeight - 1 do
      for Col := 0 to FLocalWidth - 1 do
      begin
        Img.Colors[Col, Row] := FPalette[P^];
        Inc(P);
      end;
  end;
end;

procedure TGIFPlayLoader.ReadGifBitmap(Stream: TStream);
var
  ColorTableSize: integer;
begin
  Stream.Read(FGifDescriptor, SizeOf(FGifDescriptor));

  with FGifDescriptor do
  begin
    FLocalWidth := Width;
    FLocalHeight := Height;
    Interlaced := (Packedbit and ID_INTERLACED = ID_INTERLACED);
  end;

  FLineSize := FLocalWidth * (FLocalHeight + 1);
  GetMem(FScanLine, FLineSize);

  if (FGifDescriptor.Packedbit and ID_COLOR_TABLE) <> 0 then
  begin
    ColorTableSize := FGifDescriptor.Packedbit and ID_COLOR_TABLE_SIZE + 1;
    ReadPalette(Stream, 1 shl ColorTableSize);
  end;
  if FGifUseGraphCtrlExt then
    ReadGraphCtrlExt;

end;

{ TGIFPlayImage }

constructor TGIFPlayImage.Create;
begin
  FBitmap := TBitmap.Create;
  FPosX := 0;
  FPosY := 0;
  FDelay := 0;
  FMethod := 0;
end;

destructor TGIFPlayImage.Destroy;
begin
  inherited Destroy;
  FBitmap.Free;
end;

{ TGIFPlayList }

function TGIFPlayList.GetItems(Index: integer): TGIFPlayImage;
begin
  Result := TGIFPlayImage(inherited Items[Index]);
end;

procedure TGIFPlayList.SetItems(Index: integer; AGifImage: TGIFPlayImage);
begin
  Put(Index, AGifImage);
end;

function TGIFPlayList.Add(AGifImage: TGIFPlayImage): integer;
begin
  Result := inherited Add(AGifImage);
end;

function TGIFPlayList.Extract(Item: TGIFPlayImage): TGIFPlayImage;
begin
  Result := TGIFPlayImage(inherited Extract(Item));
end;

function TGIFPlayList.Remove(AGifImage: TGIFPlayImage): integer;
begin
  Result := inherited Remove(AGifImage);
end;

function TGIFPlayList.IndexOf(AGifImage: TGIFPlayImage): integer;
begin
  Result := inherited IndexOf(AGifImage);
end;

function TGIFPlayList.First: TGIFPlayImage;
begin
  Result := TGIFPlayImage(inherited First);
end;

function TGIFPlayList.Last: TGIFPlayImage;
begin
  Result := TGIFPlayImage(inherited Last);
end;

procedure TGIFPlayList.Insert(Index: integer; AGifImage: TGIFPlayImage);
begin
  inherited Insert(Index, AGifImage);
end;

end.
