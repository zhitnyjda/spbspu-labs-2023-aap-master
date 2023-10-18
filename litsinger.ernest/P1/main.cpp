#include <iostream>

int main()
{
    setlocale(0, "ru");
    int k = 0, mx = 0;
    double n;
    std::cin >> n;
    if (-32768 > n || n > 32767)
    {
        std::cout << "Ёлемент не подходит\n";
        return 1;
    }
    if (n != int(n))
    {
        std::cout << "Ёлементы должны задаватьс€ целыми числами\n";
        return 1;
    }
    if (std::cin.fail())
    {
        std::cout << "Ёлементы должны задаватьс€ числами\n";
        return 1;
    }
    if (n == 0)
    {
        std::cout << "ѕоследовательность слишком коротка€\n";
        return 2;
    }
    k = 1;
    mx = n;
    while (n != 0)
    {
        std::cin >> n;
        if (n > mx)
        {
            mx = n;
            k = 1;
        }
        if (n == mx)
        {
            k += 1;
        }
        if (n != int(n))
        {
            std::cout << "Ёлементы должны задаватьс€ целыми числами\n";
            return 1;
        }
        if (std::cin.fail())
        {
            std::cout << "Ёлементы должны задаватьс€ числами\n";
            return 1;
        }
        if (-32768 > n || n > 32767)
        {
            std::cout << "Ёлемент не подходит\n";
            return 1;
        }
    }
    std::cout << k;
    return 0;
}

