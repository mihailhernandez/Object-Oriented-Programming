#include <iostream>

#include "stdio.h"

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

	Student* student_2 = new Student(45555, "Vladimir", "Ivanov");
	DynamicArray<Criteria*> criterias_2;
	HomeworkCriteria* homework_criteria_2 = new HomeworkCriteria("Homework criteria", 1.4);
	DynamicArray<int> grades_2;
	grades_2.push_back(2);
	grades_2.push_back(3);
	grades_2.push_back(6);
	homework_criteria_2->set_grades(grades_2);
	criterias_2.push_back(homework_criteria_2);
	ExamCriteria* exam_criteria_2 = new ExamCriteria("Exam criteria", 2);
	exam_criteria_2->set_points(101);
	criterias_2.push_back(exam_criteria_2);
	student_2->set_criterias(criterias_2);

	student_2->save_to_file("database.bin");

	delete homework_criteria_2;
	delete exam_criteria_2;
	delete student_2;
	
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

DynamicArray<Student*>* extract_students()
{
	DynamicArray<Student*>* students = new DynamicArray<Student*>();
	std::ifstream file("database.bin", std::ios::binary);
	for (int i = 0; i < 2; i++) 
	{
		Student* student = new Student();
		std::ios_base::streampos & pos = file.tellg();
		student->read_from_file("database.bin", pos);
		students->push_back(student);
	}
	file.close();
	return students;
}

int main()
{
	create_a_template_file();

	DynamicArray<Student*>* students = extract_students();
	for (auto student : *students)
	{
		student->print();
		for (auto criteria : student->get_criterias())
			std::cout << criteria->get_criteria_name() << ": " << criteria->calculate() << std::endl;
		delete student;
	}
	return 0;
}