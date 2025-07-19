#ifndef ARRAY_HPP
#define ARRAY_HPP
#define PURPLE "\e[1;32m"
#define RESET "\033[0m"

#include <exception>

template<typename T>
class Array {
private:
    T *_array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &other);
    Array<T> &operator=(const Array<T> &other);
    ~Array();
    
    T &operator[](int index);
    const T &operator[](int index) const;
    unsigned int size() const;
    
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif