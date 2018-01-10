#include "CanvasPoint.h"

int CanvasPoint::GetX() {
	return X;
}

int CanvasPoint::GetY() {
	return Y;
}

float CanvasPoint::GetAngle() {
	return _angle;
}

void CanvasPoint::SetX(int x) {
	X = x;

}

void CanvasPoint::SetY(int y) {
	Y = y;
}

void CanvasPoint::SetAngle(float angle) {
	_angle = angle;
}
