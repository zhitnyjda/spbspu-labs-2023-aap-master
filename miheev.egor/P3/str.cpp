#include "str.hpp"

miheev::String::String()
{
  size_ = 0;
  string_ = new char*[0];
}

void miheev::String::expand(size_t size);
{
  size_t sizeExpanded = size_ + size;  
  char* temp = new char[sizeExpanded];
  for (size_t i = 0; i < size_; i++)
  {
    temp[i] = string_[i];
  }
  string_ = temp;
  temp = nullptr;
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
