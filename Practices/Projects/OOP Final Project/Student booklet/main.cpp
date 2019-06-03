#include <iostream>

#include "Student.h"
#include "HomeworkCriteria.h"
#include "CriteriaFactory.h"
#include "ExamCriteria.h"

/* Removes the strcpy_s recommendations during compilation. */
#define _CRT_SECURE_NO_WARNINGS

void create_a_template_file()
{
	remove("database.bin");

	Student *student = new Student(45555, "Vladimir", "Ivanov");
	DynamicArray<Criteria*> criterias;
	HomeworkCriteria* homework_criteria = new HomeworkCriteria("Homework criteria", 1.4);
	DynamicArray<int> grades; 
	grades.push_back(2);
	grades.push_back(3);
	grades.push_back(6);
	homework_criteria->set_grades(grades);
	criterias.push_back(homework_criteria);
	ExamCriteria* exam_criteria = new ExamCriteria("Exam criteria", 2);
	exam_criteria->set_points(101);
	criterias.push_back(exam_criteria);
	student->set_criterias(criterias);

	student->save_to_file("database.bin");

	delete homework_criteria;
	delete exam_criteria;
	delete student;
}

void print_students(const DynamicArray<Student>& students)
{
	for (auto student : students)
		student.print();
}

void print_criterias(const DynamicArray<Criteria*> criterias)
{
	for (auto criteria : criterias)
		criteria->print();
}

int main()
{
	create_a_template_file();

	Student s;
	std::ifstream file("database.bin", std::ios::binary);
	std::ios_base::streampos pos = file.tellg();
	file.close();
	s.read_from_file("database.bin", pos);
	s.print();
	return 0;
}