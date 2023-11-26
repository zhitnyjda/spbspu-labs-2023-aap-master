#include <iostream>

void pushBack(size_t & size, char *& str, bool & flag)
{
  char temp = 0;
  char * new_str = new char[size + 10]{};
  for (int i = 0; i < size; i++)
  {
    new_str[i] = str[i];
  }
  int count = 0;
  while ((std::cin >> temp) && count < 10 && flag)
  {
    new_str[size + count] = temp;
    count++;
    if (temp == '\n' || !flag)
    {
      flag = 0;
      break;
    }
  }
  size += 10;
  delete[] str;
  str = new_str;
}

int main()
{
  std::cin >> std::noskipws;
  size_t size_str = 10;
  char* str = new char[10]{0};
  bool flag = 1;
  while (flag)
  {
    pushBack(size_str, str, flag);
  }
  for (int i = 0; i < size_str; i++)
  {
    std::cout << str[i];
  }
}