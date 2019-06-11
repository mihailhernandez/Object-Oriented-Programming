#include "ExclusiveOr.h"

ExclusiveOr::ExclusiveOr(BooleanExpression* left, BooleanExpression* right) :
	Operation(left, "(+)", right) {}

ExclusiveOr::ExclusiveOr(const ExclusiveOr& ExclusiveOr)
	: Operation(ExclusiveOr.get_left(), "(+)", ExclusiveOr.get_right()) {}

ExclusiveOr& ExclusiveOr::operator=(const ExclusiveOr& ExclusiveOr)
{
	if (this != &ExclusiveOr)
		copy(ExclusiveOr);
	return *this;
}

bool ExclusiveOr::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool ExclusiveOr::is_tauthology() const
{
	return (get_left()->is_tauthology() && get_right()->is_contradiction()
		|| get_left()->is_contradiction() && get_right()->is_tauthology());
}

bool ExclusiveOr::is_contradiction() const
{
	return (get_left() == get_right())
		|| (get_left()->is_tauthology() && get_right()->is_tauthology())
		|| (get_left()->is_contradiction() && get_right()->is_contradiction());
}