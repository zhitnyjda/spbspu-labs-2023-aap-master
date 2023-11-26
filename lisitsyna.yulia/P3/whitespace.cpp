#include "whitespace.hpp"
#include "iostream"

namespace lisitsyna
{
	char str::str_space(char* input)
	{
		std::cin >> std::noskipws;
		while (std::cin >> c)
		{
			input[read++] = c;
			if (c == '\n')
			{
				input[read - 1] = 0;
				break;
			}
		}
		std::cin >> std::skipws;
		return read;
	}
}
