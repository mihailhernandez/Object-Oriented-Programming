#include "Rectangle.h"

Rectangle::Rectangle(const int x1, const int y1,
	const int x2, const int y2) : Figure(4)
{
	set_point(0, x1, y1);
	set_point(1, x2, y1);
	set_point(2, x2, y2);
	set_point(3, x1, y2);
}

double Rectangle::get_perimeter() const
{
	std::cout << "Rectangle :" << std::endl;
	return 2 * (get_point(0).dist_to(get_point(1)) + get_point(0).dist_to(get_point(3)));
}