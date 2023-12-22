#include <cctype>
#include "varFunc.hpp"

int khomichenko::countDifLat (char * string, int size)
{
  int marker = 0;
  int count = 0;
  const int num = 53;
  char letters[num]={};
  for (int i = 0; i < size; i++)
  {
    if (isalpha(string[i]))
    {
      count = 0;
      for ( int j = 0; j < marker+1; j++)
      {
        if (letters[j] == string[i])
        {
          ++count;
        }
      }
      if (count==0)
      {
        letters[marker]=string[i];
        ++marker;
      }
    }
  }
  return marker;
}
