#pragma once
#include "Criteria.h"

class ExamCriteria : public Criteria
{
public:
	ExamCriteria();
	~ExamCriteria();
	double calculate() const;
};

