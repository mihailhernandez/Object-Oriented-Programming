#include "CreateTask.hpp"
#include "Actor.hpp"

CreateTask::CreateTask() : Task(Constants::CREATE) {}
	
void CreateTask::execute() const
{
		std::ofstream file(Constants::DATABASE_NAME, std::ios::binary | std::ios::app);
		if (!file)
		{
			std::cerr << "Could not open " << Constants::DATABASE_NAME << "!" << std::endl;
			return;
		}
		Actor actor;
		std::cin >> actor;
		file << actor;
		file.close();
		std::cout << "Record saved!" << std::endl;
	}
