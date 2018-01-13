#include "EditorService.h"

Polygon EditorService::_polygon;
Circle EditorService::_circle;

void EditorService::AddCanvasPointToPolygon(int x, int y) {
	_polygon.AddPivotCanvasPoint(x, y);
}

void EditorService::AddCanvasPointToCircle(int x, int y) {
	_circle.AddPivotCanvasPoint(x, y);
}

std::vector<CanvasPoint>EditorService::GetPivotCanvasPointsFromPolygon() {
	return _polygon.PivotCanvasPoints;
}

std::vector<CanvasPoint>EditorService::GetPivotCanvasPointsFromCircle() {
	return _circle.PivotCanvasPoints;
}

Polygon EditorService::GetPolygon() {
	return _polygon;
}

void EditorService::SetDpcm(int dpcm) {
	_polygon.SetDpcm(dpcm);
	_circle.SetDpcm(dpcm);
}

void EditorService::ClearPlygonPoints() {
	_polygon.ClearPivotPoints();
}

void EditorService::ClearCirclePoints() {
	_circle.ClearPivotPoints();
}

// —ircle EditorService::Get—ircle() {
// return _circle;
// }
