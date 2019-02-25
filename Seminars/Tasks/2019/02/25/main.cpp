#include <iostream>
#include <fstream> // files and streams for files 

/* 1. Files
        1.1. std::cout - standard(basic) output
        1.2. How do streams work?
        1.3. Unary counting system
        1.4. 1 bits -> 0/1    1 byte -> 2^8 = 256 combo
        1.5. byte representation using 2 hexadecimal slots (16 x 16 = 256 = 1 byte combos)
*/
int main()
{
    // Output file stream variable named of.
    std::ofstream of;

    // Input file stream variable named iff
    std::ifstream iff;

    // Open relative or absolute path of a file
    // If the file is non-existent create a new one that's empty
    of.open("a.txt" /* ios::app to append */);

    iff.open("a.txt");
  
    // If the file has failed return true
    std::cout << "Has the file failed ?" << std::endl
              << std::boolalpha << of.fail() << std::endl;

    // Add numbers to the file.
    of << "111" << std::endl;
    of << "113" << std::endl;
    of << "121" << std::endl;
    of << "161" << std::endl;

    int num;
   
    // Read until the file reaches EOF (end of file).
    while (!iff.eof())
    {
        iff >> num;
        if (iff.eof())
            break;
        std::cout << num << std::endl;
    }

    // Close the streams.
    of.close();
    iff.close();

    return 0;
}   
