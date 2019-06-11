#include "BooleanExpression.h"

void BooleanExpression::print_all() const
{
	std::cout << std::boolalpha << "Is "; print(); std::cout << " tauthology?     " << is_tauthology() << std::endl;
	std::cout << std::boolalpha << "Is "; print(); std::cout << " contradiction?  " << is_contradiction() << std::endl;
	std::cout << std::boolalpha << "Is "; print(); std::cout << " contingency?    " << is_contingency() << std::endl << std::endl;
}