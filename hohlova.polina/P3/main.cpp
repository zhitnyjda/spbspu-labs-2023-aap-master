#include <iostream>
#include <cstring>
#include "findCommonChars.hpp"
#include "readLine.hpp"

int main()
{
  using namespace hohlova;
  size_t maxCharNum = 10;
  size_t size = 0;
  char* inputStr = readLine(std::cin, size, maxCharNum);
  size_t lenInputStr = strlen(inputStr);
  if (lenInputStr == 0)
  {
    std::cerr << "Cannot read string\n";
    delete[] inputStr;
    return 1;
  }
  int answer = findCommonChars(inputStr, size);
  std::cout << answer;
  delete[] inputStr;
  return 0;
}
