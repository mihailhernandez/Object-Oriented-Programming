#include "ExamCriteria.h"

ExamCriteria::ExamCriteria() : Criteria() {}

ExamCriteria::ExamCriteria(const char* name, const double weight)
	: Criteria(name, weight)
{
}

ExamCriteria::ExamCriteria(const ExamCriteria& criteria)
	: Criteria(criteria.criteria_name, criteria.weight)
{
	ExamCriteria::copy_from(criteria);
}

ExamCriteria::~ExamCriteria()
{
}

ExamCriteria* ExamCriteria::operator=(const ExamCriteria* criteria)
{
	ExamCriteria::copy_from(*criteria);
	return this;
}

void ExamCriteria::save_to_file(const char* file_name) const
{
	Criteria::save_identifier(file_name, CriteriaIdentifiers::EXAM_CRITERIA_IDENTIFIER);
	Criteria::save_to_file(file_name);
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	file.write((const char*)& points, sizeof(int));
	file.close();
}

std::ios_base::streampos& ExamCriteria::read_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	Criteria::read_from_file(file_name, read_from_pos);
	std::ifstream file(file_name, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return read_from_pos;
	}
	file.seekg(read_from_pos);

	file.read((char*)& points, sizeof(int));

	read_from_pos = file.tellg();
	file.close();
	return read_from_pos;
}

double ExamCriteria::calculate() const
{
	if (points < 60)
		return 2;
	if (points < 90)
		return 3;
	if (points < 120)
		return 4;
	if (points < 150)
		return 5;
	return 6;
}

int ExamCriteria::get_points() const
{
	return points;
}

void ExamCriteria::set_points(const int points)
{
	this->points = points;
}

void ExamCriteria::print() const
{
	std::cout << criteria_name << std::endl;
	std::cout << "Points: " << points << std::endl;
}

void ExamCriteria::copy_from(const ExamCriteria& criteria)
{
	Criteria::copy_from(criteria.criteria_name, criteria.weight);
	this->points = criteria.points;
}