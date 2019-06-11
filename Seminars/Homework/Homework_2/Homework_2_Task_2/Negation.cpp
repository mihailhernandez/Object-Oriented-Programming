#include "Negation.h"

Negation::Negation(BooleanExpression* expression) 
	: Operation(expression, "!", nullptr) {}

Negation::Negation(const Negation& negation) 
	: Operation(negation.get_left(), negation.get_symbol(), negation.get_right()) {}

Negation& Negation::operator=(const Negation& negation)
{
	if (this != &negation)
		copy(negation);
	return *this;
}

void Negation::print() const
{
	std::cout << "!(";
	get_left()->print();
	std::cout << ")";
}

bool Negation::is_contingency() const
{
	return get_left()->is_contingency();
}

bool Negation::is_tauthology() const
{
	return get_left()->is_contingency() ? false : !get_left()->is_tauthology();
}

bool Negation::is_contradiction() const
{
	return get_left()->is_contingency() ? false : !get_left()->is_contradiction();
}