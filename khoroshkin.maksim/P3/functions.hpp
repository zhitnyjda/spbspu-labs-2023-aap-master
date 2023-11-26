#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cctype>
#include <map>

namespace khoroshkin
{
  int inputLine(char * line);
  char findFirstMax(std::map<char, int> dict);
  char findOtherMax(std::map<char, int> dict, int previousMaxChar, std::string alreadyTaken);
  std::string generateNewString(std::map<char, int> dict);
  std::string getFrequency(char * line, int length);
}

#endif