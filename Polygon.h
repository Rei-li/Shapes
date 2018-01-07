// ---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH
#include "ShapeBase.h"
#include <vector>
// ---------------------------------------------------------------------------
#endif

class Polygon : public Shape {

public:
	float GetArea();
	float GetPerimeter();
	Point GetCenter();

	void SetCenter();
	void Rotate();
	void Scale();

	std::vector<Point>Drow();

private:
	bool IsPointInPolygon(Point point);
	float AreaOfConvexPolygon();
	float CenterOfConvexPolygon();
	float GetDistance(Point startPoint, Point endPoint);
	float GetAngleValue(Point previousPoint, Point currentPoint,
		Point nextPoint);
	std::vector<Point>GetSetOfPointsWithAngleValues
		(std::vector<Point>pivotPoints);
	std::vector<Point>GetSortedListByAngles
		(std::vector<Point>pivotPointsWithAngles);
	void QuickSortByAngles(std::vector<Point> *points, int left, int right);
	std::vector<Point>Copy(std::vector<Point> *points);
	Point GetPointWithMaxAngle(std::vector<Point>pivotPointsWithAngles);
	void GetPolygonTriangles(std::vector<Polygon> *triangles,
	std::vector<Point>pivotPoints);
	std::vector<Polygon>Triangulation();
    std::vector<Polygon>CopyTriangles(std::vector<Polygon> *triangles);

};
