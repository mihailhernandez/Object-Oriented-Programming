#pragma once

#include <iostream>
#include <fstream>

class Student
{
public:
	Student();
	Student(const int, const char*, const char*);
	~Student();

	Student(const Student&);
	Student& operator=(const Student&);
	
	int get_faculty_number() const;
	const char* get_first_name() const;
	const char* get_last_name() const;

	void set_faculty_number(const unsigned int);
	void set_first_name(const char*);
	void set_last_name(const char*);
	
private:
	int faculty_number;
	char* first_name;
	char* last_name;

	void copy(const Student&);
	void free();
};

std::istream& operator>>(std::istream&, Student&);
std::ostream& operator<<(std::ostream&, const Student&);
std::ifstream& operator>>(std::ifstream&, Student&);
std::ofstream& operator<<(std::ofstream&, const Student&);

std::istream& operator>>(std::istream&, Student*);
std::ostream& operator<<(std::ostream&, const Student*);
std::ifstream& operator>>(std::ifstream&, Student*);
std::ofstream& operator<<(std::ofstream&, const Student*);
