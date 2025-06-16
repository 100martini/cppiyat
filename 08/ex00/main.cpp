#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Element not found" << std::endl;
	}

	try
	{
		easyfind(vec, 10);
	}
	catch (std::exception& e)
	{
		std::cout << "Element not found" << std::endl;
	}

	return 0;
}