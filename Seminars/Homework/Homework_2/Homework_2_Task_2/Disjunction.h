#pragma once

#include "Operation.h"

class Disjunction : public Operation
{
public:
	Disjunction(BooleanExpression*, BooleanExpression*);
	Disjunction(const Disjunction&);
	Disjunction& operator=(const Disjunction&);

	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};