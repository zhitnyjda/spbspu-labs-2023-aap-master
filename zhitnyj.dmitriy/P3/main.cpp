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

        std::cout << strSymbolsRepeats(str) << std::endl;
        std::cout << appendNumToStr(str, str_) << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
