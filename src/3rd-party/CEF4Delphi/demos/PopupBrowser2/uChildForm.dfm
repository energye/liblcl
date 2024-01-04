object ChildForm: TChildForm
  Left = 1772
  Height = 256
  Top = 454
  Width = 352
  Caption = 'Popup'
  ClientHeight = 256
  ClientWidth = 352
  Color = clBtnFace
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  Position = poScreenCenter
  LCLVersion = '3.0.0.3'
  object CEFWindowParent1: TCEFWindowParent
    Left = 0
    Height = 256
    Top = 0
    Width = 352
    Align = alClient
    TabOrder = 0
  end
  object Chromium1: TChromium
    OnTitleChange = Chromium1TitleChange
    OnBeforePopup = Chromium1BeforePopup
    OnBeforeClose = Chromium1BeforeClose
    OnClose = Chromium1Close
    Left = 24
    Top = 56
  end
end
