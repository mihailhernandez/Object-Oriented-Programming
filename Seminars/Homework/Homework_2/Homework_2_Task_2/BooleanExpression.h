#pragma once

#include <iostream>

class BooleanExpression
{
public:
	virtual void print()            const = 0;
	virtual bool is_contingency()   const = 0;
	virtual bool is_tauthology()    const = 0;
	virtual bool is_contradiction() const = 0;
	void print_all()			    const;
};