#include "Polygon.h"
#include "Logger.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <string>

// using namespace std;



float Polygon::GetArea() {


	float area = 0;
	int size = PivotCanvasPoints.size();
	if (size > 3) {
		std::vector<Polygon>triangles = Triangulation();
		for (int i = 0; i < triangles.size(); i++) {
			area = area + triangles[i].GetArea();
		}
	}
	else {

		Logger::WriteInfo("PivotCanvasPoints[0]: " + std::to_string
			(PivotCanvasPoints[0].GetX()) + "  " + std::to_string
			(PivotCanvasPoints[0].GetY()) + ";");

		Logger::WriteInfo("PivotCanvasPoints[1]: " + std::to_string
			(PivotCanvasPoints[1].GetX()) + "  " + std::to_string
			(PivotCanvasPoints[1].GetY()) + ";");

		float a = GetDistance(PivotCanvasPoints[0], PivotCanvasPoints[1]);
		Logger::WriteInfo
			("GetDistance(PivotCanvasPoints[0], PivotCanvasPoints[1]): " +
			std::to_string(a/_dpcm));
		float b = GetDistance(PivotCanvasPoints[1], PivotCanvasPoints[2]);
		Logger::WriteInfo
			("GetDistance(PivotCanvasPoints[1], PivotCanvasPoints[2]): " +
			std::to_string(b/_dpcm));
		float c = GetDistance(PivotCanvasPoints[2], PivotCanvasPoints[0]);
		Logger::WriteInfo
			("GetDistance(PivotCanvasPoints[2], PivotCanvasPoints[0]): " +
			std::to_string(c/_dpcm));
		float p = (a + b + c) / 2;
		Logger::WriteInfo("p: " + std::to_string(p/_dpcm));
		area = std::sqrt(p * (p - a) * (p - b) * (p - c));
		Logger::WriteInfo("area: " + std::to_string(area/_dpcm));
	}

	return area/_dpcm;
}

float Polygon::GetPerimeter() {

	int size = PivotCanvasPoints.size();
	int previousIndex = size - 1;
	float perimeter = 0;
	for (int currentIndex = 0; currentIndex < size; currentIndex++) {

		perimeter = perimeter + GetDistance(PivotCanvasPoints[previousIndex],
			PivotCanvasPoints[currentIndex]);

		previousIndex = currentIndex;
	}

	return perimeter;
}

CanvasPoint Polygon::GetCenter() {
	CanvasPoint centerCanvasPoint;
	int size = PivotCanvasPoints.size();
	if (size > 3) {
		std::vector<Polygon>triangles = Triangulation();

		int counter = 0;
		int xSum = 0;
		int ySum = 0;

		for (int i = 0; i < triangles.size(); i++) {
			xSum = xSum +
				(triangles[i].GetCenter().GetX() * triangles[i].GetArea());
			ySum = ySum +
				(triangles[i].GetCenter().GetY() * triangles[i].GetArea());
		}

		float area = GetArea();
		int x = xSum / area;
		int y = ySum / area;
		centerCanvasPoint.SetX(x);
		centerCanvasPoint.SetY(y);

	}
	else {
		int counter = 0;
		int xSum = 0;
		int ySum = 0;
		for (int i = 0; i < size; i++) {
			xSum = xSum + PivotCanvasPoints[i].GetX();
			ySum = ySum + PivotCanvasPoints[i].GetY();
			counter++;
		}

		int x = xSum / counter;
		int y = ySum / counter;
		centerCanvasPoint.SetX(x);
		centerCanvasPoint.SetY(y);
	}

	return centerCanvasPoint;
}

