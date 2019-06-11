#include "Operation.h"

Operation::Operation(BooleanExpression* left, const char* symbol, BooleanExpression* right) 
	: BooleanExpression(), left(left), right(right), symbol(symbol) {}

Operation::Operation(const Operation& operation) : BooleanExpression()
{
	copy(operation);
}

Operation& Operation::operator=(const Operation& operation)
{
	if (this != &operation)
		copy(operation);
	return *this;
}

Operation::~Operation()
{
	delete left;
	delete right;
}

const char* Operation::get_symbol() const
{
	return this->symbol;
}

void Operation::set_symbol(const char* symbol)
{
	this->symbol = symbol;
}

BooleanExpression* Operation::get_left() const
{
	return this->left;
}

BooleanExpression* Operation::get_right() const
{
	return this->right;
}

void Operation::set_left(BooleanExpression* left)
{
	delete this->left;
	this->left = left;
}

void Operation::set_right(BooleanExpression* right)
{
	delete this->right;
	this->right = right;
}

void Operation::print() const
{
	std::cout << "(";
	left->print();
	std::cout << " " << symbol << " ";
	right->print();
	std::cout << ")";
}

void Operation::copy(const Operation& operation)
{
	set_symbol(operation.symbol);
	set_left(operation.left);
	set_right(operation.right);
}
