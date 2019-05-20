#pragma once

#include <iostream>

class Expression
{
public:
	virtual void print() const = 0;
	virtual int evaluate() const = 0;
	virtual ~Expression() = 0;
};