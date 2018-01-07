// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeBase.h"
#include <vector>

// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

void Shape::AddPivotPoint(int x, int y) {
	Point point;
	point.SetX(x);
	point.SetY(y);

	PivotPoints.push_back(point);
}
