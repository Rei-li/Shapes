object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1092#1080#1095#1077#1089#1082#1080#1081' '#1088#1077#1076#1072#1082#1090#1086#1088
  ClientHeight = 836
  ClientWidth = 1112
  Color = clMenuBar
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ResultLb: TLabel
    Left = 976
    Top = 445
    Width = 3
    Height = 13
  end
  object ShapesRadioGroup: TRadioGroup
    Left = 872
    Top = 64
    Width = 209
    Height = 145
    Caption = #1060#1080#1075#1091#1088#1099
    TabOrder = 0
  end
  object PlygonBtn: TRadioButton
    Left = 904
    Top = 112
    Width = 113
    Height = 17
    Caption = #1052#1085#1086#1075#1086#1091#1075#1086#1083#1100#1085#1080#1082
    TabOrder = 1
  end
  object Circle: TRadioButton
    Left = 904
    Top = 160
    Width = 113
    Height = 17
    Caption = #1050#1088#1091#1075
    TabOrder = 2
  end
  object EditorPanel: TPanel
    Left = 8
    Top = 8
    Width = 841
    Height = 820
    Color = clCream
    ParentBackground = False
    TabOrder = 3
    object Editor: TImage
      Left = 0
      Top = 0
      Width = 841
      Height = 825
      OnDblClick = EditorDblClick
      OnMouseDown = EditorMouseDown
    end
  end
  object Actions: TRadioGroup
    Left = 872
    Top = 248
    Width = 209
    Height = 153
    Caption = #1044#1077#1081#1089#1090#1074#1080#1103
    TabOrder = 4
  end
  object EditBtn: TRadioButton
    Left = 904
    Top = 296
    Width = 113
    Height = 17
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 5
  end
  object SelectBtn: TRadioButton
    Left = 904
    Top = 344
    Width = 113
    Height = 17
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 6
  end
  object GetAreaBtn: TButton
    Left = 872
    Top = 440
    Width = 75
    Height = 25
    Caption = #1055#1083#1086#1097#1072#1076#1100
    TabOrder = 7
    OnClick = GetAreaBtnClick
  end
  object GetPerimeterBtn: TButton
    Left = 872
    Top = 488
    Width = 75
    Height = 25
    Caption = #1055#1077#1088#1080#1084#1077#1090#1088
    TabOrder = 8
  end
  object GetCenterBtn: TButton
    Left = 872
    Top = 536
    Width = 75
    Height = 25
    Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089
    TabOrder = 9
  end
  object ClearCanvasBtn: TButton
    Left = 872
    Top = 584
    Width = 107
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1093#1086#1083#1089#1090
    TabOrder = 10
    OnClick = ClearCanvasBtnClick
  end
  object Button5: TButton
    Left = 872
    Top = 632
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 11
  end
  object Button6: TButton
    Left = 872
    Top = 680
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 12
  end
  object EditModeChb: TCheckBox
    Left = 880
    Top = 16
    Width = 201
    Height = 25
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 13
  end
end
