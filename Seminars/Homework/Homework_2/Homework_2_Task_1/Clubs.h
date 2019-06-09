#pragma once

#include "User.h"
#include "Club.h"

class Clubs
{
public:
	Clubs();
	Clubs(const int);
	Clubs(const Clubs&);
	~Clubs();

	Clubs& operator=(const Clubs&);

	const Club** get_clubs() const;

	bool add_folk_club(const String&, const int, const int, const String&);
	bool add_house_club(const String&, const int, const int, const int);
	bool add_rock_club(const String&, const int, const int);

	bool remove_club(const String&);

	bool add_to_club(const User&, const String&);
	bool remove_from_club(const String&, const String&);

private:
	int size;
	int capacity;
	Club** clubs;

	void add_club(Club*);

	void free();
	void resize();
	void copy_from(const Clubs&);
};