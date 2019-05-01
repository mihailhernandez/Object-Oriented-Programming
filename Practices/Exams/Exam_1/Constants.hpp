#ifndef __CONSTANTS__
#define __CONSTANTS__

namespace Constants
{
	/* String constants. */
	static const char* CREATE = "create";
	static const char* SEARCH = "search";
	static const char* EXIT = "exit";

	static const char* DATABASE_NAME = "Films.db";

	/* Number constants. */
	static const unsigned int MAX_COMMAND_LENGHT = 256;

	static const unsigned int MAX_NAME_LEN =    (unsigned int) pow(2, 8);
	static const unsigned long long MAX_ID =    (unsigned long long) pow(2, 50);
	static const unsigned long long MAX_FILMS = (unsigned long long) pow(2, 50);
}

#endif