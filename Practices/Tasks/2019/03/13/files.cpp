#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

int add_numbers_to_file(const char* file_name)
{
	std::ofstream file(file_name, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return -1;
	}

	int number_count;
	std::cout << "Enter the number count: ";
	std::cin >> number_count;

	for (size_t i = 0; i < number_count; i++)
	{
		int number;
		std::cout << "Enter number " << ": ";
		std::cin >> number;
		file.write((char*)&number, sizeof(int));
	}
	file.close();

	return 0;
}

int print_every(const char* file_name)
{
	std::ifstream file(file_name, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return -1;
	}
	
	int offset;
	std::cout << "Print every * number: ";
	std::cin >> offset;

	int number;
	for (size_t i = 0; !file.eof(); i++)
	{
		file.read((char*)&number, sizeof(int));
		if (file.eof())
			break;
		if ((i + 1) % offset == 0)
			std::cout << number << std::endl;	
	}
	file.close();

	return 0;
}

int main()
{
	const char* file_name = "myfile";

	add_numbers_to_file(file_name);
	print_every(file_name);

	return 0;
}

