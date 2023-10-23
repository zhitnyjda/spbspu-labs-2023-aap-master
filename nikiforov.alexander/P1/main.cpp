#include <iostream>
#include "Header.hpp"

int main()
{
	int countmin = 0;
	try
	{
		countmin = func(std::cin);
		std::cout << countmin;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	  return 1;
	}
}
