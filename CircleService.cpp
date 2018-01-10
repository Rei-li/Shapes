//---------------------------------------------------------------------------

#pragma hdrstop

#include "CircleService.h"
#include "Circle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



#include <string>
#include <vector>

class EditorService {

	static Circle _circle ;

public:
	static void AddPoint(int x, int y);
	static std::vector<Point>GetPivotPoints();

};