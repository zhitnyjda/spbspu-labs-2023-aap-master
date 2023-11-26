#include <iostream>
#include <iomanip>
int main()
{
  size_t read = 0;
  char symbol = 0;
  int add = 25;
  size_t size = 25;
  std::cin >> std::noskipws;
  char * array = new char[size]{};
  while ((std::cin >> symbol) && (symbol != '\n'))
  {
    array[read++] = symbol;
    if (read == size)
    {
      try
      {
        char * newarray = new char[size + add]{};
        for(size_t i = 0; i < size; i++)
        {
          newarray[i] = array[i];
        }
        delete[] array;
        char * array = newarray;
        delete[] newarray;
        size += add;
      }
      catch(const std::bad_alloc &e)
      {
        std::cerr << "Unable to allocate memory\n";
        return 1;
      }
    }
  }



  delete[] array;
  return 0;
}
