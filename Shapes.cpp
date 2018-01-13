// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Shapes.h"
#include "Logger.h"
#include "EditorService.h"
#include <string>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	const int dpcm = GetDeviceCaps(Editor->Canvas->Handle, LOGPIXELSX) / 2.54;
	EditorService::SetDpcm(dpcm);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EditorMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	if (PlygonBtn->Checked && EditModeChb->Checked) {
		EditorService::AddCanvasPointToPolygon(X, Y);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::EditorDblClick(TObject *Sender) {
	EditModeChb->Checked = False;

	Screen->Height;
	Screen->Width;
	Logger::WriteInfo("Height: " + std::to_string(Screen->Height) +
		"; Width: " + std::to_string(Screen->Width));

	if (PlygonBtn->Checked) {

		std::vector<CanvasPoint>points =
			EditorService::GetPivotCanvasPointsFromPolygon();

		for (unsigned int counter = 0; counter < points.size(); counter++) {
			Logger::WriteInfo("X: " + std::to_string(points[counter].GetX()) +
				"; Y: " + std::to_string(points[counter].GetY()));
		}

		Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
		for (int i = 1; i < points.size(); i++) {
			Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
		}
		Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());

		EditorService::ClearPlygonPoints();

		for (unsigned int counter = 0; counter < points.size(); counter++) {
			Logger::WriteInfo("X: " + std::to_string(points[counter].GetX()) +
				"; Y: " + std::to_string(points[counter].GetY()));
		}
	}

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::GetAreaBtnClick(TObject *Sender) {

	class Polygon polygon = EditorService::GetPolygon();
	float area = polygon.GetArea();
	ResultLb->Caption = String(area);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ClearCanvasBtnClick(TObject *Sender) {
	Editor->Canvas->CleanupInstance();
}
// ---------------------------------------------------------------------------
