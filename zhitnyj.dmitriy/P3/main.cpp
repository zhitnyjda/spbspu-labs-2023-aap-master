#include "functionSeqSym.h"
#include "functionDgtSnd.h"
#include <iostream>

int main()
{
    char* str = new char();
    char* str_ = new char();

    try
    {
        std::cin >> str >> str_;

        if(!*str || !*str_)
        {
            throw std::logic_error("Input error!");
        }

        std::cout << strSymbolsRepeats(str) << std::endl;
        std::cout << appendNumToStr(str, str_) << std::endl;
    }
    catch(const std::logic_error& err)
    {
        std::cerr << err.what() << std::endl;
        return 1;
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
