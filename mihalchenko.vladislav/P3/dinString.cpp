#include "dinString.hpp"
#include <iostream>
#include <cstring>
#include <cmath>

extern size_t countGlobal;

mihalchenko::DinString::DinString(size_t n)
{
  this->dinstr_ = new char[n + 1];

  for (size_t i = 0; i <= n; i++)
  {
    this->dinstr_[i] = '\0';
  }
  size_ = n;
  counterCurrent_ = 0;
  addArr_ = 10;
}

mihalchenko::DinString::~DinString()
{
  delete[] dinstr_;
}

void mihalchenko::DinString::dinResize()
{
  char *newInput = new char[size_ + addArr_];
  for (size_t i = 0; i < size_; i++)
  {
    newInput[i] = dinstr_[i];
  }
  for (size_t i = size_; i < size_ + addArr_; i++)
  {
    newInput[i] = '\0';
  }
  size_ = size_ + addArr_;
  if (dinstr_ != nullptr)
  {
    delete[] dinstr_;
  }
  dinstr_ = newInput;
}

void mihalchenko::DinString::dinAppend(char elem)
{
  dinstr_[counterCurrent_++] = elem;
}

size_t mihalchenko::DinString::getSize()
{
  return size_;
}

size_t mihalchenko::DinString::getCounterCurrent()
{
  return counterCurrent_;
}

char *mihalchenko::DinString::getDinstr()
{
  return dinstr_;
}

char *mihalchenko::findIdenticalChars(char *str1, char *str2, size_t size1, size_t size2)
{
  size_t revers = 0;

  (size1 > size2) ? (revers = size2) : (revers = size1);
  char *resultStr = new char[revers];

  revers = 0;
  if (size1 > size2)
  {
    for (size_t i = 0; i < size2; i++)
    {
      if ((std::strchr(str1, str2[i]) != 0) && (str2[i] != '\0'))
      {
        resultStr[revers] = str2[i];
        revers++;
      }
    }
  }
  else
  {
    for (size_t i = 0; i < size1; i++)
    {
      if ((std::strchr(str2, str1[i]) != 0) && (str1[i] != '\0'))
      {
        resultStr[revers] = str1[i];
        revers++;
      }
    }
  }
  ::countGlobal = revers;
  return resultStr;
}

size_t mihalchenko::arrUniq(char *mas, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if (i != j)
      {
        if (mas[i] == mas[j])
        {
          while ((mas[j] == mas[size - 1]) && (j < size - 1))
          {
            size--;
          }
          std::swap(mas[size - 1], mas[j]);
          if ((i != size - 1) || (j != size - 1))
          {
            size--;
          }
        }
      }
    }
  }
  return size;
}
