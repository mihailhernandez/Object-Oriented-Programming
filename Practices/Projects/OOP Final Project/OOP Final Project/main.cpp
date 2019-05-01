#include <iostream>

class Student
{
public:
	Student(const unsigned int faculty_number, const char* first_name, const char* last_name)
	{
		set_faculty_number(faculty_number);
		set_first_name(first_name);
		set_last_name(last_name);
	}
		
	void set_faculty_number(const unsigned int faculty_number)
	{
		this->faculty_number = faculty_number;
	}
	
	void set_first_name(const char* first_name)
	{
		
	}

	void set_last_name(const char* last_name)
	{

	}
private:
	unsigned int faculty_number;
	char* first_name;
	char* last_name;
};

class StudentGrade
{
private:
	Student* student;
	unsigned int grade;
public:
};

class Criteria
{
public:
	virtual double calt_weight() const = 0;
protected:
	Criteria();
private:
	StudentGrade** grades;
};

class Student
{

};

int main()
{
	Student** students = new Student*[10];
	for (int i = 0; i < 10; i++)
		students[i] = new Student();
	
    std::cout << "Hello World!\n"; 
}