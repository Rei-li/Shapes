#pragma once

#include <vector>
#include "ShapeBase.h"
#include "CanvasPoint.h"

class Polygon : public Shape {

public:
	float GetArea();
	float GetPerimeter();
	CanvasPoint GetCenter();

private:
	bool IsCanvasPointInPolygon(CanvasPoint CanvasPoint);
	float GetDistance(CanvasPoint startCanvasPoint, CanvasPoint endCanvasPoint);
	float GetAngleValue(CanvasPoint previousCanvasPoint,
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
