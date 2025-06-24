#include "RPN.hpp"

RPN::RPN()
{
    //std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
    //std::cout << "RPN copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
    //std::cout << "RPN assignment operator called" << std::endl;
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
    //std::cout << "RPN destructor called" << std::endl;
}

int RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            _stack.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw InvalidExpressionException();
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else
        {
            throw InvalidExpressionException();
        }
    }

    if (_stack.size() != 1)
        throw InvalidExpressionException();

    return _stack.top();
}

bool RPN::isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token)
{
    if (token.empty())
        return false;
    
    if (token.length() != 1)
        return false;
    
    if (token[0] >= '0' && token[0] <= '9')
        return true;
    
    return false;
}

int RPN::performOperation(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw DivisionByZeroException();
        return a / b;
    }
    throw InvalidExpressionException();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
    return "Error";
}