#include <iostream>
#include "helpersFunc.h"

int helperFunc::findCount()
{
	int elm = 0;
	int len_ = 0;
	int count = 0;

	if(!(*helperFunc::elm >> elm))
	{
		std::cerr << "Can't get element from stream!" << std::endl;

		return 2;
	}

	if(!elm)
	{
		std::cerr << "Can't get element from stream!" << std::endl;

		return 2;
	}

	while(elm)
	{
		len_++;
		helperFunc::count++;
		helperFunc::sum += elm;

		if(helperFunc::count == 3)
		{
			if(elm == (helperFunc::sum - elm))
				count++;

			helperFunc::count = 0;
			helperFunc::sum = 0;
		}

		if(!(*helperFunc::elm >> elm))
		{
			std::cerr << "Can't get element from stream!" << std::endl;

			return 2;
		}
	}

	if(len_ < 3)
	{
		std::cerr << "Can't identify given data as sequence!" << std::endl;

		return 1;
	}

	std::cout << "\nElements count: " << count << std::endl;

	return 0;
}
