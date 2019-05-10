#include "Circle.h"

const double PI = 3.1415;

Circle::Circle(const int x, const int y, const int radius) : Figure(1), radius(radius)
{
	set_point(0, x, y);
}

double Circle::get_perimeter() const
{
	std::cout << "Circle :" << std::endl;
	return 2 * PI * radius;
}