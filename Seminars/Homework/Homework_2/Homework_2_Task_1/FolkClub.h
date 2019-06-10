#pragma once

#include "Club.h"

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

	bool add_to_club(const User&);

private:
	String singer;

	void free();
	void copy_from(const FolkClub&);
};