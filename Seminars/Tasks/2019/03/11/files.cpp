#include <iostream>
#include <fstream>

int main()
{
	std::ofstream ofile;
	std::ifstream ifile;

	ofile.open("test", std::ios::binary);

	if (!ofile.is_open())
	{	
		std::cerr << "File not opened!" << std::endl;
		return 1;
	}

	int a = 665;

	ofile.write((char*)&a, sizeof(int)); 

	int b = 1000;

	ofile.write((char*)&b, sizeof(int)); 

	ofile.close();

	ifile.open("test");

	if (!ifile.is_open())
	{
		std::cerr << "File no opened!" << std::endl;
		return 1;
	}

	int num;

	while (!ifile.eof())
	{
		ifile.read((char*)&num, sizeof(int));
		if (!ifile.good())
			break;
		std::cout << num << std::endl;
	}

	return 0;
}
