#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value, float& val);
    float findExchangeRate(const std::string& date);

    class FileNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class DatabaseLoadException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif