#include <iostream>
#include <iomanip>

int main()
{
  char * input = new char[10]{};
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (read < 9))
  {
    input[read++] = c;
    if (c == '\n')
    {
      input[read - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  std::cout << input << "\n";
  delete [] input;
}
