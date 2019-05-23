#include "Test.hpp"

Test::~Test()
{
	free();
}

Test::Test(String* name) 
	: questions(new Question*[INITIAL_SIZE]), 
	size(0), 
	question_count(INITIAL_SIZE), 
	name(name) {}

Test::Test(const Test* other)
{
	copy_from(other);
}

Test& Test::operator=(const Test* other)
{
	copy_from(other);
	return *this;
}

void Test::add_question(Question* question)
{
	if (question_count == size)
		resize();
	questions[size++] = question;
	question->set_number(size);
}

void Test::remove_question(const int number)
{
	for (int i = 0; i < size; i++)
		if (questions[i]->get_number() == number)
		{
			delete questions[i];
			for (int j = i; j < size - 1; j++)
				questions[j] = questions[j + 1];
			questions[size - 1] = nullptr;
		}
	size--;
}

void Test::free()
{
	delete[] questions;
	size = 0;
	question_count = 0;
}

void Test::copy_from(const Test* other)
{
	this->questions = new Question*[other->question_count];
	for (int i = 0; i < other->size; i++)
		//this->questions[i]->copy_from(other->questions[i]);
	this->size = other->size;
	this->question_count = other->question_count;
}

void Test::resize()
{
	question_count *= 2;
	Question** temp = new Question*[question_count];
	for (int i = 0; i < size; i++)
		temp[i] = questions[i];
	delete[] questions;
	questions = temp;
}

const String* Test::get_name() const
{
	return name;
}

const Question* Test::operator[](const int index) const
{
	return questions[index];
}

int Test::get_size() const
{
	return size;
}

int Test::get_capacity() const
{
	return question_count;
}

void Test::set_name(String* name)
{
	if (this->name != nullptr)
		delete this->name;
	this->name = name;
}

std::ostream& operator<<(std::ostream& stream, const Test* test)
{
	for (int i = 0; i < test->get_size(); i++)
		test->operator[](i)->print();
	return stream;
}