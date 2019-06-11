#include "BiImplication.h"

BiImplication::BiImplication(BooleanExpression* left, BooleanExpression* right) :
	Operation(left, "<->", right) {}

BiImplication::BiImplication(const BiImplication& biImplication)
	: Operation(biImplication.get_left(), "<->", biImplication.get_right()) {}

BiImplication& BiImplication::operator=(const BiImplication& biImplication)
{
	if (this != &biImplication)
		copy(biImplication);
	return *this;
}

bool BiImplication::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool BiImplication::is_tauthology() const
{
	return (get_left() == get_right()) 
		|| (get_left()->is_tauthology() && get_right()->is_tauthology())
		|| (get_left()->is_contradiction() && get_right()->is_contradiction());
}

bool BiImplication::is_contradiction() const
{
	return (get_left()->is_tauthology() && get_right()->is_contradiction()
		|| get_left()->is_contradiction() && get_right()->is_tauthology());
}