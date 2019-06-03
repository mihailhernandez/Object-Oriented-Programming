#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

#include "CriteriaFactory.h"
#include "DynamicArray.h"
#include "Criteria.h"

class Student
{
public:
	Student();
	Student(const int, const char*, const char*);
	Student(const Student&);
	~Student();

	Student& operator=(const Student&);
	
	int get_faculty_number() const;
	const char* get_first_name() const;
	const char* get_last_name() const;
	const DynamicArray<Criteria*>& get_criterias() const;

	void set_faculty_number(const int);
	void set_first_name(const char*);
	void set_last_name(const char*);
	void set_criterias(const DynamicArray<Criteria*>&);
	
	virtual void save_to_file(const char*) const;
	virtual std::ios_base::streampos& read_from_file(const char*, std::ios_base::streampos&);

	void print() const;
protected:

	int faculty_number;
	char* first_name;
	char* last_name;
	DynamicArray<Criteria*> criterias;

	void copy_from(const int, const char*, const char*);
	void free();

	void save_student_basic_info(const char*) const;
	void save_criteria_info(const char*) const;

	std::ios_base::streampos& read_criterias_from_file(const char*, std::ios_base::streampos&);
	std::ios_base::streampos& read_student_info_from_file(const char*, std::ios_base::streampos&);
};

std::ostream& operator<<(std::ostream&, const Student&);