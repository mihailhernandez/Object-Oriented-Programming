#include "HomeworkCriteria.h"

HomeworkCriteria::HomeworkCriteria() : Criteria() {}

HomeworkCriteria::HomeworkCriteria(const char* criteria_name, const double weight) 
	: Criteria(criteria_name, weight)
{
}

HomeworkCriteria::HomeworkCriteria(const HomeworkCriteria& criteria) :
	Criteria(criteria.criteria_name, criteria.weight)
{
	HomeworkCriteria::copy_from(criteria);
}

HomeworkCriteria::~HomeworkCriteria()
{
}

HomeworkCriteria* HomeworkCriteria::operator=(const HomeworkCriteria* criteria)
{
	HomeworkCriteria::copy_from(*criteria);
	return this;
}

void HomeworkCriteria::save_to_file(const char* file_name) const
{
	Criteria::save_identifier(file_name, CriteriaIdentifiers::HOMEWORK_CRITERIA_IDENTIFIER);
	Criteria::save_to_file(file_name);
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	int grades_count = grades.get_size();
	file.write((const char*)& grades_count, sizeof(int));
	for (auto grade : grades)
		file.write((const char*)& grade, sizeof(int));
	file.close();
}

std::ios_base::streampos& HomeworkCriteria::read_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	Criteria::read_from_file(file_name, read_from_pos);
	std::ifstream file(file_name, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return read_from_pos;
	}
	file.seekg(read_from_pos);

	int grade_count;
	file.read((char*)& grade_count, sizeof(int));
	for (int i = 0; i < grade_count; i++)
	{
		int grade;
		file.read((char*)& grade, sizeof(int));
		grades.push_back(grade);
	}

	read_from_pos = file.tellg();
	file.close();
	return read_from_pos;
}

void HomeworkCriteria::print() const
{
	std::cout << criteria_name << std::endl;
	for (auto grade : grades)
		std::cout << grade << " ";
	std::cout << std::endl;
}

double HomeworkCriteria::calculate() const
{
	double total = 0;
	for (auto grade : grades)
		total += grade;
	return total / grades.get_size();
}

const DynamicArray<int>& HomeworkCriteria::get_grades() const
{
	return grades;
}

void HomeworkCriteria::set_grades(const DynamicArray<int>& grades)
{
	this->grades = grades;
}

void HomeworkCriteria::copy_from(const HomeworkCriteria& criteria)
{
	Criteria::copy_from(criteria.criteria_name, criteria.weight);
	this->grades = criteria.grades;
}
