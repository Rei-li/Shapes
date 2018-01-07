// ---------------------------------------------------------------------------

#ifndef ShapeBaseH
#define ShapeBaseH
#include <vector>
#include "Point.h"
// ---------------------------------------------------------------------------
#endif

class Shape {
public:
	virtual float GetArea() = 0;
	virtual int GetPerimeter() = 0;
	virtual Point GetCenter();

	virtual void MoveCenter();
	virtual void Rotate();
	virtual void Scale();

	virtual std::vector<Point> Drow();

	void AddPivotPoint(int x, int y);

	std::vector<Point>PivotPoints;
 
protected:

};
