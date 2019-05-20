#pragma once

#include "Dog.hpp"

Dog::Dog(const String name) : Animal(name) {}

void Dog::roar() const
{
	std::cout << "bau bau" << std::endl;
}

Animal* Dog::clone() const
{
	Dog* copy = new Dog(*this);
	return copy;
}