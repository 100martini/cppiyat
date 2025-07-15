#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T const &value) {
    std::cout << value << " ";
}

void addOne(int &value) {
    value += 1;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = 5;
    
    std::cout << "Array: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, addOne);
    std::cout << "After +1: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    return 0;
}