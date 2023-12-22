#include "functionSeqSym.h"
#include "functionDgtSnd.h"
#include "functionStrRead.h"
#include <iostream>

int main()
{
  char* str = readDynamicString();
  char* str_ = readDynamicString();

  try
  {
    std::cin >> str >> str_;

    std::cout << strSymbolsRepeats(str) << std::endl;
    std::cout << appendNumToStr(str, str_) << std::endl;

    delete[] str;
    delete[] str_;
  }
  catch (const std::logic_error& err)
  {
    std::cerr << err.what() << std::endl;

    delete[] str;
    delete[] str_;
    return 1;
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what() << std::endl;

    delete[] str;
    delete[] str_;
    return 1;
  }

  return 0;
}
