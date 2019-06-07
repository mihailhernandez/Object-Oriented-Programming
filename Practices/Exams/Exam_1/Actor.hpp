#ifndef __ACTOR__
#define __ACTOR__

#include <fstream>
#include <cstring>
#include "Actor.hpp"
#include "Constants.hpp"

class Actor
{
public:
	Actor();
	Actor(const Actor&);
	Actor(const long long id, const char* first_name, 
		  const char* last_name, const long long films);
	~Actor();

	Actor& operator=(const Actor&);

	void set_id(const long long id);
	void set_films(const long long films);
	void set_first_name(const char* first_name);
	void set_last_name(const char* last_name);

	long long get_id() const;
	long long get_films() const;
	const char* get_first_name() const;
	const char* get_last_name() const;

private:
	long long id;
	long long films;
	char* first_name;
	char* last_name;

	void free();
	void copy(const Actor&);
};

std::ostream& operator<<(std::ostream&, const Actor&);

#endif