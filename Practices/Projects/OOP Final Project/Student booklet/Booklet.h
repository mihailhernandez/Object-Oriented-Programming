#pragma once

#include "Student.h"
#include "Criteria.h"
#include "Common.h"

class Booklet
{
public:
	Booklet();
	Booklet(const char*);
	~Booklet();
	void extract();
	void save() const;
	void calculate();
	void set_students(const Student**);

private:

	Student** students;
	Criteria** criterias;

	void save_students() const
	{
	}
};
