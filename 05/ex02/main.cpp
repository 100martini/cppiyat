#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << "\nShrubbery Form:" << std::endl;
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);

        std::cout << "\nRobotomy Form:" << std::endl;
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);

        std::cout << "\nPresidential Pardon Form:" << std::endl;
        std::cout << pardon << std::endl;
        alice.signForm(pardon);
        alice.executeForm(pardon);

        std::cout << "\nFailures:" << std::endl;
        PresidentialPardonForm failForm("Criminal");
        charlie.signForm(failForm);
        charlie.executeForm(failForm);

    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}