#pragma once

#include <iostream>

class String
{
private:
	char* str;
	int len;
	void CopyFrom(const String&);
	void Free();
public:
	String();
	~String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String& operator+=(const String&);
	const char operator[](const int) const;
	friend std::ostream& operator<<(std::ostream&, const String&);
};