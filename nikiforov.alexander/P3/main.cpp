#include <iostream>
#include "Func.hpp"
#include <cstring>

using namespace nikiforov;
int main()
{
  char c = '\0';
  size_t size = 0;
  size_t read = 0;
  char* str1 = new char[size] {};
  const char* str2 = "abs";
  std::cin >> std::noskipws;

  while ((std::cin >> c) && (c != '\n'))
  {
    nikiforov::AddElem(str1, size, read);
    str1[read++] = c;
  }

  size_t len1 = read;
  size = 0;

  size_t len2 = strlen(str2);
  std::cin >> std::skipws;
  if (len1 == 0 && len2 == 0)
  {
    std::cerr << "Too short sequence\n";
    delete[] str1;
    return 1;
  }
  std::cout << '\n' << nikiforov::result(str1, str2, len1, len2) << '\n';
  delete[] str1;
  return 0;
}
