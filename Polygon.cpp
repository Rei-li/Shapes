#include "Polygon.h"
#include "Logger.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <string>

// using namespace std;
std::vector<Polygon>Polygon::TriangulationCheck() {
	std::vector<Polygon>triangles = Triangulation();
	return triangles;
}

long double Polygon::GetArea() {

	long double area = 0;
	int size = PivotCanvasPoints.size();
	if (size > 3) {
		std::vector<Polygon>triangles = Triangulation();
		for (int i = 0; i < triangles.size(); i++) {
			// Logger::WriteInfo(std::to_string(triangles[i].GetArea()));
			area = area + triangles[i].GetArea();
			Logger::WriteInfo(std::to_string(area));
		}
	}
	else {

		Logger::WriteInfo("PivotCanvasPoints[0]: " + std::to_string
			(PivotCanvasPoints[0].GetX()) + "  " + std::to_string
			(PivotCanvasPoints[0].GetY()) + ";");

		Logger::WriteInfo("PivotCanvasPoints[1]: " + std::to_string
			(PivotCanvasPoints[1].GetX()) + "  " + std::to_string
			(PivotCanvasPoints[1].GetY()) + ";");

		Logger::WriteInfo("PivotCanvasPoints[2]: " + std::to_string
			(PivotCanvasPoints[2].GetX()) + "  " + std::to_string
			(PivotCanvasPoints[2].GetY()) + ";");

		long double a = GetDistance(PivotCanvasPoints[0], PivotCanvasPoints[1]);
		Logger::WriteInfo("a: " + std::to_string(a));
		// Logger::WriteInfo
		// ("GetDistance(PivotCanvasPoints[0], PivotCanvasPoints[1]): " +
		// std::to_string(a / _dpcm));
		long double b = GetDistance(PivotCanvasPoints[1], PivotCanvasPoints[2]);
		Logger::WriteInfo("b: " + std::to_string(b));
		// Logger::WriteInfo
		// ("GetDistance(PivotCanvasPoints[1], PivotCanvasPoints[2]): " +
		// std::to_string(b / _dpcm));
		long double c = GetDistance(PivotCanvasPoints[2], PivotCanvasPoints[0]);
		Logger::WriteInfo("c: " + std::to_string(c));
		// Logger::WriteInfo
		// ("GetDistance(PivotCanvasPoints[2], PivotCanvasPoints[0]): " +
		// std::to_string(c / _dpcm));
		long double p = (a + b + c) / 2;
		// Logger::WriteInfo("p: " + std::to_string(p / _dpcm));
		area = std::sqrt(p * (p - a) * (p - b) * (p - c));
		// Logger::WriteInfo("area: " + std::to_string(area / _dpcm));
	}

	return area;
}

