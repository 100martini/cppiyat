#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm* form = NULL;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
            form = NULL;
        }

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
            form = NULL;
        }

        form = someRandomIntern.makeForm("presidential pardon", "Criminal");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
            form = NULL;
        }

        form = someRandomIntern.makeForm("unknown form", "target");
        if (form) {
            delete form;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}