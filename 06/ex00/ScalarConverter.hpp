#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cctype>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static int detectType(const std::string& literal);
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