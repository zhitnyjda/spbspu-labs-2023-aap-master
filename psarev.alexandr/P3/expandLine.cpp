#include "expandLine.hpp"

char* psarev::expandLine(char* line, size_t elemNum, size_t extSize)
{
  char* extLine = new char[elemNum + extSize] {};
  if (!extLine) {
    delete[] line;
    throw std::logic_error("Error: Can't allocate memory!\n");
  }
  for (size_t i = 0; i < elemNum; i++) {
    extLine[i] = line[i];
  }
  return extLine;
}
