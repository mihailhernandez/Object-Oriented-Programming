#include "String.hpp"

String::String()
{
	str = new char[1];
	str[0] = '\0';
	len = 1;
}

String::String(const char* str)
{
	len = strlen(str);
	this->str = new char[len + 1];
	strcpy(this->str, str);
}
String operator+(const String& lhs, const String& rhs)
{
	String temp(lhs);
	temp += rhs;
	return temp;
}
String::String(const String& other)
{
	CopyFrom(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
String::~String()
{
	Free();
}
void String::CopyFrom(const String& other)
{
	str = new char[other.len + 1];
	strcpy(str, other.str);
	len = other.len;
}
void String::Free()
{
	delete[] str;
}

String& String::operator+=(const String& other)
{
	char* temp = new char[len + other.len + 1];
	for (int i = 0; i < len; i++)
		temp[i] = str[i];
	for (int i = 0; i < other.len; i++)
		temp[len + i] = other.str[i];
	temp[len + other.len] = '\0';
	delete[] str;
	str = temp;
	len += other.len;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	for (int i = 0; i < str.len; i++)
		stream << str[i];
	return stream;
}

const char String::operator[](const int index) const
{
	return this->str[index];
}
