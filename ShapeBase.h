#pragma once

#include <vector>
#include "CanvasPoint.h"

class Shape {

public:

	virtual long double GetArea() = 0;
	virtual long double GetPerimeter() = 0;

	virtual CanvasPoint GetCenter();

	void SetCenter(int x, int y);
//	void Move(int xStart, int yStart, int xEnd, int yEnd);
	void Rotate(int x, int y);
	void Scale(int distance);

	void ClearPivotPoints();

	void AddPivotCanvasPoint(int x, int y);
	std::vector<CanvasPoint>PivotCanvasPoints;


};
