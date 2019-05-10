#pragma once

struct Point
{
	int x;
	int y;

	Point();
	Point(const int, const int);

	double dist_to(const Point&) const;
};