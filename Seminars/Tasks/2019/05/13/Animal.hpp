#pragma once

#include "String.hpp"

class Animal
{
	String name;
public:
	Animal(const String);
	virtual ~Animal() {};
	virtual void roar() const = 0;
	virtual Animal* clone() const = 0;
};