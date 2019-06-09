#include "Club.h"
#include "Music.h"

Club::Club() : name("default"), capacity(INITIAL_SIZE), size(0), vodka_price(10), whiskey_price(10), music(Music::ALL) 
{
	users = new User[this->capacity];
}

Club::Club(const String& name, const int capacity, const int vodka_price, const int whiskey_price, const String& music)
{
	set_name(name);
	set_capacity(capacity);
	set_vodka_price(vodka_price);
	set_whiskey_price(capacity);
	set_music(music);
	this->size = 0;
	this->users = new User[this->capacity];
}

Club::Club(const Club& club)
{
	copy_from(club);
}

Club::~Club()
{
	free();
}

Club& Club::operator=(const Club& club)
{
	if (this != &club)
	{
		free();
		copy_from(club);
	}
	return *this;
}

const String& Club::get_name() const
{
	return name;
}

const String& Club::get_music() const
{
	return music;
}

const User* Club::get_users() const
{
	return users;
}

const int Club::get_capacity() const
{
	return capacity;
}

int Club::get_vodka_price() const
{
	return vodka_price;
}

int Club::get_whiskey_price() const
{
	return whiskey_price;
}

void Club::set_name(const String& name)
{
	this->name = name;
}

void Club::set_music(const String& music)
{
	this->music = music;
}

void Club::set_users(const User* users)
{
	this->users = new User[capacity];
	for (int i = 0; i < size; i++)
		this->users[i] = users[i];
}

void Club::set_capacity(const int capacity)
{
	if (capacity >= 0)
		this->capacity = capacity;
}

void Club::set_vodka_price(const int vodka_price)
{
	if (vodka_price >= 0)
		this->vodka_price = vodka_price;
}

void Club::set_whiskey_price(const int whiskey_price)
{
	if (whiskey_price >= 0)
		this->whiskey_price = whiskey_price;
}

bool Club::add_to_club(const User& user)
{
	int price = user.get_vodkas() * vodka_price + user.get_whiskeys() * whiskey_price;
	if (user.get_age() < 18)
		price += 20;
	if (price > user.get_budget())
	{
		std::cout << "Not enough budget for " << user.get_name() << " to enter " << name << std::endl;
		return false;
	}
	if (capacity == size)
	{
		std::cout << "Club " << name << " is full!" << std::endl;
		return false;
	}
	users[size++] = user;
	return true;
}

bool Club::remove_from_club(const String& name)
{
	for (int i = 0; i < size; i++)
		if (name == users[i].get_name())
		{
			for (int j = i; j < size - 1; j++)
				users[j] = users[j + 1];
			size--;
			return true;
		}
	return false;
}

void Club::free()
{
	delete[] users;
}

void Club::copy_from(const Club& club)
{
	set_music(club.get_music());
	set_capacity(club.get_capacity());
	set_users(club.get_users());
	set_whiskey_price(club.get_whiskey_price());
	set_vodka_price(club.get_vodka_price());
	this->size = club.size;
}
