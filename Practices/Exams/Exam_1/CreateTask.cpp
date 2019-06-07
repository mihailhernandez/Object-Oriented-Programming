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
		long long id, films;
		char* first_name = new char[Constants::MAX_NAME_LEN];
		char* last_name = new char[Constants::MAX_NAME_LEN];
		std::cin >> id >> first_name >> last_name >> films;
		int first_name_len = strlen(first_name);
		int last_name_len = strlen(last_name);
		file.write((const char*)& id, sizeof(long long));
		file.write((const char*)& first_name_len, sizeof(int));
		file.write((const char*)& first_name, sizeof(char) * first_name_len);
		file.write((const char*)& last_name_len, sizeof(int));
		file.write((const char*)& last_name, sizeof(char) * last_name_len);
		file.write((const char*)& films, sizeof(long long));
		delete[] first_name;
		delete[] last_name;
		file.close();
		std::cout << "Record saved!" << std::endl;
	}
