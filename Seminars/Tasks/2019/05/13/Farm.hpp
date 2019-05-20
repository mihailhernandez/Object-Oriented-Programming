#pragma once

#include "Animal.hpp"

class Farm
{
public:
	Farm(const int);
	Farm(const Farm&);
	~Farm();
	Farm& operator=(const Farm&);
	bool add_cat(const String);
	bool add_dog(const String);
	bool add_cow(const String);
	void roar_all() const;
private:
	Animal** animals;
	int len;
	int count;
	void free();
	void copy_from(const Farm&);
};