bool Polygon::IsCanvasPointInPolygon(CanvasPoint point) {
	int size = PivotCanvasPoints.size();

	bool result = false;
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		CanvasPoint currentPivotCanvasPoint = PivotCanvasPoints[i];
		int currentPivotCanvasPointX = currentPivotCanvasPoint.GetX();
		int currentPivotCanvasPointY = currentPivotCanvasPoint.GetY();

		CanvasPoint pivotPreviousCanvasPoint = PivotCanvasPoints[j];
		int pivotPreviousCanvasPointX = pivotPreviousCanvasPoint.GetX();
		int pivotPreviousCanvasPointY = pivotPreviousCanvasPoint.GetY();

		if ((currentPivotCanvasPointY <
			point.GetY() && pivotPreviousCanvasPointY >= point.GetY() ||
			pivotPreviousCanvasPointY <
			point.GetY() && currentPivotCanvasPointY >= point.GetY()) &&
			(currentPivotCanvasPointX + (point.GetY() -
			currentPivotCanvasPointY) / (pivotPreviousCanvasPointY -
			currentPivotCanvasPointY) * (pivotPreviousCanvasPointX -
			currentPivotCanvasPointX) < point.GetX())) {
			result = !result;
		}
		j = i;
	}
	return result;
}

float Polygon::GetDistance(CanvasPoint startCanvasPoint,
	CanvasPoint endCanvasPoint) {

	float x1 = (float)startCanvasPoint.GetX();
	float y1 = (float)startCanvasPoint.GetY();

	float x2 = (float)endCanvasPoint.GetX();
	float y2 = (float)endCanvasPoint.GetY();

	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

float Polygon::GetAngleValue(CanvasPoint previousCanvasPoint,
	CanvasPoint currentCanvasPoint, CanvasPoint nextCanvasPoint) {
	float PI = 3.14159265;
	float a = GetDistance(currentCanvasPoint, previousCanvasPoint);
	float b = GetDistance(currentCanvasPoint, nextCanvasPoint);
	float c = GetDistance(previousCanvasPoint, nextCanvasPoint);
	float value = std::acos((std::pow(a, 2) + std::pow(b, 2) - std::pow(c, 2)) /
		(2 * a * b)) * 180.0 / PI;
	return value;
}

std::vector<CanvasPoint>Polygon::GetSetOfCanvasPointsWithAngleValues
	(std::vector<CanvasPoint>pivotCanvasPoints) {
	int size = pivotCanvasPoints.size();
	int previousIndex = size - 1;

	std::vector<CanvasPoint>pivotCanvasPointsWithAngles;

	for (int currentIndex = 0; currentIndex < size; currentIndex++) {
		int nextIndex;
		if (currentIndex < size - 1) {
			nextIndex = currentIndex + 1;
		}
		else {
			nextIndex = 0;
		}

		CanvasPoint previousCanvasPoint = pivotCanvasPoints[previousIndex];
		CanvasPoint currentCanvasPoint = pivotCanvasPoints[currentIndex];
		CanvasPoint nextCanvasPoint = pivotCanvasPoints[nextIndex];

		float angleValue = GetAngleValue(previousCanvasPoint,
			currentCanvasPoint, nextCanvasPoint);

		currentCanvasPoint.SetAngle(angleValue);
		pivotCanvasPointsWithAngles.push_back(currentCanvasPoint);

		previousIndex = currentIndex;
	}

	return pivotCanvasPointsWithAngles;
}

std::vector<CanvasPoint>Polygon::GetSortedListByAngles
	(std::vector<CanvasPoint>pivotCanvasPointsWithAngles) {

	std::vector<CanvasPoint> *copiedPivotCanvasPointsWithAngles =
		new std::vector<CanvasPoint>();

	for (unsigned int counter = 0; counter < pivotCanvasPointsWithAngles.size();
	counter++) {

		copiedPivotCanvasPointsWithAngles->push_back
			(pivotCanvasPointsWithAngles[counter]);

	}

	QuickSortByAngles(copiedPivotCanvasPointsWithAngles, 0,
		copiedPivotCanvasPointsWithAngles->size() - 1);

	return Copy(copiedPivotCanvasPointsWithAngles);
}

void Polygon::QuickSortByAngles(std::vector<CanvasPoint> *CanvasPoints,
	int left, int right) {

	int i = left, j = right;

	CanvasPoint tmp;

	int pivot = (*CanvasPoints)[(left + right) / 2].GetAngle();

	while (i <= j) {

		while ((*CanvasPoints)[i].GetAngle() < pivot)

			i++;

		while ((*CanvasPoints)[j].GetAngle() > pivot)

			j--;

		if (i <= j) {

			tmp = (*CanvasPoints)[i];

			(*CanvasPoints)[i] = (*CanvasPoints)[j];

			(*CanvasPoints)[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		QuickSortByAngles(CanvasPoints, left, j);

	if (i < right)

		QuickSortByAngles(CanvasPoints, i, right);

}

std::vector<CanvasPoint>Polygon::Copy(std::vector<CanvasPoint> *CanvasPoints) {
	std::vector<CanvasPoint>resultList;
	for (unsigned int counter = 0; counter < CanvasPoints->size(); counter++) {

		resultList.push_back((*CanvasPoints)[counter]);

	}

	return resultList;
}

CanvasPoint Polygon::GetCanvasPointWithMaxAngle
	(std::vector<CanvasPoint>pivotCanvasPointsWithAngles) {

	std::vector<CanvasPoint>sortedCanvasPointList =
		GetSortedListByAngles(pivotCanvasPointsWithAngles);

	return sortedCanvasPointList[0];

}

void Polygon::GetPolygonTriangles(std::vector<Polygon> *triangles,
	std::vector<CanvasPoint>pivotCanvasPoints) {

	std::vector<CanvasPoint>pivotCanvasPointsWithAngles =
		GetSetOfCanvasPointsWithAngleValues(pivotCanvasPoints);

	CanvasPoint CanvasPointWithMaxAngle =
		GetCanvasPointWithMaxAngle(pivotCanvasPointsWithAngles);

	std::vector<CanvasPoint>restPivotCanvasPointsWithAngles;

	int size = pivotCanvasPointsWithAngles.size();
	int previousIndex = size - 1;

	for (int currentIndex = 0; currentIndex < size; currentIndex++) {
		int nextIndex;
		if (currentIndex < size - 1) {
			nextIndex = currentIndex + 1;
		}
		else {
			nextIndex = 0;
		}

		CanvasPoint previousCanvasPoint =
			pivotCanvasPointsWithAngles[previousIndex];
		CanvasPoint currentCanvasPoint =
			pivotCanvasPointsWithAngles[currentIndex];
		CanvasPoint nextCanvasPoint = pivotCanvasPointsWithAngles[nextIndex];

		if (currentCanvasPoint.GetX() == CanvasPointWithMaxAngle.GetX()
			&& currentCanvasPoint.GetY() == CanvasPointWithMaxAngle.GetY()
			&& currentCanvasPoint.GetAngle()
			== CanvasPointWithMaxAngle.GetAngle()) {
			Polygon triangle;
			triangle.AddPivotCanvasPoint(previousCanvasPoint.GetX(),
				previousCanvasPoint.GetY());
			triangle.AddPivotCanvasPoint(currentCanvasPoint.GetX(),
				currentCanvasPoint.GetY());
			triangle.AddPivotCanvasPoint(nextCanvasPoint.GetX(),
				nextCanvasPoint.GetY());
		}
		else {
			restPivotCanvasPointsWithAngles.push_back(currentCanvasPoint);
		}

		previousIndex = currentIndex;
	}

	if (restPivotCanvasPointsWithAngles.size() > 3) {
		GetPolygonTriangles(triangles, restPivotCanvasPointsWithAngles);
	}

}

std::vector<Polygon>Polygon::Triangulation() {
	std::vector<Polygon> *triangles = new std::vector<Polygon>();
	GetPolygonTriangles(triangles, PivotCanvasPoints);

	return CopyTriangles(triangles);
}

std::vector<Polygon>Polygon::CopyTriangles(std::vector<Polygon> *triangles) {
	std::vector<Polygon>resultList;
	for (unsigned int counter = 0; counter < triangles->size(); counter++) {

		resultList.push_back((*triangles)[counter]);

	}

	return resultList;
}
