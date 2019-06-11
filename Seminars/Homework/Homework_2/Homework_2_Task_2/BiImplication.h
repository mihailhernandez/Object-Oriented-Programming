#pragma once

#include "Operation.h"

class BiImplication : public Operation
{
public:
	BiImplication(BooleanExpression*, BooleanExpression*);
	BiImplication(const BiImplication&);
	BiImplication& operator=(const BiImplication&);

	bool is_contingency()   const;
	bool is_tauthology()    const;
	bool is_contradiction() const;
};