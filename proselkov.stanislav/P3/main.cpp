#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cctype>

int main()
{
  char * input = new char[10] {};
  char c = 0;
  size_t read = 0;
  size_t qty = 10;
  std::cin >> std::noskipws;
  while ((std::cin >> c) and (c != '\n'))
  {
    input[read++] = c;
    if (read % qty == 0)
    {
      char* InputBoss = new char[read + qty];
      for (size_t i = 0; i < read; i++)
      {
        InputBoss[i] = input[i];
      }
      delete[] input;
      input = InputBoss;
      std::cout << InputBoss << "\n";
    }
  }
  std::cin >> std::skipws;
  char * ressultArray = new char[read] {};
  //function...
  for (size_t i = 0; i < read; i++)
  {
    std::cout << ressultArray[i];
  }
  std::cout << "\n";
  delete[] input;
  delete[] ressultArray;
  return 0;
}
