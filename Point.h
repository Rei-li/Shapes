// ---------------------------------------------------------------------------

#ifndef PointH
#define PointH
// ---------------------------------------------------------------------------
#endif

class Point {

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
