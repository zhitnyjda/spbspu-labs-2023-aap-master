#include <iostream>
#include <exception>
#include <limits>
#include <windows.h>

using std::string;

bool samge_sing(int num1, int num2);
void errorMessagedExit(string error_message);

int main()
{

    int first_value = 0;
    std::cin >> first_value;

    int prev_value = first_value;
    int new_value = first_value;
    int local_max = first_value;

    int sing_change_count = 0;
    int local_max_count = 0;


    while (new_value != 0) {

        if (!samge_sing(prev_value, new_value))
            sing_change_count++;
        
        if(local_max <= new_value) {
            if(local_max < new_value) {
                local_max = new_value;
                local_max_count = 1;
            } else {
                local_max_count++;
            }   
        }

        if (!std::cin)
            errorMessagedExit("Ошибка ввода");
        
        prev_value = new_value;
        std::cin >> new_value;
    }

    std::cout << "kolichestvo izmeneniy znaka: " << sing_change_count << "\n";
    std::cout << "kolichestvo lokalnih maximumov: " << local_max_count << "\n";

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


