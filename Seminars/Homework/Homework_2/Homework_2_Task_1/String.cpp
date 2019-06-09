#include "String.h"

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
	copy_from(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy_from(other);
	}
	return *this;
}

String::~String()
{
	free();
}

void String::copy_from(const String& other)
{
	str = new char[other.len + 1];
	strcpy(str, other.str);
	len = other.len;
}

void String::free()
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

const char* String::get_string() const
{
	return str;
}

std::ostream & operator<<(std::ostream & stream, const String & str)
{
	for (int i = 0; i < str.len; i++)
		stream << str[i];
	return stream;
}

const char String::operator[](const int index) const
{
	return this->str[index];
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.get_string(), rhs.get_string()) == 0;
}


bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}