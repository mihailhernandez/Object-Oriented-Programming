#include <stdio.h>
#include <iostream>
#include "Controller.hpp"


int main()
{
	remove(Constants::DATABASE_NAME);
	Controller controller;
	controller.start();
	return 0;
}

