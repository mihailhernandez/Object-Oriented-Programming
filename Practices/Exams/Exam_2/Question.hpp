#pragma once

#include "String.hpp"

class Question
{
public:
	/* We have an abstract class that deals with dynamic obejcts,
	   so we must provide a virtual destructor.
	*/
	virtual ~Question() = 0;
	virtual void print() const = 0;
	//virtual void copy_from(const Question*) = 0;

	/* accessors and mutators */
	void set_number(const int);
	void set_points(const int);
	int get_points() const;
	int get_number() const;
	const String* get_question() const;
	void set_question(String*);

protected:
	Question(String*, int);

private:
	int number;
	int points;
	String* question;
};

std::ostream& operator<<(std::ostream&, const Question*);
