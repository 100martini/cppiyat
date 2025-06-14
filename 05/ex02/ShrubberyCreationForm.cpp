#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    //std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    //std::cout << "ShrubberyCreationForm parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {
    //std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    //std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    //std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        throw FileWriteException();
    }
    
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file << "\n";
    file << "     _-_-_\n";
    file << "  /~     ~\\\n";
    file << " |  () () |\n";
    file << "  \\   ^   /\n";
    file << "   ||||||\n";
    file << "   ||||||\n";
    
    file.close();
    std::cout << "ASCII trees written to " << filename << std::endl;
}

const char* ShrubberyCreationForm::FileWriteException::what() const throw() {
    return "Could not create or write to file!";
}