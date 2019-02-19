#include "point.cpp"

// A struct triangle that has three points in it.
// One constructor with three points and one with 
// six integers each two being the x an y coordinates
// of every point.

struct Triangle
{
    Point p1;
    Point p2;
    Point p3;

    int x1, y1, x2, y2, x3, y3;

    Triangle() {}

    // more clear but we force the user to
    // create three points before creating a
    // triangle
    Triangle(Point p1, Point p2, Point p3) 
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }

    // better for the user since he cannot see we have a point
    // struct and he will not be forced to use it
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        this->x1 = x1; 
        this->y1 = y1; 
        this->x2 = x2; 
        this->y2 = y2; 
        this->x3 = x3; 
        this->y3 = y3; 
    };
};
