#pragma once

#include <iostream>

class String
{
public:
	String();
	~String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String& operator+=(const String&);
	const char* get_string() const;
	const char operator[](const int) const;
	friend std::ostream& operator<<(std::ostream&, const String&);

private:
	char* str;
	int len;
	void copy_from(const String&);
	void free();
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);