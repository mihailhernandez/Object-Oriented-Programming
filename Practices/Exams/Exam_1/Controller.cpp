#include <iostream>
#include <fstream>
#include <cstring>
#include "Movie_Star.cpp"

const char* file_name = "Films.db";
const unsigned int MAX_TASK_NAME_LEN = 6;

const char* TASK_CREATE = "create";
const char* TASK_SEARCH = "search";
const char* TASK_EXIT   = "exit";

enum Task
{
	CREATE,
	SEARCH,
	EXIT
};

class Controller
{
public:

	void do_task() const 
	{
		if (task == Task::CREATE)
			create();
		if (task == Task::SEARCH)
			search();
	}

	void search() const
	{
		unsigned int search_id;
		std::cin >> search_id;
		std::ifstream file(file_name);
		if (!file)
		{
			std::cerr << "Error opening file " << file_name << "!" << std::endl;
			return;
		}
		bool found = false;
		while (file.peek() != EOF) 
		{
			unsigned long long id;
			unsigned long long films;
			char first_name[MAX_NAME_LEN];
			char last_name[MAX_NAME_LEN];
			unsigned long long first_name_len;
			unsigned long long last_name_len;
			file.read((char*)&id, sizeof(unsigned long long));
			file.read((char*)&first_name_len, sizeof(unsigned long long));
			file.read((char*)&first_name, first_name_len * sizeof(char));
			file.read((char*)&last_name_len, sizeof(unsigned long long));
			file.read((char*)&last_name, last_name_len * sizeof(char));
			file.read((char*)&films, sizeof(unsigned long long));
			Movie_Star star(id, first_name, last_name, films);
			if (id == search_id)
			{
				found = true;
				std::cout << star;
			}
		}
		if (!found)
			std::cout << "Record not found!" << std::endl;
		file.close();
	}

	void create() const
	{
		std::ofstream file(file_name, std::ios::app);
		if (!file)
		{
			std::cerr << "Could not open " << file_name << "!" << std::endl;
			return;
		}	
		unsigned long long id;
		unsigned long long films;
		char first_name[MAX_NAME_LEN];
		char last_name[MAX_NAME_LEN];
		std::cin >> id;
		std::cin >> first_name;
		std::cin >> last_name;
		std::cin >> films;
		unsigned long long first_name_len = strlen(first_name);
		unsigned long long last_name_len = strlen(last_name);
		file.write((char*)&id, sizeof(unsigned long long));
		file.write((char*)&first_name_len, sizeof(unsigned long long));
		file.write((char*)&first_name, first_name_len * sizeof(char));
		file.write((char*)&last_name_len, sizeof(unsigned long long));
		file.write((char*)&last_name, last_name_len * sizeof(int));
		file.write((char*)&films, sizeof(unsigned long long));
		Movie_Star star(id, first_name, last_name, films);
		std::cout << star;
		file.close();
		std::cout << "Record saved!" << std::endl;
	}

	bool set_task(const char* task_name)
	{
		if (are_same(task_name, TASK_SEARCH))
		{
			this->task = Task::SEARCH;
			return true;
		}
		if (are_same(task_name, TASK_CREATE))
		{
			this->task = Task::CREATE;
			return true;
		}
		if (are_same(task_name, TASK_EXIT))
		{
			this->task = Task::EXIT;
			return true;
		}
		return false;
	}

	Task get_task() const
	{
		return this->task;
	}

private:
	Task task = Task::EXIT;

	bool are_same(const char* task_name, const char* task)
	{
		unsigned int task_name_len = strlen(task_name);
		unsigned int task_len = strlen(task);
		if (task_name_len != task_len)
			return false;
		for (int i = 0; i < task_len; i++)
			if (task_name[i] != task[i])
				return false;
		return true;
	}
};
