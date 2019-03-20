#include <iostream>

const unsigned int MAX_NAME_LEN = 30;
const unsigned int MAX_STUDENT_COUNT = 30;

struct Book
{
	char name[MAX_NAME_LEN];
	const char* author;
};

struct Student
{
	int fn;
	Book* student_book; 
};

int main()
{
	Student* student_list[MAX_STUDENT_COUNT];
	Student student;

	student_list[0] = &student;

	char name[MAX_NAME_LEN];
	const char* author_name = "Author name";

	Book bk;

	std::cin >> bk.name;

	bk.author = author_name;
	
	student.fn = 12345;
	student.student_book = &bk;

	std::cout << student_list[0]->fn << " "
			  << student_list[0]->student_book->name << " "
			  << student_list[0]->student_book->author
			  << std::endl;

	return 0;
}
