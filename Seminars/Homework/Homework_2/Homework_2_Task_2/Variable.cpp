#include "Variable.h"

Variable::Variable(const char symbol) : BooleanExpression(), symbol(symbol) {}

Variable::Variable(const Variable& variable) : BooleanExpression(), symbol(variable.symbol) {}

Variable& Variable::operator=(const Variable& variable)
{
	if (this != &variable)
		set_symbol(variable.symbol);
	return *this;
}

void Variable::set_symbol(const char symbol)
{
	this->symbol = symbol;
}

char Variable::get_symbol() const
{
	return this->symbol;
}

void Variable::print() const
{
	std::cout << this->symbol;
}

bool Variable::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool Variable::is_tauthology() const
{
	return this->symbol == 'T';
}

bool Variable::is_contradiction() const
{
	return this->symbol == 'F';
}

int Variable::get_number_of_vars() const
{
	return symbol == 'T' || symbol == 'F' ? 0 : 1;
}

bool operator==(const Variable& left, const Variable& right)
{
	return left.get_symbol() == right.get_symbol();
}
