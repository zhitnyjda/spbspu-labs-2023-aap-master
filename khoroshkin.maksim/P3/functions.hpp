#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cctype>
#include <map>

namespace khoroshkin
{
  int inputLine(char *& line, size_t capacity);
  char findFirstMax(std::map<char, int> dict);
  char findOtherMax(std::map<char, int> dict, int previousMaxChar, std::string alreadyTaken);
  char * generateNewString(std::map<char, int> dict);
  char * getFrequency(char * line, int length);
}
#endif
