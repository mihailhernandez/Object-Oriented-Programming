#include <iostream>
#include <fstream>

const unsigned int MAX_BUFFER_LEN = 100;
const char* FILE_NAME = "info.txt";

int main()
{
	char str[MAX_BUFFER_LEN];
	unsigned int fac_num;
	std::cin >> str >> fac_num;
	
	std::ofstream file(FILE_NAME, std::ios::out);
	if (!file.is_open())
	{
		std::cerr << "File not opened correctly!" << std::endl;
		return -1;
	}
	file << str;
	file << fac_num;
	file.close();
	return 0;
}
