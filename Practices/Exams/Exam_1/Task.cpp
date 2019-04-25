#include "Task.hpp"
#include <cstring>

Task::Task(const char * name)
{
	set_name(name);
}

Task::~Task()
{
	delete[] name;
}

char * Task::get_name() const
{
	char * copy = new char[strlen(name)];
	strcpy(copy, name);
	return copy;
}

void Task::copy(const Task& other)
{
	char * other_name = other.get_name();
	this->name = new char[strlen(other_name)];
	strcpy(this->name, other_name);
	delete[] other_name;
}

Task& Task::operator=(const Task& other)
{
	copy(other);
	return *this;
}

Task::Task(const Task& other)
{
	copy(other);
}
