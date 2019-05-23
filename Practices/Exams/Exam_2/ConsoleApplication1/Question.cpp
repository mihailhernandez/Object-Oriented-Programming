#include "Question.hpp"

Question::Question(String* question, int points)
	: question(question), points(points), number(0) {}

Question::~Question()
{
	delete question;
}

std::ostream& operator<<(std::ostream& stream, const Question* question)
{
	stream << question->get_question() << std::endl;
	stream << "Points: " << question->get_points() << std::endl;
	return stream;
}

int Question::get_points() const 
{
	return points;
}

int Question::get_number() const
{
	return number;
}

const String* Question::get_question() const
{
	return question;
}

void Question::set_number(int number)
{
	this->number = number;
}

void Question::set_points(const int points)
{
	this->points = points;
}

void Question::set_question(String* question) 
{
	this->question = question;
}