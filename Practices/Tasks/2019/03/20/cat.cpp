#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file(__FILE__);
	while (!file.eof() && std::cout << (char)file.get());
	return 0;
}
