
#include "Student.h"
#include "Common.h"

#include <cstring>

Student::Student() : faculty_number(0), first_name(nullptr), last_name(nullptr) {}

Student::Student(const int faculty_number, const char* first_name, const char* last_name)
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
	free();
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

int Student::get_faculty_number() const
{
	return this->faculty_number;
}

const char* Student::get_first_name() const
{
	return first_name;
}

const char* Student::get_last_name() const
{
	return this->last_name;
}

void Student::copy(const Student& other_student)
{
	set_faculty_number(other_student.get_faculty_number());
	set_first_name(other_student.get_first_name());
	set_last_name(other_student.get_last_name());
}

void Student::free()
{
	delete[] first_name;
	delete[] last_name;
}

std::istream& operator>>(std::istream& input_stream, Student& student)
{
	unsigned int faculty_number;
	char* first_name = new char[Constants::Student::MAX_FIRST_NAME_LENGTH];
	char* last_name = new char[Constants::Student::MAX_LAST_NAME_LENGTH];
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
	output_stream << student.get_faculty_number() << " "
		<< student.get_first_name() << " " 
		<< student.get_last_name();
	return output_stream;
}
std::ifstream& operator>>(std::ifstream& input_file_stream, Student& student)
{
	int faculty_number = 0;
	int first_name_len = 0;
	int last_name_len = 0;
	char* first_name = nullptr;
	char* last_name = nullptr;
	input_file_stream.read((char*)& faculty_number, sizeof(int));
	input_file_stream.read((char*)& first_name_len, sizeof(int));
	first_name = new char[first_name_len + 1];
	input_file_stream.read((char*)& first_name, sizeof(char) * first_name_len);
	first_name[first_name_len] = '\0';
	input_file_stream.read((char*)& last_name_len, sizeof(int));
	last_name = new char[last_name_len + 1];
	input_file_stream.read((char*)& last_name, sizeof(char) * last_name_len);
	last_name[last_name_len] = '\0';
	student.set_faculty_number(faculty_number);
	student.set_first_name(first_name);
	student.set_last_name(last_name);
	delete[] first_name;
	delete[] last_name;
	return input_file_stream;
}
std::ofstream& operator<<(std::ofstream& output_file_stream, const Student& student)
{
	const char* first_name = student.get_first_name();
	const char* last_name = student.get_last_name();
	int faculty_number = student.get_faculty_number();
	int first_name_len = strlen(first_name);
	int last_name_len = strlen(last_name);
	output_file_stream.write((const char*)& faculty_number, sizeof(int));
	output_file_stream.write((const char*)& first_name_len, sizeof(int));
	output_file_stream.write((const char*)& first_name, sizeof(char) * first_name_len);
	output_file_stream.write((const char*)& last_name_len, sizeof(int));
	output_file_stream.write((const char*)& last_name, sizeof(char) * last_name_len);
	return output_file_stream;
}

std::istream& operator>>(std::istream& input_stream, Student* student)
{
	input_stream >> *(student);
	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Student* student)
{
	output_stream << *(student);
	return output_stream;
}

std::ifstream& operator>>(std::ifstream& file_input_stream, Student* student)
{
	file_input_stream >> (*student);
	return file_input_stream;
}
std::ofstream& operator<<(std::ofstream& file_output_stream, const Student* student)
{
	file_output_stream << *(student);
	return file_output_stream;
}
