// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Point.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int Point::GetX() {
	return X;
}

int Point::GetY() {
	return Y;
}

float Point::GetAngle(){
	   return _angle;
}

void Point::SetX(int x) {
	X = x;

}

void Point::SetY(int y) {
	Y = y;
}

void Point::SetAngle(float angle) {
	_angle = angle;
}
