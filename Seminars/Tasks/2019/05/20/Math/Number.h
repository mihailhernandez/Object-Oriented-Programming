#pragma once

#include "Expression.h"

class Number : public Expression
{
public:
	Number(const int);
	void print() const;
	int evaluate() const;
private:
	int number;
};