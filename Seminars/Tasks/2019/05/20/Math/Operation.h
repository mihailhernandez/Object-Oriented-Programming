#pragma once

#include "Expression.h"

class Operation : public Expression
{
public:
	Operation(Expression*, char, Expression*);
	void print() const;
	int evaluate() const;
private:
	Expression* left;
	Expression* right;
	char operation;
};