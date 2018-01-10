#pragma once

#include <vector>
#include "CanvasPoint.h"

class Shape {

public:

	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;

	virtual CanvasPoint GetCenter();

	void SetCenter(int x, int y);
	void Move(int xStart, int yStart, int xEnd, int yEnd);
	void Rotate(int x, int y);
	void Scale(int distance);

	void AddPivotCanvasPoint(int x, int y);
	std::vector<CanvasPoint>PivotCanvasPoints;

};
