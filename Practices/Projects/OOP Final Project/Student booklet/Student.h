#pragma once

#include <iostream>
#include <fstream>

#include "String.h"

class Student
{
public:
	Student();
	Student(const int, const String&, const String&);
	Student(const Student&);
	~Student();

	Student& operator=(const Student&);
	
	int get_faculty_number() const;
	const String* get_first_name() const;
	const String* get_last_name() const;

	void set_faculty_number(const int);
	void set_first_name(const String&);
	void set_last_name(const String&);

private:
	int faculty_number;
	String first_name;
	String last_name;

	void copy(const Student&);
	void free();
};

void save_to_file(const char*, const Student&);
void read_from_file(std::ifstream&, Student&);

std::istream& operator>>(std::istream&, Student&);
std::ostream& operator<<(std::ostream&, const Student&);