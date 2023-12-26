#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cctype>
#include <string>
#include "readLine.hpp"
#include "DgtSnd.hpp"

int main()
{
  const char input2[10]{"g1h2k"};
  try
  {
    char * input1 = new char[10]{};
    char * output = new char[10]{};
    int len1 = readLine(input1);
    std::cout <<//OUTPUT

    delete[] input1;
    delete input2;
    delete[] output;
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
