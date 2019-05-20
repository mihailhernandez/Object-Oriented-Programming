#include "Cow.hpp"

Cow::Cow(const String name) : Animal(name) {}

Animal* Cow::clone() const
{
	Cow* copy = new Cow(*this);
	return copy;
}

void Cow::roar() const
{
	std::cout << "muu mmuu" << std::endl;
}