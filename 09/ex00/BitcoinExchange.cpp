#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
    //std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    //std::cout << "BitcoinExchange assignment operator called" << std::endl;
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw DatabaseLoadException();

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::string rate_str = line.substr(pos + 1);
            float rate = static_cast<float>(std::atof(rate_str.c_str()));
            _database[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileNotFoundException();

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);
        std::string value_str = line.substr(pos + 3);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(value_str, value))
        {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = findExchangeRate(date);
        float result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2022)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, float& val)
{
    char* endptr;
    val = std::strtof(value.c_str(), &endptr);
    
    if (*endptr != '\0')
        return false;
    
    if (val < 0)
        return false;
    
    if (val > 1000)
        return false;
    
    return true;
}

float BitcoinExchange::findExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _database.find(date);
    if (it != _database.end())
        return it->second;

    std::map<std::string, float>::iterator lower = _database.lower_bound(date);
    if (lower == _database.begin())
        return _database.begin()->second;
    
    --lower;
    return lower->second;
}

const char* BitcoinExchange::FileNotFoundException::what() const throw()
{
    return "Error: could not open file.";
}

const char* BitcoinExchange::DatabaseLoadException::what() const throw()
{
    return "Error: could not load database.";
}