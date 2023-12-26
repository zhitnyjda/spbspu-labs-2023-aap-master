#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cctype>

int main()
{
  const char * input2 = "abc_def12";
  try
  {
    char * input1 = new char[10]{};
    char * output = new char[10]{};
    std::cout <<//
    std::cout <<//
    std::cout <<//OUTPUT

    delete[] input1
    delete[] input2
    delete[] output
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
