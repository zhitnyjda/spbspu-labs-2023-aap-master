#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <map>

namespace khoroshkin
{
  int inputLine(char *& line, size_t capacity);
  char findFirstMax(std::map<char, int> dict);
  char findOtherMax(std::map<char, int> dict, int previousMaxChar, char first = '\0', char second = '\0');
  char * generateNewString(std::map<char, int> dict);
  char * getFrequency(char * line, int length);
}

#endif
