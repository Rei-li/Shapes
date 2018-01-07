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
	virtual float GetPerimeter() = 0;
	virtual Point GetCenter();

	virtual void SetCenter(int x, int y);
	virtual void Move();
	void Rotate(int x, int y);
	virtual void Scale();

	virtual std::vector<Point> Drow();

	void AddPivotPoint(int x, int y);

	std::vector<Point>PivotPoints;
 
protected:

};
