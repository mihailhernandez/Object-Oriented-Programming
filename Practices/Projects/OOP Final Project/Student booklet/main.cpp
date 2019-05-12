#include "Student.h"
#include "DynamicArray.h"
#include "Criteria.h"
#include <stdio.h>

int main()
{
	DynamicArray<Student*> students;
	students.push_back(new Student(45555, "Vladimir", "Ivanov"));
	students.push_back(new Student(45556, "Mihail", "Petkov"));
	students.push_back(new Student(45557, "Kristian", "Georgiev"));

	for (auto s : students)
		std::cout << *(s) << std::endl;

	DynamicArray<Student*> stud;

	remove("hello.bin");
	for (auto student : students)
		save_to_file("hello.bin", *student);

	std::ifstream ifs("hello.bin", std::ios::binary);
	while (ifs.peek() != EOF)
	{
		Student* s = new Student();
		read_from_file(ifs, *s);
		stud.push_back(s);
	}

	for (auto s : stud)
		std::cout << *s << std::endl;

	return 0;
}