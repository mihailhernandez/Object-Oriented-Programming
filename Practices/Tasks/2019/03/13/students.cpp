#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iterator>

struct Student
{
	private:

	unsigned int fac_num;
	char* name;

	public:

	Student() {}
	
	Student(const char* name, const unsigned int fac_num)
	{
		this->name = new char[strlen(name)];
		set_name(this->name);
		set_fac_num(fac_num);
	}

	~Student()
	{
		delete name;
	}

	unsigned int get_fac_num() const
	{
		return this->fac_num;
	}

	const char* get_name() const
	{
		return this->name;
	}

	void set_fac_num(unsigned int fac_num)
	{
		if (fac_num < 0)
			fac_num = 0;
		this->fac_num = fac_num;
	}

	void set_name(const char* name)
	{
		std::strcpy(this->name, name);
	}

	void print() const
	{
		std::cout << "Student at address: " << this << std::endl
				  << "has a name: " << this->name << std::endl
				  << "and a faculty number: " << this->fac_num << std::endl;
	}
};

int serialize(const Student* students, const unsigned int STUDENT_COUNT, const char* STUDENTS_FILE_PATH)
{
	std::ofstream file(STUDENTS_FILE_PATH, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return -1;
	}

	file.write((char*)&STUDENT_COUNT, sizeof(int));

	for (size_t i = 0; i < STUDENT_COUNT; i++)
	{
		const char* name = students[i].get_name();
		unsigned int fac_num = students[i].get_fac_num();
		unsigned int name_len = strlen(students[i].get_name());

		file.write((char*)&fac_num, sizeof(int));
		file.write((char*)&name_len, sizeof(int));
		file.write((char*)&name, sizeof(char) * name_len);
	}

	file.close();

	return 0;
}

Student** deserialize(const char* file_name)
{
	std::ifstream file(file_name, std::ios::binary);

	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return NULL;
	}

	unsigned int student_count;
	file.read((char*)&student_count, sizeof(int));

	Student** students = new Student*[student_count];

	for (size_t i = 0; i < student_count; i++)
	{
		unsigned int fac_num;
		unsigned int name_len;

		file.read((char*)&fac_num, sizeof(int));
		file.read((char*)&name_len, sizeof(int));
		char* name = new char[name_len];
		file.read((char*)&name, sizeof(char) * name_len);
		students[i] = new Student(name, fac_num);
		
		delete name;
	}
	
	file.close();

	return students;
}


int main()
{
	const char* STUDENTS_FILE_PATH = "students";
	const unsigned int STUDENT_COUNT = 3;

	const Student students[] = 
	{
			{"Misho", 1233},
			{"Nikolay", 432},
			{"Kircho", 54}
	};

	// Trying how the iterator works
	for (auto it = std::begin(students); it != std::end(students); it++)
		it->print();

	serialize(students, STUDENT_COUNT, STUDENTS_FILE_PATH);

    Student** new_students = deserialize(STUDENTS_FILE_PATH);
	
	for (size_t i = 0; i < STUDENT_COUNT; i++)
		new_students[i]->print();

	delete[] new_students;

	return 0;
}
