#include "EditorService.h"

Polygon EditorService::_polygon;
Circle EditorService::_circle;

int EditorService::_dpcm;

int EditorService::_startMoveX;
int EditorService::_startMoveY;
int EditorService::_endMoveX;
int EditorService::_endMoveY;

std::vector<Polygon>EditorService::_polygonStates;
int EditorService::_statesIndex;

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
	_dpcm = dpcm;
}

int EditorService::GetDpcm() {
	return _dpcm;
}

void EditorService::ClearPlygonPoints() {
	_polygon.ClearPivotPoints();
}

void EditorService::ClearCirclePoints() {
	_circle.ClearPivotPoints();
}

void EditorService::SetPolygonCenter(int x, int y) {
	_polygon.SetCenter(x, y);
}

void EditorService::SetStartMovePoint(int x, int y) {
	_startMoveX = x;
	_startMoveY = y;
}

void EditorService::SetEndMovePoint(int x, int y) {
	_endMoveX = x;
	_endMoveY = y;
}

int EditorService::GetEndMovePointX() {
	return _endMoveX;
}

int EditorService::GetEndMovePointY() {
	return _endMoveY;
}

void EditorService::MovePolygon() {
	_polygonStates = _polygon.Move(_startMoveX, _startMoveY, _endMoveX,
		_endMoveY);

}

std::vector<Polygon>EditorService::GetPolygonStates() {
	return _polygonStates;
}

void EditorService::SetStatesIndex(int index) {
	_statesIndex = index;
}

int EditorService::GetStatesIndex() {
	return _statesIndex;
}

void EditorService::ClearMoveElements() {
	_statesIndex = 0;
	_polygonStates.clear();
}

// void EditorService::Set—ircleCenter(int x, int y){
// _circle.SetCenter( x,  y);
// }

// —ircle EditorService::Get—ircle() {
// return _circle;
// }
