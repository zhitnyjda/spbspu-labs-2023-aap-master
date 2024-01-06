#include <iostream>
#include <cstring>
#include "Func.hpp"

using namespace nikiforov;
int main()
{
  char c = '\0';
  size_t size = 0;
  char* str1 = new char[size] {};
  const char* str2 = "abs";

  std::cin >> std::noskipws;
  size_t read = 0;

  while (std::cin >> c)
  {
    nikiforov::AddElem(str1, size, read);
    str1[read++] = c;
    if (c == '\n') {
      str1[--read] = 0;
      break;
    }
  }

  size_t len1 = read;
  size = 0;
  size_t len2 = strlen(str2);
  std::cin >> std::skipws;

  if (len1 == 0)
  {
    std::cerr << "Too short sequence\n";
    delete[] str1;
    return 2;
  }
  std::cout << '\n' << nikiforov::result(str1, str2, len1, len2) << '\n';
  delete[] str1;
  return 0;
}
