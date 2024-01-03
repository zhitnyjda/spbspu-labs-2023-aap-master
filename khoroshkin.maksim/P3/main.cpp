#include <iostream>
#include "functions.hpp"

int main()
{
  char * userString = new char[0];
  const char * givenString = "abc";
  try
  {
    int userStringLength = khoroshkin::inputLine(userString, 10);
    if (userStringLength < 3)
    {
      throw std::logic_error("Error: Too short string\n");
    }
    char * newString = new char[userStringLength + 1];
    khoroshkin::getFrequency(userString, userStringLength, newString);
    std::cout << "Result for FRQ-TOP: " << newString << '\n';
    khoroshkin::clearString(newString, userStringLength);
    khoroshkin::generateNewWithTwo(userString, givenString, userStringLength, 3, newString);
    std::cout << "Result for EXC-SND: " << newString << '\n';
    delete[] newString;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    delete[] userString;
    return 1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: Cannot allocate memory\n";
    delete[] userString;
    return 1;
  }
  delete[] userString;
  return 0;
}
