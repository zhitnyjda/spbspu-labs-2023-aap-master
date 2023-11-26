#include <iostream>

int main()
{
  char* string = nullptr;
  try
  {
    string = functionInput(std::cin);
    if (string[0] == '\0')
    {
      delete[] string;
      throw std::logic_error("Not string");
    }
  }
  catch( const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  // Тут написать функцию которая обрабатывает строку 
  delete[] string;
  return 0;
