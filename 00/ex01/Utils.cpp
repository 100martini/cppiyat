#include "Utils.hpp"
#include <sstream>
#include <iostream>
#include <cctype>

std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return ""; 
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool isNotEmptyOrWhitespace(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isspace(static_cast<unsigned char>(str[i])))
            return true;
    }
    return false;
}

std::string reduceMultipleSpacesToOne(const std::string& input) {
    std::string output;
    bool lastWasSpace = false;
    
    for (size_t i = 0; i < input.length(); ++i) {
        if (std::isspace(static_cast<unsigned char>(input[i]))) {
            if (!lastWasSpace) {
                output.push_back(' ');
                lastWasSpace = true;
            }
        } else {
            output.push_back(input[i]);
            lastWasSpace = false;
        }
    }
    return output;
}

bool containsDigit(const std::string& s) {
    for (std::string::size_type i = 0; i < s.length(); i++) {
        if (std::isdigit(s[i])) {
            return true;
        }
    }
    return false;
}

bool isValidPhoneNumber(const std::string& s) {
    if (s.empty())
        return false;
        
    for (std::string::size_type i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!std::isdigit(c) && c != '-' && c != ' ' && c != '+' && c != '(' && c != ')') {
            return false;
        }
    }
    return true;
}

bool handleInputError() {
    if (!std::cin) {
        if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\nCTRL+D was pressed. Exiting the program.\n";
            return true;
        } else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "An error occurred while reading your input. Please try again.\n";
        }
    }
    return false;
}