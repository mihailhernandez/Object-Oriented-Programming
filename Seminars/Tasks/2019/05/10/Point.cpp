#pragma once

#include "Point.h"
#include "cmath"

Point::Point() : x(0), y(0) {}

Point::Point(const int x, const int y) : x(x), y(y) {}

double Point::dist_to(const Point& other) const
{	
	return hypot(x - other.x, y - other.y);
}