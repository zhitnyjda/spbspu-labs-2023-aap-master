#include <iostream>
#include <exception>
#include "numOfchar.hpp"

int main()
{
    panov::NumOfchar numOfchar;
    try
    {
        std::cin.exceptions(std::istream::failbit);
        int value = 0;
        do
        {
            std::cin >> value;
            numOfchar(value);
        } while (value != 0);
    }
    catch (const std::istream::failure& e)
    {
        std::cerr << "OnlyNumberPLS" << "\n";
        return 1;
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    std::cout << numOfchar() << "\n";
    return 0;
}