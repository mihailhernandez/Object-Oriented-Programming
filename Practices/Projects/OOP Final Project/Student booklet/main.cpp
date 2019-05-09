#include "Student.h"
#include "DynamicArray.h"

int main()
{
	/* ----------------------- STUDENTS -------------------------- */
	DynamicArray<Student> students;
	students.push_back(Student(45555, "Vladimir", "Ivanov"));
	students.push_back(Student(45556, "Mihail", "Petkov"));
	students.push_back(Student(45557, "Kristian", "Georgiev"));

	for (auto s : students)
		std::cout << s << std::endl;

	return 0;
}