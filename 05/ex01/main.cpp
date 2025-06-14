#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form taxForm("Tax Form", 75, 25);
        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        Form importantForm("Important Form", 1, 1);
        john.signForm(importantForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}