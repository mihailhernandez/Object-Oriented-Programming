#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	const unsigned int FIGURE_COUNT = 3;
	Figure** figures = new Figure * [FIGURE_COUNT];

	Triangle* tr = new Triangle(1, 2, 3, 6, 2, 6);
	Circle* cr = new Circle(1, 2, 3);
	Rectangle* rec = new Rectangle(1, 1, 9, 9);

	figures[0] = tr;
	figures[1] = cr;
	figures[2] = rec;

	for (int i = 0; i < FIGURE_COUNT; i++)
		std::cout << figures[i]->get_perimeter() << std::endl;

	return 0;
}