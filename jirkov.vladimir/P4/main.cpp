#include <iostream>
#include <fstream>
#include <cstring>
#include "decreaseSpiralElements.hpp"
#include "inputArray.hpp"

int main(int argc, char ** argv)
{
  using namespace jirkov;
  using namespace Array;
  if (argc != 4)
  {
    std::cerr << "Wrong input. Enter 4 arguments.\n";
    return 1;
  }

  char * end = nullptr;
  size_t num = 0;
  num = std::strtoll(argv[1], &end, 10);
  int len = strlen(argv[1]);
  if (*end != '\0')
  {
    std::cerr << "Can't parse a value.\n";
    return 1;
  }
  if (end != argv[1] + len)
  {
    std::cerr << "It is not a number\n";
    return 1;
  }
  else if (num != 1 && num != 2)
  {
    std::cerr << "incorrect number\n";
    return 1;
  }
  size_t m = 0, n = 0;
  {
    std::ifstream cin(argv[2]);
    std::ofstream cout(argv[3]);
    cin >> m;
    cin >> n;
    if (!cin)
    {
      std::cerr << "Incorrect input.\n";
      return 2;
    }
    if (num == 1)
    {
      int staticMatrix[10000];
      for (size_t i = 0; i < m * n; i++)
      {
        cin >> staticMatrix[i];
        if (!cin)
        {
          std::cerr << "Wrong input. Readed only " << i << " out of " << (m * n) << "\n";
          return 2;
        }
      }
      decreaseSpiralElements(staticMatrix, m, n);
      printArray(cout, staticMatrix, m, n);
    }

    else if (num == 2)
    {
      int * dinamicMatrix = new int[m * n];
      size_t inputElements = 0;
      inputElements = Array::inputArray(cin, dinamicMatrix, m * n, m * n);
      if (inputElements != (m * n))
      {
        std::cerr << "Wrong input. Readed only " << inputElements << " out of " << (m * n) << "\n";
        delete [] dinamicMatrix;
        return 2;
      }
      decreaseSpiralElements(dinamicMatrix, m, n);
      printArray(cout, dinamicMatrix, m,  n);
      delete [] dinamicMatrix;
    }
    else
    {
      std::cerr << "You may enter onty 1 and 2! \n";
      return 2;
    }
  }
  return 0;
}
