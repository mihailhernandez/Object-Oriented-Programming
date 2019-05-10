#pragma once
#include "Figure.h"

void Figure::copy_from(const Figure& other)
{
	points = new Point[other.point_count];
	for (int i = 0; i < other.point_count; i++)
		points[i] = other.points[i];
	point_count = other.point_count;
}

void Figure::free()
{
	delete[] points;
	point_count = 0;
}

Figure::Figure(const Figure & other) : points(nullptr), point_count(other.point_count)
{
	copy_from(other);
}

Figure::~Figure()
{
	free();
}

Figure& Figure::operator=(const Figure & other)
{
	copy_from(other);
	return *this;
}

Figure::Figure(const int point_count) : point_count(point_count)
{
	points = new Point[point_count];
}

void Figure::set_point(const int index, const int x, const int y)
{
	if (index < 0 || index >= point_count)
		return;
	points[index].x = x;
	points[index].y = y;
}

const Point& Figure::get_point(const int index) const
{
	if (index < 0 || index >= point_count)
		throw "Invalid index";
	return points[index];
}