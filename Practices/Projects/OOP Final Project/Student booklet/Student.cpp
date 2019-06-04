#include "Student.h"

Student::Student() : 
	faculty_number(0), 
	first_name(nullptr), 
	last_name(nullptr) {}

Student::Student(const int faculty_number, const char* first_name, const char* last_name)
{
	copy_from(faculty_number, first_name, last_name);
}

Student::Student(const Student& other_student)
{
	copy_from(other_student.faculty_number, other_student.first_name, other_student.last_name);
}

Student::~Student()
{
	free();
}

Student& Student::operator=(const Student& other_student)
{
	copy_from(other_student.faculty_number, other_student.first_name, 
		other_student.last_name);
	return *this;
}

void Student::set_faculty_number(const int faculty_number)
{
	this->faculty_number = faculty_number;
}

void Student::set_first_name(const char* first_name)
{
	this->first_name = new char[strlen(first_name) + 1];
	strcpy(this->first_name, first_name);
}

void Student::set_last_name(const char* last_name)
{
	this->last_name = new char[strlen(last_name) + 1];
	strcpy(this->last_name, last_name);
}

void Student::set_criterias(const DynamicArray<Criteria*>& criterias)
{
	this->criterias = criterias;
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

const DynamicArray<Criteria*>& Student::get_criterias() const
{
	return criterias;
}

void Student::copy_from(const int faculty_number, const char* first_name, const char* last_name)
{
	set_faculty_number(faculty_number);
	set_first_name(first_name);
	set_last_name(last_name);
}

void Student::free()
{
	delete[] first_name;
	delete[] last_name;
}

std::ostream& operator<<(std::ostream& output_stream, const Student& student)
{
	output_stream << student.get_faculty_number() << " "
		<< student.get_first_name() << " " 
		<< student.get_last_name();
	return output_stream;
}

std::ios_base::streampos& Student::read_student_info_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	std::ifstream file(file_name, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return read_from_pos;
	}
	file.seekg(read_from_pos);

	int first_name_len, last_name_len;
	char* first_name, * last_name;
	file.read((char*)& faculty_number, sizeof(int));
	file.read((char*)& first_name_len, sizeof(int));
	first_name = new char[first_name_len + 1];
	file.read(first_name, sizeof(char) * first_name_len);
	first_name[first_name_len] = '\0';
	file.read((char*)& last_name_len, sizeof(int));
	last_name = new char[last_name_len + 1];
	file.read(last_name, sizeof(char) * last_name_len);
	last_name[last_name_len] = '\0';

	set_first_name(first_name);
	set_last_name(last_name);

	delete[] first_name;
	delete[] last_name;

	read_from_pos = file.tellg();
	file.close();
	return read_from_pos;
}

void Student::save_to_file(const char* file_name) const
{
	save_student_basic_info(file_name);
	save_criteria_info(file_name);
}

void Student::save_student_basic_info(const char* file_name) const
{
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	int first_name_len = strlen(this->first_name);
	int last_name_len = strlen(this->last_name);
	file.write((const char*)& faculty_number, sizeof(int));
	file.write((const char*)& first_name_len, sizeof(int));
	file.write(this->first_name, sizeof(char) * first_name_len);
	file.write((const char*)& last_name_len, sizeof(int));
	file.write(this->last_name, sizeof(char) * last_name_len);
	file.close();
}

std::ios_base::streampos& Student::read_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	read_student_info_from_file(file_name, read_from_pos);
	read_criterias_from_file(file_name, read_from_pos);
	return read_from_pos;
}

void Student::print() const
{
	std::cout << faculty_number << " " << first_name << " " << last_name << std::endl;
	std::cout << "Results: " << std::endl;
	for (auto criteria : criterias)
		criteria->print();
}

void Student::save_criteria_info(const char* file_name) const
{
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	int criteria_count = criterias.get_size();
	file.write((const char*)& criteria_count, sizeof(int));
	file.close();
	for (auto criteria : criterias)
		criteria->save_to_file(file_name);
}

std::ios_base::streampos& Student::read_criterias_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	std::ifstream file(file_name, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return read_from_pos;
	}
	file.seekg(read_from_pos);

	int criteria_count, identifier;
	file.read((char*)& criteria_count, sizeof(int));
	read_from_pos = file.tellg();
	for (int i = 0; i < criteria_count; i++)
	{
		file.seekg(read_from_pos);
		file.read((char*)& identifier, sizeof(int));
		read_from_pos = file.tellg();
		Criteria* criteria = CriteriaFactory::create(identifier);
		criteria->read_from_file(file_name, read_from_pos);
		criterias.push_back(criteria);
	}

	read_from_pos = file.tellg();
	file.close();
	return read_from_pos;
}