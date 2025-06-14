#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm* form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("presidential pardon", "Criminal");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("unknown form", "target");
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}