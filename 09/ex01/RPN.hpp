#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(const std::string& expression);
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int performOperation(int a, int b, const std::string& op);

    class InvalidExpressionException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class DivisionByZeroException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif