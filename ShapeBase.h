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

	void SetCenter(int x, int y);
	void Move(int xStart, int yStart, int xEnd, int yEnd);
	void Rotate(int x, int y);
	void Scale(int distance);

	virtual std::vector<Point> Drow();

	void AddPivotPoint(int x, int y);

	std::vector<Point>PivotPoints;
 
protected:

};
