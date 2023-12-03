#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "I feel that something wrong-_-.\n";
    return 1;
  }
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  if (num == 0 && endOfParcing == argv[1])
  {
    std::cerr << "Cannot parse a value.\n";
    return 1;
  }
  else if (num == 0 && endOfParcing != argv[1])
  {
    std::cout << "Num is zero.\n";
  }
  else
  {
    std::cout << num << "\n";
  }
  int i = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr << "Cannot read a number.\n";
      return 1;
    }
  }
  std::cout << i << "\n";
  std::ofstream output(argv[3]);
  output << i << "\n";
}
