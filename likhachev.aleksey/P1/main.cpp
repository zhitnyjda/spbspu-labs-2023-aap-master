#include <iostream>
#include <exception>
#include <windows.h>
#include "sequence.hpp"

int main()
{

    
    likhachev::Sequence _sequence;

    int prev_max = _sequence.lmax();
    int sing_change_count = 0;
    int local_max_count = 0;


    try {
        std::cin.exceptions(std::istream::failbit);
        while (_sequence.read() != 0) {

            if (!_sequence.samge_sing())
                sing_change_count++;
            
            if(prev_max != _sequence.lmax())
                local_max_count = 0;
            
            if(_sequence.cvalue() == _sequence.lmax())
                local_max_count++;

            prev_max = _sequence.lmax();

        }
    } catch (const std::istream::failure & e) {
        std::cerr << "Input error\n";
        return 1;
    } catch (const std::logic_error & e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    if(_sequence.scount() == 0) {
        std::cerr << "The sequence is too small" << "\n";
        return 2;
    }
    
    std::cout << "[SGN-CHG] count of sign changes: " << sing_change_count << "\n";
    std::cout << "[LOC-MAX] count of local maxima: " << local_max_count << "\n";

    return 0;

}


