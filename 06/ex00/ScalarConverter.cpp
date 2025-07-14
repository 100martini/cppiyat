#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    //std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    //std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    //std::cout << "ScalarConverter assignment operator called" << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    //std::cout << "ScalarConverter destructor called" << std::endl;
}

int ScalarConverter::detectType(const std::string& literal) {
    if (literal.empty())
        return INVALID;
    
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return CHAR;
    
    if (literal.find('e') != std::string::npos || literal.find('E') != std::string::npos)
        return DOUBLE;
    
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || 
        literal[literal.length() - 1] == 'f')
        return FLOAT;
    
    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
        literal.find('.') != std::string::npos)
        return DOUBLE;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-') {
        if (literal.length() == 1)
            return INVALID;
        start = 1;
    }
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!isdigit(literal[i]))
            return INVALID;
    }
    
    if (!isValidInt(literal))
        return DOUBLE;
    
    return INT;
}

bool ScalarConverter::isValidInt(const std::string& literal) {
    errno = 0;
    char* endptr;
    long value = strtol(literal.c_str(), &endptr, 10);
    
    if (errno == ERANGE || *endptr != '\0' || value < INT_MIN || value > INT_MAX) {
        return false;
    }
    return true;
}

bool ScalarConverter::isValidDouble(const std::string& literal) {
    errno = 0;
    char* endptr;
    strtod(literal.c_str(), &endptr);
    
    if (*endptr != '\0') {
        if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
            literal == "-inff" || literal == "+inff" || literal == "nanf") {
            return true;
        }
        
        if (*endptr == 'f' && *(endptr + 1) == '\0')
            return true;
        
        return false;
    }
    
    return true;
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else if (value < 32 || value == 127) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    
    if (!std::isnan(value) && !std::isinf(value) && 
        (value > FLT_MAX || value < -FLT_MAX)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    float f = static_cast<float>(value);
    if (std::isnan(f)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    } else {
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    } else {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    int type = detectType(literal);
    double value = 0.0;
    
    switch (type) {
        case CHAR:
            value = static_cast<double>(literal[1]);
            break;
        case INT:
            value = static_cast<double>(atoi(literal.c_str()));
            break;
        case FLOAT:
            if (!isValidDouble(literal)) {
                std::cout << RED << "error: invalid float format!" << RESET << std::endl;
                return;
            }
            value = static_cast<double>(atof(literal.c_str()));
            break;
        case DOUBLE:
            if (!isValidDouble(literal)) {
                std::cout << RED << "error: invalid double format!" << RESET<< std::endl;
                return;
            }
            value = atof(literal.c_str());
            break;
        default:
            std::cout << RED << "error: invalid literal!" << RESET<< std::endl;
            return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}