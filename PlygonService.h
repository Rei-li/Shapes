//---------------------------------------------------------------------------

#ifndef PlygonServiceH
#define PlygonServiceH
#include "Polygon.h"
//---------------------------------------------------------------------------
#endif


#include <string>
#include <vector>

class PolygonService {
	static Polygon _polygon ;


public:
	static void AddPoint(int x, int y);
	static std::vector<Point>GetPivotPoints();

};