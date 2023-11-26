#include <iostream>
#include "repDgt.hpp"

int main()
{
  const int SIZE_INCREMENT = 10;
  const char * BAD_INPUT_ALLOC = "Could not allocate memory for an input string.\n";
  char currentCharacter = 0;
  size_t read = 0;
  char * inputString = new char[SIZE_INCREMENT]{};

  do
  {
    std::cin.get(currentCharacter);
    inputString[read++] = currentCharacter;
    if (read % SIZE_INCREMENT == 0)
    {
      try
      {
        char * tmpInputString = new char[read + SIZE_INCREMENT];
      }
      catch (const strd::bad_alloc & e)
      {
	std::cerr << BAD_INPUT_ALLOC;
	return 1;
      }

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
