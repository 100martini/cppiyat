#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 1);
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;

        rrf = someRandomIntern.makeForm("unknown form", "target");
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}