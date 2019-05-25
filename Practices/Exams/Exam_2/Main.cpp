#include "Test.hpp"
#include "TrueFalseQuestion.hpp"
#include "MultipleChoiceQuestion.hpp"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Test* test = new Test(new String("Math test"));

	TrueFalseQuestion* first  = new TrueFalseQuestion(new String("Is is true that 1 = 1?"), true, 1);
	TrueFalseQuestion* second = new TrueFalseQuestion(new String("Is is true that 1 = 2?"), false, 2);

	test->add_question(first);
	test->add_question(second);

	std::cout << test;

	return 0;
}