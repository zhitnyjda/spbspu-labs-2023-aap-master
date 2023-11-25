#include <iostream>
#include <exception>
#include <limits>
#include <windows.h>

using std::string;

bool samge_sing(int num1, int num2);
void errorMessagedExit(string error_message);

struct sequence {
    public:
        sequence() {
            prev_value = 0;
            curr_value = 0;

            local_max = -100; // INT_MIN;
            local_min = 100; // INT_MAX;
        }

        int read() {
            prev_value = curr_value;
            std::cin >> curr_value;
            
            if (!std::cin)
                errorMessagedExit("Ошибка ввода");
            
            if(curr_value > local_max)
                local_max = curr_value;
            
            if(curr_value < local_min)
                local_min = curr_value;
            
            return curr_value;
        }

        bool samge_sing()
        {
            if (prev_value * curr_value >= 0)
                return 1;
            else
                return 0;
        } 

        int lmax() {
            return local_max;
        }

        int lmin() {
            return local_min;
        }

        int cvalue() {
            return curr_value;
        }

        int pvalue() {
            return prev_value;
        }
    private:
        int prev_value;
        int curr_value;

        int count;

        int local_max;  
        int local_min;
};

int main()
{

    sequence _sequence = sequence();

    int prev_max = _sequence.lmax();
    int sing_change_count = 0;
    int local_max_count = 0;


    while (_sequence.read() != 0) {

        if (!_sequence.samge_sing())
            sing_change_count++;
        
        if(prev_max != _sequence.lmax())
            local_max_count = 0;
        
        if(_sequence.cvalue() == _sequence.lmax())
            local_max_count++;

        prev_max = _sequence.lmax();

    }

    std::cout << "kolichestvo izmeneniy znaka: " << sing_change_count << "\n";
    std::cout << "kolichestvo lokalnih maximumov: " << local_max_count << "\n";

}

void errorMessagedExit(string error_message)
{
    std::cout << "\n !!! "
        << "\n | ERROR | " << error_message
        << "\n !!! \n";
    exit(1);
}


