#ifdef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "Clock.hpp"

abstract class Command
{
	public:
	virtual std::string to_string() = 0;
	virtual void execute(Clock & clock) = 0;
};

#endif 
