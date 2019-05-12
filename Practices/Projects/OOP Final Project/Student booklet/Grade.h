#pragma once

#include "Criteria.h"

class Grade
{
public:
	Grade(const Criteria*, const int);
	const Criteria* get_criteria() const;
	int get_grade() const;
	void set_criteria(const Criteria*);
	void set_grade(const int);
private:
	Criteria* criteria;
	int grade;
};