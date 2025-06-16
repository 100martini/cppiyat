#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void print(T const &value) {
    std::cout << value << " ";
}

void addOne(int &value) {
    value += 1;
}

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array (int): ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, addOne);
    std::cout << "After adding 1: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    char charArray[] = {'M', 'a', 'r', 't', 'i', 'n', 'i'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Original array (char): ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;
    
    iter(charArray, charSize, toUpper);
    std::cout << "After toUpper: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;
    
    std::string stringArray[] = {"Martini", "xoxo", "1337"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Array (string): ";
    iter(stringArray, stringSize, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}