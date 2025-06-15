#ifndef DATA_HPP
#define DATA_HPP

#include <string>

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