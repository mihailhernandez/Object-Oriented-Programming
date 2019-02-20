#include <iostream>
#include <cstring>
#include <iomanip> 

struct Student
{

    private:

    unsigned int faculty_number;
    char *first_name;
    char *last_name;

    public:

    Student(const unsigned int fac_num, const char *f_name, const char *l_name) 
    {
        faculty_number = 0;
        first_name = new char[255];
        last_name = new char[255];
        set_faculty_number(fac_num);
        set_first_name(f_name);
        set_last_name(l_name);
    }

    ~Student()
    {
        // std::cout << "Hello, I'm going to destruct "
        //           << first_name << " " << last_name << std::endl;

        delete[] first_name;
        delete[] last_name;
    }

    void print_faculty_number()
    {
        std::cout << faculty_number << std::endl;
    }

    void print_first_name()
    {
        std::cout << first_name << std::endl;
    }
    
    void print_last_name()
    {
        std::cout << last_name << std::endl;
    }

    void set_faculty_number(const unsigned int fac_num)
    {
        faculty_number = fac_num;
    }

    void set_first_name(const char *f_name)
    {
        std::strcpy(first_name, f_name);
    }

    void set_last_name(const char *l_name)
    {
        std::strcpy(last_name, l_name);
    }

    void print()
    {
        print_faculty_number();
        print_first_name();
        print_last_name();
    }
};

int main()
{
    const unsigned int STUDENT_NUM = 4;

    Student students[STUDENT_NUM] = {
        {45564, "Mihail", "Hernandez"},
        {45565, "Alexander", "Todorov"},
        {45566, "Ivan", "Georgiev"},
        {45567, "Luchezar", "Borisov"}
    };

    for (int i = 0; i < STUDENT_NUM; i++)
        students[i].print();

    return 0;
}
