#include "Cat.hpp"

Cat::Cat(const String name) : Animal(name) {}

Animal* Cat::clone() const
{
	Cat* copy = new Cat(*this);
	return copy;
}

void Cat::roar() const 
{
	std::cout << "meow meow" << std::endl;
}