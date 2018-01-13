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
	TRadioGroup *Actions;
	TRadioButton *EditBtn;
	TRadioButton *SelectBtn;
	TButton *GetAreaBtn;
	TButton *GetPerimeterBtn;
	TButton *GetCenterBtn;
	TButton *ClearCanvasBtn;
	TButton *Button5;
	TButton *Button6;
	TLabel *ResultLb;
	TCheckBox *EditModeChb;
	void __fastcall EditorMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall EditorDblClick(TObject *Sender);
	void __fastcall GetAreaBtnClick(TObject *Sender);
	void __fastcall ClearCanvasBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
