#include <fstream>

int main()
{
	std::ifstream file(__FILE__);
	while (file.peek() != EOF && putchar(file.get()));
	return 0;
}
