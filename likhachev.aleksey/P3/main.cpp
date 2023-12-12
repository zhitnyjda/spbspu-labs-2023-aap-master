#include <iostream>
#include "lavran.cpp"
#include "lavran.hpp"

int main()
{
  char *line = new char[10];
  int size = likhachev::readSequence(line);
  likhachev::outLine(line, size);
}
