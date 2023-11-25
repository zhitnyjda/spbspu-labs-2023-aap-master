#include <limits>
#include <stdexcept>
#include "findlocalmax.hpp"

lisitsyna::FindLocalMax::FindLocalMax() :
    countmaxs_(0) ,maxValue(0)
{}
void lisitsyna::FindLocalMax::operator()(int value)
{
    const size_t maxSize = std::numeric_limits < size_t >::max();
    if (countmaxs_ == maxSize)
    {
        throw std::logic_error("Sequence is too long\n");
    }
    if (value > maxValue)
    {
        maxValue = value;
        countmaxs_ = 0;
        countmaxs_++;
    }
    else if (maxValue == value)
    {
        countmaxs_++;
    }
}
size_t lisitsyna::FindLocalMax::operator()() const
{
    return countmaxs_;
