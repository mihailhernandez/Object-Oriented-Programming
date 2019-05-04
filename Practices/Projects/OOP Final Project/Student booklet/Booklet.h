#pragma once

#include "Student.h"
#include "Criteria.h"

class Booklet
{
public:
	Booklet(const char*);
	~Booklet();
	void extract();
	void save() const;
	void calculate();

private:
	Student** students;
	Criteria** criterias;
};
