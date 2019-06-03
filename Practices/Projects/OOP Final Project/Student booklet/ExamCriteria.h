#pragma once

#include "Criteria.h"

class ExamCriteria : public Criteria
{
public:
	ExamCriteria();
	ExamCriteria(const char*, const double);
	ExamCriteria(const ExamCriteria&);
	~ExamCriteria();

	ExamCriteria* operator=(const ExamCriteria*);
	
	void save_to_file(const char*) const;
	std::ios_base::streampos& read_from_file(const char*, std::ios_base::streampos&);
	double calculate() const;
	void print() const;

	void set_points(const int points);
	int get_points() const;

private:
	int points;
	
	void copy_from(const ExamCriteria&);
};