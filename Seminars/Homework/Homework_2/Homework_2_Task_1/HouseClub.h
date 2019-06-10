#pragma once

#include "Club.h"

class HouseClub : public Club
{
public:
	HouseClub();
	HouseClub(const String&, const int, const int, const int);
	HouseClub(const HouseClub&);
	~HouseClub();

	HouseClub& operator=(const HouseClub&);

	bool add_to_club(const User&);

	void set_dj_count(const int);
	int get_dj_count() const;

private:
	int dj_count;
	void free();
	void copy_from(const HouseClub&);
};