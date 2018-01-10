#pragma once

class CanvasPoint {

	int X, Y;
	float _angle;

public:
	int GetX();
	int GetY();
	float GetAngle();
	void SetX(int x);
	void SetY(int y);
	void SetAngle(float angle);
};
