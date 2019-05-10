#pragma once
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle(const int, const int,
		const int, const int,
		const int, const int);

	double get_perimeter() const;
};