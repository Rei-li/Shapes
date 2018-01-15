#pragma once

#include <vector>
#include "ShapeBase.h"
#include "CanvasPoint.h"

class Polygon : public Shape {

public:
	long double GetArea();
	long double GetPerimeter();
	CanvasPoint GetCenter();
	std::vector<Polygon>TriangulationCheck();
	std::vector<Polygon> Move(int xStart, int yStart, int xEnd, int yEnd);
	std::vector<Polygon> Rotate(int x, int y);
		std::vector<Polygon> Scale();

private:
	bool IsCanvasPointInPolygon(CanvasPoint CanvasPoint);
	long double GetDistance(CanvasPoint startCanvasPoint,
		CanvasPoint endCanvasPoint);
	long double GetAngleValue(CanvasPoint previousCanvasPoint,
		CanvasPoint currentCanvasPoint, CanvasPoint nextCanvasPoint);
	std::vector<CanvasPoint>GetSetOfCanvasPointsWithAngleValues
		(std::vector<CanvasPoint>pivotCanvasPoints);
	std::vector<CanvasPoint>GetSortedListByAngles
		(std::vector<CanvasPoint>pivotCanvasPointsWithAngles);
	void QuickSortByAngles(std::vector<CanvasPoint> *CanvasPoints, int left,
		int right);
	std::vector<CanvasPoint>Copy(std::vector<CanvasPoint> *CanvasPoints);
	CanvasPoint GetCanvasPointWithMaxAngle
		(std::vector<CanvasPoint>pivotCanvasPointsWithAngles);
	void GetPolygonTriangles(std::vector<Polygon> *triangles,
		std::vector<CanvasPoint>pivotCanvasPoints);
	std::vector<Polygon>Triangulation();
	std::vector<Polygon>CopyTriangles(std::vector<Polygon> *triangles);

};
