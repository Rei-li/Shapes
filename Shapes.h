//---------------------------------------------------------------------------

#ifndef ShapesH
#define ShapesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//#include "EditorService.h"
//#include "Polygon.h"
//#include "Circle.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *ShapesRadioGroup;
	TRadioButton *PlygonBtn;
	TRadioButton *Circle;
	TPanel *EditorPanel;
	TImage *Editor;
	TButton *GetAreaBtn;
	TButton *GetPerimeterBtn;
	TButton *GetCenterBtn;
	TButton *ClearCanvasBtn;
	TButton *TriangulationCheckBtn;
	TButton *CenterChangeBtn;
	TLabel *AreaResultLb;
	TCheckBox *EditModeChb;
	TLabel *PerimeterResultLb;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *CenterXLb;
	TLabel *CenterYLb;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *CenterXInput;
	TEdit *CenterYInput;
	TTimer *MoveTmr;
	TTimer *RotateTmr;
	TTimer *ScaleTmr;
	void __fastcall EditorMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall EditorDblClick(TObject *Sender);
	void __fastcall GetAreaBtnClick(TObject *Sender);
	void __fastcall ClearCanvasBtnClick(TObject *Sender);
	void __fastcall GetPerimeterBtnClick(TObject *Sender);
	void __fastcall GetCenterBtnClick(TObject *Sender);
	void __fastcall TriangulationCheckBtnClick(TObject *Sender);
	void __fastcall CenterChangeBtnClick(TObject *Sender);
	void __fastcall EditorMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall MoveTmrTimer(TObject *Sender);
	void __fastcall EditModeChbClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
