#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat martini("Martini", 1);
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Wall-E");
        martini.signForm(*rrf);
        martini.executeForm(*rrf);
        delete rrf;

        rrf = someRandomIntern.makeForm("unknown", "target");
    }
    catch (std::exception& e) {
        std::cout << "excep: " << e.what() << std::endl;
    }
    
    return 0;
}