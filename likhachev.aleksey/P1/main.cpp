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


