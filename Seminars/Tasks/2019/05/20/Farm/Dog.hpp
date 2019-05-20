#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(const String);
	void roar() const;
	Animal* clone() const;
};