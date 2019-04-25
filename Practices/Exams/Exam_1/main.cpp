#include <iostream>
#include "Controller.cpp"

int main()
{
	Controller controller;
    bool is_command_valid;			
	char command[MAX_TASK_NAME_LEN];
	do {
		std::cout << "Enter command: ";
		std::cin >> command;
		is_command_valid = controller.set_task(command);
		if (is_command_valid)
			controller.do_task();
		else
			std::cout << "Invalid command!" << std::endl;
	} while(!is_command_valid || controller.get_task() != Task::EXIT);
	return 0;
}

