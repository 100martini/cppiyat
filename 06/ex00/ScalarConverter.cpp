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

bool ScalarConverter::isValidChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && 
            literal[1] >= 32 && literal[1] <= 126);
}

bool ScalarConverter::isValidInt(const std::string& literal) {
    if (literal.empty())
        return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isValidFloat(const std::string& literal) {
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
    
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    if (withoutF.empty())
        return false;
    
    size_t start = 0;
    if (withoutF[0] == '+' || withoutF[0] == '-')
        start = 1;
    
    if (start >= withoutF.length())
        return false;
    
    bool hasDot = false;
    for (size_t i = start; i < withoutF.length(); i++) {
        if (withoutF[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!isdigit(withoutF[i])) {
            return false;
        }
    }
    
    return hasDot;
}

bool ScalarConverter::isValidDouble(const std::string& literal) {
    if (literal.empty())
        return false;
    
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    bool hasDot = false;
    for (size_t i = start; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDot;
}

bool ScalarConverter::isInRange(double value, double min, double max) {
    return (value >= min && value <= max);
}

int ScalarConverter::detectType(const std::string& literal) {
    if (literal.empty())
        return INVALID;
    
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return CHAR;
    
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || 
        (literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f'))
        return FLOAT;
    
    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
        literal.find('.') != std::string::npos)
        return DOUBLE;
    
    size_t start = 0;
    if (literal.length() > 0 && (literal[0] == '+' || literal[0] == '-'))
        start = 1;
    
    if (start == 1 && literal.length() == 1)
        return INVALID;
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return INVALID;
    }
    
    return INT;
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || !isInRange(value, 0, 127)) {
        std::cout << "impossible" << std::endl;
    } else if (value < 32 || value == 127) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || !isInRange(value, INT_MIN, INT_MAX)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    
    if (std::isinf(value)) {
        if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }
    
    if (!isInRange(value, -FLT_MAX, FLT_MAX)) {
        if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }
    
    float f = static_cast<float>(value);
    std::cout << f;
    if (f == static_cast<int>(f) && isInRange(f, INT_MIN, INT_MAX))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
        return;
    }
    
    if (std::isinf(value)) {
        if (value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
        return;
    }
    
    std::cout << value;
    if (value == static_cast<int>(value) && isInRange(value, INT_MIN, INT_MAX))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    int type = detectType(literal);
    double value = 0.0;
    
    switch (type) {
        case CHAR:
            value = static_cast<double>(literal[1]);
            break;
        case INT: {
            errno = 0;
            char* endptr;
            long longValue = strtol(literal.c_str(), &endptr, 10);
            
            if (errno == ERANGE || longValue > INT_MAX || longValue < INT_MIN) {
                std::cout << RED << "error: integer overflow!" << RESET << std::endl;
                return;
            }
            if (*endptr != '\0') {
                std::cout << RED << "error: invalid integer format!" << RESET << std::endl;
                return;
            }
            value = static_cast<double>(longValue);
            break;
        }
        case FLOAT: {
            errno = 0;
            char* endptr;
            std::string withoutF = literal.substr(0, literal.length() - 1);
            value = strtod(withoutF.c_str(), &endptr);
            
            if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL)) {
                if (value > 0)
                    value = std::numeric_limits<double>::infinity();
                else
                    value = -std::numeric_limits<double>::infinity();
            }
            if (*endptr != '\0' && errno != ERANGE) {
                std::cout << RED << "error: invalid float format!" << RESET << std::endl;
                return;
            }
            break;
        }
        case DOUBLE: {
            errno = 0;
            char* endptr;
            value = strtod(literal.c_str(), &endptr);
            
            if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL)) {
                if (value > 0)
                    value = std::numeric_limits<double>::infinity();
                else
                    value = -std::numeric_limits<double>::infinity();
            }
            if (*endptr != '\0' && errno != ERANGE) {
                std::cout << RED << "error: invalid double format!" << RESET << std::endl;
                return;
            }
            break;
        }
        default:
            std::cout << RED << "error: invalid literal format!" << RESET << std::endl;
            return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}