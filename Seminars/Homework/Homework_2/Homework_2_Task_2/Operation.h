#pragma once 

#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
public:
	Operation(BooleanExpression*, const char*, BooleanExpression*);
	Operation(const Operation&);
	Operation& operator=(const Operation&);
	~Operation();

	const char* get_symbol() const;
	void set_symbol(const char*);

	BooleanExpression* get_left() const;
	BooleanExpression* get_right() const;

	void set_left(BooleanExpression*);
	void set_right(BooleanExpression*);

	void print() const;
	int get_number_of_vars() const;

protected:
	void copy(const Operation&);

private:
	const char* symbol;
	BooleanExpression* left;
	BooleanExpression* right;
};

bool operator==(const Operation&, const Operation&);