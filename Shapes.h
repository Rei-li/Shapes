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
	TRadioButton *Plygon;
	TRadioButton *Circle;
	TPanel *EditorPanel;
	TImage *Editor;
	TRadioGroup *Actions;
	TRadioButton *EditBtn;
	TRadioButton *SelectBtn;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
