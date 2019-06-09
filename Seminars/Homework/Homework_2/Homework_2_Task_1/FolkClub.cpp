#include "FolkClub.h"

FolkClub::FolkClub() : Club("default", 70, 20, 35, Music::FOLK), singer("default") {}

FolkClub::FolkClub(const String& name, const int vodka_price, const int whiskey_price, const String& singer) 
	: Club(name, 70, vodka_price, whiskey_price, Music::FOLK), singer(singer) {}

FolkClub::FolkClub(const FolkClub& folk_club) : Club(folk_club)
{
	copy_from(folk_club);
}

FolkClub::~FolkClub()
{
	free();
}

FolkClub& FolkClub::operator=(const FolkClub& folk_club)
{
	if (this != &folk_club)
	{
		free();
		copy_from(folk_club);
	}
	return *this;
}

const String& FolkClub::get_singer() const
{
	return singer;
}

void FolkClub::set_singer(const String& singer)
{
	this->singer = singer;
}

void FolkClub::set_vodka_price(const int vodka_price)
{
	if (vodka_price <)
}

bool FolkClub::add_to_club(const User& user)
{
	if (user.get_music() == Music::ROCK)
	{
		std::cout << user.get_name() << " hates " << get_music() << std::endl;
		return false;
	}
	return add_to_club(user);
}

void FolkClub::free()
{
	// nothing to free
}

void FolkClub::copy_from(const FolkClub& folk_club)
{
	Club::copy_from(folk_club);
	set_singer(folk_club.singer);
}
