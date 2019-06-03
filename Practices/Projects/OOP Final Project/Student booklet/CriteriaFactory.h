#pragma once

#include "HomeworkCriteria.h"
#include "ExamCriteria.h"
#include "Criteria.h"

class CriteriaFactory
{
public:
	static Criteria* create(const int);
};