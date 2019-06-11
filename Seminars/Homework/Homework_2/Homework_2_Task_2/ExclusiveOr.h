#pragma once

#include "Operation.h"

class ExclusiveOr : public Operation
{
public:
	ExclusiveOr(BooleanExpression*, BooleanExpression*);
	ExclusiveOr(const ExclusiveOr&);
	ExclusiveOr& operator=(const ExclusiveOr&);

	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};