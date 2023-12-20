#include "readLine.hpp"
#include "expandLine.hpp"

char* psarev::readLine()
{
  char elem = ' ';
  size_t elemNum = 0;
  size_t expAm = 10;
  size_t maxElemNum = expAm;
  char* line = new char[maxElemNum] {};
  std::cin >> std::noskipws;

  while (std::cin >> elem) {
    line[elemNum++] = elem;
    if (elem == '\n') {
      line[elemNum - 1] = 0;
      break;
    }
    if (elemNum == maxElemNum) {
      line = expandLine(line, elemNum, expAm);
      maxElemNum += expAm;
    }
  }
  std::cin >> std::skipws;
  return line;
}
