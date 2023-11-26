#include <iostream>
#include <cstring>
#include <cstddef>
#include <string>
#include "func.hpp"

int main()
{
  using namespace hohlova;
  try
  {
    char* instr = new char[10] {};
    size_t inputlen = readLine(instr);
    int c = findCommonChars(instr);
    std::cout << c;
  }
  catch (const std::bad_alloc& ex)
  {
    std::cerr << ex.what() << "\n";
    return 1;
  }
}
