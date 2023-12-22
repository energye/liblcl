object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Simple OSR Browser - Initializing browser. Please wait...'
  ClientHeight = 530
  ClientWidth = 800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnAfterMonitorDpiChanged = FormAfterMonitorDpiChanged
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object NavControlPnl: TPanel
    Left = 0
    Top = 0
    Width = 800
    Height = 30
    Align = alTop
    BevelOuter = bvNone
    Enabled = False
    Padding.Left = 5
    Padding.Top = 5
    Padding.Right = 5
    Padding.Bottom = 5
    ShowCaption = False
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 5
      Top = 5
      Width = 721
      Height = 21
      Align = alClient
      ItemIndex = 0
      TabOrder = 0
      Text = 'https://www.google.com'
      OnEnter = ComboBox1Enter
      Items.Strings = (
        'https://www.google.com'
        'https://html5demos.com/drag'
        
          'https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_selec' +
          't_form'
        'https://www.briskbard.com'
        'https://frames-per-second.appspot.com/')
    end
    object Panel2: TPanel
      Left = 726
      Top = 5
      Width = 69
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alRight
      BevelOuter = bvNone
      Padding.Left = 4
      ShowCaption = False
      TabOrder = 1
      object GoBtn: TButton
        Left = 4
        Top = 0
        Width = 31
        Height = 20
        Margins.Left = 5
        Align = alLeft
        Caption = 'Go'
        TabOrder = 0
        OnClick = GoBtnClick
        OnEnter = GoBtnEnter
      end
      object SnapshotBtn: TButton
        Left = 38
        Top = 0
        Width = 31
        Height = 20
        Hint = 'Take snapshot'
        Margins.Left = 5
        Align = alRight
        Caption = #181
        Font.Charset = SYMBOL_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Webdings'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = SnapshotBtnClick
        OnEnter = SnapshotBtnEnter
      end
    end
  end
  object Panel1: TBufferPanel
    Left = 0
    Top = 30
    Width = 800
    Height = 500
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 1
    TabStop = True
    OnClick = Panel1Click
    OnEnter = Panel1Enter
    OnExit = Panel1Exit
    OnMouseDown = Panel1MouseDown
    OnMouseMove = Panel1MouseMove
    OnMouseUp = Panel1MouseUp
    OnResize = Panel1Resize
    OnMouseLeave = Panel1MouseLeave
  end
  object chrmosr: TChromium
    OnTooltip = chrmosrTooltip
    OnBeforePopup = chrmosrBeforePopup
    OnAfterCreated = chrmosrAfterCreated
    OnBeforeClose = chrmosrBeforeClose
    OnGetViewRect = chrmosrGetViewRect
    OnGetScreenPoint = chrmosrGetScreenPoint
    OnGetScreenInfo = chrmosrGetScreenInfo
    OnPopupShow = chrmosrPopupShow
    OnPopupSize = chrmosrPopupSize
    OnPaint = chrmosrPaint
    OnCursorChange = chrmosrCursorChange
    Left = 24
    Top = 56
  end
  object AppEvents: TApplicationEvents
    OnMessage = AppEventsMessage
    Left = 24
    Top = 128
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'bmp'
    Filter = 'Bitmap files (*.bmp)|*.BMP'
    Title = 'Save snapshot'
    Left = 24
    Top = 278
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 300
    OnTimer = Timer1Timer
    Left = 24
    Top = 206
  end
end
