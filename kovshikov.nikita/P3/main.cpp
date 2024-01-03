#include <iostream>
#include <iomanip>
#include <cctype>
#include "read_input.hpp"
#include "shr_sym.hpp"
#include "dgt_snd.hpp"
#include <cstring>

int main()
{
  std::cin >> std::noskipws;
  size_t size = 25;
  size_t read = 0;
  char * userString = nullptr;
  try
  {
    userString = kovshikov::readInput(size, read);
  }
  catch(const std::bad_alloc &e)
  {
    std:: cerr << "Unable to allocate memory\n";
    return 1;
  }
 const char * myString = "Any fool can write code that is understandable to a computer, a good programmer will write code that is understandable to a person";
 size_t length = strlen(myString);
 if(read == 0 || length == 0)
  {
    std::cerr << "zero characters\n";
    return 1;
  }
  char outputShrSym[26] = {};
  kovshikov::missingChar(userString, outputShrSym, read);
  char outputDgtSnd[read + length] = {};
  kovshikov::withDigits(userString, myString, outputDgtSnd, read, length);
  std::cout << outputShrSym << "\n";
  std::cout << outputDgtSnd << "\n";
  std::cin >> std::skipws;
  delete[] userString;
  return 0;
}
