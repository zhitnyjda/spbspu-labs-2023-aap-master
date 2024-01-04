#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "findCommonChars.hpp"
#include "readLine.hpp"

int main()
{
  using namespace hohlova;
  size_t maxCharNum = 10;
  size_t size = 0;
  char* inputStr = nullptr;
  try
  {
    inputStr = hohlova::readLine(std::cin, size, maxCharNum);
  }
  catch (const std::invalid_argument & ex)
  {
    std::cerr << ex.what();
    return 1;
  }
  std::cout << hohlova::findCommonChars(inputStr);
  delete[] inputStr;
  return 0;
}
