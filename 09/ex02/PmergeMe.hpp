#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    void generateJacobsthalNumbers(std::vector<int>& jacobsthal, int n);
    void mergeInsertSortVector(std::vector<int>& arr);
    void mergeInsertSortDeque(std::deque<int>& arr);
    
    void vectorFordJohnson(std::vector<int>& arr);
    void dequeFordJohnson(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void sortAndCompare();
    void displayResults();

    class InvalidInputException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif