#include "readLine.hpp"
#include "incremArr.hpp"

char * ponomarev::readLine(std::istream & input, size_t incremOfEl)
{
  char * line = new char[incremOfEl]{};
  char elem = 0;
  size_t numOfEl = 0;
  size_t limitOfMem = incremOfEl - 1;
  input >> std::noskipws;
  while (std::cin >> elem)
  {
    line[numOfEl++] = elem;
    if (elem == '\n')
    {
      line[numOfEl - 1] = 0;
      break;
    }
    if (numOfEl == limitOfMem)
    {
      char * enlargedArr = ponomarev::incremArr(line, incremOfEl, numOfEl);
      if (enlargedArr == nullptr)
      {
        delete[] line;
        line = new char[1] {};
        return line;
      }
      limitOfMem += incremOfEl;
      delete[] line;
      line = enlargedArr;
    }
  }
  input >> std::skipws;
  return line;
}
