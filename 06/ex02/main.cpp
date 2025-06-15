#include <iostream>
#include "functions.hpp"
#include "Base.hpp"

int main() {
    for (int i = 0; i < 6; i++) {
        Base* obj = generate();
        
        std::cout << (i + 1) << ":" << std::endl;
        std::cout << "Object address: " << obj << std::endl;
        
        std::cout << "Identify by pointer: ";
        identify(obj);
        
        std::cout << "Identify by reference: ";
        identify(*obj);
        
        delete obj;
    }
    
    return 0;
}