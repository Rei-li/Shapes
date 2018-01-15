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
  object AreaResultLb: TLabel
    Left = 979
    Top = 245
    Width = 3
    Height = 13
  end
  object PerimeterResultLb: TLabel
    Left = 979
    Top = 293
    Width = 3
    Height = 13
  end
  object Label1: TLabel
    Left = 960
    Top = 341
    Width = 13
    Height = 13
    Caption = 'X: '
  end
  object Label2: TLabel
    Left = 987
    Top = 349
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 1024
    Top = 341
    Width = 13
    Height = 13
    Caption = 'Y: '
  end
  object CenterXLb: TLabel
    Left = 979
    Top = 341
    Width = 3
    Height = 13
  end
  object CenterYLb: TLabel
    Left = 1043
    Top = 341
    Width = 3
    Height = 13
  end
  object Label4: TLabel
    Left = 876
    Top = 397
    Width = 13
    Height = 13
    Caption = 'X: '
  end
  object Label5: TLabel
    Left = 987
    Top = 397
    Width = 13
    Height = 13
    Caption = 'Y: '
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
      OnMouseUp = EditorMouseUp
    end
  end
  object GetAreaBtn: TButton
    Left = 872
    Top = 240
    Width = 75
    Height = 25
    Caption = #1055#1083#1086#1097#1072#1076#1100
    TabOrder = 4
    OnClick = GetAreaBtnClick
  end
  object GetPerimeterBtn: TButton
    Left = 872
    Top = 288
    Width = 75
    Height = 25
    Caption = #1055#1077#1088#1080#1084#1077#1090#1088
    TabOrder = 5
    OnClick = GetPerimeterBtnClick
  end
  object GetCenterBtn: TButton
    Left = 872
    Top = 336
    Width = 75
    Height = 25
    Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089
    TabOrder = 6
    OnClick = GetCenterBtnClick
  end
  object ClearCanvasBtn: TButton
    Left = 872
    Top = 648
    Width = 209
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1093#1086#1083#1089#1090
    TabOrder = 7
    OnClick = ClearCanvasBtnClick
  end
  object TriangulationCheckBtn: TButton
    Left = 872
    Top = 696
    Width = 209
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1090#1088#1080#1072#1085#1075#1091#1083#1103#1094#1080#1102
    TabOrder = 8
    OnClick = TriangulationCheckBtnClick
  end
  object CenterChangeBtn: TButton
    Left = 872
    Top = 421
    Width = 209
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1094#1077#1085#1090#1088
    TabOrder = 9
    OnClick = CenterChangeBtnClick
  end
  object EditModeChb: TCheckBox
    Left = 880
    Top = 16
    Width = 201
    Height = 25
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 10
    OnClick = EditModeChbClick
  end
  object CenterXInput: TEdit
    Left = 895
    Top = 394
    Width = 78
    Height = 21
    TabOrder = 11
  end
  object CenterYInput: TEdit
    Left = 1006
    Top = 394
    Width = 75
    Height = 21
    TabOrder = 12
  end
  object RotateBtn: TButton
    Left = 872
    Top = 480
    Width = 209
    Height = 25
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1100' '#1085#1072' 90'
    TabOrder = 13
    OnClick = RotateBtnClick
  end
  object MoveBtn: TButton
    Left = 872
    Top = 528
    Width = 209
    Height = 25
    Caption = #1055#1077#1088#1077#1076#1074#1080#1085#1091#1090#1100
    TabOrder = 14
    OnClick = MoveBtnClick
  end
  object ScaleDownBtn: TButton
    Left = 932
    Top = 592
    Width = 41
    Height = 25
    Caption = '-'
    TabOrder = 15
    OnClick = ScaleDownBtnClick
  end
  object ScaleUpBtn: TButton
    Left = 979
    Top = 592
    Width = 38
    Height = 25
    Caption = '+'
    TabOrder = 16
  end
  object MoveTmr: TTimer
    Enabled = False
    Interval = 1
    OnTimer = MoveTmrTimer
    Left = 912
    Top = 752
  end
  object RotateTmr: TTimer
    Left = 976
    Top = 752
  end
  object ScaleTmr: TTimer
    Left = 1040
    Top = 752
  end
end
