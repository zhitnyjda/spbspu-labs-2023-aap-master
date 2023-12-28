#include "buffer.hpp"
#include <iostream>
#include <iomanip>

miheev::Buffer::Buffer(size_t size):
  size_(size)
{
  buff_ = new char[size]{};
}

miheev::Buffer::~Buffer()
{
  delete[] buff_;
}

void miheev::Buffer::clean()
{
  for (size_t i = 0; i < size_; i++)
  {
    buff_[i] = 0;
  }
}

size_t miheev::Buffer::getSize()
{
  return size_;
}

char miheev::Buffer::operator[](size_t index)
{
  return buff_[index];
}

bool miheev::Buffer::fillFromCin()
{
  size_t buffIndex = 0;
  char c = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    buff_[buffIndex++] = c;
    if (c == '\n')
    {
      buff_[buffIndex - 1] = 0;
      break;
    }
    if (buffIndex >= size_)
    {
      return false;
    }
  }
  std::cin >> std::skipws;
  return true;
}

void miheev::Buffer::print()
{
  for (size_t i = 0; i < size_; i++)
  {
    std::cout << buff_[i];
  }
  std::cout << '\n';
}
