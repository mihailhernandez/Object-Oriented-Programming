#include "Number.h"

Number::Number(const int number) : number(number) {}

void Number::print() const
{
	std::cout << number;
}

int Number::evaluate() const
{
	return number;
}