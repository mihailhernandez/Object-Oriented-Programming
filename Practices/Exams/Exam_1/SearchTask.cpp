#include "SearchTask.hpp"
#include "Actor.hpp"

SearchTask::SearchTask() : Task(Constants::SEARCH) {}

void SearchTask::execute() const
{
	std::ifstream file(Constants::DATABASE_NAME);
	if (!file)
	{
		std::cerr << "Could not open " << Constants::DATABASE_NAME << "!" << std::endl;
		return;
	}
	bool is_seen = false;
	Actor actor;
	while (file.peek() != EOF && !is_seen)
	{
		unsigned long long id;
		std::cin >> id;
		file >> actor;
		if (is_seen = actor.get_id() == id)
			std::cout << actor;
	}
	file.close();
	std::cout << (is_seen ? "Record not found!" : "") << std::endl;
}
