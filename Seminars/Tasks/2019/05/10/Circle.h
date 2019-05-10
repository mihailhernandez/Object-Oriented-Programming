#pragma once
#include "Figure.h"

class Circle : public Figure
{
	int radius;

public:
	Circle(const int, const int, const int);

	double get_perimeter() const;
};