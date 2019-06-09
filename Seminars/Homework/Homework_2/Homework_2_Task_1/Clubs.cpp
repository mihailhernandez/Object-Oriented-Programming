#include "Clubs.h"
#include "FolkClub.h"
#include "RockClub.h"
#include "HouseClub.h"

Clubs::Clubs() : size(0), capacity(INITIAL_SIZE), clubs(new Club*[INITIAL_SIZE]) {}

Clubs::Clubs(const int capacity): size(0), capacity(capacity), clubs(new Club*[capacity]) {}

Clubs::Clubs(const Clubs& clubs)
{
	copy_from(clubs);
}

Clubs::~Clubs()
{
	free();
}

Clubs& Clubs::operator=(const Clubs& clubs)
{
	if (this != &clubs)
	{
		free();
		copy_from(clubs);
	}
	return *this;
}

const Club** Clubs::get_clubs() const
{
	return clubs;
}

bool Clubs::add_folk_club(const String& name, const int vodka_price, const int whiskey_price, const String& singer)
{
	if (vodka_price < 20 || whiskey_price < 35)
		return false;
	add_club(new FolkClub(name, vodka_price, whiskey_price, singer));
	return true;
}

bool Clubs::add_house_club(const String& name, const int vodka_price, const int whiskey_price, const int dj_count)
{
	if (vodka_price < 30 || whiskey_price < 40)
		return false;
	add_club(new HouseClub(name, vodka_price, whiskey_price, dj_count));
	return true;
}

bool Clubs::add_rock_club(const String& name, const int vodka_price, const int whiskey_price)
{
	if (vodka_price < 20 || whiskey_price < 35)
		return false;
	add_club(new RockClub(name, vodka_price, whiskey_price));
	return true;
}

bool Clubs::remove_club(const String& name)
{
	for (int i = 0; i < size; i++)
		if (name == clubs[i]->get_name())
		{
			delete clubs[i];
			for (int j = i; j < size - 1; j++)
				clubs[j] = clubs[j + 1];
			std::cout << "Removed club " << name << std::endl;
			return true;
		}
	std::cout << "Cannot find club " << name << std::endl;
	return false;
}

bool Clubs::add_to_club(const User& user, const String& club_name)
{
	for (int i = 0; i < size; i++)
		if (club_name == clubs[i]->get_name())
			return clubs[i]->add_to_club(user);
	std::cout << "Cannot find club " << club_name << std::endl;
	return false;
}

bool Clubs::remove_from_club(const String&, const String&)
{
	return false;
}

void Clubs::add_club(Club* club)
{
	if (size == capacity)
		resize();
	clubs[size++] = club;
	std::cout << "Added club " << club->get_name() << std::endl;
}

void Clubs::free()
{
	for (int i = 0; i < size; i++)
		delete clubs[i];
	delete[] clubs;
}

void Clubs::resize()
{

}

void Clubs::copy_from(const Clubs& clubs)
{
	this->size = clubs.size;
	this->capacity = clubs.capacity;
	this->clubs = new Club * [capacity];
	for (int i = 0; i < size; i++)
		this->clubs[i] = clubs.clubs[i];
}
