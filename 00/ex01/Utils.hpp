#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#define RED "\e[0;31m"
#define PURPLE "\e[0;35m"
#define GREEN "\e[0;32m"
#define RESET "\033[0m"
#define YELLOW "\e[1;33m"
#define YELLOWISH "\e[0;33m"
#define PURPLISH "\e[1;35m"

std::string intToString(int value);
std::string trim(const std::string& str);
bool isNotEmptyOrWhitespace(const std::string& str);
std::string reduceMultipleSpacesToOne(const std::string& input);
bool containsDigit(const std::string& s);
bool isValidPhoneNumber(const std::string& s);
bool handleInputError();

#endif