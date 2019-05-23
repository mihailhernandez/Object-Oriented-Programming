#include "Question.hpp"

class TrueFalseQuestion : public Question
{
public:
	~TrueFalseQuestion();
	TrueFalseQuestion(String*, const bool, const int);
	void print() const;
	void copy_from(const Question*);
private:
	bool is_true;
};