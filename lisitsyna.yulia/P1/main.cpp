#include<iostream> 
 
int main() {
    int value = 0, lastvalue = 0;
    unsigned int count = 0, maxcount = 0;
    bool growing = false;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cerr << "Error input (return code 1)" << std::endl;
        return 1;
    }
    lastvalue = value;
    while (value != 0)
    {
        if (value > lastvalue)
        {
            growing = true;
        }
        else if (value < lastvalue && growing == true) 
        {
            maxcount++;
            growing = false;
        }
        else 
        {
            growing = false;
        }
        if (count == 1 && lastvalue > value) 
        {
            maxcount++;
        }
        lastvalue = value;
        count++;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cerr << "Error input (return code 1)" << std::endl;
            return 1;
        }
    }
    if (count == 0)
    {
        std::cerr << "Error output (return code 2)" << std::endl;
        return 2;
    }
    else
    {
        std::cout << maxcount << std::endl;
        return 0;
    }
}
