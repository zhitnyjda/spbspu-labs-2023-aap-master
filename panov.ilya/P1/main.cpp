#include <iostream>
#include "numberOfSequenceCharacterChanges.hpp"

int main()
{
    int ya_krutoi = 0;
    try {
        ya_krutoi = numberOfSequenceCharacterChanges(std::cin);
    }
    catch (std::logic_error const& error) {
        std::cout << error.what() << "\n";
        return 2;
    }
    std::cout << ya_krutoi << "\n";
}
