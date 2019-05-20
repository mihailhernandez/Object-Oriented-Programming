#pragma once

#include "Animal.hpp"

class Cow : public Animal
{
public:
	Cow(const String);
	Animal* clone() const;
	void roar() const;
};