#include <iostream>
#include <cmath>
#include "validationAndConversationToInt.h"

void check(int argc, char **argv)
{
  if (argc != 4) {
    throw std::logic_error(ARG_ERR);
  }
  int num = getInt(std::string(argv[1]));
  if (num != 1 && num != 2) {
    throw std::logic_error(INVALID_INPUT);
  }
}

int getInt(std::string number)
{
  int num = 0;
  for (unsigned long int i = 0; i < number.size(); ++i) {
    if (!isdigit(number[i])) {
      throw std::logic_error(FIRST_ARG_ERR);
    }
    num += pow(10, (number.size() - i - 1)) * (number[i] - '0');
  }
  return num;
}
