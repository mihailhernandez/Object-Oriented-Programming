#include <iostream>

#include "stdio.h"

#include "Student.h"
#include "HomeworkCriteria.h"
#include "CriteriaFactory.h"
#include "ExamCriteria.h"

/* Removes the strcpy_s recommendations during compilation. */
#define _CRT_SECURE_NO_WARNINGS

#define DATABASE_FILE "database.bin"

void create_a_template_file()
{
	remove(DATABASE_FILE);

	Student *student = new Student(45555, "Vladimir", "Ivanov");
	DynamicArray<Criteria*> criterias;
	HomeworkCriteria* homework_criteria = new HomeworkCriteria("Homework criteria", 1);
	DynamicArray<int> grades; 
	grades.push_back(2);
	grades.push_back(5);
	grades.push_back(6);
	homework_criteria->set_grades(grades);
	criterias.push_back(homework_criteria);
	ExamCriteria* exam_criteria = new ExamCriteria("Exam criteria", 1);
	exam_criteria->set_points(200);
	criterias.push_back(exam_criteria);
	student->set_criterias(criterias);

	student->save_to_file(DATABASE_FILE);

	delete homework_criteria;
	delete exam_criteria;
	delete student;
}

DynamicArray<Student*>* extract_students()
{
	DynamicArray<Student*>* students = new DynamicArray<Student*>();
	std::ifstream file(DATABASE_FILE, std::ios::binary);
	std::ios_base::streampos& pos = file.tellg();
	Student* student = new Student();
	student->read_from_file(DATABASE_FILE, pos);
	students->push_back(student);
	file.close();
	return students;
}

void print_student_grades(const DynamicArray<Student*>* students)
{
	for (auto student : *students)
	{
		double final_grade = 0;
		double total_weight = 0;
		student->print();
		for (auto criteria : student->get_criterias())
		{
			double grade = criteria->calculate();
			final_grade += grade * criteria->get_weight();
			total_weight += criteria->get_weight();
			std::cout << criteria->get_criteria_name() << ": " << grade << std::endl;
		}
		std::cout << "Final result: " << final_grade / total_weight << std::endl;
		delete student;
	}
}

int main()
{
	create_a_template_file();

	DynamicArray<Student*>* students = extract_students();
	print_student_grades(students);

	delete students;
	return 0;
}