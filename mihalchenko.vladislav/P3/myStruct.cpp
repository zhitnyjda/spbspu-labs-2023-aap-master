#include <iostream>
#include <cstring>
#include <cmath>
#include "myStruct.hpp"

extern size_t countGlobal;

mihalchenko::DinString::DinString(size_t n, char c)
{
  this->dinstr = new char[n + 1];

  for (size_t i = 0; i < n; i++)
  {
    this->dinstr[i] = c;
  }
  this->dinstr[n] = '\0';
  size = n;
  counterCurrent = 0;
  addArr = 1;
}

mihalchenko::DinString::~DinString()
{
  delete[] dinstr;
}

void mihalchenko::DinString::dinResize()
{
  char* tmp = new char[size + addArr];
  char * newInput = new char[size + addArr];
  for (size_t i = 0; i < size; i++)
  {
    newInput[i] = dinstr[i];
  }
  size = size + addArr;
  delete [] dinstr;
  dinstr = newInput;
}

void mihalchenko::DinString::dinAppend(char elem)
{
  dinstr[counterCurrent++] = elem;
}

void mihalchenko::DinString::dinOutput()
{
  for (size_t i = 0; i < size; i++)
  {
    continue;
  }
}

char * mihalchenko::findIdenticalChars(char * str1, char * str2, size_t size1, size_t size2)
{
    size_t revers = 0;

    (size1 > size2) ? (revers = size2) : (revers = size1);
    char * resultStr = new char[revers];

    revers = 0;
    if (size1 > size2)
    {
      for (size_t i = 0; i < size2; i++)
      {
        if (std::strchr(str1,str2[i]) != 0)
        {
            resultStr[revers] = str2[i];
            revers ++;
        }
      }
    }
    else
    {
      for (size_t i = 0; i < size1; i++)
      {
        if (std::strchr(str2, str1[i]) != 0)
        {
          resultStr[revers] = str1[i];
          revers ++;
        }
      }
    }
    ::countGlobal = revers;
    return resultStr;
}

size_t mihalchenko::arr_uniq(char * mas, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if(i != j)
      {
        if (mas[i] == mas[j])
        {
          std::swap(mas[size - 1], mas[j]);
          size--;
        }
      }
    }
  }
  return size;
}
