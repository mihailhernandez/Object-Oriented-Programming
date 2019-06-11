#include "Disjunction.h"

Disjunction::Disjunction(BooleanExpression* left, BooleanExpression* right) :
	Operation(left, "|", right) {}

Disjunction::Disjunction(const Disjunction& Disjunction)
	: Operation(Disjunction.get_left(), "|", Disjunction.get_right()) {}

Disjunction& Disjunction::operator=(const Disjunction& disjunction)
{
	if (this != &disjunction)
		copy(disjunction);
	return *this;
}

bool Disjunction::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool Disjunction::is_tauthology() const
{
	return get_left()->is_tauthology() || get_right()->is_tauthology();
}

bool Disjunction::is_contradiction() const
{
	return get_left()->is_contradiction() && get_right()->is_contradiction();
}
