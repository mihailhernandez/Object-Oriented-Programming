#include "Implication.h"

Implication::Implication(BooleanExpression* left, BooleanExpression* right) :
	Operation(left, "->", right) {}

Implication::Implication(const Implication& implication)
	: Operation(implication.get_left(), "->", implication.get_right()) {}

Implication& Implication::operator=(const Implication& implication)
{
	if (this != &implication)
		copy(implication);
	return *this;
}

bool Implication::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool Implication::is_tauthology() const
{
	return get_left()->is_contradiction() || (get_left()->is_tauthology() && get_right()->is_tauthology());
}

bool Implication::is_contradiction() const
{
	return get_left()->is_tauthology() && get_right()->is_contradiction();
}
