#include "readLine.hpp"
#include <cstring>
#include "functions.hpp"

int main()
{
  const size_t incremOfEl = 10;
  char * line = ponomarev::readLine(std::cin, incremOfEl);
  const char * secondLine = "g1h2k";
  size_t lenLine = strlen(line);
  size_t lenSecLine = strlen(secondLine);
  if (lenLine == 0)
  {
    std::cerr << "Error, not enough memory\n";
    delete[] line;
    return 1;
  }
  char * lineBefDel = ponomarev::delNums(line, lenLine);
  size_t temp = strlen(lineBefDel);
  for (size_t i = 0; i < temp; i++)
  {
    std::cout << lineBefDel[i];
  }
  std::cout << "\n";
  delete[] lineBefDel;
  char * lineBefAdNums = ponomarev::addNums(line, lenLine, secondLine, lenSecLine, incremOfEl);
  size_t t = strlen(lineBefAdNums);
  for (size_t i = 0; i < t; i++)
  {
    std::cout << lineBefAdNums[i];
  }
  std::cout << "\n";
  delete[] lineBefAdNums;
  delete[] line;
  return 0;
}
