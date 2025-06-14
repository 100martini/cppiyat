#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;
        
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}