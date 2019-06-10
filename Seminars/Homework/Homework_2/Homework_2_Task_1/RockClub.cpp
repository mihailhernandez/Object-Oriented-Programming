#include "RockClub.h"

RockClub::RockClub() : Club("default", 30, 40, 30, Music::ROCK) {}

RockClub::RockClub(const String& name, const int vodka_price, const int whiskey_price)
	: Club(name, 30, vodka_price, whiskey_price, Music::ROCK) {}

RockClub::RockClub(const RockClub& rock_club) : Club(rock_club)
{
	copy_from(rock_club);
}

RockClub::~RockClub()
{
	free();
}

RockClub& RockClub::operator=(const RockClub& rock_club)
{
	if (this != &rock_club)
	{
		free();
		copy_from(rock_club);
	}
	return *this;
}

bool RockClub::add_to_club(const User& user)
{
	if (user.get_music() == Music::HOUSE)
	{
		std::cout << user.get_name() << " hates " << get_music() << std::endl;
		return false;
	}
	return Club::add_to_club(user);
}

void RockClub::free()
{
	// nothing to free
}

void RockClub::copy_from(const RockClub& rock_club)
{
	Club::copy_from(rock_club);
}
