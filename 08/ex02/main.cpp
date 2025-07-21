#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << GREEN << "ORIGINAL TEST:" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << GREEN << "\nREVERSE ITERATOR TEST:" << RESET << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "\nCONST ITERATOR TEST:" << RESET << std::endl;
    const MutantStack<int>& constStack = mstack;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "\nCOPY CONSTRUCTOR TEST:" << RESET << std::endl;
    MutantStack<int> copy(mstack);
    std::cout << PURPLE << "copy size: " << RESET << copy.size() << std::endl;
    std::cout << PURPLE << "copy top: " << RESET << copy.top() << std::endl;
    
    std::cout << GREEN << "\nCOMPARISON WITH LIST:" << RESET << std::endl;
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << PURPLE << "list: " << RESET;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;
    
    return 0;
}