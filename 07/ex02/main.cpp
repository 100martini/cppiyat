#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 2;
        }
        
        std::cout << "Int array contents: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        Array<int> copyArray(intArray);
        std::cout << "Copy array size: " << copyArray.size() << std::endl;
        std::cout << "Copy array contents: ";
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;
        
        copyArray[0] = 1337;
        std::cout << "After modifying copy[0] to 1337:" << std::endl;
        std::cout << "Original array[0]: " << intArray[0] << std::endl;
        std::cout << "Copy array[0]: " << copyArray[0] << std::endl;
        
        Array<std::string> stringArray(3);
        stringArray[0] = "Martini";
        stringArray[1] = "xoxo";
        stringArray[2] = "1337";
        
        std::cout << "String array: ";
        for (unsigned int i = 0; i < stringArray.size(); i++) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Testing out of bounds access..." << std::endl;
        intArray[10];
        
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}