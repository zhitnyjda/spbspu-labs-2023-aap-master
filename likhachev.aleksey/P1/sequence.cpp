#include "sequence.hpp"
#include <limits>
#include <iostream>

likhachev::Sequence::Sequence() :
  prevValue(0), currValue(0), count(0),
  localMax(std::numeric_limits< int >::min()),
  localMin(std::numeric_limits< int >::max())
{}

int likhachev::Sequence::read()
{
  prevValue = currValue;
  std::cin >> currValue;
  if (currValue > localMax) {
    localMax = currValue;
  }
  if (currValue < localMin) {
    localMin = currValue;
  }
  count++;
  return currValue;
}

bool likhachev::Sequence::have_samge_sing() const
{
  if (prevValue * currValue >= 0) {
    return 1;
  } else {
    return 0;
  }
}

int likhachev::Sequence::getLmax() const
{
  return localMax;
}

int likhachev::Sequence::getLmin() const
{
  return localMin;
}

int likhachev::Sequence::getCvalue() const
{
  return currValue;
}

int likhachev::Sequence::getPvalue() const
{
  return prevValue;
}

int likhachev::Sequence::getCount() const
{
  return count;
}
