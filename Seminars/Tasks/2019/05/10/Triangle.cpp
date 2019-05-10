#pragma once
#include "Triangle.h"

Triangle::Triangle(const int x1, const int y1,
	const int x2, const int y2,
	const int x3, const int y3)
	: Figure(3)
{
	set_point(0, x1, y1);
	set_point(1, x2, y2);
	set_point(2, x3, y3);
}

double Triangle::get_perimeter() const
{
	std::cout << "Triangle :" << std::endl;
	return get_point(1).dist_to(get_point(2))
		+ get_point(2).dist_to(get_point(0))
		+ get_point(0).dist_to(get_point(1));
}
