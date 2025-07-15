#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#define GREEN "\e[1;32m"
#define RESET "\033[0m"

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

#endif