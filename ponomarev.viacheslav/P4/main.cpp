#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "I feel that something wrong-_-.\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value.\n";
    return 1;
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
