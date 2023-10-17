#include <iostream>
#include <limits>

#define ll long long

void inputNumber(ll &number)
{
    using namespace std;
    char input_number[20];
    try {
        cin >> input_number;
        number = stoll(input_number);
    } catch (std::logic_error &error) {
        cout << "Неправильный ввод\n";
        exit(2);
    }
}

int main()
{
    using namespace std;
    ll max_count = numeric_limits<long long>::max(), count = 0, min_member = numeric_limits<long long>::max();
    ll number;
    inputNumber(number);
    while (number != 0) {
        if (number == min_member && count < max_count) ++count;
        if (number == min_member && count == max_count) {
            cout << "Слишком много минимальных элементов\n";
            exit(2);
        }
        if (number < min_member) {
            min_member = number;
            count = 1;
        }
        inputNumber(number);
    }
    cout << count << "\n";
}
