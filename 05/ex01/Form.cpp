#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
    //std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    std::cout << "Form " << _name << " created (sign: " << _gradeToSign 
              << ", exec: " << _gradeToExecute << ")" << std::endl;
}

Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    //std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name, _gradeToSign, and _gradeToExecute are const, so we can only copy _signed
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {
    //std::cout << "Form " << _name << " destroyed" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
    std::cout << "Form " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void Form::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "bureaucrat grade is too low to sign this form!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() << " (signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << ")";
    return out;
}