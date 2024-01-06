#include <cstring>
#include "readLine.hpp"

using namespace nikiforov;
int main()
{
  char* str1 = new char[0] {};
  const char* str2 = "abs";
  std::cin >> std::noskipws;

  size_t len1 = 0;
  size_t len2 = strlen(str2);

  str1 = nikiforov::readLine(std::cin, str1, len1);

  std::cin >> std::skipws;
  std::cout << str1 << '\n' << len1;
  if (len1 == 0)
  {
    std::cerr << "Too short sequence\n";
    delete[] str1;
    return 1;
  }
  std::cout << '\n' << nikiforov::result(str1, str2, len1, len2) << '\n';
  delete[] str1;
  return 0;
}
