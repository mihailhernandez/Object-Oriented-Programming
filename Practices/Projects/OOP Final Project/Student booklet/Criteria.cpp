#include <fstream>

#include "Criteria.h"

Criteria::Criteria() {}

Criteria::~Criteria()
{
	free();
}

Criteria::Criteria(const char* criteria_name, const double weight)
{
	copy_from(criteria_name, weight);
}

void Criteria::set_criteria_name(const char* criteria_name)
{
	copy_from(criteria_name, weight);
}

void Criteria::set_weight(const double weight)
{
	this->weight = weight;
}

const char* Criteria::get_criteria_name() const
{
	return criteria_name;
}

double Criteria::get_weight() const
{
	return weight;
}

void Criteria::free()
{
	delete[] criteria_name;
}

void Criteria::save_identifier(const char* file_name, const int identifier) const
{
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	file.write((const char*)& identifier, sizeof(int));
	file.close();
}

void Criteria::copy_from(const char* criteria_name, const double weight)
{
	this->criteria_name = new char[strlen(criteria_name) + 1];
	strcpy(this->criteria_name, criteria_name);
	this->weight = weight;
}

void Criteria::save_to_file(const char* file_name) const
{
	std::ofstream file(file_name, std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return;
	}
	int criteria_name_len = strlen(this->criteria_name);
	file.write((const char*)& criteria_name_len, sizeof(int));
	file.write(this->criteria_name, criteria_name_len * sizeof(char));
	file.write((const char*)& this->weight, sizeof(double));
	file.close();
}

std::ios_base::streampos& Criteria::read_from_file(const char* file_name, std::ios_base::streampos& read_from_pos)
{
	std::ifstream file(file_name, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening file " << file_name << std::endl;
		return read_from_pos;
	}
	file.seekg(read_from_pos);

	int criteria_name_len = 0;
	file.read((char*)& criteria_name_len, sizeof(int));
	this->criteria_name = new char[criteria_name_len];
	file.read(this->criteria_name, sizeof(char) * criteria_name_len);
	criteria_name[criteria_name_len] = '\0';
	file.read((char*)& this->weight, sizeof(double));

	read_from_pos = file.tellg();
	file.close();
	return read_from_pos;
}