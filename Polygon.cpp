// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Polygon.h"
#include <cmath>
#include <vector>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

float Polygon::GetArea() {
	float area = 0;
	int size = PivotPoints.size();
	if (size > 3) {
		std::vector<Polygon>triangles = Triangulation();
		for (int i = 0; i < triangles.size(); i++) {
			area + triangles[i].GetArea();
		}
	}
	else {
		float a = GetDistance(PivotPoints[0], PivotPoints[1]);
		float b = GetDistance(PivotPoints[1], PivotPoints[2]);
		float c = GetDistance(PivotPoints[2], PivotPoints[0]);
		float p = (a + b + c) / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
	}

	return area;
}

float Polygon::GetPerimeter() {

	int size = PivotPoints.size();
	int previousIndex = size - 1;
	float p;
	for (int currentIndex = 0; currentIndex < size; currentIndex++) {

		p + GetDistance(PivotPoints[previousIndex], PivotPoints[currentIndex]);

		previousIndex = currentIndex;
	}

	return p;
}

Point Polygon::GetCenter() {
	Point centerPoint;
	int size = PivotPoints.size();
	if (size > 3) {
		std::vector<Polygon>triangles = Triangulation();

		int counter = 0;
		int xSum = 0;
		int ySum = 0;

		for (int i = 0; i < triangles.size(); i++) {
			xSum + (triangles[i].GetCenter().GetX() * triangles[i].GetArea());
			ySum + (triangles[i].GetCenter().GetY() * triangles[i].GetArea());
		}

		float area = GetArea();
		int x = xSum / area;
		int y = ySum / area;
		centerPoint.SetX(x);
		centerPoint.SetY(y);

	}
	else {
		int counter = 0;
		int xSum = 0;
		int ySum = 0;
		for (int i = 0; i < size; i++) {
			xSum + PivotPoints[i].GetX();
			ySum + PivotPoints[i].GetY();
			counter++;
		}

		int x = xSum / counter;
		int y = ySum / counter;
		centerPoint.SetX(x);
		centerPoint.SetY(y);
	}

	return centerPoint;
}

void Polygon::SetCenter() {

}

void Polygon::Rotate() {

}

void Polygon::Scale() {

}

std::vector<Point>Polygon::Drow() {

	return PivotPoints;
}

bool Polygon::IsPointInPolygon(Point point) {
	int size = PivotPoints.size();

	bool result = false;
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		Point currentPivotPoint = PivotPoints[i];
		int currentPivotPointX = currentPivotPoint.GetX();
		int currentPivotPointY = currentPivotPoint.GetY();

		Point pivotPreviousPoint = PivotPoints[j];
		int pivotPreviousPointX = pivotPreviousPoint.GetX();
		int pivotPreviousPointY = pivotPreviousPoint.GetY();

		if ((currentPivotPointY < point.GetY() && pivotPreviousPointY >=
			point.GetY() || pivotPreviousPointY <
			point.GetY() && currentPivotPointY >= point.GetY()) &&
			(currentPivotPointX + (point.GetY() - currentPivotPointY) /
			(pivotPreviousPointY - currentPivotPointY) * (pivotPreviousPointX -
			currentPivotPointX) < point.GetX())) {
			result = !result;
		}
		j = i;
	}
	return result;
}

float Polygon::AreaOfConvexPolygon() {

	return 0.0;
}

float Polygon::CenterOfConvexPolygon() {
	return 0.0;
}

float Polygon::GetDistance(Point startPoint, Point endPoint) {

	float x1 = (float)startPoint.GetX();
	float y1 = (float)startPoint.GetY();

	float x2 = (float)endPoint.GetX();
	float y2 = (float)endPoint.GetY();

	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float Polygon::GetAngleValue(Point previousPoint, Point currentPoint,
	Point nextPoint) {
	float PI = 3.14159265;
	float a = GetDistance(currentPoint, previousPoint);
	float b = GetDistance(currentPoint, nextPoint);
	float c = GetDistance(previousPoint, nextPoint);
	float value = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b))
		* 180.0 / PI;
	return value;
}

