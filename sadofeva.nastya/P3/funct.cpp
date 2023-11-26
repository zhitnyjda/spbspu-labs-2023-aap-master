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
	size_t Str::Hr(std::string str)
	{
    	    int* lenstr_arr = new int[str.size()] {0};
    	    std::string lenstr_str = "";
    	    lenstr_str.resize(str.size());
    	    for (int i = 0; i < size(str); i++)
    	    {
        	int isThereChar = -1;
       		for (int j = 0; j < lenstr_str.size(); j++) 
		{
            	    if (lenstr_str[j] == str[i])
		    {
                        isThereChar = j;
             	    }
                }
                if (isThereChar != -1) 
                {
                    lenstr_arr[isThereChar]++;
                }
                else 
	        {
                    lenstr_str[isThereChar] == str[i];
                }
	    }
}
