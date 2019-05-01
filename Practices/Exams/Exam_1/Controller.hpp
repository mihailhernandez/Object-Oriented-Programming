#ifndef __CONTROLLER__
#define __CONTROLLER__
#include <vector>
#include "Constants.hpp"
#include "CreateTask.hpp"
#include "SearchTask.hpp"
#include "ExitTask.hpp"

class Controller
{
public:
	Controller();
	~Controller();
	void start();
private:
	std::vector<Task*> tasks;
	char* command;

	void init_command();
	void init_tasks();
	Task* get_context(const char* command) const;
	bool meets_ending_condition(const Task* context) const;
};

#endif
