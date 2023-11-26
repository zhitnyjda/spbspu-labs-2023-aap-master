#include <iostream>
#include <iomanip>
#include <cctype>
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
  char output[26] = {};
  std::cout << output << "\n";
  int element = 0;
  bool flag = false;
  for(int i = 97; i <= 122 ; i++)
  {
    for(size_t j = 0; j < read; j++)
    {
      if(char(i) == (char)tolower(array[j]))
      {
        flag = true;
      }
      else if((j == read - 1) && char(i) != (char)tolower(array[j]) && flag == false)
      {
        output[element++] = char(i);
      }
    }
    flag = false;
  }
  std::cout << output << "\n";
  std::cin >> std::skipws;
  delete[] array;
  return 0;
}
