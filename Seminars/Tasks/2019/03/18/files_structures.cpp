#include <iostream>
#include <fstream>

struct Test
{
	int a;
	int b;
};

struct Test2
{
	char c;
	int a;
};

int get_file_size(std::ifstream& f)
{
	std::streampos fsize = f.tellg();
	f.seekg(0, std::ios::end);
	return f.tellg() - fsize; 
}

int main()
{
	std::ofstream ofile("test.bin", std::ios::binary);

	Test2 obj  = {'0', 4};
	Test2 obj2 = {'a', 4};
	Test2 obj3 = {'b', 5};
	Test2 obj4 = {'c', 6};

	ofile.write((const char*)&obj,  sizeof(Test2));
	ofile.write((const char*)&obj2, sizeof(Test2));
	ofile.write((const char*)&obj3, sizeof(Test2));
	ofile.write((const char*)&obj4, sizeof(Test2));

	ofile.close();

	std::ifstream ifile("test.bin", std::ios::binary);

	int size_of_file = get_file_size(ifile);
	int object_count = size_of_file / sizeof(Test2);

	Test2* arr = new Test2[object_count];

	ifile.read((char*)arr, size_of_file);

	ifile.close();

	for (int i = 0; i < object_count; i++)
	{
		std::cout << arr[i].c << ", " << arr[i].a << std::endl;
	}

	return 0;
}
