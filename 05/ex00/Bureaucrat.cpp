#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {
    //std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    validateGrade(grade);
    std::cout << "Bureaucrat " << _name << " with grade " << _grade << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    //std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    //std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    //std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade--;
    std::cout << _name << "'s grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (_grade == LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    _grade++;
    std::cout << _name << "'s grade decremented to " << _grade << std::endl;
}

void Bureaucrat::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}