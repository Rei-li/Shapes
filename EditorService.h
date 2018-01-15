#pragma once

#include "Polygon.h"
#include "Circle.h"

class EditorService {
	static class Polygon _polygon;
	static Circle _circle;
	static int _dpcm;

	static int _startMoveX;
	static int _startMoveY;
	static int _endMoveX;
	static int _endMoveY;

	static std::vector<class Polygon>_polygonStates;

	static int _statesIndex;

public:
	static void ClearPlygonPoints();
	static void ClearCirclePoints();
	static void AddCanvasPointToPolygon(int x, int y);
	static void AddCanvasPointToCircle(int x, int y);
	static std::vector<CanvasPoint>GetPivotCanvasPointsFromPolygon();
	static std::vector<CanvasPoint>GetPivotCanvasPointsFromCircle();
	static void SetDpcm(int dpcm);
	static int GetDpcm();
	static class Polygon GetPolygon();
	static void SetPolygonCenter(int x, int y);

	static void SetStartMovePoint(int x, int y);
	static void SetEndMovePoint(int x, int y);

	static int GetEndMovePointX();
	static int GetEndMovePointY();

	static void MovePolygon();
	static std::vector<class Polygon>GetPolygonStates();
	static void SetStatesIndex(int index);
	static int GetStatesIndex();

	static void RotatePolygon();
	static void ScalePolygon();

	static void ClearMoveElements();
	// static void SetCircleCenter(int x, int y);
	// static Circle EditorService::Get—ircle();
};
