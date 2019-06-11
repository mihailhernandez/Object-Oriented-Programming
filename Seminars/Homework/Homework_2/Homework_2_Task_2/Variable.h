#pragma once

#include "Operation.h"

/*   Proposition   */
const char DEFAULT_BOOLEAN_VARIABLE_SYMBOL = 'p';

class Variable : public BooleanExpression
{
public:
	Variable(const char);
	Variable(const Variable&);
	Variable& operator=(const Variable&);

	void set_symbol(const char);
	char get_symbol() const;

	void print() const;
	bool is_contingency()    const;
	bool is_tauthology()     const;
	bool is_contradiction()  const;
	int get_number_of_vars() const;
private:
	char symbol;
};

bool operator==(const Variable&, const Variable&);