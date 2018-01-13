#include "ShapeBase.h"
#include <cmath>
#include <vector>
// using namespace std;

void Shape::SetDpcm(int dpcm) {
	_dpcm = dpcm;
}

void Shape::ClearPivotPoints() {
	PivotCanvasPoints.clear();
}

void Shape::AddPivotCanvasPoint(int x, int y) {
	CanvasPoint CanvasPoint;
	CanvasPoint.SetX(x);
	CanvasPoint.SetY(y);

	PivotCanvasPoints.push_back(CanvasPoint);
}

CanvasPoint Shape::GetCenter() {
	return CanvasPoint();
}

void Shape::Rotate(int x, int y) {
	float PI = 3.14159265;
	float angleRadian = 90 * PI / 180;

	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();

		float X = (float)((currentCanvasPoint.GetX() - x) * std::cos
			(angleRadian) - (currentCanvasPoint.GetY() - y) * std::sin
			(angleRadian) + x);
		float Y = (float)((currentCanvasPoint.GetX() - x) * std::sin
			(angleRadian) + (currentCanvasPoint.GetY() - y) * std::cos
			(angleRadian) + y);

		currentCanvasPoint.SetX(X);
		currentCanvasPoint.SetY(Y);

	}

}

void Shape::Scale(int times) {
	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();
		currentCanvasPoint.SetX(currentX / times);
		currentCanvasPoint.SetY(currentY / times);
	}

}

void Shape::Move(int xStart, int yStart, int xEnd, int yEnd) {
	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();
		currentCanvasPoint.SetX(currentX + (xStart - xEnd));
		currentCanvasPoint.SetY(currentY + (yStart - yEnd));
	}
}

void Shape::SetCenter(int x, int y) {
	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();

		CanvasPoint centerCanvasPoint = GetCenter();
		int centerX = centerCanvasPoint.GetX();
		int centerY = centerCanvasPoint.GetY();

		currentCanvasPoint.SetX(currentX + (x - centerX));
		currentCanvasPoint.SetY(currentY + (y - centerY));
	}
}
