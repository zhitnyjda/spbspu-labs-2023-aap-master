#include "funct.hpp"
#include "iostream"

namespace sadofeva
{
	size_t Str::Str_read(char* input) 
	{
        std::cin >> std::noskipws;
        while (std::cin >> c)
        {
            input[read++] =  c;
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
