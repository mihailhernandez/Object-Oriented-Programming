#include "Actor.hpp"

Actor::Actor() : id(0), first_name(nullptr), last_name(nullptr), films(0) {}

Actor::Actor(const Actor& other) : id(0), first_name(nullptr), last_name(nullptr), films(0)
{
	copy(other);
}

Actor::Actor(const long long id, const char* first_name,
	const char* last_name, const long long films)
	: id(0), first_name(nullptr), last_name(nullptr), films(0)
{
	set_id(id);
	set_first_name(first_name);
	set_last_name(last_name);
	set_films(films);
}

Actor::~Actor()
{
	free();
}

Actor& Actor::operator=(const Actor& other)
{
	copy(other);
	return *this;
}

void Actor::set_id(const long long id)
{
	if (id < 0)
		this->id = 0;
	else if (id >= Constants::MAX_ID)
		this->id = Constants::MAX_ID;
	else
		this->id = id;
}

void Actor::set_first_name(const char* first_name)
{
	if (this->first_name != nullptr)
		delete[] this->first_name;
	this->first_name = new char[strlen(first_name) + 1];
	strcpy(this->first_name, first_name);
}

void Actor::set_last_name(const char* last_name)
{
	if (this->last_name != nullptr)
		delete[] this->last_name;
	this->last_name = new char[strlen(last_name) + 1];
	strcpy(this->last_name, last_name);
}

void Actor::set_films(const long long films)
{
	if (films < 0)
		this->films = 0;
	else if (films >= Constants::MAX_FILMS)
		this->films = Constants::MAX_FILMS;
	else
		this->films = films;
}

long long Actor::get_films() const
{
	return this->films;
}

long long Actor::get_id() const
{
	return this->id;
}

const char* Actor::get_first_name() const
{
	return first_name;
}

const char* Actor::get_last_name() const
{
	return last_name;
}

void Actor::copy(const Actor& other)
{
	set_id(other.get_id());
	set_first_name(other.get_first_name());
	set_last_name(other.get_last_name());
	set_films(other.get_films());
}

void Actor::free()
{
	delete[] first_name;
	delete[] last_name;
}

std::ostream& operator<<(std::ostream& stream, const Actor& actor)
{
	stream << actor.get_id() << " " << actor.get_first_name() 
		<< " " << actor.get_last_name() << " " << actor.get_films() << std::endl;
	return stream;
}