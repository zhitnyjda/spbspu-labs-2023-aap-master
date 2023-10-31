#include <iostream>
#include "helpersFunc.h"

int helperFunc::findCount()
{
	int elm = 0;
	int len_ = 0;
	int prevElm = 0;

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

	prevElm = elm;

	if(!(*helperFunc::elm >> elm))
	{
		std::cerr << "Can't identify given data as sequence!" << std::endl;

		return 1;
	}

	while(elm)
	{
		len_++;

		if (elm == prevElm)
		{
			helperFunc::count++;

			if (helperFunc::count > helperFunc::maxCount)
				helperFunc::maxCount = helperFunc::count;
		}
		else
			helperFunc::count = 0;

		prevElm = elm;

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

	std::cout << "\nElements count: " << ( helperFunc::maxCount + 1 ) << std::endl;

	return 0;
}