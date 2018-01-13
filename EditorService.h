#pragma once

#include "Polygon.h"
#include "Circle.h"

class EditorService {
	static class Polygon _polygon;
	static Circle _circle;

public:
	static void ClearPlygonPoints();
	static void ClearCirclePoints();
	static void EditorService::AddCanvasPointToPolygon(int x, int y);
	static void EditorService::AddCanvasPointToCircle(int x, int y);
	static std::vector<CanvasPoint>GetPivotCanvasPointsFromPolygon();
	static std::vector<CanvasPoint>GetPivotCanvasPointsFromCircle();
	static void SetDpcm(int dpcm);
	static class Polygon EditorService::GetPolygon();
	// static Circle EditorService::Get—ircle();
};
