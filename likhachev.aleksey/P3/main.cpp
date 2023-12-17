#include <iostream>
#include "lavran.cpp"
#include "lavran.hpp"

int main()
{
  try
  {
    char *line = new char[10];
    char subString[10]{"abc"};
    int size = likhachev::readSequence(line);

    int hasSame = likhachev::strDoesHasSame(line, size, subString, 9);
    likhachev::strRemoveDigits(line, size);

    std::cout << "Strings ";
    if (!hasSame) {
      std::cout << "do not have ";
    }
    std::cout << "common characters.\n";

    std::cout << "The string received after deleting the digits: ";
    likhachev::outLine(line, size);

    delete[] line;
    return 0;
  }
  catch (std::logic_error const& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
