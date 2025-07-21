#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(i);
    std::cout << bigSpan.shortestSpan() << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    std::list<int> myList;
    myList.push_back(50);
    myList.push_back(25);
    myList.push_back(75);
    myList.push_back(12);
    
    Span rangeSpan(10);
    
    std::cout << PURPLE << "\nadding vector: [1, 2, 3]" << RESET << std::endl;
    rangeSpan.addRange(vec.begin(), vec.end());
    
    try {
        std::cout << GREEN << "longest span after vector: " << RESET << rangeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
    
    std::cout << PURPLE << "\nadding list: [50, 25, 75, 12]" << RESET << std::endl;
    rangeSpan.addRange(myList.begin(), myList.end());

	try {
        std::cout << GREEN << "longest span after vector: " << RESET << rangeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
	}
    
    return 0;
}