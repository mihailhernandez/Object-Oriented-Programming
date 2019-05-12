
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
	free();
	copy(other_student);
}

Student::~Student()
{
	free();
}

Student& Student::operator=(const Student& other_student)
{
	free();
	copy(other_student);
	return *this;
}

bool Student::operator==(const Student& other)
{
	return faculty_number == other.faculty_number
		&& strcmp(first_name, other.first_name) == 0
		&& strcmp(last_name, other.last_name) == 0;
}

void Student::set_faculty_number(const int faculty_number)
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
	return last_name;
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
	int faculty_number;
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

void read_from_file(std::ifstream& input_file_stream, Student& student)
{
	if (!input_file_stream)
	{
		std::cerr << "Error opening file while trying to read!" << std::endl;
		return;
	}
	int faculty_number = 0;
	int first_name_len = 0;
	int last_name_len = 0;
	char* first_name = nullptr;
	char* last_name = nullptr;
	input_file_stream.read((char*)& faculty_number, sizeof(int));
	input_file_stream.read((char*)& first_name_len, sizeof(int));
	first_name = new char[first_name_len + 1];
	input_file_stream.read((char*) first_name, sizeof(char) * first_name_len);
	first_name[first_name_len] = '\0';
	input_file_stream.read((char*)& last_name_len, sizeof(int));
	last_name = new char[last_name_len + 1];
	input_file_stream.read((char*) last_name, sizeof(char) * last_name_len);
	last_name[last_name_len] = '\0';
	student.set_faculty_number(faculty_number);
	student.set_first_name(first_name);
	student.set_last_name(last_name);
	delete[] first_name;
	delete[] last_name;
}

void save_to_file(const char* file_name, const Student& student)
{
	std::ofstream output_file_stream(file_name, std::ios::binary | std::ios::app);
	if (!output_file_stream)
	{
		std::cerr << "Error opening file while trying to write!" << std::endl;
		return;
	}
	const char* first_name = student.get_first_name();
	const char* last_name = student.get_last_name();
	int faculty_number = student.get_faculty_number();
	int first_name_len = strlen(first_name);
	int last_name_len = strlen(last_name);
	output_file_stream.write((const char*)& faculty_number, sizeof(int));
	output_file_stream.write((const char*)& first_name_len, sizeof(int));
	output_file_stream.write((const char*) first_name, sizeof(char) * first_name_len);
	output_file_stream.write((const char*)& last_name_len, sizeof(int));
	output_file_stream.write((const char*) last_name, sizeof(char) * last_name_len);
	output_file_stream.close();
}