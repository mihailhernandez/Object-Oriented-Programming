#pragma once

#include "String.h"
#include "User.h"
#include "Music.h"

const unsigned int INITIAL_SIZE = 4;
const unsigned int RESIZE_BY = 2;

class Club
{
public:
	Club();
	Club(const String&, const int, const int, const int, const String&);
	Club(const Club&);
	~Club();

	Club& operator=(const Club&);

	const String& get_name() const;
	const String& get_music() const;
	const User* get_users() const;
	const int get_capacity() const;
	int get_vodka_price() const;
	int get_whiskey_price() const;

	void set_name(const String&);
	void set_music(const String&);
	void set_users(const User*);
	void set_capacity(const int);
	void set_vodka_price(const int);
	void set_whiskey_price(const int);

	virtual bool add_to_club(const User&);
	bool remove_from_club(const String&);

private:
	String music;
	String name;
	User* users;
	int size;
	int capacity;
	int vodka_price;
	int whiskey_price;

	void free();
protected:
	void copy_from(const Club&);
};