#include "readLine.hpp"

char* nikiforov::readLine(std::istream& input, char* str1)
{
  char c = '\0';
  size_t size = 0;
  size_t read = 0;

  while (input >> c)
  {
    nikiforov::AddElem(str1, size, read);
    str1[read++] = c;
    if (c == '\n') {
      str1[--read] = 0;
      break;
    }
  }
  return str1;
}
