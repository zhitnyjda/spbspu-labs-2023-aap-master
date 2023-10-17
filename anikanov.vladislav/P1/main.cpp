#include <iostream>
#include <limits>
#include <string>

#define ll long long

inline void inputNumber(ll &number)
{
    char input_number[20];
    try {
        std::cin >> input_number;
        number = std::stoll(input_number);
    } catch (std::logic_error &error) {
        std::cout << "Неправильный ввод\n";
        exit(2);
    }
}

int main()
{
    ll max_count = std::numeric_limits<long long>::max(), count = 0, min_member = std::numeric_limits<long long>::max();
    ll number;
    inputNumber(number);
    while (number != 0) {
        if (number == min_member && count < max_count) ++count;
        if (number == min_member && count == max_count) {
            std::cout << "Слишком много минимальных элементов\n";
            exit(2);
        }
        if (number < min_member) {
            min_member = number;
            count = 1;
        }
        inputNumber(number);
    }
    std::cout << count << "\n";
}
