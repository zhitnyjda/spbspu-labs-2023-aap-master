//DIF-LAT
#include <iostream>
#include "neostring.hpp"
#include "transformations.hpp"


int main()
{
  size_t size = 5;
  char* string = new char[size]{};

  miheev::readString(&string, size);
  if (string[0] == '\0')
  {
    std::cerr << "you've entered an empty line\n";
    delete[] string;
    return 1;
  }
  std::cout << miheev::countDiffLat(string) << '\n';
  delete[] string;
  return 0;
}
