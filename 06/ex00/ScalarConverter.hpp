#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cerrno>
#define RED "\e[0;31m"
#define RESET "\033[0m"

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static int detectType(const std::string& literal);
    static bool isValidChar(const std::string& literal);
    static bool isValidInt(const std::string& literal);
    static bool isValidFloat(const std::string& literal);
    static bool isValidDouble(const std::string& literal);
    static bool isInRange(double value, double min, double max);
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    static void convert(const std::string& literal);
};

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

#endif