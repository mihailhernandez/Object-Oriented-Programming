#include "Student.h"
#include "Common.h"

Student::Student() : faculty_number(0), first_name(nullptr), last_name(nullptr) {}

Student::Student(const unsigned int faculty_number, const char* first_name, const char* last_name)
	: faculty_number(0), first_name(nullptr), last_name(nullptr)
{
	set_faculty_number(faculty_number);
	set_first_name(first_name);
	set_last_name(last_name);
}

Student::Student(const Student& other_student)
	: faculty_number(0), first_name(nullptr), last_name(nullptr)
{
	copy(other_student);
}

Student::~Student()
{
	delete[] first_name;
	delete[] last_name;
}

Student& Student::operator=(const Student& other_student)
{
	copy(other_student);
	return *this;
}

void Student::set_faculty_number(const unsigned int faculty_number)
{
	this->faculty_number = faculty_number;
}

void Student::set_first_name(const char* first_name)
{
	delete[] this->first_name;
	this->first_name = Utils::copy_string(first_name);
}

void Student::set_last_name(const char* last_name)
{
	delete[] this->last_name;
	this->last_name = Utils::copy_string(last_name);
}

unsigned int Student::get_faculty_number() const
{
	return this->faculty_number;
}

char* Student::get_first_name() const
{
	return Utils::copy_string(this->first_name);
}

char* Student::get_last_name() const
{
	return Utils::copy_string(this->last_name);
}

void Student::copy(const Student& other_student)
{
	char* other_student_first_name = other_student.get_first_name();
	char* other_student_last_name = other_student.get_last_name();
	set_faculty_number(other_student.get_faculty_number());
	set_first_name(other_student_first_name);
	set_last_name(other_student_last_name);
	delete[] other_student_first_name;
	delete[] other_student_last_name;
}

std::istream& operator>>(std::istream& input_stream, Student& student)
{
	unsigned int faculty_number;
	char* first_name = new char[Constants::MAX_FIRST_NAME_LENGTH];
	char* last_name = new char[Constants::MAX_LAST_NAME_LENGTH];
	input_stream >> faculty_number >> first_name >> last_name;
	student.set_faculty_number(faculty_number);
	student.set_first_name(first_name);
	student.set_last_name(last_name);
	delete[] first_name;
	delete[] last_name;
	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Student& student)
{
	char* first_name = student.get_first_name();
	char* last_name = student.get_last_name();
	output_stream << student.get_faculty_number() << " "
		<< first_name << " " << last_name << std::endl;
	delete[] first_name;
	delete[] last_name;
	return output_stream;
}
std::ifstream& operator>>(std::ifstream& input_file_stream, Student& student)
{
	//TODO: implement me!
	return input_file_stream;
}
std::ofstream& operator<<(std::ofstream& output_file_stream, const Student& student)
{
	//TODO: implement me!
	return output_file_stream;
}