long double Polygon::GetPerimeter() {

	int size = PivotCanvasPoints.size();
	int previousIndex = size - 1;
	long double perimeter = 0;
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

		long double area = GetArea();
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

long double Polygon::GetDistance(CanvasPoint startCanvasPoint,
	CanvasPoint endCanvasPoint) {

	long double x1 = (long double)startCanvasPoint.GetX();
	long double y1 = (long double)startCanvasPoint.GetY();

	long double x2 = (long double)endCanvasPoint.GetX();
	long double y2 = (long double)endCanvasPoint.GetY();

	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

long double Polygon::GetAngleValue(CanvasPoint previousCanvasPoint,
	CanvasPoint currentCanvasPoint, CanvasPoint nextCanvasPoint) {
	long double PI = 3.14159265;
	long double a = GetDistance(currentCanvasPoint, previousCanvasPoint);
	long double b = GetDistance(currentCanvasPoint, nextCanvasPoint);
	long double c = GetDistance(previousCanvasPoint, nextCanvasPoint);
	long double value =
		std::acos((std::pow(a, 2) + std::pow(b, 2) - std::pow(c, 2)) /
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

		long double angleValue = GetAngleValue(previousCanvasPoint,
			currentCanvasPoint, nextCanvasPoint);

		currentCanvasPoint.SetAngle(angleValue);
		pivotCanvasPointsWithAngles.push_back(currentCanvasPoint);

		previousIndex = currentIndex;
	}

	return pivotCanvasPointsWithAngles;
}

std::vector<CanvasPoint>Polygon::GetSortedListByAngles
	(std::vector<CanvasPoint>pivotCanvasPointsWithAngles) {

	for (unsigned int counter = 0; counter < pivotCanvasPointsWithAngles.size();
	counter++) {
		Logger::WriteInfo
			("X: " + std::to_string(pivotCanvasPointsWithAngles[counter].GetX())
			+ "; Y: " + std::to_string(pivotCanvasPointsWithAngles[counter].GetY
			()) + "; Angle: " + std::to_string
			(pivotCanvasPointsWithAngles[counter].GetAngle()));
	}

	std::vector<CanvasPoint> *copiedPivotCanvasPointsWithAngles =
		new std::vector<CanvasPoint>();

	for (unsigned int counter = 0; counter < pivotCanvasPointsWithAngles.size();
	counter++) {

		copiedPivotCanvasPointsWithAngles->push_back
			(pivotCanvasPointsWithAngles[counter]);

	}

	for (unsigned int counter = 0;
	counter < copiedPivotCanvasPointsWithAngles->size(); counter++) {
		Logger::WriteInfo
			("X: " + std::to_string(pivotCanvasPointsWithAngles[counter].GetX())
			+ "; Y: " + std::to_string(pivotCanvasPointsWithAngles[counter].GetY
			()) + "; Angle: " + std::to_string
			(pivotCanvasPointsWithAngles[counter].GetAngle()));
	}

	QuickSortByAngles(copiedPivotCanvasPointsWithAngles, 0,
		copiedPivotCanvasPointsWithAngles->size() - 1);

	return Copy(copiedPivotCanvasPointsWithAngles);
}

void Polygon::QuickSortByAngles(std::vector<CanvasPoint> *CanvasPoints,
	int left, int right) {

	int i = left, j = right;

	CanvasPoint tmp;

	long double pivot = (*CanvasPoints)[(left + right) / 2].GetAngle();

	// for (unsigned int counter = 0; counter < CanvasPoints->size(); counter++) {
	// Logger::WriteInfo("X: " + std::to_string((*CanvasPoints)[counter].GetX()
	// ) + "; Y: " + std::to_string((*CanvasPoints)[counter].GetY()) +
	// "; Angle: " + std::to_string((*CanvasPoints)[counter].GetAngle()));
	// }

	// Logger::WriteInfo("i: " + std::to_string(i));
	// Logger::WriteInfo("j: " + std::to_string(j));

	while (i <= j) {

		while ((*CanvasPoints)[i].GetAngle() < pivot) {

			// for (unsigned int counter = 0; counter < CanvasPoints->size();
			// counter++) {
			// Logger::WriteInfo
			// ("X: " + std::to_string((*CanvasPoints)[counter].GetX()) +
			// "; Y: " + std::to_string((*CanvasPoints)[counter].GetY()) +
			// "; Angle: " + std::to_string
			// ((*CanvasPoints)[counter].GetAngle()));
			// }

			// Logger::WriteInfo("(*CanvasPoints)[i].GetAngle() " +
			// std::to_string((*CanvasPoints)[i].GetAngle()));
			// Logger::WriteInfo("pivot: " + std::to_string(pivot));
			// Logger::WriteInfo("i: " + std::to_string(i));
			i++;
		}
		while ((*CanvasPoints)[j].GetAngle() > pivot) {

			// for (unsigned int counter = 0; counter < CanvasPoints->size();
			// counter++) {
			// Logger::WriteInfo
			// ("X: " + std::to_string((*CanvasPoints)[counter].GetX()) +
			// "; Y: " + std::to_string((*CanvasPoints)[counter].GetY()) +
			// "; Angle: " + std::to_string
			// ((*CanvasPoints)[counter].GetAngle()));
			// }

			// Logger::WriteInfo("(*CanvasPoints)[j].GetAngle() " +
			// std::to_string((*CanvasPoints)[j].GetAngle()));
			// Logger::WriteInfo("pivot: " + std::to_string(pivot));
			// Logger::WriteInfo("j: " + std::to_string(j));
			j--;
		}
		if (i <= j) {

			tmp = (*CanvasPoints)[i];

			(*CanvasPoints)[i] = (*CanvasPoints)[j];

			(*CanvasPoints)[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j) {
		// for (unsigned int counter = 0; counter < CanvasPoints->size();
		// counter++) {
		// Logger::WriteInfo
		// ("X: " + std::to_string((*CanvasPoints)[counter].GetX()) +
		// "; Y: " + std::to_string((*CanvasPoints)[counter].GetY()) +
		// "; Angle: " + std::to_string
		// ((*CanvasPoints)[counter].GetAngle()));
		// }

		QuickSortByAngles(CanvasPoints, left, j);
	}
	if (i < right) {
		// for (unsigned int counter = 0; counter < CanvasPoints->size();
		// counter++) {
		// Logger::WriteInfo
		// ("X: " + std::to_string((*CanvasPoints)[counter].GetX()) +
		// "; Y: " + std::to_string((*CanvasPoints)[counter].GetY()) +
		// "; Angle: " + std::to_string
		// ((*CanvasPoints)[counter].GetAngle()));
		// }

		QuickSortByAngles(CanvasPoints, i, right);
	}
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
			triangles->push_back(triangle);
		}
		else {
			restPivotCanvasPointsWithAngles.push_back(currentCanvasPoint);
		}

		previousIndex = currentIndex;
	}

	if (restPivotCanvasPointsWithAngles.size() > 3) {
		GetPolygonTriangles(triangles, restPivotCanvasPointsWithAngles);
	}
	else {
		Polygon triangle;
		triangle.AddPivotCanvasPoint(restPivotCanvasPointsWithAngles[0].GetX(),
			restPivotCanvasPointsWithAngles[0].GetY());
		triangle.AddPivotCanvasPoint(restPivotCanvasPointsWithAngles[1].GetX(),
			restPivotCanvasPointsWithAngles[1].GetY());
		triangle.AddPivotCanvasPoint(restPivotCanvasPointsWithAngles[2].GetX(),
			restPivotCanvasPointsWithAngles[2].GetY());
		triangles->push_back(triangle);
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

std::vector<Polygon>Polygon::Move(int xStart, int yStart, int xEnd, int yEnd) {

	std::vector<CanvasPoint>CurrentPivotCanvasPoints = PivotCanvasPoints;
	std::vector<Polygon>shapeStates;

	int xDistance = xEnd - xStart;
	int yDistance = yEnd - yStart;

	double xPixelsInterval;
	double yPixelsInterval;

	double xStartDouble = xEnd;
	double yStartDouble = yEnd;

	double q = 3;

	if (abs(xDistance) > abs(yDistance)) {
		xPixelsInterval = q;
		int times = xDistance / q;
		yPixelsInterval = abs(double(yDistance) / double(times));

	}
	else {
		yPixelsInterval = q;
		int times = yDistance / q;
		xPixelsInterval = abs(double(xDistance) / double(times));
	}

	if (xDistance < 0) {
		xPixelsInterval = xPixelsInterval*-1;
	}

	if (yDistance < 0) {
		yPixelsInterval = yPixelsInterval*-1;
	}

	while (xStart != xStartDouble && yStart != yStartDouble) {
		Polygon polygon;

		for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
			CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
			int currentX = currentCanvasPoint.GetX();
			int currentY = currentCanvasPoint.GetY();

			polygon.AddPivotCanvasPoint(currentX + (xEnd - xStartDouble),
				currentY + (yEnd - yStartDouble));
		}
		shapeStates.push_back(polygon);

		if (abs(xStart - xStartDouble) > abs(xPixelsInterval)) {

			xStartDouble = xStartDouble - xPixelsInterval;

		}
		else {
			xStartDouble = xStart;
		}

		if (abs(yStart - yStartDouble) > abs(yPixelsInterval)) {

			yStartDouble = yStartDouble - yPixelsInterval;

		}
		else {
			yStartDouble = yStart;
		}

	}

	ClearPivotPoints();

	for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();

		AddPivotCanvasPoint(currentX + (xEnd - xStart),
			currentY + (yEnd - yStart));
	}
	CurrentPivotCanvasPoints.clear();

	return shapeStates;
}

std::vector<Polygon>Polygon::Rotate(int x, int y) {

	std::vector<CanvasPoint>CurrentPivotCanvasPoints = PivotCanvasPoints;
	long double PI = 3.14159265;
	int maxAngle = 90;

	std::vector<Polygon>shapeStates;

	int currentAngle = 1;

	while (currentAngle <= maxAngle) {
		long double angleRadian = currentAngle * PI / 180;

		Polygon polygon;

		for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
			CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
			int currentX = currentCanvasPoint.GetX();
			int currentY = currentCanvasPoint.GetY();

			long double X =
				(long double)((currentCanvasPoint.GetX() - x) * std::cos
				(angleRadian) - (currentCanvasPoint.GetY() - y) * std::sin
				(angleRadian) + x);
			long double Y =
				(long double)((currentCanvasPoint.GetX() - x) * std::sin
				(angleRadian) + (currentCanvasPoint.GetY() - y) * std::cos
				(angleRadian) + y);

			polygon.AddPivotCanvasPoint(X, Y);
		}
		shapeStates.push_back(polygon);

		currentAngle = currentAngle + 1;

	}

	ClearPivotPoints();

	long double angleRadian = maxAngle * PI / 180;
	for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();

		long double X =
			(long double)((currentCanvasPoint.GetX() - x) * std::cos
			(angleRadian) - (currentCanvasPoint.GetY() - y) * std::sin
			(angleRadian) + x);
		long double Y =
			(long double)((currentCanvasPoint.GetX() - x) * std::sin
			(angleRadian) + (currentCanvasPoint.GetY() - y) * std::cos
			(angleRadian) + y);

		AddPivotCanvasPoint(X, Y);

	}
	return shapeStates;
}

