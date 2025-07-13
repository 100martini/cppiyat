#include <iostream>
#include "functions.hpp"
#include "Base.hpp"

int main() {
    for (int i = 0; i < 6; i++) {
        Base* obj = generate();
        
        std::cout << PURPLE << (i + 1) << ":" << RESET << std::endl;
        std::cout << "object address: " << obj << std::endl;
        
        std::cout << "identify by pointer: ";
        identify(obj);
        
        std::cout << "identify by reference: ";
        identify(*obj);
        
        delete obj;
    }
    
    return 0;
}