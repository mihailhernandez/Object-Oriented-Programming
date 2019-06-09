#pragma once

#include "Club.h"

const int MINIMUM_VODKA_PRICE = 20;
const int MINIMUM_

class FolkClub : public Club
{
public:
	FolkClub();
	FolkClub(const String&, const int, const int, const String&);
	FolkClub(const FolkClub&);
	~FolkClub();

	FolkClub& operator=(const FolkClub&);

	const String& get_singer() const;
	void set_singer(const String&);
	void set_vodka_price(const int);
	void set_whiskey_price(const int);

	bool add_to_club(const User&);

private:
	String singer;

	void free();
	void copy_from(const FolkClub&);
};