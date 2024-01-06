#include <iostream>
#include "sequences.hpp"

int main()
{
  char *line = nullptr;
  int size = 0;
  char subString[10]{"abc"};
  try
  {
    line = likhachev::readSequence(size);

    if (size == 0) {
      std::cerr << "There are no symbols here, my dude :L ";
      delete[] line;
      return 1;
    }

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
