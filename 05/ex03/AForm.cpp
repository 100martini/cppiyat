#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
    //std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    //std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    //std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    //std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name, _gradeToSign, and _gradeToExecute are const and cannot be changed
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
    //std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
    executeAction();
}

void AForm::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "bureaucrat grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.getName() << " (signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << ")";
    return out;
}