#pragma once

#include "Operation.h"

class Conjunction : public Operation
{
public:
	Conjunction(BooleanExpression*, BooleanExpression*);
	Conjunction(const Conjunction&);
	Conjunction& operator=(const Conjunction&);

	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};