std::vector<Point>Polygon::GetSetOfPointsWithAngleValues
	(std::vector<Point>pivotPoints) {
	int size = pivotPoints.size();
	int previousIndex = size - 1;

	std::vector<Point>pivotPointsWithAngles;

	for (int currentIndex = 0; currentIndex < size; currentIndex++) {
		int nextIndex;
		if (currentIndex < size - 1) {
			nextIndex = currentIndex + 1;
		}
		else {
			nextIndex = 0;
		}

		Point previousPoint = pivotPoints[previousIndex];
		Point currentPoint = pivotPoints[currentIndex];
		Point nextPoint = pivotPoints[nextIndex];

		float angleValue = GetAngleValue(previousPoint, currentPoint,
			nextPoint);

		currentPoint.SetAngle(angleValue);
		pivotPointsWithAngles.push_back(currentPoint);

		previousIndex = currentIndex;
	}

	return pivotPointsWithAngles;
}

std::vector<Point>Polygon::GetSortedListByAngles
	(std::vector<Point>pivotPointsWithAngles) {

	std::vector<Point> *copiedPivotPointsWithAngles = new std::vector<Point>();

	for (unsigned int counter = 0; counter < pivotPointsWithAngles.size();
	counter++) {

		copiedPivotPointsWithAngles->push_back(pivotPointsWithAngles[counter]);

	}

	QuickSortByAngles(copiedPivotPointsWithAngles, 0,
		copiedPivotPointsWithAngles->size() - 1);

	return Copy(copiedPivotPointsWithAngles);
}

void Polygon::QuickSortByAngles(std::vector<Point> *points, int left, int right)
{

	int i = left, j = right;

	Point tmp;

	int pivot = (*points)[(left + right) / 2].GetAngle();

	while (i <= j) {

		while ((*points)[i].GetAngle() < pivot)

			i++;

		while ((*points)[j].GetAngle() > pivot)

			j--;

		if (i <= j) {

			tmp = (*points)[i];

			(*points)[i] = (*points)[j];

			(*points)[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		QuickSortByAngles(points, left, j);

	if (i < right)

		QuickSortByAngles(points, i, right);

}

std::vector<Point>Polygon::Copy(std::vector<Point> *points) {
	std::vector<Point>resultList;
	for (unsigned int counter = 0; counter < points->size(); counter++) {

		resultList.push_back((*points)[counter]);

	}

	return resultList;
}

Point Polygon::GetPointWithMaxAngle(std::vector<Point>pivotPointsWithAngles) {

	std::vector<Point>sortedPointList =
		GetSortedListByAngles(pivotPointsWithAngles);

	return sortedPointList[0];

}

void Polygon::GetPolygonTriangles(std::vector<Polygon> *triangles,
	std::vector<Point>pivotPoints) {

	std::vector<Point>pivotPointsWithAngles =
		GetSetOfPointsWithAngleValues(pivotPoints);

	Point pointWithMaxAngle = GetPointWithMaxAngle(pivotPointsWithAngles);

	std::vector<Point>restPivotPointsWithAngles;

	int size = pivotPointsWithAngles.size();
	int previousIndex = size - 1;

	for (int currentIndex = 0; currentIndex < size; currentIndex++) {
		int nextIndex;
		if (currentIndex < size - 1) {
			nextIndex = currentIndex + 1;
		}
		else {
			nextIndex = 0;
		}

		Point previousPoint = pivotPointsWithAngles[previousIndex];
		Point currentPoint = pivotPointsWithAngles[currentIndex];
		Point nextPoint = pivotPointsWithAngles[nextIndex];

		if (currentPoint.GetX() == pointWithMaxAngle.GetX() && currentPoint.GetY
			() == pointWithMaxAngle.GetY() && currentPoint.GetAngle()
			== pointWithMaxAngle.GetAngle()) {
			Polygon triangle;
			triangle.AddPivotPoint(previousPoint.GetX(), previousPoint.GetY());
			triangle.AddPivotPoint(currentPoint.GetX(), currentPoint.GetY());
			triangle.AddPivotPoint(nextPoint.GetX(), nextPoint.GetY());
		}
		else {
			restPivotPointsWithAngles.push_back(currentPoint);
		}

		previousIndex = currentIndex;
	}

	if (restPivotPointsWithAngles.size() > 3) {
		GetPolygonTriangles(triangles, restPivotPointsWithAngles);
	}

}

std::vector<Polygon>Polygon::Triangulation() {
	std::vector<Polygon> *triangles;
	GetPolygonTriangles(triangles, PivotPoints);

	return CopyTriangles(triangles);
}

std::vector<Polygon>Polygon::CopyTriangles(std::vector<Polygon> *triangles) {
	std::vector<Polygon>resultList;
	for (unsigned int counter = 0; counter < triangles->size(); counter++) {

		resultList.push_back((*triangles)[counter]);

	}

	return resultList;
}
