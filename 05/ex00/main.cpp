#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat martini("Martini", 3);
        std::cout << martini << std::endl;
        martini.incrementGrade();
        std::cout << martini << std::endl;

        Bureaucrat invalid("pasvalide", 151);
    }
    catch (std::exception& e) {
        std::cout << "excep: " << e.what() << std::endl;
    }
    return 0;
}