#pragma once

class Criteria
{
public:
	virtual double calculate() const = 0;
protected:
	Criteria();
};