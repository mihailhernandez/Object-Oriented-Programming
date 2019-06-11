#pragma once

#include "Operation.h"

class Implication : public Operation
{
public:
	Implication(BooleanExpression*, BooleanExpression*);
	Implication(const Implication&);
	Implication& operator=(const Implication&);

	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};