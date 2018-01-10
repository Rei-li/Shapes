#pragma once

#include "ShapeBase.h"
#include "CanvasPoint.h"

class Circle : public Shape {

public:
	float GetArea();
	float GetPerimeter();
	CanvasPoint GetCenter();

	void SetCenter();
	void Rotate();
	void Scale();

};
