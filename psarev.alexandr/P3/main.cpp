#include <iostream>
#include <cstddef>
#include "lineFuncs.hpp"

int main()
{
  try
  {
    char* line1 = new char[10] {};
    char* line2 = new char[10] {};

    char* lineRes = new char[10] {};
    size_t len1 = psarev::makeLine(line1);
    size_t len2 = psarev::makeLine(line2);
    if (len1 == 1 || len2 == 1) {
      std::cerr << "Error: At least one value need!\n";
      delete[] line1;
      delete[] line2;
      delete[] lineRes;
    }
    size_t resMarker = psarev::makeMutUnLine(line1, line2, len1, len2, lineRes);

    delete[] line1;
    delete[] line2;

    for (size_t i = 0; i < resMarker; i++) {
      std::cout << lineRes[i];
    }
    std::cout << '\n';

    delete[] lineRes;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: Can't allocate memory!\n";
    return 1;
  }
}
