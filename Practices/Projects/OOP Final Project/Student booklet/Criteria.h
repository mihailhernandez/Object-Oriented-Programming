#pragma once

#include <fstream>
#include <iostream>

namespace CriteriaIdentifiers
{
	const int HOMEWORK_CRITERIA_IDENTIFIER = 1;
	const int EXAM_CRITERIA_IDENTIFIER = 2;
};

class Criteria
{
public:
	virtual void print() const = 0;
	virtual double calculate() const = 0;
	virtual ~Criteria();

	void set_criteria_name(const char*);
	void set_weight(const double);

	const char* get_criteria_name() const;
	double get_weight() const;

	virtual void save_to_file(const char*) const;
	virtual std::ios_base::streampos& read_from_file(const char*, std::ios_base::streampos&);

protected:
	Criteria();
	Criteria(const char*, const double);
	char* criteria_name;
	double weight;

	void save_identifier(const char*, const int) const;
	void copy_from(const char*, const double);

	void free();
};