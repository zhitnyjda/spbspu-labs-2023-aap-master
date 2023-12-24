#include <iostream>
#include <iomanip>

int main()
{
  int incremOfEl = 10;
  char * line = new char[incremOfEl]{};
  char elem = 0;
  size_t numOfEl = 0;
  std::cin >> std::noskipws;
  while (std::cin >> elem)
  {
    line[numOfEl++] = elem;
    if (elem == '\n')
    {
      line[numOfEl - 1] = 0;
      break;
    }
    if (numOfEl == incremOfEl)
    {
      char * enlargedArr = new char[numOfEl + incremOfEl]{};
      for (size_t i = 0; i < numOfEl; i++)
      {
        enlargedArr[i] = line[i];
      }
      delete[] line;
      line = enlargedArr;
    }
  }
  std::cin >> std::skipws;
  std::cout << line << "\n";
  delete [] line;
}
