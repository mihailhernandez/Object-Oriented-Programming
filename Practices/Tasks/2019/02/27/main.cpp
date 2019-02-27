#include <iostream>
#include <cstdlib>

#define SIZE 4
const int s = 4;

void func();
//void func();  redefinition error.

int sum(int a, int b);

// Same as above.
// int sum(int a, int b);

// Valid because of the different signatures.
double sum(double a, double b);

// Not valid because the compiler doesn't know which function
// with 2 int arguments we want.
// double sum(int a, int b);

const size_t MAX_NUMBER_OF_STUDENTS = 1;
const size_t MAX_NUMBER_OF_GRADES = 10;

struct Student 
{
    public:

    unsigned int faculty_number;
    char *grades;

    public:

    void print()
    {
        std::cout << "Faculty number: " << faculty_number << std::endl;
        std::cout << "Grades: ";
        for (size_t i = 0; i < 10; std::cout << grades[i++] << " ");
        std::cout << std::endl;
    }

    // Setter / mutator for the faculty number field
    void set_faculty_number(const unsigned int faculty_number)
    {
        this->faculty_number = faculty_number;
    }

    // Setter / mutator for the grades field
    void set_grades(char *grades)
    {
        this->grades = grades; 
    }

    // Getter / accessor for the faculty number field 
    unsigned int get_faculty_number() const 
    {
        return faculty_number;
    }

    // Getter / accessor for the grades field 
    char* get_grades() const
    {
        return grades;
    }
};

int main()
{  

    Student students[MAX_NUMBER_OF_STUDENTS];

    for (size_t i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
    {
        char *grades = new char[MAX_NUMBER_OF_GRADES];
        unsigned int fac_num;
        std::cin >> fac_num;
        for (size_t j = 0; j < MAX_NUMBER_OF_GRADES; j++)
            std::cin >> grades[j];
        students[i].set_faculty_number(fac_num);
        students[i].set_grades(grades);
    }

    for (size_t i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
        students[i].print();

    return 0;
}
