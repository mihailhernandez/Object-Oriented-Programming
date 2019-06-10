#include "HouseClub.h"

HouseClub::HouseClub() : Club("default", 1000, 30, 40, Music::HOUSE), dj_count(0) {}

HouseClub::HouseClub(const String& name, const int vodka_price, const int whiskey_price, const int dj_count)
	: Club(name, 30, vodka_price, whiskey_price, Music::HOUSE), dj_count(dj_count) {}

HouseClub::HouseClub(const HouseClub& house_club) : Club(house_club)
{
	copy_from(house_club);
}

HouseClub::~HouseClub()
{
	free();
}

HouseClub& HouseClub::operator=(const HouseClub& house_club)
{
	if (this != &house_club)
	{
		free();
		copy_from(house_club);
	}
	return *this;
}

bool HouseClub::add_to_club(const User& user)
{
	if (user.get_music() == Music::HOUSE)
	{
		std::cout << user.get_name() << " hates " << get_music() << std::endl;
		return false;
	}
	return Club::add_to_club(user);
}

void HouseClub::set_dj_count(const int dj_count)
{
	if (dj_count < 0)
		this->dj_count = 0;
	else
		this->dj_count = dj_count;
}

int HouseClub::get_dj_count() const
{
	return dj_count;
}

void HouseClub::free()
{
	// nothing to free
}

void HouseClub::copy_from(const HouseClub& house_club)
{
	Club::copy_from(house_club);
	set_dj_count(house_club.get_dj_count());
}
