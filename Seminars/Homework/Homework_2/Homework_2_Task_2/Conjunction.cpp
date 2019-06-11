#include "Conjunction.h"

Conjunction::Conjunction(BooleanExpression* left, BooleanExpression* right) : 
	Operation(left, "&", right) {}

Conjunction::Conjunction(const Conjunction& conjunction) 
	: Operation(conjunction.get_left(), "&", conjunction.get_right()) {}

Conjunction& Conjunction::operator=(const Conjunction& conjunction)
{
	if (this != &conjunction)
		copy(conjunction);
	return *this;
}

bool Conjunction::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool Conjunction::is_tauthology() const
{
	return get_left()->is_tauthology() && get_right()->is_tauthology();
}

bool Conjunction::is_contradiction() const
{
	return get_left()->is_contradiction() || get_right()->is_contradiction();
}
