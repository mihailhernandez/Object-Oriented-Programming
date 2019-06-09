#include "User.h"
#include "Music.h"

User::User() : name("default"), age(18), budget(0), whiskeys(0), vodkas(0), music(Music::ALL) {}

User::User(const String& name, const int age, const int budget, 
		const int vodkas, const int whiskeys, const String& music)
{
	set_name(name);
	set_age(age);
	set_budget(budget);
	set_vodkas(vodkas);
	set_whiskeys(whiskeys);
	set_music(music);
}

User::User(const User& user)
{
	copy_from(user);
}

User::~User()
{
	free();
}

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		free();
		copy_from(user);
	}
	return *this;
}

const String& User::get_name() const
{
	return name;
}

const String& User::get_music() const
{
	return music;
}

int User::get_budget() const
{
	return budget;
}

int User::get_vodkas() const
{
	return vodkas;
}

int User::get_whiskeys() const
{
	return whiskeys;
}

int User::get_age() const
{
	return age;
}

void User::set_name(const String& name)
{
	this->name = name;
}

void User::set_music(const String& music)
{
	this->music = music;
}

void User::set_budget(const int budget)
{
	this->budget = budget;
}

void User::set_vodkas(const int vodkas)
{
	this->vodkas = vodkas;
}

void User::set_whiskeys(const int whiskeys)
{
	this->whiskeys = whiskeys;
}

void User::set_age(const int age)
{
	this->age = age;
}

void User::free()
{
	// nothing to free. String has it's destructor
}

void User::copy_from(const User& user)
{
	set_name(user.get_name());
	set_age(user.get_age());
	set_music(user.get_music());
	set_whiskeys(user.get_whiskeys());
	set_vodkas(user.get_vodkas());
	set_budget(user.get_budget());
}