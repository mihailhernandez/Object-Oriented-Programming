#include <iostream>
#include <cstring>

class User
{
private:
	char * name;
	int age;
	void copy_from(const User&);
	void free();
public:
	User();
	User(const User&);
	User(const char *, const int);
	~User();
	User& operator=(const User&);
	int get_age() const;
	char * get_name() const;
};

User::User() : name(nullptr), age(18) {}

User::~User()
{
	free();
}

User::User(const char* name, const int age)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->age = age;
}

void User::copy_from(const User& other)
{
	this->name = new char[strlen(other.get_name())];
	strcpy(this->name, other.get_name());
	this->age = other.get_age();
}

void User::free()
{
	delete[] name;
}

User::User(const User& other)
{
	copy_from(other);
}

User& User::operator=(const User& other)
{
	copy_from(other);
	return *this;
}

int User::get_age() const
{
	return age;
}

char * User::get_name() const
{
	char * copy = new char[strlen(name)];
	strcpy(copy, name);
	return copy;
}

class GradesBook
{
public:
	GradesBook();
	~GradesBook();
	GradesBook(const GradesBook&);
	void add_grades(int grade);
	void remove_last_grade();
	bool is_full() const;
	bool is_empty() const;
	friend std::ostream& operator<<(std::ostream&, const GradesBook&);
	GradesBook& operator=(const GradesBook&);
private:
	int size;
	int capacity;
	int * grades;
	bool is_grade_valid(int grade) const;
	void resize();
	friend void copy(const GradesBook&);
};

GradesBook::GradesBook() : capacity(4), grades(new int[4]), size(0) {}

GradesBook::~GradesBook()
{
	delete[] grades;
}

GradesBook::GradesBook(const GradesBook& other)
{
	copy(other);
}

GradesBook& GradesBook::operator=(const GradesBook& other)
{
	copy(other);
	return *this;
}

bool GradesBook::is_full() const
{
	return size == capacity;
}

bool GradesBook::is_empty() const
{
	return size == 0;
}

bool GradesBook::is_grade_valid(int grade) const
{
	return grade >= 2 && grade <= 6;
}

void GradesBook::add_grades(int grade)
{
	if (!is_grade_valid(grade))
		return;
	if (size == capacity)
		resize();
	grades[size++] = grade;
}

void GradesBook::resize()
{
	int * new_grades = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
		new_grades[i] = grades[i];
	capacity *= 2;
	delete[] grades;
	grades = new_grades;
}

void GradesBook::remove_last_grade()
{
	size--;	
}

std::ostream& operator<<(std::ostream& os, const GradesBook& grades_book)
{
	for (int i = 0; i < grades_book.capacity; i++)
		if (i < grades_book.size)
			os << " " << grades_book.grades[i];
		else
			os << " _";
	os << std::endl;
	return os;
}

void GradesBook::copy(const GradesBook& other)
{
	grades = new int[other.capacity];
	for(int i = 0; i < other.capacity; i++)
		grades[i] = other.grades[i];
	size = other.size;
	capacity = other.capacity;
}
	
class Student : public User
{
public:
	Student(const char *, const int, const int);
private:

	int fn;
};

Student::Student(const char * name, const int age, const int fn) 
	: User(name, age),
	  fn(fn) {}

int main()
{
	Student("Mihail Hernandez", 19, 45564);

	return 0;
}
