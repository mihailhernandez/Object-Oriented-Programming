#include "Actor.hpp"

Actor::Actor() : id(0), first_name(nullptr), last_name(nullptr), films(0) {}

Actor::Actor(const unsigned long long id, const char* first_name, 
	const char* last_name, const unsigned long long films)
{
	set_id(id);
	set_first_name(first_name);
	set_last_name(last_name);
	set_films(films);
}

Actor::~Actor()
{
	delete[] first_name;
	delete[] last_name;
}

void Actor::set_id(const unsigned long long id)
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

void Actor::set_films(const unsigned long long films)
{
	if (films < 0)
		this->films = 0;
	else if (films >= Constants::MAX_FILMS)
		this->films = Constants::MAX_FILMS;
	else
		this->films = films;
}

unsigned long long Actor::get_films() const
{
	return this->films;
}

unsigned long long Actor::get_id() const
{
	return this->id;
}

char* Actor::get_first_name() const
{
	char* name_cpy = new char[strlen(this->first_name) + 1];
	strcpy(name_cpy, this->first_name);
	return name_cpy;
}

char* Actor::get_last_name() const
{
	char* name_cpy = new char[strlen(this->last_name) + 1];
	strcpy(name_cpy, this->last_name);
	return name_cpy;
}

std::istream& operator>>(std::istream& is, Actor& actor)
{
	unsigned long long id;
	unsigned long long films;
	char* first_name = new char[Constants::MAX_NAME_LEN];
	char* last_name = new char[Constants::MAX_NAME_LEN];
	is >> id >> first_name >> last_name >> films;
	actor.set_id(id);
	actor.set_first_name(first_name);
	actor.set_last_name(last_name);
	actor.set_films(films);
	delete[] first_name;
	delete[] last_name;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Actor& actor)
{
	char* first_name = actor.get_first_name();
	char* last_name = actor.get_last_name();
	std::cout << actor.get_id() << " "
		<< first_name << " "
		<< last_name << " "
		<< actor.get_films() << std::endl;
	delete[] first_name;
	delete[] last_name;
	return os;
}

std::ofstream& operator<<(std::ofstream& os, const Actor& actor)
{
	unsigned long long id = actor.get_id();
	unsigned long long films = actor.get_films();
	char* first_name = actor.get_first_name();
	char* last_name = actor.get_last_name();
	unsigned int first_name_len = strlen(first_name) + 1;
	unsigned int last_name_len = strlen(last_name) + 1;
	os.write((const char*)& id, sizeof(unsigned long long))
		.write((const char*)& first_name_len, sizeof(unsigned int))
		.write((const char*)& first_name, sizeof(char) * first_name_len)
		.write((const char*)& last_name_len, sizeof(unsigned int))
		.write((const char*)& last_name, sizeof(char) * last_name_len)
		.write((const char*)& films, sizeof(unsigned long long));
	delete[] first_name;
	delete[] last_name;
	return os;
}

std::ifstream& operator>>(std::ifstream& is, Actor& actor)
{
	unsigned long long id;
	unsigned long long films;
	unsigned int first_name_len;
	unsigned int last_name_len;
	is.read((char*)& id, sizeof(unsigned long long))
		.read((char*)& first_name_len, sizeof(unsigned int));
	char* first_name = new char[first_name_len + 1];
	is.read((char*)& first_name, sizeof(char) * first_name_len)
		.read((char*)& last_name_len, sizeof(unsigned int));
	char* last_name = new char[last_name_len + 1];
	is.read((char*)& last_name, sizeof(char) * last_name_len)
		.read((char*)& films, sizeof(unsigned long long));
	first_name[first_name_len + 1] = '\0';
	last_name[last_name_len + 1] = '\0';
	actor.set_id(id);
	actor.set_first_name(first_name);
	actor.set_last_name(last_name);
	actor.set_films(films);
	delete[] first_name;
	delete[] last_name;
	return is;
}