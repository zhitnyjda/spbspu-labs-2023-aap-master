#include "str.hpp"
#include <iostream>

miheev::String::String()
{
  size_ = 0;
  string_ = new char[0];
  indexOfFirstFree_ = 0;
}

miheev::String::~String()
{
  delete[] string_;
}

void miheev::String::expand(size_t size)
{
  char* temp = new char[size_ + size]{};
  for (size_t i = 0; i < size_; i++)
  {
    temp[i] = string_[i];
  }
  string_ = temp;
  size_ += size;
  temp = nullptr;
}

void miheev::String::print() const
{
  for (size_t i = 0; i < size_; i++)
  {
    std::cout << string_[i];
  }
  std::cout << '\n';
}

void miheev::String::fillFromBuff(miheev::Buffer buff)
{
  if (indexOfFirstFree_ + buff.getSize() > size_)
  {
    expand(buff.getSize());
  }
  size_t start = indexOfFirstFree_;
  while (indexOfFirstFree_ < start + buff.getSize() && buff[indexOfFirstFree_ - start])
  {
    string_[indexOfFirstFree_] = buff[indexOfFirstFree_ - start];
    indexOfFirstFree_++;
  }
}

char* miheev::String::getString() const
{
  return string_;
}
