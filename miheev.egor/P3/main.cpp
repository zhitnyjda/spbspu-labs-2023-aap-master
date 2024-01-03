//DIF-LAT
#include <iostream>
#include "neostring.hpp"
#include "transformations.hpp"


int main()
{
  size_t size = 5;
  char* string = new char[size]{};

  miheev::readString(&string, size);
  std::cout << miheev::countDiffLat(string) << '\n';
  delete[] string;
}
