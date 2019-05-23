#include "MultipleChoiceQuestion.hpp"

/*
MultipleChoiceQuestion::MultipleChoiceQuestion(String* question, int points, bool remove_points) : Question(question, points)
{

}

void MultipleChoiceQuestion::print(std::ostream&) const
{

}

void MultipleChoiceQuestion::set_answers(String** answers)
{
	this->answers = answers;
}

void MultipleChoiceQuestion::print(std::ostream& stream) const
{
	stream << get_number() << "# " << get_question() << std::endl;
	for (int i = 0; i < answer_count; i++)
		std::cout << 'a' + i << ") " << answers_str[i] << std::endl;
	stream << "Points: " << get_points() << std::endl;
	stream << "Answer: ";
	for (int i = 0; i < right_answer_count; i++)
		std::cout << 'a' + answers[i] << "," << std::endl;
}

void MultipleChoiceQuestion::set_right_answer_count(int right_answer_count)
{
	this->right_answer_count = right_answer_count;
}

int MultipleChoiceQuestion::get_answer_count() const
{
	return answer_count;
}

void MultipleChoiceQuestion::set_answers(int answers[])
{
	this->answers = answers;
}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{
	for (int i = 0; i < answer_count; i++)
		delete answers_str[i];
	delete[] answers_str;
	delete[] answers;
}*/
