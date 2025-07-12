#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat martini("Martini", 1);
        Bureaucrat mcMurphy("McMurphy", 50);
        Bureaucrat n3ini3a("N3ini3a", 150);

        ShrubberyCreationForm shrub("Chajara");
        RobotomyRequestForm robot("Wall-E");
        PresidentialPardonForm pardon("SRAAAAA9");

        std::cout << GREEN << "Shrubbery Form" << RESET << std::endl;
        std::cout << shrub << std::endl;
        mcMurphy.signForm(shrub);
        mcMurphy.executeForm(shrub);
        std::cout << shrub << std::endl;

        std::cout << GREEN << "\nRobotomy Form" << RESET << std::endl;
        std::cout << robot << std::endl;
        martini.signForm(robot);
        martini.executeForm(robot);
        std::cout << robot << std::endl;

        std::cout << GREEN << "\nPresidential Pardon Form" << RESET << std::endl;
        std::cout << pardon << std::endl;
        martini.signForm(pardon);
        martini.executeForm(pardon);
        std::cout << pardon << std::endl;

        std::cout << GREEN << "\nFailures" << RESET << std::endl;
        PresidentialPardonForm failForm("SRAAAAA9");
        n3ini3a.signForm(failForm);
        n3ini3a.executeForm(failForm);

    }
    catch (std::exception& e) {
        std::cout << "excep: " << e.what() << std::endl;
    }
    return 0;
}