#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  try
  {
    // checking params
    if (argc > 4)
    {
      throw std::invalid_argument("Too many arguments, programm takes only 3");
    }
    else if (argc < 4)
    {
      throw std::invalid_argument("Not enough arguments, programm takes 3");
    }
    //initing params
    int num = atoi(argv[1]);
    std::string input = argv[2];
    std::string output = argv[3];

    return 0;
  }
  catch(const std::logic_error& logic_e)
  {
    std::cerr << logic_e.what();
    return 1;
  }
}