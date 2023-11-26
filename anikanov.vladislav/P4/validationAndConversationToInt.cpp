#include <iostream>
#include <cmath>
#include "validationAndConversationToInt.h"

void check(int argc, char **argv)
{
  if (argc != 4) {
    throw std::logic_error("1");
  }
  int num;
  try {
    num = std::stoi(argv[1]);
  } catch (std::exception const &ex) {
    throw std::logic_error("3");
  }
  if (num != 1 && num != 2) {
    throw std::logic_error("2");
  }

}
