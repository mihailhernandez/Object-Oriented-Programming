#include <iostream>
#include <math.h>

struct Student
{
	public :

	char* name;
	int age;
	int fac_num;

	Student(char* name, const int age, const int fac_num)
	{
		this->name = name;
		this->age = age;
		this->fac_num = fac_num;
	}
};

struct Point
{
	public:

	int x;
	int y;

	Point() {}

	Point(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	void print()
	{
		std::cout << "Point: " << x << " " << y << std::endl;
	}
};

double get_dist(const Point& p1, const Point& p2)
{
	return hypot(abs(p1.x - p2.x), abs(p1.y - p2.y)); 
}

int main()
{
	Point p1(1, 1), p2(2, 2);

	std::cout << "Size of Point: " << sizeof(Point) << std::endl;

	p1.print();
	p2.print();

	std::cout << get_dist(p1, p2) << std::endl;

	return 0;
}
