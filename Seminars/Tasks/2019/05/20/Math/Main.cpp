#include <iostream>

#include "Operation.h"
#include "Number.h"

int main()
{
	Expression* left1= new Number(3);
	Expression* right1 = new Number(4);
	Expression* left = new Operation(left1, '+', right1);

	Expression* left2 = new Number(53);
	Expression* right2 = new Number(1);
	Expression* right = new Operation(left2, '+', right2);

	Expression* final = new Operation(left, '-', right);
	final->print();
	std::cout << " = " << final->evaluate() << std::endl;

	return 0;
}