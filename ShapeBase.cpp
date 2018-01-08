// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeBase.h"
#include <cmath>
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

void Shape::Rotate(int x, int y) {
	float PI = 3.14159265;
	float angleRadian = 90 * PI / 180;

	for (int i = 0; i < PivotPoints.size(); i++) {
		Point currentPoint = PivotPoints[i];
		int currentX = currentPoint.GetX();
		int currentY = currentPoint.GetY();

		float X = (float)((currentPoint.GetX() - x) * cos(angleRadian) -
			(currentPoint.GetY() - y) * sin(angleRadian) + x);
		float Y = (float)((currentPoint.GetX() - x) * sin(angleRadian) +
			(currentPoint.GetY() - y) * cos(angleRadian) + y);

		currentPoint.SetX(X);
		currentPoint.SetY(Y);

	}

}

void Shape::Scale(int times) {
	for (int i = 0; i < PivotPoints.size(); i++) {
		Point currentPoint = PivotPoints[i];
		int currentX = currentPoint.GetX();
		int currentY = currentPoint.GetY();
		currentPoint.SetX(currentX / times);
		currentPoint.SetY(currentY / times);
	}

}

void Shape::Move(int xStart, int yStart, int xEnd, int yEnd) {
	for (int i = 0; i < PivotPoints.size(); i++) {
		Point currentPoint = PivotPoints[i];
		int currentX = currentPoint.GetX();
		int currentY = currentPoint.GetY();
		currentPoint.SetX(currentX + (xStart - xEnd));
		currentPoint.SetY(currentY + (yStart - yEnd));
	}
}

void Shape::SetCenter(int x, int y) {
	for (int i = 0; i < PivotPoints.size(); i++) {
		Point currentPoint = PivotPoints[i];
		int currentX = currentPoint.GetX();
		int currentY = currentPoint.GetY();

		Point centerPoint = GetCenter();
		int centerX = centerPoint.GetX();
		int centerY = centerPoint.GetY();

		currentPoint.SetX(currentX + (x - centerX));
		currentPoint.SetY(currentY + (y - centerY));
	}
}
