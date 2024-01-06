<<<<<<< HEAD
#include "functions.hpp"
#include "incremArr.hpp"

char * ponomarev::delNums(const char * line, size_t lenLine)
{
  char * lineBefDelNums = new char[lenLine] {};
=======
#include "delNums.hpp"

char * ponomarev::delNums(char * line, size_t lenLine)
{
  char * resLine = new char[lenLine] {};
>>>>>>> origin/ponomarev.viacheslav/P3
  size_t numOfEl = 0;
  for (size_t i = 0; i < lenLine; i++)
  {
    if (std::isdigit(line[i]) == 0)
    {
<<<<<<< HEAD
      lineBefDelNums[numOfEl++] = line[i];
    }
  }
  return lineBefDelNums;
}

char * ponomarev::addNums(const char * line, size_t lenLine, const char * secondLine, size_t lenSecLine, size_t incremOfEl)
{
  char * lineBefAdNums = new char[lenLine] {};
  size_t numOfEl = lenLine - 1;
  size_t limitOfMem = lenLine - 1;
  for (size_t i = 0; i < lenLine; i++)
  {
    lineBefAdNums[i] = line[i];
  }
  for (size_t i = 0; i < lenSecLine; i++)
  {
    if (std::isdigit(secondLine[i]) == 1)
    {
      if (numOfEl == limitOfMem)
      {
        lineBefAdNums = ponomarev::incremArr(lineBefAdNums, incremOfEl, numOfEl);
        limitOfMem += incremOfEl;
      }
      numOfEl += 1;
      lineBefAdNums[numOfEl] = secondLine[i];
    }
  }
  return lineBefAdNums;
}




=======
      resLine[numOfEl++] = line[i];
    }
  }
  return resLine;
}
>>>>>>> origin/ponomarev.viacheslav/P3
