#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "usage: ./convert <literal>" << std::endl;
        std::cout << "examples:" << std::endl;
        std::cout << "  ./convert 'c'      (char literal)" << std::endl;
        std::cout << "  ./convert 42       (int literal)" << std::endl;
        std::cout << "  ./convert 42.0f    (float literal)" << std::endl;
        std::cout << "  ./convert 42.0     (double literal)" << std::endl;
        std::cout << "  ./convert nan      (special double)" << std::endl;
        std::cout << "  ./convert +inff    (special float)" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
}