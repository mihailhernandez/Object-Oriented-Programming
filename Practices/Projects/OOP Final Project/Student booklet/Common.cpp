#include "Common.h"
#include <cstring>

char* copy_string(const char* other_string)
{
	char* copy = new char[strlen(other_string) + 1];
	strcpy_s(copy, strlen(other_string) + 1, other_string);
	return copy;
}