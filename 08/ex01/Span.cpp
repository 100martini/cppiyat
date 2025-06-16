#include "Span.hpp"

Span::Span() : _maxSize(0)
{
	//std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
	//std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	//std::cout << "Span assignment operator called" << std::endl;
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
	//std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return *maxIt - *minIt;
}