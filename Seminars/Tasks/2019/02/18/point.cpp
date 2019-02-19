// A struct point that has two coordinates x and y.
// It has a default constuctor and one with x an y.

struct Point
{
    int x;
    int y;

    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
