#include <iostream>
#include <ctime>
#include <math.h>

// The int a variable in the test file will be global
// if we include it here...
#include "test.cpp"
#include "triangle.cpp"

// a macro named m that takes a and b and multiplies them
#define m(a, b) (a * b)


// Distance between 2 points described with 2 coordinates each
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Multiplication function
int mult(int a, int b)
{
    return a * b;
}

// Distance function between two points.
double dist(const Point& p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{

    // including a cpp file using include statement
    std::cout << "a from test.cpp is " << a << std::endl;
    a++;
    std::cout << "we increment a and now a is  " << a << std::endl;
    
    // Measuring the time using a function as multiplication tool
    clock_t begin = clock();

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            mult(i, j);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
   
    // Measuring the time using a macro as multiplication tool
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

    // One way to define three points.
    int x1, y1,
        x2, y2,
        x3, y3;

    // we make a struct to create our own type 
    Point p(1, 3);
    Point p1(1, 2), p2(3, 4);

    std::cout << "dist from point 1 and point 2 = " << dist(p1, p2) << std::endl;

    std::cout << "size of Point = " << sizeof(Point) << std::endl; 

    // interesting fact
    // we can store a bool in one bit but the system fetches 1 byte 
    // to not make asymmetries 

    std::cout << "size of bit = " << sizeof(bool) << std::endl;

    // We can make our own triangle.
    Triangle triangle(p, p1, p2);           // using 3 points
    Triangle triangle_1(1, 2, 4, 5, 6, 7);  // using 6 coordinates

    std::cout << "size of Triangle = " << sizeof(Triangle) << std::endl; 

    return 0;
}
