#pragma once

#include "Polygon.h"
#include "Circle.h"


#include <string>
#include <vector>

class EditorService {
	static class Polygon _polygon ;
	static Circle _circle ;

public:
	static void AddCanvasPoint(int x, int y);
	static std::vector<CanvasPoint>GetPivotCanvasPoints();

};