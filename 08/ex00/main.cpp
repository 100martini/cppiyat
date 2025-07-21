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
		std::cout<< "L9inaha! wach " << *it << "?" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Mal9inahach :(" << std::endl;
	}

	vec.pop_back();
	try
	{
		easyfind(vec, 3);
	}
	catch (std::exception& e)
	{
		std::cout << "Mal9inahach :(" << std::endl;
	}

	return 0;
}