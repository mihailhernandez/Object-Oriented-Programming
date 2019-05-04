#pragma once

namespace Constants
{
	static const unsigned int MAX_FIRST_NAME_LENGTH = 255;
	static const unsigned int MAX_LAST_NAME_LENGTH = 255;

	static const double MIN_WEIGHT = 0;
}

namespace Utils
{
	char* copy_string(const char*);
}