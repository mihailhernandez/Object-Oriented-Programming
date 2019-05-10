#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle(const int, const int, 
		const int, const int);

	double get_perimeter() const;
};