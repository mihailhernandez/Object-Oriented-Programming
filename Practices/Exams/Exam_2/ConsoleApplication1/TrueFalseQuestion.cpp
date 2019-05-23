#include "TrueFalseQuestion.hpp"

TrueFalseQuestion::TrueFalseQuestion(String* question, const bool is_true, const int points) 
	: Question(question, points), is_true(is_true) {}

TrueFalseQuestion::~TrueFalseQuestion() {}

void TrueFalseQuestion::print() const
{
	std::cout << get_number() << "# " << get_question() << std::endl;
	std::cout << 'a' << ") Yes" << std::endl;
	std::cout << 'b'  << ") No" << std::endl;
	std::cout << "Points: " << get_points() << std::endl;
	std::cout << "Answer: " << (is_true ? 'a' : 'b') << std::endl;
}

void TrueFalseQuestion::copy_from(const Question* other)
{
	set_question((String*)other->get_question());
	set_number(other->get_number());
	set_points(other->get_points());
}
