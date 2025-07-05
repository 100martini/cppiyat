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

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    FormCreator creators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    
    std::cout << "Error: Form \"" << formName << "\" is not known!" << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}