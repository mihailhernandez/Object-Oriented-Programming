#include "Operation.h"

Operation::Operation(Expression* left, 
	const char operation, 
	Expression* right)
	: Expression() 
{
	this->left = left;
	this->operation = operation;
	this->right = right;
}

void Operation::print() const
{
	std::cout << "(";
	left->print();
	std::cout << operation;
	right->print();
	std::cout << ")";
}

int Operation::evaluate() const
{
	int value2 = right->evaluate();
	int result = left->evaluate();;
	if (operation == '+')
		result += value2;
	else
		result -= value2;
	return result;
}

Operation::~Operation()
{
	delete left;
	delete right;
	operation = '\0';
}