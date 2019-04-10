#ifndef SHOW_TIME_COMMAND_H_
#define SHOW_TIME_COMMAND_H_

#include "Command.hpp"
#include <string>
#include <iostream>

class ShowTimeCommand : public Command
{
	public:
	ShowTimeCommand() {}
	~ShowTimeCommand() {}
};

std::string ShowTimeCommand::to_string()
{		
	return "show_time_command";	
}

void ShowTimeCommand::execute(Clock & clock)
{
	clock.print(); 	
}

#endif
