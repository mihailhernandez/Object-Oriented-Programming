#include "Criteria.h"
#include "Common.h"

Criteria::Criteria(const double weight) : weight(0)
{
	set_weight(weight);
}

void Criteria::set_weight(const double weight)
{
	this->weight = weight <= Constants::MIN_WEIGHT ? Constants::MIN_WEIGHT : weight;
}

double Criteria::get_weight() const
{
	return this->weight;
}
