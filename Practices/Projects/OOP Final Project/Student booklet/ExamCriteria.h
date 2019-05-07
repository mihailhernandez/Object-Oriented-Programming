#pragma once
#include "Criteria.h"

class ExamCriteria : public Criteria
{
public:
	Criteria* get_instance();
	double calculate() const;
private:
	ExamCriteria();
};

