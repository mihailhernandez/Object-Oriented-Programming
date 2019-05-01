#include "Controller.hpp"

void Controller::init_tasks()
{
	CreateTask* create = new CreateTask();
	SearchTask* search = new SearchTask();
	ExitTask* exit = new ExitTask();
	tasks.push_back(create);
	tasks.push_back(search);
	tasks.push_back(exit);
}

void Controller::init_command()
{
	command = new char[Constants::MAX_COMMAND_LENGHT];
}

Controller::Controller()
{
	init_command();
	init_tasks();
}

Controller::~Controller()
{
	delete[] command;
	for (auto task : tasks)
		delete task;
	tasks.clear();
}

void Controller::start()
{
	Task* context = nullptr;
	while (true) 
	{
		std::cin >> command;
		context = get_context(command);
		if (context == nullptr)
			continue;
		if (meets_ending_condition(context))
			break;
		context->execute();
	}
}

bool Controller::meets_ending_condition(const Task* context) const
{
	return typeid(context) == typeid(ExitTask);
}

Task* Controller::get_context(const char* command) const
{
	for (auto task : tasks)
	{
		char* task_command = task->get_command();
		bool are_equal = strcmp(task_command, command) == 0;
		delete[] task_command;
		if (are_equal)
			return task;
	}
	return nullptr;
}




