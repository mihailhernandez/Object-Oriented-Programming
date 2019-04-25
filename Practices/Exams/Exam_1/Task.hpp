#ifndef __TASK__
#define __TASK__

class Task
{
public:
	~Task();
	virtual void execute() = 0;
	char * get_name() const;
	Task& operator=(const Task& other);
	Task(const Task& other);
protected:
	char * name;
	Task(const char * name);
private:
	void copy();
};

#endif 
