#pragma once

#include "Question.hpp"

class MultipleChoiceQuestion : public Question
{
public:
	~MultipleChoiceQuestion();
	MultipleChoiceQuestion(String*, int, bool);
	void print() const;

	void add_answer();
	int get_answer_count() const;
	
private:
	int size;
	int capacity;
	bool remove_points;
	String** answers_str;
};