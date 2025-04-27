#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "Testing INFO level:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "Testing WARNING level:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "Testing ERROR level:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "Testing invalid level:" << std::endl;
    harl.complain("INVALID");
    
    return 0;
}