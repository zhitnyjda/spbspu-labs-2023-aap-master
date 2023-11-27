#include <iostream>
#include "findlocalmax.hpp"

int main() {
    size_t value = 0;
    size_t count = 0;
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
            std::cerr << "Error output (return code 2)" << "\n";
            return 2;
        }
        else
        {
            findLocalMax(value);
            std::cout << findLocalMax() << "\n";
            return 0;
        }
    }
}
