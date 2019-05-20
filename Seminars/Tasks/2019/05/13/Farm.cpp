#include <iostream> 

#include "Farm.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Cow.hpp"

Farm::Farm(const int len) : animals(new Animal*[len]), count(0), len(len) {}

Farm::Farm(const Farm& other) : animals(nullptr), count(0), len(0)
{
	copy_from(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copy_from(other);
	}
	return *this;
}

Farm::~Farm()
{
	free();
}

bool Farm::add_cat(const String name)

{
	Cat* c = new Cat(name);
	if (count == len)
		return false;
	animals[count] = c;
	count++;
	return true;
}

bool Farm::add_dog(const String name)
{
	Dog* c = new Dog(name);
	if (count == len)
		return false;
	animals[count] = c;
	count++;
	return true;
}

bool Farm::add_cow(const String name)
{
	Cow* c = new Cow(name);
	if (count == len)
		return false;
	animals[count] = c;
	count++;
	return true;
}

void Farm::roar_all() const
{
	for (int i = 0; i < count; i++)
		animals[i]->roar();  //roar is a virtual function 
}

void Farm::free()
{
	for (int i = 0; i < count; i++)
		delete animals[i];
	delete[] animals;
}

void Farm::copy_from(const Farm& other)
{
	animals = new Animal*[other.len];
	for (int i = 0; i < other.count; i++)
		animals[i] = other.animals[i]->clone(); //clone is a virtual function
	len = other.len;
	count = other.count;
}