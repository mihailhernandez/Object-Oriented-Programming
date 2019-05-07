#pragma once

class Criteria
{
public:
	virtual double calculate() const = 0;
	virtual Criteria* get_instance() = 0;
protected:
	Criteria* criteria;
	Criteria();
};