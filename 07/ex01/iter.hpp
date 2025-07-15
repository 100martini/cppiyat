#ifndef ITER_HPP
#define ITER_HPP
#define GREEN "\e[1;32m"
#define RESET "\033[0m"

template<typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template<typename T>
void iter(T *array, size_t length, void (*func)(T const &)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif