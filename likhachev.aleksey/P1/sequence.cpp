#include "sequence.hpp"
#include <limits>
#include <iostream>

likhachev::Sequence::Sequence():
  prev_value(0), curr_value(0), local_max(INT_MIN), local_min(INT_MAX)
{}

int likhachev::Sequence::read() {
    prev_value = curr_value;
    std::cin >> curr_value;
    
    if (!std::cin)
        std::cerr << "Ошибка ввода" << "\n";
    
    if(curr_value > local_max)
        local_max = curr_value;
    
    if(curr_value < local_min)
        local_min = curr_value;
    
    return curr_value;
}

bool likhachev::Sequence::samge_sing() {
    if (prev_value * curr_value >= 0)
        return 1;
    else
        return 0;
} 

int likhachev::Sequence::lmax() {
    return local_max;
}

int likhachev::Sequence::lmin() {
    return local_min;
}

int likhachev::Sequence::cvalue() {
    return curr_value;
}

int likhachev::Sequence::pvalue() {
    return prev_value;
}