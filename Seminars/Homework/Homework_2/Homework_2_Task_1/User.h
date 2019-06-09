#pragma once

#include "String.h"

class User
{
public:
	User();
	User(const String&, const int, const int, const int, const int, const String&);
	User(const User&);
	~User();

	User& operator=(const User&);

	const String& get_name() const;
	const String& get_music() const;
	int get_budget() const;
	int get_vodkas() const;
	int get_whiskeys() const;
	int get_age() const;

	void set_name(const String&);
	void set_music(const String&);
	void set_budget(const int);
	void set_vodkas(const int);
	void set_whiskeys(const int);
	void set_age(const int);

private:
	String music;
	String name;
	int age;
	int budget;
	int vodkas;
	int whiskeys;

	void free();
	void copy_from(const User&);
};
