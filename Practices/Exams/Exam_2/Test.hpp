#pragma once
#include "Question.hpp"

const unsigned int INITIAL_SIZE = 4;

class Test
{
public:
	~Test();
	Test(String*);
	Test(const Test*);

	Test& operator=(const Test*);

	void add_question(Question*);
	void remove_question(const int);

	int get_size() const;
	int get_capacity() const;
	const Question* operator[](const int) const;

	const String* get_name() const;
	void set_name(String*);

private:
	int question_count;
	int size;
	Question** questions;
	String* name;

	void free();
	void copy_from(const Test*);
	void resize();
};

std::ostream& operator<<(std::ostream&, const Test*);