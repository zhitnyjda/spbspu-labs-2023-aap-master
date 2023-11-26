#include <iostream>
#include "findlocalmax.hpp"

int main() {
    int value = 0;
    int count = 0;
    using namespace lisitsyna;
    FindLocalMax findLocalMax;
    try {
        std::cin >> value;
        if (std::cin.fail())
        {
            throw 1;
        }
    }
    catch (int ex) {
        std::cerr << "Invalid input!";
        return 1;
    }
    while (value != 0)
    {
        count++;
        try {
            std::cin >> value;
            if (std::cin.fail())
            {
                throw 1;
            }
        }
        catch (int ex) {
            std::cerr << "Invalid input!";
            return 1;
        }
        if (count == 0)
        {
            std::cerr << "Error output (return code 2)" << std::endl;
            return 2;
        }
        else
        {
            findLocalMax(value);
            std::cout << findLocalMax() << std::endl;
            return 0;
        }
    }
}
