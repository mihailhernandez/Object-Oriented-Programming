#pragma once

class Criteria
{
public:
	Criteria(const double);
	virtual double calculate() const = 0;
	void set_weight(const double);
	double get_weight() const;
private:
	double weight;
};