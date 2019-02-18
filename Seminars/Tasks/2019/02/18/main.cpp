#include <iostream>
#include <ctime>
#include <math.h>
#include "test.hpp"

#define m(a, b) (a * b)

struct Point
{
    Point() {}
    Point(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }
    int x, y; 
};

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int mult(int a, int b)
{
    return a * b;
}

double dist(const Point& p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

struct Triangle
{
    Triangle(Point p1, Point p2, Point p3)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }

    Point p1;
    Point p2;
    Point p3;
};

int main()
{
    std::cout << "a from test.hpp is " << a << std::endl;
    a++;
    std::cout << "we increment a and now a is  " << a << std::endl;
    
    clock_t begin = clock();

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            mult(i, j);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    begin = clock();

    std::cout << "multiplication using a function 1bil time using a function "
              << elapsed_secs << std::endl; 

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            m(i, j);

    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << "multiplication using a macro 1bil time using a macro " 
              << elapsed_secs << std::endl; 

    int x1, y1,
        x2, y2,
        x3, y3;

    // mn tupo taka shtoto mn promenlivi mnogo neshta

    // we make a struct to create our own type 

    Point p(1, 3);
    Point p1(1, 2), p2(3, 4);

    std::cout << "dist from point 1 and point 2 = " << dist(p1, p2) << std::endl;

    std::cout << "size of Point = " << sizeof(Point) << std::endl; 

    // interesting fact
    // we can store a bool in one bit but the system fetches 1 byte 
    // to not make asymmetries 

    std::cout << "size of bit = " << sizeof(bool) << std::endl;

    Triangle triangle(p, p1, p2);

    std::cout << "size of Triangle = " << sizeof(Triangle) << std::endl; 

    return 0;
}
