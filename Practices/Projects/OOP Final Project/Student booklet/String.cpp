#include "String.h"
#include <cstring>

String::String() : string(new char[0]), length(0) {}

String::String(const char* string)
{
	this->length = strlen(string);
	this->string = new char[this->length + 1];
	strcpy(this->string, string);
}

String::String(const String& other)
{
	copy_from(other);
}

String::~String()
{
	free();
}

String& String::operator=(const String& string)
{
	copy_from(string);
}

String& String::operator+=(const String& string)
{
	char* temp = new char[this->length + string.length + 1];
	for (int i = 0; i < this->length; i++)
		temp[i] = this->string[i];
	for (int i = 0; i < string.length; i++)
		temp[this->length] = string.string[i];
	this->length += string.length;
	temp[this->length] = '\0';
	delete[] this->string;
	this->string = temp;
}

String String::operator+(const String& string)
{
	String str(*this);
	str += string;
	return str;
}

const char String::operator[](const int index) const
{
	return this->string[index];
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.string;
	return stream;
}

void String::free()
{
	delete[] string;
	length = 0;
}

void String::copy_from(const String& string)
{
	this->string = new char[string.length + 1];
	strcpy(this->string, string.string);
	this->length = string.length;