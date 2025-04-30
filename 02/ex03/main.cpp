#include <iostream>
#include "Point.hpp"

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    
    Point inside(1.0f, 1.0f);
    Point outside(20.0f, 20.0f);
    Point edge(0.0f, 5.0f);
    Point vertex(0.0f, 0.0f);
    
    std::cout << "Point (1, 1) is inside the triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point (20, 20) is inside the triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point (0, 5) is inside the triangle: " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl;
    std::cout << "Point (0, 0) is inside the triangle: " << (bsp(a, b, c, vertex) ? "true" : "false") << std::endl;
    
    return 0;
}