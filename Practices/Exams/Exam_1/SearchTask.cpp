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
	Actor* actor;
	while (file.peek() != EOF && !is_seen)
	{
		long long id_entry;
		actor = new Actor();
		std::cin >> id_entry;
		long long id, films;
		int first_name_len, last_name_len;
		file.read((char*)& id, sizeof(long long));
		file.read((char*)& first_name_len, sizeof(int));
		char* first_name = new char[first_name_len + 1];
		file.read((char*)& first_name, sizeof(char) * first_name_len);
		first_name[first_name_len + 1] = '\0';
		file.read((char*)& last_name_len, sizeof(int));
		char* last_name = new char[last_name_len + 1];
		file.read((char*)& last_name, sizeof(char) * last_name_len);
		last_name[last_name_len + 1] = '\0';
		file.read((char*)& films, sizeof(long long));
		actor->set_id(id);
		actor->set_films(films);
		actor->set_first_name(first_name);
		actor->set_last_name(last_name);
		std::cout << actor;
		is_seen = id_entry == actor->get_id();
		if (is_seen)
			std::cout << *actor;
		delete actor;
	}
	file.close();
	std::cout << (is_seen ? "Record not found!" : "") << std::endl;
}
