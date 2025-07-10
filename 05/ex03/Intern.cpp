#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
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
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    AForm* (*creators[])(const std::string&) = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "unknown form type!";
}