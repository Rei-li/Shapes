#pragma once

#include "ShapeBase.h"
#include "CanvasPoint.h"

class Circle : public Shape {

public:
	long double GetArea();
	long double GetPerimeter();
	CanvasPoint GetCenter();

	void SetCenter();
	void Rotate();
	void Scale();

};
