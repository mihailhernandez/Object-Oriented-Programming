#include <iostream>
#include <cstring>

bool has_digits(const char * str)
{
	for (const char * c = str; *c; c++)
		if (*c >= '0' && *c <= '9')
			return true;
	return false;
}

class InformaticsStudent
{
	private:

	char * name;
	int fn;

	public:

	InformaticsStudent() {}
	
	InformaticsStudent(const char * name, const int fn)
	{
		set_name(name);
		set_fn(fn);
	}

	InformaticsStudent(const InformaticsStudent& other)
	{
		set_name(other.get_name());
		set_fn(other.get_fn());
	}

	InformaticsStudent& operator=(const InformaticsStudent& other)
	{
		if (this == &other)
		{
			delete[] name;
			set_name(other.get_name());
			set_fn(other.get_fn());
		}
		return *this;
	}

	~InformaticsStudent()
	{
		delete[] name;
	}

	const char * get_name() const
	{
		return name;
	}

	int get_fn() const
	{
		return fn;		
	}

	void set_name(const char * name)
	{
		int len = strlen(name);
		if (len > 9 || has_digits(name))
		{
			this->name[0] = '\0';
			return;
		}
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}

	void set_fn(const int fn)
	{
		if (fn < 40000 || fn > 50000)
		{
			this->fn = 40000;
			return;
		}
		this->fn = fn;
	}

	void print() const
	{
		std::cout << name << std::endl << fn << std::endl;
	}
};

int main()
{
	InformaticsStudent student("misho", 45333);
	InformaticsStudent student2(student);
	InformaticsStudent student3 = student2;
	student.print();
	student2.print();
	student3.print();
	return 0;
}
