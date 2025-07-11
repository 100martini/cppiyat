#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat martini("Martini", 50);
        Form taxForm("tax", 75, 25);
        std::cout << martini << std::endl;
        std::cout << taxForm << '\n' << std::endl;
        martini.signForm(taxForm);
        std::cout << taxForm << '\n' << std::endl;
         
        Form importantForm("important", 1, 1);
        martini.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "excep: " << e.what() << std::endl;
    }
    return 0;
}