#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(const String);
	Animal* clone() const;
	void roar() const;
};