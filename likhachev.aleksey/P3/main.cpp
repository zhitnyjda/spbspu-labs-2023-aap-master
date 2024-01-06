#include <iostream>
#include "sequences.hpp"

int main()
{
  char *line = new char[10];
  char subString[10]{"abc"};
  try
  {
    int size = likhachev::readSequence(line);

    int hasSame = likhachev::strDoesHasSame(line, size, subString, 3);
    size = likhachev::strRemoveDigits(line, size);

    std::cout << "\n";
    std::cout << "String ";
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
    delete[] line;
    return 1;
  }
}
