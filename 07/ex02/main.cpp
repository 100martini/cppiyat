#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }

int main()
{
    std::cout << PURPLE << "1: Basic construction" << RESET << std::endl;
    Array<int> empty;
    Array<int> numbers(5);
    
    std::cout << "empty array size: " << empty.size() << std::endl;
    std::cout << "numbers array size: " << numbers.size() << std::endl;
    
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    
    std::cout << "numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << PURPLE << "\n2: Copy constructor" << RESET << std::endl;
    Array<int> copy(numbers);
    copy[0] = 1337;
    std::cout << "OG[0]: " << numbers[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;
    std::cout << "Deep copy works? " << (numbers[0] != copy[0] ? "YES." : "NO.") << std::endl;

    std::cout << PURPLE << "\n3: Assignment operator" << RESET << std::endl;
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = 1337;
    std::cout << "OG[1]: " << numbers[1] << std::endl;
    std::cout << "assigned[1]: " << assigned[1] << std::endl;

    std::cout << PURPLE << "\n4: Out of bounds" << RESET << std::endl;
    try {
        std::cout << "trying numbers[10]" << std::endl;
        numbers[10] = 42;
    }
    catch (std::exception &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "trying numbers[-1]" << std::endl;
        numbers[-1] = 42;
    }
    catch (std::exception &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << PURPLE << "\n5: Other types" << RESET << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Khdama?";
    strings[1] = "Khdama";
    strings[2] = "!";
    
    std::cout << "strings: ";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;

    return 0;
}