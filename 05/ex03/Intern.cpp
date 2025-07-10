#include "Intern.hpp"

Intern::Intern() {
    //std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    //std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    //std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    //std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    FormCreator forms[] = {
        {"shrubbery creation", &createShrubberyForm},
        {"robotomy request", &createRobotomyForm},
        {"presidential pardon", &createPresidentialForm}
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }

    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "unknown form type!";
}