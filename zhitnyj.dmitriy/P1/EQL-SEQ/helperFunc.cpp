#include <iostream>
#include <stdexcept>
#include "helpersFunc.h"

int helperFunc::operator()(std::istream *str)
{
	int n_ = 0;

	do
	{
		try
		{
			if(str->peek() != 10 && helperFunc::n == n_)
			{
				std::cout << "Sequence should end with 0!" << std::endl;

				return 1;
			}
			
			*str >> n_;

			if (str->fail())
			{
				std::cout << "Not a sequence!" << std::endl;

				return 2;
			}
			helperFunc::operator()(n_);
		}
		catch(std::exception &err)
		{
			err.what();
		}

	}while(n_);

	std::cout << "Count: " << ( helperFunc::mCount + 1 ) << std::endl;

	return 0;
}

int helperFunc::operator()(int n_)
{
	if (n_ == helperFunc::n)
	{
		helperFunc::count++;

		if(helperFunc::count > helperFunc::mCount)
			helperFunc::mCount = helperFunc::count;
	}
	else
	{
		helperFunc::n = n_;

		helperFunc::count = 0;
	}

	return 0;
}
