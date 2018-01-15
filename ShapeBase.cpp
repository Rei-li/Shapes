#include "ShapeBase.h"
#include <cmath>
#include <vector>
// using namespace std;

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

//void Shape::Rotate(int x, int y) {
//	long double PI = 3.14159265;
//	long double angleRadian = 90 * PI / 180;
//
//	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
//		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
//		int currentX = currentCanvasPoint.GetX();
//		int currentY = currentCanvasPoint.GetY();
//
//		long double X =
//			(long double)((currentCanvasPoint.GetX() - x) * std::cos
//			(angleRadian) - (currentCanvasPoint.GetY() - y) * std::sin
//			(angleRadian) + x);
//		long double Y =
//			(long double)((currentCanvasPoint.GetX() - x) * std::sin
//			(angleRadian) + (currentCanvasPoint.GetY() - y) * std::cos
//			(angleRadian) + y);
//
//		currentCanvasPoint.SetX(X);
//		currentCanvasPoint.SetY(Y);
//
//	}
//
//}

//void Shape::Scale(int times) {
//	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
//		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
//		int currentX = currentCanvasPoint.GetX();
//		int currentY = currentCanvasPoint.GetY();
//		currentCanvasPoint.SetX(currentX / times);
//		currentCanvasPoint.SetY(currentY / times);
//	}
//
//}

//void Shape::Move(int xStart, int yStart, int xEnd, int yEnd) {
//
//std::vector<CanvasPoint>CurrentPivotCanvasPoints = PivotCanvasPoints;
//	std::vector<Shape> shapeStates;
//
//	while(xStart != xEnd && yStart != yEnd){
//				Shape shape;
//
//	}
//
//
//
//
// ClearPivotPoints();
//
//	for (int i = 0; i < PivotCanvasPoints.size(); i++) {
//		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
//		int currentX = currentCanvasPoint.GetX();
//		int currentY = currentCanvasPoint.GetY();
//
//		AddPivotCanvasPoint(currentX + (xStart - xEnd), currentY + (yStart - yEnd));
//	}
//	CurrentPivotCanvasPoints.clear();
//}

void Shape::SetCenter(int x, int y) {
	std::vector<CanvasPoint>CurrentPivotCanvasPoints = PivotCanvasPoints;
	CanvasPoint centerCanvasPoint = GetCenter();
	int centerX = centerCanvasPoint.GetX();
	int centerY = centerCanvasPoint.GetY();
	ClearPivotPoints();
	for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = PivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();

		AddPivotCanvasPoint(currentX + (x - centerX), currentY + (y - centerY));

	}
	CurrentPivotCanvasPoints.clear();
}
