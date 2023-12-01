#include <iostream>
#include "readLine.hpp"
#include "createLine.hpp"

int main()
{
  try
  {
    char* line1 = new char[10] {};
    const char* line2 = "abc ef";

    size_t len1 = psarev::readLine(line1);
    if (len1 == 0) {
      std::cerr << "Error: At least ONE value need!\n";
      delete[] line1;
      return 1;
    }
    size_t len2 = 6;

    char* lineRes = new char[10] {};
    size_t resMarker = psarev::createTaskLine(line1, line2, len1, len2, lineRes);

    delete[] line1;

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
