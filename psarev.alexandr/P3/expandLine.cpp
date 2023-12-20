#include "expandLine.hpp"

char* psarev::expandLine(char* line, size_t elemNum, size_t expAm)
{
  char* extLine = new char[elemNum + expAm] {};
  if (!extLine) {
    delete[] line;
    throw std::logic_error("Error: Can't allocate memory!\n");
  }
  for (size_t i = 0; i < elemNum; i++) {
    extLine[i] = line[i];
  }
  delete[] line;
  return extLine;
}
