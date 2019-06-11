#pragma once

#include "Operation.h"

class Negation : public Operation
{
public:
	Negation(BooleanExpression*);
	Negation(const Negation&);
	Negation& operator=(const Negation&);

	void print()            const;
	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};