#include <iostream>
#include <exception>
#include <limits>
#include <windows.h>

using std::string;

bool samge_sing(int num1, int num2);
void errorMessagedExit(string error_message);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int prev_value = 1;
    int new_value = prev_value;

    int sing_change_count = 0;


    while (new_value != 0) {
        if (samge_sing(prev_value, new_value))
            sing_change_count++;

        prev_value = new_value;
        std::cin >> new_value;

        if (!std::cin)
            errorMessagedExit("Ошибка ввода");
    }

    std::cout << "Количество изменений знака: " << sing_change_count;

}

bool samge_sing(int num1, int num2)
{
    if (num1 * num2 > 0)
        return 1;
    else
        return 0;
}

void errorMessagedExit(string error_message)
{
    std::cout << "\n !!! "
        << "\n | ERROR | " << error_message
        << "\n !!! \n";
    exit(1);
}


