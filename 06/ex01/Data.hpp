#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define PURPLE "\e[1;35m"
#define RESET "\033[0m"

struct Data {
    int id;
    std::string name;
    double value;
    
    Data();
    Data(int id, const std::string& name, double value);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

#endif