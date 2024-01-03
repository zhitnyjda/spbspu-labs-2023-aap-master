#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <map>

namespace khoroshkin
{
  int inputLine(char *& line, size_t capacity);
  char findFirstMax(std::map<char, int> dict);
  char findOtherMax(std::map<char, int> dict, int previousMaxChar, char first = '\0', char second = '\0');
  void generateNewString(std::map<char, int> dict, char * newString);
  void getFrequency(const char * line, int length, char * newString);
  void clearString(char * string, size_t stringSize);
  void generateNewWithTwo(const char * firstLine, const char * secondLine, size_t size1, size_t size2, char * newString);
}

#endif
