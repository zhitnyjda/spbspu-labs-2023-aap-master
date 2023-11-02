#include "findmaxima.hpp"
#include <limits>

namespace redko
{
  FindMaxima::FindMaxima() :
    firstMaxValue(std::numeric_limits< int > ::min()), secondMaxValue(std::numeric_limits< int > ::min())
  {}
  void FindMaxima::operator()(int value) {
    if (value > firstMaxValue)
    {
      secondMaxValue = firstMaxValue;
      firstMaxValue = value;
    }
    else if (value > secondMaxValue)
    {
      secondMaxValue = value;
    }
  }
  int FindMaxima::operator()() const
  {
    return secondMaxValue;
  }
}
