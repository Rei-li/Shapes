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
		Editor->Canvas->Pixels[X][Y] = clBlack;
		EditorService::AddCanvasPointToPolygon(X, Y);
	}

	if (!EditModeChb->Checked) {
		EditorService::SetStartMovePoint(X, Y);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::EditorDblClick(TObject *Sender) {
	// EditModeChb->Checked = False;

	// Logger::WriteInfo("Height: " + std::to_string(Screen->Height) +
	// "; Width: " + std::to_string(Screen->Width));
	//
	// if (PlygonBtn->Checked) {
	//
	// std::vector<CanvasPoint>points =
	// EditorService::GetPivotCanvasPointsFromPolygon();
	//
	// for (unsigned int counter = 0; counter < points.size(); counter++) {
	// Logger::WriteInfo("X: " + std::to_string(points[counter].GetX()) +
	// "; Y: " + std::to_string(points[counter].GetY()));
	// }
	//
	// Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
	// for (int i = 1; i < points.size(); i++) {
	// Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
	// }
	// Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());
	//
	// for (unsigned int counter = 0; counter < points.size(); counter++) {
	// Logger::WriteInfo("X: " + std::to_string(points[counter].GetX()) +
	// "; Y: " + std::to_string(points[counter].GetY()));
	// }
	// }

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::GetAreaBtnClick(TObject *Sender) {

	class Polygon polygon = EditorService::GetPolygon();
	double area = polygon.GetArea();
	AreaResultLb->Caption = String(area / EditorService::GetDpcm());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ClearCanvasBtnClick(TObject *Sender) {
	EditorService::ClearPlygonPoints();

	Editor->Canvas->Brush->Color = clCream;
	Editor->Canvas->FillRect(Rect(0, 0, Editor->Width, Editor->Height));
	Editor->Canvas->Brush->Color = clBlack;

	CenterXLb->Caption = String();
	CenterYLb->Caption = String();
	PerimeterResultLb->Caption = String();
	AreaResultLb->Caption = String();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::GetPerimeterBtnClick(TObject *Sender) {
	class Polygon polygon = EditorService::GetPolygon();
	double p = polygon.GetPerimeter();
	PerimeterResultLb->Caption = String(p / EditorService::GetDpcm());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::GetCenterBtnClick(TObject *Sender) {
	class Polygon polygon = EditorService::GetPolygon();
	CanvasPoint center = polygon.GetCenter();
	int x = center.GetX();
	int y = center.GetY();
	Editor->Canvas->Pixels[x][y] = clBlack;
	CenterXLb->Caption = String(x);
	CenterYLb->Caption = String(y);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::TriangulationCheckBtnClick(TObject *Sender) {
	class Polygon polygon = EditorService::GetPolygon();
	std::vector<class Polygon>triagles = polygon.TriangulationCheck();

	for (int counter = 0; counter < triagles.size(); counter++) {
		std::vector<CanvasPoint>points = triagles[counter].PivotCanvasPoints;

		Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
		for (int i = 1; i < points.size(); i++) {
			Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
		}
		Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::CenterChangeBtnClick(TObject *Sender) {

	class Polygon polygon = EditorService::GetPolygon();
	std::string x(AnsiString(CenterXInput->Text).c_str());
	std::string y(AnsiString(CenterYInput->Text).c_str());

	if (x != "" && y != "") {
		int X = stoi(x);
		int Y = stoi(y);

		EditorService::SetPolygonCenter(X, Y);

		Editor->Canvas->Brush->Color = clCream;
		Editor->Canvas->FillRect(Rect(0, 0, Editor->Width, Editor->Height));
		Editor->Canvas->Brush->Color = clBlack;

		class Polygon polygonEdited = EditorService::GetPolygon();
		std::vector<CanvasPoint>points = polygonEdited.PivotCanvasPoints;

		Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
		for (int i = 1; i < points.size(); i++) {
			Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
		}
		Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());
	}

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::EditorMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	if (!EditModeChb->Checked && (X != EditorService::GetEndMovePointX()
		&& Y != EditorService::GetEndMovePointY())) {

		Logger::WriteInfo("X: " + std::to_string(EditorService::GetEndMovePointX
			()) + "; Y: " + std::to_string(EditorService::GetEndMovePointY()));

		EditorService::SetEndMovePoint(X, Y);
		EditorService::MovePolygon();
		MoveTmr->Enabled = True;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MoveTmrTimer(TObject *Sender) {

	if (PlygonBtn->Checked) {
		std::vector<class Polygon>polygons = EditorService::GetPolygonStates();
		int index = EditorService::GetStatesIndex();

		if (polygons.size() > index) {
			class Polygon currentPolygon = polygons[index];
			std::vector<CanvasPoint>points = currentPolygon.PivotCanvasPoints;
			Editor->Canvas->Brush->Color = clCream;
			Editor->Canvas->FillRect(Rect(0, 0, Editor->Width, Editor->Height));
			Editor->Canvas->Brush->Color = clBlack;

			Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
			for (int i = 1; i < points.size(); i++) {
				Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
			}
			Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());

			EditorService::SetStatesIndex(index + 1);
		}
		else {
			EditorService::ClearMoveElements();
			MoveTmr->Enabled = False;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::EditModeChbClick(TObject *Sender) {

	if (!EditModeChb->Checked) {

		Logger::WriteInfo("Height: " + std::to_string(Screen->Height) +
			"; Width: " + std::to_string(Screen->Width));

		if (PlygonBtn->Checked) {

			std::vector<CanvasPoint>points =
				EditorService::GetPivotCanvasPointsFromPolygon();

			for (unsigned int counter = 0; counter < points.size(); counter++) {
				Logger::WriteInfo("X: " + std::to_string(points[counter].GetX())
					+ "; Y: " + std::to_string(points[counter].GetY()));
			}

			Editor->Canvas->MoveTo(points[0].GetX(), points[0].GetY());
			for (int i = 1; i < points.size(); i++) {
				Editor->Canvas->LineTo(points[i].GetX(), points[i].GetY());
			}
			Editor->Canvas->LineTo(points[0].GetX(), points[0].GetY());

			for (unsigned int counter = 0; counter < points.size(); counter++) {
				Logger::WriteInfo("X: " + std::to_string(points[counter].GetX())
					+ "; Y: " + std::to_string(points[counter].GetY()));
			}
		}
	}
}
// ---------------------------------------------------------------------------
