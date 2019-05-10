#pragma once

#include <iostream>
#include "Point.h"

class Figure
{
	Point* points;
	int point_count;

	void copy_from(const Figure&);
	void free();

public:
	Figure(const int);
	Figure(const Figure&);
	Figure& operator=(const Figure&);
	~Figure();

	virtual double get_perimeter() const = 0;

	void set_point(const int, const int, const int);
	const Point& get_point(const int) const;
};
