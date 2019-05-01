#ifndef __ACTOR__
#define __ACTOR__
#include <fstream>
#include <iostream>
#include <cstring>
#include "Actor.hpp"
#include "Constants.hpp"

class Actor
{
public:
	Actor();
	Actor(const unsigned long long id, const char* first_name, 
		  const char* last_name, const unsigned long long films);
	~Actor();
	void set_id(const unsigned long long id);
	void set_films(const unsigned long long films);
	void set_first_name(const char* first_name);
	void set_last_name(const char* last_name);
	unsigned long long get_id() const;
	unsigned long long get_films() const;
	char* get_first_name() const;
	char* get_last_name() const;
private:
	unsigned long long id;
	unsigned long long films;
	char* first_name;
	char* last_name;
};

std::ostream& operator<<(std::ostream& os, const Actor& actor);
std::istream& operator>>(std::istream& is, Actor& actor);
std::ofstream& operator<<(std::ofstream& os, const Actor& actor);
std::ifstream& operator>>(std::ifstream& is, Actor& actor);

#endif