std::vector<Polygon>Polygon::Scale() {

	double scale = 2;

	std::vector<CanvasPoint>CurrentPivotCanvasPoints = PivotCanvasPoints;

	CanvasPoint centerCanvasPoint = GetCenter();
	int centerX = centerCanvasPoint.GetX();
	int centerY = centerCanvasPoint.GetY();




	std::vector<Polygon>shapeStates;

	double currentScale = 1;

	while (currentScale <= scale) {
		Polygon polygon;

		for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
			CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
			int currentX = currentCanvasPoint.GetX();
			int currentY = currentCanvasPoint.GetY();

			int scaledX = currentX / scale;
			int scaledY = currentY / scale;

			polygon.AddPivotCanvasPoint(scaledX, scaledY);
		}

		  polygon.SetCenter(centerX, centerY)   ;

		shapeStates.push_back(polygon);

		currentScale = currentScale + 0.1;

	}




	ClearPivotPoints();

	for (int i = 0; i < CurrentPivotCanvasPoints.size(); i++) {
		CanvasPoint currentCanvasPoint = CurrentPivotCanvasPoints[i];
		int currentX = currentCanvasPoint.GetX();
		int currentY = currentCanvasPoint.GetY();
		AddPivotCanvasPoint(currentX / scale, currentY / scale);
	}
	  SetCenter(centerX, centerY) ;




	return shapeStates;

}
