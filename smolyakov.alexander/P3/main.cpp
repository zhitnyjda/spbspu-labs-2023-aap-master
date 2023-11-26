#include <iostream>
#include "repDgt.hpp"

int main()
{
  const int SIZE_INCREMENT = 10;
  char * inputString = new char[SIZE_INCREMENT]{};
  char currentCharacter = 0;
  size_t read = 0;

  do
  {
    std::cin.get(currentCharacter);
    inputString[read++] = currentCharacter;
    if (read % SIZE_INCREMENT == 0)
    {
      char * tmpInputString = new char[read + SIZE_INCREMENT];
      for (size_t i = 0; i < read; i++)
      {
	tmpInputString[i] = inputString[i];
      }
      delete[] inputString;
      inputString = tmpInputString;
    }
  }
  while (currentCharacter != '\n');

  std::cout << containsRepeatingDigits(inputString, read) << '\n'; 
  delete[] inputString;
  return 0;
}
