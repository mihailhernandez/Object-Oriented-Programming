#pragma once

#include "Club.h"

class RockClub : public Club
{
public:
	RockClub();
	RockClub(const String&, const int, const int);
	RockClub(const RockClub&);
	~RockClub();

	RockClub& operator=(const RockClub&);

	bool add_to_club(const User&);

private:
	void free();
	void copy_from(const RockClub&);
};