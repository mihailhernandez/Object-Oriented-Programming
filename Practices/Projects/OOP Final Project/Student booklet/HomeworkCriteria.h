#pragma once

#include <fstream>

#include "DynamicArray.h"
#include "Criteria.h"

class HomeworkCriteria : public Criteria
{
public:
	HomeworkCriteria();
	HomeworkCriteria(const char*, const double);
	HomeworkCriteria(const HomeworkCriteria&);
	~HomeworkCriteria();

	HomeworkCriteria* operator=(const HomeworkCriteria*);

	void print() const;
	double calculate() const;

	const DynamicArray<int>& get_grades() const;
	void set_grades(const DynamicArray<int>&);

	void save_to_file(const char*) const;
	std::ios_base::streampos& read_from_file(const char*, std::ios_base::streampos&);

private:
	DynamicArray<int> grades;

	void copy_from(const HomeworkCriteria&);
};