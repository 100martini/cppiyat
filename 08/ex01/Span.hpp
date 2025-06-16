#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _numbers.size() > _maxSize)
			throw std::exception();
		_numbers.insert(_numbers.end(), begin, end);
	}

	class FullSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Span is full";
		}
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "No span can be found";
		}
	};
};

#endif