#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    //std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
    //std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    //std::cout << "PmergeMe assignment operator called" << std::endl;
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    //std::cout << "PmergeMe destructor called" << std::endl;
}

void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (arg[j] < '0' || arg[j] > '9')
                throw InvalidInputException();
        }
        
        long num = std::atol(arg.c_str());
        if (num < 0 || num > 2147483647)
            throw InvalidInputException();
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
    
    if (_vectorData.empty())
        throw InvalidInputException();
}

void PmergeMe::generateJacobsthalNumbers(std::vector<int>& jacobsthal, int n)
{
    if (n <= 0)
        return;
    
    jacobsthal.push_back(1);
    if (n > 1)
        jacobsthal.push_back(3);
    
    for (int i = 2; jacobsthal[i-1] < n; i++)
    {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next >= n)
            break;
        jacobsthal.push_back(next);
    }
}

void PmergeMe::vectorFordJohnson(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] > arr[i + 1])
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            else
                pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
        else
        {
            unpaired = arr[i];
        }
    }
    
    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }
    
    std::sort(mainChain.begin(), mainChain.end());
    
    std::vector<int> jacobsthal;
    generateJacobsthalNumbers(jacobsthal, static_cast<int>(pendingChain.size()));
    
    std::vector<bool> inserted(pendingChain.size(), false);
    
    for (size_t i = 0; i < jacobsthal.size(); i++)
    {
        int idx = jacobsthal[i] - 1;
        if (idx >= 0 && idx < static_cast<int>(pendingChain.size()) && !inserted[idx])
        {
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[idx]);
            mainChain.insert(pos, pendingChain[idx]);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 0; i < pendingChain.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[i]);
            mainChain.insert(pos, pendingChain[i]);
        }
    }
    
    if (unpaired != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
    
    arr = mainChain;
}

void PmergeMe::dequeFordJohnson(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    std::deque<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] > arr[i + 1])
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            else
                pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
        else
        {
            unpaired = arr[i];
        }
    }
    
    std::deque<int> mainChain;
    std::deque<int> pendingChain;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }
    
    std::sort(mainChain.begin(), mainChain.end());
    
    std::vector<int> jacobsthal;
    generateJacobsthalNumbers(jacobsthal, static_cast<int>(pendingChain.size()));
    
    std::vector<bool> inserted(pendingChain.size(), false);
    
    for (size_t i = 0; i < jacobsthal.size(); i++)
    {
        int idx = jacobsthal[i] - 1;
        if (idx >= 0 && idx < static_cast<int>(pendingChain.size()) && !inserted[idx])
        {
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[idx]);
            mainChain.insert(pos, pendingChain[idx]);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 0; i < pendingChain.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[i]);
            mainChain.insert(pos, pendingChain[i]);
        }
    }
    
    if (unpaired != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
    
    arr = mainChain;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    vectorFordJohnson(arr);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    dequeFordJohnson(arr);
}

void PmergeMe::sortAndCompare()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
    {
        std::cout << _vectorData[i] << " ";
    }
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    clock_t start = clock();
    mergeInsertSortVector(_vectorData);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    start = clock();
    mergeInsertSortDeque(_dequeData);
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After: ";
    for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
    {
        std::cout << _vectorData[i] << " ";
    }
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << dequeTime << " us" << std::endl;
}

void PmergeMe::displayResults()
{
    sortAndCompare();
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
    return "Error";
}