#include <iostream>
#include <cstring>
#include <math.h>

const unsigned int MAX_NAME_LEN    = (unsigned int) pow(2, 8);
const unsigned long long MAX_ID    = (unsigned long long) pow(2, 50);
const unsigned long long MAX_FILMS = (unsigned long long) pow(2, 50);

class Movie_Star
{
public:
	Movie_Star() {}
	Movie_Star(const unsigned long long id, const char* first_name, 
					const char* last_name, const unsigned long long films)
	{
		set_id(id);
		set_first_name(first_name);
		set_last_name(last_name);
		set_films(films);
	}

	void set_id(const unsigned long long id)
	{
		if (id < 0)
			this->id = 0;
		else if (id >= MAX_ID)
			this->id = MAX_ID;
		else
			this->id = id;
	}	

	void set_first_name(const char* first_name)
	{
		strcpy(this->first_name, first_name);
	}
	
	void set_last_name(const char* last_name)
	{
		strcpy(this->last_name, last_name);
	}

	void set_films(const unsigned long long films)
	{
		if (films < 0)
			this->films = 0;
		else if (films >= MAX_FILMS)
			this->films = MAX_FILMS;
		else 
			this->films = films;
	}

	unsigned long long get_films() const
	{
		return films;
	}

	unsigned long long get_id() const
	{
		return id;
	}

	char* get_first_name() const
	{
		char* name_cpy = new char[strlen(first_name)];
		strcpy(name_cpy, first_name);
		return name_cpy;
	}

	char* get_last_name() const
	{
		char* name_cpy = new char[strlen(last_name)];
		strcpy(name_cpy, last_name);
		return name_cpy;
	}
private:
	unsigned long long id;
	unsigned long long films;
	char first_name[MAX_NAME_LEN];
	char last_name[MAX_NAME_LEN];
};

std::ostream& operator<<(std::ostream& os, Movie_Star actor)
{
	char* first_name = actor.get_first_name();
	char* last_name = actor.get_last_name();
	os << actor.get_id() << " " << first_name 
			<< " " << last_name  << " " << actor.get_films() << std::endl;
	delete[] first_name;
	delete[] last_name;
	return os;
}
